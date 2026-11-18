#ifdef NONMATCHING
// DRAFT: GAME 0x2BEAA8
// 17 differing words: n loaded into v0 then copied to a3, loop nop alignment; tried copy var q/m, key cast.
extern "C" unsigned short *func_002BEAA8(unsigned **pp, int id) {
    unsigned *h = *pp;
    if (h) {
        unsigned short key = id;
        unsigned n = *h;
        unsigned m = n;
        unsigned i = 0;
        if (n != 0) {
            unsigned short *p = (unsigned short *)((char *)h + 0x10);
            unsigned short *q = p;
            do {
                i++;
                if (*p == key)
                    return q;
                q += 2;
                p += 2;
            } while (i < m);
        }
    }
    return 0;
}
#endif
