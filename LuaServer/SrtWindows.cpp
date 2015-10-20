#include "SrtWindows.h"
#include "Script.h"
#pragma comment(lib,"../lib/Kplib.lib")
#include "../include/KpLib.h"


int Srt_MessageBox(lua_State* ls)
{
    const char* szMsg = NULL;
	int   nMsg        = 0;
    const char* szTitle = NULL;
    unsigned int unType = MB_OK;
    
    //信息
    if (lua_isstring(ls,1)){
        szMsg = lua_tostring(ls,1);
    }else if(lua_isnumber(ls,1)){
		nMsg=lua_tonumber(ls,1);
	}
    //标题
    if (lua_isstring(ls,2)){
        szTitle = lua_tostring(ls,2);
    }
    //对话框类型
	unsigned int unTypetmp =0;
    if (lua_isnumber(ls,3)){
        unTypetmp = lua_tounsigned(ls,3);
    }
	if (unType!=0){
		unType=unTypetmp;
	}
	int nRs;
	if (szMsg==NULL){
		char szTmp[256]={0};
		sprintf(szTmp,"%d",nMsg);
		nRs= MessageBox(NULL,szTmp,szTitle,unType);
	}else{
		nRs= MessageBox(NULL,szMsg,szTitle,unType);
	}
    lua_pushinteger(ls,nRs);
    return 1;
}

int Srt_PostMessage(lua_State* ls)
{
    HWND hWnd = NULL;
    UINT msg = 0;
    WPARAM wParam = 0;
    LPARAM lParam = 0;

    //HWND
    if (lua_isnumber(ls,1)){
        hWnd = (HWND)lua_tounsigned(ls,1);
    }
    //MESSAGE
    if (lua_isnumber(ls,2)){
        msg = lua_tounsigned(ls,2);
    }
    //WPARAM
    if (lua_isnumber(ls,3)){
        wParam = lua_tounsigned(ls,3);
    }
    //LPARAM
    if (lua_isnumber(ls,4)){
        lParam = lua_tounsigned(ls,4);
    }

    BOOL bRs = PostMessage(hWnd,msg,wParam,lParam);
    lua_pushboolean(ls,bRs);
    return 1;
}

int Srt_SendMessage(lua_State* ls)
{
    HWND hWnd = NULL;
    UINT msg = 0;
    WPARAM wParam = 0;
    LPARAM lParam = 0;

    //HWND
    if (lua_isnumber(ls,1)){
        hWnd = (HWND)lua_tounsigned(ls,1);
    }
    //MESSAGE
    if (lua_isnumber(ls,2)){
        msg = lua_tounsigned(ls,2);
    }
    //WPARAM
    if (lua_isnumber(ls,3)){
        wParam = lua_tounsigned(ls,3);
    }
    //LPARAM
    if (lua_isnumber(ls,4)){
        lParam = lua_tounsigned(ls,4);
    }

    BOOL bRs = SendMessage(hWnd,msg,wParam,lParam);
    lua_pushboolean(ls,bRs);
    return 1;
}

int Srt_FindWindow(lua_State* ls)
{
    const char* szClssName = NULL;
    const char* szWndTitle = NULL;
   
    //Window Class Name
    if (lua_isstring(ls,1)){
        szClssName = lua_tostring(ls,1);
    }
    //Window Title
    if (lua_isstring(ls,2)){
        szWndTitle = lua_tostring(ls,2);
    }

    HWND hWnd = FindWindow(szClssName,szWndTitle);
    lua_pushinteger(ls,(unsigned int)hWnd);
    return 1;
}

int Srt_DeleteFile(lua_State* ls)
{
    const char* szFileName = NULL;

    if (lua_isstring(ls,1)){
        szFileName = lua_tostring(ls,1);
    }

    BOOL bRs = DeleteFile(szFileName);
    lua_pushboolean(ls,bRs);
    return 1;
}

int Srt_DeleteDir(lua_State* ls)
{
    const char* szDir = NULL;

    if (lua_isstring(ls,1)){
        szDir = lua_tostring(ls,1);
    }
    
    BOOL bRs = RemoveDirectory(szDir);
    lua_pushboolean(ls,bRs);
    return 1;
}

int Srt_Md5(lua_State* ls)
{
	const char* szBuff = NULL;
	unsigned int nBuffSize = 0;

	if (lua_isstring(ls,1)){
		szBuff = lua_tostring(ls,1);
	}
	nBuffSize = strlen(szBuff);

	if (lua_isnumber(ls,2)){
		nBuffSize = lua_tounsigned(ls,2);
	}

	CKpMd5 oMd5(szBuff,nBuffSize);
	lua_pushfstring(ls,"%s",oMd5.toString().c_str());
	return 1;
}

