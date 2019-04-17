#include "Spawn.h"


Spawn::Spawn(std::string fpath)
{
	std::ifstream path(fpath);
	if (path.fail()) throw "json file is not found.";//例外処理
	std::istreambuf_iterator<char> it(path);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//string形式のjson
	std::string err;
	data = json11::Json::parse(str_json, err);//Jsonで使えるようにする
}
