/*
* one_nob.c -- Lua core, libraries, and interpreter in a single file
*/

/* default is to build the full interpreter */
#ifndef MAKE_LIB
#ifndef MAKE_LUAC
#ifndef MAKE_LUA
#define MAKE_LUA
#endif
#endif
#endif

#ifdef TARGET_MAC
#define LUA_USE_MACOSX
#elif defined(TARGET_LINUX)
#define LUA_USE_LINUX
#endif

/* choose suitable platform-specific features */
/* some of these may need extra libraries such as -ldl -lreadline -lncurses */
#if 0
#define LUA_USE_LINUX
#define LUA_USE_MACOSX
#define LUA_USE_POSIX
#define LUA_ANSI
#endif

/* no need to change anything below this line ----------------------------- */

#include "liblua/lprefix.h"

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* setup for luaconf.h */
#define LUA_CORE
#define LUA_LIB
#define ltable_c
#define lvm_c
#include "liblua/luaconf.h"

/* do not export internal symbols */
#undef LUAI_FUNC
#undef LUAI_DDEC
#undef LUAI_DDEF
#define LUAI_FUNC	static
#define LUAI_DDEC(def)	/* empty */
#define LUAI_DDEF	static

/* core -- used by all */
#include "lzio_nob.c"
#include "lctype_nob.c"
#include "lopcodes_nob.c"
#include "lmem_nob.c"
#include "lundump_nob.c"
#include "ldump_nob.c"
#include "lstate_nob.c"
#include "lgc_nob.c"
#include "llex_nob.c"
#include "lcode_nob.c"
#include "lparser_nob.c"
#include "ldebug_nob.c"
#include "lfunc_nob.c"
#include "lobject_nob.c"
#include "ltm_nob.c"
#include "lstring_nob.c"
#include "ltable_nob.c"
#include "ldo_nob.c"
#include "lvm_nob.c"
#include "lapi_nob.c"

/* auxiliary library -- used by all */
#include "lauxlib_nob.c"

/* standard library  -- not used by luac */
#ifndef MAKE_LUAC
#include "lbaselib_nob.c"
#include "lcorolib_nob.c"
#include "ldblib_nob.c"
#include "liolib_nob.c"
#include "lmathlib_nob.c"
#include "loadlib_nob.c"
#include "loslib_nob.c"
#include "lstrlib_nob.c"
#include "ltablib_nob.c"
#include "lutf8lib_nob.c"
#include "linit_nob.c"
#endif

/* lua */
#ifdef MAKE_LUA
#include "lua_nob.c"
#endif

/* luac */
#ifdef MAKE_LUAC
#include "luac_nob.c"
#endif
