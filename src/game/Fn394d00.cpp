extern unsigned int D_003F5520;

// DRAFT: GAME 0x00394D00
// 8 differing words: store order e[-1],e[0],e[1] best; return placement (temp r, early return, base ptr) and if/else forms tried, no further gain
#ifdef NONMATCHING
extern "C" int func_00394D00(int key) {
    unsigned int i;
    if (D_003F5520 != 0) {
        unsigned int *e = &D_003F5520 + 3;
        for (i = 0; i < D_003F5520; i++, e += 3) {
            if (e[0] == (unsigned int)key) {
                e[-1] = 0; e[0] = 0; e[1] = 0;
                return i;
            }
        }
    }
    return -1;
}
#endif
