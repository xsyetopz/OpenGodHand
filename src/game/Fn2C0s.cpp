// Further small functions from 0x2C0000-0x2D0000.
extern "C" void func_002CE488(char *a, int b);
extern "C" int *GetSeData__4cSndi(char *a, int b);
extern "C" void func_002CB7E8(char *a, int b);
extern "C" void func_0030F5A0(char *a);
extern "C" void func_002C0038(char *a);
extern "C" void func_002CE510(char *a, short b, int c);
extern "C" int func_002CDA38(char *a);
extern "C" void func_00375050(int a, int b);
extern "C" void func_002CE3E8(char *a);
extern "C" void *Getplayer__Fv(void);
extern "C" void func_002C8AD8(char *a);
extern "C" void func_002CF310(char *a);
extern "C" char *func_003A54D8(char *s, int c);
extern "C" int func_002CF600(char *a, int b, char *c);
extern "C" int func_002CFC78(char *a);
extern "C" int func_002CFC88(char *a);
extern "C" void func_002CD740(char *a);
extern "C" void SeFadeOut__4cSnd6eSndIds(char *a, int b, short c);
extern "C" void *memset(void *, int, unsigned long);
extern int D_00747A2C;
extern int D_0044CE48[];
extern "C" int *func_002CD8F8(char *a, int b);
extern "C" int func_002C38D8(char *g, int a, int b, int c);
extern "C" int func_00373A58(char *a);
extern "C" void func_003734F0(char *a);
extern "C" void func_003735E0(char *a, int b, float x, float y);
extern "C" int func_002CDA38(char *a);
extern "C" void func_002CE3E8(char *a);
extern "C" int func_002CD7C8(char *a, int b);
extern "C" void func_002CFE68(char *a, int b, int c, char *d);
struct SceEnt {
    int a, b;
};
struct SceHost {
    char pad[0x58];
    SceEnt e[1];
};
extern SceHost *g_Sce;
extern char g_SceAt[];
extern char *g_SaveManager;
extern char *CoreSave;
extern unsigned D_00747A24;

// FUNCTION: GAME 0x2C2138
extern "C" int func_002C2138(char *self, int v)
{
    if (!*(int *)(self + 0x3C))
        return 0;
    int r = func_002C38D8((char *)g_Sce, *(int *)(self + 0x3C), *(int *)(self + 0x40), self[0x44]);
    g_Sce->e[r].a = v;
    return 1;
}

// FUNCTION: GAME 0x2CD548
extern "C" void func_002CD548(char *self, float x, unsigned set, unsigned clr)
{
    *(float *)(self + 0xC8) = x;
    *(unsigned *)(self + 0x98) = (*(unsigned *)(self + 0x98) | set) & ~clr;
    if (func_00373A58(self) == 1)
        func_003734F0(self);
    func_003735E0(self, -1, 1.0f, x);
}

// FUNCTION: GAME 0x2CE510
extern "C" void func_002CE510(char *self, short a, int b)
{
    if (!func_002CDA38(self))
        return;
    if (*(short *)(self + 8) != a)
        return;
    if (b == 1 && (*(unsigned *)(self + 0xC) & 1))
        return;
    func_002CE3E8(self);
}

// FUNCTION: GAME 0x2CD6D0
extern "C" void func_002CD6D0(char *self, int a, int b)
{
    *(char **)(self + 0x380) = self;
    memset(self, 0, 0x380);
    *(int *)(self + 0x384) = b;
    func_002CD740(self);
    *(int *)(self + 0x38C) = a;
    int r = func_002CD7C8((char *)a, b);
    *(int *)(self + 0x388) = r;
    *(int *)(*(char **)(self + 0x380) + 0x10) = r;
}

// FUNCTION: GAME 0x2CC050
extern "C" int func_002CC050(char *self)
{
    for (int i = 0x14; i < 0x34; i++) {
        if (func_002CFC78(*(char **)(self + 0x3C) + i * 64) == 1)
            return i;
    }
    return -1;
}

// FUNCTION: GAME 0x2CF6F8
extern "C" int func_002CF6F8(char *self, int a, int b)
{
    char buf[0x40];
    func_002CFE68(self, a, b, buf);
    int r = func_002CF600(self, a, buf);
    if (r == 1)
        *(int *)(self + 0x3C) = b;
    return r;
}
