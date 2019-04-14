#include "Audio.h"
#include<fstream>
#include<memory>
#include"DxLib.h"

Audio::Audio()
{
	std::ifstream audiopath("img/audiosource.json");
	if (audiopath.fail()) throw "audiosource.json is not found.";//例外処理
	std::istreambuf_iterator<char> it(audiopath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);	//string形式のjson
	std::string err;
	json = json11::Json::parse(str_json, err);//Jsonで使えるようにする
	count_size = 0;
	for (auto &item : json["audio"].array_items()) {
		count_size++;//最大数を数える
	}
	audio = std::make_unique<AudioObject[]>(count_size);//メモリ確保
	for (int i = 0; i < count_size; ++i) { audio[i].exist = false; }
}

Audio::~Audio()
{
	for (int i = 0; i < count_size; ++i) {
		DeleteSoundMem(audio[i].handle);
	}
}

void Audio::play(std::string name)
{
	for (int i = 0; i < count_size; ++i) {
		if (audio[i].name == name) {
			int playtype;
			if (audio[i].loop) playtype = DX_PLAYTYPE_LOOP;
			else playtype = DX_PLAYTYPE_BACK;
			PlaySoundMem(audio[i].handle, playtype);
			break;
		}
	}
}

void Audio::load(std::string scope_)
{
	for (auto &audiosource : json["audio"].array_items())
	{
		for (auto &scope : audiosource["scope"].array_items()) {
			if (scope_ == scope.string_value()) {
				if (exist(audiosource["name"].string_value()) == false) {
					for (int i = 0; i < count_size; ++i) {
						if (audio[i].exist == false) {
							audio[i].name = audiosource["name"].string_value();//名前
							audio[i].loop = audiosource["loop"].bool_value();//ループ再生を行うか
							audio[i].path = audiosource["path"].string_value();
							audio[i].handle = LoadSoundMem(audio[i].path.c_str());
							//デフォルト値を入れる
							set_default(audio[i]);

							if (audio[i].handle == -1) throw std::runtime_error("audio file is not found.");//ファイルが読み込めないと例外を返す
							audio[i].exist = true;
							break;
						}
					}
				}
			}
		}
	}
}

void Audio::stop(std::string name)
{
	for (int i = 0; i < count_size; ++i) {
		if (audio[i].name == name) {
			//再生中なら
			if (CheckSoundMem(audio[i].handle) == 1) {
				StopSoundMem(audio[i].handle);//停止
				break;
			}
		}
	}
}

bool Audio::exist(std::string name) {
	//nameが存在しているか調べるメソッド
	bool ret = false;
	for (int i = 0; i < count_size; i++) {
		if (audio[i].name == name) {
			//存在していたら
			ret = true;
			break;
		}
	}
	return ret;
}

void Audio::set_default(AudioObject ao)
{
	if (ao.loop == NULL) {
		ao.loop = false;//ループ記述がない場合falseにする（ループしない）
	}
}
