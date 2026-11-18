// COMPILER: ee-gcc2.96
extern int func_00322C68();
extern char D_003EAEC8[];
extern int D_003C80E0;
extern volatile int D_003C8138;
extern int D_003CF9D0;
extern int func_00325360(), func_003AFB90(), func_003AFB30(), func_003AFBA0(), func_003AFC10();
extern volatile long D_003C8158, D_003C8168, D_003C8178, D_003C8188, D_003C8198, D_003C81A8;
extern volatile long D_003C8160;
extern void func_00324E98(), func_003AFAE0(), func_0033F130(), func_0033F3D0();
extern int *D_003EB308[], D_003EB708;
extern char D_00451A18[], D_00451A40[];

extern char _gp[], D_003C81D0[], D_003C99D0[];
extern int D_003CF9D8, D_003C80B4, D_003C80BC;
extern volatile int D_003C8138, D_003C8140;
extern int CreateThread(), StartThread(), func_00325360(), func_003AFB30();
extern void func_00324EB0(), func_00324F08();
extern char _gp[], D_003CB9D0[];
extern int D_003CF9D8, D_003C80C8, D_003C80A4, D_003C80FC;
extern volatile int D_003C814C, D_003C8150, D_003C8148;
extern int func_003252F8(), func_00325610(), func_003AFBA0(), func_003AFBD0();
extern void func_00325100(), func_00325290();
extern void func_003257C8(), func_003258B8(), func_00325A58(), func_00325988(), func_00325B90();
extern void func_0033BC18(), func_0033BC30(), func_0033BEC0(), func_00329028(), func_00329040();
// FUNCTION: GAME 0x322B88
int func_00322B88(int a, int b, int c, int d, int e, int f)
{
    return func_00322C68(a, 0, 0, b, c, 0, 0xFFFFF, d, e, f, 0);
}

// FUNCTION: GAME 0x322BD8
int func_00322BD8(int a, int b, int c, int d, int e, int f)
{
    return func_00322C68(a, b, c, 0, 0, 0, 0xFFFFF, d, e, f, 0);
}

// FUNCTION: GAME 0x322C18
int func_00322C18(int a, int b, int c, int d, int e, int f)
{
    return func_00322C68(a, 0, 0, b, c, 0, 0xFFFFF, d, e, f, 1);
}

// FUNCTION: GAME 0x323478
char *func_00323478(void)
{
    char *r = 0;
    int i;
    for (i = 0; i < 16; i++) {
        char *q = D_003EAEC8 + i * 0x44;
        if (*q == 0) {
            r = q;
            break;
        }
    }
    return r;
}

// FUNCTION: GAME 0x323A00
void func_00323A00(int *s)
{
    int *o = (int *)s[2];
    if (o) {
        if (((char *)s)[2] == 0) {
            if (D_003EB708 == 1) {
                func_0033F3D0(s[9], s[10]);
                o = (int *)s[2];
            }
            {
                int *vt = (int *)*o;
                s[2] = 0;
                ((void (*)(int *))vt[3])(o);
            }
        }
    }
}

// FUNCTION: GAME 0x324530
int func_00324530(unsigned a, int b)
{
    int *p;
    if (a >= 0x100) {
        func_0033F130(D_00451A18);
        return -3;
    }
    p = D_003EB308[a];
    if (p == 0) {
        func_0033F130(D_00451A18);
        return -3;
    }
    if (b < 0 || b >= p[2]) {
        func_0033F130(D_00451A40);
        return -3;
    }
    return 0;
}

// FUNCTION: GAME 0x324D18
void func_00324D18(void)
{
    if (--D_003C80E0 == 0) {
        func_00325360(D_003C8138);
        D_003C8138;
        func_003AFB30(func_003AFB90(), D_003CF9D0);
    }
    if (D_003C80E0 < 0)
        D_003C80E0 = 0;
}

// FUNCTION: GAME 0x324EB0
void func_00324EB0(void)
{
    if (D_003C8158 == 0) {
        do
            func_00324E98();
        while (D_003C8158 == 0);
    }
    D_003C8160 = 1;
    func_003AFAE0();
}

