extern unsigned D_00747A84;
extern char Fade[];
extern char *g_Sce;
extern "C" void start__9classFADEUiUiUiUiUiUi(char *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void taskExec__9cScenarioRFv_vi(char *, void (*)(), int);
extern "C" void kill__9cTaskWork(char *);
extern "C" void func_002C4EF0();
// DRAFT: GAME 0x2C4E18 - 1 word differs: bit-4 test is sra, original dsrl; tried unsigned long/long f, (long) casts, u=f copies (scoped, after load, global), %2, 1UL mask, != 0 (40+ words or same 1 word)
#ifdef NONMATCHING
extern "C" int func_002C4E18(char *self)
{
    int f = D_00747A84;
    if (f & 0x20000000) return 0;
    if (((unsigned long)f >> 4) & 1) return 1;
    if (*(unsigned char *)(self + 0x108) == 0) return 0;
    if ((*(unsigned long *)((char *)&D_00747A84 - 0x444) & 0x800000) == 0) return 0;
    D_00747A84 = f | 0x10;
    start__9classFADEUiUiUiUiUiUi(Fade, 0, 8, 0, 0, 0xFF000000, 0xF);
    taskExec__9cScenarioRFv_vi(self, func_002C4EF0, 0);
    kill__9cTaskWork(*(char **)(g_Sce + 0x1C) + *(int *)(g_Sce + 0x10C) * 0x58);
    *(unsigned char *)(self + 0x108) = 0;
    return 1;
}
#endif
