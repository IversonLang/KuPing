#include <Windows.h>

BOOL WINAPI DllMain( HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved )
{
    switch(dwReason)
    {
    case DLL_PROCESS_ATTACH:
        OutputDebugString("ScriptServer Dll Attach\n");
    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}

