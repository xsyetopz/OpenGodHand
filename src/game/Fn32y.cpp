// COMPILER: ee-gcc2.96
struct Sl { char st; char p1, p2, f3; char pad[0x5C]; };
extern int D_003D04B4, D_003D04B8;
extern Sl D_003D04D0[];
extern "C" void func_00327A50(Sl *, int, int, int, int);
// FUNCTION: GAME 0x327B58
extern "C" Sl *func_00327B58(int a, int b, int c, int d)
{
    Sl *s = 0;
    int i = 0;
    if (D_003D04B8 > 0) {
        for (; i < D_003D04B8; i++) {
            s = &D_003D04D0[D_003D04B4 + i];
            if (s->st == 0) break;
        }
    }
    if (i == D_003D04B8) return 0;
    func_00327A50(s, a, b, c, d);
    s->f3 = 1;
    return s;
}

struct Q { char b0, b1, b2, b3; int h; int f8; int arr[15]; int f48, f4C, f50, f54; int pad[21]; };
extern Q D_003CF9F0[16];
extern "C" int func_00339FF8(int);
extern "C" int func_0033A000(int);
extern "C" int func_0033A008(int);
extern "C" int func_0033C7F8(int, int, int, int);
extern "C" void func_0033CE68(int, void *, Q *);
extern "C" void func_00326B98();
extern "C" void func_00326568(Q *);
// FUNCTION: GAME 0x3265A8
extern "C" Q *func_003265A8(int a, int n, int *p)
{
    int i;
    int v = *p;
    for (i = 0; i < 16; i++)
        if (!D_003CF9F0[i].b0) break;
    if (i == 16) return 0;
    Q *q = &D_003CF9F0[i];
    int f1 = func_00339FF8(v);
    int w = func_0033A000(v) / 2;
    int h = func_0033C7F8(n, f1, w, w + func_0033A008(v) / 2);
    q->h = h;
    if (h) {
        func_0033CE68(h, (void *)func_00326B98, q);
        q->f8 = a;
        q->b2 = n;
        for (int k = 0; k < n; k++) q->arr[k] = p[k];
        q->b1 = 0;
        func_00326568(q);
        q->f48 = 0;
        q->f4C = 0;
        q->f50 = 0;
        q->f54 = 0;
        q->b0 = 1;
        return q;
    }
    return 0;
}

extern int D_003D04BC, D_003D04C0;

// FUNCTION: GAME 0x327C30
extern "C" Sl *func_00327C30(int a, int b, int c, int d)
{
    Sl *s = 0;
    int i = 0;
    if (D_003D04C0 > 0) {
        for (; i < D_003D04C0; i++) {
            s = &D_003D04D0[D_003D04BC + i];
            if (s->st == 0) break;
        }
    }
    if (i == D_003D04C0) return 0;
    func_00327A50(s, a, b, c, d);
    s->f3 = 0;
    return s;
}
