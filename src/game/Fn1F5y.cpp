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
