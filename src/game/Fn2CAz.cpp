struct S6 { unsigned short a, b, c, d, e, f; };
struct S { unsigned short a, b, c, d, e, f; int x; int pad[4]; };
extern S6 SndEfxTbl[];
extern int D_0044CE40[];
extern "C" int func_003749D8(short, S *);
// FUNCTION: GAME 0x2CA390
extern "C" void func_002CA390(char *self, int idx)
{
    if (*(int *)(self + 0x130) != idx) {
        S6 *p = &SndEfxTbl[idx * 2];
        int *q = D_0044CE40;
        int i;
        for (i = 0; i < 2; i++) {
            S t;
            t.a = p->a;
            t.b = p->b;
            t.c = p->c;
            t.d = p->d;
            t.e = p->e;
            t.f = p->f;
            t.x = *q;
            if (func_003749D8(i, &t) == -1)
                return;
            q++;
            p++;
        }
        *(int *)(self + 0x130) = idx;
    }
}
