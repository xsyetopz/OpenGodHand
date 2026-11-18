struct Q383 {
    int q0, q4, n;
    char pad[0x0C];
    unsigned char b[8];
    int m20;
};
struct P383 {
    int p0, p4;
    short s[0x4E];
    Q383 q;
};
extern "C" {
int func_00383280(int, Q383 *);
void func_0032EC78(int, int, int);
void func_0032A9F0(int, int);
}

// FUNCTION: GAME 0x383170
extern "C" void func_00383170(int a, P383 *p, unsigned char f)
{
    if (f) {
        Q383 *q = &p->q;
        if (func_00383280(a, q)) {
            for (int i = 0; i < q->n; i++) {
                if (q->b[i + 1])
                    func_0032EC78(q->m20, i, -0x3C0);
                else
                    func_0032EC78(q->m20, i, p->s[i + 1]);
            }
        } else {
            for (int i = 0; i < q->n; i++)
                func_0032EC78(q->m20, i, p->s[i + 1]);
        }
    } else {
        func_0032A9F0(*(int *)((char *)p + 0x64), p->s[0]);
    }
}
