struct V3 { float x, y, z; };

struct Dst {
    char pad[0xD0];
    V3 *p;
    char pad2[0x100 - 0xD4];
    int a, b, c;
};

struct Obj {
    char pad0[0x278];
    Dst **pp;
    char pad1[0x2B4 - 0x27C];
    unsigned char f2B4;
    char pad2[0x2F4 - 0x2B5];
    unsigned char b2F4, b2F5, b2F6, b2F7;
    char pad3[0x610 - 0x2F8];
    int i610;
    float f614;
    int i618;
    char pad4[0x630 - 0x61C];
    V3 v630;
    char pad5[0x644 - 0x63C];
    int i644;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1C8D48
// 19 words differ: original stores byte to sp0 in the beqz delay slot and uses beqz/b where we emit beql; tried volatile sp0, ternary, init-then-if, decl order
extern "C" void func_001C8D48(Obj *self) {
    int t = self->f2B4;
    self->b2F5 = 3;
    self->f614 = 0.065f;
    self->b2F4 = 0;
    self->b2F6 = 0;
    self->b2F7 = 0;
    self->i610 = 0;
    self->i618 = 0;
    self->i644 = 0;
    Dst *d;
    volatile int sp0 = t;
    if (t)
        d = *self->pp;
    else
        d = 0;
    V3 *v = &self->v630;
    if (d) {
        V3 *q = d->p;
        if (q != v) {
            q->x = self->v630.x;
            q->y = v->y;
            q->z = v->z;
        }
        d->c = 0;
        d->a = 0;
        d->b = 0;
    }
}
#endif