int Str_UnRarFile(lua_State* ls)
{
	const char* szPathName = NULL;
	const char* szPath = NULL;
	if (lua_isstring(ls,1)){
		szPathName = lua_tostring(ls,1);
	}
	if (lua_isstring(ls,2)){
		szPath = lua_tostring(ls,2);
	}
	BOOL bRs =CKpRar::UnRarFile((LPSTR)szPathName,(LPSTR)szPath);
	lua_pushboolean(ls,bRs);
	return 1;
}

//返回table ()数组
int Str_Split(lua_State* ls)
{
	const char* szStr = NULL;
	const char* szMark = NULL;
	if (lua_isstring(ls,1)){
		szStr = lua_tostring(ls,1);
	}
	if (lua_isstring(ls,1)){
		szMark = lua_tostring(ls,2);
	}
	vector<string> vecStr;
	CKpString::Split(szStr,szMark,vecStr);
	//返回数组
	lua_newtable(ls);// 新建table
	for (int i=0;i<vecStr.size();i++){
		lua_pushfstring(ls,"%s",vecStr[i].c_str());//数据入栈
		lua_rawseti(ls, -2, i+1);//将数据压栈顶
	}
	return 1;//返回值个数
}

//获取文件夹
int Str_ScanFolder(lua_State* ls)
{
	const char* szPath = NULL;
	if (lua_isstring(ls,1)){
		szPath = lua_tostring(ls,1);
	}
	vector<FileInfoStruct*> vecOut;
	CKpFindFile::ScanFolder(szPath,vecOut);
	//返回map
	lua_newtable(ls);
	for (int i=0;i<vecOut.size();i++){
		lua_pushfstring(ls,"%s",vecOut[i]->sFileName.c_str());//map  value 值
		lua_setfield(ls,-2,vecOut[i]->sFullPath.c_str());//map Key 键
	}
	return 1;
}

//获取文件
int Str_ScanFile(lua_State* ls)
{
	const char* szPath = NULL;
	const char* szMark = NULL;
	if (lua_isstring(ls,1)){
		szPath = lua_tostring(ls,1);
	}
	if (lua_isstring(ls,2)){//后缀
		szMark = lua_tostring(ls,2);
	}
	vector<FileInfoStruct*> vecOut;
	if (strlen(szMark)>0){
		CKpFindFile::ScanFile(szPath,vecOut,szMark);
	}else{
		CKpFindFile::ScanFile(szPath,vecOut);
	}
	//返回map
	lua_newtable(ls);
	for (int i=0;i<vecOut.size();i++){
		lua_pushfstring(ls,"%s",vecOut[i]->sFileName.c_str());//map  value 值
		lua_setfield(ls,-2,vecOut[i]->sFullPath.c_str());//map Key 键
	}
	return 1;
}

//检测路径下是否有子文件
int Str_HaveChildFile(lua_State* ls)
{
	const char* szPath = NULL;
	if (lua_isstring(ls,1)){
		szPath = lua_tostring(ls,1);
	}
	BOOL bFlag=CKpFindFile::HaveChildFile(szPath);
	lua_pushboolean(ls,bFlag);
	return 1;
}

//检测路径下是否有子路径
int Str_HaveChildFolder(lua_State* ls)
{
	const char* szPath = NULL;
	if (lua_isstring(ls,1)){
		szPath = lua_tostring(ls,1);
	}
	BOOL bFlag=CKpFindFile::HaveChildFolder(szPath);
	lua_pushboolean(ls,bFlag);
	return 1;
}

//检测卷类型
int Str_GetType(lua_State* ls)
{
	const char* szPath = NULL;
	if (lua_isstring(ls,1)){
		szPath = lua_tostring(ls,1);
	}
	TCHAR szTmp[MAX_PATH]={0};
	strcpy(szTmp,szPath);
	LPCTSTR szType=CKpFindFile::GetType(szTmp);
	lua_pushfstring(ls,szType);
	return 1;
}

//获取系统特殊文件信息到数组
int Str_GetSystemFile(lua_State* ls)
{
	vector<FileInfoStruct*> vecOut;
	CKpFindFile::GetSystemFile(vecOut);
	//返回map
	lua_newtable(ls);
	for (int i=0;i<vecOut.size();i++){
		lua_pushfstring(ls,"%s",vecOut[i]->sFileName.c_str());//map  value 值
		lua_setfield(ls,-2,vecOut[i]->sFullPath.c_str());//map Key 键
	}
	return 1;
}