// FUNCTION: GAME 0x325360
int func_00325360(int a)
{
    int st[12];
    int r = 0;
    if (a) {
        func_003AFBA0(a, st);
        if (st[0] != 8 && st[0] != 12)
            r = func_003AFC10(a);
    }
    return r;
}

// FUNCTION: GAME 0x3257C8
void func_003257C8(void)
{
    D_003C8158 = 1;
    D_003C8168 = 1;
    D_003C8178 = 1;
    D_003C8188 = 1;
    D_003C8198 = 1;
    D_003C81A8 = 1;
}

// FUNCTION: GAME 0x326568
void func_00326568(int *p)
{
    p[14] = 0x7FFFFFFF;
    p[41] = 0;
    p[38] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[16] = 0;
    p[17] = 0;
    ((char *)p)[3] = 0;
    p[40] = 0;
    p[15] = -1;
}

// FUNCTION: GAME 0x3253C0
void func_003253C0(void)
{
    int p[12];
    p[1] = (int)func_00324EB0;
    p[2] = (int)D_003C81D0;
    p[3] = 0x800;
    p[5] = D_003CF9D8;
    p[4] = (int)_gp;
    D_003C8138 = CreateThread(p);
    D_003C8138;
    StartThread(D_003C8138, 0);
    if (D_003C8138) {
        func_00325360(D_003C8138);
        D_003C8138;
    }
    func_003AFB30(D_003C8138, D_003C80B4);
}

// FUNCTION: GAME 0x325468
void func_00325468(void)
{
    int p[12];
    p[1] = (int)func_00324F08;
    p[2] = (int)D_003C99D0;
    p[3] = 0x1000;
    p[5] = D_003CF9D8;
    p[4] = (int)_gp;
    D_003C8140 = CreateThread(p);
    D_003C8140;
    StartThread(D_003C8140, 0);
    func_003AFB30(D_003C8140, D_003C80BC);
}

// FUNCTION: GAME 0x325578
void func_00325578(void)
{
    int p[12];
    p[1] = (int)func_00325100;
    p[2] = (int)D_003CB9D0;
    p[3] = 0x2000;
    p[5] = D_003CF9D8;
    p[4] = (int)_gp;
    D_003C814C = CreateThread(p);
    D_003C814C;
    StartThread(D_003C814C, 0);
    func_003AFB30(D_003C814C, D_003C80C8);
    func_00325360(D_003C814C);
    D_003C814C;
}

// FUNCTION: GAME 0x325818
void func_00325818(void)
{
    if (--D_003C80A4 == 0) {
        func_003257C8();
        func_003258B8();
        func_00325A58();
        func_00325988();
        func_00325B90();
        func_003AFB30(D_003C8148, D_003CF9D8);
        func_0033BC18(0, 0);
        func_0033BC30(0, 0);
        func_0033BEC0();
    }
}

// FUNCTION: GAME 0x325DF0
void func_00325DF0(void)
{
    if (func_003252F8(D_003C814C) == D_003C814C)
        func_00325290(D_003C814C);
    if (func_00325610() == 1) {
        if (func_003252F8(D_003C8150) == D_003C8150)
            func_00325290(D_003C8150);
    }
}

// FUNCTION: GAME 0x325E78
void func_00325E78(void)
{
    int st[12];
    if (D_003C80FC == 1) {
        func_003AFBA0(D_003C8148, st);
        if (st[0] == 4 || st[0] == 12) {
            if (func_003AFBD0(D_003C8148) == D_003C8148)
                D_003C80FC = 0;
        }
    }
}

// FUNCTION: GAME 0x327E88
void func_00327E88(int *o, int a1, int a2, int a3, int t)
{
    func_00329028(o);
    o[3] = a3;
    o[4] = t << 11;
    o[5] = t;
    o[20] = a1;
    o[21] = a2;
    ((char *)o)[0x45] = 1;
    func_00329040();
}
