// Per-mode update of a sound object; sole switch of 0x2CC628.
struct SndFlt {
    char _pad[0x6C];
    float v;
};
extern SndFlt Snd;
extern "C" int func_002CC568(void *);
extern "C" int func_00373A50(void *);
extern "C" int func_00373B30(void *);
extern "C" void func_003739A0(void *, int, float);
extern "C" void func_002CCBF8(void *);
extern "C" void func_002CCD80(void *);
extern "C" void func_002CD1D0(void *);
extern "C" void func_002CD310(void *);
extern "C" void func_00372CB0(void *);

// FUNCTION: GAME 0x2CC628
extern "C" void func_002CC628(char *self)
{
    if (!func_002CC568(self))
        return;
    if (func_00373A50(self) == 1) {
        for (int i = 0; i < func_00373B30(self); i++)
            func_003739A0(self, 0, Snd.v);
    }
    switch (*(unsigned *)(self + 0x94)) {
    case 1:
    case 5:
        func_002CD1D0(self);
        break;
    case 2:
        func_002CCD80(self);
        break;
    case 3:
        func_002CCBF8(self);
        break;
    case 4:
        func_002CD310(self);
    case 0:
    default:
        break;
    }
    *(unsigned *)(self + 0x98) &= 0xFFFFFFFB;
    func_00372CB0(self);
}
