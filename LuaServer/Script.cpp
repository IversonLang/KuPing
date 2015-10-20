#include "Script.h"

bool ExecScriptString(const char* szScript)
{
    lua_State* ls = luaL_newstate();
    if (ls == NULL){
        return false;
    }
    luaL_openlibs(ls);
    LoadExLib(ls);

    if (LUA_OK == luaL_loadstring(ls,szScript)){
        return (LUA_OK == lua_resume(ls,NULL,0));
    }
    return false;
}

bool ExecScriptFile(const char* szScriptFile)
{
    lua_State* ls = luaL_newstate();
    if (ls == NULL){
        return false;
    }
    luaL_openlibs(ls);
    LoadExLib(ls);

    if (LUA_OK == luaL_loadfile(ls,szScriptFile)){
        return (LUA_OK == lua_resume(ls,NULL,0));
    }
    return false;
}

static const luaL_Reg lrExLib[] = {
    {EXLIB_WINDOWS, ex_Windows},
    {NULL,NULL}
};

void LoadExLib(lua_State* ls)
{
    const luaL_Reg *lib;
    for (lib = lrExLib; lib->func; lib++) {
        luaL_requiref(ls, lib->name, lib->func, 1);
        lua_pop(ls, 1);  /* remove lib */
    }
}
