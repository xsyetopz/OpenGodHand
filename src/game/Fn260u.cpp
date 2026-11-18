// Small units in 0x260000-0x270000.

extern unsigned short D_00747A50;
extern char D_005864F0[];
extern "C" char *func_00292DC8(void *, int, float);
extern "C" int func_00294A68(void *);
extern "C" void func_0026E988(void *, int, int, int, float);

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
