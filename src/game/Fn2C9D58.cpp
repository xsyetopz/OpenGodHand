extern char g_ps2[];
extern char D_0044CD20[], D_0044CD40[], D_0044CD60[], D_0044CD80[], D_0044CDA0[], D_0044CDA8[], D_0044CDC8[];
extern "C" int func_002BE240(char *, char *, int, char *);
extern "C" void func_00375318(void);
extern "C" void func_003A11F8(void);

// FUNCTION: GAME 0x2C9D58
extern "C" void func_002C9D58(void)
{
    while (func_002BE240(g_ps2, D_0044CD20, 0, 0) < 0) {}
    while (func_002BE240(g_ps2, D_0044CD40, 0, 0) < 0) {}
    while (func_002BE240(g_ps2, D_0044CD60, 0, 0) < 0) {}
    while (func_002BE240(g_ps2, D_0044CD80, 7, D_0044CDA0) < 0) {}
    func_00375318();
    func_003A11F8();
    while (func_002BE240(g_ps2, D_0044CDA8, 0x13, D_0044CDC8) < 0) {}
}
