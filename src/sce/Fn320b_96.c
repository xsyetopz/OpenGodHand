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
extern int func_0033F130();
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
