extern "C" void func_00296738(void *);
extern "C" int func_002967B0(void *);
extern "C" void ResetHiddenModels__12HideModelMgr(void *);
extern "C" void ClearHiddenModelList__12HideModelMgr(void *);
extern "C" void setOmSuspend__9cScenariob(void *, int);
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void executeTask__11cNowLoading(int);
extern char Fade;
extern int NowLoading;
extern char _12HideModelMgr$g_Singleton;
extern void *g_Sce;
extern int D_00747A80[];
extern char D_00747A2C;
extern int D_00752CF0;
extern int D_005CAFF4;
extern char g_E3;
extern void *SubScr;
extern "C" void func_00201BE0(void *, int);
extern "C" void func_002A6FF8(char *);
extern "C" void *Getplayer__Fv(void);
extern "C" int CkSubScreen__4pl00(void *);
extern "C" void SubScrOn__7cSubScr9eSubScrIdUcUc(void *, int, int, int);
extern "C" void Move__Fv(void);
extern "C" void Trans__Fv(void);

// DRAFT: GAME 0x2965F0 - 31 words; Tried: local int flags mask, unsigned flags, early return in block
#ifdef NONMATCHING
extern "C" int func_002965F0(char *self)
{
    switch (self[5]) {
    case 0:
        func_00296738(self);
        self[5]++;
        /* fallthrough */
    case 1:
        if (func_002967B0(self) != 0) {
            D_00747A80[0] |= 0x2000000;
            ResetHiddenModels__12HideModelMgr(&_12HideModelMgr$g_Singleton);
            ClearHiddenModelList__12HideModelMgr(&_12HideModelMgr$g_Singleton);
            D_00747A80[-2] |= 0x200000;
            setOmSuspend__9cScenariob(g_Sce, 1);
            {
                int flags = D_00747A80[-2];
                flags &= 0xDFFFFFFF;
                flags &= 0xEFFFFFFF;
                flags &= 0xFBFFFFFF;
                D_00747A80[-2] = flags;
            }
            D_00747A80[1] |= 0x1000000;
            start__9classFADEUiUiUiUiUiUi(&Fade, 0, 8, 0, 0xFF000000, 0xFF000000, 0);
            executeTask__11cNowLoading(NowLoading);
            self[7] = 0;
            self[4] = 1;
            self[5] = 0;
            self[6] = 0;
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}
#endif

// DRAFT: GAME 0x2A6690 - 79 words; Tried: unsigned long 0x1A0 read (no gain); frame 0x30 vs 0x40 and timer constant form open
#ifdef NONMATCHING
extern "C" void gameLoop__5cGame(char *self)
{
    int t = *(int *)0x10000800;
    D_00752CF0 = t;
    if (*(int *)(&D_00747A2C + 8) & 0x800) {
        func_00201BE0(&g_E3, t);
    }
    func_002A6FF8(self);
    char *a = &D_00747A2C - 0x58C;
    if ((*(int *)(a + 0x1A0) & 0x200000) && *(short *)(self + 0x1B0) == 0) {
        int v = *(int *)(a + 0x5E4);
        if (!(v & 0x200000) && !(v & 0x4000) && !(v & 0x2000000) && !(*(int *)(a + 0x5D8) & 0x2000000)) {
            int c = CkSubScreen__4pl00(Getplayer__Fv());
            if (c == (*(short *)(self + 0x1B0) == 0)) {
                SubScrOn__7cSubScr9eSubScrIdUcUc(SubScr, 0, 0, 0);
            }
        }
    }
    if (*(short *)(self + 0x1B0) != 0) {
        *(short *)(self + 0x1B0) = (short)((unsigned short)*(short *)(self + 0x1B0) - 1);
    }
    Move__Fv();
    D_005CAFF4 = 0;
    Trans__Fv();
    D_00752CF0 -= *(int *)0x10000800;
}
#endif

// DRAFT: GAME 0x2AC878 - 53 words; Tried: __builtin_sqrtf (101); sqrt.s asm on s2 with d = s2 + ap[-1] (55); asm on s2 with d = s2 (55); asm on s2 with d = ap[-1] + s2 (53, kept); frame and saved-register set not yet compared against the original
#ifdef NONMATCHING
extern "C" int func_002AC878(float t, int unused, float *outx, float *outy, char *obj)
{
    float arr[32];
    if (1.0f < t) {
        return 0;
    }
    char *p = *(char **)(obj + 0x1C);
    int n = *(short *)(p + 0x6E);
    int lim = n - 2;
    int i = 1;
    float f4 = 0.0f;
    if (i < lim) {
        f4 = t * *(float *)(obj + 0x9C);
        float *pt = *(float **)obj + 2;
        float *ap = arr + 1;
        do {
            float dx = fabsf(pt[0] - pt[2]);
            float dy = fabsf(pt[1] - pt[3]);
            float s2 = dx * dx + dy * dy;
            __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(s2));
            float d = ap[-1] + s2;
            if (f4 < d) {
                break;
            }
            *ap = d;
            i++;
            ap++;
            pt += 2;
        } while (i < lim);
    }
    if (n < 4) {
        return 0;
    }
    float u = (f4 - arr[i - 1]) / (arr[i] - arr[i - 1]);
    float *q = *(float **)obj + 2 * i;
    float x0 = q[0];
    *outx = x0 + (q[2] - x0) * u;
    float y0 = q[1];
    *outy = y0 + (q[3] - y0) * u;
    return 1;
}
#endif

// FUNCTION: GAME 0x2B0D68
extern "C" int func_002AF348(int);
extern "C" int func_002A4B20(int, unsigned short);
extern "C" char *getMessageAddr__C8cMessageUs(char *, unsigned short);
extern int Font;
extern int Message;
extern "C" float func_002B0D68(char *self, int n, float *out)
{
    int s = n;
    int m = 1;
    unsigned digits = func_002AF348(s);
    float acc = 0.0f;
    int v1 = 1;
    if ((unsigned)m < digits) {
        do {
            v1++;
            m *= 10;
        } while ((unsigned)v1 < digits);
    }
    if (m != 0) {
        do {
            int q = s / m;
            char *msg = getMessageAddr__C8cMessageUs((char *)Message, 4);
            acc += (float)func_002A4B20(Font, *(unsigned short *)(msg + q * 2)) * (*out * *(float *)(self + 0x3C) * *(float *)(self + 0x44)) + *(float *)(self + 0x2C) * *(float *)(self + 0x44);
            int t = q * m;
            m = m / 10;
            s -= t;
        } while (m != 0);
    }
    return acc - *(float *)(self + 0x2C) * *(float *)(self + 0x44);
}
