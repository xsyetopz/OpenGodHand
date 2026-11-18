// Small functions in 0x2E0000-0x2FFFFF.

extern "C" {
void func_002F1AA0(int, unsigned);
void func_002FBED0(void *);

// FUNCTION: GAME 0x2FBE10
void func_002FBE10() {}

// FUNCTION: GAME 0x2FBE18
void func_002FBE18() {}

// FUNCTION: GAME 0x2FBE20
void func_002FBE20() {}

// FUNCTION: GAME 0x2FEBD8
void func_002FEBD8() {}

// FUNCTION: GAME 0x2F1B40
void func_002F1B40() { func_002F1AA0(1, 0xFFFF); }

// FUNCTION: GAME 0x2F29E0
void func_002F29E0(void *p) { func_002FBED0(p); }

void func_002FBE50(void *);
void func_002FBE28(char *);
void func_002FBDD8(void *);
void *func_002E9B68(void *);
void *func_002EBF08(void *);
void *func_002F56C0(void *);
void *func_002F61C8(void *);
extern char D_0044E820[];
extern char D_0044EA10[];
extern char D_0044F880[];
extern char D_0044FAD0[];

// FUNCTION: GAME 0x2FEC30
void func_002FEC30() {}

// FUNCTION: GAME 0x2F3070
void func_002F3070(void *p) { func_002FBED0(p); }

// FUNCTION: GAME 0x2F4D28
void func_002F4D28(void *p) { func_002FBED0(p); }

// FUNCTION: GAME 0x2F5448
void func_002F5448(void *p) { func_002FBED0(p); }

// FUNCTION: GAME 0x2FEBB8
void func_002FEBB8(void *p) { func_002FBE50(p); }

// FUNCTION: GAME 0x2EBC28
void func_002EBC28(char *p)
{
    *(char **)(p + 0xF0) = D_0044E820;
    func_002FBE28(p);
}

// FUNCTION: GAME 0x2EFC80
void func_002EFC80(char *p)
{
    *(char **)(p + 0xF0) = D_0044EA10;
    func_002FBE28(p);
}

// FUNCTION: GAME 0x2FA070
void func_002FA070(char *p)
{
    *(char **)(p + 0xF0) = D_0044F880;
    func_002FBE28(p);
}

// FUNCTION: GAME 0x2FBE28
void func_002FBE28(char *p)
{
    *(char **)(p + 0xF0) = D_0044FAD0;
    func_002FBDD8(p);
}

// FUNCTION: GAME 0x2FFBF8
void *func_002FFBF8(void *p)
{
    void *r = p;
    if (r)
        r = func_002E9B68(p);
    return r;
}

// FUNCTION: GAME 0x2FFC60
void *func_002FFC60(void *p)
{
    void *r = p;
    if (r)
        r = func_002EBF08(p);
    return r;
}

// FUNCTION: GAME 0x2FFF90
void *func_002FFF90(void *p)
{
    void *r = p;
    if (r)
        r = func_002F56C0(p);
    return r;
}

// FUNCTION: GAME 0x2FFFB8
void *func_002FFFB8(void *p)
{
    void *r = p;
    if (r)
        r = func_002F61C8(p);
    return r;
}

void func_002D4FC0(int, unsigned);
void func_002D9B70(int, unsigned);
void func_002D9E98(int, unsigned);
void func_002D9458(char *, char *);
void func_002D5918(char *);
void func_002D5990(char *);

// FUNCTION: GAME 0x2D5000
void func_002D5000() { func_002D4FC0(1, 0xFFFF); }

// FUNCTION: GAME 0x2D9BA0
void func_002D9BA0() { func_002D9B70(1, 0xFFFF); }

// FUNCTION: GAME 0x2D9F08
void func_002D9F08() { func_002D9E98(1, 0xFFFF); }

// FUNCTION: GAME 0x2D98A0
void func_002D98A0(char *p) { func_002D9458(p, p + 0xE8A0); }

// FUNCTION: GAME 0x2D5768
void func_002D5768(int *p, int a, short b, int c)
{
    p[2] = a;
    p[1] = -1;
    *(short *)((char *)p + 0x1C) = b;
    p[0] = c;
    *(short *)((char *)p + 0xC) = 0;
    p[4] = 0;
}

// FUNCTION: GAME 0x2D5890
void func_002D5890(char *p, int a)
{
    *(int *)(p + 0x14) = a;
    *(short *)(p + 0x1E) = 0;
    func_002D5918(p);
}

// FUNCTION: GAME 0x2D5958
void func_002D5958(char *p, int a)
{
    *(int *)(p + 0x14) = a;
    *(short *)(p + 0x1E) = 0;
    func_002D5990(p);
}

// FUNCTION: GAME 0x2D6578
void func_002D6578(char *p, int a)
{
    char *t = *(char **)(p + 4);
    if (t)
        *(float *)(t + 0x68) = (float)a;
}

// FUNCTION: GAME 0x2D65A0
void func_002D65A0(char *p, int a)
{
    char *t = *(char **)(p + 4);
    if (t)
        *(float *)(t + 0x6C) = (float)a;
}

// FUNCTION: GAME 0x2D65D0
void func_002D65D0(char *p, float *out)
{
    char *t = *(char **)(p + 4);
    if (t && out)
        *out = *(float *)(t + 0x6C);
}
}
