// COMPILER: ee-gcc2.9-991111
// SCE libstdc++ dtoa (upstream gcc-2.95 floatconv.c): mult, quorem; libio _IO_file_doallocate.

typedef struct Bigint {
    struct Bigint *next;
    int k;
    int maxwds;
    short on_stack;
    short sign;
    int wds;
    unsigned int x[1];
} Bigint;

#define Storeinc(a, b, c) (((unsigned short *)a)[1] = (unsigned short)b, \
    ((unsigned short *)a)[0] = (unsigned short)c, a++)

extern Bigint *func_0038F5B8(Bigint *, int);
extern int func_0038FDE8(Bigint *, Bigint *);

// mult
// FUNCTION: GAME 0x38F9B8
Bigint *func_0038F9B8(Bigint *c, Bigint *a, Bigint *b)
{
    int k, wa, wb, wc;
    unsigned int carry, y, z;
    unsigned int *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
    unsigned int z2;
    if (a->wds < b->wds) {
        Bigint *tmp = a;
        a = b;
        b = tmp;
    }
    k = a->k;
    wa = a->wds;
    wb = b->wds;
    wc = wa + wb;
    if (wc > a->maxwds)
        k++;
    c = func_0038F5B8(c, k);
    for (x = c->x, xa = x + wc; x < xa; x++)
        *x = 0;
    xa = a->x;
    xae = xa + wa;
    xb = b->x;
    xbe = xb + wb;
    xc0 = c->x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xffff)) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                Storeinc(xc, z2, z);
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16)) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                Storeinc(xc, z, z2);
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc)
        ;
    c->wds = wc;
    return c;
}

// quorem
// FUNCTION: GAME 0x391340
int func_00391340(Bigint *b, Bigint *S)
{
    int n;
    int borrow, y;
    unsigned int carry, q, ys;
    unsigned int *bx, *bxe, *sx, *sxe;
    int z;
    unsigned int si, zs;

    n = S->wds;
    if (b->wds < n)
        return 0;
    sx = S->x;
    sxe = sx + --n;
    bx = b->x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Storeinc(bx, z, y);
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->x;
            while (--bxe > bx && !*bxe)
                --n;
            b->wds = n;
        }
    }
    if (func_0038FDE8(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->x;
        sx = S->x;
        do {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            Storeinc(bx, z, y);
        } while (sx <= sxe);
        bx = b->x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe)
                --n;
            b->wds = n;
        }
    }
    return q;
}

struct VT { char pad[0x8C]; int (*stat)(void *, void *); };
struct F { int flags; char pad[0x34]; int fileno; char pad2[0x14]; struct VT *vt; };
struct St { int dev; int mode; char pad[0x40]; long blksize; char pad2[0x20]; };
extern void (*D_003F5518)(void);
extern void *malloc(unsigned int);
extern void _IO_setb(void *, char *, char *, int);
extern int func_003B0448(int);
// _IO_file_doallocate
// FUNCTION: GAME 0x38F3D8
int func_0038F3D8(struct F *fp)
{
    unsigned int size;
    int couldbetty;
    char *p;
    struct St st;

    if (D_003F5518)
        (*D_003F5518)();
    if (fp->fileno < 0 || fp->vt->stat(fp, &st) < 0) {
        couldbetty = 0;
        size = 0x400;
    } else {
        couldbetty = (st.mode & 0xF000) == 0x2000;
        size = st.blksize <= 0 ? 0x400 : st.blksize;
    }
    p = malloc(size);
    if (!p)
        return -1;
    _IO_setb(fp, p, p + size, 1);
    if (couldbetty && func_003B0448(fp->fileno))
        fp->flags |= 0x200;
    return 1;
}
