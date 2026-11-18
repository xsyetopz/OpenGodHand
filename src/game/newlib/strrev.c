// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// In-place string reverse (0x3A95A8), strlen loop then pairwise swap.
// FUNCTION: GAME 0x3A95A8
char *func_003A95A8(char *s)
{
    char *str = s;
    int n = 0;
    int i;
    char *p;
    char *q;

    while (str[n])
        n++;
    n--;
    q = str + n;
    p = str;
    for (i = 0; i < n; i++, n--) {
        char c = *q;
        char d = *p;
        *p = c;
        *q = d;
        p++;
        q--;
    }
    return str;
}
