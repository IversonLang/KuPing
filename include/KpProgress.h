#pragma once
#include <sys/stat.h>
#include <windows.h>
#include <tlhelp32.h>

namespace CKpProgress
{
	//根据进程ID获取窗口句柄
	HWND PidToWnd(DWORD dwProcessID);
	//获取进程ID
	UINT GetProcessId(LPCTSTR pszExeFile);
	//获取进程
	BOOL GetProcessId(LPSTR pszExeName,UINT& unId);
	//开启进程
	void RunExe( const char* pFile,const char* pParma );

};

