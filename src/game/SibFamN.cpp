// Sibling families: scenario task starters, move-offset toggles, stop-flag setters.
#include "game/cVec.h"

extern char g_SceAt[];
extern void *g_Sce;
extern "C" int SetDisable__13cSceAtManagerUs(void *, unsigned short);
extern "C" void taskExec__9cScenarioPvT1i(void *, void *, void *, int);

#define SIB_TASK(NAME, OFF, FN)                                                 \
    extern "C" void FN(void *);                                                 \
    extern "C" void NAME(char *self)                                            \
    {                                                                           \
        SetDisable__13cSceAtManagerUs(g_SceAt, *(unsigned short *)(self + OFF)); \
        taskExec__9cScenarioPvT1i(g_Sce, (void *)FN, self, -1);                 \
    }

// FUNCTION: GAME 0x1E4920
SIB_TASK(func_001E4920, 0x3D0, func_001E4970)
// FUNCTION: GAME 0x1E9F18
SIB_TASK(func_001E9F18, 0x1B0, func_001E9F68)

extern "C" void SetMoveOffsetPosXSin__12CustomIDWorkiUs(void *, int, unsigned short);
extern "C" void ResetMoveOffsetPos__12CustomIDWork(void *);

#define SIB_MOVEOFS(NAME, OFF, A, B)                                            \
    extern "C" void NAME(char *self, int on)                                    \
    {                                                                           \
        if (on)                                                                 \
            SetMoveOffsetPosXSin__12CustomIDWorkiUs(self + OFF, A, B);          \
        else                                                                    \
            ResetMoveOffsetPos__12CustomIDWork(self + OFF);                     \
    }

// FUNCTION: GAME 0x1ED4B0
SIB_MOVEOFS(func_001ED4B0, 0x11D0, 3, 0x10)
// FUNCTION: GAME 0x1EE730
SIB_MOVEOFS(func_001EE730, 0xDF0, 3, 0x10)

#define SIB_STOP(NAME)                                                          \
    extern "C" void NAME(char *self)                                            \
    {                                                                           \
        long v = *(unsigned *)(self + 0x5B0);                                   \
        if (((v >> 1) & 1) == 0) {                                              \
            *(int *)(self + 0x5B0) |= 1;                                        \
            *(unsigned char *)(self + 0x2F4) = 2;                               \
            *(unsigned char *)(self + 0x2F6) = 0;                               \
            *(unsigned char *)(self + 0x2F7) = 0;                               \
            *(unsigned char *)(self + 0x2F5) = 0;                               \
        }                                                                       \
    }

// FUNCTION: GAME 0x1889C8
SIB_STOP(func_001889C8)

// FUNCTION: GAME 0x1C3B98
SIB_STOP(func_001C3B98)

extern "C" void func_0030F5A0(void *);

#define SIB_SETVT(NAME, SYM, OFF)                                               \
    extern const char SYM[];                                                    \
    extern "C" void NAME(char *p, int f)                                        \
    {                                                                           \
        *(const char **)(p + OFF) = SYM;                                        \
        if (f & 1)                                                              \
            func_0030F5A0(p);                                                   \
    }

// FUNCTION: GAME 0x2BAE68
SIB_SETVT(func_002BAE68, D_0044BAB0, 0x18)
// FUNCTION: GAME 0x305A38
SIB_SETVT(func_00305A38, D_00450080, 0x424)

#include "game/StopAim.h"
// FUNCTION: GAME 0x1746B0
FN190_STOP(func_001746B0)

extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *self, void *dmg);

// FUNCTION: GAME 0x197EC8
extern "C" void func_00197EC8(char *self)
{
    unsigned short *hp = (unsigned short *)(self + 0x9D8);
    void **dp = (void **)(self + 0x600);
    for (int i = 0; i < 1; hp++, i++, dp++) {
        int r = checkDamage__7cOmBaseP11cDamageTake(self, *dp);
        if (r == 1) {
            int d = *(int *)((char *)*dp + 0x4C);
            int t = *hp - d;
            *hp = t;
            if ((short)t < 0) {
                *(unsigned char *)(self + 0x9DA) = i;
                *(unsigned char *)(self + 0x2F4) = 2;
                *(unsigned char *)(self + 0x2F5) = 0;
                *(unsigned char *)(self + 0x2F6) = 0;
                *(unsigned char *)(self + 0x2F7) = 0;
                *(int *)(self + 0x5B0) |= 1;
            } else {
                *(unsigned char *)(self + 0x2F4) = r;
                *(unsigned char *)(self + 0x2F5) = 0;
                *(unsigned char *)(self + 0x2F6) = 0;
                *(unsigned char *)(self + 0x2F7) = 0;
            }
        }
    }
}

#define SIB_ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern "C" void *func_001B6E90(void *self);
extern "C" void func_0016F640(void *p, int v);
extern const char D_004272F8[];

// FUNCTION: GAME 0x1A5100
extern "C" void *func_001A5100(char *self)
{
    char *p = self + 0x630;
    int i = 6;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_004272F8;
    SIB_ZQ(self, 0x600);
    SIB_ZQ(self, 0x610);
    do {
        SIB_ZQ(p, 0x0);
        SIB_ZQ(p, 0x10);
        SIB_ZQ(p, 0x20);
        SIB_ZQ(p, 0x30);
        SIB_ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    } while (--i != -1);
    return self;
}

struct SibPool {
    char _p[0x1C];
    unsigned cur;
    char _pad[4];
    unsigned low;
};
extern "C" void *func_002A97A0(void *p);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_00148358(void *p);
// FUNCTION: GAME 0x149488
extern "C" void func_00149488(SibPool *self)
{
    void *e = func_002A97A0(self);
    if (!e)
        return;
    unsigned c = self->cur - 1;
    self->cur = c;
    if (c < self->low)
        self->low = c;
    memset(e, 0, 0x480);
    func_00148358(e);
}

extern "C" void *memcpy(void *, const void *, unsigned);
// FUNCTION: GAME 0x145100
extern "C" void func_00145100(char *self, void *src, short n)
{
    if (n >= 0x24)
        *(short *)(self + 0x334) = 0x23;
    else
        *(short *)(self + 0x334) = n;
    memcpy(self + 0x2A8, src, *(short *)(self + 0x334) << 2);
    *(unsigned *)(self + 0x90) |= 0x40000000;
}

extern char g_DmgManage[];
extern char EspSys[];
extern "C" void func_001B6F38(void *self, int a);
extern "C" void effDataRelease__6espSys12eEffDataType(void *sys, int t);
extern "C" void ReleaseDamageGive__13cDamageManageP11cDamageGive(void *mgr, void *p);
extern const char D_004294F0[], D_00429B88[];

// FUNCTION: GAME 0x1BDED8
extern "C" void func_001BDED8(char *self, int a)
{
    *(const void **)(self + 0x214) = D_004294F0;
    effDataRelease__6espSys12eEffDataType(EspSys, 0x241);
    func_001B6F38(self, a);
}

// FUNCTION: GAME 0x1C00C8
extern "C" void func_001C00C8(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00429B88;
    void *d = *(void **)(self + 0x680);
    if (d) {
        ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, d);
        *(void **)(self + 0x680) = 0;
    }
    func_001B6F38(self, a);
}
