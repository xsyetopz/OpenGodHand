extern "C" {
void func_002FBE50(void *, int);
}
extern unsigned D_0071B7C0[], D_0071B840[], D_0071B8C0[];
extern char D_0061B7C0[];

static inline int bit(unsigned *a, unsigned i) {
    return (a[i >> 5] & (0x80000000u >> (i & 0x1F))) != 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2FB6C8  44 words; i++ placement/bnel delay slots and mask reg differ; variants: do-while, for, inline bit helper, nested ifs
extern "C" void func_002FB6C8(int a) {
    char *p = D_0061B7C0;
    unsigned i = 0;
    do {
        if (bit(D_0071B7C0, i)) {
            if (!bit(D_0071B840, i)) {
                if (!bit(D_0071B8C0, i)) {
                    if (*(short *)(p + 0x23A) == a)
                        func_002FBE50(p, (i >> 5) * 4);
                }
            }
        }
        i++;
        p += 0x400;
    } while ((int)i < 0x400);
}
#endif
