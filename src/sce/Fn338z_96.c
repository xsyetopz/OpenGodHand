// COMPILER: ee-gcc2.96
extern int D_003E8DD4, D_003E9068, D_003E8DDC;
extern void func_00332310();
extern void func_003B5A50();
extern void func_003325F8();

// FUNCTION: GAME 0x33B3B0
void func_0033B3B0(void)
{
    if (--D_003E8DD4 == 0) {
        func_00332310(D_003E9068);
        D_003E9068 = 0;
        if (D_003E8DDC) {
            func_003B5A50(D_003E8DDC);
            D_003E8DDC = 0;
        }
        func_003325F8();
    }
}

typedef struct { void (*fn)(); void *arg; } CbD;
extern CbD D_007588B0;
extern char D_003E9990[];
extern char *strncpy();

// FUNCTION: GAME 0x33B790
void func_0033B790(char *s)
{
    if (!s) {
        D_007588B0.fn(D_007588B0.arg, 0);
    } else {
        strncpy(D_003E9990, s, 0x7F);
        if (D_007588B0.fn)
            D_007588B0.fn(D_007588B0.arg, D_003E9990);
    }
}

extern int D_003E0710, D_003E0708;
extern void func_003402E0(), func_00332670(), func_00337398();

// FUNCTION: GAME 0x3381B0
void func_003381B0(char *o)
{
    int buf[4];
    int i;
    int *p;
    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        o[0] = 0;
        return;
    }
    i = 0;
    if (*(int *)(o + 4) > 0) {
        p = (int *)(o + 0x10);
        do {
            if (*p)
                func_003402E0(*p);
            p++;
            i++;
        } while (i < *(int *)(o + 4));
    }
    buf[0] = *(int *)(o + 0x20);
    func_00332670(9, buf, 1, 0, 0);
    i = 0;
    if (*(int *)(o + 4) > 0) {
        p = (int *)(o + 8);
        do {
            if (*p)
                func_00337398(*p);
            p++;
            i++;
        } while (i < *(int *)(o + 4));
    }
    o[0] = 0;
}

typedef struct { int (*fn)(); int arg; int z; } E3;
extern E3 D_00758620[8][6];
extern volatile int D_003E9970[], D_003E9950[];

// FUNCTION: GAME 0x33BC48
int func_0033BC48(int a)
{
    int r = 0;
    int i;
    E3 *e = D_00758620[a];
    for (i = 5; i >= 0; i--) {
        int (*fn)() = e->fn;
        int arg = e->arg;
        e++;
        if (fn) {
            D_003E9970[a] = 1;
            r |= fn(arg);
            D_003E9970[a] = 0;
        }
    }
    D_003E9950[a]++;
    return r;
}

extern int D_003EAEC0, D_003EB840, D_003EB83C, D_003EB838, D_003EB834, D_003EB708, D_003EB830;
extern char D_003EB810[], D_003EB710[], D_003EB308[], D_003EAEC8[];
extern void func_00323B58();
extern void *memset();

// FUNCTION: GAME 0x33F4C8
void func_0033F4C8(void)
{
    if (--D_003EAEC0 == 0) {
        func_00323B58();
        D_003EB840 = 1;
        D_003EB83C = -1;
        D_003EB838 = 0;
        D_003EB834 = 0;
        D_003EB708 = 0;
        D_003EB830 = 0;
        memset(D_003EB810, 0, 0x20);
        memset(D_003EB710, 0xFF, 0x100);
        memset(D_003EB308, 0, 0x400);
        memset(D_003EAEC8, 0, 0x440);
    }
}
