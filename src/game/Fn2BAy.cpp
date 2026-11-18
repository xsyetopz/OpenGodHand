// God Hand: unit in 0x2BAC98.

extern char D_0042C320[];
// FUNCTION: GAME 0x2BAC98
extern "C" void func_002BAC98(char *s)
{
    char *b = s + 0x14;
    char *e;
    if (b) {
        e = s + 0x34;
        while (b != e)
            e -= 8;
    }
    *(unsigned *)s &= ~0x603u;
    *(char **)(s + 8) = D_0042C320;
}
