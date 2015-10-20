#pragma once
#include <Windows.h>
#define SYNCHRO_SECTION				0x00000001
#define SYNCHRO_EVENT				0x00000002
#define SYNCHRO_MUTUALEXCLUSION		0x00000003
#define SYNCHRO_SEMAPHORE			0x00000004
#define SYNCHRO_WAITABLETIMER		0x00000005
namespace CKpThreadSynchro
{
	//�����߳�
	HANDLE BeginThred(LPTHREAD_START_ROUTINE pThreadName,LPVOID pParam,DWORD& dwPID);
	//�����߳�
	void EndThread(DWORD dwExitCode);

	//ָ�봫���ࣨ���ࣩ 
	class CKpThreadSynchronizationBase
	{
	public:
		CKpThreadSynchronizationBase(){}
		~CKpThreadSynchronizationBase(){}

		virtual void Lock(UINT64 nDueTime=0,LONG nTime=0){}
		virtual void UnLock(){}
		virtual void WaitUp(){}
	};
	//�ٽ���
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
	//�¼�
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
	//������
	class CKpThreadMutualExclusion :public CKpThreadSynchronizationBase
	{
		HANDLE m_hMutex;
	public:
		CKpThreadMutualExclusion();
		~CKpThreadMutualExclusion();

		virtual void Reset();
		virtual void WaitUp();
	};
	//�ź���
	class CKpThreadSemaphore :public CKpThreadSynchronizationBase
	{
		HANDLE m_hSemaphore;
	public:
		CKpThreadSemaphore();
		~CKpThreadSemaphore();

		virtual void UnLock();
		virtual void WaitUp();
	};
	//�ɵȺ�ʱ��
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

