// COMPILER: ee-gcc2.96
// SCE framed wrappers (continued from Fn32x_96.c), -O2 -G0.

int func_003228C0();
int adxf_CreateAdxFs(void);
int func_00323700();
void func_00323AA0();
void func_003381B0();
void func_003382A0();
void func_00338338();
void func_0033CEE8();
void func_0033CF88();
void func_0033CF90();
void func_0033CFB8();
void func_0033CFF8();

// FUNCTION: GAME 0x323780
int func_00323780(int a, int b, int c, int d)
{
    int r;
    func_003228C0(1, 0, a, b, -1);
    r = adxf_CreateAdxFs();
    if (r) {
        if (func_00323700(r, a, b, c, d) < 0) {
            func_00323AA0(r);
            r = 0;
        }
    }
    func_003228C0(1, 1, a, b, -1);
    return r;
}

// FUNCTION: GAME 0x327860
void func_00327860(void *a) 
{
    func_0033CF88(((int*)a)[1]);
}

// FUNCTION: GAME 0x327878
void func_00327878(void *a) 
{
    func_0033CF90(((int*)a)[1]);
}

// FUNCTION: GAME 0x327950
void func_00327950(void *a) 
{
    func_0033CEE8(((int*)a)[1]);
}

// FUNCTION: GAME 0x327970
void func_00327970(void *a) 
{
    func_0033CFB8(((int*)a)[1]);
}

// FUNCTION: GAME 0x327988
void func_00327988(void *a) 
{
    func_0033CFF8(((int*)a)[1]);
}

// FUNCTION: GAME 0x3262D8
void func_003262D8(int a)
{
    func_00338338(a, 0);
    func_003382A0(a, 0);
    func_003381B0(a);
}

void *memset(void *, int, unsigned);
int func_003228C0();
int adxf_CreateAdxFs(void);
int adxf_SetFileInfoEx(int, int, int);
int func_00323840(int, int, int);
int adxf_Stop();
void func_00328018();
void func_00327D90();
int func_0033D190();
void func_0033D870();
void func_00326CB8();
void func_00327048();
void func_00327230();
void func_0033E678();
void func_0033E690();
void func_00327418();
void func_00326890();
void func_00327568();

// FUNCTION: GAME 0x323AA0
void func_00323AA0(char *s)
{
    int h;
    func_003228C0(3, 0, s, -1, -1);
    if (s) {
        if (s[1] == 2)
            adxf_Stop(s);
        h = *(int *)(s + 4);
        if (h) {
            s[0] = 0;
            *(int *)(s + 4) = 0;
            func_00328018(h);
            func_00327D90(h);
        }
        memset(s, 0, 0x44);
        func_003228C0(3, 1, s, -1, -1);
    }
}

// FUNCTION: GAME 0x323660
int func_00323660(int a, int b)
{
    int r;
    func_003228C0(1, 0, a, b, -1);
    r = adxf_CreateAdxFs();
    if (r) {
        if (adxf_SetFileInfoEx(r, a, b) < 0) {
            func_00323AA0((char *)r);
            r = 0;
        }
    }
    func_003228C0(1, 1, a, b, -1);
    return r;
}

// FUNCTION: GAME 0x323960
int func_00323960(int a, int b)
{
    int r;
    func_003228C0(2, 0, a, b, -1);
    r = adxf_CreateAdxFs();
    if (r) {
        if (func_00323840(r, a, b) < 0) {
            func_00323AA0((char *)r);
            r = 0;
        }
    }
    func_003228C0(2, 1, a, b, -1);
    return r;
}

// FUNCTION: GAME 0x3272C0
void func_003272C0(char *s)
{
    char *h = *(char **)(s + 4);
    int t;
    if (!func_0033D190(h))
        func_00326CB8(s);
    func_0033D870(h);
    if (func_0033D190(h) == 3)
        func_00327048(s);
    t = *(short *)(h + 0x98);
    if (t == 10 || t == 20 || t == 11 || t == 12 || t == 15)
        func_00327230(s);
}

// FUNCTION: GAME 0x327370
void func_00327370(char *s)
{
    if (*(int *)(s + 0xA0) > 0) {
        func_0033E678();
        func_00327418(s);
        func_0033E690();
    }
    if (s[1] == 2)
        func_003272C0(s);
    else if (s[1] == 1)
        func_00326890(s);
    if (*(int *)(s + 0xA4) > 0) {
        func_0033E678();
        func_00327568(s);
        func_0033E690();
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x323568 (2 words differ: sw 0x34(s0) is scheduled after lw a0,4(s0) instead of before)
extern char D_00451658[];
void func_0033F130();
int func_00327F00();
int func_00328098();
int func_00328D40();
int func_00328D80();
int adxf_SetFileInfoEx(int *s, int b, int c)
{
    if (!b) {
        func_0033F130(D_00451658);
        return -1;
    }
    s[13] = c;
    s[5] = 0;
    s[14] = b;
    func_00327F00(s[1], b, c, 0, 0xFFFFF);
    if (func_00328098(s[1]) == 4) {
        func_00328018(s[1]);
        return -1;
    }
    {
        int v;
        s[4] = func_00328D40(s[1]);
        v = func_00328D80(s[1]);
        s[15] = 0;
        s[3] = v;
        s[16] = v;
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x323840 (23 words differ: stack out-param load/store order of 0x100/0x104 slots)
int func_00324640();
int func_00324808();
int func_00327F00();
int func_00328098();
void func_00328018();
int func_00323840(int *s, int b, int c)
{
    char buf[256];
    int t, r, q, p;
    int v;
    if (func_00324640(b, c, buf, &p, &q, &r, &t) < 0)
        return -3;
    s[13] = p;
    s[12] = q;
    v = func_00324808(b);
    s[5] = 0;
    s[16] = r;
    s[14] = v;
    s[15] = q;
    func_00327F00(s[1], v, s[13], q, r);
    if (func_00328098(s[1]) == 4) {
        func_00328018(s[1]);
        return -1;
    }
    s[3] = r;
    s[4] = t;
    return 0;
}
#endif
