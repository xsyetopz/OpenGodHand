extern "C" void setExit__17cActionButtonUnit(void *);
extern "C" void SeStop__4cSnd6eSndId(void *, int);
extern "C" void func_001268F0(void *);
extern "C" void func_001268B0(void *, int);
extern "C" int func_001FC708(void *);
extern "C" void trans__7cIDBase(void *);
extern "C" void func_001468B0(void *);
extern "C" void *initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void *getIDWork__7cIDBasei(void *, int);
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

extern "C" void sceVu0ApplyMatrix(void *, void *, void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x133AA8
// diff: flags sw vs swc1 0x20 order, and final swc1 0x24/0x28 swapped (4 words)
extern "C" void func_00133AA8(char *self)
{
    sceVu0ApplyMatrix(self + 0x60, *(void **)(self + 0x40), self + 0x50);
    float r = *(float *)(self + 0x70);
    float x = *(float *)(self + 0x60);
    float y = *(float *)(self + 0x64);
    float z = *(float *)(self + 0x68);
    *(float *)(self + 0x10) = x - r;
    *(float *)(self + 0x14) = y - r;
    *(float *)(self + 0x18) = z - r;
    *(int *)(self + 8) &= -3;
    *(float *)(self + 0x28) = z + r;
    *(float *)(self + 0x24) = y + r;
    *(float *)(self + 0x20) = x + r;
}
#endif

// FUNCTION: GAME 0x13C220
extern "C" void func_0013C220(char *self)
{
    unsigned short i;
    char *p = self + 0x98;
    *(int *)(self + 0x90) = 0;
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 10);
    i = 0;
    do {
        *(void **)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 4);
}

// FUNCTION: GAME 0x13D048
extern "C" void func_0013D048(char *self)
{
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 6);
    initialize__7cIDBase7eIdData5eIdNo(self + 0x140, 1, 7);
    initialize__7cIDBase7eIdData5eIdNo(self + 0x190, 1, 8);
    initialize__7cIDBase7eIdData5eIdNo(self + 0xA0, 1, 0x1B);
    initialize__7cIDBase7eIdData5eIdNo(self + 0xF0, 1, 0x1C);
}

// FUNCTION: GAME 0x13F118
extern "C" void func_0013F118(char *self)
{
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 0x11);
    *(int *)(self + 0x9C) = 0xFFFF;
}

// FUNCTION: GAME 0x143558
extern "C" void func_00143558(char *self)
{
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 0x13);
    initialize__7cIDBase7eIdData5eIdNo(self + 0xB0, 1, 0x18);
}
