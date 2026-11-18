// Small functions from 0x2D0000-0x2E0000.
extern char *scrArray;
extern "C" char *func_002D22B0();
extern "C" int func_002CCA78(char *);

// FUNCTION: GAME 0x2D1DD0
extern "C" int func_002D1DD0()
{
    char *r = func_002D22B0();
    if (r) {
        int v = func_002CCA78(r);
        if (v == 0) return 0;
    }
    return 1;
}

// FUNCTION: GAME 0x2DB318
extern "C" void setAlphaScrollLayer__FUif(unsigned layer, float a)
{
    char **p = *(char ***)(scrArray + 4);
    for (; p != *(char ***)(scrArray + 8); p++) {
        char *o = *p;
        if (layer == *(unsigned char *)(o + 0x2FD)) {
            *(float *)(o + 0x24C) = a;
            *(float *)(*p + 0x31C) = a;
        }
    }
}
