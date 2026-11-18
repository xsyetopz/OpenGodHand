// Small unnamed functions in 0x2E0000-0x2EFFFF, placed next to ESLib.
#ifndef GAME_ESLIBFN_H
#define GAME_ESLIBFN_H

// Objects are local structs: a vtable pointer sits at 0xF0.

struct cObj;
void ReleaseObj(cObj *obj);

struct EsObj {
    char pad0[0xF0];
    const void *vt;
};
struct EsObjB2 : EsObj {
    char pad1[0x2B0 - 0xF4];
    cObj *m_obj;
};

extern "C" {
void func_002DF950(int, int);
void func_002FBE28(EsObj *, ...);
EsObj *func_002FBCC8(EsObj *);
void func_002FBED0(EsObj *);
void func_002FEB18(EsObj *);
void func_002EBC50(EsObj *, int);
void func_00300148();
void func_0031EEA8(void *, const void *, const void *);
}

#define VT_SET(addr, vtsym, callee)                         \
    extern "C" const char vtsym[];                          \
    extern "C" void func_00##addr(EsObj *self)              \
    {                                                       \
        self->vt = vtsym;                                   \
        callee(self);                                       \
    }

#define VT_AFTER(addr, vtsym)                               \
    extern "C" const char vtsym[];                          \
    extern "C" EsObj *func_00##addr(EsObj *self)            \
    {                                                       \
        func_002FBCC8(self);                                \
        self->vt = vtsym;                                   \
        return self;                                        \
    }

#define TAIL(addr, callee)                                  \
    extern "C" void func_00##addr(EsObj *self)              \
    {                                                       \
        callee(self);                                       \
    }

#define SINGLETON(addr, obj, vtsym, init)                   \
    extern "C" int obj[];                                   \
    extern "C" const char vtsym[];                          \
    extern "C" const char D_007863C8[];                     \
    extern "C" void *func_00##addr()                        \
    {                                                       \
        if (obj[0] == 0) {                                  \
            init();                                         \
            func_0031EEA8(obj, vtsym, D_007863C8);          \
        }                                                   \
        return obj;                                         \
    }

extern "C" unsigned char D_0061B289;
extern "C" int DISPLAY_H;

struct EsObjSrc {
    char pad[0x13C];
    float f13C, f140, f144, f148;
    char pad2[0x16C - 0x14C];
    int i16C;
};
struct EsObjCopy {
    char pad[0x110];
    EsObjSrc *src;
    char pad2[0x2B0 - 0x114];
    float f2B0, f2B4, f2B8, f2BC;
    int i2C0;
};
struct EsObjFlag {
    char pad[0x11C];
    unsigned int flags;
    char pad2[0x2CB - 0x120];
    unsigned char b2CB;
};
struct ESLib {
    static float ESHermite(float t, float p0, float p1, float m0, float m1);
    static float ESCatMullRom(float t, float p0, float p1, float p2, float p3);
};
struct CatMat {
    float m[16];
};
extern "C" void sceVu0ApplyMatrix(float *, CatMat *, float *);
extern "C" const CatMat D_0044E050;

struct EsObjInit : EsObj {
    char pad1[0x2B0 - 0xF4];
    int i2B0, i2B4, i2B8, i2BC, i2C0, i2C4, i2C8;
    char pad2[0x2D4 - 0x2CC];
    float f2D4;
    int i2D8, i2DC;
    char pad3[0x30C - 0x2E0];
    int i30C;
    char pad4[0x324 - 0x310];
    int i324;
    char pad5[0x330 - 0x328];
    int i330, i334, i338, i33C;
};
struct EsFlagObj {
    char pad[0x250];
    unsigned int flags;
};
struct EsFlagCopy {
    char pad[0x114];
    EsFlagObj *src;
    char pad2[0x2B0 - 0x118];
    EsFlagObj *dst;
};

extern "C" int DISPLAY_W;
extern "C" unsigned char D_0061B288;
extern "C" char D_0061B298[];

struct cHeap {
    void free(void *);
};
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
struct EsGlobal {
    char pad[8];
    unsigned char b8, b9;
    unsigned short sA;
    char pad2[0x14 - 0xC];
    void *p14;
};
extern "C" EsGlobal D_0061B280;
extern "C" cHeap D_00754200;
extern "C" unsigned int D_00747A34;
extern "C" char D_00580D40[];
extern "C" const char D_0044E030[];
extern "C" const char D_0044E040[];
extern "C" void func_001FFD00(const char *, const char *);

