#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x86emu.h"

const char* appindicator3Name = "libappindicator3.so.1";
#define LIBNAME appindicator3

#define PRE_INIT    \
    if(box86_nogtk) \
        return -1;

#define CUSTOM_INIT \
    lib->altmy = strdup("my3_");                                    \
    lib->priv.w.needed = 5; \
    lib->priv.w.neededlibs = (char**)calloc(lib->priv.w.needed, sizeof(char*)); \
    lib->priv.w.neededlibs[0] = strdup("libgtk-3.so.0");        \
    lib->priv.w.neededlibs[1] = strdup("libgdk-3.so.0");        \
    lib->priv.w.neededlibs[2] = strdup("libgio-2.0.so.0");      \
    lib->priv.w.neededlibs[3] = strdup("libgobject-2.0.so.0");  \
    lib->priv.w.neededlibs[4] = strdup("libglib-2.0.so.0");     \

#include "wrappedlib_init.h"