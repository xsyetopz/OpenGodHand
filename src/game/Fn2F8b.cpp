#include "game/Fn2F8Decls.h"

extern "C" {

// FUNCTION: GAME 0x2E6318
void *func_002E6318()
{
    if (D_007863E8 == 0) {
        func_002EFA60();
        func_0031EEA8(&D_007863E8, D_0044E398, &D_007863F8);
    }
    return &D_007863E8;
}

// FUNCTION: GAME 0x2F5358
void *func_002F5358()
{
    if (D_00786508 == 0) {
        func_00300148();
        func_0031EEA8(&D_00786508, D_0044F398, D_007863C8);
    }
    return &D_00786508;
}

// FUNCTION: GAME 0x2F7090
void *func_002F7090()
{
    if (D_00786558 == 0) {
        func_00300148();
        func_0031EEA8(&D_00786558, D_0044F6C0, D_007863C8);
    }
    return &D_00786558;
}

// FUNCTION: GAME 0x2F9CE0
void *func_002F9CE0()
{
    if (D_00786578 == 0) {
        func_002EFA60();
        func_0031EEA8(&D_00786578, D_0044F868, &D_007863F8);
    }
    return &D_00786578;
}

// FUNCTION: GAME 0x2E76F8
void func_002E76F8(char *p, int f)
{
    *(const char **)(p + 0xF0) = D_0044E640;
    World_light_work.Del_LightData(*(unsigned short *)(p + 0x2B2), *(unsigned *)(p + 0x2B4));
    func_002FBE28(p, f);
}

// FUNCTION: GAME 0x2F5730
void func_002F5730(char *p, int f)
{
    *(const char **)(p + 0xF0) = D_0044F448;
    char *q = *(char **)(p + 0x2F0);
    if (q)
        (*(cHeap **)(q - 0x20))->free(q);
    func_002EBC50(p, f);
}

// FUNCTION: GAME 0x2F4B30
void func_002F4B30(char *p, int f)
{
    *(const char **)(p + 0xF0) = D_0044F1C8;
    if (*(void **)(p + 0x2B0))
        ReleaseObj(*(cObj **)(p + 0x2B0));
    func_002FBE28(p, f);
}

// FUNCTION: GAME 0x2D51F0
void func_002D51F0(char *p)
{
    unsigned i;
    for (i = 0; i < *(unsigned short *)(p + 0xC); i++)
        func_002D5790(*(char **)p + i * 0x58);
}

// FUNCTION: GAME 0x2D56A8
void func_002D56A8(char *p)
{
    int i;
    for (i = 0; i < *(unsigned short *)(p + 0xC); i++)
        ((cTaskWork *)(*(char **)p + i * 0x58))->kill();
}

// FUNCTION: GAME 0x2D5708
void func_002D5708(char *p, int f)
{
    *(const char **)(p + 0x54) = D_0044D1E8;
    char *q = *(char **)(p + 0x10);
    if (q)
        (*(cHeap **)(q - 0x20))->free(q);
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x2D42F8
void func_002D42F8(char *p)
{
    if (*(int *)p) {
        if (func_00345B88(*(int *)p))
            func_00345F48(*(int *)p, 0);
    }
}

// FUNCTION: GAME 0x2D5AD8
void func_002D5AD8(char *p)
{
    switch (*(unsigned short *)(p + 0x1E)) {
    case 0:
    default:
        (*(void (**)())(p + 0x14))();
        break;
    case 1:
        (*(void (**)(int))(p + 0x14))(*(int *)(p + 0x18));
        break;
    }
    ((cTaskWork *)p)->exit();
}

// FUNCTION: GAME 0x2D5250
void func_002D5250(unsigned short a)
{
    char *t = g_Sce + 0x1C;
    void *w = *(void **)(t + 4);
    if (w) {
        *(unsigned short *)(t + 0x34) = a;
        ((cTaskWork *)w)->sleep(1);
    } else
        ((cTaskWork *)D_00752C04)->sleep(a);
}

// FUNCTION: GAME 0x2C0CB0
int func_002C0CB0(float *c, float *p)
{
    float dx = p[0] - c[0];
    float dy = p[1] - c[8];
    float dz = p[2] - c[1];
    float r = c[2];
    float l = dx * dx + dy * dy + dz * dz;
    // The two nops ahead of sqrt.s are the hazard padding of the original inline template (see VuFn.cpp).
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(l));
    if (r < l)
        return 0;
    return 1;
}

// FUNCTION: GAME 0x2C0C28
int func_002C0C28(float *c, float *p)
{
    if (p[1] < c[8])
        return 0;
    if (c[9] < p[1])
        return 0;
    float dx = p[0] - c[0];
    float dz = p[2] - c[1];
    float r = c[2];
    float l = dx * dx + dz * dz;
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(l));
    if (r < l)
        return 0;
    return 1;
}

} // extern "C"

// FUNCTION: GAME 0x2D64D0
void CustomIDWork::SetNoDisp(bool b)
{
    char *t = (char *)m_work;
    if (t) {
        if (b)
            *(unsigned *)(t + 0x2C) |= 0x8000000;
        else
            *(unsigned *)(t + 0x2C) &= 0xF7FFFFFF;
    }
}

// FUNCTION: GAME 0x2D0528
sBgmTbl *cBgmData::GetTblPtr(int i)
{
    sBgmTbl *r;
    if (func_002CFF68(this))
        r = (sBgmTbl *)(*(char **)((char *)this + 0x10) + i * 32);
    else
        r = 0;
    return r;
}

// FUNCTION: GAME 0x2C9B10
extern "C" void func_002C9B10(char *p, int i)
{
    if (*(int *)p) {
        char *b = p + 0x14;
        char *s = b + i;
        if (CoreSave.getSkill((PL_SKILL)*s) == 1)
            CoreSave.setSkill((PL_SKILL)*s, 0);
    }
}
