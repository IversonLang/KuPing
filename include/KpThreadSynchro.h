#pragma once
#include <Windows.h>
#define SYNCHRO_SECTION				0x00000001
#define SYNCHRO_EVENT				0x00000002
#define SYNCHRO_MUTUALEXCLUSION		0x00000003
#define SYNCHRO_SEMAPHORE			0x00000004
#define SYNCHRO_WAITABLETIMER		0x00000005
namespace CKpThreadSynchro
{
	//创建线程
	HANDLE BeginThred(LPTHREAD_START_ROUTINE pThreadName,LPVOID pParam,DWORD& dwPID);
	//结束线程
	void EndThread(DWORD dwExitCode);

	//指针传递类（父类） 
	class CKpThreadSynchronizationBase
	{
	public:
		CKpThreadSynchronizationBase(){}
		~CKpThreadSynchronizationBase(){}

		virtual void Lock(UINT64 nDueTime=0,LONG nTime=0){}
		virtual void UnLock(){}
		virtual void WaitUp(){}
	};
	//临界区
	class CKpThreadSection :public CKpThreadSynchronizationBase
	{
		RTL_CRITICAL_SECTION Section;
	public:
		CKpThreadSection();
		~CKpThreadSection();
	public:

		virtual void Lock(UINT64 nDueTime=0,LONG nTime=0);
		virtual void UnLock();
	};
	//事件
	class CKpThreadEvent :public CKpThreadSynchronizationBase
	{
		HANDLE m_hEvent ;
	public:
		CKpThreadEvent();
		~CKpThreadEvent();

		virtual void Lock(UINT64 nDueTime=0,LONG nTime=0);
		virtual void UnLock();
		virtual void WaitUp();
	};
	//互斥量
	class CKpThreadMutualExclusion :public CKpThreadSynchronizationBase
	{
		HANDLE m_hMutex;
	public:
		CKpThreadMutualExclusion();
		~CKpThreadMutualExclusion();

		virtual void Reset();
		virtual void WaitUp();
	};
	//信号量
	class CKpThreadSemaphore :public CKpThreadSynchronizationBase
	{
		HANDLE m_hSemaphore;
	public:
		CKpThreadSemaphore();
		~CKpThreadSemaphore();

		virtual void UnLock();
		virtual void WaitUp();
	};
	//可等候定时器
	class CKpThreadWaitableTimer :public CKpThreadSynchronizationBase
	{
		HANDLE m_hTimer;
	public:
		CKpThreadWaitableTimer();
		~CKpThreadWaitableTimer();

		virtual void SetTimer(UINT64 nDueTime=0,LONG nTime=0);
		virtual void WaitUp();
	};

};

