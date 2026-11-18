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

#ifdef NONMATCHING
extern char g_EmManage[];
extern "C" void ReleaseEm__9cEmManageP7cEmBase(void *, void *);
extern "C" void func_0028FB08(void *);

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
    int m = 0;
    if (*(unsigned char *)(self + 0x15B0) != 0)
        m = 2;
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
