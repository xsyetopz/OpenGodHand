extern "C" void func_001DBFB8(void *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);

struct Sub1DC {
    char pad[0x604];
    int k;
};
struct Obj1DC {
    Sub1DC *s;
    int flags;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x001DC4C0
// 12 words: orig keeps i+1 (t1) live across the outer loop with the i<4 test and a copy of base (t5->t4); tried do-while with j/i=j (30), i++<4 (14)
extern "C" int func_001DC4C0(char *self)
{
    unsigned short x[5], y[5];
    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    if (y[0] == 4 || y[1] == 4) {
        Obj1DC **base = (Obj1DC **)(self + 0x3004);
        int i;
        for (i = 0; i < 5; i++) {
            Obj1DC **p = base;
            int n = 4;
            unsigned short cnt;
            int k;
            do {
                (*p)->flags &= ~4;
                p++;
            } while (--n >= 0);
            cnt = 0;
            for (k = i + 1; k < 5; k++) {
                Obj1DC *a = base[i];
                Obj1DC *b = base[k];
                if (a->s->k == b->s->k) {
                    cnt = cnt + 1;
                    a->flags |= 4;
                    base[k]->flags |= 4;
                }
            }
            if (cnt == 3)
                break;
        }
        return 1;
    }
    return 0;
}
#endif
