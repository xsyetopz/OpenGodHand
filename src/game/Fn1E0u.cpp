// God Hand: small functions in 0x1E0000-0x1F0000
extern "C" void displayScrollLayer__FUib(unsigned, int);
// FUNCTION: GAME 0x1E44A8
extern "C" void func_001E44A8(char *self)
{
    unsigned v = *(unsigned short *)(self + 0x4C0);
    if (v & 0x8000) {
        v++;
        *(unsigned short *)(self + 0x4C0) = v;
        if ((v & 0x3FFF) >= 8) {
            unsigned w = (~v & 0x4000) | (v & 0x800) | 0x8000;
            *(unsigned short *)(self + 0x4C0) = w;
            if (w & 0x4000) displayScrollLayer__FUib(*(unsigned *)(self + 0x480), 1);
            else displayScrollLayer__FUib(*(unsigned *)(self + 0x480), 0);
        }
    }
}

struct T5 { int a[5]; };
extern T5 D_0042BDD8;
extern "C" void SetLocalPosY__12CustomIDWorki(char *, int);
// FUNCTION: GAME 0x1EE6C8
extern "C" void func_001EE6C8(char *self, unsigned short i)
{
    if (i < 5) {
        T5 t = D_0042BDD8;
        SetLocalPosY__12CustomIDWorki(self + 0xDF0, t.a[i]);
    }
}

// FUNCTION: GAME 0x1E9078
extern "C" float func_001E9078(char **self)
{
    char *p = *self;
    if (!p) return 0.0f;
    float a = *(float *)(p + 0x100) * 57.2957763671875f;
    if (a < 0.0f) a += 360.0f;
    a += 0.01f;
    if (a >= 360.0f) a -= 360.0f;
    return a;
}
