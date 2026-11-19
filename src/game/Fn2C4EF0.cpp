extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern "C" void exit__9cTaskWork(void *);
extern "C" void deleteAll__8cMessage(void *);
extern "C" void func_002CA6B0(void *);
extern "C" void func_00306140();
extern "C" void taskExec__9cScenarioPvT1i(void *, int, int, int);
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
struct FadeS {
    char _p[0x1C];
    unsigned char busy;
};
extern FadeS Fade;
extern char Snd[];
extern void *Message;
extern char *g_Sce;
extern int D_00747A84;
extern unsigned D_00747A8C[];
#define GS(o, T) (*(T *)(g_Sce + (o)))

// FUNCTION: GAME 0x2C4EF0
extern "C" void func_002C4EF0()
{
    if (Fade.busy != 0) {
        do {
            sleep__9cTaskWorkUs(GS(0x20, void *), 1);
        } while (Fade.busy != 0);
    }
    int i = GS(0x109, signed char);
    if (i >= 0) {
        if (i < 0x40)
            D_00747A8C[(unsigned)i >> 5] |= 0x80000000u >> (i & 0x1F);
    }
    deleteAll__8cMessage(Message);
    func_002CA6B0(Snd);
    func_00306140();
    if (GS(0xFC, int) != 0)
        taskExec__9cScenarioPvT1i(g_Sce, GS(0xFC, int), GS(0x100, int), GS(0x10C, int));
    if (GS(0x110, unsigned char) != 0)
        start__9classFADEUiUiUiUiUiUi(&Fade, 0, 8, 0, 0xFF000000, 0, 0xF);
    D_00747A84 &= ~0x10;
    exit__9cTaskWork(GS(0x20, void *));
}
