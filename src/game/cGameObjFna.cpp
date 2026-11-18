// Small unnamed helpers in 0x2A0000-0x2AFFFF, written as extern "C" free functions over raw offsets.
#include "game/cGameObjFn.h"

extern "C" {

// FUNCTION: GAME 0x2A4B88
short func_002A4B88(char *self, u16 id)
{
    return *(short *)(self + ((id & 0xF000) >> 8) + 0xE);
}

// FUNCTION: GAME 0x2A4C00
u8 func_002A4C00(char *self, u32 id)
{
    id &= 0xFFFF;
    char *e = self + (id >> 12) * 16;
    return *(u8 *)(*(char **)(e + 4) + (id & 0xFFF) * 4 + 8);
}

// FUNCTION: GAME 0x2A5B00
void func_002A5B00(u8 *self)
{
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
}

// FUNCTION: GAME 0x2A7308
void func_002A7308(int *self)
{
    self[0] = 0;
    self[1] = 0;
}

// FUNCTION: GAME 0x2A9528
void func_002A9528(int *self)
{
    self[0] = 0;
    self[1] = 0;
}

// FUNCTION: GAME 0x2A9C90
void func_002A9C90(float *self, float v)
{
    self[3] = v;
}

// FUNCTION: GAME 0x2A9D28
float func_002A9D28(float *self)
{
    return self[2];
}

// FUNCTION: GAME 0x2AF720
void func_002AF720(char *self, float v)
{
    *(float *)(self + 0x60) = v;
}

// FUNCTION: GAME 0x2AF708
void func_002AF708(char *self, short v)
{
    *(short *)(self + 0x54) = v;
}

// FUNCTION: GAME 0x2AF710
void func_002AF710(char *self, int a, int b)
{
    *(int *)(self + 0x58) = a;
    *(int *)(self + 0x5C) = b;
}

// FUNCTION: GAME 0x2AF668
void func_002AF668(char *self, float a, float b)
{
    *(float *)(self + 0x2C) = a;
    *(float *)(self + 0x30) = b;
}

// FUNCTION: GAME 0x2AEF90
u8 func_002AEF90(char *self)
{
    return *(u8 *)(self + 0xBF0);
}

// FUNCTION: GAME 0x2AEF98
void func_002AEF98(char *self)
{
    *(u8 *)(self + 0xBF0) = 0;
}

// FUNCTION: GAME 0x2ABC18
void func_002ABC18(int, char *o)
{
    *(short *)(o + 0xA0) = 0;
    *(int *)(o + 0x2C) &= ~0x4000;
}

// FUNCTION: GAME 0x2ACC28
void func_002ACC28(u32 *p, u32 mask, int on)
{
    if (on)
        *p |= mask;
    else
        *p &= ~mask;
}

// FUNCTION: GAME 0x2AE3D0
char *func_002AE3D0(char *self)
{
    *self = 0;
    *(int *)(self + 8) = -1;
    *(int *)(self + 4) = 0;
    return self;
}

// FUNCTION: GAME 0x2AEB50
u32 func_002AEB50(char *self, int, u32 a)
{
    return (*(u16 *)(*(char **)(self + 4) + 2) + a & 0xFFFF) | 0x1000;
}

// FUNCTION: GAME 0x2A4950
void func_002A4950() { func_002A48A8(1, 0xFFFF); }
// FUNCTION: GAME 0x2A7318
void func_002A7318() { func_002A72C8(1, 0xFFFF); }
// FUNCTION: GAME 0x2A9DA0
void func_002A9DA0() { func_002A9D30(1, 0xFFFF); }
// FUNCTION: GAME 0x2ACC50
void func_002ACC50() { func_002ACBE8(1, 0xFFFF); }
// FUNCTION: GAME 0x2AD218
void func_002AD218() { func_002AD1B0(1, 0xFFFF); }

// FUNCTION: GAME 0x2A58A0
void func_002A58A0(char *self, int v)
{
    *(int *)(self + 0x28000 + 0x2060) = v;
    func_002A58D8(self, 0xFFFFFFFF);
}

// FUNCTION: GAME 0x2A7CA0
u8 func_002A7CA0(char *self, cVec *out)
{
    cVec *src = (cVec *)(self + 0x520);
    *out = *src;
    return *(u8 *)(self + 0x530);
}

// FUNCTION: GAME 0x2ACE28
void *func_002ACE28(void *self, u32 id)
{
    return getTexAddr(self, 1, id);
}

// FUNCTION: GAME 0x2A9790
void func_002A9790(int *self)
{
    self[0] = 0;
    self[4] = 0;
    self[5] = 0;
}

// FUNCTION: GAME 0x2A9D30
void func_002A9D30(int a, int b)
{
    if (b == 0xFFFF && a)
        func_002A98A8((int *)g_HeatSys);
}

// FUNCTION: GAME 0x2AED40
char *func_002AED40(char *self, u16 id)
{
    for (char *n = *(char **)(self + 0x10); n; n = *(char **)(n + 8))
        if (*(u16 *)(n + 0x64) == id)
            return n;
    return 0;
}

// FUNCTION: GAME 0x2AEDC0
int func_002AEDC0(char *self, u8 v)
{
    int c = 0;
    for (char *n = *(char **)(self + 0x10); n; n = *(char **)(n + 8))
        if (*(u8 *)(n + 0x2C) == v)
            c++;
    return c;
}

// FUNCTION: GAME 0x2AF028
void func_002AF028(char *self)
{
    for (char *n = *(char **)(self + 0x10); n; n = *(char **)(n + 8))
        func_002B16F0(n);
}

// FUNCTION: GAME 0x2AF6B8
void func_002AF6B8(int *p, int on)
{
    if (on)
        *p |= 1;
    else
        *p &= ~1;
}

// FUNCTION: GAME 0x2A94F0
void func_002A94F0(SS *a)
{
    a->h->f8 = 0;
    a->h->f4 = 0;
    a->h->f10 = 0x20;
    a->h->fC = a->n - 0x20;
    a->h->s = (HH *)a;
}

// FUNCTION: GAME 0x2A98A8
void *func_002A98A8(int *self) { self[0] = 0; self[6] = (int)&D_0044AEF8; self[1] = 0; self[3] = 0; self[2] = 0; self[5] = 0; *(char *)(self + 4) = 0; return self; }

// FUNCTION: GAME 0x2A98D8
void func_002A98D8(char *self, int f)
{
    *(char **)(self + 0x18) = D_0044AEF8;
    if (f & 1)
        func_0030F5A0();
}

}
