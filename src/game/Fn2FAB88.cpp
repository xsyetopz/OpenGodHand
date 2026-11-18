extern char D_0061B7C0[];
extern unsigned D_0071B7C0[], D_0071B840[], D_0071B8C0[];
extern "C" int func_002FACA8(int, int);
extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x2FAB88
extern "C" int func_002FAB88(int id)
{
    for (int i = 0x3FF; i >= 0; i--) {
        char *p = D_0061B7C0 + i * 0x400;
        unsigned bit = 0x80000000u >> (i & 0x1F);
        unsigned w = (unsigned)i >> 5;
        if (!(D_0071B7C0[w] & bit)) {
            memset(p, 0, 0x400);
            int r = func_002FACA8(i, id);
            if (r) {
                D_0071B7C0[w] |= bit;
                D_0071B840[w] &= ~bit;
                D_0071B8C0[w] &= ~bit;
                return r;
            }
        }
    }
    return 0;
}
