// Units at 0x2D9F28, 0x2DB6D0 and 0x14E990.
extern int D_0044D3C0;
extern char D_0041EB80[], D_0041EBE8[];
extern "C" void func_0030F5A0(void *, int);
extern "C" int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(void *, void *, void *, int, int, int, int, int, int, int, int, int, int);
extern "C" void *__4cObj(char *);
extern "C" void *memset(void *, int, unsigned int);

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
#define ZV(v) __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&(v)) : "memory")

struct Vec4 {
    float x, y, z, w;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x2D9F28 - draft: plain C; uninitialized store is dropped, asm has sw $v1 first
extern "C" void func_002D9F28(void **p, int flag)
{
    void *u;
    *p = u;
    *p = (void *)&D_0044D3C0;
    int t = flag & 1;
    if (t != 0)
        func_0030F5A0(p, t);
}

// DRAFT: GAME 0x2DB6D0 - draft: 13-arg ChkLine call, zeroed locals via sqc2
extern "C" float func_002DB6D0(char *self)
{
    Vec4 a, b, c;
    ZV(a);
    ZV(b);
    ZV(c);
    a.y = (a.y + 1.0f) - 50.0f;
    float r = c.y;
    if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(&a, &b, &c, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) != 1)
        r = *(float *)(self + 4);
    return r;
}
#endif

// FUNCTION: GAME 0x14E990
extern "C" void *__8cObjBase(char *p)
{
    __4cObj(p);
    *(char **)(p + 0x214) = D_0041EBE8;
    ZQ(p, 0x310);
    ZQ(p, 0x320);
    ZQ(p, 0x330);
    ZQ(p, 0x360);
    ZQ(p, 0x370);
    ZQ(p, 0x380);
    ZQ(p, 0x390);
    ZQ(p, 0x460);
    ZQ(p, 0x480);
    ZQ(p, 0x490);
    ZQ(p, 0x4C0);
    *(char **)(p + 0x4AC) = D_0041EB80;
    memset(p + 0x4A8, 0, 4);
    *(int *)(p + 0x4A0) = -1;
    *(int *)(p + 0x4B4) = 0;
    *(int *)(p + 0x4B0) = 0;
    *(int *)(p + 0x4A4) = 0;
    *(int *)(p + 0x44C) = 0;
    *(char *)(p + 0x420) = 0;
    return p;
}
