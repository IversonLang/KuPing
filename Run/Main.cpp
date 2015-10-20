#include <Windows.h>

HMODULE g_hDll = NULL;

enum{
    UM_BEGIN = WM_USER + 100,
    UM_RELOAD_DLL,
};

LRESULT WINAPI MsgProc(HWND hWnd,UINT msg, WPARAM wParam,LPARAM lParam);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
    WNDCLASSEX wc = {sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0, 0,
        GetModuleHandle(NULL), NULL, NULL, NULL, NULL, 
        "KpScriptWnd", NULL};

    RegisterClassEx(&wc);

    //创建窗口
    HWND hWnd = CreateWindow("KpScriptWnd", "KpScript", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 
        GetDesktopWindow(), NULL, wc.hInstance, NULL);

    if (!hWnd){
        return 0;
    }

	//加载Lua 服务
    PostMessage(hWnd,UM_RELOAD_DLL,0,0);

    MSG msg;
    while (GetMessage(&msg,NULL,NULL,NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT WINAPI MsgProc(HWND hWnd,UINT msg, WPARAM wParam,LPARAM lParam)
{
    switch (msg)
    {
        case UM_RELOAD_DLL:
            OutputDebugString("Reload Dll\n");
            if (g_hDll){
                OutputDebugString("Free Dll\n");
                FreeLibrary(g_hDll);
                g_hDll = NULL;
            }
            OutputDebugString("Load Server Dll\n");
            g_hDll = LoadLibrary("Server.dll");
            if (g_hDll == NULL){
                OutputDebugString("Load Server Dll Fail\n");
                PostQuitMessage(0);
            }
            break;

    }

    return DefWindowProc(hWnd,msg,wParam,lParam);
}