//CKpBase64 加密
int Str_Encrypt(lua_State* ls)
{
	const char* pszSrc = NULL;
	if (lua_isstring(ls,1)){
		pszSrc = lua_tostring(ls,1);
	}
	int nSise=0;
	if (lua_isnumber(ls,2)){
		nSise = lua_tonumber(ls,2);
	}
	DWORD dwBase64StrSeze=nSise*2;
	LPBYTE pbyDst =new BYTE[dwBase64StrSeze];
	string strErrStr;
	CKpBase64 base64;
	base64.Encrypt((LPCBYTE)pszSrc,nSise,pbyDst,&dwBase64StrSeze,strErrStr);
	lua_pushfstring(ls,(LPCSTR)pbyDst);
	lua_pushnumber(ls,dwBase64StrSeze);
	lua_pushfstring(ls,strErrStr.c_str());
	return 3;
}

//CKpBase64 解密
int Str_Decrypt(lua_State* ls)
{
	const char* pszSrc = NULL;
	if (lua_isstring(ls,1)){
		pszSrc = lua_tostring(ls,1);
	}
	int nSise=0;
	if (lua_isnumber(ls,2)){
		nSise = lua_tonumber(ls,2);
	}
	DWORD dwBase64StrSeze=nSise;
	LPBYTE pbyDst =new BYTE[dwBase64StrSeze];
	string strErrStr;
	CKpBase64 base64;
	base64.Decrypt((LPCBYTE)pszSrc,nSise,pbyDst,&dwBase64StrSeze,strErrStr);
	LPBYTE pbyDsts =new BYTE[dwBase64StrSeze];
	memcpy(pbyDsts,pbyDst,dwBase64StrSeze);
	delete []pbyDst;
	lua_pushfstring(ls,(LPCSTR)pbyDsts);
	lua_pushnumber(ls,dwBase64StrSeze);
	lua_pushfstring(ls,strErrStr.c_str());
	return 3;
}

//Browser 浏览器
int Str_Browser(lua_State* ls)
{
	const char* pszUrl = NULL;
	int nWidth=0,nHeight=0;
	BOOL bFlag=FALSE;
	if (lua_isstring(ls,1)){
		pszUrl = lua_tostring(ls,1);
	}
	if (lua_isnumber(ls,2)){
		nWidth = lua_tonumber(ls,2);
	}
	if (lua_isnumber(ls,3)){
		nHeight = lua_tonumber(ls,3);
	}
	if (lua_isboolean(ls,4)){
		bFlag = lua_toboolean(ls,4);
	}
	//DLL浏览器 
	typedef void (*SHOWBROWSER)(LPCSTR strUrl,int nWidth,int nHeight,BOOL bIsObstruct); 
	HMODULE hModule=( HMODULE )LoadLibrary("..\\Bin\\browser.dll");
	SHOWBROWSER ShowBrowser = (SHOWBROWSER)GetProcAddress( hModule, "ShowBrowser" );
	ShowBrowser(pszUrl,nWidth,nHeight,bFlag);

	BOOL bFlags=TRUE;
	lua_pushboolean(ls,bFlags);
	return 1;
}


static const luaL_Reg WindowsLib[] = {
    {"MessageBox",          Srt_MessageBox},
    {"PostMessage",         Srt_PostMessage},
    {"SendMessage",         Srt_SendMessage},
    {"FindWindow",          Srt_FindWindow},
    {"DeleteFile",          Srt_DeleteFile},
    {"DeleteDir",           Srt_DeleteDir},
	{"Md5",					Srt_Md5},
	{"UnRarFile",           Str_UnRarFile},
	{"Split",               Str_Split},
	{"ScanFolder",          Str_ScanFolder},
	{"ScanFile",            Str_ScanFile},
	{"HaveChildFile",       Str_HaveChildFile},
	{"HaveChildFolder",     Str_HaveChildFolder},
	{"GetType",             Str_GetType},
	{"GetSystemFile",       Str_GetSystemFile},
	{"Encrypt",             Str_Encrypt},
	{"Decrypt",             Str_Decrypt},
	{"Browser",             Str_Browser},
    {NULL, NULL}
};

int ex_Windows(lua_State* ls)
{
    luaL_newlib(ls,WindowsLib);
    return 1;
}