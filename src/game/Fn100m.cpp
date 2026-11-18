// Player-family state functions in 0x100000-0x120000, over raw offsets.
#include "game/cEm00StateDecls.h"
#include "game/cVec.h"

extern "C" {
void func_00124E58(void *);
void func_00124E68(void *, float);
void func_001268F0(void *);
void func_00126770(void *);
void func_0012A8D8(void *);
int func_00123938(void *, int);
void func_0010A408(void *, int, int, int, int, int);
void func_0010A420(void *, int, int, int, int, int);
void func_0010A438(void *);
void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
}

struct cFn100mSnd {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cFn100mSnd Snd;

// DRAFT: GAME 0x114CB8 - addu s1/s0 placement vs addiu a2,0x29 / daddu a3,s2 arg setup (5 words)
#ifdef NONMATCHING
extern "C" void func_00114CB8(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_001268F0(self);
        func_00124E58(self);
        func_00126770(self);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        int t = *(int *)(self + 0x304);
        int a = *(int *)(t + 0x3D8) + t;
        int b = *(int *)(t + 0x3DC) + t;
        Snd.SeCall(0, 0x29, self, 0, 0, 0, 0);
        func_002A8578(self, a, b, 3, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        func_00124E68(self, 0.19634955f);
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (*(int *)(self + 0x698) == 0)
            func_0012A8D8(self);
    }
    func_00123938(self, 1);
}
#endif

extern float D_003BD48C;

// FUNCTION: GAME 0x10CC58
extern "C" void func_0010CC58(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        int t = *(int *)(self + 0x304);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_002A8578(self, *(int *)(t + 0x220) + t, *(int *)(t + 0x278) + t, 3, 0.0f, 0, 0);
        *(int *)(self + 0x15B0) = 16;
        B(0x2F6)++;
    }
    case 1: {
        *(float *)(self + 0x15F0) = D_003BD48C;
        int c = *(int *)(self + 0x15B0);
        if (c) {
            *(int *)(self + 0x15B0) = c - 1;
            func_00124E68(self, 0.19634955f);
        }
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
    }
    }
    func_00123938(self, 1);
}

// FUNCTION: GAME 0x1142E0
extern "C" void func_001142E0(char *self)
{
    *(float *)(self + 0x54C) = 15.0f;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00124E58(self);
        int t = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x18) + t, *(int *)(t + 0x1C) + t, 3, 0.0f, 0, 0);
        func_0010A408(self, 5, 0x17, 0x2A, 0, 10);
        func_0010A420(self, 5, 0x17, 0x2A, 0, 10);
        *(char *)(self + 0x1684) = 1;
        *(unsigned short *)(self + 0x3AC) |= 1;
        func_0010A438(self);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) { B(0x2F4)=0; B(0x2F5)=0; B(0x2F6)=0; B(0x2F7)=0; }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (!func_00123938(self, 1)) {
        if (*(unsigned short *)(self + 0x3AC) & 1)
            *(int *)(self + 0x15F4) = (*(int *)(self + 0x15F4) & ~0x10) | 0x20;
        *(unsigned short *)(self + 0x3AC) |= 0x800;
        *(float *)(self + 0x674) = 0.05f;
    }
}

enum eEffDataType { };
enum eEffId { };
class cObj;
class cVec;
extern void SetEffectPos(eEffDataType, eEffId, cObj *, const cVec &, float, int);

// DRAFT: GAME 0x10BD28 - 4<n compiles to sltiu not slt with preloaded 4; sw of n ordering (~12 words)
#ifdef NONMATCHING
extern "C" void SetCannonDamage__4pl00(char *self)
{
    if (*(short *)(self + 0x54A) > 0) {
        unsigned char n = B(0x2B4);
        volatile int d = n;
        char *p = 0;
        if (4 < n)
            p = *(char **)(*(char **)(self + 0x278) + 0x10);
        if (p)
            SetEffectPos((eEffDataType)0, (eEffId)3, 0, **(cVec **)(p + 0xF0), 1.0f, -1);
        Snd.SeCall(0, 0x123, self, 0, 0, 0, 0);
        int h = *(unsigned short *)(self + 0x54A) - 10;
        *(short *)(self + 0x54A) = h;
        if ((h << 16) <= 0) {
            B(0x2F7) = 1;
            B(0x2F4) = 2;
            *(short *)(self + 0x54A) = 0;
            B(0x2F5) = 1;
            B(0x2F6) = 0;
        } else {
            B(0x2F4) = 6;
            B(0x2F6) = 4;
            B(0x2F7) = 0;
            B(0x2F5) = 0;
        }
    }
}
#endif

// FUNCTION: GAME 0x102EE0
extern "C" void func_00102EE0(char *self)
{
    char *pl = (char *)Getplayer();
    g_CollSolidManage.SetActive((cGameObj *)self, false);
    *(int *)(self + 0x250) |= 2;
    *(float *)(self + 0x54C) = 2.0f;
    switch (B(0x2F6)) {
    case 0: {
        int t = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0xC) + t, *(int *)(t + 0x10) + t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        *(cVec *)(*(char **)(self + 0xF0)) = **(cVec **)(pl + 0xF0);
        *(cVec *)(self + 0x100) = *(cVec *)(pl + 0x100);
        moveMotion((cObjBase *)self);
    }
}
