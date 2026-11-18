extern "C" float func_002AC650(int, short, int, char *);

// FUNCTION: GAME 0x2AC1C0
extern "C" void func_002AC1C0(int a, char *self)
{
    char *t = *(char **)(self + 0x1C);
    unsigned f = *(unsigned *)(t + 4);
    unsigned g;
    if (!(f & 0x800000))
        return;
    g = *(unsigned *)(self + 0x2C);
    if (g & 0x1000)
        return;
    if (*(char *)(t + 0x5E) != 0)
        return;
    {
        unsigned c = f & 0x40000;
        short n = *(short *)(t + 0x1B0);
        int m = n - 1;
        short lim = *(short *)((int)t + m * 12 + 0x1BC);
        if (!c) {
            if (lim < *(unsigned short *)(self + 0xA4)) {
                *(unsigned *)(self + 0x2C) = g | 0x1000;
                return;
            }
        } else if (lim < *(unsigned short *)(self + 0xA4)) {
            *(unsigned short *)(self + 0xA4) = 0;
        }
        float r = func_002AC650(a, *(short *)(self + 0xA4), n, *(char **)(self + 8));
        *(float *)(self + 0x40) = r;
        *(float *)(self + 0x44) = r;
        unsigned long h = *(unsigned *)(self + 0x2C);
        if ((h >> 5 & 1) == 0)
            *(unsigned short *)(self + 0xA4) = *(unsigned short *)(self + 0xA4) + 1;
    }
}
