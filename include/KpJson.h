#pragma once
#include "json.h"

#include <string>
#include <fstream>
using namespace std;

class CKpJson
{
private:
    CKpJson(void);
    ~CKpJson(void);
public:
    //从文件加载json数据
    static bool LoadFromFile(const char* szJsonFile,Json::Value& jv);
    //保存json数据到文件
    static bool SaveTo(Json::Value& jv,const char* szFile);
    //Json数据转字符串
    static string Json2String(Json::Value& jv);
    //字符串转Json
    static bool String2Json(string& sJonsString,Json::Value& jv );
};

