// Medium unnamed functions in 0x300000-0x31BFFF.
#include "game/cFn300Mid.h"

// FUNCTION: GAME 0x30EE68
extern "C" void func_0030EE68(void *p, int f)
{
    if (f == 0xFFFF && p) {
        func_002A9528(D_00754200);
        func_002A9528(SoundHeap);
        func_002A9528(RoomHeap);
        func_002A9528(SubScrHeap);
        func_002A9528(D_00754240);
    }
}

// FUNCTION: GAME 0x305358
extern "C" void func_00305358(unsigned *self, unsigned *d)
{
    self[1] = (unsigned)SearchData(d, D_0044FEA0, 0);
    self[0] = (unsigned)SearchData(d, D_0044FEA0, 1);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3182D8
// 2 words differ: final two stores swapped (orig stores D_00754C50 via v1 first); a D_00754C50 pointer temp fixed the lui order (4 -> 2); store-order permutations did not help; t at block top, *t before objbaseArray, &objbaseArray pointer all still 2 words
extern "C" void func_003182D8(void *p, int f)
{
    if (f == 0xFFFF && p) {
        func_002A9528(D_00754C10);
        func_002A9528(D_00754C20);
        objArray = 0;
        func_002C53A8(scrArray);
        int *t = (int *)D_00754C50;
        objbaseArray = 0;
        *t = 0;
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x306FF8
// 2 words differ: original loop-back is `bnel; daddu a2,v0` in the delay slot, ours `bnez; movn a2,v0,v0`; tried do-while with nx, `while (nx && (c = nx))`, ternary, for(;;)/continue, goto exits
extern "C" void func_00306FF8(char *self, LNode *n)
{
    LNode *c = (LNode *)(self + 0x4200);
    if (c) {
        LNode *nx;
        do {
            if (n->key < c->key) {
                LNode *pv = c->prev;
                n->next = c;
                n->prev = pv;
                pv->next = n;
                c->prev = n;
                goto out;
            }
            nx = c->next;
            if (nx)
                c = nx;
        } while (nx);
        c->next = n;
        n->prev = c;
        n->next = 0;
    }
out:
    func_00307060(self);
}
#endif

// FUNCTION: GAME 0x3059A8
extern "C" int func_003059A8(void *self, int type, int x)
{
    char buf[16];
    int r;
    if (type == 5)
        r = 0;
    else {
        void *e = func_003058D8(self, type);
        if (!e) {
            getEffTypeString__FPc12eEffDataType(buf, type);
            r = 0;
        } else
            r = func_00305858(e, x);
    }
    return r;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x306F10
// 3 words differ: original computes (self + 0x300) first and adds i * 4 after; gcc adds self to i * 4 first
extern "C" int func_00306F10(char *self, int i)
{
    struct Ob { char _p[0xA]; unsigned short cnt; };
    Ob **sp;
    Ob *o;
    short r;
    if (i >= 32 || (o = *(sp = (Ob **)(self + 0x300) + i)) == 0)
        return -1;
    r = --o->cnt;
    if (r < 0)
        return r;
    if (r == 0) {
        func_00306FF8(self, (LNode *)*sp);
        *sp = 0;
    }
    return r;
}
#endif

// FUNCTION: GAME 0x312E88
extern "C" void *func_00312E88()
{
    char *p = (char *)_MemoryAlloc(0x360, 0x10, *(cHeap *)D_00754C20);
    if (!p)
        return 0;
    memset(p, 0, 0x360);
    __4cObj(p);
    *(void **)(p + 0x214) = D_00450CE8;
    __asm__ volatile("sqc2 $vf0,0x310(%0)" : : "r"(p) : "memory");
    *(char *)(p + 0x32C) = 0;
    __asm__ volatile("sqc2 $vf0,0x340(%0)" : : "r"(p) : "memory");
    return p;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x309028
// 5 words differ: store scheduling of the float/short stores (original order f40, A4, f7C, f78, A0, A2, A6, A8); ~110 random source orders did not finish
extern "C" void func_00309028(S309028 *p)
{
    memset(p, 0, 0x2E0);
    p->b8D = 6;
    p->s8E = 5;
    p->c4C = 0x80808080;
    p->f40 = 1.0f;
    p->f78 = 1.0f;
    p->f7C = 1.0f;
    p->sA0 = 0;
    p->sA2 = 0;
    p->sA4 = 0;
    p->sA6 = 0;
    p->sA8 = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x305FB0
// 20 words differ: original keeps t in a2 and the loop counter in a0 (self is dead after the load); tried i declared first, while loop, t2 order: no change
extern "C" void *func_00305FB0(char *self, int id)
{
    char *t = *(char **)(self + 0x400);
    if (!t)
        return 0;
    char *t0 = t + (*(int *)(t + 0x10) + 0x10);
    char *t2 = t + (*(int *)(t + 0x14) + 0x10);
    unsigned n = *(unsigned *)(t0 + 4);
    int *p = (int *)(t0 + 0x10);
    for (unsigned i = 0; i < n; i++, p++) {
        if (*(unsigned short *)(*p + t0 + 0x10) == id)
            return t2 + (*(int *)(t2 + i * 4 + 0x10) + 0x10);
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x306030
extern "C" void *func_00306030(char *self, int type, int idx)
{
    if (type == 3)
        return func_00305FB0(self, idx);
    int *e = (int *)func_003058D8(self, type);
    if (!e)
        return 0;
    int *a = (int *)e[1];
    if (!a || !(idx - 1 < a[0]))
        return 0;
    int v = a[idx];
    return v ? (void *)(v + (int)a) : 0;
}

// FUNCTION: GAME 0x3062A8
extern "C" void func_003062A8(void *self, int k)
{
    switch (k) {
    case 0:
        func_00300AE8(self, 0);
        break;
    case 1:
        func_002FB6C8(self);
        break;
    case 2:
        func_002FB6C8(self);
        func_00300AE8(self, 0);
        break;
    }
}

// FUNCTION: GAME 0x306330
extern "C" void func_00306330(void *self, int k)
{
    switch (k) {
    case 0:
        func_00300C00(self, 1);
        break;
    case 1:
        func_002FB7B0(self);
        break;
    case 2:
        func_002FB7B0(self);
        func_00300C00(self, 1);
        break;
    }
}

// FUNCTION: GAME 0x30A200
extern "C" void func_0030A200(int i)
{
    unsigned char *s = (unsigned char *)D_00747BA0 + i * 0xB0;
    if (s[1] == 1) {
        func_00397550(0x1000A000, 0, 0);
        func_003973E8(0x1000A000, *(int *)(s + 8));
        func_00397550(0x1000A000, 0, 0);
        func_003973E8(0x1000A000, *(int *)(s + 0xC));
    }
}

// FUNCTION: GAME 0x30B698
extern "C" void func_0030B698()
{
    D_00747A24 |= 0x4000;
    func_0031A0E8(D_00754C80);
    func_002C3280(g_Sce);
    func_002D50E8(GlobalTask, 4, 0x3000, 0x20);
    func_002D51C0(GlobalTask, 0, 0x8000);
    func_002D51C0(GlobalTask, 1, 0x8000);
    func_002D51F0(GlobalTask);
    func_002E1348();
}

// FUNCTION: GAME 0x30CAA0
extern "C" void func_0030CAA0()
{
    if (D_00747A24 & 0x10000000)
        func_0030B870(1);
    else
        func_0030B870(0);
    if (D_00747A24 & 0x20000000)
        func_003AFF50(0);
    else
        FlushCache(0);
    func_00396440(D_007476C0, *(int *)(D_007476C0 - 0x10));
    func_0030CB30();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31A6B0
// 6 words differ: f0/f1/f2 register assignment and pCamWork load order
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern char *pCamWork;
extern "C" unsigned func_0031A6B0(char *self, float *v)
{
    float t[4];
    sceVu0ApplyMatrix(t, (float *)pCamWork, v);
    float f = t[3] * 10.0f;
    unsigned r = 0;
    if (!(f < 0.0f))
        r = (int)f;
    return r >> *(unsigned char *)(self + 0xB58);
}
#endif
