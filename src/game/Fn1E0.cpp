struct WT { int a, b; };
extern WT WorldTime;
extern "C" void SdeSystemOutModeSet(int);
extern "C" void func_001FF3A0(void *);
extern "C" void trans__7cIDBase(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1F9C30 - reg alloc/order differs (lui/lw *a0 swapped)
extern "C" void func_001F9C30(WT **p)
{
    (*p)->a = WorldTime.a;
    (*p)->b = WorldTime.b;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1FC170 - a0/a1/v1 reg alloc swapped
extern "C" void func_001FC170(char **p, int n, int v)
{
    unsigned char i = n;
    char *q = *p;
    if (q) {
        if (i < 10) {
            q[0x98 + i] = v;
        }
    }
}

#endif

// FUNCTION: GAME 0x1F9E68
extern "C" void func_001F9E68(char **p)
{
    char *q = *p;
    if (q) {
        SdeSystemOutModeSet(*(int *)(q + 0x170));
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1FC360 - gcc picks movn/extra reg; orig keeps r=1 in v0 then movz
extern "C" int func_001FC360(char **p, int n)
{
    int r = 1;
    char *q = *p;
    if (q == 0) {
        return 0;
    }
    int f = *(int *)(q + 0xB90);
    int m = 1 << n;
    if ((f & m) == 0) {
        r = 0;
    }
    return r;
}

#endif

// FUNCTION: GAME 0x1FF0B0
extern "C" void func_001FF0B0(int *p)
{
    if (p[1] > 0) {
        p[1] = p[1] - 1;
    }
    if (p[1] == 0) {
        p[0] = 4;
    }
}

// FUNCTION: GAME 0x1FF448
extern "C" void func_001FF448(int *p)
{
    if (p[1] >= 0) {
        func_001FF3A0(p);
    }
}

// FUNCTION: GAME 0x1E7440
extern "C" void func_001E7440(char *self)
{
    trans__7cIDBase(self + 0x530);
    trans__7cIDBase(self);
}

// FUNCTION: GAME 0x1E8E88
extern "C" void func_001E8E88(char *self)
{
    int *q = (int *)(self + 0xA4);
    int v = 9;
    int i;
    for (i = 0x14; i >= 0; i--, q--) {
        *q = v;
    }
}
