#pragma once
#include <Windows.h>
#include <cassert>
#include <string>
#include "KpUnRar.h"

namespace CKpRar
{
	BOOL UnRarFile(LPSTR pszRarPath,LPSTR pszUnRarPath);//解压rar
	BOOL ResourcesRarFile(  DWORD dwResoucesID,LPCSTR pszIpType,LPCSTR pszRarPath );//VC资源存为rar文件使用

	class CInstanceUnRar
	{
		typedef HANDLE (PASCAL *_RAROpenArchive)(struct RAROpenArchiveData *ArchiveData);
		typedef HANDLE (PASCAL *_RAROpenArchiveEx)(struct RAROpenArchiveDataEx *ArchiveData);
		typedef int    (PASCAL *_RARCloseArchive)(HANDLE hArcData);
		typedef int    (PASCAL *_RARReadHeader)(HANDLE hArcData,struct RARHeaderData *HeaderData);
		typedef int    (PASCAL *_RARReadHeaderEx)(HANDLE hArcData,struct RARHeaderDataEx *HeaderData);
		typedef int    (PASCAL *_RARProcessFile)(HANDLE hArcData,int Operation,char *DestPath,char *DestName);
		typedef int    (PASCAL *_RARProcessFileW)(HANDLE hArcData,int Operation,wchar_t *DestPath,wchar_t *DestName);
		typedef void   (PASCAL *_RARSetCallback)(HANDLE hArcData,UNRARCALLBACK Callback,LPARAM UserData);
		typedef void   (PASCAL *_RARSetChangeVolProc)(HANDLE hArcData,CHANGEVOLPROC ChangeVolProc);
		typedef void   (PASCAL *_RARSetProcessDataProc)(HANDLE hArcData,PROCESSDATAPROC ProcessDataProc);
		typedef void   (PASCAL *_RARSetPassword)(HANDLE hArcData,char *Password);
		typedef int    (PASCAL *_RARGetDllVersion)();

		_RAROpenArchive			RAROpenArchive;
		_RAROpenArchiveEx		RAROpenArchiveEx;
		_RARCloseArchive		RARCloseArchive;
		_RARReadHeader			RARReadHeader;
		_RARReadHeaderEx		RARReadHeaderEx;
		_RARProcessFile			RARProcessFile;
		_RARProcessFileW		RARProcessFileW;
		_RARSetCallback			RARSetCallback;
		_RARSetChangeVolProc	RARSetChangeVolProc;
		_RARSetProcessDataProc	RARSetProcessDataProc;
		_RARSetPassword			RARSetPassword;
		_RARGetDllVersion		RARGetDllVersion;
	public:
		CInstanceUnRar();
		~CInstanceUnRar();
	public:
		FARPROC         GetProcAddress( const char *lpProcName);
		void			Entry();
		void			Run();
		void			Leave();
	private:
		HMODULE m_hLib;
	};

	class CUnRarFile  
	{
	public:
		CUnRarFile();
		virtual ~CUnRarFile(); 
	public:
		BOOL			Open( const char *lpRarFile, UINT uOpenMode);
		BOOL			ReadHeader( RARHeaderDataEx *lpHeaderData );
		BOOL			UnpFile( int Operation = RAR_EXTRACT, char *lpDestPath = NULL, char *lpDestName = NULL);
		BOOL			SetCallBack( UNRARCALLBACK Callback, LPARAM UserData );
		static int		GetItemCount( const char *lpRarFile, LPDWORD lpdwFileCount, LPDWORD lpdwDirCount);
		static BOOL		GetItemSize( const char *lpRarFile, PLARGE_INTEGER lpliSize );
		BOOL			Close();
	private:
		HANDLE			m_hVal;
		std::string		m_strVal;
		//		CProgressCtrl*  m_lpProgressCtrl;
	};
};


