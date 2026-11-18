// COMPILER: ee-gcc2.96
int func_0035D7B8(int);
int func_0035DA58(int, int);
int func_0035E9E8(int);
void func_0035D728(int);
extern char D_00459C48[];
int func_003A93F8();
int func_0035DDB0();
int func_0035F1D0();
int func_0035F418();

// FUNCTION: GAME 0x35DA58
int func_0035DA58(int a, int b)
{
    int r = 0;
    int i;
    for (i = 0; i < 0x1A; i++) {
        int p = a + i * 64 + 0x180;
        if (*(unsigned char *)(p + 0x18) == b) {
            r = p;
            break;
        }
    }
    return r;
}

// FUNCTION: GAME 0x35DD50
int func_0035DD50(int a, int b, int c)
{
    int p = func_003A93F8(a, D_00459C48);
    if (p) {
        int r = func_0035DDB0(p + 4, b);
        func_0035DDB0(r + 1, c);
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x35E0F0
int func_0035E0F0(int a, int b)
{
    int s = *(int *)(a + 4);
    if (func_0035D7B8(a)) return func_0035DA58(s, b);
    return 0;
}

// FUNCTION: GAME 0x35F3C8
int func_0035F3C8(int a, int b, int c)
{
    func_0035F1D0(a, b, c, 0);
    return func_0035F418(a, b, c);
}

// DRAFT: GAME 0x35DC10
// 3 words: prologue save order s0/s1 swapped
#ifdef NONMATCHING
int func_0035DC10(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(int *)s;
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35DC60
// 3 words: prologue save order
#ifdef NONMATCHING
int func_0035DC60(int a, int *b)
{
    int s;
    *b = -1;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(unsigned char *)(s + 4);
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35DCB0
// 3 words: prologue save order
#ifdef NONMATCHING
int func_0035DCB0(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(short *)(s + 8);
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35DD00
// 3 words: prologue save order
#ifdef NONMATCHING
int func_0035DD00(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(int *)(s + 0xC);
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35D758
// 18 words: original loop counter in v0, bnez exit
#ifdef NONMATCHING
void func_0035D758(int n, int p)
{
    if (n > 0) {
        do {
            func_0035D728(p);
            p += 0x10;
        } while (--n != 0);
    }
}
#endif

// DRAFT: GAME 0x35E968
// 9 words: original uses movz for the byte > 1 test
#ifdef NONMATCHING
int func_0035E968(int a, int b)
{
    if (func_0035E9E8(a) == 0xC0) return (*(unsigned char *)(b + 0x20) != 0) & (*(unsigned char *)(b + 0x20) >= 2);
    return 0;
}
#endif

// DRAFT: GAME 0x35E9A8
// 9 words: original uses movz for the byte > 1 test
#ifdef NONMATCHING
int func_0035E9A8(int a, int b)
{
    if (func_0035E9E8(a) == 0xE0) return (*(unsigned char *)(b + 0x20) != 0) & (*(unsigned char *)(b + 0x20) >= 2);
    return 0;
}
#endif
