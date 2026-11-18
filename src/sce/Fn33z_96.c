// COMPILER: ee-gcc2.96
extern char D_00454458[], D_00454960[], D_00454948[];
void func_00332808(int *, char *);
void func_00334008(int *, char *);
unsigned strlen(const char *);
int func_00333470(int, int);
int func_00334E98(int, int);
void func_00334998(void);
int func_00331C78(int);
int func_00331F50(int);
void func_00326050(char *);
void func_00334500(char *);

// FUNCTION: GAME 0x332DD0
int func_00332DD0(int *a, int b, int c)
{
    int p, n;
    if (a == 0) { func_00332808(a, D_00454458); return 0; }
    if (c == 0) a[3] = b;
    else if (c == 2) a[3] = a[2] + b;
    else if (c == 1) a[3] = a[3] + b;
    n = a[2];
    p = a[3];
    a[5] = 0;
    if (p >= n) p = n;
    if (p < 0) p = 0;
    a[3] = p;
    return p;
}

// FUNCTION: GAME 0x334738
int func_00334738(int *a, int b, int c)
{
    int p, n;
    if (a == 0) { func_00334008(a, D_00454960); return 0; }
    if (c == 0) a[7] = b;
    else if (c == 2) a[7] = a[4] + b;
    else if (c == 1) a[7] = a[7] + b;
    n = a[4];
    p = a[7];
    a[10] = 0;
    if (p >= n) p = n;
    if (p < 0) p = 0;
    a[7] = p;
    return p;
}

// FUNCTION: GAME 0x3334C8
int func_003334C8(char *a, char *b)
{
    int n = strlen(a);
    int i;
    if (n != strlen(b)) return -1;
    for (i = 0; i < n; ) {
        int r = func_00333470(a[i], b[i]);
        i++;
        if (r != 0) return -1;
    }
    return 0;
}

// FUNCTION: GAME 0x334EF0
int func_00334EF0(char *a, char *b)
{
    int n = strlen(a);
    int i;
    if (n != strlen(b)) return -1;
    for (i = 0; i < n; ) {
        int r = func_00334E98(a[i], b[i]);
        i++;
        if (r != 0) return -1;
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x334698
// diff: 2 words, epilogue ld $s0/$s1 restore order swapped before tail call
void func_00334698(char *a)
{
    int r;
    if (a != 0) {
        if (((unsigned char *)a)[2] >= 2) func_00334998();
        if (a[1] == 0) {
            func_00331C78(0x5000);
            r = func_00331F50(*(int *)(a + 0x18));
            func_00331C78(0x5001);
            if (r < 0) func_00326050(D_00454948);
            a[0] = 0;
        } else a[0] = 0;
        func_00334500(a);
    }
}
#endif
