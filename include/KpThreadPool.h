#pragma once
#include <windows.h>   
#include <iostream>   
#include <tchar.h>  
#include <vector> 
using namespace std; 
//工作函数指针类型
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
	void SingleWorkItem(WORKITEM cFunction,LPVOID pwParam,DWORD dwFlag=WT_EXECUTELONGFUNCTION);//一次添加单个线程
	void MultiWorkItem(vector<FUNCTIONINFO*>& vecFunction) ;//一次添加多个线程
};

