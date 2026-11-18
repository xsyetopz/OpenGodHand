#include "game/cOmBase.h"

// Small free functions of the cOm* map-object units in 0x1B0000-0x1BFFFF.
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" void func_001B6FB8(void *self);

#ifdef NONMATCHING
// DRAFT: GAME 0x1B8030
// diff: Slice 14: 25 range-test forms (&&, bool/char/short temps, ?:, if/else, goto, switch ranges, inline helper, -O1) give movn, sltiu or two separate branches; none gives slti/xori joined through a1+andi.
// original branches on v<0x3C0 with a0 temp (bnez + daddu a0,v0); compiled uses beqz and returns in v0 directly
extern "C" unsigned long func_001B8030(char *self)
{
    int v = *(unsigned short *)(self + 0x2FE);
    return v < 0x3C0 ? 0 : v < 0x400;
}
#endif

// FUNCTION: GAME 0x1B7EA8
extern "C" void func_001B7EA8(char *self, float *src)
{
    float *dst = (float *)(self + 0x100);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    *(unsigned int *)(self + 0x5B8) |= 0x10;
}

// FUNCTION: GAME 0x1B8448
extern "C" void func_001B8448(cOmBase *self)
{
    KillEffect__FPC4cObji13eEspEraseMode(self, 0, 2);
    self->dieCommon();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1B8720
// 4 words off: if(b==0) w=0; else w=...; then if(w==0) gives the layout, but sw precedes bnel (original beqz + sw in delay slot) and the arms are swapped; tried ?:, if/else orders, sink placements
extern "C" int func_001B8720(char *self)
{
    volatile int sink;
    unsigned char b = *(unsigned char *)(self + 0x2B4);
    sink = b;
    char *w;
    if (b == 0)
        w = 0;
    else
        w = **(char ***)(self + 0x278);
    if (w == 0)
        return *(int *)(self + 0xF0);
    return *(int *)(w + 0xF0);
}
#endif

// FUNCTION: GAME 0x1BF4E0
extern "C" int func_001BF4E0(char *self)
{
    func_001B6FB8(self);
    int f = *(int *)(self + 0x5B8);
    *(int *)(self + 0x5B8) = f & -0x41;
    return 1;
}

// FUNCTION: GAME 0x1BFFE0
extern "C" void func_001BFFE0(cOmBase *self)
{
    long v = self->m_flags;
    if (((v >> 1) & 1) == 0) {
        self->m_flags |= 1;
        self->m_mode2F4 = 2;
        self->m_mode2F6 = 0;
        self->m_mode2F7 = 0;
        self->m_mode2F5 = 0;
    }
}

// FUNCTION: GAME 0x1BB508
extern "C" void func_001BB508(cOmBase *self)
{
    *(signed char *)((char *)self + 0x531) = -1;
    KillEffect__FPC4cObji13eEspEraseMode(self, 0, 2);
    self->dieCommon();
}

extern "C" void func_0012EC58(void *scr, void *p);
extern char g_CollScr[];

// FUNCTION: GAME 0x1BDBB8
extern "C" void func_001BDBB8(char *self)
{
    void *c = *(void **)(self + 0x77C);
    if (c) {
        func_0012EC58(g_CollScr, c);
        *(void **)(self + 0x77C) = 0;
    }
}
