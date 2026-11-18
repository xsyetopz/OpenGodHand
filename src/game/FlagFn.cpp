extern int D_00747A78;
extern int D_00755800;
extern int D_00755804;
extern char *D_00755840;

// FUNCTION: GAME 0x31BDC8
extern "C" void func_0031BDC8(char *self)
{
    unsigned long f = D_00747A78;
    unsigned long b = (f >> 5) & 1;
    if (b) {
        char *dst = self + 0x100;
        int i;
        for (i = 0; i < 32; i++) {
            dst[i] = ((char (*)[32])D_00755840)[D_00755800][i];
        }
        int n = D_00755800 + 1;
        D_00755800 = n;
        if (n >= D_00755804) {
            D_00747A78 = D_00747A78 & ~0x20;
        }
    }
}

extern unsigned D_00747A2C[];
extern unsigned D_00747A88;
extern int D_00747A24;
extern char *SaveLoad;
extern "C" void openLoad__9cSaveLoad(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x160F38 - flag test ok (lw/dsrl/andi); shared return-1 tail, switch/beql layout and D_00747A24 base reg differ
extern "C" int func_00160F38(char *self)
{
    int *g = (int *)D_00747A2C;
    if (!(g[2] & 0x800) && g[3] >= 0) {
        unsigned long f = g[3];
        unsigned long b = (f >> 6) & 1;
        if (!b) {
            short s = *(short *)(self + 0x52);
            switch (s) {
            case 0:
                openLoad__9cSaveLoad(SaveLoad);
                *(unsigned short *)(self + 0x52) = *(unsigned short *)(self + 0x52) + 1;
            case 1:
                if (D_00747A88 & 0x40000000) {
                    return 0;
                }
            default:
                D_00747A24 &= -3;
                *(short *)(self + 0x52) = 0;
            }
        }
    }
    return 1;
}
#endif

extern int D_00747A84[];

// FUNCTION: GAME 0x2BF420
extern "C" void func_002BF420(char *p)
{
    if (D_00747A84[1] >= 0) {
        unsigned long f = D_00747A84[-24];
        unsigned long b = (f >> 6) & 1;
        if (b) {
            p[0] = 4;
            p[3] = 0;
            p[0xC] = 1;
            p[0] = 4;
        } else {
            p[3] = 0;
            p[0] = 5;
        }
        p[2] = 0;
        p[1] = 0;
    }
}

extern int D_00586B34;
extern unsigned char D_0074748C;

// FUNCTION: GAME 0x2967B0
extern "C" int func_002967B0(void)
{
    if (*(int *)D_00747A2C < 0) {
        return 0;
    }
    unsigned long f = D_00586B34;
    unsigned long a = (f >> 1) & 1;
    if (a) {
        return 1;
    }
    unsigned long b = (f >> 2) & 1;
    if (b) {
        return 1;
    }
    unsigned long c = (f >> 3) & 1;
    if (c) {
        return 1;
    }
    return (D_0074748C >> 2) & 1;
}

extern char EventConfig[];
extern "C" void func_00297660(void *);
extern "C" void setEventNo__12cEventConfigi(void *, int);

// FUNCTION: GAME 0x2975F8
extern "C" void initEnv__6cEventi(char *self, int no)
{
    unsigned long f = *(int *)(self + 8);
    unsigned long b = (f >> 1) & 1;
    if (!b) {
        func_00297660(self);
        *(int *)(self + 0x18) = no;
        setEventNo__12cEventConfigi(EventConfig, no);
        *(int *)(self + 8) |= 2;
    }
}

extern "C" int func_001FF638(void *);
extern "C" void func_001FF3A0(void *);

// FUNCTION: GAME 0x1FF338
extern "C" int func_001FF338(char *self)
{
    int n = *(int *)(self + 4);
    if (n < 0) {
        return 0;
    }
    if (n > 0) {
        return 1;
    }
    unsigned long f = *(int *)(self + 8);
    unsigned long b = (f >> 1) & 1;
    if (b) {
        return 0;
    }
    if (!func_001FF638(self)) {
        return 0;
    }
    func_001FF3A0(self);
    return 1;
}

extern char g_EmSet;

// FUNCTION: GAME 0x2C33D8
extern "C" void func_002C33D8(char *self)
{
    g_EmSet = 0;
    void (*fn)() = *(void (**)())(*(char **)(self + 0xD4) + 4);
    if (fn) {
        fn();
    }
    unsigned long f = D_00747A24;
    unsigned long b = (f >> 6) & 1;
    if (b || (f & 0x200)) {
        self[0x14] = 0;
    }
}

extern char Fade[];
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);

// FUNCTION: GAME 0x296738
extern "C" void func_00296738(void)
{
    if (*(int *)D_00747A2C >= 0) {
        unsigned long f = D_00586B34;
        unsigned long a = (f >> 1) & 1;
        if (a) {
            return;
        }
        unsigned long b = (f >> 2) & 1;
        if (b) {
            return;
        }
        unsigned long c = (f >> 3) & 1;
        if (c) {
            return;
        }
        start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, 0, 0xFF000000, 15);
    }
}

extern void *NowLoading;
extern "C" void func_00297128(void *);
extern "C" int func_00297AA8(void *);
extern "C" void Set_bg_mode__FUiUcUcUc(unsigned, unsigned char, unsigned char, unsigned char);
extern "C" void executeTask__11cNowLoading(void *);
extern "C" void startReleaseObj__6cEvent(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x297038 - 47 words differ: flag tests give beqz+nop where the original has bnel; case layout differs
extern "C" void func_00297038(char *self)
{
    int fl = *(int *)(self + 8);
    unsigned long f = fl;
    unsigned long b = (f >> 7) & 1;
    if (b && (fl & 0x100)) {
        goto body;
    }
    func_00297128(self);
    return;
body:
    switch (self[5]) {
    case 0: {
        unsigned long g = D_00586B34;
        unsigned long h = (g >> 6) & 1;
        if (!h) {
            start__9classFADEUiUiUiUiUiUi(Fade, 0, 8, 0, 0xFF000000, 0xFF000000, 0);
            Set_bg_mode__FUiUcUcUc(1, 0, 0, 0);
            executeTask__11cNowLoading(NowLoading);
        }
        startReleaseObj__6cEvent(self);
        self[5] = (unsigned char)self[5] + 1;
        break;
    }
    case 8:
        if (func_00297AA8(self)) {
            func_00297128(self);
        }
        break;
    default:
        self[5] = (unsigned char)self[5] + 1;
        break;
    }
}
#endif
