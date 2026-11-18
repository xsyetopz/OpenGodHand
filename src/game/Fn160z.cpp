// Free functions in 0x160000-0x170000.

#include "game/cIDBase.h"

struct sIDInner1689 {
    char _pad0[0x50];
    int m_50;
    int m_54;
};
struct sIDSys1689 {
    sIDInner1689 *m_inner;
};
extern sIDSys1689 *IDSys;
extern char *Cockpit;
extern char CamManager[], World_light_work[];
extern "C" void func_001615F0(void *);
extern "C" void func_00161590(void *);
extern "C" void func_00143A90(void *);
extern "C" void initData__10cCockPlBar(void *);
extern "C" void func_00138F40(void *, int);
extern "C" void func_002D98A0(void *);
extern "C" void SubscreenMode__4pl00Ui(char *, unsigned);

struct sV3 {
    float x, y, z;
};

// FUNCTION: GAME 0x1689E8
extern "C" void func_001689E8(char *self)
{
    func_001615F0(self);
    func_00143A90(Cockpit + 0x1AE0);
    initData__10cCockPlBar(Cockpit + 0x460);
    func_00138F40(CamManager, 0);
    sV3 *d = (sV3 *)(*(char **)(self + 0x1D8) + 0x100);
    sV3 *s = (sV3 *)(self + 0x1F0);
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
    SubscreenMode__4pl00Ui(*(char **)(self + 0x1D8), 0);
    func_002D98A0(World_light_work);
    ((cIDBase *)(self + 0x210))->release();
    ((cIDBase *)(self + 0xD0))->release();
    ((cIDBase *)self)->release();
    sIDInner1689 *in = IDSys->m_inner;
    in->m_54 = 0;
    in->m_50 = 0;
    func_00161590(self);
}

extern float D_0041FE60[];
extern float D_0041FE78[];
// FUNCTION: GAME 0x169258
extern "C" void func_00169258(char *self)
{
    switch (self[0x5B]) {
    case 0:
        {
            char *p = *(char **)(self + 0x124);
            float f = D_0041FE60[0];
            *(short *)(self + 0x1D2) = 0;
            *(short *)(self + 0x1D0) = 0;
            *(float *)(p + 0x3C) = f;
        }
        self[0x5B] = 1;
        break;
    case 1:
        *(float *)(*(char **)(self + 0x124) + 0x3C) = D_0041FE60[*(short *)(self + 0x1D2)];
        break;
    case 2:
        *(short *)(*(char **)(self + 0x8C) + 0x90) = 0x2001;
        *(short *)(*(char **)(self + 0x90) + 0x90) = 0x2001;
        *(unsigned *)(*(char **)(self + 0x94) + 0x2C) &= 0xF7FFFFFF;
        *(unsigned *)(*(char **)(self + 0x98) + 0x2C) &= 0xF7FFFFFF;
        *(float *)(*(char **)(self + 0x94) + 0x38) = D_0041FE78[self[0x1D4]];
        break;
    case 4:
        if (*(unsigned char *)(self + 0x286) != 0) {
            self[0x5B] = 3;
        } else {
            self[0x5A] = 6;
        }
        break;
    }
}

// FUNCTION: GAME 0x160C48
extern "C" void func_00160C48(unsigned char *self)
{
    unsigned char st = self[0xED4];
    if (st == 0) {
        return;
    }
    if (st == 1) {
        return;
    }
    if (st == 2) {
        int n = *(int *)(self + 0xED8);
        *(unsigned *)(self + 0xED0) = (*(unsigned *)(self + 0xED0) & 0xFFFFFF) | ((int)((float)n * 0.25f * 128.0f) << 24);
        if (n == 4) {
            self[0xED4] = 0;
        }
    }
    if (self[0xED4] == 3) {
        int n = *(int *)(self + 0xED8);
        *(unsigned *)(self + 0xED0) = (*(unsigned *)(self + 0xED0) & 0xFFFFFF) | ((int)((1.0f - (float)n * 0.25f) * 128.0f) << 24);
        if (n == 4) {
            self[0xED4] = 1;
        }
    }
    *(int *)(self + 0xED8) += 1;
}

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
struct V4 {
    float x, y, z, w;
};
struct sScrDraw {
    char _p[0x28];
};
extern sScrDraw *ScrDraw;
extern "C" char *Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(float *, unsigned, unsigned, void *, int, unsigned);
extern "C" void drawInit__14cScrSpriteDraw(sScrDraw *);

// FUNCTION: GAME 0x160D50
extern "C" void func_00160D50(char *self)
{
    int info[20];
    V4 v[4] __attribute__((aligned(16)));
    info[0] = 1;
    char *p = (char *)v;
    for (int i = 3; i != -1; i--) {
        ZQ(p, 0x0);
        p += 0x10;
    }
    V4 *pa = &v[0];
    V4 *pb = &v[1];
    V4 *pc = &v[2];
    V4 *pd = &v[3];
    v[0].x = -1.0f;
    pa->y = -1.0f;
    v[0].z = 0;
    pa->w = 1.0f;
    v[1].x = 513.0f;
    pb->y = -1.0f;
    v[1].z = 0;
    pb->w = 1.0f;
    v[2].x = -1.0f;
    pc->y = 449.0f;
    v[2].z = 0;
    pc->w = 1.0f;
    v[3].x = 513.0f;
    pd->y = 449.0f;
    v[3].z = 0;
    pd->w = 1.0f;
    char *r = Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(&pa->x, *(unsigned *)(self + 0xED0), 1, info, 6, 5);
    if (r) {
        *(unsigned long *)(r + 0x40) = 0x3001D;
    }
    drawInit__14cScrSpriteDraw(ScrDraw);
    *(int *)((char *)ScrDraw + 0x28) = 7;
    *(int *)((char *)ScrDraw + 0x2C) = 1;
}
