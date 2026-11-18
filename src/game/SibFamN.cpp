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
