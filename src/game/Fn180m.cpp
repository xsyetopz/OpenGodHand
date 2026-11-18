// Small free functions of the cOm* object units in 0x180000-0x1A0000.
#include "game/cVec.h"

#include "game/StopAim.h"

// FUNCTION: GAME 0x18CDA8
FN190_STOP(func_0018CDA8)
// FUNCTION: GAME 0x18DB60
FN190_STOP(func_0018DB60)
// FUNCTION: GAME 0x18E918
FN190_STOP(func_0018E918)

extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *self, void *dmg);

#define FN180M_HIT(NAME, ARR, N, OFF)                                              \
    extern "C" void NAME(char *self)                                            \
    {                                                                           \
        short *hp = (short *)(self + ARR);                                      \
        void **dp = (void **)(self + 0x600);                                    \
        for (int i = 0; i < N; hp++, i++, dp++) {                               \
            int r = checkDamage__7cOmBaseP11cDamageTake(self, *dp);            \
            if (r == 1) {                                                       \
                int d = *(int *)((char *)*dp + 0x4C);\
                *hp = *hp - d;                            \
                if (*hp < 0) {                                                  \
                    *(unsigned char *)(self + ARR + OFF) = i;                     \
                    *(unsigned char *)(self + 0x2F4) = 2;                       \
                    *(unsigned char *)(self + 0x2F5) = 0;                       \
                    *(unsigned char *)(self + 0x2F6) = 0;                       \
                    *(unsigned char *)(self + 0x2F7) = 0;                       \
                    *(int *)(self + 0x5B0) |= 1;                                \
                } else {                                                        \
                    *(unsigned char *)(self + 0x2F4) = r;                       \
                    *(unsigned char *)(self + 0x2F5) = 0;                       \
                    *(unsigned char *)(self + 0x2F6) = 0;                       \
                    *(unsigned char *)(self + 0x2F7) = 0;                       \
                }                                                               \
            }                                                                   \
        }                                                                       \
    }

// FUNCTION: GAME 0x1896E0
FN180M_HIT(func_001896E0, 0xCD2, 2, 4)
// FUNCTION: GAME 0x1968A0
FN180M_HIT(func_001968A0, 0x9D8, 1, 2)

extern const char D_00422EB8[];
extern char g_DmgManage[];
extern char EspSys[];
extern "C" void func_001FE278(void *mgr, void *p);
extern "C" void effDataRelease__6espSys12eEffDataType(void *sys, int t);
extern "C" void func_001B6F38(void *self, int a);
// FUNCTION: GAME 0x1838D8
extern "C" void func_001838D8(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00422EB8;
    void **dp = (void **)(self + 0x600);
    for (unsigned i = 0; i < 7; i++, dp++) {
        if (*dp) {
            func_001FE278(g_DmgManage, *dp);
            *dp = 0;
        }
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x298);
    func_001B6F38(self, a);
}
