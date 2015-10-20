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
    //���ļ�����json����
    static bool LoadFromFile(const char* szJsonFile,Json::Value& jv);
    //����json���ݵ��ļ�
    static bool SaveTo(Json::Value& jv,const char* szFile);
    //Json����ת�ַ���
    static string Json2String(Json::Value& jv);
    //�ַ���תJson
    static bool String2Json(string& sJonsString,Json::Value& jv );
};

