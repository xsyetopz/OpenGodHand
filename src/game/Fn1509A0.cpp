// FUNCTION: GAME 0x1509A0
extern "C" void func_001509A0(char *p) {
    *(int *)(p + 0x3C) = 0;
    
    int n = 0x280;
    do {
        char *q = p + n * 0x180 - 0x80;
        *(long *)(q - 0x40) = 0x70000002;
        *(int *)(q - 0x38) = 0;
        *(int *)(q - 0x34) = 0x50000002;
        *(long *)(q - 0x30) = (0x8000L << 45 | 0x8001);
        *(long *)(q - 0x28) = 0xE;
        *(long *)(q - 0x20) = 0xFF;
        *(long *)(q - 0x18) = 0x3F;
        *(int *)(q - 0xB8) = 0x11000000;
        *(long *)(q - 0x98) = 0x50;
        *(long *)(q - 0x90) = 0;
        *(long *)(q - 0x88) = 0x51;
        *(long *)(q - 0x78) = 0x52;
        *(long *)(q - 0xB0) = (0x8000L << 45 | 0x8004);
        *(long *)(q - 0xA8) = 0xE;
        *(long *)(q - 0x70) = 0;
        *(long *)(q - 0x68) = 0x53;
        *(long *)(q - 0x58) = 0;
        *(int *)(q - 0x48) = 0;
        *(long *)(q + 0x80) = 0x70000002;
        *(int *)(q + 0x88) = 0;
        *(int *)(q + 0x8C) = 0x50000002;
        *(long *)(q + 0x90) = (0x8000L << 45 | 0x8001);
        *(long *)(q + 0x98) = 0xE;
        *(long *)(q + 0xA0) = 0xFF;
        *(long *)(q + 0xA8) = 0x3F;
        *(int *)(q + 0x8) = 0x11000000;
        *(long *)(q + 0x28) = 0x50;
        *(long *)(q + 0x30) = 0;
        *(long *)(q + 0x38) = 0x51;
        *(long *)(q + 0x48) = 0x52;
        *(long *)(q + 0x10) = (0x8000L << 45 | 0x8004);
        *(long *)(q + 0x18) = 0xE;
        *(long *)(q + 0x50) = 0;
        *(long *)(q + 0x58) = 0x53;
        *(long *)(q + 0x68) = 0;
        *(int *)(q + 0x78) = 0;
            } while (--n != 0);
}
