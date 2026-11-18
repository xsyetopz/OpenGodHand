extern "C" float func_002AC650(int, short, int, char *);

// FUNCTION: GAME 0x2AC298
extern "C" void func_002AC298(int a, char *self)
{
    char *t = *(char **)(self + 0x1C);
    unsigned f = *(unsigned *)(t + 4);
    unsigned g;
    if (!(f & 0x400000))
        return;
    g = *(unsigned *)(self + 0x2C);
    if (g & 0x800)
        return;
    if (*(char *)(t + 0x5F) != 0)
        return;
    {
        unsigned c = f & 0x20000;
        short n = *(short *)(t + 0x214);
        int m = n - 1;
        short lim = *(short *)((int)t + m * 12 + 0x220);
        if (!c) {
            if (lim < *(unsigned short *)(self + 0xA4)) {
                *(unsigned *)(self + 0x2C) = g | 0x800;
                return;
            }
        } else if (lim < *(unsigned short *)(self + 0xA4)) {
            *(unsigned short *)(self + 0xA4) = 0;
        }
        float r = func_002AC650(a, *(short *)(self + 0xA4), n, *(char **)(self + 0xC));
        *(float *)(self + 0x48) = r * 360.0f;
        unsigned long h = *(unsigned *)(self + 0x2C);
        if ((h >> 5 & 1) == 0)
            *(unsigned short *)(self + 0xA6) = *(unsigned short *)(self + 0xA6) + 1;
    }
}
