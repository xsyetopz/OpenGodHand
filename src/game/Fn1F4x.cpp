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
