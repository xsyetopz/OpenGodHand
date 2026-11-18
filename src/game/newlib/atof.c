// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdlib/atof.c (0x3A7C28).
extern double strtod(const char *, char **);

// FUNCTION: GAME 0x3A7C28
double atof(const char *s)
{
    return strtod(s, (char **)0);
}
