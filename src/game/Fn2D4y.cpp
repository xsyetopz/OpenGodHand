extern "C" void func_00342888(int);
extern "C" void func_00326208();
extern "C" void func_003443C8(int);
extern "C" void free__5cHeapPv(int, int);
extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x2D40F8
extern "C" void func_002D40F8(int *s)
{
    if (s[0x3C / 4] < 0) {
        if (s[0])
            func_00342888(s[0]);
        if (s[0xA8 / 4])
            free__5cHeapPv(*(int *)(s[0xA8 / 4] - 0x20), s[0xA8 / 4]);
        s[0xA8 / 4] = 0;
        func_00326208();
    }
    if (s[0])
        func_003443C8(s[0]);
    if (s[1])
        free__5cHeapPv(*(int *)(s[1] - 0x20), s[1]);
    if (s[2])
        free__5cHeapPv(*(int *)(s[2] - 0x20), s[2]);
    if (s[3])
        free__5cHeapPv(*(int *)(s[3] - 0x20), s[3]);
    if (s[4])
        free__5cHeapPv(*(int *)(s[4] - 0x20), s[4]);
    if (s[5])
        free__5cHeapPv(*(int *)(s[5] - 0x20), s[5]);
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
    s[3] = 0;
    s[4] = 0;
    s[5] = 0;
    s[6] = 0;
    memset(s, 0, 0xAC);
    s[0x58 / 4] = -1;
    *(short *)((char *)s + 0x40) = 0x1F;
    *(short *)((char *)s + 0x42) = 0x64;
    s[0x5C / 4] = -1;
}
