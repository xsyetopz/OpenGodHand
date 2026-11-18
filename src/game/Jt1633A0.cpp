// Jump-table unit; this file holds no other .rodata.
extern char *g_Sce;
extern unsigned char D_00747A51;
extern unsigned char D_00747A57;

#define P(a, b) \
    do { \
        *(float *)(*(char **)(self + 0x80) + 0x38) = (a); \
        *(float *)(*(char **)(self + 0x80) + 0x3C) = (b); \
        return; \
    } while (0)

// FUNCTION: GAME 0x1633A0
extern "C" void func_001633A0(char *self)
{
    unsigned sel = *(unsigned char *)(g_Sce + 0x14) ? D_00747A57 : D_00747A51;
    switch (sel) {
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
