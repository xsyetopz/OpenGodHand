// Sys pair-table reset and data search loop at 0x31D1B0.
struct SysT { char _0[0x5AC]; unsigned *p5AC; char _1[0x4C]; unsigned *p5FC; char _2[0]; char c600; };
extern SysT Sys;
struct Pr { int a, b; };
extern Pr D_007558A8[];
extern int D_007559A8[];
extern char D_00450EF0[];
extern char D_00450EF8[];
extern char D_00450F00[];
extern char D_00450F08[];
extern "C" unsigned *SearchData__FPUiPCcUi(unsigned *, const char *, unsigned);
extern "C" void func_0031D658(unsigned *, int);

// FUNCTION: GAME 0x31D1B0
extern "C" void func_0031D1B0(void)
{
    Sys.c600 = 0;
    for (int i = 0x20; i != 0; i--) {
        D_007558A8[i - 1].a = 0;
        D_007558A8[i - 1].b = 0;
        D_007559A8[i - 1] = 0;
    }
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
        if (!q) return;
        func_0031D658(q, f);
    }
}
