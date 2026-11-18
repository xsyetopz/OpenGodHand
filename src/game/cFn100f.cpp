// Second half of cFn100b (split to keep files under 300 lines).
extern "C" void setExit__17cActionButtonUnit(void *);
extern "C" void SeStop__4cSnd6eSndId(void *, int);
extern "C" void func_001268F0(void *);
extern "C" void func_001268B0(void *, int);
extern "C" int func_001FC708(void *);
extern "C" void trans__7cIDBase(void *);
extern "C" void func_001468B0(void *);
extern "C" void *initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void *getIDWork__7cIDBasei(void *, int);
extern char Snd[];
extern char CoreSave[];
extern char D_00747A24[];
extern unsigned D_007474A8;

// FUNCTION: GAME 0x1467E8
extern "C" void func_001467E8(char *self)
{
    unsigned short i;
    char *p = self + 0x90;
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 0x1D);
    i = 0;
    initialize__7cIDBase7eIdData5eIdNo(self + 0xA0, 1, 0x1E);
    do {
        *(void **)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 4);
    *(short *)(self + 0x100) = 0;
    func_001468B0(self);
}

extern "C" void func_0031EEC8(void *, char *);
extern "C" void func_0031EEA8(void *, char *, void *);
extern int __ti15cCollisionSolid[];
extern char D_0041D830[], D_0041D848[], D_0041D860[];
extern int D_00785548[], D_00785558[];

// FUNCTION: GAME 0x1342B8
extern "C" int *func_001342B8()
{
    if (!D_00785548[0]) {
        if (!__ti15cCollisionSolid[0])
            func_0031EEC8(__ti15cCollisionSolid, D_0041D830);
        func_0031EEA8(D_00785548, D_0041D848, __ti15cCollisionSolid);
    }
    return D_00785548;
}

// FUNCTION: GAME 0x134330
extern "C" int *func_00134330()
{
    if (!D_00785558[0]) {
        if (!__ti15cCollisionSolid[0])
            func_0031EEC8(__ti15cCollisionSolid, D_0041D830);
        func_0031EEA8(D_00785558, D_0041D860, __ti15cCollisionSolid);
    }
    return D_00785558;
}

extern int __ti21cCollisionScrollSolid[];
extern char D_0041D5D0[], D_0041D5E8[], D_0041D600[], D_0041D880[];
extern int D_00785528[], D_00785538[], D_00785568[];

// FUNCTION: GAME 0x133810
extern "C" int *func_00133810()
{
    if (!D_00785528[0]) {
        if (!__ti21cCollisionScrollSolid[0])
            func_0031EEC8(__ti21cCollisionScrollSolid, D_0041D5D0);
        func_0031EEA8(D_00785528, D_0041D5E8, __ti21cCollisionScrollSolid);
    }
    return D_00785528;
}

// FUNCTION: GAME 0x133888
extern "C" int *func_00133888()
{
    if (!D_00785538[0]) {
        if (!__ti21cCollisionScrollSolid[0])
            func_0031EEC8(__ti21cCollisionScrollSolid, D_0041D5D0);
        func_0031EEA8(D_00785538, D_0041D600, __ti21cCollisionScrollSolid);
    }
    return D_00785538;
}

// FUNCTION: GAME 0x1343A8
extern "C" int *func_001343A8()
{
    if (!D_00785568[0]) {
        if (!__ti15cCollisionSolid[0])
            func_0031EEC8(__ti15cCollisionSolid, D_0041D830);
        func_0031EEA8(D_00785568, D_0041D880, __ti15cCollisionSolid);
    }
    return D_00785568;
}

extern "C" int func_00135EC8(void *, void *, void *, void *, float *);
extern "C" int func_001361A0(void *, float *);

// FUNCTION: GAME 0x1365B8
extern "C" int func_001365B8(void *a, void *b, void *c, void *d, float *e)
{
    float t[4];
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(t) : "memory");
    if (!func_00135EC8(a, b, d, c, t))
        return 0;
    if (!func_001361A0(c, t))
        return 0;
    if (e && e != t) {
        e[0] = t[0];
        e[1] = t[1];
        e[2] = t[2];
    }
    return 1;
}

static inline int IsSet(const int &v) { return v != 0; }
static inline int Gt(const int &v, int n) { return v > n; }

// FUNCTION: GAME 0x12CA60
extern "C" int func_0012CA60(char *self)
{
    int *o;
    if (*(unsigned *)(self + 0x15F4) & 0x200000)
        return 1;
    if (IsSet(*(unsigned char *)(self + 0x2B4)))
        o = **(int ***)(self + 0x278);
    else
        o = 0;
    if (o == 0)
        return 0;
    {
        float *a = *(float **)(self + 0xF0);
        float *b = *(float **)((char *)o + 0xF0);
        if (b[1] < a[1] + 0.8f)
            return 1;
    }
    return 0;
}

extern char CamManager[];
extern "C" void setPartsCamera__11cCamManagerUc(void *, unsigned char);
extern "C" void SetParts__12cPartsCameraP6cPartsN21(void *, void *, void *, void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x124EC0
// diff: IsSet/Gt idiom matches the stack stores; only s0/s1 are swapped (self vs CamManager, 29 words)
extern "C" void func_00124EC0(char *self)
{
    void *a, *b;
    char *cm = CamManager;
    setPartsCamera__11cCamManagerUc(cm, 0);
    if (Gt(*(unsigned char *)(self + 0x2B4), 0x1B))
        a = *(void **)(*(char **)(self + 0x278) + 0x6C);
    else
        a = 0;
    if (Gt(*(unsigned char *)(self + 0x2B4), 0x1C))
        b = *(void **)(*(char **)(self + 0x278) + 0x70);
    else
        b = 0;
    SetParts__12cPartsCameraP6cPartsN21(cm + 0x920, self, a, b);
    *(unsigned *)(self + 0x15F4) |= 2;
}
#endif

extern unsigned D_00747A78;

static inline char *Tgt(char *self)
{
    if (Gt(*(unsigned char *)(self + 0x2B4), 1))
        return *(char **)(*(char **)(self + 0x278) + 4);
    return 0;
}

// FUNCTION: GAME 0x1BF2F0
extern "C" void func_001BF2F0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0:
    {
        if (Tgt(self)) {
            *(float *)(Tgt(self) + 0x100) += 0.17453292f;
            if (*(float *)(Tgt(self) + 0x100) > 0.0f) {
                *(int *)(Tgt(self) + 0x100) = 0;
                (*(unsigned char *)(self + 0x2F5))++;
            }
        }
    }
        break;
    case 1:
        D_00747A78 &= 0xFDFFFFFF;
        self[0x2F4] = 0;
        self[0x2F5] = 0;
        *(int *)(self + 0x600) &= -2;
        break;
    }
}
