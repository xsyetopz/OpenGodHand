// Unit at 0x3127B0.
class cHeap;
extern cHeap *MemDefalutHeapPtr;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
extern "C" void free__5cHeapPv(void *, void *);
extern "C" void *memmove(void *, const void *, unsigned);

struct Vec {
    unsigned char pad;
    int *b;
    int *e;
    int *cap;
};

// FUNCTION: GAME 0x3127B0
extern "C" void func_003127B0(Vec **out, unsigned n)
{
    Vec *v = (Vec *)_MemoryAlloc(0x10, 0x10, *MemDefalutHeapPtr);
    if (v) {
        unsigned char u;
        volatile unsigned char t = v->pad;
        v->pad = u;
        v->pad = t;
        v->b = 0;
        v->e = 0;
        v->cap = 0;
    }
    *out = v;
    int *ob = v->b;
    if ((unsigned)(v->cap - ob) < n) {
        int cnt = v->e - ob;
        unsigned sz = cnt * 4;
        int *nb = (int *)_MemoryAlloc(n * 4, 0x10, *MemDefalutHeapPtr);
        memmove(nb, ob, sz);
        if (v->b)
            free__5cHeapPv(((void **)v->b)[-8], v->b);
        v->e = nb + cnt;
        v->b = nb;
        v->cap = nb + n;
    }
}
