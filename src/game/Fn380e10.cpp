extern "C" void func_0031C900(int);
extern "C" void func_003298C0(int);
extern "C" void func_00329EA8(int);
extern "C" void func_0032B300(int, int);

// FUNCTION: GAME 0x00380E10
extern "C" void func_00380E10(int base) {
    int i;
    for (i = 9; i >= 0; i--) {
        char *p = (char *)base + 0x58 + (9 - i) * 0x48;
        if (*(int *)(p + 0x30) != 0) {
            func_00329EA8(*(int *)(p + 0x30));
            if (*(unsigned char *)(p - 0x10) != 0) {
                *(unsigned char *)(p - 0x10) = 0;
                func_0032B300(*(int *)(p + 0x30), 0);
            }
            func_003298C0(*(int *)(p + 0x30));
            *(int *)(p + 0x30) = 0;
            func_0031C900(*(int *)(p + 0x34));
        }
    }
}
