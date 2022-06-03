#define LIB_NAME "signpost"
#define MODULE_NAME "signpost"

#include "signpost_private.h"
#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX)

namespace dmSignpost {
static int Lua_Start(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 1);
    const char *scopeName = luaL_checkstring(L, 1);
    uint64_t id = Platform_Start(scopeName);
    lua_pushnumber(L, id);
    return 1;
}

static int Lua_Stop(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    uint64_t id = luaL_checknumber(L, 1);
    char *info = 0;
    if (lua_type(L, 2) != LUA_TNONE) {
        info = (char*)luaL_checkstring(L, 2);
    }
    Platform_Stop(id, info);
    return 0;
}

static int Lua_Event(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);
    const char *info = luaL_checkstring(L, 1);
    Platform_Event(info);
    return 0;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
{
    {"start", Lua_Start},
    {"stop", Lua_Stop},
    {"event", Lua_Event},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}
} //namespace
#endif

static dmExtension::Result InitializeMyExtension(dmExtension::Params* params)
{
    // Init Lua
#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX)
    dmSignpost::LuaInit(params->m_L);
#endif
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeMyExtension(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(signpost, LIB_NAME, 0, 0, InitializeMyExtension, 0, 0, FinalizeMyExtension)
