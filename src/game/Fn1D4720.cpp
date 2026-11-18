#ifdef NONMATCHING
// DRAFT: GAME 0x1D4720
// 27 words differ (register allocation: a/i/p get a3/a1/a2 vs a1/a3/a2, loop3 counter); variants: decl order, split/shared counters, ternary vs if.
extern "C" int func_001D4720(char *self)
{
    char ***p, ***q;
    int i, c, v, j, a, t, w;
    a = 0;
    unsigned short n = *(unsigned short *)(self + 0x17FC);
    if (n) {
        i = n;
        p = (char ***)(self + 0x17D4);
        do {
            t = *(int *)(**p + 0x604);
            if (t) {
                if ((unsigned)(t - 1) < 9u) a = a + 1 + t;
                else a += 10;
            }
            i--;
            p++;
        } while (i);
    }
    c = 0;
    if (*(unsigned short *)(self + 0x17FC)) {
        q = (char ***)(self + 0x17D4);
        i = *(unsigned short *)(self + 0x17FC);
        do {
            i--;
            if (*(int *)(**q + 0x604) == 0) c = (c + 1) & 0xFFFF;
            q++;
        } while (i);
    }
    if (c) {
        v = c - 1;
        do {
            j = v & 0xFFFF;
            if (j) a++;
            else {
                w = a + 11;
                if (w < 22) a = w;
                else a++;
            }
            v = j - 1;
        } while (j);
    }
    return a;
}

// DRAFT: GAME 0x1D47E8
extern "C" int func_001D47E8(char *self)
{
    char ***p, ***q;
    int i, c, v, j, a, t, w;
    a = 0;
    unsigned short n = *(unsigned short *)(self + 0x17FE);
    if (n) {
        i = n;
        p = (char ***)(self + 0x17E8);
        do {
            t = *(int *)(**p + 0x604);
            if (t) {
                if ((unsigned)(t - 1) < 9u) a = a + 1 + t;
                else a += 10;
            }
            i--;
            p++;
        } while (i);
    }
    c = 0;
    if (*(unsigned short *)(self + 0x17FE)) {
        q = (char ***)(self + 0x17E8);
        i = *(unsigned short *)(self + 0x17FE);
        do {
            i--;
            if (*(int *)(**q + 0x604) == 0) c = (c + 1) & 0xFFFF;
            q++;
        } while (i);
    }
    if (c) {
        v = c - 1;
        do {
            j = v & 0xFFFF;
            if (j) a++;
            else {
                w = a + 11;
                if (w < 22) a = w;
                else a++;
            }
            v = j - 1;
        } while (j);
    }
    return a;
}
#endif
