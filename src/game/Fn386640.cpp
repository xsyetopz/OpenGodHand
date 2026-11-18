extern char D_0045D008;

// DRAFT: GAME 0x00386640
// 14 differing words: loop reg alloc (0x2F in a3 vs t0, acc copy via v0, extra lui a3); tried char n counter, hoisted k, t copy
#ifdef NONMATCHING
extern "C" int func_00386640(char **pp) {
    int r = -1;
    char *s;
    if (*(int *)(*pp - 0x10) == 0) {
        s = &D_0045D008;
    } else {
        (*pp)[*(int *)(*pp - 0x10)] = 0;
        s = *pp;
    }
    char c = *s++;
    if (c != 0) {
        int acc = (r << 24) + 0x1000000;
        int t;
        do {
            if (c == '/') {
                t = acc;
                r = t >> 24;
                acc = t + 0x1000000;
            }
            c = *s++;
        } while (c != 0);
    }
    return r > -1 ? r : 0;
}
#endif
