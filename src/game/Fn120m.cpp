// Misc units in 0x120000-0x140000 over raw offsets.
#include "game/cVec.h"

// DRAFT: GAME 0x138CA8 - 7 words: loop end pointer/temp register allocation (e in a0, x/y in v0/v1 vs target e=v0, x=v1, y=a0)
#ifdef NONMATCHING
extern "C" void func_00138CA8(void *self, char *dst, char *src, unsigned char f)
{
    if (f & 1)
        *(cVec *)(dst + 0x210) = *(cVec *)(src + 0x210);
    if (f & 2)
        *(cVec *)(dst + 0x200) = *(cVec *)(src + 0x200);
    if (f & 8) {
        typedef int Q __attribute__((mode(TI)));
        Q *d = (Q *)dst, *s = (Q *)src;
        do {
            d[0] = s[0];
            d[1] = s[1];
            s += 2;
            d += 2;
        } while ((char *)s != src + 0x360);
    }
}
#endif

extern "C" void __15cCollisionSolid(void *);
extern const char D_0041D7E0[];

// FUNCTION: GAME 0x1339F0
extern "C" char *func_001339F0(char *self, int a, cVec *p, float r)
{
    __15cCollisionSolid(self);
    cVec *q = (cVec *)(self + 0x50);
    *(int *)(self + 0x40) = a;
    *(const void **)(self + 0x30) = D_0041D7E0;
    __asm__ volatile("sqc2 $vf0,0x50(%0)" : : "r"(self) : "memory");
    __asm__ volatile("sqc2 $vf0,0x60(%0)" : : "r"(self) : "memory");
    *(int *)(self + 4) = 1;
    *q = *p;
    *(float *)(self + 0x70) = r;
    return self;
}

struct Lnk {
    Lnk *next;
};

// FUNCTION: GAME 0x12EC58
extern "C" void func_0012EC58(char *self, Lnk *item)
{
    Lnk *cur = *(Lnk **)(self + 0x190);
    Lnk *prev = 0;
    if (cur) {
        if (item != cur) {
            prev = cur;
            while ((cur = cur->next) != 0 && item != cur)
                prev = cur;
        }
        if (cur) {
            if (cur != *(Lnk **)(self + 0x190))
                prev->next = cur->next;
            else
                *(Lnk **)(self + 0x190) = cur->next;
            if (cur) {
                char *vt = *(char **)((char *)cur + 0x5C);
                ((void (*)(char *, int))(*(int *)(vt + 0xC)))((char *)cur + *(short *)(vt + 8), 3);
            }
            *(int *)(self + 0x194) -= 1;
        }
    }
}

extern "C" void func_001344A0(void *);
extern "C" void func_00134458(void *, int);

// FUNCTION: GAME 0x1347E8
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(char *self, void *obj)
{
    char *prev = 0;
    if (obj) {
        char *head = *(char **)self;
        char *cur = head;
        while (cur) {
            if (*(void **)cur == obj)
                break;
            prev = cur;
            cur = *(char **)(cur + 0x10);
        }
        if (cur) {
            if (cur != head)
                *(int *)(prev + 0x10) = *(int *)(cur + 0x10);
            else
                *(int *)self = *(int *)(cur + 0x10);
            func_001344A0(cur);
            if (cur)
                func_00134458(cur, 3);
            *(int *)(self + 4) -= 1;
        }
    }
}

extern "C" void trans__7cIDBase(void *);

// FUNCTION: GAME 0x13E260
extern "C" void func_0013E260(char *self)
{
    unsigned short i = 0;
    int none = -1;
    char *base = self + 0x33C;
    int step = 0x50;
    do {
        char *p = base + i;
        if (*p != none) {
            trans__7cIDBase(self + (i * step + 0x90));
            if (*p >= 0x24)
                *p = none;
        }
        i++;
    } while (i < 8);
}

extern "C" void _$_12CustomIDWork(void *, int);
extern "C" void func_0030F5A0(void *);
extern const char D_0041DCC8[];

// DRAFT: GAME 0x13DE90 - 19 words: target has self in s1, first in v0->s2; ours swaps s1/s2 and lui s3/s4 order (tried for(;;) break form, p/first decl order, me alias)
#ifdef NONMATCHING
extern "C" void func_0013DE90(char *self, unsigned f)
{
    struct W { char x[0x7C]; };
    W *first = (W *)(self + 0x120);
    if (first) {
        W *p = (W *)(self + 0x38C);
        if (first != p) {
            p--;
            for (;;) {
                _$_12CustomIDWork(p, 0);
                if (first == p)
                    break;
                p--;
            }
        }
    }
    *(const void **)(self + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(self);
}
#endif

#include "game/cEm00StateDecls.h"
extern "C" {
void func_0012AC28(void *);
void func_0012B928(void *);
void func_00124EC0(void *);
void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
void SetPlCatched__9cEmManage(void *);
void SetSlotWait__9cEmManagei(void *, int);
void GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(void *, int, float, float);
}
extern char g_EmManage[];

// FUNCTION: GAME 0x122A50
extern "C" void func_00122A50(char *self)
{
    char *em = *(char **)(self + 0x694);
    *(float *)(self + 0x54C) = 5.0f;
    g_CollSolidManage.SetActive((cGameObj *)self, false);
    SetPlCatched__9cEmManage(g_EmManage);
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    *(int *)(self + 0x15F4) |= 0x80000;
    switch (B(0x2F6)) {
    case 0:
        func_0012AC28(self);
        func_0012B928(self);
        if (em) {
            *(cVec *)(*(char **)(em + 0xF0)) = **(cVec **)(self + 0xF0);
            *(float *)(em + 0x104) = *(float *)(self + 0x104);
        }
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x54, 0.0f, 0.0f);
        B(0x2F6)++;
        goto c1;
    case 2:
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x55, 0.0f, 0.0f);
        B(0x2F6)++;
        goto c1;
    case 4:
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x56, 0.0f, 0.0f);
        B(0x2F6)++;
        goto c1;
    case 1:
    case 3:
    case 5:
    c1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self))
            B(0x2F6)++;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        break;
    case 6:
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x57, 0.0f, 0.0f);
        B(0x2F6)++;
    case 7:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        break;
    }
}
