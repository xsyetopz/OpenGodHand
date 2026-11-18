// COMPILER: ee-gcc2.96
extern int D_003D9DD8, D_003DA394, D_003E9D5C;
extern int D_003D847C, D_003D8478, D_003D9DD4, D_003E9D3C;
extern unsigned char D_003D9DD0[];

// FUNCTION: GAME 0x3331C0
void func_003331C0(int v) { D_003D9DD8 = v; }

// FUNCTION: GAME 0x335348
void func_00335348(int v) { D_003DA394 = v; }

// FUNCTION: GAME 0x339788
void func_00339788(int *p, int a, int b)
{
    p[14] = a;
    p[15] = b;
}

// FUNCTION: GAME 0x33C708
void func_0033C708(int v) { D_003E9D5C = v; }

// FUNCTION: GAME 0x33C718
int func_0033C718(void) { return D_003E9D5C; }

// FUNCTION: GAME 0x33CE68
void func_0033CE68(int *p, int a, int b)
{
    p[30] = a;
    p[31] = b;
}

// FUNCTION: GAME 0x33D218
void func_0033D218(int *p)
{
    if (p[1] == 0)
        p[1] = 1;
}

// FUNCTION: GAME 0x33FB48
void func_0033FB48(int *p)
{
    if (p[3] == 3)
        p[3] = 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x331C78 (8 words off: original materializes both addresses with lui+addiu first, ours folds the low half into the accesses)
void func_00331C78(int v)
{
    int *b = &D_003D8478;
    int *a = &D_003D847C;
    *b = *a;
    *a = v;
}
#endif

// FUNCTION: GAME 0x333E68
void func_00333E68(int a, int b, int c, int d)
{
    D_003D9DD0[0] = a;
    D_003D9DD0[1] = b;
    D_003D9DD0[2] = c;
    D_003D9DD4 = d;
}

// FUNCTION: GAME 0x33C520
int func_0033C520(void)
{
    D_003E9D3C++;
    return 0;
}

// FUNCTION: GAME 0x33C7A0
void func_0033C7A0(int *p, int unused, int n)
{
    p[35] += n;
    p[34] += n;
}

// FUNCTION: GAME 0x33FA10
void func_0033FA10(unsigned short *p, unsigned short *a, unsigned short *b, unsigned short *c)
{
    *a = p[26];
    *b = p[27];
    *c = p[28];
}

// FUNCTION: GAME 0x33FB00
void func_0033FB00(int *p)
{
    if (p[3] == 0) {
        p[4] = 0;
        p[3] = 1;
    }
}

// FUNCTION: GAME 0x33F9D8
void func_0033F9D8(unsigned short *p, unsigned short *a, unsigned short *b)
{
    a[0] = p[20];
    b[0] = p[21];
    a[1] = p[22];
    b[1] = p[23];
}

#ifdef NONMATCHING
// DRAFT: GAME 0x33C770 (2 words off: first loaded value lands in $v1 instead of $t0)
int func_0033C770(int *p, int *a, int *b, int *c)
{
    int w;
    int t = p[35];
    int r = p[15];
    *a = t;
    *b = p[16] - p[35];
    w = p[34];
    *c = p[6] - w;
    return r;
}
#endif

