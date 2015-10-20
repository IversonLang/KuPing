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
		IsSetZero=true;//�Ƿ�����
		IsSetPrimaryKey=false;//�Ƿ���Ϊ����
	}
	string strFieldsName;//�ֶ���
	bool IsSetZero;//�Ƿ�����
	bool IsSetPrimaryKey;//�Ƿ���Ϊ����
};

class CKpAdoDatabase
{
public:
	CKpAdoDatabase(void);
	virtual ~CKpAdoDatabase(void);
public:
	BOOL OpenMdb(LPSTR szMdbPath);//����Connection�ӿ� �������ݿ�
	void OpenMdbTable(LPCSTR pszTableNmae);//�����ݿ�� 
	void CloseTable();//�رռ�¼����
	void Close(); //�ر����ݿ�����
public:
	void AddNew(LONG lnIndex=0,LPSTR Value="0");//��Ӽ�¼
	void SetValue(LONG lnIndex,LPCSTR Value);//�޸ļ�¼
	void Delete(_In_ int iIndex,_In_ int nCount = 1);
	void FindData(LPCSTR pszTableNmae,LPCSTR pszWhereKey,LPCSTR pszValue,vector<LPCSTR>& vecName);//����������ѯ��SQL�� ��ȡ��¼��
public:
	ULONG GetrecordCount();//��ȡ��¼��������
	ULONG GetFieldCount();//��ȡ�ֶε�����
	BOOL GetFieldInfo(long nIndex,string& strName);//��ȡ�ֶε���Ϣ
	BOOL GetFieldCollect(long nIndex,string& strName);//��ȡ��¼
	void MoveNext();//�α����
	void MovePrevious();//�α���ǰ
	void MoveFirst();//ͷ
	void MoveLast();//β
	BOOL IsBOF();     //�ж��α�ָ���Ƿ��ڼ�¼ͷ��
	BOOL IsEOF();     //�ж��α�ָ���Ƿ��ڼ�¼β��
	void Update();//�������ݿ�
public:
	BOOL IsHaveFile( LPSTR pszPath );
	BOOL CreateMdb(string strMdbName);//����ACCESS���ݿ� 
	BOOL CreateTable( string strMdbName,string strTabName,vector<FIELDSINFO*>& vecFields);//�������ݿ��
	BOOL IsTalbeExit(string strTable);//�ж�һ���������ݿ����Ƿ����
public:
	_ConnectionPtr m_pConnection;//����ADO���ݿ�����ָ��
	_RecordsetPtr m_pRecordset;//�����¼��ָ��
};

