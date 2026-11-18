#ifdef NONMATCHING
// DRAFT: GAME 0x37ABA0
// 45 words differ: gcc merges the duplicate toggle cases (2/6, 3/5) and rewrites tests as xori; original keeps 6 separate blocks with distinct branch polarity; tried case reorder and polarity swaps.
extern "C" void func_0037ABA0(char *self, char *arg)
{
    if (*(unsigned *)(self + 0x38) & 0xA000) {
        char sel = arg[8];
        unsigned short *p = *(unsigned short **)arg;
        unsigned f = *p;
        switch (sel) {
        case 2:
            if (!(f & 0x10)) {
                f &= 0xFFEF;
                f |= 0x20;
            } else {
                f &= 0xFFDF;
                f |= 0x10;
            }
            break;
        case 3:
            if (!(f & 1)) {
                f &= 0xFFFE;
                f |= 2;
            } else {
                f &= 0xFFFD;
                f |= 1;
            }
            break;
        case 5:
            if (f & 1) {
                f &= 0xFFFD;
                f |= 1;
            } else {
                f &= 0xFFFE;
                f |= 2;
            }
            break;
        case 6:
            if (f & 0x10) {
                f &= 0xFFDF;
                f |= 0x10;
            } else {
                f &= 0xFFEF;
                f |= 0x20;
            }
            break;
        case 0:
        case 7:
            f ^= 2;
            break;
        case 1:
        case 4:
        case 8:
            f ^= 1;
            break;
        }
        *p = f;
    }
}
#endif
