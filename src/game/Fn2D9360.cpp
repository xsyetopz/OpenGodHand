struct Tbl {
    unsigned int n;
};

struct Own {
    char pad[0x16130];
    Tbl *t;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x2D9360
// 9 words differ: n in t0 vs a3 for result, peel base v1 vs a2, peel load 0(v1) vs 0x14(a2); tried 5 stmt orders (RNI/RIN/NRI/NIR/IRN all 9), decl order, union pun, t->v14 peel (22), explicit n!=0 peel (32)
extern "C" float func_002D9360(Own *self, int id) {
    Tbl *t = self->t;
    char *e;
    if (t == 0 || (e = (char *)t + 0x14, id == 0))
        return 1.0f;
    unsigned int n = t->n;
    union { float f; int i; } r;
    r.f = 1.0f;
    for (unsigned int i = 0; i < n; i++) {
        if (((unsigned char *)e)[-2] == id) {
            r.i = *(int *)e;
            break;
        }
        e += 0x50;
    }
    return r.f;
}
#endif
