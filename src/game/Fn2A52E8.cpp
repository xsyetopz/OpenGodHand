extern "C" long *func_002A4F30(char *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x2A52E8
// 32 differing words; byte-pack scheduling differs (compiled shifts hi first); variants: long/unsigned char temps, split long vars
extern "C" void func_002A52E8(char *self, unsigned c)
{
    long *p = func_002A4F30(self, 0x30);
    if (p) {
        float one = 1.0f;
        long v = (long)(c & 0xFF) | ((long)((c >> 8) & 0xFF) << 8) | ((long)((c >> 16) & 0xFF) << 16) | ((long)((c >> 24) & 0xFF) << 24) | ((long)*(int *)&one << 32);
        p[0] = 0x10000002;
        p[5] = 1;
        ((int *)p)[2] = 0x11000000;
        ((int *)p)[3] = 0x50000002;
        p[2] = (0x8000L << 45) | 0x8001;
        p[3] = 0xE;
        p[4] = v;
    }
}
#endif
