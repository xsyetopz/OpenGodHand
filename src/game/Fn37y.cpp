// More small functions in the ProDG game-code island 0x370000-0x387430.

extern "C" {
void func_0032E040(int *, int);
int func_00385E98(int);
void *memset(void *, int, unsigned);
extern char Sde_iss_hed[];
extern int D_0076A790[];
extern char D_0076CF20[];
}

// FUNCTION: GAME 0x374570
extern "C" void func_00374570(int **p)
{
    if (*p)
        func_0032E040(*p, 1);
}

// FUNCTION: GAME 0x374598
extern "C" void func_00374598(int **p)
{
    if (*p)
        func_0032E040(*p, 0);
}

// FUNCTION: GAME 0x377D58
extern "C" void func_00377D58()
{
    memset(Sde_iss_hed, 0, 0x600);
}

// FUNCTION: GAME 0x377FF8
extern "C" int func_00377FF8()
{
    int *p = D_0076A790;
    int v = p[6] + 1;
    p[6] = v;
    if (!v)
        p[6] = 1;
    return p[6];
}

// FUNCTION: GAME 0x37D388
extern "C" char *func_0037D388(signed char n)
{
    char *e = D_0076CF20 + n * 0x50;
    return *(unsigned short *)e ? 0 : e;
}

// FUNCTION: GAME 0x376CF8
extern "C" void func_00376CF8(unsigned short *a, unsigned short *b)
{
    b[0xB] = a[0xB];
    b[0xC] = a[0x12];
    b[0xD] = a[0x13];
    b[0xE] = a[0x14];
    b[0xF] = a[0x15];
}

// FUNCTION: GAME 0x37E8D8
extern "C" int func_0037E8D8(int *p)
{
    p[2] = 0;
    p[3] = 0;
    return func_00385E98(p[4]) != 0;
}

// FUNCTION: GAME 0x380870
extern "C" unsigned func_00380870(unsigned v)
{
    return (v << 24) | ((v << 8) & 0xFF0000) | ((v >> 8) & 0xFF00) | (v >> 24);
}

extern "C" {
void func_003749D8(int);
int func_0037FE78(char *, char *);
void func_002E0DE8(int, int, int, const char *, int);
int func_0037D1A8(int, int);
extern char D_0045CD40[];
extern unsigned char D_0076A7B4;
extern char D_0076EA50[];
void func_00375FA0();
void func_00376008();
void func_00376370();
void func_0037BE98();
void func_00376E38();
void func_00376EA0();
void func_003774A8();
void func_00378AE0(void *);
void func_0037B0E0(void *);
void func_00378D18(void *);
void func_003794D0(void *);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x37B768 - 8 words; gcc folds 0x16C into the sh offset; an empty asm("+r"(off)) barrier after the add matches but is not allowed
extern "C" void func_0037B768(char *o)
{
    register int off asm("$5") = o[0x27];
    off = off * 32 + 0x16C;
    char *q = o + off;
    *(short *)q = 0;
    func_003749D8(o[0x27]);
}
#endif

// FUNCTION: GAME 0x37C5C8
extern "C" void func_0037C5C8(unsigned short *o, unsigned short *s, unsigned short mode)
{
    if (mode == 2)
        o[0x1D] = s[0x19];
    else
        o[0x1C] = s[0x18];
    o[3] |= 9;
}

// FUNCTION: GAME 0x383848
extern "C" void func_00383848(char *o)
{
    if (func_0037FE78(o, o + 0x370))
        o[2] = 0;
}

// FUNCTION: GAME 0x384B98
extern "C" void func_00384B98(int a, int b)
{
    func_002E0DE8(3, 0x18, 8, D_0045CD40, b);
}

// FUNCTION: GAME 0x375180
extern "C" int func_00375180()
{
    if (func_0037D1A8(1, 0))
        return 1;
    return D_0076A7B4 != 0;
}

// FUNCTION: GAME 0x375A78
extern "C" void func_00375A78(short n)
{
    memset(D_0076EA50 + (n << 5), 0, 0x20);
}

// FUNCTION: GAME 0x375F68
extern "C" void func_00375F68()
{
    func_00375FA0();
    func_00376008();
    func_00376370();
    func_0037BE98();
}

// FUNCTION: GAME 0x376E00
extern "C" void func_00376E00()
{
    func_00376E38();
    func_00376EA0();
    func_003774A8();
    func_0037BE98();
}

// FUNCTION: GAME 0x378AA8
extern "C" void func_00378AA8(void *o)
{
    func_00378AE0(o);
    func_0037B0E0(o);
    func_00378D18(o);
}

// FUNCTION: GAME 0x378CE0
extern "C" void func_00378CE0(void *o)
{
    func_00378AE0(o);
    func_0037B0E0(o);
    func_003794D0(o);
}

extern "C" {
extern char D_0076E590[];
extern char D_0076B9C0[];
void func_0037ACA0(void *);
void func_0037AEC0(void *);
void func_0037D680(void *);
}

// FUNCTION: GAME 0x37D170
extern "C" unsigned short *func_0037D170()
{
    int p = (int)D_0076B9C0;
    int e = p + 0xF00;
    do {
        if (*(unsigned short *)p != 0) { p += 0x50; continue; }
        return (unsigned short *)p;
    } while (p < e);
    return 0;
}

// FUNCTION: GAME 0x37AC68
extern "C" void func_0037AC68(void *o)
{
    func_0037ACA0(o);
    func_0037B0E0(o);
    func_0037AEC0(o);
}

// FUNCTION: GAME 0x37C2A8
extern "C" void func_0037C2A8(unsigned short *o, unsigned short *s)
{
    o[0x20] = s[0x1A];
    o[0x21] = s[0x1B];
    o[0x16] = s[0xE];
    func_0037D680(o);
}
