// Units at 0x2F2898, 0x2FBB78, 0x317FF0.
extern "C" void func_002D9F68(void *, void *, int);
extern "C" void func_002B6160(float *, char *);
extern "C" void func_002B6310(float *, char *);
extern "C" int func_0031D098(char *);
extern char D_0044EED0[];
extern char D_0044EEE8[];
extern char D_0061B7C0[];
extern char D_0071B7C0[];
extern char D_0071B840[];
extern char D_0071B8C0[];
typedef void (*FnBB78)(char *, int, char *);
extern "C" void *_MemoryAlloc__FUiUiR5cHeap(unsigned int, unsigned int, char *);
extern "C" void free__5cHeapPv(void *, void *);
extern "C" void *memmove(void *, const void *, unsigned int);
extern char *MemDefalutHeapPtr;

#ifdef NONMATCHING
// DRAFT: GAME 0x2F2898 - 69 differing words: base in $a2 vs $a0, movz/bnez form for the 0x18C +1, 1.0f load into $f1 vs $f3. Variants tried: 6 (best kept).
extern "C" int func_002F2898(char *self)
{
    float tmp[3];
    char *base = *(char **)(self + 0x110);
    int n;
    *(float *)(self + 0x2D8) = *(float *)(base + 0x13C);
    n = *(int *)(base + 0x16C);
    *(int *)(self + 0x2B0) = n;
    *(int *)(self + 0x2B4) = *(int *)(base + 0x170);
    if (n >= 3) {
        func_002D9F68(self, D_0044EED0, n);
        return 0;
    }
    int v = *(unsigned char *)(base + 0x18C);
    if (n == 0) {
        v += 1;
    }
    *(int *)(self + 0x2B8) = v;
    char *base2 = *(char **)(self + 0x110);
    *(unsigned char *)(self + 0x2D0) = (*(signed char *)(base2 + 0x18D) != 0);
    float *q = (float *)(self + 0x2E0);
    q[0] = *(float *)(base2 + 0x148);
    q[3] = 1.0f;
    q[1] = *(float *)(base2 + 0x14C);
    q[2] = *(float *)(base2 + 0x150);
    if (*(signed char *)(self + 0x103) == -1) {
        func_002B6310(tmp, self);
    } else {
        func_002B6160(tmp, self);
    }
    float *dst = (float *)(self + 0x2C0);
    if (dst != tmp) {
        dst[0] = tmp[0];
        dst[1] = tmp[1];
        dst[2] = tmp[2];
    }
    if (*(unsigned char *)(self + 0x2D0) != 0) {
        *(int *)(self + 0x2D4) = func_0031D098(self + 0x220);
    }
    n = *(int *)(self + 0x2B0);
    if (n == 1 && *(int *)(self + 0x2B8) == 0) {
        func_002D9F68(self, D_0044EEE8, 0);
        *(int *)(self + 0x2B8) = n;
    }
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2FBB78 - 54 differing words (332 vs 328 bytes): $s0/$s1 swap, a3 else-if structure, beqz/bnel offsets one instruction off. Variants tried: 8 (attempt 8 with if/else-if dispatch gave 75, reverted).
extern "C" void func_002FBB78(int a0, int a1, int a2, int a3)
{
    unsigned int v = a2 & 0xFF;
    unsigned int i;
    char *e;
    for (i = 0, e = D_0061B7C0; i < 0x400; i++, e += 0x400) {
        unsigned int bit = 0x80000000u >> (i & 31);
        unsigned int w = (i >> 5) * 4;
        if (!(*(unsigned int *)(D_0071B7C0 + w) & bit)) continue;
        if (*(unsigned int *)(D_0071B840 + w) & bit) continue;
        if (*(unsigned int *)(D_0071B8C0 + w) & bit) continue;
        int hit;
        if (a3 == 0) {
            hit = (*(short *)(e + 0x23A) == a0) && (*(unsigned short *)(e + 0x23C) == a1);
        } else {
            hit = (*(short *)(e + 0x23A) != a0) || (*(unsigned short *)(e + 0x23C) != a1);
        }
        if (hit) {
            char *obj = *(char **)(e + 0xF0);
            short off = *(short *)(obj + 0x30);
            FnBB78 fn = *(FnBB78 *)(obj + 0x34);
            fn(e + off, v, e);
        }
    }
}
#endif

// FUNCTION: GAME 0x317FF0
extern "C" void func_00317FF0(char *vec, char *pos, int *val)
{
    char *end = *(char **)(vec + 0x8);
    char *cap = *(char **)(vec + 0xC);
    if (end != cap) {
        if (end != 0) {
            *(int *)end = *(int *)(end - 4);
        }
        char *e2 = *(char **)(vec + 0x8);
        char *p4 = e2 - 4;
        int n = ((p4 - pos) >> 2) << 2;
        *(char **)(vec + 0x8) = e2 + 4;
        int v = *val;
        memmove(e2 - n, pos, n);
        *(int *)pos = v;
    } else {
        char *begin = *(char **)(vec + 0x4);
        int cnt = (end - begin) >> 2;
        int nc = cnt != 0 ? cnt * 2 : 1;
        unsigned int bytes = nc << 2;
        char *buf = (char *)_MemoryAlloc__FUiUiR5cHeap(bytes, 0x10, MemDefalutHeapPtr);
        char *b2 = *(char **)(vec + 0x4);
        int d = pos - b2;
        char *np = buf + d;
        memmove(buf, b2, (d >> 2) << 2);
        if (np != 0) {
            *(int *)np = *val;
        }
        np += 4;
        char *dst = np;
        int m = *(char **)(vec + 0x8) - pos;
        char *newend = dst + m;
        memmove(dst, pos, (m >> 2) << 2);
        char *old = *(char **)(vec + 0x4);
        if (old != 0) {
            free__5cHeapPv(*(void **)(old - 0x20), old);
        }
        *(char **)(vec + 0x4) = buf;
        *(char **)(vec + 0xC) = buf + bytes;
        *(char **)(vec + 0x8) = newend;
    }
}
