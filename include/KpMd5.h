#pragma once
#include <windows.h>
#include <string>
#include <fstream>
typedef unsigned char byte;
typedef unsigned long ulong;
using std::string;
using std::ifstream;

class CKpMd5
{
public:
    CKpMd5(void);
	CKpMd5(const void *input, size_t length);
	CKpMd5(const string &str);
	CKpMd5(ifstream &in);
    ~CKpMd5(void);
public:
	void update(const void *input, size_t length);
	void update(const string &str);
	void update(ifstream &in);
	const byte* digest();
	string toString();
	void reset();
private:
	void update(const byte *input, size_t length);
	void final();
	void transform(const byte block[64]);
	void encode(const ulong *input, byte *output, size_t length);
	void decode(const byte *input, ulong *output, size_t length);
	string bytesToHexString(const byte *input, size_t length);
	//Àà²»ÄÜ¿½±´
	CKpMd5(const CKpMd5&);
	CKpMd5& operator=(const CKpMd5&);
private:
	ulong _state[4];				/* state (ABCD) */
	ulong _count[2];				/* number of bits, modulo 2^64 (low-order word first) */
	byte _buffer[64];				/* input buffer */
	byte _digest[16];				/* message digest */
	bool _finished;					/* calculate finished ? */
	static const byte PADDING[64];	/* padding for calculate */
	static const char HEX[16];
	//	static const size_t BUFFER_SIZE = 1024;
};
