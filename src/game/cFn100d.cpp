#include "cFn100Decl.h"

// FUNCTION: GAME 0x138F40
extern "C" void func_00138F40(char *self)
{
    int a = *(int *)(self + 0x1028);
    if (a != 0x10) {
        char *v = *(char **)(self + 0xFF0);
        char *old = pCamWork;
        if (v == 0) {
            *(int *)(self + 0x1028) = 1;
            pCamWork = self;
        } else {
            *(int *)(self + 0x1028) = *(int *)(self + 0x102C);
            pCamWork = v;
        }
        *(int *)(self + 0x102C) = a;
        *(char **)(self + 0xFF0) = old;
    }
}

extern "C" void func_001344A0(char *);
extern "C" void func_0030F5A0(void *);

// FUNCTION: GAME 0x134458
extern "C" void func_00134458(char *self, int flag)
{
    func_001344A0(self);
    if (flag & 1)
        func_0030F5A0(self);
}

extern "C" void *func_0012B328(void *);
extern "C" void SetParent__8cOmThrowP8cGameObj(void *, void *);
extern "C" void *Getplayer__Fv(void);
extern "C" void func_00139FF8(void *);
extern "C" void func_0013AD90(void *);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(void *, void *);
extern "C" void _$_7cPlBase(char *, int);
extern const char D_0041D220[];
extern char g_CollSolidManage[];

// FUNCTION: GAME 0x137A48
extern "C" void *func_00137A48(char *self)
{
    *(int *)self = 0;
    *(int *)(self + 0x30) = 0;
    memset(self + 4, 0, 0x2C);
    *(float *)(self + 0x1C) = 1.06f;
    return self;
}

// FUNCTION: GAME 0x13DA98
extern "C" void func_0013DA98(char *self)
{
    if (*(unsigned *)(*(char **)(self + 0x94) + 0x2C) & 0x400) {
        move__7cIDBase(self);
        *(unsigned short *)(self + 0x92) = *(unsigned short *)(self + 0x92) + 1;
    }
}

// FUNCTION: GAME 0x107EC8
extern "C" void func_00107EC8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_0041D220;
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
    _$_7cPlBase(self, flag);
}

// FUNCTION: GAME 0x12B5C0
extern "C" void func_0012B5C0(char *self)
{
    int t = *(int *)(self + 0x6A4);
    if (t)
        *(int *)(self + 0x6A0) = t;
    if (*(int *)(self + 0x6A0) == 0) {
        void *v = func_0012B328(self);
        *(void **)(self + 0x6A0) = v;
        if (v == 0)
            return;
    }
    SetParent__8cOmThrowP8cGameObj(*(void **)(self + 0x6A0), self);
}

// FUNCTION: GAME 0x139FA8
extern "C" void func_00139FA8(void *self)
{
    char *p = (char *)Getplayer__Fv();
    if (*(int *)(p + 0x5D8) != 4)
        func_00139FF8(self);
    else
        func_0013AD90(self);
}

extern "C" void _$_8cGameObj(void *, int);
extern "C" void func_00137F38(void *, void *);
extern "C" void release__7cIDBase(void *);

// FUNCTION: GAME 0x1002C0
extern "C" void _$_7cPlBase(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_0041B598;
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
    _$_8cGameObj(self, flag);
}

// FUNCTION: GAME 0x13C5C8
extern "C" void func_0013C5C8(char *self)
{
    *(int *)(self + 0x50) = 0;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x5C) = 0;
    *(int *)(self + 0x60) = 0;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x6C) = 0;
    *(short *)(self + 0x70) = 0;
    *(short *)(self + 0x72) = 0;
    self[0x74] = 0;
    self[0x75] = 0;
    self[0x76] = 0;
    self[0x77] = 0;
    self[0x78] = 0;
    self[0x79] = 0;
    self[0x7A] = 0;
    self[0x7B] = 0;
    self[0x7C] = 0;
}

// FUNCTION: GAME 0x138FC8
extern "C" void func_00138FC8(char *self)
{
    func_00137F38(self + 0xFF4, self);
    if ((*(unsigned *)(self + 0x1028) & 4) == 0)
        move__7cCamera(pCamWork);
}

// FUNCTION: GAME 0x13E908
extern "C" void func_0013E908(char *self)
{
    if (*(int *)(self + 0x94)) {
        release__7cIDBase(self);
        *(int *)(self + 0x94) = 0;
        *(float *)(self + 0xA4) = 1.0f;
        *(int *)(self + 0x9C) = 0;
        *(int *)(self + 0xA0) = 0;
    }
    *(float *)(self + 0xA4) = 1.0f;
    *(int *)(self + 0x94) = 0;
    *(int *)(self + 0x9C) = 0;
    *(int *)(self + 0xA0) = 0;
}

// FUNCTION: GAME 0x12ECF0
extern "C" void func_0012ECF0(void *vself)
{
    char *self = (char *)vself;
    if (*(int *)(self + 0x190)) {
        char *nx;
        do {
            char *a = *(char **)(self + 0x190);
            nx = *(char **)a;
            if (a) {
                char *vt = *(char **)(a + 0x5C);
                ((void (*)(char *, int))*(void **)(vt + 0xC))(a + *(short *)(vt + 8), 3);
            }
            *(char **)(self + 0x190) = nx;
            *(int *)(self + 0x194) = *(int *)(self + 0x194) - 1;
        } while (nx);
    }
}

extern "C" void restartAnim__7cIDBase(void *);
extern "C" int getIDWork__7cIDBasei(void *, int);
extern unsigned int D_00747A84;

// FUNCTION: GAME 0x13F150
extern "C" void func_0013F150(char *self)
{
    unsigned short i = 0;
    char *p = self + 0x90;
    restartAnim__7cIDBase(self);
    self[0x1C] = 1;
    do {
        *(int *)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 3);
}

// FUNCTION: GAME 0x13E380
extern "C" void func_0013E380(char *self)
{
    unsigned short i;
    char *p = self + 0x9C;
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 0x1F);
    i = 0;
    do {
        *(int *)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 2);
    *(int *)(self + 0x90) = 0;
}
