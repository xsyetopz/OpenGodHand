// Jump-table unit; this file holds no other .rodata.
extern char *g_Sce;
extern char Sys[];

#define P(a, b) \
    do { \
        *(float *)(*(char **)(self + 0x80) + 0x38) = (a); \
        *(float *)(*(char **)(self + 0x80) + 0x3C) = (b); \
        return; \
    } while (0)

#ifdef NONMATCHING
// 21-word near-miss (decl order and lo+(hi<<4) reorder tried, no gain;best 16 words: temp e8 pointer, but hi/v regs then shift t0->t1; split 0x2013 add via temp b gives 19): self and clamped value swap a3/a2, and gcc folds 0x2013 onto lo before the shift add
// DRAFT: GAME 0x162B18
extern "C" void func_00162B18(char *self)
{
    unsigned v, hi, lo;
    if (*(unsigned char *)(g_Sce + 0x14)) {
        hi = (unsigned char)Sys[0x5B7];
        lo = (unsigned char)Sys[0x5B6];
    } else {
        hi = (unsigned char)Sys[0x5B1];
        lo = (unsigned char)Sys[0x5B0];
    }
    if (hi)
        v = (hi << 4) + 0x2013 + lo;
    else
        v = 0x20A3;
    if (v > 0x20A3)
        v = 0x20A3;
    *(unsigned short *)(*(char **)(self + 0xE4) + 0x90) = v;
    *(unsigned short *)(*(char **)(self + 0xE8) + 0x90) = v;
    switch (hi) {
    case 0: P(254.0f, 289.0f);
    case 1: P(102.0f, 266.0f);
    case 2: P(167.0f, 195.0f);
    case 3: P(134.0f, 92.0f);
    case 4: P(235.0f, 126.0f);
    case 5: P(320.0f, 190.0f);
    case 6: P(320.0f, 88.0f);
    case 7: P(408.0f, 88.0f);
    case 8: P(455.0f, 47.0f);
    }
}
#endif
