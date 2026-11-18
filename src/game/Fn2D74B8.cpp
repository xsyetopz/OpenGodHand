#ifdef NONMATCHING
// DRAFT: GAME 0x002D74B8
// DRAFT: gcc if-converts the u8 range flags (movz/movn); orig branches (slti/xori/beqz); tried inline helper, && form, r=a>=lo;if(r) r=a<hi
extern "C" int func_002D74B8(int a) {
    unsigned char r = 0;
    if (a >= 0x100) r = a < 0x200;
    if (r) return 1;
    r = 0;
    if (a >= 0x200) r = a < 0x301;
    if (r) return 1;
    r = 0;
    if (a >= 0x300) r = a < 0x501;
    if (r) return 1;
    r = 0;
    if (a >= 0x500) r = a < 0x601;
    if (r) return 1;
    return (unsigned)(a - 0xFF01) < 2;
}
#endif
