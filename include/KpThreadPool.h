#pragma once
#include <windows.h>   
#include <iostream>   
#include <tchar.h>  
#include <vector> 
using namespace std; 
//��������ָ������
typedef DWORD(WINAPI* WORKITEM)(LPVOID);
struct FUNCTIONINFO{
	FUNCTIONINFO(){
		cFunction=NULL;
		pwParam=NULL;
		dwFlag=WT_EXECUTELONGFUNCTION;
	}
	WORKITEM cFunction;
	LPVOID   pwParam;
	DWORD    dwFlag;
};
class CKpThreadPool
{
public:
    CKpThreadPool(void);
    ~CKpThreadPool(void);
public: 
	void SingleWorkItem(WORKITEM cFunction,LPVOID pwParam,DWORD dwFlag=WT_EXECUTELONGFUNCTION);//һ����ӵ����߳�
	void MultiWorkItem(vector<FUNCTIONINFO*>& vecFunction) ;//һ����Ӷ���߳�
};

