// Units in .text 0x150000-0x16FFFF.

struct Pair8 {
    int v0, v1;
};
extern "C" int func_0015FD68(void *p);
// DRAFT: GAME 0x15FCB8
// diff: 10 words; original branches bltz to the return-0 tail and stores through two copies of the entry pointer (a0 and v1); compiled uses bgez/b.
#ifdef NONMATCHING
extern "C" int func_0015FCB8(Pair8 *self, int a, int b)
{
    int i = func_0015FD68(self);
    int r;
    if (i < 0) {
        r = 0;
    } else {
        Pair8 *e = self + i;
        e->v0 = b;
        e->v1 = a;
        r = 1;
    }
    return r;
}
#endif

struct Pool150 {
    char _pad[0x1C];
    unsigned cur;
    char _pad2[4];
    unsigned low;
};
extern "C" void *func_002A97A0(void *p);
extern "C" void func_003A52F0(void *p, int v, int n);
extern "C" int func_0014FF80(void *p);
// FUNCTION: GAME 0x150538
extern "C" int func_00150538(Pool150 *self)
{
    void *e = func_002A97A0(self);
    if (!e)
        return 0;
    unsigned c = self->cur - 1;
    self->cur = c;
    if (c < self->low)
        self->low = c;
    func_003A52F0(e, 0, 0x220);
    return func_0014FF80(e);
}

extern const char D_00420070[];
extern const char D_00420158[];
extern const char D_00420240[];
extern char g_DmgManage[];
extern char EspSys[];
extern "C" void func_001FE278(void *mgr, void *p);
extern "C" void effDataRelease__6espSys12eEffDataType(void *sys, int t);
extern "C" void func_001C2820(void *self, int a);
// FUNCTION: GAME 0x16F438
extern "C" void func_0016F438(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00420070;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(void **)(self + 0x600) = 0;
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x258);
    func_001C2820(self, a);
}

// FUNCTION: GAME 0x16F720
extern "C" void func_0016F720(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00420158;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(void **)(self + 0x600) = 0;
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x259);
    func_001C2820(self, a);
}

// FUNCTION: GAME 0x16FA10
extern "C" void func_0016FA10(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00420240;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(void **)(self + 0x600) = 0;
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x25A);
    func_001C2820(self, a);
}

extern char Snd[];
extern "C" void func_002CBA48(void *snd, int a, int b, void *c, int d, int e, int f, int g);
// FUNCTION: GAME 0x16FEA0
extern "C" void func_0016FEA0(void *self)
{
    func_002CBA48(Snd, 2, 0, self, 0, 0, 0, 0);
    func_002CBA48(Snd, 2, 2, self, 0, 0, 0, 0);
}

extern "C" void func_001641B8(char *self);
extern "C" void func_00164238(void *p);
extern "C" void func_001643F8(void *p);
// FUNCTION: GAME 0x164140
extern "C" void func_00164140(char *self)
{
    switch ((unsigned char)self[0x64]) {
    case 0:
        func_001641B8(self);
        break;
    case 1:
        func_00164238(self);
        break;
    case 2:
    case 3:
        func_001643F8(self);
        break;
    }
}

extern char Sys[];
extern "C" void func_002CB8A0(void *snd, int a, int b, int c, int d, int e, int f);
// DRAFT: GAME 0x1641B8
// diff: 2 words; the -1 stored to self+0x60 is in v1 in the original, v0 in the compiled output.
#ifdef NONMATCHING
extern "C" void func_001641B8(char *self)
{
    char *g = Sys;
    if (*(long *)(g + 0x1A0) & 0x20000000)
        *(int *)(self + 0x60) = 10;
    if (*(long *)(g + 0x1A0) & 0x200000) {
        func_002CB8A0(Snd, 0, 0x161, -1, -1, 0, 0);
        *(int *)(self + 0x60) = -1;
    }
}
#endif
