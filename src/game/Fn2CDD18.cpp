// Unnamed unit at 0x2CDD18.
extern "C" int func_002CDA38(void *);
extern "C" int func_002CDFF0(void *, short, short, int, int);
extern "C" void sceVu0CopyVector(float *, float *);

struct Fn2CDObj {
    char _p0[0x10];
    int m_10;
    char _p14[0x38 - 0x14];
    char *m_38;
    char *m_3C;
    float m_40;
    float m_44;
    int m_48;
    float m_4C;
};

// FUNCTION: GAME 0x2CDD18
extern "C" int func_002CDD18(Fn2CDObj *self, short a, short b, char *p, char *q, int c, int d)
{
    if (func_002CDA38(self) == 1) return 0;
    self->m_38 = p;
    self->m_3C = q;
    if (p == 0) {
        self->m_10 = 0;
        self->m_4C = 1.0f;
        *(int *)&self->m_40 = 0;
        self->m_44 = 0.0f;
        self->m_48 = 0;
    } else {
        self->m_10 = 2;
        if (q == 0)
            sceVu0CopyVector(&self->m_40, *(float **)(p + 0xF0));
        else
            sceVu0CopyVector(&self->m_40, *(float **)(q + 0xF0));
        self->m_44 = self->m_44 + 1.3f;
    }
    return func_002CDFF0(self, a, b, c, d);
}
