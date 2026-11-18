// COMPILER: ee-gcc2.96

int func_0035E868();

// FUNCTION: GAME 0x344F68
int func_00344F68(int a) {
    int r;
    if (func_0035E868(a, 0xE0, &r) != 1) return 0x11;
    switch (r) {
    case 0:
    case 2:
    case 4:
    case 5:
    case 7:
    case 8:
        return 0x11;
    case 1:
        return 0x21;
    case 3:
        return 0x51;
    case 6:
        return 0x61;
    default:
        return 0x11;
    }
}
