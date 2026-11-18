// Small leaf units in 0x2D0000-0x2E0000 over raw offsets.
extern "C" {
void func_002D0820(char *, float);
void func_002D31B0(int, unsigned int);
void *memset(void *, int, unsigned);
int Check__4cDvd6eDvdId(void *, int);
void set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(void *, int, int, int, int, int, int);
float Adjust_theta__Ff(float);
int func_003AFB30(int, int);
int SignalSema(int);
void func_003AFAE0();
void sceVu0ApplyMatrix(float *, float *, float *);
int func_002D22B0(void *, int, int);
void func_002D2F78(void *, int, int, int, int);
void func_002D5788(char *, int);
void func_002D5918(char *);
void BgmEvFadeSet__4cSnd6eBgmPt9eBgmReqNofff(float, float, float);
int func_002CFF68(void *);
}
extern char D_0044D388[];
extern char Snd[];
extern char Dvd[];
extern char g_ActBtn[];
extern char *D_00747A94;
extern char *D_00747A98;

// FUNCTION: GAME 0x2D0350
extern "C" void func_002D0350(char *self, int m) { *(int *)(self + 4) |= m; }

// FUNCTION: GAME 0x2D03D0
extern "C" int func_002D03D0(char *self, int m) { return (~*(int *)(self + 4) & m) == 0; }

// FUNCTION: GAME 0x2D2DB0
extern "C" char *func_002D2DB0(char *self, int i) { return *(char **)(self + 0x38) + i * 0xDC; }

// FUNCTION: GAME 0x2D9E18
extern "C" void *func_002D9E18(void **self)
{
    *self = D_0044D388;
    return self;
}

// FUNCTION: GAME 0x2D42E0
extern "C" void func_002D42E0(char *self)
{
    if (*(int *)self) *(int *)(self + 0x60) = 1;
}

// FUNCTION: GAME 0x2DB6B0
extern "C" char *Getplayer__Fv() { return D_00747A94; }

// FUNCTION: GAME 0x2DB6C0
extern "C" char *GetJacket__Fv() { return D_00747A98; }

// FUNCTION: GAME 0x2D3190
extern "C" int func_002D3190(char *self)
{
    int v = *(int *)(self + 0xC40) + 1;
    *(int *)(self + 0xC40) = v;
    if (!v) *(int *)(self + 0xC40) = 1;
    return *(int *)(self + 0xC40);
}

// FUNCTION: GAME 0x2D36E8
extern "C" int *func_002D36E8(int *self)
{
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    self[5] = 0;
    self[6] = 0;
    self[0xA8 / 4] = 0;
    return self;
}

// FUNCTION: GAME 0x2DA9B8
extern "C" void Add_nullspeed__FP8cObjBase(char *self)
{
    sceVu0ApplyMatrix(*(float **)(self + 0xF0), (float *)(self + 0x80), (float *)(self + 0x330));
}

// FUNCTION: GAME 0x2D1578
extern "C" int func_002D1578(void *unused, int a1) { return func_002D22B0(Snd, 0, a1) != 0; }

// FUNCTION: GAME 0x2D30E0
extern "C" void func_002D30E0(void *self, int a1, int a2, int a3) { func_002D2F78(self, 1, a1, a2, a3); }

// FUNCTION: GAME 0x2D51C0
extern "C" void func_002D51C0(char *self, int a1, int a2) { func_002D5788(*(char **)self + a1 * 0x58, a2); }

// FUNCTION: GAME 0x2D58B8
extern "C" void func_002D58B8(char *self, int a1, int a2)
{
    *(short *)(self + 0x1E) = 1;
    *(int *)(self + 0x14) = a1;
    *(int *)(self + 0x18) = a2;
    func_002D5918(self);
}

// FUNCTION: GAME 0x2D58E8
extern "C" void func_002D58E8(char *self, int a1, int a2)
{
    *(short *)(self + 0x1E) = 1;
    *(int *)(self + 0x14) = a1;
    *(int *)(self + 0x18) = a2;
    func_002D5918(self);
}

