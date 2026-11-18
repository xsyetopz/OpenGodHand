// Misc units in 0x120000-0x130000 over raw offsets.
#include "game/cCoreSave.h"
#include "game/cEm00StateDecls.h"

struct Qv120 { float v[4] __attribute__((aligned(16))); };
extern "C" {
void func_00124E58(void *);
void func_0012AC28(void *);
void func_0012B928(char *);
void func_001269E0(void *, unsigned, int);
void SetFall__8cOmThrow(void *);
void func_001C8D48(void *);
}
extern int pl_skill_power_tbl[][5];

class cPmf120 {
public:
    virtual void f();
};
extern "C" void (cPmf120::*D_003BD458[])();

// FUNCTION: GAME 0x122C48
extern "C" void func_00122C48(cPmf120 *self)
{
    func_00124E58(self);
    func_0012AC28(self);
    func_0012B928((char *)self);
    if (!(B(0x2F5) < 2)) B(0x2F5) = 0;
    (self->*D_003BD458[B(0x2F5)])();
}

// FUNCTION: GAME 0x126918
extern "C" int func_00126918(char *self)
{
    if (!((int)*(unsigned short *)(self + 0x5E0) < CoreSave.getComboMax(*(unsigned short *)(self + 0x5E2)))) {
        *(unsigned short *)(self + 0x5E2) = 0;
        *(unsigned short *)(self + 0x5E0) = 0;
    }
    int c = CoreSave.getCombo(*(unsigned short *)(self + 0x5E2), *(unsigned short *)(self + 0x5E0));
    CoreSave.getComboLv(*(unsigned short *)(self + 0x5E2), *(unsigned short *)(self + 0x5E0));
    *(short *)(self + 0x5E4) = 0;
    *(short *)(self + 0x5E6) = 0;
    int w = pl_skill_power_tbl[c][0];
    *(int *)(self + 0x166C) = w;
    *(int *)(self + 0x1668) = w;
    func_001269E0(self, c, 0);
    *(unsigned short *)(self + 0x5E0) += 1;
    return c;
}

// FUNCTION: GAME 0x12B928
extern "C" void func_0012B928(char *self)
{
    if (*(char **)(self + 0x6A0)) {
        Qv120 q;
        asm volatile("sqc2 $vf0,%0" : "=m"(q));
        ((int *)q.v)[0] = 0;
        q.v[1] = 0.1f;
        ((int *)q.v)[2] = 0;
        SetFall__8cOmThrow(*(char **)(self + 0x6A0));
        asm volatile("" : : "m"(q));
        float *d = *(float **)(*(char **)(self + 0x6A0) + 0xF0);
        float *s = *(float **)(self + 0xF0);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
        (*(float **)(*(char **)(self + 0x6A0) + 0xF0))[1] += 1.6f;
        char *o = *(char **)(self + 0x6A0);
        float *e = (float *)(o + 0x490);
        float *p = *(float **)(o + 0xF0);
        if (e != p) { e[0] = p[0]; e[1] = p[1]; e[2] = p[2]; }
        *(int *)(self + 0x6A0) = 0;
    }
}

// FUNCTION: GAME 0x12B9F0
extern "C" void DiscardThrowObj__4pl00(char *self)
{
    if (*(char **)(self + 0x6A0)) {
        Qv120 q;
        asm volatile("sqc2 $vf0,%0" : "=m"(q));
        ((int *)q.v)[0] = 0;
        q.v[1] = 0.1f;
        ((int *)q.v)[2] = 0;
        func_001C8D48(*(char **)(self + 0x6A0));
        asm volatile("" : : "m"(q));
        float *d = *(float **)(*(char **)(self + 0x6A0) + 0xF0);
        float *s = *(float **)(self + 0xF0);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
        (*(float **)(*(char **)(self + 0x6A0) + 0xF0))[1] += 1.6f;
        char *o = *(char **)(self + 0x6A0);
        float *e = (float *)(o + 0x490);
        float *p = *(float **)(o + 0xF0);
        if (e != p) { e[0] = p[0]; e[1] = p[1]; e[2] = p[2]; }
        *(int *)(self + 0x6A0) = 0;
    }
}

