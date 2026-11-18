// God Hand: unit in 0x2B3C20.

extern "C" int func_002B4690(char *, char *);
extern "C" void func_00306528(int, int, int, int, int, unsigned);
// FUNCTION: GAME 0x2B3C20
extern "C" int func_002B3C20(char *s)
{
    int r = func_002B4690(s, *(char **)(s + 0x8C) + 8);
    unsigned short *h = *(unsigned short **)(s + 0x8C);
    int n = h[3] + 1;
    unsigned tag = (h[2] << 16) | h[1];
    switch (tag) {
    case 0x45524F43:
    case 0x65726F63:
        func_00306528(0, n, r, 0, -1, 0xFFFFFFFF);
        break;
    case 0x4D4F4F52:
    case 0x6D6F6F72:
        func_00306528(1, n, r, 0, -1, 0xFFFFFFFF);
        break;
    }
    return 0;
}
