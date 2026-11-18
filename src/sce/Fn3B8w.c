// COMPILER: ee-gcc2.9-991111
// SCE library small units 0x3B8000-0x3C0000, ee-gcc 2.9-991111 -O2 -G0.

// FUNCTION: GAME 0x3BA550
void func_003BA550(int *p)
{
    signed char *b = *(signed char **)(p + 2);
    unsigned v;
    b[0] = 0x72;
    b[1] = -8;
    b[2] = 0x1F;
    b[3] = 0x4E;
    b[4] = 1;
    b[5] = *((unsigned char *)p + 0x38);
    v = (p[13] << 3) & 0xFFFF;
    b[6] = v;
    b[7] = v >> 8;
}

extern char D_00460A00[];
extern void func_003B9DE0(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x3BA4F8 (7 words off: original has a nop pad before the success label)
int func_003BA4F8(int *p, unsigned char *s)
{
    unsigned c;
    unsigned v;
    s += (p[10] == 1);
    c = *s;
    v = c & 7;
    if ((c >> 3) > 8) {
        func_003B9DE0(D_00460A00);
        return -1;
    }
    p[14] = v;
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3BA370 (original keeps non-rotated loop jumping to the i<n test)
int func_003BA370(unsigned char *p, int n)
{
    int i;
    if (n >= 3) {
        for (i = 0; i < n; i += 2) {
            if (p[0] == 0xB && p[1] == 0x77)
                return i;
            if (p[0] == 0x77 && p[1] == 0xB)
                return i;
            p += 2;
        }
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x3BACA0
int func_003BACA0(int a)
{
    int r = 0;
    switch (a) {
    case 0:
        while (*(volatile int *)0x10002010 < 0)
            ;
        r = 0;
        break;
    case 1:
        r = *(volatile unsigned *)0x10002010 >> 31;
        break;
    }
    return r;
}
