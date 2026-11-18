struct Ord5 { int a[5]; };
extern const Ord5 D_0042BAF0;
extern "C" void displayScrollLayer__FUib(unsigned, int);

// FUNCTION: GAME 0x1E6ED8
extern "C" void func_001E6ED8(char *self, int a1, int a2)
{
    unsigned sel = (unsigned char)self[0x3D8];
    Ord5 o = D_0042BAF0;
    int v = sel << 11;
    *(unsigned short *)(self + 0x3E8) = v;
    if (a2)
        *(unsigned short *)(self + 0x3E8) = v | 0x8000;
    int i = 0;
    int t;
    if (a1) {
        t = (int)(self + 0x3A0);
        int *p = o.a;
        *(unsigned short *)(self + 0x3E8) |= 0x4000;
        do {
            int idx = *p++;
            displayScrollLayer__FUib(*(unsigned *)(t + (idx << 2)), i == (unsigned char)self[0x3D8]);
            i++;
        } while (i < 5);
    } else {
        t = (int)(self + 0x3A0);
        int n = 4;
        int *p = o.a;
        do {
            int idx = *p++;
            displayScrollLayer__FUib(*(unsigned *)(t + (idx << 2)), 0);
        } while (--n >= 0);
    }
}
