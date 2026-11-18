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
extern "C" void func_00150418(void *self, int n);
extern "C" void *func_002A96C0(int size, int n, int a);
extern "C" void *func_0030EE08(void *p, int a, int heap);
extern "C" void func_002A96D8(void *self, void *q, int size, int n, int a);
// DRAFT: GAME 0x1504B0
// diff: 10 words; callees/args/stores match but s0/s1 are swapped (original self=s0, n=s1) and tail store order 20,24,18,1C is scheduler-hoisted.
#ifdef NONMATCHING
extern "C" void func_001504B0(char *self, int n)
{
    func_00150418(self, n);
    void *p = func_002A96C0(0x220, n, 0x10);
    void *q = func_0030EE08(p, 0x10, MemDefalutHeapPtr);
    func_002A96D8(self, q, 0x220, n, 0x10);
    *(int *)(self + 0x24) = n;
    *(int *)(self + 0x18) = n;
    *(int *)(self + 0x1C) = n;
    *(void **)(self + 0x20) = p;
}
#endif

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
