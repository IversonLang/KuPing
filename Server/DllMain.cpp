#include <Windows.h>
HMODULE g_hDll = NULL;

typedef bool (*fnRunString)(const char* szScript);
typedef bool (*fnRunFile)(const char* szScriptFile);

fnRunString RunString = NULL;
fnRunFile RunFile = NULL;

BOOL WINAPI DllMain( HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved )
{
    switch(dwReason)
    {
    case DLL_PROCESS_ATTACH:
        OutputDebugString("Server Dll Attach\n");
        if(g_hDll == NULL){
            g_hDll = LoadLibrary("ScriptServer.dll");
            if (g_hDll == NULL){
                OutputDebugString("Server Dll Attach Fail\n");
                RunString = NULL;
                RunFile = NULL;
                return FALSE;
            }
            RunString = (fnRunString)GetProcAddress(g_hDll,"ExecScriptString");
            RunFile = (fnRunFile)GetProcAddress(g_hDll,"ExecScriptFile");

            //RunString("a = Windows.MessageBox(\"Hello\",\"Œ“»•\",2) \r\n Windows.MessageBox(a)");
            RunFile("../t.lua");
        }
    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}
