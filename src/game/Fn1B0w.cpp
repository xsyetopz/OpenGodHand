// Enemy-object init helpers in 0x1B0000-0x1BF000.
extern "C" void *func_0031CCF0(void *, const char *, int);
extern "C" int func_00149738(void *, void *, void *, int, int);
extern "C" void func_00312708(void *);
extern "C" void func_001B7DE8(void *, int);
extern "C" void func_00150128(void *, int);
extern "C" void func_0013F558(void *, void *);
extern char NameA[], NameB[], NameC[], NameD[];
extern char *GPtr;
// FUNCTION: GAME 0x1B6FB8
extern "C" int func_001B6FB8(char *self)
{
    void *s1 = func_0031CCF0(*(void **)(self + 0x304), NameA, 0);
    int t;
    void *v = func_0031CCF0(*(void **)(self + 0x304), NameB, 0);
    if (v) {
        t = 0;
    } else {
        v = func_0031CCF0(*(void **)(self + 0x304), NameC, 0);
        if (v) {
            t = 1;
        } else {
            v = func_0031CCF0(*(void **)(self + 0x304), NameD, 0);
            t = 0;
        }
    }
    if (!func_00149738(self, s1, v, 0, t)) {
        func_00312708(self);
        return 0;
    }
    char *p = *(char **)(self + 0x5E0);
    if (p && *(unsigned char *)(p + 0x2D))
        func_001B7DE8(self, *(unsigned char *)(p + 0x2D) - 1);
    func_00150128(self, 0);
    *(unsigned *)(self + 0x5B8) |= 0x40;
    *(unsigned *)(self + 0x254) |= 0x80000000;
    *(unsigned *)(self + 0x254) |= 0x08000000;
    *(unsigned *)(self + 0x4A8) |= 0x10000000;
    *(short *)(self + 0x570) = -1;
    *(int *)(self + 0x574) = 2;
    *(float *)(self + 0x3A8) = 1.0f;
    if (*(unsigned short *)(self + 0x2FE) == 0x359)
        func_0013F558(GPtr + 0x1E90, self);
    return 1;
}
