// dui-demo.cpp : main source file
//

#include "stdafx.h"
#include "MainDlg.h"
#include <iostream>   
using namespace std;

//从PE文件加载，注意从文件加载路径位置
#define RES_TYPE 1
//#define RES_TYPE 0   //从文件中加载资源
// #define RES_TYPE 1  //从PE资源中加载UI资源

#ifdef _DEBUG
#define SYS_NAMED_RESOURCE _T("soui-sys-resourced.dll")
#else
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#endif
  
#include <curl/curl.h> 
#pragma comment(lib,"../lib/libcurl.lib")


struct FtpFile {
	const char *filename;
	FILE *stream;
};

static size_t my_fwrite(void *buffer, size_t size, size_t nmemb, void *stream)
{
	struct FtpFile *out=(struct FtpFile *)stream;
	if(out && !out->stream) {
		out->stream=fopen(out->filename, "wb");//打开文件进行写入
		if(!out->stream)
			return -1;
	}
	return fwrite(buffer, size, nmemb, out->stream);
}

static int download()
{
	CURL *curl;
	CURLcode res;
	struct FtpFile ftpfile={
		"E://test.xml", //定义下载到本地的文件位置和路径
		NULL
	};


	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();  //初始化一个curl指针

	if(curl) 
	{ 

		//设置远端地址
		curl_easy_setopt(curl, CURLOPT_URL,"http://config.kuping.cc/Public/conf/kp6/webbrowser.xml");

		//执行写入文件流操作
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_fwrite);//当有数据被写入，回调函数被调用，
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ftpfile); //设置结构体的指针传递给回调函数

		//启用时会汇报所有的信息，存放在STDERR或指定的CURLOPT_STDERR中
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		curl_easy_setopt(curl, CURLOPT_USERPWD, "SUREN:SUREN");

		//写入文件
		res = curl_easy_perform(curl);

		//释放curl对象
		curl_easy_cleanup(curl);

		if(res != CURLE_OK)
		{
			cout<<stderr<<res<<endl;
		}
	}

	if(ftpfile.stream)
	{
		//关闭文件流
		fclose(ftpfile.stream);
	}

	//释放全局curl对象
	curl_global_cleanup();

	return 0;

}



int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int /*nCmdShow*/)
{

	AllocConsole();
	freopen("CONOUT$","w+t", stdout);
	freopen("CONIN$","r+t", stdin);

    HRESULT hRes = OleInitialize(NULL);
    SASSERT(SUCCEEDED(hRes));

    int nRet = 0;
    
    SComMgr *pComMgr = new SComMgr;

    //将程序的运行路径修改到项目所在目录所在的目录
    TCHAR szCurrentDir[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));
    LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T('\\'));
    _tcscpy(lpInsertPos + 1, _T(".."));
    SetCurrentDirectory(szCurrentDir);
    {
        BOOL bLoaded=FALSE;
        CAutoRefPtr<SOUI::IImgDecoderFactory> pImgDecoderFactory;
        CAutoRefPtr<SOUI::IRenderFactory> pRenderFactory;
        bLoaded = pComMgr->CreateRender_GDI((IObjRef**)&pRenderFactory);
        SASSERT_FMT(bLoaded,_T("load interface [render] failed!"));
        bLoaded=pComMgr->CreateImgDecoder((IObjRef**)&pImgDecoderFactory);
        SASSERT_FMT(bLoaded,_T("load interface [%s] failed!"),_T("imgdecoder"));

        pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);
        SApplication *theApp = new SApplication(pRenderFactory, hInstance);
        //从DLL加载系统资源
        HMODULE hModSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
        if (hModSysResource)
        {
            CAutoRefPtr<IResProvider> sysResProvider;
            CreateResProvider(RES_PE, (IObjRef**)&sysResProvider);
            sysResProvider->Init((WPARAM)hModSysResource, 0);
            theApp->LoadSystemNamedResource(sysResProvider);
            FreeLibrary(hModSysResource);
        }else
        {
            SASSERT(0);
        }

        CAutoRefPtr<IResProvider>   pResProvider;
#if (RES_TYPE == 0)
        CreateResProvider(RES_FILE, (IObjRef**)&pResProvider);
        if (!pResProvider->Init((LPARAM)_T("uires"), 0))
        {
            SASSERT(0);
            return 1;
        }
#else 
        CreateResProvider(RES_PE, (IObjRef**)&pResProvider);
        pResProvider->Init((WPARAM)hInstance, 0);
#endif

        theApp->AddResProvider(pResProvider);
        theApp->Init(_T("XML_INIT"));

        // 加载LUA脚本模块。
        // CAutoRefPtr<IScriptModule> pScriptLua;
        // bLoaded=pComMgr->CreateScrpit_Lua((IObjRef**)&pScriptLua);
        // SASSERT_FMT(bLoaded,_T("load interface [%s] failed!"),_T("script_lua"));
        
		// 使用curllib 下载文件
		// download();

        // BLOCK: Run application
        {
            CMainDlg dlgMain;
            dlgMain.Create(GetActiveWindow());
            dlgMain.SendMessage(WM_INITDIALOG);
            dlgMain.CenterWindow(dlgMain.m_hWnd);
            dlgMain.ShowWindow(SW_SHOWNORMAL);
            nRet = theApp->Run(dlgMain.m_hWnd);
        }

        delete theApp;
    }
    
    delete pComMgr;
    
    OleUninitialize();
    return nRet;
}
