// COMPILER: ee-gcc2.96
// SCE runtime helpers in 0x3B9998-0x3BA900.

extern void func_003BA058(int *);

// FUNCTION: GAME 0x3B9BB8
void func_003B9BB8(int *a)
{
    int *p = *(int **)(a[1] + 4);
    int *q = (int *)p[0xC0 / 4];
    if (q)
        func_003BA058(q);
}

// FUNCTION: GAME 0x3BA6C0
void func_003BA6C0(unsigned char *p, unsigned int n)
{
    unsigned int i;
    for (i = 8; i < n; i += 2) {
        unsigned char *a = p + i;
        unsigned char *b = a + 1;
        unsigned char x = *a;
        unsigned char y = *b;
        *b = x;
        *a = y;
    }
}
