struct E05D8 { int a, b; };
struct T05D8 { E05D8 *tbl; int _4; char *rec; };
struct O05D8 { char _p[0x30]; T05D8 *t; };

#ifdef NONMATCHING
// DRAFT: GAME 0x002D05D8
// 17 words: original keeps t in v0 with bnel delay-slot load, ours beqz and different regs; early-return/nested variants tried
extern "C" char *func_002D05D8(O05D8 *o, int i, int *out) {
    if (!o->t)
        return 0;
    E05D8 *e = &o->t->tbl[i];
    if (!e->b)
        return 0;
    *out = e->b;
    return o->t->rec + e->a * 12;
}
#endif
