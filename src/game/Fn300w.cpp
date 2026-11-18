// Small units in 0x300000-0x308000 (emitter slots, effect data lookup, effect system reset).
extern char D_0071B940[], D_00741940[], D_00741960[], D_00741980[];
extern char EspSys[];
extern char D_00743250[];

extern "C" void func_00302918(void *);
extern "C" void func_003039E8(void *, const void *, int);
extern "C" void func_00305A18(void *);

// FUNCTION: GAME 0x300830
void EmitterAllKill(void)
{
    for (int i = 0; i < 0x100; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_00741940)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741960)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741980)[(unsigned)i >> 5] & m))
            func_00302918(D_0071B940 + i * 0x260);
    }
}

// FUNCTION: GAME 0x3009F8
extern "C" void func_003009F8(const void *o, int id)
{
    for (int i = 0; i < 0x100; i++) {
        unsigned m = 0x80000000u >> (i & 0x1F);
        if ((((unsigned *)D_00741940)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741960)[(unsigned)i >> 5] & m) &&
            !(((unsigned *)D_00741980)[(unsigned)i >> 5] & m))
            func_003039E8(D_0071B940 + i * 0x260, o, id);
    }
}

// FUNCTION: GAME 0x302930
extern "C" void func_00302930(char *s, unsigned short a, int mode)
{
    if (*(unsigned short *)(s + 0x224) == 0) {
        *(unsigned short *)(s + 0x224) = a;
        return;
    }
    int t = (int)*(float *)(s + 0x228);
    int d = *(unsigned short *)(s + 0x224) - (unsigned short)t;
    if (mode != 1) {
        if (mode != 0 || !(d < a))
            return;
    }
    *(unsigned short *)(s + 0x224) = a + t;
}

enum eEffDataType { T0 };
enum eIdData { I0, I1 };
class cIDManager {
public:
    char *getTexAddr(eIdData, unsigned);
};
extern cIDManager *IDManager;
extern "C" int *func_003058D8(void *, eEffDataType);
class espSys {
public:
    char *getEffT32Addr(eEffDataType t, int i);
};

// FUNCTION: GAME 0x3060B0
char *espSys::getEffT32Addr(eEffDataType t, int i)
{
    if ((int)t == 0x48)
        return IDManager->getTexAddr(I1, i);
    int *e = func_003058D8(this, t);
    if (!e)
        return 0;
    int *tab = (int *)e[2];
    if (!tab)
        return 0;
    if (i >= tab[0])
        return 0;
    int off = tab[1 + i];
    return off ? (char *)(off + (int)tab) : 0;
}

// FUNCTION: GAME 0x307140
extern "C" void func_00307140(int a, int b)
{
    if (b == 0xFFFF && a) {
        func_00305A18(EspSys);
        char *p = D_00743250;
        p += 0x380;
        for (int i = 999; i != -1; i--) {
            __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(p) : "memory");
            p += 0x10;
        }
    }
}
