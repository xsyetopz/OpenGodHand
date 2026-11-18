// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// Integer to string (0x3A9620): digits from table D_003FA998, then reverse via func_003A95A8.
extern char D_003FA998[];
char *func_003A95A8(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A9620
// diff: 17 words, only t0/t1 register numbering and prologue order
char *func_003A9620(int value, char *str, int base)
{
    unsigned int n = value;
    unsigned int neg = n >> 31;
    int i = 0;

    if (neg && base == 10)
        n = -n;
    do {
        str[i++] = D_003FA998[n % base];
        n /= base;
    } while (n != 0);
    if (neg)
        str[i++] = '-';
    str[i] = 0;
    return func_003A95A8(str);
}
#endif
