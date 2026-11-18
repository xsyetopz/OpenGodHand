extern const float V0001[];

static inline void cp(float *d)
{
    int i = 3;
    const float *s = V0001;
    do { *d++ = *s++; } while (--i != -1);
}

// FUNCTION: GAME 0x2A9DF8
extern "C" void func_002A9DF8(char *p)
{
    *(int *)(p + 0) = 0;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = 0;
    *(int *)(p + 0xC) = 0;
    p[0x18] = 0;
    p[0x19] = 0;
    *(short *)(p + 0x1A) = 0;
    p[0x1C] = 0;
    p[0x1D] = 0;
    p[0x1E] = 0;
    cp((float *)(p + 0x20));
    cp((float *)(p + 0x30));
    *(short *)(p + 0x44) = 0x80;
    *(float *)(p + 0x40) = 0.01f;
    p[0x46] = 6;
}
