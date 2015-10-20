#pragma once

#define XYSSL_ERR_BASE64_BUFFER_TOO_SMALL -0x0010   
#define XYSSL_ERR_BASE64_INVALID_CHARACTER -0x0012   

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;

#define SAFE_DELETE(ptr) do{ if(ptr) {delete ptr; ptr=NULL;} }while(0)
#define SAFE_INITLP(a,b,c)b = new a[c]; memset(b,0,sizeof(a) * c);

class CKpBase64
{ 
public:
	CKpBase64(){};
	virtual ~CKpBase64(){};
public:
	BOOL Encrypt(LPCBYTE pbySrc, int nLen,LPBYTE pbyDst, LPDWORD pdwLen,string& strErrorInfo);  
	BOOL Decrypt(LPCBYTE pbySrc, int nLen,LPBYTE pbyDst, LPDWORD pdwLen,string& strErrorInfo);  
private:
	int Base64Encode(LPCBYTE pbySrc, int nLen,LPBYTE pbyDst, LPDWORD pdwLen);
	int Base64Decode(LPCBYTE pbySrc, int nLen,LPBYTE pbyDst, LPDWORD pdwLen);
};

