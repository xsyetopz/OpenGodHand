struct Out {
    unsigned char kind;
    char *base;
    char *cur;
    unsigned short cnt;
    unsigned short val;
    union {
        int i;
        float f;
    } u;
};
struct In {
    unsigned int hdr;
    int pad2;
    union {
        int off;
        float f;
    } u;
};
extern "C" void func_00159DA0(Out *, char *, In *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1599B0
// 61 words differ: p copied to t0 instead of in-place a1, branch order (orig tests ==1, <2, ==3, ==5); tried switch (orders 1,3,5 / 5,1,3), if-chain.
extern "C" void func_001599B0(Out *o, char *p, In *in)
{
    int t = (in->hdr >> 12) & 0xF;
    unsigned char k = t;
    o->kind = t;
    if (k == 1) {
        p += in->u.off;
        o->base = p;
        o->cur = p + 0xC;
        if (*(unsigned short *)((char *)in + 2) < 2) {
            o->u.i = 0;
            o->kind = 0;
            return;
        }
        o->cnt = 0;
        o->cur = p + 0x10;
        o->val = *(unsigned char *)(p + 0x10);
        func_00159DA0(o, p, in);
        return;
    }
    if (k >= 2 && k == 3) {
        p += in->u.off;
        o->base = p;
        o->cur = p + 0x18;
        if (*(unsigned short *)((char *)in + 2) < 2) {
            o->u.i = 0;
            o->kind = 0;
            return;
        }
        o->cnt = 0;
        o->cur = p + 0x20;
        o->val = *(unsigned short *)(p + 0x20);
        func_00159DA0(o, p, in);
        return;
    }
    if (k >= 2 && k == 5) {
        char *q = p + in->u.off;
        o->cur = q;
        if (*(unsigned short *)((char *)in + 2) < 2) {
            o->u.i = 0;
            o->kind = 0;
            return;
        }
        o->cnt = 0;
        o->cur = q + 0x10;
        o->val = *(unsigned short *)(q + 0x10);
        func_00159DA0(o, p, in);
        return;
    }
    o->u.f = in->u.f;
}
#endif
