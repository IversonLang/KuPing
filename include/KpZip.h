#pragma once
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "zlib.h"
#pragma comment(lib,"../lib/Kpzdll.lib")

namespace CKpZip
{
	int Compress(Bytef *data, uLong ndata,Bytef *zdata, uLong *nzdata); //��ѹ
	int Uncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata); //��ѹ
	int GzCompress(Bytef *data, uLong ndata, Bytef *zdata, uLong *nzdata);//gzip��ѹ
	int GzUncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata); //gzip��ѹ
	int HttpGzUncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata); //HTTP gzip ��ѹ
};



