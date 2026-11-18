// Small units in 0x140000-0x150000.

// FUNCTION: GAME 0x148200
extern "C" void func_00148200(float *m, float a, float b)
{
    m[15] = 0;
    m[0] = 1.0f;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 1.0f;
    m[6] = 0;
    m[7] = 0;
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[9] = b;
    m[10] = 1.0f;
    m[8] = a;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x14E778 - 4 words off: prologue move order (a0 to s4 before a1 to s2)
struct O;
extern "C" int func_0014B638(void);
extern "C" O *func_0014B6F8(O *, int);
extern "C" void func_00155D60(O *, int, int);
extern "C" void func_0014E778(O *self, int a)
{
    int n = func_0014B638();
    int i;
    for (i = 0; i < n; i++) {
        O *o = func_0014B6F8(self, i);
        func_00155D60(o, a, 0);
        func_00155D60(o, a, 1);
    }
}
#endif
