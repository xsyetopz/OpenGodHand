extern "C" void func_001B6FB8(void *);
extern "C" void func_001B6E90(void *);
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" void setRiseWaitTime__5cOm53Ui(void *, unsigned);
extern "C" void setDownPos__5cOm53f(void *, float);
extern char CoreSave[];
extern const float D_00428000[];
extern const char D_004275C8[];

// FUNCTION: GAME 0x001A7820
extern "C" int func_001A7820(char *self)
{
    func_001B6FB8(self);
    *(unsigned *)(self + 0x5A0) |= 1;
    setRiseWaitTime__5cOm53Ui(self, 0x1C2);
    setDownPos__5cOm53f(self, 0.0f);
    *(char *)(self + 0x613) = 0;
    *(unsigned *)(self + 0x5B8) |= 8;
    return 1;
}

// FUNCTION: GAME 0x001AE6A0
extern "C" float func_001AE6A0(char *self)
{
    int lv = getGameLevel__9cCoreSave(CoreSave);
    if (lv > 5)
        lv = 5;
    return D_00428000[lv] * *(float *)(self + 0x5A8);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x001AE630
// diff: 3 words, second v in v1 instead of a0
extern "C" int func_001AE630(char *self)
{
    int n = 0;
    int *p = *(int **)(self + 0x604);
    int v;
    if (p && (v = p[0x9D0 / 4]) >= 0) {
        if (v & 0x40000000)
            return 1;
    } else
        n = 1;
    p = *(int **)(self + 0x608);
    if (p) {
        int w = p[0x9D0 / 4];
        if (w < 0)
            n++;
        else if (w & 0x40000000)
            return 1;
    } else
        n++;
    return n >= 2;
}
#endif

// FUNCTION: GAME 0x001A7788
extern "C" void *func_001A7788(char *self)
{
    func_001B6E90(self);
    *(const char **)(self + 0x214) = D_004275C8;
    unsigned char *p = (unsigned char *)(self + 0x600);
    unsigned i = 0;
    do {
        p[i] = 0xFF;
        i++;
    } while (i < 0x10);
    self[0x611] = 0;
    self[0x610] = 0;
    self[0x612] = 0;
    self[0x615] = 0;
    self[0x614] = 0;
    return self;
}
