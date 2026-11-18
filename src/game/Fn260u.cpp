// Small units in 0x260000-0x270000.

extern unsigned short D_00747A50;
extern char D_005864F0[];
extern "C" char *func_00292DC8(void *, int, float);
extern "C" int func_00294A68(void *);
extern "C" void func_0026E988(void *, int, int, int, float);
extern "C" void func_00273F08(void *);
extern "C" void func_00149AD8(void *, int, int, int);
extern "C" float func_0031D020(void);
extern "C" void func_001F8350(float *, char *, float *);
extern "C" void func_001B1760(void *, float *, float);
struct V3 {
    float x, y, z;
};
static inline float Sq(float a)
{
    float r;
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%1" : "=f"(r) : "f"(a));
    return r;
}

// FUNCTION: GAME 0x26E6B0
extern "C" int func_0026E6B0(char *s)
{
    if (D_00747A50 == 0x501) {
        if (!(0.0f < *(float *)(s + 0x16C0)) && *(int *)(s + 0x16D8) != 0 && (*(int *)(s + 0x1644) & 0x10000)) {
            char *o = func_00292DC8(D_005864F0, *(int *)(s + 0xF0), 10.0f);
            if (o && !func_00294A68(D_005864F0)) {
                D_005864F0[0x540] = 10;
                func_0026E988(s, *(int *)(o + 0xF0), 16, 0, 300.0f);
                s[0x2F7] = 0;
                s[0x2F4] = 0;
                s[0x2F6] = 0;
                s[0x2F5] = 0x13;
                return 1;
            }
        }
    }
    return 0;
}

// FUNCTION: GAME 0x26A558
extern "C" void func_0026A558(char *s)
{
    int t = *(int *)(s + 0x564) ^ 0x251;
    if (t == 0 && !(*(int *)(s + 0x16D4) & 0x10)) {
        if (*(short *)(s + 0x54A) <= *(short *)(s + 0x548) / 2) {
            func_00273F08(s);
            return;
        }
        int p = *(int *)(s + 0x304);
        func_00149AD8(s, *(int *)(s + 0x284), *(int *)(p + 0x60) + p, 0);
        int r = *(unsigned char *)(s + 0x17B0);
        unsigned char n = r;
        if (n && ((r & 1) || n >= 8))
            *(unsigned *)(s + 0x254) |= 0x10000000;
        else
            *(unsigned *)(s + 0x254) &= ~0x10000000;
    }
}

// FUNCTION: GAME 0x26A938
extern "C" void func_0026A938(char *s, int i, int flag)
{
    V3 v;
    __asm__ volatile("sqc2 $vf0, 0(%0)" : : "r"(&v) : "memory");
    char *base = s + 0x6E4; void **slot = (void **)(base + (i << 2));
    void *o = *slot;
    if (o) {
        *slot = 0;
        float a = func_0031D020() * 0.02f;
        float b = func_0031D020() * 0.01f + 0.2f;
        float c = func_0031D020() * 0.02f;
        v.x = a;
        v.y = b;
        v.z = c;
        func_001F8350(&v.x, s + 0x80, &v.x);
        if (flag)
            func_001B1760(o, &v.x, 0.0f);
        else
            func_001B1760(o, &v.x, 150.0f);
    }
}

// FUNCTION: GAME 0x26A838
extern "C" void func_0026A838(char *s, int i)
{
    V3 v;
    __asm__ volatile("sqc2 $vf0, 0(%0)" : : "r"(&v) : "memory");
    char *base = s + 0x6E4;
    void **slot = (void **)(base + (i << 2));
    void *o = *slot;
    if (o) {
        *slot = 0;
        float z = (Sq(*(float *)(s + 0x618)) - 3.0f) * 0.02f;
        if (z < 0.05f) z = 0.05f;
        float x = func_0031D020() * 0.02f;
        float y = func_0031D020() * 0.01f + 0.3f;
        v.x = x;
        v.z = z;
        v.y = y;
        func_001F8350(&v.x, s + 0x80, &v.x);
        func_001B1760(o, &v.x, 150.0f);
    }
}

// FUNCTION: GAME 0x26B9E8
// The slot is typed int-returning: that gives the original v1 (vtable) / v0 (slot) allocation; a void slot swaps them.
#include "game/cVec.h"
struct VT {
    char p[0x40];
    short off;
    short pad;
    int (*fn)(char *);
};
extern "C" char *CreateObj__F6eObjIdT0(int, int);
extern "C" void func_001D0090(char *, char *);
extern "C" void func_0026B9E8(char *s)
{
    int t = *(int *)(s + 0x564) ^ 0x211;
    if (t == 0) {
        char *o = CreateObj__F6eObjIdT0(0x3B8, 0xFFFF);
        if (o) {
            VT *vt = *(VT **)(o + 0x214);
            vt->fn(o + vt->off);
            **(cVec **)(o + 0xF0) = **(cVec **)(s + 0xF0);
            (*(cVec **)(o + 0xF0))->y -= 0.6f;
            *(cVec *)(o + 0x490) = **(cVec **)(o + 0xF0);
            *(int *)(o + 0x100) = 0;
            int *p = (int *)(o + 0x100);
            p[1] = 0;
            p[2] = 0;
            func_001D0090(o, s);
            *(char **)(s + 0x730) = o;
        }
    }
}
