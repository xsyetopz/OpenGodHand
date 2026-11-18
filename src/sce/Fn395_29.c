// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2
// SCE runtime helpers in 0x394000-0x398000 (continuation of Fn394_29.c).

extern int scePrintf();
extern int func_00397590();
extern int func_003970A0();
extern char D_0045DFC8[];

// FUNCTION: GAME 0x397028
void func_00397028(volatile int *obj)
{
    int cnt = 0x1000000;
    while (*obj & 0x100) {
        if (--cnt < 0) {
            scePrintf(D_0045DFC8);
            func_00397590(obj);
        }
    }
}

// FUNCTION: GAME 0x3974D0
void func_003974D0(int *s, int a, int b)
{
    int v = func_003970A0(a);
    func_00397028(s);
    { unsigned m = 0xFFFFFFFFu; if (m != (unsigned)s[0x10 / 4])
        s[0x10 / 4] = v; }
    s[0x20 / 4] = b;
    {
        int f = s[0] & ~0xC;
        f &= ~1;
        s[0] = f | 0x100;
    }
}

#ifdef NONMATCHING
typedef struct { char pad[0x20]; long out; long pad2; unsigned long reg; } SceGsObj;

// DRAFT: GAME 0x3960D0
void func_003960D0(SceGsObj *o, short x, short y, short half)
{
    int h = (o->reg >> 48) & 0x7FF;
    int w = (o->reg >> 16) & 0x7FF;
    long ay = y - (unsigned long)(h + 1) / 2;
    long ax = x - (unsigned long)(w + 1) / 2;
    long hi = half ? ((ay << 4) + 8) << 32 : ay << 36;
    o->out = (ax << 4) | hi;
}

// DRAFT: GAME 0x396048
void func_00396048(SceGsObj *o, short x, short y, short half)
{
    int h = (o->reg >> 48) & 0x7FF;
    int w = (o->reg >> 16) & 0x7FF;
    long ay = y - (unsigned long)(h + 1) / 2;
    long ax = x - (unsigned long)(w + 1) / 2;
    long hi = half ? ((ay << 4) + 8) << 32 : ay << 36;
    o->out = (ax << 4) | hi;
}
#endif
