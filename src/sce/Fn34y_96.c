// COMPILER: ee-gcc2.96
typedef struct O O;
typedef struct { char pad[0x1C]; void (*f1c)(O *, int, int *); void (*f20)(O *, int, int); } V;
struct O { V *vt; };
typedef struct { char pad[0x14]; void (*f)(void *); } V14;
typedef struct { char pad[0x3C]; int (*f)(int, int, int, int *); } V3C;
extern char D_00458F10[];
void func_0033ACA0(int, int, int, int *);
int func_00346828(int);
void func_00348BE0(char *);
void func_00347E58(int, int);
void func_00345D40(int, int);
void func_00346100(int);
void func_003358B8(int);
void func_00342FF8(int);
int func_0034A9B8(int, int *, int *);
int func_0034AA00(int, int);
void func_0034AA20(int);

// FUNCTION: GAME 0x349FB0
void func_00349FB0(O *a, int b, int c)
{
    int t;
    if (b == 0) {
        ((void (*)(O *))a->vt->f1c)(a);
    } else {
        func_0033ACA0(c, b, c, &t);
        a->vt->f20(a, 1, c);
        a->vt->f1c(a, 0, &t);
    }
}

// FUNCTION: GAME 0x347868
void func_00347868(int a)
{
    V14 **o;
    if (func_00346828(a) != 1) { func_00348BE0(D_00458F10); return; }
    func_00347E58(a, 1);
    func_00345D40(a, *(int *)(a + 0x1C0));
    func_00346100(a);
    func_003358B8(*(int *)(a + 0x48));
    o = *(V14 ***)(a + 0x1BC);
    if (o) (*o)->f(o);
    func_00342FF8(a);
    *(int *)(a + 0x2D4) = 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x349EF0
// diff: 7 words, v0/v1 swapped for t[1] and the 0x3C method pointer, a0/a3 setup order around the first call
int func_00349EF0(int a, int *out)
{
    int t[3];
    V3C *v;
    int r;
    *out = 0;
    v = *(V3C **)(a + 0x2004);
    r = func_0034A9B8(a, &t[0], &t[1]);
    if (r == 0) {
        *out = t[1];
        v->f(a, t[0], t[1], &t[2]);
        r = func_0034AA00(a, t[2]);
        if (r == 0) {
            func_0034AA20(a);
            return 0;
        }
    }
    return r;
}
#endif
