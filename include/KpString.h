#pragma once
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;

namespace CKpString
{
	void ByteToWChar(LPCSTR szByte, std::wstring& wstr);                 //窄字节转宽字节
	void WCharToByte(wchar_t* szWChar, std::string& strByte);            //宽字节转窄字节
	string WCharToUTF8(const std::string& strGBK);                       //GB2132扩展码转UTF_8
	string UTF8ToWChar(const std::string& strUTF8);                      //UTF_8转GB2132扩展码
	BOOL Split(LPCSTR pszStr,LPCSTR pszMark,vector<string>& vecStr);     //分割字符串存到vecctor
	LPSTR FtoA(double douData, int nCount, LPSTR buff);                  //浮点数转换为字符串 返回字符 
	LPSTR FtoAe(double douData, int nCount, LPSTR buff);                 //浮点数转换为字符串 返回字符 返回科学计数法表示
	int GetCharCount(LPSTR pszBuf,int& nChineseChar);                    //获取字符串字符个数，输出汉字个数，返回字符总数
	double AtoF(LPSTR pszBuf);                                           //字符转浮点数
};

