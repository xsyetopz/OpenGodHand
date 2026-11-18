// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// Buffered byte writer (0x3A9C80): appends n bytes to D_0077DA88, flushing via func_003B0268 at 0x80.
extern int D_003FA9C0;
extern char *D_003FA9C4;
extern char D_0077DA88[];
int func_003B0268(void *, char *, int);

// FUNCTION: GAME 0x3A9C80
int func_003A9C80(void *h, char *buf, unsigned int n, int flush)
{
    unsigned int i;
    int k;
    char *q;

    if (flush == 1) {
        int r = func_003B0268(h, D_0077DA88, D_003FA9C0);
        D_003FA9C0 = 0;
        D_003FA9C4 = D_0077DA88;
        return r;
    }
    for (i = 0; i < n; i++) {
        *D_003FA9C4 = buf[i];
        q = D_003FA9C4;
        k = D_003FA9C0 + 1;
        q = q + 1;
        D_003FA9C0 = k;
        D_003FA9C4 = q;
        if (k >= 0x80) {
            int r = func_003B0268(h, D_0077DA88, k);
            D_003FA9C4 = D_0077DA88;
            D_003FA9C0 = 0;
            if (!r)
                return 0;
        }
    }
    return i;
}
