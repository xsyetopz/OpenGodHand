// Units in .text 0x150000-0x16FFFF (continued).

struct VT150 {
    char _pad[8];
    short adj;
    short _pad2;
    void (*fn)(void *, int);
};
extern "C" void func_002A9800(void *self, void *obj);
// FUNCTION: GAME 0x1505A8
extern "C" void func_001505A8(char *self, char *obj)
{
    if (obj) {
        *(int *)(self + 0x1C) += 1;
        VT150 *vt = *(VT150 **)(obj + 0x214);
        vt->fn(obj + vt->adj, 2);
        func_002A9800(self, obj);
    }
}

extern int MemDefalutHeapPtr;
extern "C" void func_00150418(char *self);
extern "C" void *func_002A96C0(int size, int n, int a);
extern "C" void *func_0030EE08(void *p, int a, int heap);
extern "C" void func_002A96D8(void *self, void *q, int size, int n, int a);

struct Loc155 {
    char *m;
    int pad[3];
};
extern "C" int func_001551C0(void *self, int i);
// FUNCTION: GAME 0x155138
extern "C" int func_00155138(char *self)
{
    Loc155 l;
    l.m = *(char **)(self + 0x388);
    unsigned v = *(unsigned short *)(l.m + 0xA);
    int n = v & 0xFF;
    self[0x385] = v;
    if (n > 0x10)
        return 0;
    int i = 0;
    int sum = 0;
    do {
        int r = func_001551C0(self, i);
        i++;
        n--;
        sum += r << 1;
    } while (n);
    return sum;
}

extern "C" int func_001552D0(void *self, int i);
// FUNCTION: GAME 0x155248
extern "C" int func_00155248(char *self)
{
    Loc155 l;
    l.m = *(char **)(self + 0x388);
    unsigned v = *(unsigned short *)(l.m + 0xA);
    int n = v & 0xFF;
    self[0x385] = v;
    if (n > 0x10)
        return 0;
    int i = 0;
    int sum = 0;
    do {
        int r = func_001552D0(self, i);
        i++;
        n--;
        sum += r << 1;
    } while (n);
    return sum;
}

extern char Dvd[];
extern char SubScrHeap[];
extern void *IDManager;
extern "C" void func_002A9680(void *heap, void *p);
extern "C" void *func_00200CB0(void *dvd, void *a, void *b, void *heap, int c, int d, int e, int f);
extern "C" void func_00201160(void *dvd, void *r);
extern "C" void func_002ACFA8(void *mgr, void *buf, void *name, int n);
// FUNCTION: GAME 0x166540
extern "C" void func_00166540(char *self, void *a)
{
    void *p = *(void **)(self + 0x298);
    if (p)
        func_002A9680(*(void **)((char *)p - 0x20), p);
    void *r = func_00200CB0(Dvd, a, self + 0x298, SubScrHeap, 0, 0, 0, 0);
    *(void **)(self + 0x29C) = r;
    func_00201160(Dvd, r);
}

// FUNCTION: GAME 0x161500
extern "C" int func_00161500(char *self, void *name)
{
    char buf[0x40];
    if (!*(int *)(self + 0x50)) {
        func_002ACFA8(IDManager, buf, name, -1);
        void *r = func_00200CB0(Dvd, buf, self + 0x50, SubScrHeap, 0, 0, 0, 0);
        *(void **)(self + 0x54) = r;
        func_00201160(Dvd, r);
    }
    return *(int *)(self + 0x50);
}

extern "C" char *func_002A9860(void *self, void *it);
extern "C" void func_002A9790(void *self);
// FUNCTION: GAME 0x150418
extern "C" void func_00150418(char *self)
{
    char *it = func_002A9860(self, 0);
    while (it) {
        char *next = func_002A9860(self, it);
        VT150 *vt = *(VT150 **)(it + 0x214);
        vt->fn(it + vt->adj, 2);
        it = next;
    }
    char *h = *(char **)self;
    func_002A9790(self);
    if (h)
        func_002A9680(*(void **)(h - 0x20), h);
}

struct V4g {
    float x, y, z, w;
};
extern "C" void func_001F7DA0(V4g *v);
extern "C" void func_001476D0(void *self, int a);
extern "C" void func_00147B60(void *self, void *a, V4g *v, int b);
extern "C" void func_00147BF8(void *self, void *a, void *b);
// FUNCTION: GAME 0x150138
extern "C" void func_00150138(char *self)
{
    V4g v;
    v.x = *(float *)(self + 0x100) + *(float *)(self + 0x130);
    v.y = *(float *)(self + 0x104) + *(float *)(self + 0x134);
    v.z = *(float *)(self + 0x108) + *(float *)(self + 0x138);
    v.w = 1.0f;
    func_001F7DA0(&v);
    func_001476D0(self, *(int *)(self + 0xD0));
    func_00147B60(self, self, &v, 0);
    func_00147BF8(self, self, self + 0x110);
}

// DRAFT: GAME 0x1563F0
// diff: branch layout (orig bnez to normal arm placed after denormal; 27 words)
#ifdef NONMATCHING
unsigned short F32toF16(float f)
{
    unsigned u = *(unsigned *)&f;
    unsigned a = u & 0x7FFFFFFF;
    unsigned sign = (u >> 16) & 0x8000;
    if (a > 0x47FFEFFF)
        return (unsigned short)(sign | 0x7FFF);
    if (a <= 0x387FFFFF) {
        unsigned e = a >> 23;
        unsigned m = (a & 0x7FFFFF) | 0x800000;
        a = m >> (0x71 - e);
    } else {
        a += 0xC8000000;
    }
    a = a + 0xFFF + ((a >> 13) & 1);
    return (unsigned short)(sign | (a >> 13));
}
#endif
