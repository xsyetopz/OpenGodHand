// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/string/strrchr.c (0x3A93A8).
// FUNCTION: GAME 0x3A93A8
char *strrchr(const char *s, int i)
{
    const char *last = 0;
    char c = i;

    while (*s) {
        if (*s == c)
            last = s;
        s++;
    }
    return (char *)(*s != c ? last : s);
}
