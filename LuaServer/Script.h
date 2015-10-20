#pragma once

#include "../Lua/src/lua.hpp"
#pragma comment(lib,"../lib/lua.lib")

bool ExecScriptString(const char* szScript);
bool ExecScriptFile(const char* szScriptFile);
bool ExecScriptStringTh(const char* szScript);
bool ExecScriptFileTh(const char* szScriptFile);
void LoadExLib(lua_State* ls);

#define EXLIB_WINDOWS "Windows"
int ex_Windows(lua_State* ls);