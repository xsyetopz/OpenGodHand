// Command-list helpers for cActionButton in 0x1F7900-0x1F8000 (raw offsets, extern "C").
extern "C" int *func_001F7798(char *self);
extern "C" void func_001F7800(char *base, int idx, void *node);
extern "C" int func_002CCB58(char *self);
extern "C" int func_002D0770(void *p);
extern "C" int func_002CD398(char *self);
extern "C" void func_00373810(char *self, int m);
extern "C" void func_00373858(char *self, int m);
extern "C" int func_00373A58(char *self);
extern "C" void func_002CD4A8(char *self, float f);
extern "C" void func_002CD470(char *self, float f);
extern char D_005685B0;
extern char D_00568650;
extern char D_005686A0;
extern char Snd[];
extern "C" void func_0030D258(void);
extern "C" void func_0030ECF8(int a);
extern "C" void func_0015B0A0(void);
extern "C" void func_0031CEB8(void);
extern "C" void *memset(void *p, int c, unsigned int n);
extern "C" void func_002BDFF8(void *self, int m);
extern "C" void func_0030CB30(void);
extern "C" void func_003951F8(int a, int b, int c, int d);
extern "C" void func_00395398(int a);
extern "C" void func_00395F68(void (*fn)(void));
extern "C" void func_0030B148(void);
extern "C" void func_0030D1F8(void);
extern "C" void func_001FF858(void *a, void *b);
extern "C" void func_002BE6E8(void *self);
extern char Sys[];
extern char g_ps2[];
extern char RelSys[];
extern char D_00747A2C[];
extern char D_00580D40[];
extern char D_004504D8[];
extern int D_003C3CCC;
extern int D_00752D3C;

#ifdef NONMATCHING
// DRAFT: GAME 0x1F7900
// Variant C: header word read before the null test, separate early return.
extern "C" char *setCommandList__13cActionButton12eScePriorityRC7cMatrixP12COMMAND_LISTUi(char *self, int prio, void *mtx, unsigned char *list, unsigned count)
{
    char *n = (char *)func_001F7798(self);
    unsigned w = *(unsigned *)n;
    if (!n) {
        return 0;
    }
    unsigned i = 0;
    *(char **)(n + 0x38) = &D_005685B0;
    *(char **)(n + 0x3C) = &D_00568650;
    *(char **)(n + 0x40) = &D_005686A0;
    *(unsigned *)n = w | 1;
    *(int *)(n + 0x1C) = 0x32;
    *(int *)(n + 0x24) = 3;
    *(void **)(n + 0x28) = mtx;
    *(int *)(n + 0x10) = 0;
    *(int *)(n + 0x14) = 0;
    *(int *)(n + 0x18) = prio;
    n[0x35] = 0;
    *(short *)(n + 0x30) = 0;
    n[0x34] = (unsigned char)count;
    if (count) {
        unsigned char *e = list;
        do {
            *(unsigned *)(*(char **)(n + 0x38) + (i << 2)) = *(unsigned *)e;
            *(unsigned short *)(*(char **)(n + 0x3C) + (i << 1)) = *(unsigned short *)(e + 4);
            *(unsigned char *)(*(char **)(n + 0x40) + i) = *(unsigned char *)(e + 8);
            e += 12;
            i++;
        } while (i < count);
    }
    func_001F7800(self, prio, n);
    return n;
}
#endif