extern "C" {
void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
void func_00126770(void *);
void func_002A8578(void *, int, int, int, float, int, int);
void calcParts__6cModel(void *);
void calcWorldParts__6cModel(void *);
void InverseKinematics__2IKP8cObjBase(void *, void *);
void func_001CF3A8(void *);
void SetHeatMode__8cHeatSysUc(void *, int);
void SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, int, int, unsigned);
void *func_002948C8(void *, unsigned);
int func_001B8640(void *);
float *func_001B8720(void *);
float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
}
extern char g_EmManage[];
extern char g_HeatSys[];

// FUNCTION: GAME 0x12A2E0
extern "C" float *func_0012A2E0(char *self)
{
    Qv120 q;
    asm volatile("sqc2 $vf0,%0" : "=m"(q));
    for (unsigned i = 0; i < 2; i++) {
        void *s = func_002948C8(g_EmManage, i);
        if (s && func_001B8640(s)) {
            float *v = func_001B8720(s);
            if (q.v != v) { q.v[0] = v[0]; q.v[1] = v[1]; q.v[2] = v[2]; }
            if (!(12.25f < capVu0MagnitudeSqXZ__FPCfT0(q.v, *(float **)(self + 0xF0))))
                return func_001B8720(s);
        }
    }
    return *(float **)(self + 0xF0);
}

// FUNCTION: GAME 0x12C418
extern "C" void reset__4pl00(char *self)
{
    clearMotionCam__4pl00UiUi(self, 0, 0);
    func_00126770(self);
    char *t = *(char **)(self + 0x304);
    B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
    func_002A8578(self, *(int *)(t + 0x28) + (int)t, *(int *)(t + 0x2C) + (int)t, 0, 0.0f, 0, 0);
    moveMotion((cObjBase *)self);
    calcParts__6cModel(self);
    InverseKinematics__2IKP8cObjBase(self + 0x448, self);
    calcWorldParts__6cModel(self);
    if (*(void **)(self + 0x6A8)) {
        func_001CF3A8(*(void **)(self + 0x6A8));
        calcParts__6cModel(*(void **)(self + 0x6A8));
    }
    *(int *)(self + 0x15F4) = (*(int *)(self + 0x15F4) & ~0x10) | 0x20;
    SetHeatMode__8cHeatSysUc(g_HeatSys, 0);
    *(int *)(self + 0x640) = 0;
}

// FUNCTION: GAME 0x12CC70
extern "C" void func_0012CC70(char *self)
{
    if (*(int *)(self + 0x644)) return;
    char *o = *(char **)(self + 0x640);
    if (o) {
        *(char **)(self + 0x644) = o;
        *(int *)(self + 0x15F4) |= 0x800000;
        if (*(int *)(o + 0x564) != 0x26A) {
            SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x61, o, 0, 6, 0xFFFFFFFF);
        } else {
            SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x79, o, 0, 6, 0xFFFFFFFF);
            char *p = *(char **)(self + 0x644);
            if (*(char **)(p + 0x748)) SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x79, *(char **)(p + 0x748), 0, 6, 0xFFFFFFFF);
            if (*(char **)(p + 0x74C)) SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x79, *(char **)(p + 0x74C), 0, 6, 0xFFFFFFFF);
            if (*(char **)(p + 0x750)) SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x79, *(char **)(p + 0x750), 0, 6, 0xFFFFFFFF);
        }
    }
}

struct cVObj120 { char pad[0x214]; };
class cVCall120 : public cVObj120 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(int);
};
extern "C" cVCall120 *GetJacket__Fv();

// FUNCTION: GAME 0x12C7D0
extern "C" void func_0012C7D0(char *self, int f)
{
    if (f == 1) *(unsigned *)(self + 0x250) |= 0x8000;
    else *(unsigned *)(self + 0x250) &= ~0x8000u;
    if (f == 1) *(int *)(self + 0x5A0) |= 8;
    else *(int *)(self + 0x5A0) &= ~8;
    if (GetJacket__Fv()) GetJacket__Fv()->v11(f);
    cVCall120 *o = *(cVCall120 **)(self + 0x698);
    if (o) o->v11(f);
    o = *(cVCall120 **)(self + 0x6A0);
    if (o) o->v11(f);
    o = *(cVCall120 **)(self + 0x6A8);
    if (o) o->v11(f);
}

extern "C" int func_002C2490(void *, void *, void *);
extern char g_SceAt[];

