// Further small functions from 0x2C0000-0x2D0000.
extern "C" int func_002CFE28(char *a, int b);
extern "C" int printf(const char *, ...);
extern "C" int func_002D30E0(char *a, int b, int c, int d);
extern int D_00747A34;
extern char D_0044CF78[];
extern char D_00603A40[];
extern "C" void func_002CFCB0(char *a, int b);
extern "C" int IsAlive__7cSeData(char *a);
extern "C" int _MemoryAlloc__FUiUiR5cHeap(unsigned a, unsigned b, int c);
extern "C" int func_001FF9C0(char *a, int b, int c, int d);
extern "C" int func_00322A68(int a, int b, int c, int d);
extern char D_00580D40[];

// FUNCTION: GAME 0x2CD8F8
extern "C" int *func_002CD8F8(char *self, int b)
{
    char *p = *(char **)(self + 0x380) + 0x1C;
    for (int i = 1; i < 0x20; i++, p += 0x1C)
        if (*(int *)(p + 0x14) == b) return (int *)p;
    return 0;
}
// FUNCTION: GAME 0x2CD930
extern "C" char *func_002CD930(char *self)
{
    char *p = *(char **)(self + 0x380) + 0x1C;
    for (int i = 1; i < 0x20; i++, p += 0x1C)
        if (*(int *)(p + 0x14) == 0) return p;
    return 0;
}

// FUNCTION: GAME 0x2CF8E8
extern "C" int func_002CF8E8(char *self)
{
    if (*(int *)(self + 0x1C)) return 0;
    int *h = *(int **)(self + 0x10);
    int s = h[0x28 / 4];
    if (s != (int)h) {
        int r = func_002CFE28(self, h[0x2C / 4]);
        *(int *)(self + 0x1C) = r;
        if (!r) return 0;
        if (D_00747A34 & 0x10000000)
            printf(D_0044CF78, *(int *)(self + 0x3C), *(int *)(self + 0x2C), (*(int **)(self + 0x10))[0x2C / 4]);
        *(int *)(self + 0x34) = func_002D30E0(D_00603A40, s, *(int *)(self + 0x1C), (*(int **)(self + 0x10))[0x2C / 4]);
    }
    func_002CFCB0(self, 0x20);
    return 1;
}

// FUNCTION: GAME 0x2CFBC0
extern "C" int func_002CFBC0(char *self)
{
    if (IsAlive__7cSeData(self) == 1) return 0;
    unsigned n = *(unsigned *)(*(char **)(self + 0x20));
    *(int *)(self + 0x24) = _MemoryAlloc__FUiUiR5cHeap(((n + 0x8E) >> 1) << 2, 0x10, *(int *)(self + 8));
    int p = *(int *)(self + 0x10);
    int r = func_001FF9C0(D_00580D40, p + *(int *)(p + 0x30), 0, 0);
    if (func_00322A68(*(int *)(self + 0x28), 0, r, *(int *)(self + 0x24))) return 0;
    func_002CFCB0(self, 4);
    return 1;
}
extern "C" void func_002CF310(char *a);
extern "C" void func_002CFD50(char *a);
extern "C" int func_002CFA08(char *a);
extern "C" int func_002CF868(char *a);
extern "C" int func_002CF888(char *a);
extern "C" void func_002CFC98(char *a);
// FUNCTION: GAME 0x2CF760
extern "C" int func_002CF760(char *self, int a, int b, int c)
{
    if (*(int *)self) func_002CF310(self);
    *(int *)(self + 0x2C) = a;
    *(int *)(self + 0x3C) = c;
    *(int *)self = 1;
    func_002CFD50(self);
    *(int *)(self + 0x10) = b;
    func_002CFCB0(self, 0x181);
    if (func_002CFA08(self)) {
        if (func_002CF868(self) != 1) return 1;
        if (func_002CF888(self)) {
            if (func_002CF8E8(self)) return 1;
        }
    }
    func_002CFC98(self);
    return 0;
}

extern "C" int sprintf(char *, const char *, ...);
extern "C" int FileExist__4cDvdPCc(char *d, char *p);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(char *d, char *p, char *o, int h, int a, int b, int c, int e);
extern int D_00747A2C;
extern char D_0044CF68[];
extern char Dvd[];
// FUNCTION: GAME 0x2CF600
extern "C" int func_002CF600(char *self, int a, int b)
{
    char buf[0x40];
    if (*(int *)self) {
        if (D_00747A2C >= 0) return 0;
        func_002CF310(self);
    }
    *(int *)(self + 0x2C) = a;
    *(int *)self = 1;
    *(int *)(self + 0x3C) = 0x7FFFFFFF;
    func_002CFD50(self);
    sprintf(buf, D_0044CF68, b);
    if (FileExist__4cDvdPCc(Dvd, buf)) {
        int r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, buf, self + 0x10, *(int *)(self + 8), 0, 0, 0, 0);
        *(int *)(self + 0x38) = r;
        if (r && *(int *)(self + 0x10)) goto ok;
    }
    func_002CF310(self);
    return 0;
ok:
    func_002CFCB0(self, 1);
    return 1;
}
extern "C" int func_002D0318(char *a);
extern "C" void func_00200F50(char *d, int a);
extern "C" int func_002D03D0(char *a, int b);
extern "C" int func_00323000(int a);
extern "C" void func_00322F58();
extern "C" void free__5cHeapPv(int h, int p);
extern "C" void *memset(void *, int, unsigned);
extern unsigned char D_0044D070;
// FUNCTION: GAME 0x2CFF90
extern "C" void func_002CFF90(char *self)
{
    if (!func_002D0318(self)) func_00200F50(Dvd, *(int *)(self + 0x1C));
    if (func_002D03D0(self, 4) == 1 && !func_002D03D0(self, 8) && func_00323000(*(int *)(self + 0x18)) == 2)
        func_00322F58();
    if (*(int *)(self + 0xC)) free__5cHeapPv(*(int *)(self + 8), *(int *)(self + 0xC));
    if (*(int *)(self + 0x14)) free__5cHeapPv(*(int *)(self + 8), *(int *)(self + 0x14));
    memset(self, 0, 0x44);
    *(int *)(self + 0x20) = -1;
    *(int *)(self + 0x18) = -1;
    *(unsigned char *)(self + 0x24) = D_0044D070;
}

extern "C" int func_002D2EE8(char *, int);
extern char D_0044CEE8[];
extern "C" int func_00372C68(char *);
extern "C" void func_002CC578(char *);

// FUNCTION: GAME 0x2C97C8
extern "C" int func_002C97C8(int a, int c)
{
    switch (c) {
    case 0x20: case 0x1A: case 0x5C: case 0x5D: return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x2CC500
extern "C" char *func_002CC500(char *s)
{
    func_00372C68(s);
    *(char **)(s + 0x80) = D_0044CEE8;
    func_002CC578(s);
    return s;
}

// FUNCTION: GAME 0x2CF9A8
extern "C" int func_002CF9A8(char *s)
{
    char *d = D_00603A40;
    if (!func_002D2EE8(d, *(int *)(s + 0x30)) || !func_002D2EE8(d, *(int *)(s + 0x34))) return 0;
    return 1;
}

extern "C" int func_002CC568(char *);
extern "C" int func_00373770(char *);

// FUNCTION: GAME 0x2CCA78
extern "C" int func_002CCA78(char *s)
{
    if (!func_002CC568(s) || (*(int *)(s + 0x98) & 1)) return 1;
    int r = func_00373770(s);
    int k = 2;
    return k < r;
}
