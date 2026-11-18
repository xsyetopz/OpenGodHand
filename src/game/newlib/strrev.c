// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// String reverse helper used by itoa (0x3A95A8).

// FUNCTION: GAME 0x3A95A8
char *func_003A95A8(char *s)
{
    int len = 0;
    int i;
    char c;

    while (s[len])
        len++;
    len--;
    for (i = 0; i < len; i++, len--) {
        c = s[i];
        s[i] = s[len];
        s[len] = c;
    }
    return s;
}
