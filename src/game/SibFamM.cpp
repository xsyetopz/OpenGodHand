// Sibling families: 0x277F80-0x27E638 model setup, and damage-hit handlers.
extern "C" void func_001595E8(void *, int);
extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" int setupModel__6cModelPC10SCR_HEADERUibT3(void *, int, int, int, int);

#define SIB_SETUP(NAME, S1, S2)                                                 \
    extern const char S1[], S2[];                                               \
    extern "C" int NAME(char *self)                                             \
    {                                                                           \
        func_001595E8(self, 0);                                                 \
        int a = SearchData__FPUiPCcUi(*(void **)(self + 0x304), S1, 0);         \
        int b = SearchData__FPUiPCcUi(*(void **)(self + 0x304), S2, 0);         \
        if (b)                                                                  \
            return setupModel__6cModelPC10SCR_HEADERUibT3(self, a, b, 0, 0);    \
        return 0;                                                               \
    }

// FUNCTION: GAME 0x277F80
SIB_SETUP(func_00277F80, D_00447B90, D_00447B98)
// FUNCTION: GAME 0x279938
SIB_SETUP(func_00279938, D_00447D38, D_00447D40)
// FUNCTION: GAME 0x279F68
SIB_SETUP(func_00279F68, D_00447E58, D_00447E60)
// FUNCTION: GAME 0x27D150
SIB_SETUP(func_0027D150, D_00448180, D_00448188)
// FUNCTION: GAME 0x27E638
SIB_SETUP(func_0027E638, D_004482C8, D_004482D0)

extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *self, void *dmg);

#define SIB_HIT(NAME, ARR, N, OFF)                                                 \
    extern "C" void NAME(char *self)                                            \
    {                                                                           \
        unsigned short *hp = (unsigned short *)(self + ARR);                    \
        void **dp = (void **)(self + 0x600);                                    \
        for (int i = 0; i < N; i++, hp++, dp++) {                               \
            int r = checkDamage__7cOmBaseP11cDamageTake(self, *dp);            \
            if (r == 1) {                                                       \
                int d = *(int *)((char *)*dp + 0x4C);                           \
                int t = *hp - d;                                                \
                *hp = t;                                                        \
                if ((short)t < 0) {                                             \
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

// FUNCTION: GAME 0x190BF0
SIB_HIT(func_00190BF0, 0xF88, 4, 8)
// FUNCTION: GAME 0x1A1690
SIB_HIT(func_001A1690, 0xD98, 2, 4)
// FUNCTION: GAME 0x1A2D50
SIB_HIT(func_001A2D50, 0xD9A, 2, 4)
