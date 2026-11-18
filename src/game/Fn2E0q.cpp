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
