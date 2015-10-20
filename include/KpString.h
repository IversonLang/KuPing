#pragma once
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;

namespace CKpString
{
	void ByteToWChar(LPCSTR szByte, std::wstring& wstr);                 //խ�ֽ�ת���ֽ�
	void WCharToByte(wchar_t* szWChar, std::string& strByte);            //���ֽ�תխ�ֽ�
	string WCharToUTF8(const std::string& strGBK);                       //GB2132��չ��תUTF_8
	string UTF8ToWChar(const std::string& strUTF8);                      //UTF_8תGB2132��չ��
	BOOL Split(LPCSTR pszStr,LPCSTR pszMark,vector<string>& vecStr);     //�ָ��ַ����浽vecctor
	LPSTR FtoA(double douData, int nCount, LPSTR buff);                  //������ת��Ϊ�ַ��� �����ַ� 
	LPSTR FtoAe(double douData, int nCount, LPSTR buff);                 //������ת��Ϊ�ַ��� �����ַ� ���ؿ�ѧ��������ʾ
	int GetCharCount(LPSTR pszBuf,int& nChineseChar);                    //��ȡ�ַ����ַ�������������ָ����������ַ�����
	double AtoF(LPSTR pszBuf);                                           //�ַ�ת������
};

