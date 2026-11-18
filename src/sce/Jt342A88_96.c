// COMPILER: ee-gcc2.96

int func_00329F98(void);

// FUNCTION: GAME 0x342A88
int func_00342A88(void) {
    switch (func_00329F98()) {
    case 0:
        return 0;
    case 1:
    case 2:
        return 1;
    case 3:
    case 4:
        return 2;
    case 5:
        return 3;
    case 6:
    default:
        return 4;
    }
}
