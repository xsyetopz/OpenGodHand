// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// Buffered byte writer (0x3AB050): appends n bytes to D_0077DB08, flushing via func_003B0268 at 0x80.
extern int D_003FA9C8;
extern char *D_003FA9CC;
extern char D_0077DB08[];
int func_003B0268(void *, char *, int);

// FUNCTION: GAME 0x3AB050
int func_003AB050(void *h, char *buf, unsigned int n, int flush)
{
    unsigned int i;
    int k;
    char *q;

    if (flush == 1) {
        int r = func_003B0268(h, D_0077DB08, D_003FA9C8);
        D_003FA9C8 = 0;
        D_003FA9CC = D_0077DB08;
        return r;
    }
    for (i = 0; i < n; i++) {
        *D_003FA9CC = buf[i];
        q = D_003FA9CC;
        k = D_003FA9C8 + 1;
        q = q + 1;
        D_003FA9C8 = k;
        D_003FA9CC = q;
        if (k >= 0x80) {
            int r = func_003B0268(h, D_0077DB08, k);
            D_003FA9CC = D_0077DB08;
            D_003FA9C8 = 0;
            if (!r)
                return 0;
        }
    }
    return i;
}