#ifdef NONMATCHING
// DRAFT: GAME 0x12CAE0 - ~20 words: original needs dsrl on the lw'd flag (sra/srl here) and a different early-exit layout (bc1tl to epilogue, v0=0 delay stubs)
extern "C" int func_0012CAE0(char *self)
{
    if (*(float *)(self + 0x15D0) > 0.0f) return 0;
    if (*(float *)(self + 0x54C) > 0.0f) return 0;
    if (((unsigned long)(int)D_00747A2C >> 3) & 1) return 0;
    int r = func_002C2490(g_SceAt, *(void **)(self + 0xF0), self + 0x15E0);
    if (r != 1) return 0;
    *(float *)(self + 0x15D0) = 90.0f;
    if (*((unsigned char *)&D_00747A2C + 0x25) == 5)
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x4B, self, 0, -1, 0xFFFFFFFF);
    if (*(short *)(self + 0x54A) >= 0xB) {
        short n = *(unsigned short *)(self + 0x54A) - 0x19;
        *(short *)(self + 0x54A) = n;
        if (n <= 0) *(short *)(self + 0x54A) = r;
    } else {
        *(short *)(self + 0x54A) = 0;
    }
    B(0x2F4) = 1; B(0x2F5) = 7; B(0x2F7) = 0; B(0x2F6) = 0;
    return 1;
}
#endif

struct cSnd120 {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cSnd120 Snd;
extern "C" void AddHeatGage__8cHeatSysfUi(void *, float, unsigned);
extern "C" void addGameLevelPoint__9cCoreSavei(void *, int);

// FUNCTION: GAME 0x129430
extern "C" void func_00129430(char *self)
{
    if (*(short *)(self + 0x1616) == 0) B(0x1615) = 0;
    *(short *)(self + 0x1616) = 0x2D;
    B(0x1615) = B(0x1615) + 1;
    if ((signed char)B(0x1615) == 5) {
        Snd.SeCall(0, 0x36, self, 0, 0, 0, 0);
        addGameLevelPoint__9cCoreSavei(&CoreSave, 100);
    }
    float f = 1.5f;
    if ((signed char)B(0x1615) >= 2) f = 0.5f;
    if (CoreSave.getGameLevel() == 5) f *= 0.5f;
    AddHeatGage__8cHeatSysfUi(g_HeatSys, f, 0);
    if ((signed char)B(0x1615) % 3 == 1) Snd.SeCall(0, 0xEE, self, 0, 0, 0, 0);
    addGameLevelPoint__9cCoreSavei(&CoreSave, 0x32);
}

class cVCall120b : public cVObj120 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7();
};
extern "C" {
void func_001FECE0(void *, int, int);
cVCall120b *CreateObj__F6eObjIdT0(int, int);
void sceVu0ApplyMatrix(float *, void *, float *);
}
extern char g_DataManager[];

#ifdef NONMATCHING
// DRAFT: GAME 0x129BA0 - ~49 words: target keeps q->w->c Qv copies (ldc2/sdc2) at sp+0x20/0x10 with 3 saved regs; gcc elides them (frame 0x60 vs 0x70)
extern "C" void func_00129BA0(char *self)
{
    char *t = *(char **)(self + 0x304);
    func_001FECE0(g_DataManager, 0x3BF, *(int *)(t + 0x310) + (int)t);
    cVCall120b *o = CreateObj__F6eObjIdT0(0x3BF, 0xFFFF);
    if (o) {
        Qv120 q;
        asm volatile("sqc2 $vf0,%0" : "=m"(q));
        q.v[1] = 3.0f;
        q.v[2] = -0.3f;
        q.v[0] = 0;
        o->v7();
        Qv120 w = q;
        sceVu0ApplyMatrix(w.v, self + 0x80, w.v);
        Qv120 c = w;
        float *d = *(float **)((char *)o + 0xF0);
        if (d != c.v) { d[0] = c.v[0]; d[1] = c.v[1]; d[2] = c.v[2]; }
        float *a = (float *)((char *)o + 0x100);
        float *b = (float *)(self + 0x100);
        if (a != b) { a[0] = b[0]; a[1] = b[1]; a[2] = b[2]; }
        *(float *)((char *)o + 0x108) = -0.17453292f;
        *(float *)((char *)o + 0x100) = -0.17453292f;
    }
}
#endif
