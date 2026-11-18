extern "C" void *memset(void *, int, unsigned);
extern "C" void func_002BEDC8(char **, unsigned);

#ifdef NONMATCHING
// DRAFT: GAME 0x2BEDE8 - 22 words: i/off register swap (a3/t0), first three cvt.w.s use f3 not f0, first store folded to 0xC(v1); tried float return/r var (worse), pointer copy, do-while
extern "C" void func_002BEDE8(char **self, unsigned n, char *src0)
{
    memset(*self + 0xC, 0, 0x600);
    func_002BEDC8(self, n);
    unsigned i = 0;
    if (n) {
        char *src = src0;
        int off = 0;
        do {
            char *b = *self + off;
            char *d = b + 0xC;
            *(short *)(d + 0) = (short)(*(float *)(src + 0) * 20.0f);
            *(short *)(d + 2) = (short)(*(float *)(src + 4) * 20.0f);
            *(short *)(d + 4) = (short)(*(float *)(src + 8) * 20.0f);
            i++;
            off += 0x18;
            *(short *)(d + 6) = (short)(*(float *)(src + 0x14) * 57.295776f);
            *(int *)(d + 8) = *(int *)(src + 0x20);
            *(int *)(d + 0xC) = *(int *)(src + 0x24);
            *(unsigned char *)(d + 0x10) = *(unsigned char *)(src + 0x28);
            *(unsigned char *)(d + 0x11) = *(unsigned char *)(src + 0x29);
            *(unsigned char *)(d + 0x12) = *(unsigned char *)(src + 0x2A);
            unsigned char t = *(unsigned char *)(src + 0x2B);
            src += 0x40;
            *(unsigned char *)(d + 0x13) = t;
        } while (i < n);
    }
}
#endif
