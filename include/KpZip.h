#pragma once
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "zlib.h"
#pragma comment(lib,"../lib/Kpzdll.lib")

namespace CKpZip
{
	int Compress(Bytef *data, uLong ndata,Bytef *zdata, uLong *nzdata); //加压
	int Uncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata); //解压
	int GzCompress(Bytef *data, uLong ndata, Bytef *zdata, uLong *nzdata);//gzip加压
	int GzUncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata); //gzip解压
	int HttpGzUncompress(Byte *zdata, uLong nzdata, Byte *data, uLong *ndata); //HTTP gzip 解压
};



