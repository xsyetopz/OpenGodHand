// COMPILER: ee-gcc2.96

// FUNCTION: GAME 0x3554D8
void func_003554D8(char *a)
{
    char *p = *(char **)(a + 0x1FC0);
    *(int *)(p + 0x7C) = 1;
}

// FUNCTION: GAME 0x356358
int func_00356358(char *a)
{
    return *(int *)(*(int *)(a + 0x1FC0) + 0x1128) != 0;
}

// FUNCTION: GAME 0x357140
int func_00357140(char *a)
{
    *(int *)(a + 0x4C) = 3;
    return 0;
}

// FUNCTION: GAME 0x358930
int func_00358930(char *a)
{
    *(int *)(a + 0x4C) = 4;
    return 0;
}

// FUNCTION: GAME 0x35A1C8
int func_0035A1C8(char *a, int i)
{
    return *(int *)(a + i * 4 + 0xA0C);
}

// FUNCTION: GAME 0x35A298
void func_0035A298(int *a, int b)
{
    a[0] = 0;
    // barrier pins the store order the original scheduler produced
    __asm__ volatile("");
    a[2] = b;
    a[1] = 0;
}

// FUNCTION: GAME 0x355630
void func_00355630(int *a)
{
    if (a)
        *a = 0;
}

// FUNCTION: GAME 0x358678
void func_00358678(long *a)
{
    a[0] = 0; a[1] = 0; a[2] = 0;
}

// FUNCTION: GAME 0x35B0D8
void func_0035B0D8(char *a, int b, int c)
{
    a += c * 4; *(int *)(a + 0xD30) = b;
}

// FUNCTION: GAME 0x35C528
void func_0035C528(int *a, int b)
{
    if (b > 0)
        a[4] = b;
}

// FUNCTION: GAME 0x35D708
void func_0035D708(int *a)
{
    a[0] = 0; a[1] = 0; a[2] = 0;
}

// FUNCTION: GAME 0x35D718
void func_0035D718(int *a, int b, int c)
{
    a[2] = c;
    a[0] = b;
    a[1] = 0;
}

// FUNCTION: GAME 0x355640
void func_00355640(int *a)
{
    if (a)
        *a = 2;
}

// FUNCTION: GAME 0x355658
void func_00355658(int *a)
{
    if (a)
        *a = 4;
}

// FUNCTION: GAME 0x35C4F8
void func_0035C4F8(char *a, long *b)
{
    *(long *)(a + 0x158) = b[0];
    *(long *)(a + 0x160) = b[1];
}

// FUNCTION: GAME 0x35C510
void func_0035C510(char *a, long *b)
{
    *(long *)(a + 0x168) = b[0];
    *(long *)(a + 0x170) = b[1];
}

// FUNCTION: GAME 0x3537A8
void func_003537A8(char *a, int b, int *c, int *d)
{
    a += 0xA0C;
    *d = *(int *)(a + 0xAC);
    *c = *(int *)(a + 0xA8);
}

// FUNCTION: GAME 0x356E80
void func_00356E80(char *a)
{
    int *p = (int *)(*(char **)(a + 0x1FC0) + 0x1128);
    p[3] = p[3] - 1;
}

// FUNCTION: GAME 0x35C368
int func_0035C368(char *a, int b)
{
    a += b * 0x44; return *(int *)(a + 0x1F34);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x35FF98 gcc stores a[0x12] first, then 4,3C,40,44; original goes 4,3C,40,44,48; 4 words
void func_0035FF98(int *a)
{
    a[0x12] = 0;
    a[0x11] = 0;
    a[0x10] = 0;
    a[0xF] = 0;
    a[1] = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x355790 v0/v1 roles swapped and the constant 1 is returned via a second path; original sets v0=1 in the beqz delay slot; 3 words
int func_00355790(char *a, char *b)
{
    int r = 1;
    if (a)
        r = *(int *)(b + 0x38) < *(int *)(a + 0x38);
    return r;
}
#endif

// FUNCTION: GAME 0x35AB98
int func_0035AB98(char *a, int *b, int *c)
{
    a += 0xD30;
    *b = *(int *)(a + 0x28C);
    *c = *(int *)(a + 0x290);
    return 0;
}

// FUNCTION: GAME 0x35BB40
void func_0035BB40(long *a)
{
    a[0] = 0;
    a[1] = 0x7FFFFFFFFFFFFFFFL;
    a[2] = 0;
    *(int *)((char *)a + 0x18) = 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x359730 gcc keeps a+4 in v0 and the constants in v1/a1; original uses v1 for a+4, v0 for 1, a1 for -3; 5 words
void func_00359730(int *a)
{
    int *p = a + 1;
    p[1] = -3;
    p[2] = 1;
    a[0] = 0;
    p[0] = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3557B0 gcc allocates v0/v1 where the original uses v1/a1 for the clamp; 4 words
void func_003557B0(int *a)
{
    int v = a[0x5C / 4] + 1;
    if (v < 0)
        v = 0;
    a[0x5C / 4] = v;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x35A7A0 v1/a2 swapped for the -1 compare; 3 words
int func_0035A7A0(char *a, char *b)
{
    if (*(int *)(b + 0x2CC) == -1)
        return 0;
    return *(int *)(a + 0x4C) == 4;
}
#endif
