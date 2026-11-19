// Small unnamed helpers in 0x2A0000-0x2AFFFF, written as extern "C" free functions over raw offsets.
#include "game/cGameObjFn.h"

extern "C" {

void *memset(void *, int, unsigned);
void func_002AE940(void *, int);
// FUNCTION: GAME 0x2ACCD8
void func_002ACCD8(void *p) { memset(p, 0, 0x100); }
// FUNCTION: GAME 0x2AE970
void func_002AE970() { func_002AE940((void *)1, 0xFFFF); }
// FUNCTION: GAME 0x2AF6E0
void func_002AF6E0(int *p, int on) { if (on) *p |= 2; else *p &= -3; }

extern char Mc;
// FUNCTION: GAME 0x2AD288
void func_002AD288(int *self, int f) { self[4] = 0; self[5] = 0; if (f & 1) func_0030F5A0(); }
// FUNCTION: GAME 0x2AE940
void func_002AE940(void *a, int b) { if (b == 0xFFFF && a) func_002AE3D0(&Mc); }
// FUNCTION: GAME 0x2A4FA0
void func_002A4FA0(char *self)
{
    char *b = self + 0x28000;
    int v = *(int *)(b + 0x2054);
    *(int *)(b + 0x205C) = 5;
    v = (v + 15) & 0xFFFFFFF0u;
    *(int *)(b + 0x2054) = v;
    *(int *)(b + 0x2050) = v;
}
// FUNCTION: GAME 0x2A9648
char *func_002A9648(void *, char *p, unsigned n)
{
    char *h = p - 0x20;
    n += 0x20;
    if (*(unsigned *)(h + 0x10) >= n) {
        unsigned r = *(unsigned *)(h + 0x10) - n;
        *(unsigned *)(h + 0x10) = n;
        *(unsigned *)(h + 0xC) += r;
        return p;
    }
    return 0;
}
extern char Game, g_CollScr, D_005CB020, D_005CB300, Snd, D_00460D50, D_0044AF10, D_0044ADD8, Sys, GlobalTask;
extern char *g_SaveManager;
extern unsigned D_00747A84[];
void func_0012E5C8(void *);
void __8cIDParam(void *) __asm__("__8cIDParam");
void func_00309000(void *);
void stageClear__12cSaveManager(void *);
void func_002CABE0(void *);
void func_0031EEC8(void *, void *);
void func_002AFC48(float, float, void *, int, int, int, int, int);
int SearchData__FPUiPCcUi(void *, const char *, unsigned);
void execute__12cTaskManagerRFv_vi(void *, void (*)(void *), void *);
void func_002AE788(void *);
void *func_002A5AD0(char *);
// FUNCTION: GAME 0x2A72C8
void func_002A72C8(int a, int b) { if (b == 0xFFFF && a) { func_002A5AD0(&Game); func_0012E5C8(&g_CollScr); } }
// FUNCTION: GAME 0x2ACBE8
void func_002ACBE8(int a, int b) { if (b == 0xFFFF && a) { __8cIDParam(&D_005CB020); func_00309000(&D_005CB300); } }
// FUNCTION: GAME 0x2A5D40
void func_002A5D40(char *self) { stageClear__12cSaveManager(g_SaveManager); func_002CABE0(&Snd); *self = 3; }
// FUNCTION: GAME 0x2A9D60
void *func_002A9D60() { if (*(int *)&D_00460D50 == 0) func_0031EEC8(&D_00460D50, &D_0044AF10); return &D_00460D50; }
// FUNCTION: GAME 0x2AE740
void func_002AE740(int a) { D_00747A84[1] |= 0x80000000u; execute__12cTaskManagerRFv_vi(&GlobalTask, func_002AE788, (void *)a); }
// FUNCTION: GAME 0x2A71B0
void func_002A71B0() { char *s = &Sys; *(int *)(s + 0x608) = SearchData__FPUiPCcUi(*(void **)(s + 0x5AC), &D_0044ADD8, 0); }
#ifdef NONMATCHING
// 5 words differ: register allocation (original keeps object ptr in v1, short in a0)
// DRAFT: GAME 0x2ABCE8
void func_002ABCE8(char *a, char *o)
{
    char *p = *(char **)(o + 0x1C);
    short s = *(short *)(p + 0x1B0);
    *(short *)(o + 0xA4) = 0;
    unsigned char c = s < 2;
    if (*(char *)(p + 0x5E) == 0 && c) { *(int *)(o + 0x2C) |= 0x1000; return; }
    *(int *)(o + 0x2C) &= -0x1001;
}
#endif
#ifdef NONMATCHING
// 2 words differ: original loads the two floats via a0 instead of the v0 copy; tried float temps, int*/float* views, hoisted diff, callee int/char decl, char* alias for diff, (int)self cast for diff, int-indexed diff (no change); batch: void *self, int self, char-array indexing, floatidx, void-int callee decl (each 2 words)
// DRAFT: GAME 0x2AFC08
void func_002AFC08(char *self, int t0)
{
    func_002AFC48(*(float *)(self + 0x88), *(float *)(self + 0x8C), self, *(int *)(self + 4), *(int *)(self + 0x64), *(int *)(self + 0x68), t0, *(int *)(self + 0x1C) - *(int *)(self + 0x6C));
}
#endif

}
