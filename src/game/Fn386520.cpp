// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn386Rep {
    int len;
    unsigned cap;
    int ref;
    int share;
};
struct Fn386Str {
    int **p0;
    int **p4;
};
extern "C" void free(void *);
extern "C" int *func_003BB058(int *);
extern "C" int strlen(const char *);
extern "C" void func_003BB178(Fn386Str *, int, int, const char *, int);
extern int *D_003C4030[];
extern char D_0045D018[];

// FUNCTION: GAME 0x386520
extern "C" void func_00386520(int **a, const char *s)
{
    int **q = a + 1;
    if (a != q) {
        int *v = *q;
        Fn386Rep *r = (Fn386Rep *)(v - 4);
        if (--r->ref == 0) {
            if (r->cap + 16 > 0x80) {
                free(r);
            } else {
                int **slot = (int **)((char *)D_003C4030 + ((((r->cap + 23) >> 3) - 1) << 2));
                *(int **)(v - 4) = *slot;
                *slot = (int *)r;
            }
        }
        int *w = a[0];
        int *h = w - 4;
        if (h[3] != 0)
            w = func_003BB058(h);
        else
            h[2]++;
        *q = w;
    }
    int n = strlen(s);
    func_003BB178((Fn386Str *)a, *(int *)(a[0] - 4), 0, s, n);
    n = strlen(D_0045D018);
    func_003BB178((Fn386Str *)a, *(int *)(a[0] - 4), 0, D_0045D018, n);
}
