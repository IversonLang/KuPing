#pragma once
#import"C:/Program Files/Common Files/System/ado/msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#import"C:/Program Files/Common Files/System/ado/Msadox.dll"  rename_namespace("ADOCG") rename("EOF", "adoXEOF") rename("DataTypeEnum","adoXDataTypeEnum")  
using namespace ADOCG;
#define TESTHR(x) if FAILED(x) _com_issue_error(x);
#pragma warning (disable: 4146)
#pragma warning (default: 4146)
#include<stdio.h>
#include<iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;

struct FIELDSINFO
{
	FIELDSINFO(){
		IsSetZero=true;//是否清零
		IsSetPrimaryKey=false;//是否设为主键
	}
	string strFieldsName;//字段名
	bool IsSetZero;//是否清零
	bool IsSetPrimaryKey;//是否设为主键
};

class CKpAdoDatabase
{
public:
	CKpAdoDatabase(void);
	virtual ~CKpAdoDatabase(void);
public:
	BOOL OpenMdb(LPSTR szMdbPath);//创建Connection接口 链接数据库
	void OpenMdbTable(LPCSTR pszTableNmae);//打开数据库表 
	void CloseTable();//关闭记录集表
	void Close(); //关闭数据库连接
public:
	void AddNew(LONG lnIndex=0,LPSTR Value="0");//添加记录
	void SetValue(LONG lnIndex,LPCSTR Value);//修改记录
	void Delete(_In_ int iIndex,_In_ int nCount = 1);
	void FindData(LPCSTR pszTableNmae,LPCSTR pszWhereKey,LPCSTR pszValue,vector<LPCSTR>& vecName);//根据条件查询（SQL） 获取记录集
public:
	ULONG GetrecordCount();//获取记录集的数量
	ULONG GetFieldCount();//获取字段的数量
	BOOL GetFieldInfo(long nIndex,string& strName);//获取字段的信息
	BOOL GetFieldCollect(long nIndex,string& strName);//获取记录
	void MoveNext();//游标向后
	void MovePrevious();//游标向前
	void MoveFirst();//头
	void MoveLast();//尾
	BOOL IsBOF();     //判断游标指针是否在记录头部
	BOOL IsEOF();     //判断游标指针是否在记录尾部
	void Update();//更新数据库
public:
	BOOL IsHaveFile( LPSTR pszPath );
	BOOL CreateMdb(string strMdbName);//创建ACCESS数据库 
	BOOL CreateTable( string strMdbName,string strTabName,vector<FIELDSINFO*>& vecFields);//创建数据库表
	BOOL IsTalbeExit(string strTable);//判断一个表在数据库中是否存在
public:
	_ConnectionPtr m_pConnection;//定义ADO数据库连接指针
	_RecordsetPtr m_pRecordset;//定义记录集指针
};

