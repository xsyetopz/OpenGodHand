// Const-ref temporary reproduces the lbu/sw-to-stack then register-branch pattern.
static inline int IsSet(const int &v) { return v != 0; }

struct V3 { float x, y, z; };
struct Dst {
    char pad[0xD0];
    V3 *p;
    char pad2[0x100 - 0xD4];
    int a, b;
    float c;
};
struct Obj {
    char pad0[0x278];
    Dst **pp;
    char pad1[0x2B4 - 0x27C];
    unsigned char f2B4;
    char pad2[0x2F4 - 0x2B5];
    unsigned char b2F4, b2F5, b2F6, b2F7;
    char pad3[0x610 - 0x2F8];
    V3 v610;
    char pad4[0x630 - 0x61C];
    V3 v630;
    char pad6[4];
    unsigned char b640;
    char pad5[0x644 - 0x641];
    int i644;
};

extern "C" float fRand1_1__Fv();

// FUNCTION: GAME 0x1C8BE0
extern "C" void SetThrow__8cOmThrowRC4cVec(Obj *self, const V3 *v)
{
    V3 *t = &self->v610;
    self->b2F5 = 1;
    self->b2F4 = 0;
    self->b2F6 = 0;
    self->b2F7 = 0;
    if (t != v) {
        self->v610.x = v->x;
        t->y = v->y;
        t->z = v->z;
    }
    self->i644 = 0;
    Dst *d;
    if (IsSet(self->f2B4))
        d = *self->pp;
    else
        d = 0;
    V3 *q;
    if (d) {
        V3 *s = &self->v630;
        q = d->p;
        if (q != s) {
            q->x = self->v630.x;
            q->y = s->y;
            q->z = s->z;
        }
        d->a = 0;
        d->b = 0;
        d->c = fRand1_1__Fv() * 0.5235988f + 0.5235988f;
        self->b640 = 0;
    }
}
