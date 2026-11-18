struct SysT { char p0[0x10]; int f10; char p1[0x18C]; long a; char p2[8]; long b; char p3[0x3D0]; unsigned f588; };
extern SysT Sys;
extern char Snd[];
extern "C" void func_001F6A80(char *);
extern "C" void func_001F6AF8(char *);
extern "C" void SeCall__4cSnd6eSeBlksssUii(char *, int, int, int, int, int, int);

// FUNCTION: GAME 0x1F6520
extern "C" void func_001F6520(char *self)
{
    if (Sys.a & 0x30000000L) {
        self[0] = 2;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x160, -1, -1, 0, 0);
    } else {
        long f = Sys.b;
        if (f & 0x2000000L) {
            self[1] = 1;
            *(int *)(self + 0x20) = 0;
            self[2] = 0;
            self[3] = 0;
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
        } else if (f & 0x1000000L) {
            *(int *)(self + 0x20) = 5;
            self[1] = 1;
            self[2] = 0;
            self[3] = 0;
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
        } else if (f & 0x1000000000L) {
            func_001F6A80(self);
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
        } else if (f & 0x10000000000L) {
            func_001F6AF8(self);
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
        }
    }
}

extern unsigned D_00747A24[];
extern char Dvd[], RoomHeap[], D_0042C000[];
extern char *IDManager, **IDSys;
extern "C" int getLocalFileName__10cIDManagerPcT1Sc(char *, char *, char *, signed char);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(char *, char *, void **, char *, int, unsigned, unsigned, unsigned);
extern "C" void CheckWait__4cDvd6eDvdId(char *, int);
extern "C" void setIDData__10cIDManager7eIdDataPUi(char *, int, unsigned *);
extern "C" int initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" int setPackedMessData__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void func_001F6A80(char *);

// FUNCTION: GAME 0x1F5A98
extern "C" int func_001F5A98(char *self)
{
    char name[0x40];
    getLocalFileName__10cIDManagerPcT1Sc(IDManager, name, D_0042C000, -1);
    char *id = self + 0x30;
    int r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, name, (void **)(self + 0x80), RoomHeap, 0, 0, 0, 0);
    CheckWait__4cDvd6eDvdId(Dvd, r);
    setIDData__10cIDManager7eIdDataPUi(*IDSys, 0x1E, *(unsigned **)(self + 0x80));
    if (!initialize__7cIDBase7eIdData5eIdNo(id, 0x1E, 0))
        return 0;
    if (!setPackedMessData__7cIDBase7eIdData5eIdNo(id, 0x1E, 1))
        return 0;
    Sys.f10 = 1;
    *(int *)(self + 0x24) = -2;
    *(int *)(self + 8) = 10;
    self[4] = 0;
    *(int *)(self + 0xC) = 1;
    *(int *)(self + 0x20) = 0;
    self[5] = 0;
    if (Sys.f588 & 0x8000000)
        *(int *)(self + 0x10) = 1;
    else
        *(int *)(self + 0x10) = 0;
    if (D_00747A24[1] & 0x4000000)
        *(int *)(self + 0x14) = 1;
    else
        *(int *)(self + 0x14) = 0;
    if (D_00747A24[1] & 0x2000000)
        *(int *)(self + 0x18) = 1;
    else
        *(int *)(self + 0x18) = 0;
    if (D_00747A24[1] & 0x1000000)
        *(int *)(self + 0x1C) = 1;
    else
        *(int *)(self + 0x1C) = 0;
    func_001F6A80(self);
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    return 1;
}

