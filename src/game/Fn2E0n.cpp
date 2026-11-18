// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// Unnamed printf-style wrappers in 0x2E0000-0x2EFFFF.
extern "C" int func_002E0AD8(int);
extern "C" int func_002E0AE0(int);
extern "C" int func_002E0B18(int, int);
extern "C" void func_002E0F18(char *, int, int, int, int);
extern "C" int vsprintf(char *, const char *, void *);
extern "C" char D_0061B298[];

// FUNCTION: GAME 0x2E0C80
extern "C" void func_002E0C80(int a, int b, int c, int d, int e, const char *fmt, void *ap)
{
    if (func_002E0AD8(d))
        return;
    if (func_002E0AE0(b))
        return;
    int n = vsprintf(D_0061B298, fmt, ap);
    if (n + 1 >= 0x200)
        *(int *)0x11111111 = 0;
    if (func_002E0B18(a, n))
        return;
    func_002E0F18(D_0061B298, a, b, c, e);
}

extern "C" void Moji_size_set__FUcUc(unsigned char, unsigned char);

// FUNCTION: GAME 0x2E0B78
extern "C" void func_002E0B78(int a, int b, int c, int d, int e, int f, int g, const char *fmt, void *ap)
{
    if (func_002E0AD8(f))
        return;
    if (func_002E0AE0(d))
        return;
    Moji_size_set__FUcUc(a, b);
    int n = vsprintf(D_0061B298, fmt, ap);
    if (n + 1 >= 0x200)
        *(int *)0x11111111 = 0;
    if (func_002E0B18(c, n))
        return;
    func_002E0F18(D_0061B298, c, d, e, g);
    Moji_size_set__FUcUc(0, 0);
}

struct cHeap;
extern "C" void *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, cHeap &);
extern "C" cHeap D_00754240;

struct Vec4 { int x, y, z; float w; };

// FUNCTION: GAME 0x2EBD10
extern "C" int func_002EBD10(char *self, int unused, unsigned n)
{
    unsigned sz;
    void *q;
    int one;
    if (*(unsigned *)(self + 0x2E0) & 8) {
        sz = n * 0x60 + 0xF0;
        void *p = _MemoryAlloc__FUiUiR5cHeap(sz, 16, D_00754240);
        *(void **)(self + 0x2CC) = p;
        if (!p)
            goto fail;
        p = _MemoryAlloc__FUiUiR5cHeap(sz, 16, D_00754240);
        *(void **)(self + 0x2D0) = p;
        if (!p)
            goto fail;
    } else {
        sz = n * 0x40 + 0xF0;
        void *p = _MemoryAlloc__FUiUiR5cHeap(sz, 16, D_00754240);
        *(void **)(self + 0x2C4) = p;
        if (!p)
            goto fail;
        p = _MemoryAlloc__FUiUiR5cHeap(sz, 16, D_00754240);
        *(void **)(self + 0x2C8) = p;
        if (!p)
            goto fail;
    }
    sz = n << 4;
    q = _MemoryAlloc__FUiUiR5cHeap(sz, 16, D_00754240);
    *(void **)(self + 0x2BC) = q;
    if (!q)
        goto fail;
    for (unsigned i = 0; i < n; i++) {
        Vec4 *v = (Vec4 *)*(char **)(self + 0x2BC) + i;
        v->x = 0;
        v->y = 0;
        v->z = 0;
        v->w = 1.0f;
    }
    if (*(unsigned *)(self + 0x2E0) & 4) {
        void *r = _MemoryAlloc__FUiUiR5cHeap(sz, 16, D_00754240);
        *(void **)(self + 0x2C0) = r;
        if (!r)
            goto fail;
        for (unsigned i = 0; i < n; i++) {
            Vec4 *v = (Vec4 *)*(char **)(self + 0x2C0) + i;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            v->w = 1.0f;
        }
    }
    one = 1;
    if (((*(unsigned long *)(self + 0x240)) & (0xFFFFUL << 40)) != (0x10100UL << 32) || *(float *)(self + 0x2DC) != 0.0f)
        *(unsigned *)(self + 0x2E0) |= 1;
    *(int *)(self + 0x2E4) = one;
    return 1;
fail:
    return 0;
}
