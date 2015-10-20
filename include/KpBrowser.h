#pragma once
#include <Windows.h>
#include <string>
using namespace std;
#include <shlobj.h>
#include "shellapi.h"
#pragma comment( lib, "shell32.lib")
#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#pragma comment(lib,"atl")
#pragma comment(lib,"User32.lib")

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

class CKpBrowser
{
public:
	CKpBrowser(HWND hWnd);
	~CKpBrowser(void);
public:
	void Open(const char* szUrl);
	static void Init(HINSTANCE hInstance);
public:
	static CComModule ms_Module;
	static CAxWindow ms_WinContainer;
	static GUID ms_Guid;
	static BOOL ms_bIsInit;
	IWebBrowser2* m_iWebBrowser;
};


