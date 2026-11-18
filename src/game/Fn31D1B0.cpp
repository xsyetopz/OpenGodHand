// Sys pair-table reset and data search loop at 0x31D1B0.
struct SysT { char _0[0x5AC]; unsigned *p5AC; char _1[0x4C]; unsigned *p5FC; char _2[0]; char c600; };
extern SysT Sys;
extern int D_007558A8[];
extern int D_007559A8[];
extern char D_00450EF0[];
extern char D_00450EF8[];
extern char D_00450F00[];
extern char D_00450F08[];
extern "C" unsigned *SearchData__FPUiPCcUi(unsigned *, const char *, unsigned);
extern "C" void func_0031D658(unsigned *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x31D1B0
extern "C" void func_0031D1B0(void)
{
    Sys.c600 = 0;
    int *v = D_007559A8 + 0x1F;
    int *a = D_007558A8 + 0x3F;
    int n = 0x20;
    do {
        a[-1] = 0;
        n--;
        a[0] = 0;
        *v = 0;
        a -= 2;
        v--;
    } while (n);
    int f = 1;
    unsigned *d = SearchData__FPUiPCcUi(Sys.p5AC, D_00450EF0, 0);
    unsigned *p = SearchData__FPUiPCcUi(d, D_00450EF8, 0);
    Sys.p5FC = p;
    if (!p) {
        f = 0;
        Sys.p5FC = SearchData__FPUiPCcUi(d, D_00450F00, 0);
    }
    for (int i = 0;; i++) {
        unsigned *q = SearchData__FPUiPCcUi(d, D_00450F08, i);
        if (!q) break;
        func_0031D658(q, f);
    }
}
#endif
