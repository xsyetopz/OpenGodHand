// Small effect-event and bit-set units in 0x2E0000-0x300000.
extern unsigned char EspSys[];
extern char D_0061B7C0[], D_0061B280[];
extern unsigned D_0071B840[];
extern "C" void effDataRegist__6espSys12eEffDataTypePv(void *, int, void *);
extern "C" void effDataRelease__6espSys12eEffDataType(void *, int);
extern "C" void KillEventEsp__Fv();
extern "C" void KillEventEmitter__Fv();
extern "C" void sstClearSetFlag__6espSys(void *);
extern "C" void func_00305C20(void *);
extern "C" void *memset(void *, int, unsigned);
extern unsigned D_0071B7C0[], D_0071B8C0[];
extern "C" int func_00306030(void *, int, int);

// FUNCTION: GAME 0x2FA0B0
extern "C" void EffEventDataRegist__FPv(void *p)
{
    if (p) {
        EspSys[0x41C] = 1;
        effDataRegist__6espSys12eEffDataTypePv(EspSys, 6, p);
    }
}

// FUNCTION: GAME 0x2FA0E8
extern "C" void EffEventDataRelease__Fv()
{
    if (EspSys[0x41C] == 1) {
        EspSys[0x41C] = 0;
        effDataRelease__6espSys12eEffDataType(EspSys, 6);
    }
}

// FUNCTION: GAME 0x2FA128
extern "C" int EffEventIsCutDataExist__FUi(unsigned a)
{
    return func_00306030(EspSys, 6, a + 1) != 0;
}

// FUNCTION: GAME 0x2FB020
extern "C" void PushEsp__FP7espWork(char *p)
{
    unsigned d = p - D_0061B7C0;
    D_0071B840[d >> 15] |= 0x80000000u >> ((d >> 10) & 0x1F);
}

// FUNCTION: GAME 0x2E13D8
extern "C" void Moji_size_set__FUcUc(unsigned char a, unsigned char b)
{
    if (a && b) {
        D_0061B280[8] = a;
        D_0061B280[9] = b;
    } else {
        D_0061B280[8] = 8;
        D_0061B280[9] = 8;
    }
}

// FUNCTION: GAME 0x2FA310
extern "C" void EffectEventEndProc__Fv()
{
    KillEventEsp__Fv();
    KillEventEmitter__Fv();
    sstClearSetFlag__6espSys(EspSys);
    func_00305C20(EspSys);
}

// FUNCTION: GAME 0x2FAA20
extern "C" void InitEspWork__Fv()
{
    memset(D_0061B7C0, 0, 0x100000);
    memset(D_0071B7C0, 0, 0x80);
    memset(D_0071B840, 0, 0x80);
    memset(D_0071B8C0, 0, 0x80);
}
