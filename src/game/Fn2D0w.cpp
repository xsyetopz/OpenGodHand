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

// FUNCTION: GAME 0x2D9038
extern "C" char *Get_LightData2__11cWorldLightUsUi(char *t, unsigned short id, unsigned k)
{
    char *e = 0;
    int i = 0;
    for (; i < *(int *)(t + 0x78); i++) {
        e = t + 0x80 + i * 0x70;
        if (*(unsigned *)(e + 0x54) == k && *(unsigned short *)(e + 2) == id) break;
    }
    return i == *(int *)(t + 0x78) ? 0 : e;
}

// FUNCTION: GAME 0x2DB5A0
extern "C" void GetViewScrollIdAll__FPUi(unsigned *out)
{
    char **p = *(char ***)(scrArray + 4);
    for (; p != *(char ***)(scrArray + 8); p++) {
        char *o = *p;
        unsigned id = *(unsigned char *)(o + 0x2FD);
        if (id < 0x100 && (*(unsigned *)(o + 0x250) & 2))
            out[id >> 5] |= 0x80000000u >> (id & 0x1F);
    }
}

// FUNCTION: GAME 0x2D93E8
extern "C" unsigned func_002D93E8(char *t)
{
    unsigned id = 0xFFFF;
    int n = *(int *)(t + 0x78);
    int unused;
    do {
        unused = 1;
        for (int i = 0; i < n; i++) {
            if (*(unsigned short *)(t + 0x82 + i * 0x70) == id) { unused = 0; break; }
        }
        if (unused) break;
        id = (id - 1) & 0xFFFF;
    } while (id);
    return id;
}
