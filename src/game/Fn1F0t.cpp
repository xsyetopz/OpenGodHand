// Small helpers in 0x1F0000-0x200000, over raw offsets (continued from Fn1F0s.cpp).

extern "C" void setDoorJump__5cDoor(void *);

typedef void (*VFn)(char *, int);
// FUNCTION: GAME 0x1FD820
extern "C" void func_001FD820(char *self, int a1)
{
    char *p = *(char **)(self + 0x3C);
    if (p) {
        do {
            char *o = *(char **)(*(char **)(p + 0x28) + 0x34);
            char *vt = *(char **)(o + 0x100);
            ((VFn) * (int *)(vt + 0x3C))(o + *(short *)(vt + 0x38), a1);
            p = *(char **)(p + 0x24);
        } while (p);
    }
}


extern char Door[];
// FUNCTION: GAME 0x1F9ED0
extern "C" void func_001F9ED0(char **self)
{
    if (*self) {
        char *p = Door;
        char *d = p + 0x1C;
        *(unsigned short *)(*self + 0x15A) = *(unsigned short *)(d + 0x10);
        *(float *)(*self + 0x15C) = *(float *)(p + 0x1C);
        *(float *)(*self + 0x160) = *(float *)(d + 4);
        *(float *)(*self + 0x164) = *(float *)(d + 8);
        *(float *)(*self + 0x168) = *(float *)(d + 0xC);
        (*self)[0x158] = d[0x12];
        (*self)[0x159] = d[0x13];
        *(int *)(*self + 0x16C) = *(int *)(d + 0x14);
    }
}

extern unsigned short D_00747A50;
// FUNCTION: GAME 0x1FFEB8
extern "C" void func_001FFEB8(unsigned char *d, unsigned short a1, float *v, unsigned char a3, int t0, unsigned char t1, float f)
{
    *(unsigned short *)(d + 0x14) = (a1 == D_00747A50) ? 0xFFFF : a1;
    *(float *)(d + 4) = v[0];
    *(float *)(d + 8) = v[1];
    *(float *)(d + 0xC) = v[2];
    *(float *)(d + 0x10) = f;
    d[0x16] = 0xFF;
    d[0x17] = a3;
    *(int *)(d + 0x18) = t0;
    d[0x3A] = t1;
    setDoorJump__5cDoor(d);
}


extern char Door[];
extern "C" void func_002009B0(char *, char *);
// FUNCTION: GAME 0x1F9F50
extern "C" void func_001F9F50(char **self)
{
    char *s = *self;
    if (s) {
        struct { float x, y, z, w; unsigned short h; unsigned char b0, b1; int i; } t;
        t.h = *(unsigned short *)(s + 0x15A);
        t.x = *(float *)(s + 0x15C);
        t.y = *(float *)(s + 0x160);
        t.z = *(float *)(s + 0x164);
        t.w = *(float *)(s + 0x168);
        t.b0 = s[0x158];
        t.b1 = s[0x159];
        t.i = *(int *)(s + 0x16C);
        func_002009B0(Door, (char *)&t);
    }
}

// FUNCTION: GAME 0x1FC650
extern "C" void getAllStageTime__9cCoreSavePUiN21(char **self, unsigned *h, unsigned *m, unsigned *s)
{
    char *d = *self;
    if (d) {
        unsigned t = *(unsigned *)(d + 0xBBC);
        unsigned hh = t / 108000;
        t -= hh * 108000;
        unsigned mm = t / 1800;
        t -= mm * 1800;
        unsigned ss = t / 30;
        if (h) *h = hh;
        if (m) *m = mm;
        if (s) *s = ss;
    }
}

extern "C" int ckClearStage__9cCoreSaveUs(void *, unsigned short);
extern char CoreSave[];
// FUNCTION: GAME 0x1FC020
extern "C" char func_001FC020(int *self)
{
    if (!*self) return 0;
    unsigned char i = 1;
    while (i < 8) {
        if (!ckClearStage__9cCoreSaveUs(CoreSave, i)) break;
        i++;
    }
    return i;
}

