struct N002CBF78 {
    char pad0[4];
    N002CBF78 *next;
    short a;
    short b;
    int flags;
    char pad10[0x14];
    int key;
};

struct H002CBF78 {
    char pad[0x1C];
    N002CBF78 *head;
};

// DRAFT: GAME 0x2CBF78 (40 differing words: loop-invariant 1 hoisted to t5 and mode branch layout differ; tried continue-style, switch-like nesting, key temp)
#ifdef NONMATCHING
extern "C" N002CBF78 *func_002CBF78(H002CBF78 *self, N002CBF78 *skip, short a, short b, int mode, int limit)
{
    N002CBF78 *best = 0;
    N002CBF78 *n = self->head;
    while (n) {
        if (n->a == a && n->b == b && n != skip) {
            if (mode == 1) {
                if (n->flags & 1)
                    return n;
            } else if (mode < 2) {
                if (mode == 0) {
                    if ((n->flags & 1) != 1)
                        return n;
                }
            } else if (mode == 2) {
                if (!(limit < n->key)) {
                    if (best == 0)
                        best = n;
                    else if (n->key < best->key)
                        best = n;
                }
            }
        }
        n = n->next;
    }
    return best;
}
#endif
