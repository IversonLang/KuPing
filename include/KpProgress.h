#pragma once
#include <sys/stat.h>
#include <windows.h>
#include <tlhelp32.h>

namespace CKpProgress
{
	//���ݽ���ID��ȡ���ھ��
	HWND PidToWnd(DWORD dwProcessID);
	//��ȡ����ID
	UINT GetProcessId(LPCTSTR pszExeFile);
	//��ȡ����
	BOOL GetProcessId(LPSTR pszExeName,UINT& unId);
	//��������
	void RunExe( const char* pFile,const char* pParma );

};

