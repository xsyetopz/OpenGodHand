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
