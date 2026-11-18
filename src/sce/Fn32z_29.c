// COMPILER: ee-gcc2.9-991111

// FUNCTION: GAME 0x321980
unsigned char *func_00321980(unsigned char *p, int *out)
{
    unsigned sh = 0;
    int v = 0;
    unsigned char b;
    do {
        b = *p++;
        v |= (b & 0x7F) << sh;
        sh += 7;
    } while (b & 0x80);
    if (sh < 32 && (b & 0x40))
        v |= -1 << sh;
    *out = v;
    return p;
}

// FUNCTION: GAME 0x321D38
int func_00321D38(int *p)
{
    int n = 0;
    int off = p[0];
    int t;
    if (off) {
        for (;;) {
            if (p[1] && p[2])
                n++;
            t = *(int *)((char *)p + off + 4);
            p = (int *)((char *)p + off + 4);
            if (!t)
                break;
            off = t;
        }
    }
    return n;
}

// FUNCTION: GAME 0x321D80
struct V321 { int *data; int count; };
void func_00321D80(int *p, struct V321 *v, unsigned *pmin, unsigned *pmax)
{
    unsigned lo = *pmin;
    unsigned hi = *pmax;
    while (p[0]) {
        if (p[1] && p[2]) {
            unsigned a, e;
            v->data[v->count++] = (int)p;
            a = p[2];
            e = a + p[3];
            if (a < lo)
                lo = a;
            if (hi < e)
                hi = e;
        }
        p = (int *)((char *)p + p[0] + 4);
    }
    *pmin = lo;
    *pmax = hi;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31CDC0 (28 words differ: original hoists the found-return block ahead of the loop and uses a pointer walk)
char *func_0031CDC0(unsigned *p, unsigned *a, unsigned *b, int idx)
{
    unsigned n, i;
    int k = 0;
    if (p == 0)
        return 0;
    n = p[0];
    for (i = 1; i <= n; i++) {
        unsigned v = p[i];
        if (v == *a || v == *b) {
            if (k == idx)
                return (char *)p + p[i];
            k++;
        }
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x321E08
extern void *malloc(unsigned);
extern void *func_00321AD0(void *, int);
struct O { unsigned lo, hi; int *a; int **b; int n; };
struct L { int *d1; int c1; int *d2; int c2; unsigned lo, hi; };
void func_00321E08(struct O *o)
{
    int **q;
    int n;
    struct L l;
    if (o->b) {
        n = 0;
        for (q = o->b; *q; q++)
            n += func_00321D38(*q);
    } else {
        n = func_00321D38(o->a);
    }
    o->n = n;
    l.d1 = malloc(n * 4);
    l.d2 = malloc(n * 4);
    l.lo = 0xFFFFFFFF;
    l.c1 = 0;
    l.c2 = 0;
    l.hi = 0;
    if (o->b) {
        for (q = o->b; *q; q++)
            func_00321D80(*q, (struct V321 *)&l, &l.lo, &l.hi);
    } else {
        func_00321D80(o->a, (struct V321 *)&l, &l.lo, &l.hi);
    }
    o->b = func_00321AD0(&l, n);
    o->lo = l.lo;
    o->hi = l.hi;
}

// FUNCTION: GAME 0x322030
extern int strcmp(const char *, const char *);
extern int strlen(const char *);
extern char D_004512C0[], D_004512C8[];
struct U { int v; } __attribute__((packed));
struct S { char *str; int a; unsigned b; int c; int d; };
unsigned char *func_00322030(int *cie, struct S *s)
{
    unsigned char *p;
    unsigned char *e;
    unsigned len;
    s->str = (char *)cie - cie[1] + 0xD;
    if (strcmp(s->str, D_004512C0) != 0 && strcmp(s->str, D_004512C8) != 0 && s->str[0] != 'z')
        return 0;
    e = (unsigned char *)s->str + strlen(s->str);
    p = e + 1;
    if (strcmp(s->str, D_004512C8) == 0) {
        s->a = ((struct U *)p)->v;
        p = e + 5;
    } else {
        s->a = 0;
    }
    p = func_00321938(p, &s->b);
    p = func_00321980(p, &s->c);
    s->d = *p++;
    if (s->str[0] == 'z') {
        p = func_00321938(p, &len);
        p += len;
    }
    return p;
}

// FUNCTION: GAME 0x3224F8
extern void free(void *);
extern void abort(void) __attribute__((noreturn));
struct N { int a; int b; int key; void *p; int c; struct N *next; };
extern struct N *D_00755C18;
struct N *func_003224F8(int key)
{
    struct N **pp = &D_00755C18;
    struct N *n;
    if (*pp) {
        do {
            n = *pp;
            if (n->key == key) {
                *pp = n->next;
                if (n->a)
                    free(n->p);
                return n;
            }
            pp = &n->next;
        } while (*pp);
    }
    abort();
}
