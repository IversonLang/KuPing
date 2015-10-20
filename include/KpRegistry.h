#pragma once
#pragma warning(disable : 4786)
#pragma warning(disable : 4503)
#pragma warning(disable : 4530)
#include <string>
#include "KpString.h"
using namespace std;
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
#define MAX_DATA_VALUE 16383
#include <winreg.h>

class CKpRegistry
{
public:
	CKpRegistry(HKEY hKey=HKEY_LOCAL_MACHINE);
	virtual ~CKpRegistry(void);
public:
	BOOL Open(LPCSTR lpSubKey);
	BOOL CreateKey(LPCSTR lpSubKey);
	BOOL SaveKey(LPCSTR lpSubKey);
	BOOL RestoreKey(LPCSTR lpSubKey);
	BOOL Read(LPCSTR lpValueName, LPSTR pBuffer, int& nLen);
	BOOL Read(LPCSTR lpValueName, DWORD& dwVal);
	BOOL Read(LPCSTR lpValueName, int& nVal);
	BOOL Write(LPCSTR lpSubKey, LPSTR pBuffer);
	BOOL Write(LPCSTR lpSubKey, DWORD dwVal);
	BOOL Write(LPCSTR lpSubKey, int nVal);

	BOOL EnumKey(LPCSTR lpSubKey,DWORD& KeyValNum,DWORD& SubKeyNum);
	BOOL EnumKey(LPSTR lpSubKey,DWORD& KeyValNum,DWORD& SubKeyNum);
	BOOL GetValues(int Index,std::string& strKeyName,BYTE* bVal,DWORD& vType);
	BOOL GetSubKeuName(int Index,std::string& strSubName);
	DWORD GetKeyValueNum(){return m_KeyValueNum;}
	DWORD GetSubKeyNum(){return m_SubKeyNum;}

	BOOL DeleteKey(LPCSTR lpSubKey);
	BOOL DeleteValue(LPCSTR lpValueName);
	void Close();
	HKEY GetKey(){return m_hKey;}
public:
	BOOL SetRegedit( HKEY hKEY,LPCSTR strKey,LPCSTR pszVariable,DWORD dwType,LPCSTR pszData );//ÐÞ¸Ä×¢²á±í
	BOOL RemoveRegedit( HKEY hKEY,LPCSTR strKey,LPCSTR pszVariable );//É¾³ý×¢²á±íÏî
	BOOL GetRegedit( HKEY hKEY,LPCSTR strKey,LPCSTR pszVariable,DWORD dwType,string& strData );//²éÑ¯×¢²á±í
protected:
	HKEY m_hKey;
	DWORD m_KeyValueNum;
	DWORD m_SubKeyNum;
};