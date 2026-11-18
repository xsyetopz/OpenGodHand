struct Q820 {
    int q0, q4, n;
    char pad[0x0C];
    unsigned char b[8];
    int m20;
};
struct P820 {
    unsigned char b0, b1, b2, b3;
    short s[22];
    Q820 q;
};
extern "C" void func_0032EC78(int, int, int);

// FUNCTION: GAME 0x3820C0
extern "C" void func_003820C0(int a, P820 *p)
{
    Q820 *q = &p->q;
    if (p->b2 == 0) {
        for (int i = 0; i < 4; i++) {
            ((unsigned short *)((char *)p + 0x10))[i] = p->s[5];
            p->s[i + 1] = p->s[0];
        }
    }
    if (q->m20) {
        if (p->b2) {
            if (q->b[p->b2] == 0)
                func_0032EC78(q->m20, p->b2 - 1, p->s[p->b2]);
        } else {
            for (int i = 0; i < q->n; i++) {
                if (q->b[i + 1] == 0)
                    func_0032EC78(q->m20, i, p->s[p->b2]);
            }
        }
    }
}
