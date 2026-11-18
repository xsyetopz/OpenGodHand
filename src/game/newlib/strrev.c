// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// In-place string reverse (0x3A95A8), strlen loop then pairwise swap.
#ifdef NONMATCHING
// DRAFT: GAME 0x3A95A8
// diff: 3 words, init order of i/q/p (orig: t0=i=0, a2=q, a1=p)
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
    if (n > 0) {
        q = str + n;
        p = str;
        i = 0;
        do {
            unsigned char c = *q;
            char d = *p;
            *p = c;
            *q = d;
            i++;
            n--;
            p++;
            q--;
        } while (i < n);
    }
    return str;
}
#endif
