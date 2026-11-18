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

struct O;
extern "C" int getMeshNum__C6cModel(void *);
extern "C" O *getMeshPtr__6cModeli(void *, int);
extern "C" void func_00155D60(O *, int, int);
// FUNCTION: GAME 0x14E778
extern "C" void func_0014E778(void *self, int a)
{
    int n = getMeshNum__C6cModel(self);
    int i;
    for (i = 0; i < n; i++) {
        O *o = getMeshPtr__6cModeli(self, i);
        func_00155D60(o, a, 0);
        func_00155D60(o, a, 1);
    }
}
