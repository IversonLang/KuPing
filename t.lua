--��ʼ������
a,b,c=2,3,4
--����һ
add=function (number1,number2)
	return number1+number2 ;
end

--luaC++��չʹ��˵�� http://blog.csdn.net/Lodger007/article/details/837349
	
--������
function sub(c,a) 
	return c-a;
end
	
Windows.MessageBox(sub(a,b));	

--if���
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

--whileѭ��
nCount=0;
while(1)do
    nCount=nCount+1;
	if(nCount>3)then
		break;
	end
	--Windows.MessageBox("Run");
end
--forѭ��
for nCount=1,3,1 do
	--Windows.MessageBox("for");
end
--��������
Array={"read","write","open","close"}
nCountEnd=#Array;
--Windows.MessageBox(#Array);
for nCount=1,nCountEnd,1 do
	--Windows.MessageBox(Array[nCount]);
end
--��ѹ
Windows.UnRarFile("f:\\360data\\��Ҫ����\\����\\a.rar","f:\\360data\\��Ҫ����\\����");



--�ָ��ַ��� �������� ��չ���� 
myTable=Windows.Split("sdf,dfd,d3,fe4,f45,",",");
nCountEnd=#myTable;--���鳤��
for i=1,nCountEnd,1 do
	--Windows.MessageBox(myTable[i]);
end 

--��ȡ�Զ�·�� �ļ��� �������� ��չ����
myTable=Windows.ScanFolder("C:\\");
for k, v in pairs(myTable) do 
	--Windows.MessageBox(k);
	--Windows.MessageBox(v);
end 


--��ȡָ��·�� ͼƬ�ļ���Ϣ �������� ��չ����
myTable=Windows.ScanFile("C:\\","ini");
for key, value in pairs(myTable) do 
	--Windows.MessageBox(key);
	--Windows.MessageBox(value);
end 


--���·�����Ƿ������ļ�
bFlag=Windows.HaveChildFile("c:\\");
if(bFlag)then
	--Windows.MessageBox("�����ļ�");
end

--���·�����Ƿ�����·��
bFlag=Windows.HaveChildFolder("c:\\");
if(bFlag)then
	--Windows.MessageBox("����·��");
end
--��������
HeapType=Windows.GetType("c:\\");
--Windows.MessageBox(HeapType);


--��ȡϵͳ�����ļ�
myTable=Windows.GetSystemFile();
for key, value in pairs(myTable) do 
	--Windows.MessageBox(key);
	--Windows.MessageBox(value);
end 

--Base64 ����
--Windows.MessageBox(string.len("hello")+1);--����ַ�������  c������0��β ����+1
str,nuber,strErr=Windows.Encrypt("hello",string.len("hello")+1);
--Windows.MessageBox(str);
--Windows.MessageBox(nuber);
--Windows.MessageBox(strErr);


--Base64 ����
--Windows.MessageBox(string.len("hello"));--����ַ�������
strs,nubers,strErrs=Windows.Decrypt(str,nuber);
--Windows.MessageBox(strs);
--Windows.MessageBox(nubers);
--Windows.MessageBox(strErrs);

--����� ��ʾ��
bIsTrue=Windows.Browser("http://www.baidu.com/",800,600,0);
if bIsTrue then
	Windows.MessageBox("������ɹ�");
end	

--os.exit();--�˳�����

--Windows.MessageBox(strTmp2);


    --strDmbArray = getdmb(); 


--������չ ��MD5ǩ����
--Windows.MessageBox(Windows.Md5("abc",2))

--�ļ�����
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

