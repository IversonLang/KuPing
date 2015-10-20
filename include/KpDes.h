#pragma once
#include<windows.h>
#include <string>
using namespace std;

#ifndef   ENCRYPT
#define   ENCRYPT  0         /* DES 方向 */
#define   DECRYPT  1
#endif

#ifndef   STAND
#define   STAND    0         /* MAC 标准 */
#define   BPI      1
#endif

typedef unsigned int        UINT;
#define SAFE_DELETE(ptr) do{ if(ptr) {delete ptr; ptr=NULL;} }while(0)
#define SAFE_CREATEARRAY(a,b,c) a b[c]; memset(b,0,sizeof(a) * c);
#define SAFE_CREATELP(a,b,c) a *b = new a[c]; memset(b,0,sizeof(a) * c);
#define SAFE_INITLP(a,b,c)b = new a[c]; memset(b,0,sizeof(a) * c);
#define SAFE_lP(a,b) a * b = NULL;


class CKpDes
{
public:
    CKpDes(void);
    ~CKpDes(void);
public:
	void GetDesKey(LPBYTE pbyKey, int n);
	void Encrypt0(LPBYTE pbyText, LPBYTE pbyMtext);
	void Discrypt0(LPBYTE pbyMtext, LPBYTE pbyText);
	void Expand0(LPBYTE pbyIn, LPSTR pszOut);
	void Compress0(LPBYTE pbyOut, LPBYTE pbyIn);
	void Compress016(LPBYTE pbyOut, LPBYTE pbyIn);

	void Setkeystar(LPBYTE pbyBits);
	void LS(LPSTR pbyBits, LPSTR pszBuffer, int nCount);
	void Son(LPSTR pszCc, LPSTR pszDd, LPSTR pszKk);

	void Ip(LPBYTE pbyText, LPBYTE pbyLl, LPBYTE pbyRr);
	void _Ip(LPBYTE pbyText, LPBYTE pbyLl, LPBYTE pbyRr);
	void _FFT(int n, LPSTR ll, LPSTR rr, LPSTR LL, LPSTR RR);
	void S_box(LPSTR pszAa, LPSTR pszBb);
	void Des_thre_KEY(LPBYTE pbySource,LPBYTE pbyDest,LPBYTE pbyKey,char szFlag,int  nLeng );
	/*
	DES加密解密程序
	参数:  source --- 源(8字节16进制)
	dest   --- 目标(8字节16进制)
	key    --- KEY值(8字节16进制)
	flag   --- ENCRYPT 加密
	DECRYPT 解密
	*/
	LPSTR DesStr( LPSTR pszSource,LPSTR pszKey, int nLeng,LPUINT punOutleng);//加密 字符串
	LPSTR DiscryptDesStr( LPSTR pszSource,LPSTR pszKey, int nLeng,LPUINT punOutleng ); //解密 字符串;
	void Des(LPBYTE pbySource, LPBYTE pbyDest,LPBYTE pbyKey, BYTE pbyFlag);
	void DesMac(LPBYTE pbySource, int iLen, LPBYTE pbyDest,LPBYTE pbyKey);
	void Do_XOR(LPBYTE pbyDest, LPBYTE pbySource, int nSize);
	void HEX_2_DSP(LPBYTE pbyHex, LPBYTE pbyDsp, int nCount);
	void DSP_2_HEX(LPBYTE pbyDsp, LPBYTE pbyHex, int nCount);
	void Cdes(LPSTR pszSource,  LPSTR pszDest,LPSTR pszKey,  char pszFlag); //0 加密 1解密
	void Des_thre(LPBYTE pbySource,LPBYTE pbyDest,LPBYTE pbyKey,char szFlag,int  nLeng );
public:
	BYTE C[17][28];
	BYTE D[17][28];
	BYTE K[17][48];
	BYTE c;
	BYTE ch1;
};