// ---- medium units ----
struct EsSrcA {
    char pad[0x13C];
    float f13C, f140, f144;
    char pad1[0x150 - 0x148];
    float f150;
    char pad2[0x16C - 0x154];
    unsigned char b16C;
    char pad3[0x170 - 0x16D];
    unsigned char b170;
};
struct EsObjA {
    char pad[0x110];
    EsSrcA *src;
    char pad0[0x11C - 0x114];
    unsigned int flags;
    char pad1[0x2B0 - 0x120];
    float f2B0, f2B4, f2B8, f2BC;
    char pad2[0x2C8 - 0x2C0];
    float f2C8;
    unsigned char b2CC;
    char pad3;
    unsigned char b2CE;
    char pad4;
    float f2D0;
};

extern "C" unsigned char D_0061B644;

struct EsSrcB {
    char pad[0x16C];
    int i16C;
    unsigned char b170;
    char pad1[0x18C - 0x171];
    signed char b18C;
    unsigned char b18D, b18E, b18F, b190;
};

struct EsParamB {
    char pad[0x40];
    float f40;
};

struct EsObjB {
    char pad[0x110];
    EsSrcB *src;
    char pad0[0x2B0 - 0x114];
    int i2B0, i2B4, i2B8;
    unsigned short s2BC;
    unsigned char b2BE, b2BF, b2C0;
    char pad1[0x2C4 - 0x2C1];
    float f2C4;
};

struct EsObjC : EsObj {
    char pad1[0x2D8 - 0xF4];
    float f2D8, f2DC;
};

#define FREE_BLOCK(p) \
    if (p)            \
    (*(cHeap **)((char *)(p) - 0x20))->free(p)

struct EsObjD : EsObj {
    char pad1[0x2BC - 0xF4];
    void *p2BC, *p2C0, *p2C4, *p2C8, *p2CC, *p2D0;
};

extern "C" const char D_0044E960[];

struct EsObjE : EsObj {
    char pad1[0x30C - 0xF4];
    void *p30C;
    char pad2[0x324 - 0x310];
    void *p324;
    char pad3[0x330 - 0x328];
    void *p330, *p334, *p338, *p33C;
};

extern "C" int D_0061B540[];

struct EsObjF {
    char pad[0x2BC];
    unsigned int n;
};

extern "C" void func_002E2C50(EsObj *);
extern "C" void func_002E2D40(EsObj *);
extern "C" void func_002E2E00(EsObj *);
extern "C" void func_002FBE50(EsObj *);

struct EsObjG : EsObj {
    char pad1[0x24C - 0xF4];
    unsigned char b24C;
    char pad2[0x2C4 - 0x24D];
    int i2C4;
    char pad3[0x2CC - 0x2C8];
    unsigned int flags;
    char pad4[0x2D5 - 0x2D0];
    unsigned char b2D5;
};

struct EsObjJ : EsObj {
    char pad1[0x2B8 - 0xF4];
    float f2B8, f2BC, f2C0, f2C4;
};

struct EsSrcK {
    char pad[0x13C];
    float f13C, f140;
    char pad1[0x18C - 0x144];
    signed char b18C, b18D, b18E;
    unsigned char b18F;
};

struct EsObjK {
    char pad[0x110];
    EsSrcK *src;
    char pad1[0x2B0 - 0x114];
    float f2B0, f2B4;
    int i2B8, i2BC;
    float f2C0, f2C4;
    int i2C8, i2CC;
};

extern "C" void func_002D9F68(void *, const char *);
extern "C" const char D_0044E808[];

extern "C" void func_002E9808(void *, int, int, int);
extern "C" void func_002E8B38(void *, int, int);
extern "C" void func_002E83D8(int, int, int, int, int);
extern "C" void func_002E8EE8(void *, int, int, int);

struct EsObjL {
    char pad[0x11C];
    unsigned int flags;
};

// ---- destructor clones: store vptr, then `if (f & 1) delete` ----
extern "C" void func_0030F5A0(void *);

#define DTOR_CLONE(name, vtsym, off)                        \
    extern "C" char vtsym[];                                \
    extern "C" void name(char *p, int f)                    \
    {                                                       \
        *(char **)(p + off) = vtsym;                        \
        if (f & 1)                                          \
            func_0030F5A0(p);                               \
    }

#define CALL1_EBC50(s) ((void (*)(EsObj *))func_002EBC50)(s)

#endif
