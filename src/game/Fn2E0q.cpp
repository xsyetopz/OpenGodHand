// Varargs printf wrappers and ESP object update units in 0x2E0000-0x300000.
typedef void *va_list;
extern unsigned D_00747A84;
extern "C" void func_002E0C80(int a, int b, int c, int d, int e, const char *fmt, void *ap);
extern "C" void func_002E0B78(int a, int b, int c, int d, int e, int f, int g, const char *fmt, void *ap);
extern "C" void func_002FA350(float *);
extern "C" void func_002FBE50(void *);

// FUNCTION: GAME 0x2E0D60
extern "C" void printf__FiiiiiiPCce(int a, int b, int c, int d, int e, int f, const char *fmt, ...)
{
    va_list ap = (va_list)((char *)__builtin_next_arg(fmt) - 8);
    func_002E0B78(a, b, c, d, e, f, 0, fmt, ap);
}

// FUNCTION: GAME 0x2E0DA8
extern "C" void printf__FiiiiPCce(int a, int b, int c, int d, const char *fmt, ...)
{
    va_list ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x18);
    func_002E0C80(a, b, c, d, 0, fmt, ap);
}

// FUNCTION: GAME 0x2FC9A8
extern "C" int func_002FC9A8(char *s)
{
    short c = *(short *)(s + 0x238);
    if (c <= 0) {
        if (!(*(unsigned *)(*(char **)(s + 0x110) + 4) & 0x2000) && (s[0x11D] & 1))
            goto do_call;
        if (D_00747A84 & 0x20000)
            goto do_call;
        goto do_add;
    }
    if (*(short *)(s + 0x22E) >= c) {
        unsigned f = *(unsigned *)(s + 0x11C);
        if (f & 0x800) {
            if (f & 0x400)
                *(short *)(s + 0x22E) = 0;
            else
                *(short *)(s + 0x22E) = *(unsigned short *)(s + 0x238);
        } else {
            func_002FBE50(s);
            return 1;
        }
    }
    if ((!(*(unsigned *)(*(char **)(s + 0x110) + 4) & 0x2000) && (s[0x11D] & 1)) || (D_00747A84 & 0x20000)) {
do_call:
        func_002FA350((float *)(s + 0x234));
    } else {
do_add:
        *(float *)(s + 0x234) += 1.0f;
    }
    *(short *)(s + 0x22E) = (int)*(float *)(s + 0x234);
    return 0;
}

// FUNCTION: GAME 0x2FCF88
extern "C" void func_002FCF88(char *s)
{
    if (!(*(unsigned *)(s + 0x11C) & 0x4000000))
        return;
    if ((!(*(unsigned *)(*(char **)(s + 0x110) + 4) & 0x2000) && (*(unsigned *)(s + 0x11C) & 0x100)) || (D_00747A84 & 0x20000))
        func_002FA350((float *)(s + 0x240));
    else
        *(float *)(s + 0x240) += 1.0f;
    if ((signed char)(int)*(float *)(s + 0x240) < *(signed char *)(s + 0x23F))
        return;
    unsigned char c = s[0x244];
    s[0x244] = c + 1;
    *(float *)(s + 0x240) = 0.0f;
    if ((signed char)(c + 1) >= *(signed char *)(s + 0x2A0)) {
        if (*(unsigned *)(s + 0x11C) & 0x2000000)
            s[0x244] = 0;
        else
            s[0x244] = c;
    }
}

extern char *pCamWork;
extern char D_0044F038[], D_0044F058[];
extern "C" void func_002D9F68(void *, const char *, ...);
extern "C" int func_002F3E68(char *);

// FUNCTION: GAME 0x2F3F30
extern "C" int func_002F3F30(char *s)
{
    *(float *)(pCamWork + 0x268) = *(float *)(*(char **)(s + 0x110) + 0x13C);
    *(float *)(pCamWork + 0x26C) = *(float *)(*(char **)(s + 0x110) + 0x140);
    *(float *)(pCamWork + 0x270) = *(float *)(*(char **)(s + 0x110) + 0x144);
    *(float *)(pCamWork + 0x274) = *(float *)(*(char **)(s + 0x110) + 0x148);
    *(float *)(pCamWork + 0x254) = *(float *)(*(char **)(s + 0x110) + 0x14C);
    *(float *)(pCamWork + 0x258) = *(float *)(*(char **)(s + 0x110) + 0x150);
    *(float *)(pCamWork + 0x25C) = *(float *)(*(char **)(s + 0x110) + 0x154);
    *(float *)(pCamWork + 0x260) = *(float *)(*(char **)(s + 0x110) + 0x158);
    char *d = *(char **)(s + 0x110);
    *(float *)(s + 0x2B8) = *(float *)(d + 0x15C) * 1000.0f;
    *(short *)(s + 0x2B0) = (signed char)d[0x18C];
    *(short *)(s + 0x2B2) = (signed char)d[0x18D];
    short a = *(short *)(s + 0x2B0);
    if (a < -1) {
        func_002D9F68(s, D_0044F038, a);
        return 0;
    }
    short b = *(short *)(s + 0x2B2);
    if (b < -1) {
        func_002D9F68(s, D_0044F058, b);
        return 0;
    }
    if (func_002F3E68(s)) {
        if (*(short *)(s + 0x2B0) != -1)
            pCamWork[0x278] = s[0x2B0];
        else
            pCamWork[0x278] = 0;
        if (*(short *)(s + 0x2B2) != -1)
            pCamWork[0x264] = s[0x2B2];
        else
            pCamWork[0x264] = 0;
    }
    return 1;
}

struct V3 {
    float x, y, z;
    V3 &operator=(const V3 &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
};
extern "C" unsigned irand__Fv();

// FUNCTION: GAME 0x2F4EB8
extern "C" int func_002F4EB8(char *s, char *o)
{
    char *d0 = *(char **)(s + 0x110);
    *(short *)(s + 0x2BC) = (signed char)d0[0x18C];
    int r = (signed char)d0[0x18D];
    unsigned ur = r;
    if (r) {
        unsigned m = irand__Fv() % ur;
        unsigned v = *(unsigned short *)(s + 0x2BC) - m;
        *(short *)(s + 0x2BC) = v;
        if ((int)(v << 16) <= 0)
            *(short *)(s + 0x2BC) = 0;
    }
    char *d = *(char **)(s + 0x110);
    s[0x2BE] = d[0x18E];
    *(float *)(s + 0x2B4) = (signed char)d[0x18F] * 0.025f;
    *(float *)(s + 0x2B8) = (signed char)d[0x190] * 0.5f;
    s[0x2E0] = d[0x197];
    if (*(int *)(o + 0x50)) {
        *(int *)(s + 0x2C0) = *(int *)(o + 0x50);
        s[0x2BF] = o[0x4E];
        *(V3 *)(s + 0x2D0) = *(V3 *)(o + 0x60);
    } else {
        int p = *(int *)(s + 0x114);
        if (p && (signed char)d[0xBE] >= 0) {
            *(int *)(s + 0x2C0) = p;
            s[0x2BF] = d[0xBE];
        }
        char *e = *(char **)(s + 0x110);
        *(float *)(s + 0x2D0) = *(float *)(e + 0x13C);
        *(float *)(s + 0x2D4) = *(float *)(e + 0x140);
        *(float *)(s + 0x2D8) = *(float *)(e + 0x144);
    }
    return 1;
}