// FUNCTION: GAME 0x2D1E18
extern "C" void func_002D1E18() { BgmEvFadeSet__4cSnd6eBgmPt9eBgmReqNofff(0.0f, 15.0f, -1.0f); }

// FUNCTION: GAME 0x2D04F8
extern "C" int GetHeadPtr__8cBgmData(char *self)
{
    if (!func_002CFF68(self)) return 0;
    return *(int *)(self + 0xC);
}

// FUNCTION: GAME 0x2D0728
extern "C" void func_002D0728(char *self, int a1, float f)
{
    *(int *)(self + 0x50) = a1;
    func_002D0820(self, f);
}

// FUNCTION: GAME 0x2D0578
extern "C" char *func_002D0578(char *self, int i)
{
    char *p = *(char **)(self + 0x30);
    if (!p) return 0;
    return *(char **)(p + 0x10) + i * 8;
}

// FUNCTION: GAME 0x2D0598
extern "C" char *func_002D0598(char *self, int i)
{
    char *p = *(char **)(self + 0x30);
    if (!p) return 0;
    return *(char **)(p + 0x14) + i * 16;
}

// FUNCTION: GAME 0x2D05B8
extern "C" char *func_002D05B8(char *self, int i)
{
    char *p = *(char **)(self + 0x30);
    if (!p) return 0;
    return *(char **)(p + 0x1C) + i * 2;
}

// FUNCTION: GAME 0x2D31E0
extern "C" void func_002D31E0() { func_002D31B0(1, 0xFFFF); }

// FUNCTION: GAME 0x2D3220
extern "C" void func_002D3220(void *self) { memset(self, 0, 0xC0); }

// FUNCTION: GAME 0x2D42B0
extern "C" int func_002D42B0(char *self)
{
    if (!*(int *)self) return 0;
    return *(int *)(*(char **)(self + 8) + 0x24);
}

// FUNCTION: GAME 0x2D5440
extern "C" void func_002D5440(char *self, int a1)
{
    if (!*(char **)(self + 4) || a1 == -1) return;
    *(unsigned char *)(*(char **)self + a1 * 0x58 + 0x50) = *(unsigned char *)(*(char **)(self + 4) + 0x50);
}

// FUNCTION: GAME 0x2D65F8
extern "C" void func_002D65F8(char *self, float a, float b, float c, float d)
{
    if (!*(char **)(self + 4)) return;
    *(float *)(*(char **)(self + 4) + 0x70) = a;
    *(float *)(*(char **)(self + 4) + 0x74) = b;
    *(float *)(*(char **)(self + 4) + 0x78) = c;
    *(float *)(*(char **)(self + 4) + 0x7C) = d;
}

// FUNCTION: GAME 0x2D0318
extern "C" int func_002D0318(char *self)
{
    int id = *(int *)(self + 0x1C);
    if (!id) return 1;
    return Check__4cDvd6eDvdId(Dvd, id) == 0;
}

// FUNCTION: GAME 0x2DB770
extern "C" void func_002DB770()
{
    set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(g_ActBtn, 0xB, 0x13, 0x10, 0, 0, 0);
}

// FUNCTION: GAME 0x2DB7A8
extern "C" void func_002DB7A8()
{
    set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(g_ActBtn, 0xB, 0x14, 0x11, 0, 0, 0);
}

// FUNCTION: GAME 0x2DA8D8
extern "C" float Ang_mult_late__Ffff(float a, float b, float t)
{
    float x = Adjust_theta__Ff(b);
    float y = Adjust_theta__Ff(a);
    float d = Adjust_theta__Ff(y - x);
    return Adjust_theta__Ff(x + d * t);
}

// FUNCTION: GAME 0x2D5990
extern "C" void func_002D5990(char *self)
{
    *(short *)(self + 0xC) = 2;
    if (*(int *)(self + 4) == -1) return;
    func_003AFB30(*(int *)(self + 4), 1);
    SignalSema(*(int *)(*(char **)self + 0x28));
    *(int *)(self + 4) = -1;
    func_003AFAE0();
}
