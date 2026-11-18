extern "C" int func_001FF238(void *);

struct DM {
    char pad[4];
    int n;
    char *p;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x28FE58
// 25 words differ: s0/s1 register swap (count vs pointer) and extra move/nop; tried decl order, hoisted pointer, temp for call result
extern "C" int func_0028FE58(DM *self) {
    int c = 0;
    char *q = self->p;
    int i = 0;
    if (self->n > 0) {
        do {
            i++;
            int r = func_001FF238(q);
            q += 0x5C;
            if (r == 1)
                c++;
        } while (i < self->n);
    }
    return c;
}
#endif
