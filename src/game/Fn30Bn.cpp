// Larger unnamed units in 0x30B000-0x31C000.
extern "C" int printf(const char *, ...);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_00299348(void *);
extern "C" void func_0031A338(void *);
extern "C" void func_00306D10();
extern "C" void func_0030CF10();
extern "C" void func_003077B0(void *);
extern "C" void func_0015FD98(void *);
extern "C" void systemInit__9cCoreSave(void *);
extern "C" void systemInit__9cRoomSave(void *);
extern "C" void func_0031C348();
extern "C" void func_00201AD0(void *);
extern "C" void func_002B6598(int);
extern "C" void execute__12cTaskManagerRFv_vi(void *, void (*)(), int);
extern "C" void func_0030D358();
extern "C" void func_002A5998();
extern "C" void func_0030D5C8();
extern char D_00450518[];
extern char D_00450530[];
extern char D_00747A4C[];
extern char cFilter_tag[];
extern char D_00754C80[];
extern char Fade[];
extern char *SubScr;
extern char CoreSave[];
extern char g_RoomSave[];
extern char g_E3[];
extern char GlobalTask[];
extern int NowLoading;

// FUNCTION: GAME 0x30B728
extern "C" void func_0030B728()
{
    printf(D_00450518);
    char *a = D_00747A4C;
    memset(a, 0, 0x68);
    char *s = a - 0x5AC;
    *(short *)(s + 0x5B0) = 0x20;
    *(float *)(s + 0x574) = 1.0f;
    func_00299348(cFilter_tag);
    func_0031A338(D_00754C80);
    func_00306D10();
    func_0030CF10();
    func_003077B0(Fade);
    func_0015FD98(SubScr);
    systemInit__9cCoreSave(CoreSave);
    systemInit__9cRoomSave(g_RoomSave);
    func_0031C348();
    if (*(unsigned *)(s + 0x594) & 0x800)
        func_00201AD0(g_E3);
    printf(D_00450530);
    if (!(*(unsigned *)(s + 0x584) & 0x80000)) {
        execute__12cTaskManagerRFv_vi(GlobalTask, func_0030D358, 3);
    } else {
        char *t = GlobalTask;
        execute__12cTaskManagerRFv_vi(t, func_002A5998, 0);
        execute__12cTaskManagerRFv_vi(t, func_0030D5C8, 3);
    }
    func_002B6598(NowLoading);
}

extern unsigned D_00754250[];
extern int D_003C3D08;
extern unsigned D_003C3D10[];
extern "C" void func_0030F2B0(unsigned);

// FUNCTION: GAME 0x30F348
extern "C" unsigned func_0030F348()
{
    unsigned y;
    int kk;
    if (D_003C3D08 >= 624) {
        if (D_003C3D08 == 625)
            func_0030F2B0(5489);
        for (kk = 0; kk < 227; kk++) {
            y = (D_00754250[kk] & 0x80000000u) | (D_00754250[kk + 1] & 0x7FFFFFFFu);
            D_00754250[kk] = D_00754250[kk + 397] ^ (y >> 1) ^ D_003C3D10[y & 1];
        }
        for (; kk < 623; kk++) {
            y = (D_00754250[kk] & 0x80000000u) | (D_00754250[kk + 1] & 0x7FFFFFFFu);
            D_00754250[kk] = D_00754250[kk - 227] ^ (y >> 1) ^ D_003C3D10[y & 1];
        }
        y = (D_00754250[623] & 0x80000000u) | (D_00754250[0] & 0x7FFFFFFFu);
        D_00754250[623] = D_00754250[396] ^ (y >> 1) ^ D_003C3D10[y & 1];
        D_003C3D08 = 0;
    }
    y = D_00754250[D_003C3D08++];
    y ^= y >> 11;
    y ^= (y << 7) & 0x9D2C5680u;
    y ^= (y << 15) & 0xEFC60000u;
    y ^= y >> 18;
    return y;
}
