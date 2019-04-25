#include "Audio.h"
#include<fstream>
#include<memory>
#include"DxLib.h"

std::vector<std::shared_ptr<AudioObject>> Audio::audioobj;

void AudioObject::set_default()
{
	if (loop == NULL) {
		loop = false;//ループ記述がない場合falseにする（ループしない）
	}
}

void Audio::register_audio(AudioObject& obj)
{
	if (obj.exist == false) {
		obj.handle = LoadSoundMem(obj.path.c_str());
		obj.exist = true;//読み込み済み
	}
}

void Audio::init()
{
	std::ifstream audiopath("ogg/audiosource.json");
	if (audiopath.fail()) throw "audiosource.json is not found.";//例外処理
	std::istreambuf_iterator<char> it(audiopath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);	//string形式のjson
	std::string err;
	json11::Json json = json11::Json::parse(str_json, err);//Jsonで使えるようにする
	for (auto &item : json["audio"].array_items()) {
		std::shared_ptr<AudioObject> audio = std::make_shared<AudioObject>();
		audio->exist = false;
		audio->name = item["name"].string_value();
		audio->loop = item["loop"].bool_value();
		audio->path = item["path"].string_value();
		for (auto &scope : item["scope"].array_items()) {
			audio->scopes.push_back(scope.string_value());
		}
		audio->set_default();
		audioobj.push_back(std::move(audio));
	}
}

void Audio::play(std::string name)
{
	for (auto itr = audioobj.begin(); itr != audioobj.end(); ++itr) {
		if ((*itr)->name == name) {//名前を見つけたら
			int playtype;
			if ((*itr)->loop == true) playtype = DX_PLAYTYPE_LOOP;
			else playtype = DX_PLAYTYPE_BACK;
			PlaySoundMem((*itr)->handle, playtype);
			break;
		}
	}
}

int Audio::load(std::string scope_)
{
	int num = 0;
	for (auto itr = audioobj.begin(); itr != audioobj.end(); ++itr) {
		if ((*itr)->exist == false) {//読み込まれていないなら
			if ((*itr)->exist_scope(scope_)) {
				register_audio(*(*itr));//登録
				num++;
			}
		}
	}
	return num;//番号を返す
}

void Audio::stop(std::string name)
{
	for (auto itr = audioobj.begin(); itr != audioobj.end(); ++itr) {
		if ((*itr)->name == name) {//名前を見つけたら
			//再生中なら
			if (CheckSoundMem((*itr)->handle) == 1) {
				StopSoundMem((*itr)->handle);//停止
				break;
			}
		}
	}
}

//bool Audio::exist(std::string name) {
//	/*nameが存在しているか調べるメソッド
//	bool ret = false;
//	for (int i = 0; i < count_size; i++) {
//		if (audio[i].name == name) {
//			存在していたら
//			ret = true;
//			break;
//		}
//	}
//	return ret;*/
//}

bool AudioObject::exist_scope(std::string scope_)
{
	bool check = false;
	for (auto&& scope : scopes) {
		if (scope == scope_) {
			check = true;
			break;
		}
	}
	return check;
}
