// Mid-size units in 0x200000-0x230000.
extern "C" void func_002011B0(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2017A8 - self/b saved-register swap (s0/s1), loop 2 otherwise equal
extern "C" char *func_002017A8(char *self)
{
    char *b = self + 4;
    char *e = b;
    char *p = b;
    int i;
    for (i = 0; i < 0x20; i++, e += 0x88, p += 0x88) {
        if (*(int *)p == 0)
            return e;
    }
    func_002011B0(self);
    e = self + 4;
    p = b;
    int end = (int)b + 0x1100;
    for (; (int)p < end; p += 0x88, e += 0x88) {
        if (*(int *)p == 0)
            return e;
    }
    return 0;
}
#endif

struct Slot2 {
    int a;
    int key;
    char pad[0x7C];
    void *res;
};
struct Pool2 {
    Slot2 *cur;
    Slot2 slots[0x20];
};

extern "C" void func_00324008();
extern "C" void func_002018F0(void *);
extern "C" void func_00201290(void *);
extern "C" void func_00201228(void *, void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x200F50 - result and cur swap v1/a0
extern "C" int func_00200F50(Pool2 *self, int key)
{
    int r = 0;
    Slot2 *c = self->cur;
    if (c == 0)
        return 0;
    if (c->key == key) {
        if (c->res != 0) {
            func_00324008();
            func_002018F0(self);
        }
        self->cur = 0;
        func_00201290(self);
        r = 1;
    } else {
        Slot2 *s = self->slots;
        int *k = &self->slots[0].key;
        int *end = &self->slots[0x20].key;
        do {
            if (*k == key) {
                func_00201228(self, s);
                r = 1;
            }
            k += 0x22;
            s++;
        } while ((int)k < (int)end);
    }
    return r;
}
#endif

class cHeap;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
extern int D_00580D40;
struct DvdSlot {
    int used;
    int id;
    int ret;
    int fC;
    char pad0[0x5C];
    int f6C;
    int f70;
    int f74;
    unsigned f78;
    int f7C;
    void *f80;
};
struct DvdQ {
    int cur;
};
extern "C" DvdSlot *func_002017A8(void *);
extern "C" int func_001FF9C0(int *, const char *, unsigned *, int *);
extern "C" int func_00201788(void *);

// FUNCTION: GAME 0x200CB0
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(DvdQ *self, const char *name, void **out, cHeap &heap, int id, unsigned a, unsigned b, unsigned c)
{
    *out = 0;
    DvdSlot *s = func_002017A8(self);
    if (s == 0)
        return 0;
    int r = func_001FF9C0(&D_00580D40, name, &s->f78, &s->fC);
    s->ret = r;
    s->f7C = (int)&heap;
    s->f74 = (s->f78 + 0x7FF) >> 11;
    if (r < 0)
        return 0;
    s->used = 1;
    if (id == 0)
        s->id = func_00201788(self);
    else
        s->id = id;
    s->f6C = c;
    s->f70 = b;
    s->f80 = 0;
    if (a != 0)
        s->f74 = (a + 0x7FF) >> 11;
    void *p = _MemoryAlloc(s->f74 << 11, 0x80, heap);
    s->f80 = p;
    if (p == 0) {
        func_00201228(self, s);
        return 0;
    }
    *out = p;
    if (self->cur == 0)
        func_00201290(self);
    return s->id;
}
