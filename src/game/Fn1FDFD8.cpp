// Unnamed unit in 0x1FDFD8.
extern "C" void func_001FCEB0(void *);
extern "C" void func_001FCF20(void *);
extern "C" void func_001FD448(void *);
extern "C" void func_001FD528(void *);
extern "C" void func_001FD770(void *);

struct Fn1FA { char _p[0x4A]; unsigned char m_4A; char _q[0x60 - 0x4B]; };
struct Fn1FB { char _p[0x4A]; unsigned char m_4A; char _q[0x70 - 0x4B]; };
struct Fn1FMgr {
    Fn1FA a[160];
    Fn1FB b[256];
    char _pad[0xACD0 - 0x3C00 - 0x7000];
    int m_cnt;
};

// DRAFT: GAME 0x1FDFD8
// 74 words differ: gcc CSEs self+0x3C00 into a saved reg (extra s-reg, frame 0x50 vs 0x40); tried char* loops, struct arrays, int/unsigned counters.
#ifdef NONMATCHING
extern "C" void func_001FDFD8(Fn1FMgr *self)
{
    if (self->m_cnt) {
        self->m_cnt = self->m_cnt - 1;
        return;
    }
    Fn1FA *p;
    for (p = self->a; p < (Fn1FA *)self->b; p++)
        if (p->m_4A) func_001FCEB0(p);
    unsigned i;
    Fn1FB *q = self->b;
    for (i = 0; i < 256u; i++, q++)
        if (q->m_4A) func_001FD448(q);
    for (p = self->a; p < (Fn1FA *)self->b; p++)
        if (p->m_4A) { func_001FCF20(p); func_001FD770(p); }
    q = self->b;
    for (i = 0; i < 256u; i++, q++)
        if (q->m_4A) { func_001FD528(q); func_001FD770(q); }
}
#endif
