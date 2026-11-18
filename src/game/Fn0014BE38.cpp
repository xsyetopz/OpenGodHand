// Fn0014BE38: flag-based priority selection.
extern int D_00747AA8;

// FUNCTION: GAME 0x0014BE38
extern "C" int func_0014BE38(char *a, char *b) {
    int r = (*(unsigned *)(a + 0x250) & 0x2000) ? 0x14 : 2;
    if (*(unsigned *)(b + 0x380) & 0x20000000) {
        float f = *(float *)(a + 0x24C) * ((float)*(unsigned char *)(a + 0x2B6) / 255.0f)
                  * ((float)*(unsigned char *)(a + 0x2B7) / 255.0f)
                  * ((float)*(unsigned char *)(a + 0x2BC) / 255.0f);
        if (f == 1.0f) r = 0x1E;
    }
    if (*(unsigned *)(b + 0x380) & 0x40000000) {
        if (D_00747AA8) r = 0x20;
    }
    return r;
}
