#include "game/Fn17y.h"

extern char g_EmManage[];
extern float D_00747A14;
extern "C" float GetSpeedRate__9cEmManage(void *);

// FUNCTION: GAME 0x1B43C8
extern "C" void func_001B43C8(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0:
        *(unsigned char *)(self + 0x2F5) = 1;
        *(float *)(self + 0x630) = *(float *)(self + 0x62C);
    case 1:
        if (*(float *)(self + 0x630) <= 0.0f) {
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F4) = 1;
        } else {
            *(float *)(self + 0x630) = *(float *)(self + 0x630) - GetSpeedRate__9cEmManage(g_EmManage) * D_00747A14;
        }
        break;
    }
}

extern char g_DmgManage[];
extern char D_004290C8[];
extern "C" int ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" void func_001B6F38(void *, int);

// FUNCTION: GAME 0x1B9030
extern "C" void func_001B9030(char *self, int a)
{
    *(char **)(self + 0x214) = D_004290C8;
    if (ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, *(void **)(self + 0x600))) {
        *(int *)(self + 0x600) = 0;
        *(int *)(self + 0x604) = -1;
    }
    if (ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, *(void **)(self + 0x608))) {
        *(int *)(self + 0x608) = 0;
        *(int *)(self + 0x60C) = -1;
    }
    KillEffect__FPC4cObji13eEspEraseMode(self, 0, 2);
    func_001B6F38(self, a);
}

// FUNCTION: GAME 0x1B0BD0
extern "C" int func_001B0BD0(sC3 *s)
{
    func_001B6FB8(s);
    struct { cVec v; float w; } t;
    t.v.x = 1.5f;
    t.v.y = 2.4f;
    t.v.z = 0.1f;
    t.w = 1.0f;
    s->m_600 = t.v;
    func_001BDA00(s);
    func_001BD698(s);
    func_001BDD88(s, 2.5f);
    s->m_5a0 |= 0x10;
    return 1;
}
