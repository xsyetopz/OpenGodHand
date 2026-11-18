// Sole switch of 0x2AB9A8.
extern "C" void func_002AF6A8(void *, int, int);
extern char D_005E7510[];
// FUNCTION: GAME 0x2AB9A8
extern "C" void func_002AB9A8(int, unsigned char x)
{
    unsigned r = x % 10;
    unsigned q = (unsigned char)(x / 10);
    switch (r) {
    case 1: func_002AF6A8(D_005E7510, 3, q); break;
    case 2: func_002AF6A8(D_005E7510, 4, q); break;
    case 3: func_002AF6A8(D_005E7510, 5, q); break;
    case 4: func_002AF6A8(D_005E7510, 6, q); break;
    case 5: func_002AF6A8(D_005E7510, 7, q); break;
    case 6: func_002AF6A8(D_005E7510, 8, q); break;
    case 7: func_002AF6A8(D_005E7510, 9, q); break;
    default: func_002AF6A8(D_005E7510, 2, q); break;
    }
}
