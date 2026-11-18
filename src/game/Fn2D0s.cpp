// Small leaf units in 0x2D0000-0x2E0000 over raw offsets.
extern "C" {
void func_002D0820(char *, float);
void func_002D31B0(int, unsigned int);
void *memset(void *, int, unsigned);
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
