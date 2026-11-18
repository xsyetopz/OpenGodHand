extern "C" int func_003447A8(int, int, int);
extern "C" void func_00344E88(int, int);

// FUNCTION: GAME 0x002D4248
extern "C" int func_002D4248(int *p) {
    if (func_003447A8(p[0], (int)p + 0x58, p[2]) == 1) {
        if (p[0x58 / 4] != p[0x5C / 4]) {
            if (p[0x5C / 4] >= 0) {
                func_00344E88(p[0], p[0x5C / 4]);
            }
            p[0x5C / 4] = p[0x58 / 4];
        }
        return 1;
    }
    return 0;
}
