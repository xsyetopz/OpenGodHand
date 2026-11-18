#include "game/cVec.h"

extern "C" void getScreenPos__C7cCameraRC4cVec(cVec *, void *, cVec *);
extern "C" void SetLocalPosXY__12CustomIDWorkii(char *, int, int);
extern "C" void func_001ED700(char *, int, int);
extern void *pCamWork;

// FUNCTION: GAME 0x1EDD90
extern "C" void func_001EDD90(char *self, cVec *p, int a)
{
    void *cam = pCamWork;
    if (cam) {
        cVec s;
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(s));
        cVec t;
        getScreenPos__C7cCameraRC4cVec(&t, cam, p);
        s = t;
        SetLocalPosXY__12CustomIDWorkii(self + 0x2CC, (int)s.x, (int)s.y);
        func_001ED700(self, 5, a);
    }
}

struct V4 : cVec {
    float w;
};
extern "C" void func_0031A0B8(void *, int);
extern "C" void func_0031A088(void *, int);

// FUNCTION: GAME 0x1E8F78
extern "C" void func_001E8F78(char *self, float f)
{
    char *o = *(char **)self;
    if (o) {
        *(float *)(self + 0xB8) = f;
        V4 v;
        v.x = f;
        v.y = 0.0f;
        v.z = 0.0f;
        v.w = 1.0f;
        *(cVec *)(o + 0x340) = v;
        func_0031A0B8(o, 3);
        if (v.x == 0.0f && v.y == 0.0f && v.z == 0.0f)
            return;
        func_0031A088(o, 3);
    }
}

extern "C" void SetMessNo__12CustomIDWorki(char *, int);
extern "C" void SetLocalPosY__12CustomIDWorki(char *, int);
struct A5 {
    int v[5];
};
extern A5 D_0042BDC0;

// FUNCTION: GAME 0x1EE5F0
extern "C" void func_001EE5F0(char *self, unsigned char a, unsigned char b, int msg)
{
    if (a < 5 && b < 5) {
        SetMessNo__12CustomIDWorki(self + (a * 0x7C + 0x630), msg);
        SetMessNo__12CustomIDWorki(self + (a * 0x7C + 0xB84), msg);
        A5 tbl;
        tbl = D_0042BDC0;
        SetLocalPosY__12CustomIDWorki(self + (b * 0x7C + 0x348), tbl.v[a]);
    }
}

extern "C" void BgmEventFade__4cSnd9eBgmReqNofff(void *, int, float, float, float);
extern "C" void displayScrollLayer__FUib(unsigned, int);
extern "C" void func_00143A90(char *);
extern char Snd[];
extern char *Cockpit;

// FUNCTION: GAME 0x1EB648
extern "C" void func_001EB648(char *self)
{
    if (*(int *)(self + 8) == 0) {
        float a = 15.0f;
        float b = 0.0f;
        float c = -1.0f;
        BgmEventFade__4cSnd9eBgmReqNofff(Snd, 0x25, a, b, c);
        BgmEventFade__4cSnd9eBgmReqNofff(Snd, 0x24, a, b, c);
        displayScrollLayer__FUib(1, 0);
        func_00143A90(Cockpit + 0x1AE0);
        *(unsigned *)(self + 0x54) |= 1;
        *(int *)(self + 8) += 1;
    }
}
