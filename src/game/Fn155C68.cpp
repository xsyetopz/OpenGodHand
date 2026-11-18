extern unsigned int D_004A5D80[][2];

static inline void put(unsigned long *p, int i)
{
    *p = ((unsigned long)((D_004A5D80[i][1] | 0x30000000) & 0xFFFFFFFF)) | ((unsigned long)(D_004A5D80[i][0] & 0x0FFFFFFF) << 32);
}

// FUNCTION: GAME 0x155C68
extern "C" void func_00155C68(unsigned long *a, unsigned long *b, int n)
{
    int m = n;
    if (m >= 0) {
        m &= 0xFF;
        put(a, m);
        put(b, m + 1);
        return;
    }
    *a = 0x10000000;
    m &= 0xFF;
    put(b, m + 1);
}
