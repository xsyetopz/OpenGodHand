extern "C" void func_001F4778(void *, int, int);
extern "C" void func_001F5478(void *, int);
extern "C" void func_001F4928(void *, int);
extern "C" void func_001F9C88(void *);
extern "C" void func_001F9ED0(void *);
extern "C" void func_001F9C30(void *);
extern "C" void func_001F9C58(void *);
extern "C" void func_001F9DD0(void *);
extern "C" void func_001F9E28(void *);
extern "C" void func_001F9E90(void *);
extern "C" void func_001FACB0(void *);
extern "C" char *Getplayer__Fv(void);
extern "C" void setVital__9cCoreSavei(void *, int);

extern char CoreSave[];
extern char g_HeatSys[];
extern "C" void SetHeatGage__8cHeatSysf(void *, float);
extern "C" void func_001FA638(void *, int);
extern "C" void clearGodItem__9cCoreSave(void *);
extern "C" void addGodItem__9cCoreSaveUc(void *, int);
extern "C" int func_001FF9C0(void *, int, int *, int);
extern "C" int func_00323918(int, int);
extern "C" void func_00323E80(int, int, int);
extern "C" int func_003244C8(int);
extern "C" void func_00395398(int);
extern "C" void func_00323A70(int);
extern char D_00580D40[];
extern "C" int func_00323618(int, int);
extern "C" int func_003243C8(int);
extern "C" void *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, void *);
extern char D_00754200[];

extern "C" void func_001E7470(void *, int, int);
extern "C" void func_001EE9A0(void *);
extern "C" void func_001EDF60(void *);
extern "C" void func_001ED660(void *);
extern "C" void func_001ECBD0(void *);
extern "C" void func_001EB9F8(void *);
extern "C" void free__5cHeapPv(int, int);
extern int *IDSys;
extern "C" void initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void restartAnim__7cIDBase(void *);
extern "C" void *getIDWork__7cIDBasei(void *, int);
extern "C" void Initialize__12CustomIDWorkP7cIDWork(void *, void *);
extern "C" void func_001ED7E0(void *);
extern "C" void func_001EDC28(void *, int);
extern "C" void func_001ED700(void *, int, int);
extern "C" void func_001EE2A8(void *, int);
extern "C" void func_001EE2C8(void *, int);
extern "C" void SetDisp__12CustomIDWorkb(void *, int);
extern "C" void func_001EE1C0(void *, int, int);
extern "C" void SetMessNo__12CustomIDWorki(void *, int);
extern "C" void func_001ECE30(void *, int, int);
extern "C" void func_001ED490(void *, int);

// FUNCTION: GAME 0x1F4840
extern "C" void func_001F4840(void *self)
{
    func_001F4778(self, 0x6F, 0);
    func_001F4778(self, 0, 1);
    func_001F4778(self, 1, 1);
    func_001F4778(self, 2, 1);
    func_001F4778(self, 3, 1);
    func_001F4778(self, 4, 1);
    func_001F4778(self, 5, 1);
    func_001F4778(self, 6, 1);
    func_001F4778(self, 7, 1);
    func_001F4778(self, 8, 1);
    func_001F4778(self, 9, 1);
    func_001F5478(self, 1);
    func_001F4928(self, 1);
}

// FUNCTION: GAME 0x1F9B88
extern "C" void func_001F9B88(void *self, int flag)
{
    func_001F9C88(self);
    if (flag) {
        func_001F9ED0(self);
        func_001F9C30(self);
        func_001F9C58(self);
        func_001F9DD0(self);
        func_001F9E28(self);
        func_001F9E90(self);
    }
    func_001FACB0(self);
    if (*(short *)(Getplayer__Fv() + 0x54A) > 0)
        setVital__9cCoreSavei(self, *(short *)(Getplayer__Fv() + 0x54A));
    else
        setVital__9cCoreSavei(self, 1);
}

// FUNCTION: GAME 0x1F6D38
extern "C" void ResetWarmUpRoom__10CasinoWork(char *self)
{
    char *p = Getplayer__Fv();
    int v = *(int *)(self + 4);
    if (v >= *(short *)(p + 0x548))
        *(short *)(p + 0x54A) = *(unsigned short *)(p + 0x548);
    else
        *(short *)(p + 0x54A) = v;
    setVital__9cCoreSavei(CoreSave, *(int *)(self + 4));
    SetHeatGage__8cHeatSysf(g_HeatSys, *(float *)(self + 8));
    func_001FA638(CoreSave, *(short *)(self + 0xC));
    clearGodItem__9cCoreSave(CoreSave);
    int i;
    for (i = 0; i < *(unsigned short *)(self + 0xE); i++)
        addGodItem__9cCoreSaveUc(CoreSave, 1);
    *(int *)self &= -2;
}

