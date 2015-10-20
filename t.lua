--初始化变量
a,b,c=2,3,4
--函数一
add=function (number1,number2)
	return number1+number2 ;
end

--luaC++扩展使用说明 http://blog.csdn.net/Lodger007/article/details/837349
	
--函数二
function sub(c,a) 
	return c-a;
end
	
Windows.MessageBox(sub(a,b));	

--if语句
if (c>a) then
	--Windows.MessageBox(add(8,b));
end

if (a==2)or(b>a) then
	Windows.MessageBox("max:b or b=2");
	elseif (a==2)or(b<a)then
	Windows.MessageBox("max:a and a~=2");
	else
	Windows.MessageBox("max:a or a~=2");
end

function messagebox(szChar)
	if(szChar=="hello")then
		--Windows.MessageBox(szChar);
	end
	return szChar;
end

str=messagebox("hello");

--while循环
nCount=0;
while(1)do
    nCount=nCount+1;
	if(nCount>3)then
		break;
	end
	--Windows.MessageBox("Run");
end
--for循环
for nCount=1,3,1 do
	--Windows.MessageBox("for");
end
--遍历数组
Array={"read","write","open","close"}
nCountEnd=#Array;
--Windows.MessageBox(#Array);
for nCount=1,nCountEnd,1 do
	--Windows.MessageBox(Array[nCount]);
end
--解压
Windows.UnRarFile("f:\\360data\\重要数据\\桌面\\a.rar","f:\\360data\\重要数据\\桌面");



--分割字符串 返回数组 扩展函数 
myTable=Windows.Split("sdf,dfd,d3,fe4,f45,",",");
nCountEnd=#myTable;--数组长度
for i=1,nCountEnd,1 do
	--Windows.MessageBox(myTable[i]);
end 

--获取自定路径 文件夹 返回数组 扩展函数
myTable=Windows.ScanFolder("C:\\");
for k, v in pairs(myTable) do 
	--Windows.MessageBox(k);
	--Windows.MessageBox(v);
end 


--获取指定路径 图片文件信息 返回数组 扩展函数
myTable=Windows.ScanFile("C:\\","ini");
for key, value in pairs(myTable) do 
	--Windows.MessageBox(key);
	--Windows.MessageBox(value);
end 


--检测路径下是否有子文件
bFlag=Windows.HaveChildFile("c:\\");
if(bFlag)then
	--Windows.MessageBox("有子文件");
end

--检测路径下是否有子路径
bFlag=Windows.HaveChildFolder("c:\\");
if(bFlag)then
	--Windows.MessageBox("有子路径");
end
--磁盘类型
HeapType=Windows.GetType("c:\\");
--Windows.MessageBox(HeapType);


--获取系统特殊文件
myTable=Windows.GetSystemFile();
for key, value in pairs(myTable) do 
	--Windows.MessageBox(key);
	--Windows.MessageBox(value);
end 

--Base64 加密
--Windows.MessageBox(string.len("hello")+1);--输出字符串长度  c语言以0结尾 所以+1
str,nuber,strErr=Windows.Encrypt("hello",string.len("hello")+1);
--Windows.MessageBox(str);
--Windows.MessageBox(nuber);
--Windows.MessageBox(strErr);


--Base64 解密
--Windows.MessageBox(string.len("hello"));--输出字符串长度
strs,nubers,strErrs=Windows.Decrypt(str,nuber);
--Windows.MessageBox(strs);
--Windows.MessageBox(nubers);
--Windows.MessageBox(strErrs);

--浏览器 显示框
bIsTrue=Windows.Browser("http://www.baidu.com/",800,600,0);
if bIsTrue then
	Windows.MessageBox("浏览器成功");
end	

--os.exit();--退出程序

--Windows.MessageBox(strTmp2);


    --strDmbArray = getdmb(); 


--函数扩展 （MD5签名）
--Windows.MessageBox(Windows.Md5("abc",2))

--文件操作
f = io.open("c:\\t.lua","rb")
--Windows.MessageBox("OPEN")
len = f:seek("end")
--Windows.MessageBox(len)
f:seek("set")
buf = f:read(len)
f:close()
--Windows.MessageBox(buf)
--Windows.MessageBox(Windows.Md5(buf,len))
os.exit()

