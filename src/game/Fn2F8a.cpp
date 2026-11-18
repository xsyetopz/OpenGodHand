#include "game/Fn2F8Decls.h"

extern "C" {

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
void func_002EBC28(char *p, int f)
{
    *(char **)(p + 0xF0) = D_0044E820;
    func_002FBE28(p, f);
}

// FUNCTION: GAME 0x2EFC80
void func_002EFC80(char *p, int f)
{
    *(char **)(p + 0xF0) = D_0044EA10;
    func_002FBE28(p, f);
}

// FUNCTION: GAME 0x2FA070
void func_002FA070(char *p, int f)
{
    *(char **)(p + 0xF0) = D_0044F880;
    func_002FBE28(p, f);
}

// FUNCTION: GAME 0x2FBE28
void func_002FBE28(char *p, int)
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

// FUNCTION: GAME 0x2D22B0
void *func_002D22B0(cSnd *self, int a, int b)
{
    char *n = *(char **)((char *)self + 0x18);
    while (n) {
        if (*(int *)(n + 0x8C) - 0x80 == a && *(int *)(n + 0x90) == b)
            return n;
        n = *(char **)(n + 0x88);
    }
    return 0;
}

// FUNCTION: GAME 0x2D5080
void func_002D5080(unsigned long *p, int *a, int *b)
{
    *a = 1 << ((*p >> 26) & 0xF);
    *b = 1 << ((*p >> 30) & 0xF);
}

// FUNCTION: GAME 0x2FBE88
void func_002FBE88(char *p)
{
    if (!(*(unsigned *)(p + 0x11C) & 0x10000)) {
        char *v = *(char **)(p + 0xF0);
        ((void (*)(char *))(*(void **)(v + 0x14)))(p + *(short *)(v + 0x10));
    }
}

// FUNCTION: GAME 0x2F3020
int func_002F3020(char *p)
{
    char *q = *(char **)(p + 0x110);
    *(float *)(p + 0x2B8) = *(float *)(q + 0x13C) + 0.5f;
    *(float *)(p + 0x2BC) = 0.7f - *(float *)(q + 0x140);
    *(int *)(p + 0x2B0) = *(unsigned char *)(q + 0x18C) + 1;
    *(int *)(p + 0x2B4) = *(int *)(p + 0x220);
    return 1;
}

// FUNCTION: GAME 0x2D5BB8
void *func_002D5BB8()
{
    if (D_00460D78 == 0)
        func_0031EEC8(&D_00460D78, D_0044D200);
    return &D_00460D78;
}

// FUNCTION: GAME 0x2D5BF8
void *func_002D5BF8()
{
    if (D_00460D80 == 0)
        func_0031EEC8(&D_00460D80, D_0044D210);
    return &D_00460D80;
}

// FUNCTION: GAME 0x2D9EC8
void *func_002D9EC8()
{
    if (D_00460D88 == 0)
        func_0031EEC8(&D_00460D88, D_0044D3A0);
    return &D_00460D88;
}

// FUNCTION: GAME 0x2D9FF8
void *func_002D9FF8()
{
    if (D_00460D90 == 0)
        func_0031EEC8(&D_00460D90, D_0044D3D8);
    return &D_00460D90;
}

// FUNCTION: GAME 0x2EFA60
void *func_002EFA60()
{
    if (D_007863F8 == 0) {
        func_00300148();
        func_0031EEA8(&D_007863F8, D_0044E9F8, D_007863C8);
    }
    return &D_007863F8;
}

// FUNCTION: GAME 0x2F3DC0
void *func_002F3DC0()
{
    if (D_007864C8 == 0) {
        func_00300148();
        func_0031EEA8(&D_007864C8, D_0044F030, D_007863C8);
    }
    return &D_007864C8;
}

} // extern "C"
