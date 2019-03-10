#pragma once
#include<memory>

//カプセル化するクラス
//対象オブジェクトを包みリスト化する
template <typename T> class List{
public:
    std::shared_ptr<List<T>> next;
    std::shared_ptr<T> content;
};

//template class List<Star>;


template <typename T> class BasicList{
public:
    BasicList();
    bool lead();  //アドレスを先頭に戻す
    bool exist();   //生きてますか？
    bool proceed();  //アドレスを次に移動する
    bool create(std::shared_ptr<T>);//インスタンスのアドレスを受け取る
    bool clone();
    bool destroy(); //インスタンスを削除する
    std::shared_ptr<T> get();       //currentを返す
private:
    std::shared_ptr<List<T>> head;    //先頭
    std::shared_ptr<List<T>> previous;    //一つ後ろ
    std::shared_ptr<List<T>> current; //現在のアドレス
};


//関数の実装
template <typename T> BasicList<T>::BasicList()
{
    head = nullptr;
    current = nullptr;
    previous = nullptr;
}

template <typename T> bool BasicList<T>::lead()
{
    bool ret = false;
    if(head != nullptr){    //リストの先頭がnullptrではないということはリストが存在しているということになる
        ret = true;
        current = head;
    }
    return ret;
}

template <typename T> bool BasicList<T>::proceed()
{
    bool ret = false;
    if(current != nullptr){
        previous = current;  //一つ後ろのアドレスを記録する
        current = current->next;    //現在のアドレスを進める
        ret = true;                 //進められたらtrueを返す、進められない場合はfalseを返す
    }
    return ret;
}

template <typename T> bool BasicList<T>::exist()
{
    bool ret = false;
    if(current != nullptr) ret = true;
    return ret;
}

template <typename T> bool BasicList<T>::create(std::shared_ptr<T> new_content)
{
    bool ret = true;
    std::shared_ptr<List<T>> new_instance = std::make_shared<List<T>>();   //リストオブジェクトを新規作成する
	new_instance->content = new_content;	//リストに内容(content)を登録する　作成はしない
    
    if(current == nullptr && previous == nullptr){
        //最初のリストを作成する処理
        current = new_instance;   //空のリストの場合
        head = current;
        
    }
    else if(current != nullptr){
        //二つ目以降のリストを作成する処理
        previous = std::move(current);      //所有権を移動する
        current = std::move(new_instance);  //所有権を移動する
        previous->next = current;           //所有権を複製する
    }
    else ret = false;   //終端でcreateした場合は作成不可
    
    return ret;
};

template <typename T> bool BasicList<T>::clone()
{
    bool ret = false;
    if(current != nullptr){
        create();   //新規インスタンスを生成する
        *current->content = *previous->content;     //インスタンスを複製する
        ret = true;
    }
    return ret;
}

template <typename T> bool BasicList<T>::destroy()
{
	//先頭削除問題未解決！！！
    bool ret = false;
    if(current != nullptr){
        current = std::move(current->next);
        previous->next = std::move(current);
        ret = true;
    }
    return ret;
}

template <typename T> std::shared_ptr<T> BasicList<T>::get()
{
    //リストオブジェクトの中の一つを返す
    return current->content;  //アドレスを返す
};