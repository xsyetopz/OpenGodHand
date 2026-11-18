// Medium functions from 0x180000-0x1C0000.

// FUNCTION: GAME 0x1A7EC0
extern "C" int setGetOnEm__5cOm53Ui(char *s, unsigned a)
{
    unsigned i;
    char *t = s;
    char *b = t + 0x600;
    for (i = 0; i < 16; i++) {
        unsigned x = (unsigned char)t[0x610] + i;
        unsigned f = x < 16;
        unsigned idx = f * x;
        if ((unsigned char)b[idx] == 0xFF) {
            b[idx] = a;
            t[0x612] = (unsigned char)t[0x612] + 1;
            return 1;
        }
    }
    return 0;
}

struct T6 { int v[6]; };
extern T6 D_00427CD8;
extern "C" int Rnd__Fv(void);

// FUNCTION: GAME 0x1ABBE8
extern "C" int func_001ABBE8(char *s, int a)
{
    T6 t;
    if ((*(unsigned *)(s + 0x9D0) & 0x20000000) == 0) {
        t = D_00427CD8;
        if (a != 1)
            return Rnd__Fv() % t.v[a] == 0;
    }
    return 0;
}
