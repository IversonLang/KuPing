#pragma once
#include <windows.h>
#include <string>
#include <tchar.h>
#include <vector>
#include <set>
using namespace std;

#ifdef _UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif

struct FileInfoStruct{
	tstring sFileName;
	tstring sFullPath;
};

struct FileInfoParam{
	LPTSTR szFolder;
	UINT unMsg;//要发送的消息
	vector<FileInfoStruct*>* pVecOut;
	LPVOID pParam;
};

namespace CKpFindFile
{
	void ScanFolder( LPCTSTR szFolder,vector<FileInfoStruct*>& vecOut,LPVOID pParam );
	void ScanFolder( LPCTSTR szFolder,vector<FileInfoStruct*>& vecOut );
	void ScanFile(LPCTSTR szFolder,vector<FileInfoStruct*>& vecOut,LPCTSTR szExt = _T("jpg|bmp|png"));
	BOOL HaveChildFile(tstring szFolder);
	BOOL HaveChildFolder(tstring szFolder);
	LPCTSTR GetType( LPTSTR pszDir );
	void ShowVolumneInfo( LPTSTR pszDir,tstring& strName );
	void GetSystemFile(vector<FileInfoStruct*>& vecOut);
	void GetDeskPath(vector<FileInfoStruct*>& vecOut);
	bool GetShellPath(LPCSTR lpwLnkFile, tstring& strPath); 
};
