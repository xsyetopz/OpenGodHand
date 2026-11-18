extern int D_00747AA8;

// FUNCTION: GAME 0x14BEF8
extern "C" unsigned char func_0014BEF8(char *self, char *other)
{
    unsigned char r = *(unsigned char *)(self + 0x2BE);
    if (r != 0xFE)
        return r;
    int f = *(int *)(other + 0x380);
    unsigned char v = 0xE;
    if (!(f & 0x1000000))
        v = 0xA;
    if (*(int *)(self + 0x250) & 0x2000)
        v = 0x14;
    if (f & 0x20000000) {
        float a = *(float *)(self + 0x24C) * ((float)*(unsigned char *)(self + 0x2B6) / 255.0f)
            * ((float)*(unsigned char *)(self + 0x2B7) / 255.0f)
            * ((float)*(unsigned char *)(self + 0x2BC) / 255.0f);
        if (a == 1.0f)
            v = 0x1E;
    }
    if (*(int *)(*(char **)(other + 0x414) + 0x34) & 0x200000) {
        if (D_00747AA8 != 0)
            v = 0x22;
    }
    return v;
}
