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
