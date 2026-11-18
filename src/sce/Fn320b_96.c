// COMPILER: ee-gcc2.96
// FLAGS: -O2
// SCE helpers in 0x322000-0x328098 compiled with 2.96 (continuation of Fn320_96.c).
extern int func_003AFBB0();
extern int func_003AFBA0();
extern int func_003AFBD0();
extern int func_003AFC30();
extern int func_003B0A40();
extern int func_00328368();
extern int func_00328018();
extern int func_00327370();
extern int func_0033C918();
extern int func_0033E678();
extern int func_0033E690();
extern int func_0033CF98();
extern int func_0033CFA8();
extern void *memset();
extern char D_003CF9F0[];
extern void func_0033F130();
extern int adxf_GetStat();
extern int adxf_Stop();
extern int func_00322F18();
extern int D_003EB838, D_003EB83C, D_003EB840;
extern char D_004513C8[], D_00451390[];

// FUNCTION: GAME 0x325240
void func_00325240(int o)
{
    int buf[12];
    if (o) {
        func_003AFBB0(o, buf);
        if (buf[0] == 4 || buf[0] == 12)
            func_003B0A40(o);
    }
}

// FUNCTION: GAME 0x325290
void func_00325290(int o)
{
    int buf[12];
    if (o) {
        func_003AFBA0(o, buf);
        if (buf[0] == 4 || buf[0] == 12)
            func_003AFBD0(o);
    }
}

// FUNCTION: GAME 0x3252F8
int func_003252F8(int o)
{
    int buf[12];
    int r = 0;
    if (o) {
        func_003AFBA0(o, buf);
        if (buf[0] == 8 || buf[0] == 12)
            r = func_003AFC30(o);
    }
    return r;
}

// FUNCTION: GAME 0x327DC0
void func_00327DC0(char *o)
{
    if (o) {
        func_00328368();
        func_00328018(o);
        o[0] = 0;
        memset(o, 0, 0x60);
    }
}

// FUNCTION: GAME 0x3276A8
void func_003276A8()
{
    char *p = D_003CF9F0;
    do {
        if (*p == 1)
            func_00327370(p);
        p += 0xAC;
    } while ((int)p < (int)D_003CF9F0 + 0xAC0);
}

// FUNCTION: GAME 0x326718
void func_00326718(int *o)
{
    if (o) {
        if (o[1]) {
            int t = o[1];
            o[1] = 0;
            func_0033C918(t);
        }
        func_0033E678();
        memset(o, 0, 0xAC);
        func_0033E690();
    }
}

// FUNCTION: GAME 0x322F80
void func_00322F80()
{
    if (D_003EB838 && D_003EB83C >= 0) {
        if (adxf_GetStat(D_003EB838) != 1)
            adxf_Stop(D_003EB838);
        D_003EB840 = 1;
        func_00322F18();
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x322978 (4 words off, string pointer temp in v0 instead of a0)
int adxf_ChkPrmPt(unsigned a, int b)
{
    char *m;
    if (a >= 0x100) {
        m = D_00451390;
    } else {
        if (b)
            return 0;
        m = D_004513C8;
    }
    func_0033F130(m);
    return -3;
}

// DRAFT: GAME 0x3278E8 (5 words off, -0x80 delay-slot duplication differs)
int func_003278E8(unsigned char *o, int b)
{
    int r;
    if (func_0033CF98(*(int *)(o + 4)) > 0 && (unsigned)(o[1] - 2) < 2)
        r = func_0033CFA8(*(int *)(o + 4), b);
    else
        r = -0x80;
    return r;
}
#endif

struct O328 { int p0, p1, p2, p3, p4, n; char pad[0x40]; int m; };
struct Q328 { int p0, p1, p2, p3, p4, n, p6, p7, p8, p9, p10, p11, s; };
extern int func_00329070();
extern int func_00329088();

// FUNCTION: GAME 0x328120
int func_00328120(struct O328 *o, int v)
{
    o->m = v;
    if (o->n < v)
        o->m = o->n;
    return o->m;
}

// FUNCTION: GAME 0x328178
int func_00328178(struct O328 *o)
{
    if (o->p2)
        return o->m;
    return 0;
}

// FUNCTION: GAME 0x328488
void func_00328488(struct Q328 *o, int v)
{
    if (v >= 0)
        o->s = v;
    else
        o->s = o->n;
}

// FUNCTION: GAME 0x3280D8
int func_003280D8(int a, int b)
{
    int r;
    func_00329070();
    r = func_00328120((struct O328 *)a, b);
    func_00329088();
    return r;
}

// FUNCTION: GAME 0x328190
void func_00328190(char *o)
{
    *(int *)(o + 0x34) = 0;
    *(int *)(o + 0x4C) = 0;
    if (*(int *)(o + 0x14) == 0)
        o[1] = 3;
    else
        o[1] = 2;
    o[2] = 0;
    *(int *)(o + 0x24) = 0;
    *(int *)(o + 0x28) = 0;
    o[0x47] = 1;
}

extern int func_00329028();
extern int func_00329040();
extern int func_00328288();
extern void func_0033F130();
extern char D_00452288[], D_004522E8[];

// FUNCTION: GAME 0x328200
int func_00328200(char *o)
{
    func_00329028();
    func_00328190(o);
    *(int *)(o + 0x5C) = 0xFFFFF;
    func_00329040();
    return 1;
}

// FUNCTION: GAME 0x328240
int func_00328240(int a, int b)
{
    int r;
    func_00329070();
    r = func_00328288(a, b);
    func_00329088();
    return r;
}

// FUNCTION: GAME 0x32A9C0
int func_0032A9C0(char *o)
{
    if (!o) {
        func_0033F130(D_00452288);
        return 0;
    }
    return *(short *)(o + 0x46);
}

// FUNCTION: GAME 0x32AAD8
int func_0032AAD8(char *o)
{
    if (!o) {
        func_0033F130(D_004522E8);
        return 0;
    }
    return *(short *)(o + 0x40);
}
