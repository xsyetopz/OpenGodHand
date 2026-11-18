// Unnamed units in 0x2B0000-0x2C0000 (block copy, state reset).
struct BlkQ { int b[0x2F]; };
extern BlkQ D_005E7910;
extern "C" void func_002B21F0(char *, int);

// FUNCTION: GAME 0x2B2080
extern "C" void func_002B2080(BlkQ *d)
{
    *d = D_005E7910;
}

// DRAFT: GAME 0x2B42F0
// diff: 30 words, flag word is 64-bit (lw/dsrl) in the original; ours sign-extends the masked store (dsll32/dsra32) and lays the arms out differently
#ifdef NONMATCHING
extern "C" void func_002B42F0(char *self)
{
    long fl = *(int *)(self + 0x14);
    unsigned long bit = ((unsigned long)fl >> 6) & 1;
    int nf = fl & -9;
    *(int *)(self + 0x14) = nf;
    if (!bit) {
        unsigned short *p = *(unsigned short **)(self + 0x8C);
        unsigned hi = *p & 0xFF00;
        if (hi == 0x8000) {
            self[0xF] = 0;
            self[0xC] = 7;
        } else if (hi == 0x9000) {
            func_002B21F0(self, p[1]);
            self[0xF] = 0;
            self[0xC] = 0;
        } else {
            self[0xF] = 0;
            self[0xC] = 0;
        }
    } else {
        self[0xF] = 0;
        self[0xC] = 7;
    }
    self[0xD] = 0;
    self[0xE] = 0;
}
#endif

extern "C" void func_002D42E0(char *);
extern unsigned D_00747A84;

// FUNCTION: GAME 0x2B4DA8
extern "C" void func_002B4DA8(char **self)
{
    int a = 0;
    int b = 0;
    for (int n = 2; n >= 0; n--) {
        char *base = *self;
        unsigned char ok = *(int *)(base + a) != 0;
        if (ok) {
            func_002D42E0(base + b);
            b += 0xAC;
        } else {
            b += 0xAC;
        }
        a += 0xAC;
    }
    D_00747A84 &= ~0x2000u;
}
