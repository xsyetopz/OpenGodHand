extern char g_ActBtn[];
extern "C" void func_001DFD90();
extern "C" void set__13cActionButton12eScePriority8eActType11eActBtnTypePvT(char *, int, int, int, void *, void *, int);

// FUNCTION: GAME 0x1DFD50
extern "C" void SetActBtn__5Slot1(char *self)
{
    set__13cActionButton12eScePriority8eActType11eActBtnTypePvT(g_ActBtn, 4, 0x15, 0, (void *)func_001DFD90, self, 0);
}

extern char CamManager[];
extern "C" void setSubScrCamera__11cCamManagerUc(char *, unsigned char);

// FUNCTION: GAME 0x1DBD50
extern "C" void SetPokerCamera__5PokerG4cVecT1(char *self, float *a, float *b)
{
    setSubScrCamera__11cCamManagerUc(CamManager, 0);
    char *c = CamManager;
    *(char **)(self + 0x304C) = c + 0xC90;
    float *d = (float *)(c + 0xEA0);
    if (d != a) { d[0] = a[0]; d[1] = a[1]; d[2] = a[2]; }
    char *p = *(char **)(self + 0x304C);
    float *e = (float *)(p + 0x200);
    if (e != b) { e[0] = b[0]; e[1] = b[1]; e[2] = b[2]; }
}

extern "C" void func_001DD258(char *, int, int);

// FUNCTION: GAME 0x1DD5A0
extern "C" void func_001DD5A0(char *self, int k)
{
    func_001DD258(self, 0x25, k);
    func_001DD258(self, 0x26, k);
    func_001DD258(self, 0x27, k);
    func_001DD258(self, 0x28, k);
    func_001DD258(self, 0x29, k);
    func_001DD258(self, 0x2A, k);
    func_001DD258(self, 0x2B, k);
    func_001DD258(self, 0x2C, k);
}

extern "C" void initialize__7cIDBase7eIdData5eIdNo(char *, int, int);
extern "C" void restartAnim__7cIDBase(char *);
extern "C" void *getIDWork__7cIDBasei(char *, int);
extern "C" void Initialize__12CustomIDWorkP7cIDWork(char *, void *);
extern "C" void SetDisp__12CustomIDWorkb(char *, int);
extern "C" void func_001DD218(char *, int);
extern "C" void func_001DD238(char *, int);

// FUNCTION: GAME 0x1DD0D8
extern "C" void func_001DD0D8(char *self)
{
    char *b = self + 0x10;
    initialize__7cIDBase7eIdData5eIdNo(b, 0x12, 0);
    restartAnim__7cIDBase(b);
    int i = 0;
    char *w = self + 0x60;
    for (; i < 0x4D; i++) {
        Initialize__12CustomIDWorkP7cIDWork(w, getIDWork__7cIDBasei(self + 0x10, i));
        w += 0x7C;
    }
    SetDisp__12CustomIDWorkb(self + 0x60, 0);
    func_001DD218(self, 0);
    func_001DD238(self, 0);
}

extern "C" void SetOffsetPosXY__12CustomIDWorkii(char *, int, int);
struct T5 { int a[5]; };
extern T5 D_0042B5D0;

// FUNCTION: GAME 0x1DEBF0
extern "C" void func_001DEBF0(char *self, unsigned char k, int x, int y)
{
    if (k < 5) {
        T5 t = D_0042B5D0;
        SetOffsetPosXY__12CustomIDWorkii(self + (t.a[k] * 0x7C + 0x60), x, y);
    }
}

extern "C" void SetNumber__12CustomIDWorki(char *, int);
struct T8 { int a[8]; };
extern T8 D_0042B5B0;

// FUNCTION: GAME 0x1DD648
extern "C" void func_001DD648(char *self, unsigned short k, int x)
{
    if (k < 8) {
        T8 t = D_0042B5B0;
        SetNumber__12CustomIDWorki(self + (t.a[k] * 0x7C + 0x60), x);
    }
}

extern char Dvd[], RoomHeap[], D_0042B6E8[];
extern char *IDManager, **IDSys;
extern "C" int getLocalFileName__10cIDManagerPcT1Sc(char *, char *, char *, signed char);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(char *, char *, void **, char *, int, unsigned, unsigned, unsigned);
extern "C" void CheckWait__4cDvd6eDvdId(char *, int);
extern "C" void setIDData__10cIDManager7eIdDataPUi(char *, int, unsigned *);
extern "C" void func_001DECE0(char *);

// FUNCTION: GAME 0x1DF890
extern "C" void func_001DF890(char *self)
{
    char name[0x40];
    unsigned *data[4];
    getLocalFileName__10cIDManagerPcT1Sc(IDManager, name, D_0042B6E8, -1);
    int r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, name, (void **)data, RoomHeap, 0, 0, 0, 0);
    if (r) {
        CheckWait__4cDvd6eDvdId(Dvd, r);
        setIDData__10cIDManager7eIdDataPUi(*IDSys, 0x12, (unsigned *)data[0]);
        func_001DD0D8(self);
        func_001DECE0(self + 0x25B0);
    }
}
