#include "cVec.h"

// Small unnamed helpers in 0x2A0000-0x2AFFFF, written as extern "C" free
// functions over raw offsets until their owning classes are known.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

// 0x2A6C78: 12 words differ; gcc strength-reduces the pointer (original keeps a0+0x14 with negative offsets)
#ifdef NONMATCHING
void func_002A6C78(int *p)
{
    int *q = p + 5;
    int i = 31;
    do {
        q[-2] = 0xFFFF;
        q[-1] = -1;
        q[0] = 0;
        i--;
        q += 3;
    } while (i >= 0);
}

#endif

extern void func_002A48A8(int, int);
extern void func_002A72C8(int, int);
extern void func_002A9D30(int, int);
extern void func_002ACBE8(int, int);
extern void func_002AD1B0(int, int);

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


extern int D_00747A0C;
extern char g_HeatSys[];
extern char D_0044AEF8[];
extern void func_002A58D8(char *, u32);
extern void func_002A98A8(void *);
extern void func_0030F5A0();
extern void func_002B16F0(void *);
extern void *getTexAddr(void *, int, u32) __asm__("getTexAddr__10cIDManager7eIdDataUi");

// 0x2A4B20: 4 words differ (movn vs movz select, addu operand order)
#ifdef NONMATCHING
short func_002A4B20(char *self, u16 id)
{
    if (id == 0)
        return D_00747A0C ? 4 : 8;
    u32 w = *(u32 *)(*(char **)(self + (id >> 12) * 16 + 4) + (id & 0xFFF) * 4 + 8);
    return ((w >> 20) & 0x3F) - ((w >> 8) & 0x3F) + 1;
}
#endif

// 0x2A4BA0: 16 words differ (original keeps self in a2 via daddu)
#ifdef NONMATCHING
short func_002A4BA0(char *self, u16 id)
{
    if (id == 0)
        return 0;
    char *e = self + (id >> 12) * 16;
    u32 w = *(u32 *)(*(char **)(e + 4) + (id & 0xFFF) * 4 + 8);
    return *(u16 *)(e + 0xE) - ((w >> 14) & 0x3F);
}
#endif

// FUNCTION: GAME 0x2A58A0
void func_002A58A0(char *self, int v)
{
    *(int *)(self + 0x28000 + 0x2060) = v;
    func_002A58D8(self, 0xFFFFFFFF);
}

void *operator new(unsigned, void *p) { return p; }
struct PathFinding {
    PathFinding();
};

// 0x2A5AD0: placement-new of PathFinding at +0x18C; 10 words differ (frame/ctor call shape)
#ifdef NONMATCHING
void *func_002A5AD0(char *self)
{
    new (self + 0x18C) PathFinding;
    return self;
}
#endif

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
        func_002A98A8(g_HeatSys);
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

struct HH {
    HH *s;
    int f4, f8, fC, f10;
};
struct SS {
    HH *h;
    int n;
};

// FUNCTION: GAME 0x2A94F0
void func_002A94F0(SS *a)
{
    a->h->f8 = 0;
    a->h->f4 = 0;
    a->h->f10 = 0x20;
    a->h->fC = a->n - 0x20;
    a->h->s = (HH *)a;
}

struct NN {
    int a;
    NN *prev;
    NN *next;
};

// 0x2A9620: 4 words differ (load of l->next scheduled before first store)
#ifdef NONMATCHING
void func_002A9620(int a, NN *n, NN *l)
{
    NN *nx = l->next;
    n->a = a;
    n->next = nx;
    n->prev = l;
    if (nx)
        nx->prev = n;
    l->next = n;
}
#endif

// 0x2A96C0: 3 words differ (addiu/addu operand order of a+7+c)
#ifdef NONMATCHING
int func_002A96C0(int a, int b, int c)
{
    int t = a + 7;
    t += c;
    return (t & -c) * b;
}
#endif

// FUNCTION: GAME 0x2A98D8
void func_002A98D8(char *self, int f)
{
    *(char **)(self + 0x18) = D_0044AEF8;
    if (f & 1)
        func_0030F5A0();
}

}