// FUNCTION: GAME 0x2CCBF8
// Switch on unkB0 as m2c shows: case 0 falls into case 1, case 2 polls func_00373A58.
extern "C" void func_002CCBF8(char *self)
{
    func_002CCB58(self);
    int st = *(int *)(self + 0xB0);
    switch (st) {
    case 0:
        if (*(int *)(self + 0xBC) == *(int *)(self + 0xAC) && (func_002D0770(Snd) & *(int *)(self + 0x9C)) && !(*(int *)(self + 0x98) & 0x1FF00) && func_002CD398(self) != 0) {
            func_00373810(self, 8);
            *(int *)(self + 0xB0) = 1;
        } else {
            return;
        }
        /* fall through */
    case 1:
        if (*(int *)(self + 0xBC) != *(int *)(self + 0xAC) || !(func_002D0770(Snd) & *(int *)(self + 0x9C))) {
            func_002CD4A8(self, 0.0f);
            *(int *)(self + 0xB4) = 0x3C;
            *(int *)(self + 0xB0) = 2;
        }
        break;
    case 2:
        if (func_00373A58(self) == 1) {
            int v = *(int *)(self + 0xB4);
            if (v == 0) {
                func_00373858(self, 8);
                *(int *)(self + 0xB0) = 0;
            } else {
                *(int *)(self + 0xB4) = v - 1;
            }
        }
        if ((func_002D0770(Snd) & *(int *)(self + 0x9C)) && *(int *)(self + 0xBC) == *(int *)(self + 0xAC)) {
            func_002CD470(self, 60.0f);
            *(int *)(self + 0xB4) = 0;
            *(int *)(self + 0xB0) = 1;
        }
        break;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x308A38
// m2c structure: scrArray loop clears bit 0 of +0x380 over mesh chain (+0x404),
// objbaseArray loop clears bit 1 of +0x5A0 when +0x2FE halfword is in hide ranges.
extern "C" char *getMeshPtr__6cModeli(void *, int);
extern "C" char *scrArray;
extern "C" char *objbaseArray;

extern "C" void ResetHiddenModels__12HideModelMgr(void)
{
    unsigned s = *(unsigned *)(scrArray + 4);
    if (s < *(unsigned *)(scrArray + 8)) {
        do {
            char *m = getMeshPtr__6cModeli((void *)*(int *)s, 0);
            if (m != 0) {
                do {
                    *(int *)(m + 0x380) &= ~1;
                    m = *(char **)(m + 0x404);
                } while (m != 0);
            }
            s += 4;
        } while (s < *(unsigned *)(scrArray + 8));
    }
    unsigned a = *(unsigned *)(objbaseArray + 4);
    if (a < *(unsigned *)(objbaseArray + 8)) {
        do {
            char *o = *(char **)a;
            int t = *(unsigned short *)(o + 0x2FE);
            unsigned char hide = 0;
            if (t >= 0x100 && t < 0x1FF) {
                hide = 1;
            } else if (t >= 0x200 && t < 0x300) {
                hide = 1;
            } else if (t >= 0x300 && t < 0x500) {
                hide = 1;
            } else if (t >= 0x500 && t < 0x600) {
                hide = 1;
            }
            if (hide) {
                *(int *)(o + 0x5A0) &= ~2;
            }
            a += 4;
        } while (a < *(unsigned *)(objbaseArray + 8));
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x30B298
// Variant A: Sys accessed through a local base pointer; global block as raw offsets from D_00747A2C.
extern "C" void func_0030B298(void)
{
    char *sys = Sys;
    func_0030D258();
    func_0030ECF8(0);
    func_0015B0A0();
    func_0031CEB8();
    memset(sys, 0, 0x620);
    int a1 = *(int *)(sys + 0x59C) & 0xFFEFFFFF;
    *(int *)(sys + 0x56C) = 1;
    *(int *)(sys + 0x578) = 0;
    *(int *)(sys + 0x59C) = a1;
    if ((*(int *)(sys + 0x598) & 0x200000) && !(a1 & 0x1000000)) {
        *(int *)(sys + 0x584) |= 0x200;
    } else {
        *(short *)(sys + 0x5B0) = 0x20;
    }
    char *g = D_00747A2C;
    if (*(int *)(g + 8) & 0x800) {
        *(int *)(g - 0x20) = 1;
    }
    char *t = g - 0x58C;
    *(int *)(t + 0x57C) = 0;
    *(int *)(t + 0x580) = 0;
    if ((*(int *)(t + 0x578) ^ 1) != 0) {
        D_003C3CCC = 0x40;
    } else {
        D_003C3CCC = 0x50;
    }
    func_002BDFF8(g_ps2, a1);
    func_0030CB30();
    if (*(int *)(sys + 0x578) == 1) {
        func_003951F8(0, 1, 3, 0);
        func_00395398(0);
    }
    func_00395F68(func_0030B148);
    func_0030D1F8();
    func_001FF858(D_00580D40, D_004504D8);
    *(unsigned char *)(sys + 0x569) = 2;
    D_00752D3C = 0;
    func_002BE6E8(RelSys);
}
#endif