#ifdef NONMATCHING
extern "C" int func_002CB278(void *);
extern char Snd[];
// DRAFT: GAME 0x1FF4D0 (3 words: original keeps the range test in v0, compiled reuses a1)
// diff: 3 words; also tried inline/&&/assign-in-cond/int t forms; ~15 forms tried (temps, int/unsigned id, inline helper, &&, ?:)
extern "C" void func_001FF4D0(char *self, unsigned id)
{
    unsigned t = id - 0x200;
    if (t < 0xFF) {
        int r = func_002CB278(Snd);
        char *a = self + 0x24;
        *(int *)(a + (*(int *)(self + 0x18) << 2)) = r;
        if (*(int *)(a + (*(int *)(self + 0x18) << 2)) != -1)
            *(int *)(self + 0x18) += 1;
    }
}
#endif

struct Sce { char pad[0x20]; void *task; };
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern char Fade[];
extern Sce *g_Sce;

// FUNCTION: GAME 0x1F6078
extern "C" void func_001F6078(char *self)
{
    start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, 0, 0xFF000000, 10);
    sleep__9cTaskWorkUs(g_Sce->task, 10);
    self[4] = 1;
}

struct Ent { short off; short pad; void (*fn)(char *); };
extern Ent D_003BF0E0[];
extern "C" void move__7cIDBase(char *);
extern "C" void trans__7cIDBase(char *);
extern short D_005CAE40;

// FUNCTION: GAME 0x1F5E90
extern "C" void func_001F5E90(unsigned char *self)
{
    char *p = (char *)self + 0x30;
    int o = self[0] << 3;
    short off = *(short *)((char *)D_003BF0E0 + o);
    (*(void (**)(char *))((char *)D_003BF0E0 + o + 4))((char *)self + off);
    D_005CAE40 = 10;
    move__7cIDBase(p);
    trans__7cIDBase(p);
}

extern "C" void __7cIDBase(char *);
extern "C" void __12CustomIDWork(char *);

// FUNCTION: GAME 0x1F45D8
extern "C" char *func_001F45D8(char *self)
{
    *(int *)self = 0;
    __7cIDBase(self + 0x10);
    char *p = self + 0x60;
    for (int i = 0x6E; i != -1; i--, p += 0x7C)
        __12CustomIDWork(p);
    return self;
}

extern "C" void restartAnim__7cIDBase(char *);
// FUNCTION: GAME 0x1F5EF8
extern "C" void func_001F5EF8(unsigned char *self)
{
    restartAnim__7cIDBase((char *)self + 0x30);
    self[3] = 0;
    self[2] = 0;
    self[0] = 1;
    self[1] = 1;
    start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, 0xFF000000, 0, 10);
    sleep__9cTaskWorkUs(g_Sce->task, 10);
}


extern "C" void func_001FF2E0(char *, int);
// FUNCTION: GAME 0x1FED78
extern "C" void func_001FED78(char *self, int id, int a)
{
    for (int i = 0; i < *(int *)(self + 4); i++) {
        char *e = (char *)(i * 0x5C) + *(int *)(self + 8);
        if (*(int *)(e + 0x20) == id)
            func_001FF2E0(e, a);
    }
}

extern "C" int func_001FC210(char **);
extern "C" void func_001FC170(char **, unsigned char, int);

// FUNCTION: GAME 0x1FB8B8
extern "C" void setGodReel__9cCoreSave10eCommandNo(char **self, int n)
{
    char *d = *self;
    if (d && n < 0x1F) {
        *(int *)(d + 0x130) |= 1 << n;
        int r = func_001FC210(self);
        if (r != -1)
            func_001FC170(self, r, n);
    }
}

#ifdef NONMATCHING
extern "C" void BgmEventFade__4cSnd9eBgmReqNofff(void *, int, float, float, float);
extern "C" void release__7cIDBase(char *);
extern "C" void free__5cHeapPv(void *, void *);
extern int D_007474B0;
extern char Snd[];
extern char *IDManager;

// DRAFT: GAME 0x1F5C48 (6 words: store order of D_007474B0 and IDManager+0xF0/0xF4 loads; tried F4/F0 source order (6), IDManager direct (15), hoisted id (9))
extern "C" void func_001F5C48(char *self)
{
    D_007474B0 = 0;
    BgmEventFade__4cSnd9eBgmReqNofff(Snd, *(int *)(self + 0x24), 20.0f, 0.0f, -1.0f);
    release__7cIDBase(self + 0x30);
    char *m = IDManager;
    *(int *)(m + 0xF0) = 0;
    *(int *)(m + 0xF4) = 0;
    char *p = *(char **)(self + 0x80);
    if (p)
        free__5cHeapPv(*(void **)(p - 0x20), p);
}
#endif
