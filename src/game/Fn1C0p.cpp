struct V3 {
    float x, y, z;
};
struct V16 {
    float x, y, z, w;
} __attribute__((aligned(16)));
extern char CoreSave[];
extern char Snd[];
extern unsigned WorldTime;
extern char *Cockpit;
extern "C" int irand__Fv(void);
extern "C" int getGold__9cCoreSave(void *);
extern "C" int getClearNum__9cCoreSave(void *);
extern "C" void addGold__9cCoreSaveib(void *, int, int);
extern "C" void SetBgmState__4cSnd9eBgmState(void *, int);
extern "C" void BgmEventStart__4cSnd9eBgmReqNoii(void *, int, int, int);
extern "C" void setData__13cCockGetPointG4cVecUss(void *, V16 *, unsigned short, short);
extern "C" int func_001DCDA8(void);
extern "C" void func_001DE858(void *, unsigned char);
extern "C" void func_001C7138(void *);
extern "C" void func_001C7310(void *);
extern char g_EmManage[];
extern "C" float GetSpeedRate__9cEmManage(void *);
extern "C" void SetMotionStep__FP8cObjBasef(void *, float);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void moveMotion__FP8cObjBase(void *);
extern "C" unsigned func_001DCE68(void *, int, int);
extern "C" void SetNumber__12CustomIDWorki(void *, int);
extern "C" void SetOffsetPosX__12CustomIDWorki(void *, int);


#ifdef NONMATCHING
// DRAFT: GAME 0x1D9CA0
// diff: 2 words, sb 0x3024 / sb 0x3025 store order swapped; source order, uchar r and a temp zero all schedule the same way
extern "C" void func_001D9CA0(char *self)
{
    int v = func_001DCDA8();
    *(int *)(self + 0x3048) = v;
    int r;
    if (v < 8) {
        func_001DE858(self, *(unsigned char *)(self + 0x3048));
        if (*(int *)(self + 0x3048) < 8) {
            SetBgmState__4cSnd9eBgmState(Snd, 2);
            r = 9;
            goto done;
        }
    }
    BgmEventStart__4cSnd9eBgmReqNoii(Snd, 0x28, 0, 0);
    r = 10;
done:
    self[0x3024] = r;
    self[0x3025] = 0;
}
#endif

// FUNCTION: GAME 0x001C2408
extern "C" void func_001C2408(char *self, int n)
{
    if (n > 0) {
        if (getClearNum__9cCoreSave(CoreSave))
            n *= 2;
        addGold__9cCoreSaveib(CoreSave, n, 0);
        V16 v;
        __asm__ volatile("lqc2 $vf4,0(%0)\n\tsqc2 $vf4,0(%1)" : : "r"(*(char **)(self + 0xF0)), "r"(&v) : "memory");
        setData__13cCockGetPointG4cVecUss(Cockpit + 0x15C0, &v, (unsigned short)n, *(short *)(self + 0x2AC));
    }
}

// FUNCTION: GAME 0x001C6C30
extern "C" void func_001C6C30(char *self, V3 *p, float a, float b, float c)
{
    self[2] = 2;
    self[3] = 0x10;
    self[0] = 0;
    V3 *u = (V3 *)(self + 0x90);
    u->x = 0;
    u->y = b;
    u->z = 0;
    V3 *w = (V3 *)(self + 0xF0);
    w->x = 0;
    w->y = a;
    w->z = 0;
    V3 *d = (V3 *)(self + 0x50);
    if (d != p) {
        d->x = p->x;
        d->y = p->y;
        d->z = p->z;
    }
    *(float *)(self + 0x154) = c;
    func_001C7138(self);
    func_001C7310(self);
}

// DRAFT: GAME 0x1DCE68 (saved-reg assignment and order differ: orig keeps hi in s2, lo in s3)
#ifdef NONMATCHING
extern "C" unsigned func_001DCE68(void *, int lo, int hi)
{
    unsigned t = WorldTime;
    int g = getGold__9cCoreSave(CoreSave);
    unsigned r = t + irand__Fv() % 100 + g;
    return r % (hi - (lo - 1)) + lo;
}
#endif

// FUNCTION: GAME 0x001CB828
extern "C" void func_001CB828(char *self)
{
    float r = GetSpeedRate__9cEmManage(g_EmManage);
    *(float *)(self + 0x5A8) = r;
    SetMotionStep__FP8cObjBasef(self, r);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        int p = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(p + 0xC) + p, 0, 0, 0, 0, 0.0f);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

// FUNCTION: GAME 0x001CB990
extern "C" void func_001CB990(char *self)
{
    float r = GetSpeedRate__9cEmManage(g_EmManage);
    *(float *)(self + 0x5A8) = r;
    SetMotionStep__FP8cObjBasef(self, r);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        int p = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(p + 0xC) + p, 0, 0, 0, 0, 0.0f);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

// DRAFT: GAME 0x1DBE18 (9 words: original uses lwu flag test, count-up loop)
#ifdef NONMATCHING
extern "C" void func_001DBE18(char *self, int *out)
{
    int *list[52];
    int n = 0;
    for (int i = 0; i < 52; i++) {
        if (*(unsigned *)(self + 0x2E68 + i * 8) & 1)
            list[n++] = (int *)(self + 0x2E64 + i * 8);
    }
    if (n) {
        int *e = list[func_001DCE68(self, 0, n - 1)];
        *out = (int)e;
        e[1] &= ~1;
    }
}
#endif

// FUNCTION: GAME 0x001DD6D8
extern "C" void func_001DD6D8(char *self, int v)
{
    void *w = self + 0x22C4;
    SetNumber__12CustomIDWorki(w, v);
    if (v < 1000)
        SetOffsetPosX__12CustomIDWorki(w, -0x29);
    else if (v < 10000)
        SetOffsetPosX__12CustomIDWorki(w, -0x1C);
    else if (v <= 99999)
        SetOffsetPosX__12CustomIDWorki(w, -0xD);
    else
        SetOffsetPosX__12CustomIDWorki(w, 0);
}
