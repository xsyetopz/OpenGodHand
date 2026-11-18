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

extern int D_00747A78;
extern "C" void func_00319520(int a);
extern "C" void sceVu0CopyVector(void *d, void *s);
extern "C" int func_002CD398(char *a);
extern "C" void func_00373858(char *a, int b);
extern "C" int func_003737C8(char *a, int b);
extern "C" int func_00373770(char *a);
extern "C" void func_002CC5E8(char *a);
extern "C" int func_002CFD38(char *a, int b);
extern "C" void func_002A9648(int a, int b, int c, int d);
extern "C" int func_00373A50(char *a);
extern char *Message;
extern "C" int func_002AEB50(char *m, int a, int b);
extern "C" void func_002C4150(char *self, int a, int b, int c, int e, int f);
extern "C" void exit__9cTaskWork(char *t);
extern "C" void func_002CE430(char *a);
extern int *D_003C30C0[];
extern "C" int func_002C0B38(char *a, int b);
extern "C" int func_002C0C28(char *a, int b);
extern "C" int func_002C0CB0(char *a, int b);
extern "C" void func_002CAF28(char *a);
extern "C" void BgmControl__4cSnd(char *a);
extern "C" void func_00325DD8(void);
extern "C" void func_002CA5D8(char *a);
extern "C" void func_00375380(void);
extern "C" void func_00375500(void);
extern "C" void func_002CA558(char *a);
extern char D_00603A40[];
extern "C" void func_002D2E38(char *a);
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

// FUNCTION: GAME 0x2C5470
extern "C" void func_002C5470(int **self)
{
    if (!(D_00747A78 & 0x8000000)) {
        for (int *p = (int *)(*self)[1]; (unsigned)p < (unsigned)(*self)[2]; p++)
            func_00319520(*p);
    }
}

// FUNCTION: GAME 0x2CE488
extern "C" void func_002CE488(char *self, int b)
{
    if (!func_002CDA38(self)) return;
    char *t = *(char **)(self + 0x38);
    if (t != (char *)b) return;
    if ((*(unsigned char *)(self + 0xC) ^ 1) & 1) {
        char *o = *(char **)(self + 0x3C);
        if (!o) sceVu0CopyVector(self + 0x40, *(void **)(t + 0xF0));
        else sceVu0CopyVector(self + 0x40, *(void **)(o + 0xF0));
    }
    *(int *)(self + 0x38) = 0;
    *(int *)(self + 0x3C) = 0;
}

// FUNCTION: GAME 0x2CD310
extern "C" void func_002CD310(char *self)
{
    if (*(int *)(self + 0xB0) == 0) {
        if (!func_002CD398(self)) return;
        if (*(short *)(self + 0xA0) == 0) func_00373858(self, 8);
        *(int *)(self + 0xB0) = 1;
    }
    if (func_003737C8(self, 8)) return;
    if (func_00373770(self)) return;
    func_002CC5E8(self);
}

// FUNCTION: GAME 0x2CFCB0
extern "C" void func_002CFCB0(char *self, int a)
{
    *(int *)(self + 4) |= a;
    if (func_002CFD38(self, 0x7F) != 1) return;
    int r = 2;
    if (func_002CFD38(self, 0x80) == 0) {
        int p = *(int *)(self + 0x10);
        int q = *(int *)(p + 0x20);
        if (q != p) func_002A9648(*(int *)(self + 8), p, q - p, 0x10);
        func_002CFCB0(self, 0x80);
    }
    *(int *)self = r;
}

// FUNCTION: GAME 0x2CAB58
extern "C" int func_002CAB58(char *self)
{
    int r = *(int *)(self + 0x1C) == 0;
    for (char *p = *(char **)(self + 0x18); p; p = *(char **)(p + 0x88)) {
        if (!func_00373A50(p)) continue;
        if (func_00373A58(p)) continue;
        unsigned f = *(unsigned *)(p + 0x98);
        if (f & 0x100) {
            if (!(f & 0x180000)) r = 0;
        }
    }
    return r;
}

// FUNCTION: GAME 0x2C2368
extern "C" void func_002C2368(char *self)
{
    char *p = self + 0x5C;
    int v = *(unsigned short *)(p + 2);
    if ((unsigned)v < 0x1000) v = func_002AEB50(Message, *(unsigned short *)(self + 0x5C), v);
    func_002C4150((char *)g_Sce, v, *(int *)(p + 0xC), 0, 0, 1);
    exit__9cTaskWork(*(char **)((char *)g_Sce + 0x20));
}

// FUNCTION: GAME 0x2CBC58
extern "C" void func_002CBC58(char *self, short a, short b)
{
    for (char *p = *(char **)(self + 0x1C); p; p = *(char **)(p + 4)) {
        if (*(short *)(p + 8) != a) continue;
        if ((int)(*(unsigned *)(p + 0xC) & 1) == 1) func_00375050(*(int *)(p + 0x14), b);
        else func_002CE430(p);
    }
}

// FUNCTION: GAME 0x2CB3A8
extern "C" int func_002CB3A8(int unused, int a1)
{
    for (int i = 0; i < 15; i++) {
        int *q = D_003C30C0[i];
        if (*q != 0x2FF) {
            do {
                if (a1 == *q++) return *D_003C30C0[i];
            } while (*q != 0x2FF);
        }
    }
    return a1;
}

// FUNCTION: GAME 0x2C0A98
extern "C" int func_002C0A98(char *self, int a, int mode)
{
    if (mode == 1 && ((self[0x29] ^ 1) & 1)) return 0;
    mode = self[0x29] & 6;
    switch (mode) {
    case 0: return func_002C0B38(self, a);
    case 2: return func_002C0C28(self, a);
    case 4: return func_002C0CB0(self, a);
    default: return 0;
    }
}

// FUNCTION: GAME 0x2CA470
extern "C" void func_002CA470(char *self)
{
    unsigned i = 0;
    func_002CAF28(self);
    int *p = (int *)(self + 0x140);
    BgmControl__4cSnd(self);
    func_00325DD8();
    func_002CA5D8(self);
    func_00375380();
    func_00375500();
    func_002CA558(self);
    func_002D2E38(D_00603A40);
    do {
        int v = *p;
        i++;
        if (v) {
            SeFadeOut__4cSnd6eSndIds(self, v, 5);
            *p = 0;
        }
    } while (p++, i < 8);
}
