extern unsigned D_00747A2C[];
extern int D_00747A24;

extern "C" int func_001FF0D8(void *);

struct FEl {
    char pad[8];
    int flags;
    char pad2[0x50];
};

// FUNCTION: GAME 0x1FEEA0
extern "C" int func_001FEEA0(char *self)
{
    int i = 0;
    for (; i < *(int *)(self + 4); i++) {
        if (func_001FF0D8(&(*(FEl **)(self + 8))[i])) {
            continue;
        }
        unsigned long f = (*(FEl **)(self + 8))[i].flags;
        unsigned long b = (f >> 2) & 1;
        if (b) {
            continue;
        }
        return i;
    }
    return -1;
}

extern int D_00747A78;

// FUNCTION: GAME 0x2D9C10
extern "C" void func_002D9C10(int *cnt)
{
    char *g = (char *)&D_00747A78;
    if (D_00747A78 & 0x2000) {
        return;
    }
    unsigned long f = *(int *)(g - 0x54);
    unsigned long b = (f >> 3) & 1;
    if (b) {
        return;
    }
    int w = *(int *)(g + 0xC);
    if (w & 0x2000000) {
        return;
    }
    g -= 0x5D8;
    if (*(unsigned short *)(g + 0x5B0) == 0x21) {
        return;
    }
    if (*(int *)(g + 0x594) & 0x800) {
        if (w & 0x8000000) {
            return;
        }
    }
    if (*(unsigned char *)(g + 0x569) == 1) {
        if ((*(int *)(g + 0x210) & 1) == 0) {
            return;
        }
    }
    *cnt = *cnt + 1;
}

// FUNCTION: GAME 0x2D9CA8
extern "C" void func_002D9CA8(int *cnt)
{
    char *g = (char *)&D_00747A78;
    if (D_00747A78 & 0x2000) {
        return;
    }
    unsigned long f = *(int *)(g - 0x54);
    unsigned long b = (f >> 3) & 1;
    if (b) {
        return;
    }
    int w = *(int *)(g + 0xC);
    if (w & 0x2000000) {
        return;
    }
    g -= 0x5D8;
    if (*(unsigned short *)(g + 0x5B0) == 0x21) {
        return;
    }
    if (*(int *)(g + 0x594) & 0x800) {
        if (w & 0x8000000) {
            return;
        }
    }
    if (*(unsigned char *)(g + 0x569) == 1) {
        if ((*(int *)(g + 0x210) & 1) == 0) {
            return;
        }
    }
    cnt[1] = cnt[1] + 1;
}

extern char CoreSave[];
extern "C" int func_001FC708(void *);
extern "C" void trans__7cIDBase(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x140638 - 27 words differ: self lands in s1 not s2; 0x80000000 mask test folds to bgezl
extern "C" void func_00140638(char *self)
{
    if (*(int *)(self + 0xA0) == 0) {
        return;
    }
    int *g = &D_00747A24;
    unsigned long f = g[0];
    unsigned long b = (f >> 3) & 1;
    if (b) {
        return;
    }
    if (g[2] < 0) {
        return;
    }
    unsigned m = 0x80000000;
    if ((*(unsigned *)(self + 0x90) & m) == 0) {
        return;
    }
    if (func_001FC708(CoreSave)) {
        return;
    }
    if (*(unsigned char *)(self + 0x358) != 0 && *(int *)(self + 0x35C) != 0) {
        unsigned short i = 0;
        char *tbl = self + 0x35C;
        do {
            trans__7cIDBase(*(void **)(tbl + (i << 2)));
            i++;
        } while (i < *(unsigned char *)(self + 0x358) && *(int *)(tbl + (i << 2)) != 0);
    }
    trans__7cIDBase(self);
}
#endif

extern int D_00586B34;
extern char Fade[];
extern "C" void initEnv__6cEventi(void *, int);
extern "C" char *Getplayer__Fv();
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern int D_00747A84;

// FUNCTION: GAME 0x296458
extern "C" void playStart__6cEventi(char *self, int no)
{
    initEnv__6cEventi(self, no);
    D_00747A84 = D_00747A84 | 0x20000000;
    self[0x34] = 0;
    *(int *)(self + 8) |= 1;
    char *pl = Getplayer__Fv();
    float *src = *(float **)(pl + 0xF0);
    float *dst = (float *)(self + 0x20);
    float z;
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    z = *(float *)(pl + 0x104);
    *(float *)(self + 0x30) = z;
    *(float *)(pl + 0x54C) = 60.0f;
    self[4] = 0;
    self[5] = 0;
    self[6] = 0;
    self[7] = 0;
    unsigned long f = D_00586B34;
    unsigned long b = (f >> 3) & 1;
    if (b) {
        start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, 0xFF000000, 0xFF000000, 0);
    }
}

extern char *g_Sce;
extern char Dvd[];
extern char D_0044A890[];
extern "C" int func_002962A8(int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" int FileExist__4cDvdPCc(void *, const char *);
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern "C" void startSoftEvent__9cScenario14eSoftEventType(void *, int);
extern "C" void endSoftEvent__9cScenario(void *);

// FUNCTION: GAME 0x296370
extern "C" void playStartWait__6cEventi(char *self, int no)
{
    char buf[0x20];
    int id = func_002962A8(no);
    sprintf(buf, D_0044A890, id);
    if (FileExist__4cDvdPCc(Dvd, buf)) {
        unsigned long f = D_00747A84;
        unsigned long b = (f >> 4) & 1;
        while (b) {
            sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 1);
            f = D_00747A84;
            b = (f >> 4) & 1;
        }
        startSoftEvent__9cScenario14eSoftEventType(g_Sce, 4);
        playStart__6cEventi(self, id);
        while (*(int *)(self + 8) & 1) {
            sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 1);
        }
        endSoftEvent__9cScenario(g_Sce);
    }
}

extern char Sys[];
extern char WorldTime[];
extern char D_0042C7D0[];
extern "C" void getGlobalHMS__10cWorldTimePUiN21(void *, unsigned *, unsigned *, unsigned *);
extern "C" void setEnding__3cE3b(void *, int);
extern "C" void debugPrint__9cScenarioPCce(void *, const char *, ...);
