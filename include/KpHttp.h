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
	BOOL CreateForm(LPSTR szAction,BOOL bMethod,LPSTR szEnctype);  //������Ҫ�ύ�ı�
	void AddTextParam(LPSTR szField,LPSTR szValue);    //��������ı��ֶ�
	void AddFileParam(LPSTR szField,LPSTR szPath);     //���������Ҫ�ϴ����ļ�

	int  SubmitForm(string& strResponse);					//�����ύ��
	void SubmitForm(HWND hwnd,DWORD dwMsg,DWORD dwData=0);	//�첽���ύ (����Ϣ)
	void SubmitForm(HTTP_FORM_CALL_BACK_PROC pFunc,LPVOID wParam,string& lParam);//�첽���ύ (�ص�����)
	void SubmitForm();                                      //�첽�ύ�� (���ܽ��)  //���Ż������ڲ���һ��ʵ��ͬ�½��ж���߳�
	static UINT SubmitFormThread(LPVOID lp);				//�첽�ύ�̺߳���
	void StopSubmit();

	static BOOL GetRequest( const char* szUrl,string& sRespons );
	static unsigned short GetPortOfUrl( const char* szUrl );
	static BOOL GetPathOfUrl( const char* szUrl,char* szPath,int nLens );
	static BOOL GetHostOfUrl( const char* szUrl,char* szHost,int nLens );
	static void GetReturnCode( const char* szUrl,string& sRespons,int& nReturnCode );

	void SetFormHost(LPSTR szHost);                     //���ñ��ύ������
	void SetFormAction(LPSTR szAction);					//�����ύ��·��
	void SetFormMothod(BOOL bMethod);					//���÷�ʽ
	void SetFormEnctype(LPSTR szEnctype);				//���ñ������ύ����

	BOOL IsWorking();                                   //�������Ƿ������첽�ύ����

	void SetCompleteMsg(HWND hwnd, DWORD dwMsg,DWORD dwData = 0);
	LPSTR GetFormField(LPSTR strKey);   //��ȡ���ֶ�
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
	BOOL m_bisWorking;					//�Ƿ������첽�ύ
	string m_strGetParam;
	BOOL m_bIsStop;
	DWORD m_dwCompleteData;
	DWORD m_dwCompleteMsg;
	HWND  m_hCompleteWnd;
public:
	static int m_nReturnCode;
};

