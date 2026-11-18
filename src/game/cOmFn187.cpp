#include "game/cDamageManage.h"

// Destructor-chain wrappers for map objects that own an array of damage-take records
// (released through func_001FE278) and one damage-give record at GOFF (released through
// cDamageManage::ReleaseDamageGive), then call the base destructor.
extern cDamageManage g_DmgManage;
extern "C" void func_001FE278(void *mgr, void *p);
extern "C" void func_001B6F38(void *self, int flag);
extern const char D_00420EF0[];
extern const char D_004211D8[];
extern const char D_004212E8[];
extern const char D_00423338[];
extern const char D_00423608[];
extern const char D_00423F58[];

// FUNCTION: GAME 0x187D10
extern "C" void func_00187D10(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00423338;
    void *d = *(void **)(self + 0x604);
    if (d) {
        func_001FE278(&g_DmgManage, d);
        *(void **)(self + 0x604) = 0;
    }
    void *g = *(void **)(self + 0x608);
    if (g) {
        g_DmgManage.ReleaseDamageGive((cDamageGive *)g);
        *(void **)(self + 0x608) = 0;
    }
    func_001B6F38(self, flag);
}

#define OM_DMG_DTOR_N(ADDR, VT, N, GOFF) \
    extern "C" void func_00##ADDR(char *self, int flag) \
    { \
        *(const void **)(self + 0x214) = VT; \
        void **p = (void **)(self + 0x600); \
        for (int i = N; i >= 0; i--) { \
            if (*p) { \
                func_001FE278(&g_DmgManage, *p); \
                *p = 0; \
            } \
            p++; \
        } \
        void *g = *(void **)(self + GOFF); \
        if (g) { \
            g_DmgManage.ReleaseDamageGive((cDamageGive *)g); \
            *(void **)(self + GOFF) = 0; \
        } \
        func_001B6F38(self, flag); \
    }

// FUNCTION: GAME 0x175630
OM_DMG_DTOR_N(175630, D_004211D8, 1, 0x608)

// FUNCTION: GAME 0x176CB8
OM_DMG_DTOR_N(176CB8, D_004212E8, 1, 0x608)

// FUNCTION: GAME 0x189008
OM_DMG_DTOR_N(189008, D_00423608, 1, 0x608)

// FUNCTION: GAME 0x190250
OM_DMG_DTOR_N(190250, D_00423F58, 3, 0x610)

extern char g_CollScr;
extern "C" void func_0012EC58(void *coll, void *p);

// FUNCTION: GAME 0x171D20
extern "C" void func_00171D20(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00420EF0;
    void **p = (void **)(self + 0x600);
    for (int i = 0; i >= 0; i--) {
        if (*p) {
            func_001FE278(&g_DmgManage, *p);
            *p = 0;
        }
        p++;
    }
    void *g = *(void **)(self + 0x604);
    if (g) {
        g_DmgManage.ReleaseDamageGive((cDamageGive *)g);
        *(void **)(self + 0x604) = 0;
    }
    void *c = *(void **)(self + 0xDA8);
    if (c) {
        func_0012EC58(&g_CollScr, c);
        *(void **)(self + 0xDA8) = 0;
    }
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x17DF88
extern "C" void func_0017DF88(char *self)
{
    void **p = (void **)(self + 0x654);
    for (int i = 7; i >= 0; i--) {
        if (*p) {
            func_0012EC58(&g_CollScr, *p);
            *p = 0;
        }
        p++;
    }
    void *c = *(void **)(self + 0x674);
    if (c) {
        func_0012EC58(&g_CollScr, c);
        *(void **)(self + 0x674) = 0;
    }
}
