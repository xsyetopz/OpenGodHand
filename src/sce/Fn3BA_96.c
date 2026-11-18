// COMPILER: ee-gcc2.96
extern void func_003B9DE0(char *);
struct Dec;
extern void func_003BA148(struct Dec *);
extern void func_003B9DB0(void);
extern void func_003B9DC8(void);
extern char D_00460950[];
// FUNCTION: GAME 0x3BA0C8
void func_003BA0C8(int *p)
{
    int i;
    if (p == 0) {
        func_003B9DE0(D_00460950);
        return;
    }
    func_003B9DB0();
    for (i = 0; i < p[6]; i++)
        func_003BA148((struct Dec *)p);
    func_003B9DC8();
}

struct VT {
    int pad[6];
    int (*f18)(void *, int, int, int *);
    int (*f1C)(void *, int, int *);
    int (*f20)(void *, int, int *);
    int (*f24)(void *, int);
};
struct St {
    struct VT *vt;
};
struct Dec {
    int pad0;
    int state;
    int *p8;
    int pad0C;
    struct St *in;
    struct St *in2;
    int pad18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int pad2C;
    int pad30;
    int f34;
};
extern int func_003BA370(int, int);
extern void func_0033ACA0(int *, int, int *, int *);
extern int func_003BA3D8(struct Dec *, int);
extern int func_003BA4F8(struct Dec *, int);
extern void func_003BA550(struct Dec *);
extern int func_003BA5A0(struct Dec *);
extern void func_003BA6C0(int *, int);
extern int func_003BA708(struct Dec *);

#ifdef NONMATCHING
// DRAFT: GAME 0x3BA148 (31 words off: original emits state=4 block before success stores; goto and if/else tails both give success first)
void func_003BA148(struct Dec *d)
{
    int a[4];
    int b[4];
    if (d->state == 1)
        d->state = 2;
    if (d->f24 == 1) {
        if (d->in->vt->f24(d->in, 1) <= 0)
            d->state = 3;
    }
    if (d->state != 2)
        return;
    if (d->in2->vt->f24(d->in2, 0) < 0x1800)
        return;
    d->in->vt->f18(d->in, 1, 0x7FFFFFFF, a);
    func_0033ACA0(a, func_003BA370(a[0], a[1]), a, b);
    d->in->vt->f20(d->in, 0, a);
    d->in->vt->f1C(d->in, 1, b);
    d->in->vt->f18(d->in, 1, 6, a);
    if (a[1] < 6) {
        d->in->vt->f1C(d->in, 1, a);
        return;
    }
        if (func_003BA3D8(d, a[0]) >= 0 && func_003BA4F8(d, a[0] + 4) >= 0) {
        d->in->vt->f1C(d->in, 1, a);
        if (d->in->vt->f24(d->in, 1) < d->f34)
            return;
        func_003BA550(d);
        if (func_003BA5A0(d) >= 0) {
            if (d->f28 == 1)
                func_003BA6C0(d->p8, 0x1800);
            if (func_003BA708(d) < 0) {
                d->state = 4;
            } else {
                d->f20 += 0x1800;
                d->f1C += d->f34;
            }
            return;
        }
    }
    d->state = 4;
}
#endif
