// Slot table updates in 0x1F0000-0x200000.

extern unsigned char D_00747A51;

#ifdef NONMATCHING
// DRAFT: GAME 0x1FB1C0 - 50 differing words: i/off register swap (t2/t3), cvt.w.s lands in f4 not f0, loop slot offsets folded; tried do-while, off hoist, short/int param
extern "C" void func_001FB1C0(char **self, int id, float *pos, float *ang, int a4, unsigned char *a5)
{
    id &= 0xFFFF;
    if (!D_00747A51)
        return;
    char *base = *self;
    if (!base)
        return;
    unsigned short *e = (unsigned short *)(base + 0x28A);
    unsigned short *q = e;
    for (unsigned i = 0; i < 0x80; i++, q += 8, e += 8) {
        int off = i * 16;
        if (*e == 0xFFFF)
            continue;
        if (q[3] == id) {
            q[4] = (short)(pos[0] * 10.0f);
            char *s = (char *)(off + (int)*self + 0x28A);
            *(short *)(s + 0xA) = (short)(pos[1] * 10.0f);
            s = (char *)(off + (int)*self + 0x28A);
            *(short *)(s + 0xC) = (short)(pos[2] * 10.0f);
            s = (char *)(off + (int)*self + 0x28A);
            *(char *)(s + 5) = (char)(ang[1] * 57.295776f * 0.5f);
            *(short *)(off + (int)*self + 0x298) = a4;
            *(unsigned char *)(off + (int)*self + 0x28E) = *a5;
            return;
        }
    }
}
#endif
