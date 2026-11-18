extern "C" void *initialize__7cIDBase7eIdData5eIdNo(void *, int, int);

// FUNCTION: GAME 0x133408
extern "C" int func_00133408(void *, float *a, float *b, float *c, float *d)
{
    if (b[0] < c[0] || a[0] > d[0])
        return 0;
    if (b[2] < c[2] || a[2] > d[2])
        return 0;
    if (b[1] < c[1] || a[1] > d[1])
        return 0;
    return 1;
}

// FUNCTION: GAME 0x135250
extern "C" int func_00135250(void *, float *a, float *b, float *c, float *d)
{
    if (b[0] < c[0] || a[0] > d[0])
        return 0;
    if (b[2] < c[2] || a[2] > d[2])
        return 0;
    if (b[1] < c[1] || a[1] > d[1])
        return 0;
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x139910
// diff: load/store scheduling of the two vec temps differs (21 words)
extern "C" void func_00139910(char *self)
{
    char *p = *(char **)(self + 0x364);
    if (p && *(char **)(self + 0x368)) {
        float t[4];
        float *d = (float *)(self + 0x210);
        t[2] = *(float *)(p + 0xB8);
        t[0] = *(float *)(p + 0xB0);
        t[1] = *(float *)(p + 0xB4);
        t[3] = 1.0f;
        if (d != t) {
            d[0] = t[0];
            d[1] = t[1];
            d[2] = t[2];
        }
        p = *(char **)(self + 0x368);
        d = (float *)(self + 0x200);
        t[2] = *(float *)(p + 0xB8);
        t[0] = *(float *)(p + 0xB0);
        t[1] = *(float *)(p + 0xB4);
        t[3] = 1.0f;
        if (d != t) {
            d[0] = t[0];
            d[1] = t[1];
            d[2] = t[2];
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x13DF70
// diff: original keeps off+self in v0 then moves to s0 (17 words)
extern "C" void func_0013DF70(char *self)
{
    unsigned short i = 0;
    do {
        int off = i * 0x50;
        char *e;
        initialize__7cIDBase7eIdData5eIdNo(self + (off + 0x90), 1, 0x12);
        e = self + off;
        *(short *)(e + 0xD4) = 1;
        *(float *)(e + 0xD0) = 0.00724635f;
        i++;
    } while (i < 8);
}
#endif

extern "C" void func_001331B8(void *, long);

// FUNCTION: GAME 0x1332D0
extern "C" void func_001332D0(void *self, const char *s, int) __asm__("SetCollEnable__16cCollisionScrollPCcb");
extern "C" void func_001332D0(void *self, const char *s, int)
{
    long m = 0;
    if (*s) {
        int i = 0;
        do {
            long v = *s;
            s++;
            m |= v << (i * 8);
            i++;
        } while (i < 8 && *s);
    }
    func_001331B8(self, m);
}
