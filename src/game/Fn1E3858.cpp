extern "C" void displayScrollLayer__FUib(unsigned int, bool);
extern int D_003BE130[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1E3858
// 12 words differ: gcc hoists nor/andi/sltiu above the 0x8000 branch and picks other temps; tried short/int/unsigned v, a inside the if, empty-if vs inverted compare, (int)base+(q<<2)
extern "C" void func_001E3858(char *self) {
    unsigned short *p = (unsigned short *)(self + 0x49C);
    int *q = D_003BE130;
    char *base = self + 0x400;
    int n = 2;
    do {
        int v = *p;
        n--;
        int a = v + 1;
        if (v & 0x8000) {
            *p = a;
            int w = ((~a & 0x4000) | 0x8000) & 0xFFFF;
            if ((unsigned)(a & 0x3FFF) < 11) {
            } else {
                *p = w;
                if (w & 0x4000)
                    displayScrollLayer__FUib(*(unsigned int *)((int)base + (*q << 2)), 1);
                else
                    displayScrollLayer__FUib(*(unsigned int *)((int)base + (*q << 2)), 0);
            }
        }
        q++;
        p++;
    } while (n >= 0);
}
#endif
