struct Fn2BA300Item {
    unsigned flags;
    Fn2BA300Item *next;
};

struct Fn2BA300Tbl {
    char _pad0[0x20];
    short adj0;
    short _pad22;
    void (*fn0)(char *, Fn2BA300Item *, int, unsigned);
    char _pad28[0x10];
    short adj1;
    short _pad3A;
    int (*fn1)(char *, Fn2BA300Item *, int);
};

struct Fn2BA300 {
    char *base;
    unsigned count;
    int stride;
    char _padC[4];
    Fn2BA300Item *head;
    char _pad14[4];
    Fn2BA300Tbl *tbl;
};

// DRAFT: GAME 0x2BA300
// 6 words: list-search loop layout (found-return is bnel+b, orig beql delay-slot v0=s0); tried do-while, for, break+flag, store order.
#ifdef NONMATCHING
extern "C" Fn2BA300Item *func_002BA300(Fn2BA300 *self, int arg)
{
    unsigned i = 0;
    if (self->count != 0) {
        do {
            Fn2BA300Item *it = (Fn2BA300Item *)(self->base + self->stride * i);
            if ((it->flags & 0x603) == 0) {
                self->tbl->fn0((char *)self + self->tbl->adj0, it, self->stride, i);
                if (!self->tbl->fn1((char *)self + self->tbl->adj1, it, arg)) {
                    return 0;
                }
                Fn2BA300Item *p = self->head;
                Fn2BA300Item *q = p;
                while (q) {
                    if (q == it) return it;
                    q = q->next;
                }
                it->next = p;
                self->head = it;
                return it;
            }
            i++;
        } while (i < self->count);
    }
    return 0;
}
#endif
