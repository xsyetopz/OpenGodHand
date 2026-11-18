extern "C" void setExit__17cActionButtonUnit(void *);
extern "C" void SeStop__4cSnd6eSndId(void *, int);
extern "C" void func_001268F0(void *);
extern "C" void func_001268B0(void *, int);
extern "C" int func_001FC708(void *);
extern "C" void trans__7cIDBase(void *);
extern char Snd[];
extern char CoreSave[];
extern char D_00747A24[];
extern unsigned D_007474A8;

// FUNCTION: GAME 0x126770
extern "C" void func_00126770(char *self)
{
    void *b = *(void **)(self + 0x165C);
    if (b) {
        setExit__17cActionButtonUnit(b);
        *(int *)(self + 0x165C) = 0;
    }
    SeStop__4cSnd6eSndId(Snd, *(int *)(self + 0x161C));
    *(int *)(self + 0x161C) = 0;
    unsigned m = 0xFFBFFFFF;
    unsigned x = *(unsigned *)(Snd + 0xB0);
    unsigned y = *(unsigned *)(Snd + 0xAC);
    x &= m;
    y &= m;
    *(unsigned *)(Snd + 0xB0) = x;
    *(unsigned *)(Snd + 0xAC) = y;
    SeStop__4cSnd6eSndId(Snd, *(int *)(self + 0x1620));
    *(int *)(self + 0x1620) = 0;
}

// FUNCTION: GAME 0x126820
extern "C" void func_00126820(char *self)
{
    unsigned f = D_007474A8;
    if ((f & 0x90) == 0) {
        int n = *(int *)(self + 0x1658);
        if (n) {
            *(int *)(self + 0x1658) = n - 1;
        } else {
            func_001268F0(self);
        }
    } else if (f & 0x10) {
        func_001268F0(self);
        func_001268B0(self, 2);
    } else if (f & 0x80) {
        func_001268B0(self, 1);
    }
}

// FUNCTION: GAME 0x13CF20
extern "C" void func_0013CF20(char *self)
{
    if (*(int *)(self + 0x94)) {
        char *a = *(char **)(self + 0x9C);
        if (a) {
            unsigned long f = *(unsigned *)D_00747A24;
            if (((f >> 3) & 1) == 0) {
                if (*(int *)(D_00747A24 + 8) >= 0) {
                    if (*(short *)(a + 0x548) && (*(unsigned *)(self + 0xA0) & 0x20000000)) {
                        if (func_001FC708(CoreSave) == 0)
                            trans__7cIDBase(self);
                    }
                }
            }
        }
    }
}

// FUNCTION: GAME 0x13EBA0
extern "C" void func_0013EBA0(char *self)
{
    if (*(int *)(self + 0x94)) {
        char *a = *(char **)(self + 0x9C);
        if (a) {
            unsigned long f = *(unsigned *)D_00747A24;
            if (((f >> 3) & 1) == 0) {
                if (*(int *)(D_00747A24 + 8) >= 0) {
                    if (*(short *)(a + 0x548) && (*(unsigned *)(self + 0xA0) & 0x20000000)) {
                        if (func_001FC708(CoreSave) == 0 && (*(unsigned *)(D_00747A24 + 0x60) & 0x80000) == 0)
                            trans__7cIDBase(self);
                    }
                }
            }
        }
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x13F510
// diff: first two prologue insns (lui a1 / addiu v1) swapped
extern "C" void func_0013F510(char *self)
{
    short i;
    int *p;
    for (p = (int *)(self + 0xB8), i = 4; i >= 0; i--) {
        p[0x6A] = 0;
        ((float *)p)[0x86] = 1.0f;
        p[0] = 0;
        p--;
    }
    *(int *)(self + 0xA0) = 0;
    self[0x358] = 0;
    self[0x384] = 0;
}
#endif

static inline int inRange4(int c)
{
    if (c < 4 && c >= 0)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x12BAF0
extern "C" int func_0012BAF0(unsigned char *self)
{
    if (*(unsigned *)(self + 0x15F4) & 0x400)
        return 1;
    if (self[0x2F4] == 0)
        return inRange4(self[0x2F5]);
    return 0;
}
