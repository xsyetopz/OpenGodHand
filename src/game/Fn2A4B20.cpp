// Span length from a packed table entry.
extern int D_00747A0C;

// FUNCTION: GAME 0x2A4B20
extern "C" short func_002A4B20(char *self, unsigned id)
{
    unsigned short k = id;
    if (k == 0)
        return D_00747A0C == 0 ? 8 : 4;
    char *e = self + (k >> 12) * 16;
    unsigned w = *(unsigned *)(*(char **)(e + 4) + (k & 0xFFF) * 4 + 8);
    return ((w >> 20) & 0x3F) - ((w >> 8) & 0x3F) + 1;
}
