// COMPILER: ee-gcc2.96
int func_0034C390();
int func_0034DA88();
int func_0035D7B8();
int func_0036C920();
void func_0034DF68();
void func_0034DF80();
int func_0034DEC8();
int func_0034DD70();
int func_0035C2D0();
void func_0035E148();
void func_0035E1B8();
void func_0035E238();
void func_0035E2A8();

// FUNCTION: GAME 0x34C680
int func_0034C680(int **a, int b)
{
    int buf[4];
    int c;
    int d = b == 0;
    (*(void (**)())((char *)*a + 0x18))(a, b, c, buf);
    (*(void (**)())((char *)*a + 0x20))(a, d, buf);
    return buf[1];
}

// FUNCTION: GAME 0x34D820
void func_0034D820(int a, int b, int *c)
{
    if (b != 0) {
        c[0] = func_0034DA88(a, b, func_0035E148);
        c[1] = func_0034DA88(a, b, func_0035E1B8);
        c[2] = func_0034DA88(a, b, func_0035E238);
        c[3] = func_0034DA88(a, b, func_0035E2A8);
    }
}

// FUNCTION: GAME 0x34E460
int func_0034E460(char *a, int b)
{
    int r = func_0034C390(a, *(int *)(a + 0x1F84), b);
    if (r == 0) {
        *(int *)(a + 0x37A8) += b;
    }
    return r;
}

// FUNCTION: GAME 0x35DED8
int func_0035DED8(char *a, int *b)
{
    unsigned char *p;
    *b = 0;
    p = *(unsigned char **)(a + 4) + 0xB0;
    if (func_0035D7B8(a) == 0) {
        return 0;
    }
    *b = p[2];
    return 1;
}

// FUNCTION: GAME 0x35DF28
int func_0035DF28(char *a, int *b)
{
    unsigned char *p;
    *b = 0;
    p = *(unsigned char **)(a + 4) + 0xB0;
    if (func_0035D7B8(a) == 0) {
        return 0;
    }
    *b = p[3];
    return 1;
}

// FUNCTION: GAME 0x35DFE0
int func_0035DFE0(char *a, int *b)
{
    int *p;
    *b = 0;
    p = *(int **)(a + 4) + 0xB0/4;
    if (func_0035D7B8(a) == 0) {
        return 0;
    }
    *b = p[2];
    return 1;
}

// FUNCTION: GAME 0x35E030
int func_0035E030(char *a, int *b)
{
    int *p;
    *b = 0;
    p = *(int **)(a + 4) + 0xB0/4;
    if (func_0035D7B8(a) == 0) {
        return 0;
    }
    *b = p[3];
    return 1;
}

// FUNCTION: GAME 0x35E080
int func_0035E080(char *a, int *b)
{
    int *p;
    *b = 0;
    p = *(int **)(a + 4) + 0xB0/4;
    if (func_0035D7B8(a) == 0) {
        return 0;
    }
    *b = p[4];
    return 1;
}

// FUNCTION: GAME 0x35CAC8
int func_0035CAC8(int *a)
{
    int n = a[4];
    int sum = 0;
    int i;
    int *p;
    if (n > 0) {
        p = a + 6;
        for (i = 0; i < n; i++) {
            sum += *p++;
        }
    }
    return sum / n;
}

// FUNCTION: GAME 0x35CA08
int func_0035CA08(int *a, int b)
{
    int r;
    int *q = a + 5;
    int n = a[4];
    int i = *q;
    a[6 + i % n] = b;
    *q = i + 1;
    r = func_0035CAC8(a);
    a[0x1A8 / 4] = a[0x1A4 / 4] = r;
    return r;
}

// FUNCTION: GAME 0x35B568
void func_0035B568(char *a)
{
    char buf[0x10];
    int *p = (int *)(a + 0xD30);
    int r = func_0036C920(p[0xB8]);
    func_0034DF68(buf);
    p[0xB7] = p[0xB7] + r;
    func_0034DF80(buf);
}

// FUNCTION: GAME 0x358E78
int func_00358E78(int a, int b)
{
    if (func_0034DEC8(a) != 0) {
        return func_0034DD70(0, 0xFF000134, 9, b, 0);
    }
    return func_0035C2D0(a, 0);
}
