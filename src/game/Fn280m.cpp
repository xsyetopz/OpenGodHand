// Medium units in 0x280000-0x29FFFF.
extern "C" void func_001595E8(void *, int);
extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" int setupModel__6cModelPC10SCR_HEADERUibT3(void *, int, int, int, int);
extern const char D_00448588[], D_00448590[], D_00448778[], D_00448780[];

// FUNCTION: GAME 0x280B60
extern "C" int func_00280B60(char *self)
{
    func_001595E8(self, 0);
    int a = SearchData__FPUiPCcUi(*(void **)(self + 0x304), D_00448588, 0);
    int b = SearchData__FPUiPCcUi(*(void **)(self + 0x304), D_00448590, 0);
    if (b)
        return setupModel__6cModelPC10SCR_HEADERUibT3(self, a, b, 0, 0);
    return 0;
}

// FUNCTION: GAME 0x282EC0
extern "C" int func_00282EC0(char *self)
{
    func_001595E8(self, 0);
    int a = SearchData__FPUiPCcUi(*(void **)(self + 0x304), D_00448778, 0);
    int b = SearchData__FPUiPCcUi(*(void **)(self + 0x304), D_00448780, 0);
    if (b)
        return setupModel__6cModelPC10SCR_HEADERUibT3(self, a, b, 0, 0);
    return 0;
}

extern "C" void movePlayInit__6cEvent(void *);
extern "C" void movePlayQuit__6cEvent(void *);
extern "C" int func_00296DD8(void *);

// FUNCTION: GAME 0x296C28
extern "C" int func_00296C28(char *self)
{
    switch (self[5]) {
    case 0:
        movePlayInit__6cEvent(self);
        self[5]++;
    case 1:
        if (func_00296DD8(self)) {
            movePlayQuit__6cEvent(self);
            self[5] = 0;
            self[4] = 4;
            self[6] = 0;
            self[7] = 0;
            return 1;
        }
        return 0;
    }
    return 0;
}

extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void calcNullPart__6cModel(void *);
extern "C" void Add_nullspeed__FP8cObjBase(void *);

// FUNCTION: GAME 0x2884E0
extern "C" void func_002884E0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0xD8) + (int)t, *(int *)(t + 0xDC) + (int)t, 10, 0.0f, 0, 0);
        self[0x2F6]++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
        calcNullPart__6cModel(self);
        Add_nullspeed__FP8cObjBase(self);
    }
}

extern char g_EmManage[];
extern "C" int ReleaseEm__9cEmManageP7cEmBase(void *, void *);
extern "C" void func_0028FB08(void *);

extern "C" void *Getplayer__Fv();
extern "C" int func_0031ED08(float);

// FUNCTION: GAME 0x289610
extern "C" void func_00289610(char *self, float a, float b)
{
    void *p = Getplayer__Fv();
    char *t = *(char **)(self + 0x304);
    int x = *(int *)(t + 0x160) + (int)t;
    int y = *(int *)(t + 0x164) + (int)t;
    func_002A8578(p, x, y, func_0031ED08(a), b, 0, 0);
}

extern char g_CollSolidManage[];
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);

// FUNCTION: GAME 0x2880C8
extern "C" void func_002880C8(char *self)
{
    *(unsigned *)(self + 0x15B0) |= 0x10020;
    *(float *)(self + 0x54C) = 3.0f;
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x168) + (int)t, *(int *)(t + 0x16C) + (int)t, 3, 0.0f, 0, 0);
        self[0x2F6]++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

// FUNCTION: GAME 0x288C98
extern "C" void func_00288C98(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        func_0028FB08(self);
        self[0x2F6]++;
    case 1: {
        float f = *(float *)(self + 0x24C) - 0.1f;
        *(float *)(self + 0x24C) = f;
        if (f <= 0.0f) {
            *(float *)(self + 0x24C) = 0.0f;
            ReleaseEm__9cEmManageP7cEmBase(g_EmManage, self);
            self[0x2F6]++;
        }
    }
    }
}

// FUNCTION: GAME 0x28AB48
extern "C" void func_0028AB48(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        func_0028FB08(self);
        self[0x2F6]++;
    case 1: {
        float f = *(float *)(self + 0x24C) - 0.1f;
        *(float *)(self + 0x24C) = f;
        if (f <= 0.0f) {
            *(float *)(self + 0x24C) = 0.0f;
            ReleaseEm__9cEmManageP7cEmBase(g_EmManage, self);
            self[0x2F6]++;
        }
    }
    }
}

#ifdef NONMATCHING
extern char *g_Sce;
extern unsigned D_00747A84;
extern "C" void startSoftEvent__9cScenario14eSoftEventType(void *, int);
extern "C" int taskExec__9cScenarioPvT1i(void *, void *, void *, int);
extern "C" void func_0028E858(void *);

static inline void markTask(int id)
{
    if (id >= 0)
        *(unsigned char *)(*(char **)(g_Sce + 0x1C) + id * 0x58 + 0x50) |= 1;
}

// DRAFT: GAME 0x28E7C8
// diff: register numbering (s0/s1 swapped) and id copied to a0 before bltz
extern "C" void func_0028E7C8(void *self)
{
    startSoftEvent__9cScenario14eSoftEventType(g_Sce, 2);
    D_00747A84 &= 0xFFFEFFFF;
    markTask(taskExec__9cScenarioPvT1i(g_Sce, (void *)func_0028E858, self, 1));
}

struct Lnk {
    int pad;
    Lnk *next;
    char *obj;
};
struct VT {
    char pad[0x60];
    short off;
    short pad2;
    void (*fn)(void *, int);
};

static inline unsigned char inRange(int v)
{
    int r = 0;
    if (v >= 0x200)
        r = v < 0x300;
    return r;
}

// DRAFT: GAME 0x2948E8
// diff: range test compiles to movn select, original branches (a0=0 / slti 0x300) then andi 0xFF
extern "C" void func_002948E8(char *self, int arg)
{
    for (Lnk *n = *(Lnk **)(self + 0x500); n; n = n->next) {
        char *o = n->obj;
        if (o && inRange(*(unsigned short *)(o + 0x2FE))) {
            VT *vt = *(VT **)(o + 0x214);
            vt->fn(o + vt->off, arg);
        }
    }
}

// DRAFT: GAME 0x281D10
// diff: constant select emits movz (t0=2, movz zero) instead of movn (t0=0, movn 2)
extern "C" void func_00281D10(char *self)
{
    int m = *(unsigned char *)(self + 0x15B0) == 0 ? 0 : 2;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0xC) + (int)t, *(int *)(t + 0x10) + (int)t, 5, 0.0f, m, 0);
        self[0x2F6]++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

#endif
