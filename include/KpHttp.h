#pragma once
#if !defined(HTTP_FORM_)
#define HTTP_FORM_ENCTYPE_NORMAL "application/x-www-form-urlencoded"
#define HTTP_FORM_ENCTYPE_UPLOAD "multipart/form-data"
#define HTTP_FORM_ENCTYPE_TEXT   "text/plain"
#define HTTP_FORM_METHOD_GET     FALSE
#define HTTP_FORM_METHOD_POST    TRUE

#endif
//#include <Winsock2.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")
#include "KpZip.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
typedef UINT (*HTTP_FORM_CALL_BACK_PROC)(LPVOID,string);


class CKpHttp
{
public:
	struct buff_ST{
		char* buff;
		DWORD nLenght;
	};
public:
    CKpHttp(LPSTR szHost);
    virtual ~CKpHttp(void);
public:
	BOOL CreateForm(LPSTR szAction,BOOL bMethod,LPSTR szEnctype);  //创建需要提交的表
	void AddTextParam(LPSTR szField,LPSTR szValue);    //给表单添加文本字段
	void AddFileParam(LPSTR szField,LPSTR szPath);     //给表单添加需要上传的文件

	int  SubmitForm(string& strResponse);					//阻塞提交表单
	void SubmitForm(HWND hwnd,DWORD dwMsg,DWORD dwData=0);	//异步表单提交 (发消息)
	void SubmitForm(HTTP_FORM_CALL_BACK_PROC pFunc,LPVOID wParam,string& lParam);//异步表单提交 (回调函数)
	void SubmitForm();                                      //异步提交表单 (不管结果)  //待优化。现在不能一个实例同事进行多个线程
	static UINT SubmitFormThread(LPVOID lp);				//异步提交线程函数
	void StopSubmit();

	static BOOL GetRequest( const char* szUrl,string& sRespons );
	static unsigned short GetPortOfUrl( const char* szUrl );
	static BOOL GetPathOfUrl( const char* szUrl,char* szPath,int nLens );
	static BOOL GetHostOfUrl( const char* szUrl,char* szHost,int nLens );
	static void GetReturnCode( const char* szUrl,string& sRespons,int& nReturnCode );

	void SetFormHost(LPSTR szHost);                     //设置表单提交的主机
	void SetFormAction(LPSTR szAction);					//设置提交的路径
	void SetFormMothod(BOOL bMethod);					//设置方式
	void SetFormEnctype(LPSTR szEnctype);				//设置表单数据提交类型

	BOOL IsWorking();                                   //检查对象是否正在异步提交。。

	void SetCompleteMsg(HWND hwnd, DWORD dwMsg,DWORD dwData = 0);
	LPSTR GetFormField(LPSTR strKey);   //获取表单字段
	void CreateHeader();
protected:
	string GetFileType( string fileExt );
	string GetFileName(const char* full_name);
	string GetFileExt(string full_name);
public:
	string CKpHttp::UTF8Convert(string  str,  int  sourceCodepage,  int  targetCodepage);
	string CKpHttp::URLEncode(string sIn);
	inline BYTE ToHex(const BYTE &x)
	{
		return x > 9 ? x + 55: x + 48;
	}
private:
	static BOOL s_bIsInitSocket;
	map<LPSTR,LPSTR> m_field_Map;
	DWORD  m_dwFormId;
	HWND   m_hWnd;
	DWORD  m_dwMsgUploadRate;
	INT    m_nRateMin;
	INT    m_nRateMax;
	string m_strCookie;
	string m_strHost;
	unsigned short m_nPoint;
	string m_strMethod;
	string m_strEnctype;
	string m_strAction;
	DWORD  m_dwContentLength;
	string m_strHeader;
	string m_strBodyText;
	string m_strEndText;
	vector<buff_ST*> m_fBodyFile_Vct; 
	string m_strBoundary;
	BOOL m_bisWorking;					//是否正在异步提交
	string m_strGetParam;
	BOOL m_bIsStop;
	DWORD m_dwCompleteData;
	DWORD m_dwCompleteMsg;
	HWND  m_hCompleteWnd;
public:
	static int m_nReturnCode;
};

