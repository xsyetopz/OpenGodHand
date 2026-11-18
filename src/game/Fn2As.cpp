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

extern "C" void func_002A9DF8(char *);
extern "C" int func_002ACD78(int *, int, int);
extern "C" int setWorkFromData__7cIDBasePUi(char *, int);
extern "C" void resetAnim__7cIDBase(char *);
extern int **IDSys;

// FUNCTION: GAME 0x2A9EA0
extern "C" int initialize__7cIDBase7eIdData5eIdNo(char *self, int a, int b)
{
    func_002A9DF8(self);
    *(int *)(self + 0x10) = b;
    *(char *)(self + 0x46) = 6;
    *(int *)(self + 0x14) = a;
    int p = func_002ACD78(*IDSys, a, b + 1);
    if (!p) return 0;
    if (setWorkFromData__7cIDBasePUi(self, p)) resetAnim__7cIDBase(self);
    return 1;
}

extern char Sys[];
extern char Sys2;
extern char *Message;
extern char D_0044B100[];
extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);

// FUNCTION: GAME 0x2AE990
extern "C" void func_002AE990(char *self)
{
    char *s = Sys;
    *(int *)Message = SearchData__FPUiPCcUi(*(void **)(s + 0x558), D_0044B100, 0);
    *(int *)(Message + 0xC) = SearchData__FPUiPCcUi(*(void **)(s + 0x558), D_0044B100, 1);
    *(short *)(self + 0xBDA) = 0x384;
    *(char *)(self + 0xBF0) = 0;
}

extern "C" int func_002AC538(int, int, int, char *);
extern "C" float func_002AC5B0(int, int, int, char *);

// FUNCTION: GAME 0x2AC650
extern "C" float func_002AC650(int a, short key, int n, char *tbl)
{
    int i = func_002AC538(a, key, n, tbl);
    return i < 0 ? 0.0f : *(float *)(tbl + i * 12) + (*(float *)(tbl + i * 12 + 12) - *(float *)(tbl + i * 12)) * func_002AC5B0(a, key, i, tbl);
}

extern "C" void func_002A9100(long *, long *, int);
extern "C" void func_002A9210(long *, long *, int, int);

// FUNCTION: GAME 0x2A9288
extern "C" void func_002A9288(long *first, long *last, int c)
{
    if (last - first > 16) {
        long *m = first + 16;
        func_002A9100(first, m, c);
        func_002A9210(m, last, 0, c);
    } else {
        func_002A9100(first, last, c);
    }
}

extern "C" void func_002AEDF0(char *, unsigned char);
extern "C" unsigned short *func_002AEE40(char *, short);
extern "C" void func_002B2158(unsigned short *, unsigned short, unsigned char, void *);

// FUNCTION: GAME 0x2AEB68
extern "C" unsigned short create__8cMessageUiP4cObjUcs(char *self, unsigned no, void *obj, unsigned char c, short s)
{
    func_002AEDF0(self, c);
    unsigned short *p = func_002AEE40(self, s);
    if (!p) return 0xFFFF;
    func_002B2158(p, no, c, obj);
    return *p;
}

extern "C" void func_002A84A8(char *);
extern "C" void setMotionInfo__FP8cObjBaseUiUiUiffUs(char *, unsigned, unsigned, unsigned, float, float, unsigned short);

// FUNCTION: GAME 0x2A8578
extern "C" void func_002A8578(char *self, unsigned a, unsigned b, unsigned c, float f, unsigned short d, unsigned short e)
{
    if (!e) func_002A84A8(self);
    setMotionInfo__FP8cObjBaseUiUiUiffUs(self, a, b, c, *(float *)(self + 0x5A8), f, d);
}

struct P8 { int a; float k; };
static inline int lt(const P8 &x, const P8 &y) { return x.k < y.k; }

// FUNCTION: GAME 0x2A8E48
extern "C" P8 *func_002A8E48(P8 *lo, P8 *hi, P8 pivot)
{
    while (1) {
        while (lt(*lo, pivot)) lo++;
        hi--;
        while (lt(pivot, *hi)) hi--;
        if (!(lo < hi)) return lo;
        P8 t = *lo;
        *lo = *hi;
        *hi = t;
        lo++;
    }
}

extern "C" void gameInit__10cWorldTime(void *);
extern "C" void setPlCamera__11cCamManagerUc(void *, unsigned char);
extern "C" void func_00290110(void *);
extern "C" void func_001FDEA8(void *);
extern "C" void func_001F6CF8(void *);
extern "C" void gameInit__9cCoreSave(void *);
extern char WorldTime[], CamManager[], g_EmManage[], g_DmgManage[], g_CasinoWork[], CoreSave[];
extern unsigned D_00747A24;

// FUNCTION: GAME 0x2A5B18
extern "C" void func_002A5B18(char *self)
{
    gameInit__10cWorldTime(WorldTime);
    D_00747A24 |= 0x10;
    setPlCamera__11cCamManagerUc(CamManager, 0);
    *self = 1;
    func_00290110(g_EmManage);
    func_001FDEA8(g_DmgManage);
    Initialize__8cHeatSys((int *)g_HeatSys);
    func_001F6CF8(g_CasinoWork);
    gameInit__9cCoreSave(CoreSave);
    *(float *)(self + 0x1AC) = 0.5f;
}

// FUNCTION: GAME 0x2A84A8
extern "C" void func_002A84A8(char *self)
{
    char *p = *(char **)(self + 0x42C);
    if (p) {
        char *e = p + *(unsigned short *)(p + 0x14);
        for (unsigned i = 0; i < *(unsigned short *)(p + 0x16); i++, e += 12) {
            int id = *(int *)e;
            if (id != -1) {
                if (*(unsigned char *)(e + 0xA) & 2)
                    KillEffect__FPC4cObji13eEspEraseMode(self, id, 2);
                else
                    KillEffect__FPC4cObji13eEspEraseMode(self, id, 0);
            }
        }
    }
    int s = *(short *)(self + 0x570);
    if (s != -1) KillEffect__FPC4cObji13eEspEraseMode(self, s, *(int *)(self + 0x574));
    *(short *)(self + 0x570) = -1;
    *(int *)(self + 0x574) = 2;
}

extern "C" void func_002B22E8(char *, int, char *, int, int);

// FUNCTION: GAME 0x2AEA18
extern "C" void func_002AEA18(char *self)
{
    char *s = Sys;
    *(int *)(Message + 4) = SearchData__FPUiPCcUi(*(void **)(s + 0x5AC), D_0044B100, *(unsigned *)(s + 0x56C));
    char *p = self + 0x18;
    char *q;
    for (int i = 14; i >= 0; i--) {
        q = p + 0xBC;
        func_002B22E8(p, 0, q, 0, 0);
        p = q;
    }
    func_002B22E8(q, 0, 0, 0, 0);
    *(short *)(self + 0xBD8) = 1;
    *(char **)(self + 0x14) = self + 0x18;
    *(int *)(self + 0x10) = 0;
}

extern "C" unsigned strlen(const char *);
extern char g_ps2[];
extern char D_0044B060[], D_0044B090[];
struct B10 { char c[10]; };
extern B10 D_0044B080;
extern "C" int func_002BE240(char *, char *, int, char *);

// FUNCTION: GAME 0x2AE3F0
extern "C" void func_002AE3F0(int *self)
{
    while (func_002BE240(g_ps2, D_0044B060, 0, 0) < 0) {}
    B10 b = D_0044B080;
    while (func_002BE240(g_ps2, D_0044B090, strlen(b.c) + 1, b.c) < 0) {}
    self[3] = -1;
    self[4] = -1;
}
