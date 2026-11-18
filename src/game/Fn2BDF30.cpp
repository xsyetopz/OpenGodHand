#ifdef NONMATCHING
// DRAFT: GAME 0x2BDF30
// 11 differing words: original has extra pre-loop v0=a1 copy and returns a1; tried for/do-while, copy pointer r.
extern "C" unsigned short *func_002BDF30(int, unsigned short *p, int n, float f) {
    unsigned short *r = p;
    int i = 0;
    if (n > 0) {
        do {
            i++;
            if (f <= (float)p[1])
                return r;
            p += 2;
            r += 2;
        } while (i < n);
    }
    return 0;
}
#endif