// FUNCTION: GAME 0x1FFD00
extern "C" void func_001FFD00(int a, int b, int c)
{
    int buf[1];
    int r = func_001FF9C0(D_00580D40, b, buf, 0);
    if (r >= 0) {
        int h = func_00323918(0, r);
        func_00323E80(h, buf[0], c);
        while (func_003244C8(h) != 3)
            func_00395398(0);
        func_00323A70(h);
    }
}

// FUNCTION: GAME 0x1FFC60
extern "C" void *func_001FFC60(int a, int b)
{
    int h = func_00323618(b, 0);
    int n = func_003243C8(h);
    void *m = _MemoryAlloc__FUiUiR5cHeap(n << 11, 0x40, D_00754200);
    func_00323E80(h, n, (int)m);
    while (func_003244C8(h) != 3)
        func_00395398(0);
    return m;
}

// FUNCTION: GAME 0x1E77B0
extern "C" void func_001E77B0(void *self, int v)
{
    func_001E7470(self, 2, v);
    func_001E7470(self, 3, v);
    func_001E7470(self, 4, v);
    func_001E7470(self, 5, v);
    func_001E7470(self, 6, v);
    func_001E7470(self, 7, v);
    func_001E7470(self, 8, v);
}

// FUNCTION: GAME 0x1E9E40
extern "C" void func_001E9E40(char *self)
{
    char *p = self + 0x5C;
    int n = 4;
    do {
        func_001EE9A0(p);
        n--;
        p += 0x40;
    } while (n >= 0);
    func_001EDF60(self + 0x1B90);
    func_001ED660(self + 0x1840);
    func_001ECBD0(self + 0x210);
    int *w = (int *)*IDSys;
    w[0xA4 / 4] = 0;
    w[0xA0 / 4] = 0;
    int h = *(int *)(self + 0x2A0C);
    if (h != 0)
        free__5cHeapPv(*(int *)(h - 0x20), h);
    func_001EB9F8(self);
}

// FUNCTION: GAME 0x1ED5B8
extern "C" void func_001ED5B8(char *self)
{
    char *b = self + 0x10;
    int i;
    initialize__7cIDBase7eIdData5eIdNo(b, 0x14, 2);
    i = 0;
    char *w = self + 0x60;
    restartAnim__7cIDBase(b);
    do {
        Initialize__12CustomIDWorkP7cIDWork(w, getIDWork__7cIDBasei(self + 0x10, i));
        i++;
        w += 0x7C;
    } while (i < 6);
    func_001ED7E0(self);
    func_001EDC28(self, 0);
    func_001ED700(self, 6, 0);
}

// FUNCTION: GAME 0x1EDEA8
extern "C" void func_001EDEA8(char *self)
{
    char *b = self + 0x10;
    int i;
    initialize__7cIDBase7eIdData5eIdNo(b, 0x14, 1);
    i = 0;
    char *w = self + 0x60;
    restartAnim__7cIDBase(b);
    do {
        Initialize__12CustomIDWorkP7cIDWork(w, getIDWork__7cIDBasei(self + 0x10, i));
        i++;
        w += 0x7C;
    } while (i < 0x1D);
    func_001EE2A8(self, 0);
    func_001EE2C8(self, 0);
    SetDisp__12CustomIDWorkb(self + 0x60, 0);
    func_001EE1C0(self, 0x1D, 0);
}

// FUNCTION: GAME 0x1ECAF0
extern "C" void func_001ECAF0(char *self)
{
    char *b = self + 0x10;
    int i;
    initialize__7cIDBase7eIdData5eIdNo(b, 0x14, 0);
    i = 0;
    char *w = self + 0x60;
    restartAnim__7cIDBase(b);
    do {
        Initialize__12CustomIDWorkP7cIDWork(w, getIDWork__7cIDBasei(self + 0x10, i));
        i++;
        w += 0x7C;
    } while (i < 0x2D);
    SetMessNo__12CustomIDWorki(self + 0xE6C, 0x101A);
    SetMessNo__12CustomIDWorki(self + 0x1534, 0x101A);
    SetMessNo__12CustomIDWorki(self + 0xEE8, 0x101B);
    SetMessNo__12CustomIDWorki(self + 0x15B0, 0x101B);
    SetDisp__12CustomIDWorkb(self + 0x440, 0);
    func_001ECE30(self, 0x2D, 0);
    func_001ED490(self, 0);
}