extern "C" void func_001F4778(char *, int, int);
// FUNCTION: GAME 0x1F4928
extern "C" void func_001F4928(char *self, int on)
{
    func_001F4778(self, 0x50, 0);
    func_001F4778(self, 0x51, 0);
    func_001F4778(self, 0x52, 0);
    func_001F4778(self, 0x53, 0);
    func_001F4778(self, 0x54, 0);
    func_001F4778(self, 0x55, 0);
    func_001F4778(self, 0x56, 0);
    func_001F4778(self, 0x57, 0);
    func_001F4778(self, 0x58, 0);
    func_001F4778(self, 0x59, 0);
    func_001F4778(self, 0x5A, 0);
    func_001F4778(self, 0x5B, 0);
    func_001F4778(self, 0x5C, 0);
    func_001F4778(self, 0x5D, 0);
    func_001F4778(self, 0x5E, 0);
    func_001F4778(self, 0x5F, 0);
    func_001F4778(self, 0x60, 0);
    if (on) {
        func_001F4778(self, 0x50, 1);
        func_001F4778(self, 0x51, 1);
        func_001F4778(self, 0x52, 1);
        func_001F4778(self, 0x53, 1);
        func_001F4778(self, 0x54, 1);
        func_001F4778(self, 0x55, 1);
        func_001F4778(self, 0x56, 1);
        func_001F4778(self, 0x57, 1);
        func_001F4778(self, 0x58, 1);
        func_001F4778(self, 0x59, 1);
        func_001F4778(self, 0x5A, 1);
        func_001F4778(self, 0x5B, 1);
        func_001F4778(self, 0x5C, 1);
        func_001F4778(self, 0x5D, 1);
        func_001F4778(self, 0x5E, 1);
        func_001F4778(self, 0x5F, 1);
        func_001F4778(self, 0x60, 1);
    }
}

extern "C" void SetNumber__12CustomIDWorki(char *, int);
extern "C" void SetMessNo__12CustomIDWorki(char *, int);

// FUNCTION: GAME 0x1F50A0
extern "C" void func_001F50A0(char *self, unsigned short id, int t, int c)
{
    if (id < 7) {
        int a = id * 3 + 0x2D;
        int b = id * 3 + 0x2E;
        int d = id * 3 + 0x2F;
        func_001F4778(self, a, 0);
        int e = id + 0x68;
        func_001F4778(self, b, 0);
        func_001F4778(self, d, 0);
        func_001F4778(self, e, 0);
        if (t) {
            int mn = t / 60;
            int sc = t % 60;
            int o = id * 0x174;
            SetNumber__12CustomIDWorki(self + (o + 0x162C), mn);
            SetNumber__12CustomIDWorki(self + (o + 0x16A8), sc);
            func_001F4778(self, a, c);
            func_001F4778(self, b, c);
            func_001F4778(self, d, c);
        } else {
            SetMessNo__12CustomIDWorki(self + (id * 0x7C + 0x32C0), 0x102B);
            func_001F4778(self, e, c);
        }
    }
}

struct GameT { char pad[0x1B0]; short f1B0; };
extern GameT Game;
extern char Fade[];
extern char *g_Sce;
extern unsigned D_00747A78[];
extern "C" void Set_bg_mode__FUiUcUcUc(unsigned, unsigned char, unsigned char, unsigned char);
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern "C" char *Getplayer__Fv();
extern "C" void reset__4pl00(char *);
extern "C" void func_001F6B78(char *, int);
extern "C" void func_001F6C40(char *, int);
extern "C" int func_001F5A98(char *);
extern "C" void func_001F5E90(char *);
extern "C" void func_001F5C48(char *);
extern "C" void func_002D14F8(char *, float);
extern "C" void kill__9classFADE(void *);

// FUNCTION: GAME 0x1F5CC0
extern "C" void Execute__7JukeBox(char *self)
{
    unsigned col = D_00747A78[13];
    D_00747A78[0] |= 0x4000;
    Set_bg_mode__FUiUcUcUc(1, 0, 0, 0);
    Game.f1B0 = 0x1E;
    start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, 0, 0xFF000000, 15);
    sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 15);
    reset__4pl00(Getplayer__Fv());
    func_001F6B78(self, 1);
    func_001F6C40(self, 1);
    if (func_001F5A98(self) && !*(unsigned char *)(self + 4)) {
        while (!*(unsigned char *)(self + 4)) {
            func_001F5E90(self);
            sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 1);
        }
    }
    func_001F5C48(self);
    Game.f1B0 = 0x1E;
    func_002D14F8(Snd, 20.0f);
    func_001F6B78(self, 0);
    start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, 0xFF000000, 0, 15);
    sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 15);
    kill__9classFADE(Fade);
    Set_bg_mode__FUiUcUcUc(1, col & 0xFF, (col >> 8) & 0xFF, (col >> 16) & 0xFF);
    func_001F6C40(self, 0);
}
