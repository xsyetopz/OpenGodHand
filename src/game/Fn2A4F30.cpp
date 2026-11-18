// Advances a cursor inside a double-buffered region; returns the old cursor.
extern unsigned D_007476B0;

// FUNCTION: GAME 0x2A4F30
extern "C" unsigned func_002A4F30(char *self, unsigned n)
{
    char *b = self + 0x28000;
    unsigned cur = *(unsigned *)(b + 0x2054);
    unsigned lim = *(unsigned *)(b + 0x2058);
    unsigned nx = cur + n;
    if (nx < lim)
        *(unsigned *)(b + 0x2054) = nx;
    else {
        *(unsigned *)(b + 0x2054) = lim;
        return 0;
    }
    unsigned d = nx - (unsigned)(self + ((D_007476B0 & 1) * 0x15000 + 0x50));
    if (*(unsigned *)(b + 0x208C) < d)
        *(unsigned *)(b + 0x208C) = d;
    return cur;
}
