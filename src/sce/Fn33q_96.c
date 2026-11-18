// COMPILER: ee-gcc2.96
extern int D_003E0710, D_003E0708, D_003E0738, D_003E0748[];
extern char D_004559F0[], D_00455920[], D_00455A00[], D_00455950[];
extern struct { void (*f)(int); int arg; } D_007588A8;
extern volatile int D_003E9948, D_003E994C;
extern char D_00455E78[];
int func_00332670(int, int, int, int *, int);
void func_00338A48(char *, char *);
void func_0033B6E8(char *, int);

// FUNCTION: GAME 0x337C00
void func_00337C00(void)
{
    int t[2];
    if (D_003E0710 == 1 && D_003E0708 <= 0) return;
    if (D_003E0738 != 1) {
        int x, y;
        func_00332670(14, 0, 0, t, 2);
        x = t[0]; y = t[1];
        D_003E0748[0] = x;
        D_003E0748[1] = y;
        D_003E0738 = 1;
    }
}

// FUNCTION: GAME 0x339108
void func_00339108(int *a, int b, int *c)
{
    if (a == 0) { func_00338A48(D_004559F0, D_00455920); return; }
    if (a[1] == 0) { func_00338A48(D_00455A00, D_00455950); return; }
    if (c[1] > 0 && c[0] != 0 && b != 0 && b != 1) {
        int (*f)(int, int);
        f = (int (*)(int,int))a[7];
        c[1] = 0;
        c[0] = 0;
        if (f) f(a[8], -3);
    }
}

// FUNCTION: GAME 0x33C3A0
int func_0033C3A0(unsigned char *p)
{
    if (p[0] == 0xB && p[1] == 0x77) return 1;
    if (p[0] == 0x77 && p[1] == 0xB) return 1;
    if (p[16] == 0xB && p[17] == 0x77) return 1;
    if (p[16] == 0x77 && p[17] == 0xB) return 1;
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x33B5C8
// diff: 2 words, original keeps the argument in $a2 where the compile uses $a1
void func_0033B5C8(int a)
{
    if (D_007588A8.f) {
        if (--D_003E9948 == 0) {
            if (D_003E994C != a) func_0033B6E8(D_00455E78, D_003E994C);
            D_003E994C = 0;
        }
        D_007588A8.f(D_007588A8.arg);
    }
}

// DRAFT: GAME 0x33CC50
// diff: 39 words, struct init store/load order differs (144 vs 156 bytes)
typedef struct { char p0[0x10]; int w10; short h1C; short pad; int w20; short h24, h26; int w28, w2c, w30, w34; int w3c, w40, w44; int w50, w54, w58, w5c, w60, w64; int w88, w8c; short h98, h9a; } S;
void func_0033CC50(char *q)
{
    S *s = (S *)q;
    *(short *)(q + 2) = 1;
    *(int *)(q + 0x14) = 0xBB80;
    q[0xE] = 2;
    q[0xD] = 0x10;
    *(int *)(q + 0x18) = 0x7FFFFFFF;
    q[0xF] = 0x7F;
    s->h98 = s->h9a;
    s->w50 = 2;
    s->w54 = 0x7F;
    s->w58 = 0x400;
    s->w5c = s->w3c;
    s->w60 = s->w40;
    s->w64 = s->w44;
    s->w88 = 0;
    s->w10 = 0x400;
    s->w8c = 0;
    s->h1C = 0;
    s->h24 = 0;
    s->h26 = 0;
    s->w20 = 0;
    s->w28 = 0;
    s->w2c = 0;
    s->w30 = 0;
    s->w34 = 0;
}
#endif
