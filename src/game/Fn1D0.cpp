struct IdIn1D0 {
    char pad[0x90];
    int a, b, c, d;
};
struct IdSys1D0 {
    IdIn1D0 *m;
};
extern IdSys1D0 *IDSys;
extern char g_SceAt[];
extern struct cScn1D0 *g_Sce;
extern int D_00747A0C;
extern char *Cockpit;
extern "C" void func_00143A90(void *);
extern "C" void Main__12CustomIDWork(void *);
extern "C" void move__7cIDBase(void *);
extern "C" void release__7cIDBase(void *);
extern "C" void func_001DEDA8(void *);
extern "C" void func_001DD180(void *);
extern "C" void func_001DFDE0(void *);
extern "C" int SetDisable__13cSceAtManagerUs(void *, unsigned short);
extern "C" void taskExec__9cScenarioPvT1i(cScn1D0 *, void *, void *, int);
extern "C" void SetLocalPosX__12CustomIDWorki(void *, int);

// FUNCTION: GAME 0x1DF940
extern "C" void func_001DF940(char *self)
{
    func_001DEDA8(self + 0x25B0);
    func_001DD180(self);
    IdIn1D0 *i = IDSys->m;
    i->b = 0;
    i->a = 0;
}

// FUNCTION: GAME 0x1DFD90
extern "C" void func_001DFD90(char *self)
{
    SetDisable__13cSceAtManagerUs(g_SceAt, *(unsigned short *)(self + 0x48C));
    taskExec__9cScenarioPvT1i(g_Sce, (void *)func_001DFDE0, self, -1);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1DF7D0 - gcc emits movz/other layout; orig: const in a1, movn a1,v0,f (19 words)
extern "C" void func_001DF7D0(char *self, int f)
{
    int x = D_00747A0C;
    int a;
    int b;
    if (x == 0 || x < 0 || x >= 7) {
        a = 0x12;
        b = -0x61;
    } else {
        a = 0x19;
        b = -0x4F;
    }
    int r = a;
    if (f) {
        r = b;
    }
    SetLocalPosX__12CustomIDWorki(self + 0x440, r);
}
#endif

// FUNCTION: GAME 0x1D4480
extern "C" void func_001D4480(char *self)
{
    if (*(int *)(self + 0x1808) == 0) {
        func_00143A90(Cockpit + 0x1AE0);
        *(int *)(self + 0x1800) |= 1;
        *(int *)(self + 0x1808) += 1;
    }
}

// FUNCTION: GAME 0x1DBCF8
extern "C" void func_001DBCF8(char *self)
{
    if (*(unsigned char *)(self + 0x3025) == 0) {
        func_00143A90(Cockpit + 0x1AE0);
        *(int *)(self + 0x3020) |= 1;
        *(unsigned char *)(self + 0x3025) += 1;
    }
}

// FUNCTION: GAME 0x1DD1A0
extern "C" void func_001DD1A0(char *self)
{
    char *p = self + 0x60;
    int i;
    for (i = 0x4C; i >= 0; i--) {
        Main__12CustomIDWork(p);
        p += 0x7C;
    }
    move__7cIDBase(self + 0x10);
}

// FUNCTION: GAME 0x1DEDC8
extern "C" void func_001DEDC8(char *self)
{
    char *p = self + 0x60;
    int i;
    for (i = 0x10; i >= 0; i--) {
        Main__12CustomIDWork(p);
        p += 0x7C;
    }
    move__7cIDBase(self + 0x10);
}

#define MAIN_LOOP_FN(name, last)                       \
    extern "C" void name(char *self)                  \
    {                                                  \
        char *p = self + 0x60;                         \
        int i;                                         \
        for (i = last; i >= 0; i--) {                  \
            Main__12CustomIDWork(p);                   \
            p += 0x7C;                                 \
        }                                              \
        move__7cIDBase(self + 0x10);                   \
    }

// FUNCTION: GAME 0x1D4F78
MAIN_LOOP_FN(Move__11BlackJackId, 0x2C)
// FUNCTION: GAME 0x1ECBF0
MAIN_LOOP_FN(func_001ECBF0, 0x2C)
// FUNCTION: GAME 0x1EDF80
MAIN_LOOP_FN(func_001EDF80, 0x1C)
// FUNCTION: GAME 0x1F4700
MAIN_LOOP_FN(func_001F4700, 0x6E)

extern "C" void free__5cHeapPv(void *, void *);

// FUNCTION: GAME 0x2BE4E8
extern "C" void func_002BE4E8(char *self)
{
    char *q = *(char **)(self + 0x4C0);
    if (q) {
        free__5cHeapPv(*(void **)(q - 0x20), q);
    }
}
