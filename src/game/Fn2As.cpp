// FUNCTION: GAME 0x2A96C0
extern "C" int func_002A96C0(int a, int n, int align)
{
    int t = a + 7;
    t += align;
    align = -align;
    return (t & align) * n;
}

extern "C" void resetAnim__7cIDBase(char *);

// FUNCTION: GAME 0x2ABBE8
extern "C" void restartAnim__7cIDBase(char *self)
{
    resetAnim__7cIDBase(self);
    *(char *)(self + 0x1C) = 1;
}

extern "C" char *Getplayer__Fv();
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(char *, int, int);

// FUNCTION: GAME 0x2A9CC8
extern "C" void SetHeatMode__8cHeatSysUc(float *self, unsigned char mode)
{
    *(unsigned char *)(self + 4) = mode;
    float d = self[1] - self[3];
    self[2] = d;
    if (d < 0.0f) self[2] = 0.0f;
    if (mode) KillEffect__FPC4cObji13eEspEraseMode(Getplayer__Fv(), 3, 2);
}

extern unsigned D_00747A78;
extern "C" void func_002B2438(int *);
extern "C" int func_002AEF10(int *, int *);

// FUNCTION: GAME 0x2AEFA8
extern "C" void func_002AEFA8(int *self)
{
    int *p;
    if (!(D_00747A78 & 0x80000)) {
        p = (int *)self[4];
        if (p) {
            do {
                func_002B2438(p);
                int t = *(unsigned char *)((char *)p + 0xC) ^ 7;
                if (!t) p = (int *)func_002AEF10(self, p);
                else p = (int *)p[2];
            } while (p);
        }
    }
}

extern float g_HeatSys[];
extern "C" void func_002A9BF0(float *, float);
extern "C" void SetHeatGage__8cHeatSysf(float *, float);
extern "C" void func_002A9C90(float *, float);
extern "C" void func_002A9B50(float *);

// FUNCTION: GAME 0x2A9908
extern "C" void Initialize__8cHeatSys(int *self)
{
    self[0] = 0;
    self[1] = 0;
    self[3] = 0;
    self[2] = 0;
    self[5] = 0;
    func_002A9BF0(g_HeatSys, 120.0f);
    SetHeatGage__8cHeatSysf(g_HeatSys, 0.0f);
    func_002A9C90(g_HeatSys, 120.0f);
}

// FUNCTION: GAME 0x2A9AD0
extern "C" int SubHeatGage__8cHeatSysfUi(float *self, float f, unsigned flag)
{
    float d = self[1] - f;
    self[1] = d;
    if (d < self[2]) self[1] = self[2];
    func_002A9B50(self);
    if (flag) {
        if (self[1] <= self[2]) {
            self[1] = self[2];
            return 1;
        }
    }
    return 0;
}
