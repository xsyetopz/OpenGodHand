// COMPILER: ee-gcc2.96
// Small units of 0x330000-0x33FFFF.
extern int D_003E0710;
extern int D_003E0708;

// FUNCTION: GAME 0x337B80
extern "C" void func_00337B80(unsigned char *p, unsigned a)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0) return;
    if (a < 2 && *(signed char *)(p + 0x56) != (int)a) {
        p[1] = p[0x56];
        p[0x56] = a;
    }
}

// FUNCTION: GAME 0x338788
extern "C" void func_00338788(char *p, int a)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0) return;
    if (a > 0) a = 0;
    if (a < -999) a = -999;
    *(int *)(p + 0x38) = a;
}

extern int D_003E0734, D_003E0730, D_003E070C;
extern char D_00455398[], D_004553C8[], D_004553F8[];
extern "C" void func_003260C8(char *, int);

// FUNCTION: GAME 0x336E88
extern "C" void PS2RNA_SetupVoice(int a, int b)
{
    if (a < 0) { func_003260C8(D_00455398, a); return; }
    if (b < 0) { func_003260C8(D_004553C8, b); return; }
    int n = a * 2 + b;
    if (n > 0x20) { func_003260C8(D_004553F8, 0x20); return; }
    D_003E0708 = n;
    D_003E0730 = a;
    D_003E0734 = b;
    D_003E070C = (n * 65) << 8;
    D_003E0710 = 1;
}

extern char D_00455090[], D_004550B8[], D_004550E0[];
extern "C" void func_00336330(int, char *);
extern "C" char *func_00336530();
extern "C" void func_003A57C4(char *, char *);
extern "C" void func_003365A8(char *);
// FUNCTION: GAME 0x336618
extern "C" char *func_00336618(char *a, int b, int c)
{
    if (!a) { func_00336330((int)a, D_00455090); return 0; }
    if (c) { func_00336330(0, D_004550B8); return 0; }
    char *p = func_00336530();
    if (!p) { func_00336330(0, D_004550E0); return 0; }
    func_003A57C4(p + 0x1C, a);
    func_003365A8(p);
    return p;
}

extern "C" void func_0033B688();
extern "C" void func_0033B6B8();
// FUNCTION: GAME 0x331200
extern "C" int func_00331200(signed char *p, int a, long b, long c, int d)
{
    int r = 0;
    func_0033B688();
    int s = p[2];
    if (s == 0 || s == 3 || s == 9) {
        p[1] = 2;
        *(int *)(p + 0x30) = a;
        p[2] = 1;
        r = 1;
        *(int *)(p + 0x18) = d;
        *(long *)(p + 0x20) = c;
        *(long *)(p + 0x28) = b;
        *(int *)(p + 4) = 0;
    }
    func_0033B6B8();
    return r;
}

struct Slot { void *f0; int f4; char *f8; int fc, f10; int f14, f18; void *f1c; void *f20; };
extern Slot D_003E3AD0[32];
extern char D_003E3A98[], D_004558F0[];
extern "C" void func_00338A28(void);
extern "C" void func_00338EC8(Slot *);
// FUNCTION: GAME 0x338BD8
extern "C" Slot *func_00338BD8(int a, int b)
{
    int i;
    for (i = 0; i < 32; i++)
        if (D_003E3AD0[i].f4 == 0) break;
    if (i == 32) return 0;
    Slot *s = &D_003E3AD0[i];
    s->f4 = 1;
    s->f0 = D_003E3A98;
    s->f14 = a;
    s->f18 = b;
    s->f8 = D_004558F0;
    s->f1c = (void *)func_00338A28;
    s->f20 = s;
    func_00338EC8(s);
    return s;
}

struct E44 { char st; char pad[0x43]; };
extern int D_003E84BC;
extern E44 D_003E84C0[16];
extern "C" void func_00332310(E44 *);
// FUNCTION: GAME 0x3325F8
extern "C" void func_003325F8()
{
    if (--D_003E84BC == 0) {
        int one = 1;
        E44 *e = D_003E84C0;
        for (int i = 15; i >= 0; i--, e++)
            if (e->st == one)
                func_00332310(e);
    }
}

struct E48 { char st; char pad[0x47]; };
extern int D_003D90E0;
extern E48 D_003D9150[40];
extern "C" int func_0033BF18(int *);
extern "C" void func_00332890(E48 *);
// FUNCTION: GAME 0x332958
extern "C" void func_00332958()
{
    if (func_0033BF18(&D_003D90E0)) {
        int one = 1;
        E48 *e = D_003D9150;
        for (int i = 39; i >= 0; i--, e++)
            if (e->st == one)
                func_00332890(e);
        D_003D90E0 = 0;
    }
}

struct E30 { char st; char pad[0x2F]; };
extern int D_003D9F74;
extern E30 D_003D9FE0[13];
extern "C" void func_003340F0(E30 *);
// FUNCTION: GAME 0x3341B8
extern "C" void func_003341B8()
{
    if (func_0033BF18(&D_003D9F74)) {
        int one = 1;
        E30 *e = D_003D9FE0;
        for (int i = 12; i >= 0; i--, e++)
            if (e->st == one)
                func_003340F0(e);
        D_003D9F74 = 0;
    }
}

// FUNCTION: GAME 0x336378
extern "C" int func_00336378(char *s, char **end, int radix)
{
    int r = 0;
    for (;;) {
        unsigned char c = *s;
        int v;
        if ((unsigned)(c - '0') < 10) v = (signed char)c - '0';
        else if ((unsigned)(c - 'a') < 6) v = (signed char)c - 0x57;
        else if ((unsigned)(c - 'A') < 6) v = (signed char)c - 0x37;
        else break;
        r = r * radix + v;
        s++;
    }
    *end = s;
    return r;
}
