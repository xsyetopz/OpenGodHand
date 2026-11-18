// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdlib/atoi.c (0x3A7C48).
extern long strtol(const char *, char **, int);

// FUNCTION: GAME 0x3A7C48
int atoi(const char *s)
{
    return (int)strtol(s, (char **)0, 10);
}
