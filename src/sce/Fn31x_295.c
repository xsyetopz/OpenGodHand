// COMPILER: ee-gcc2.95.3-136
// SCE library units in 0x31C000-0x31FFFF built by SN ee-gcc 2.95.3 (sq s0 prologues), -O2 -G0.

extern int D_00747B14;
extern unsigned *D_00747A4C;
extern char D_00450ED8[];
extern char D_00450E88[];
unsigned *SearchData__FPUiPCcUi(unsigned *, const char *, unsigned);
int memcmp(const void *, const void *, unsigned);
void func_0031C238(int, char *, char *);
void func_0031D3D0();

// FUNCTION: GAME 0x31C1D0
void func_0031C1D0(int a, char *b)
{
    if (b && !memcmp(b, D_00450E88, 4))
        func_0031C238(a, b + 4, b + 0x20);
}

// FUNCTION: GAME 0x31CE38
unsigned *SearchCameraData__FPCc(const char *n)
{
    unsigned *p = SearchData__FPUiPCcUi(D_00747A4C, D_00450ED8, 0);
    if (!p)
        return 0;
    return SearchData__FPUiPCcUi(p, n, 0);
}

float func_0031CF78(void);

// FUNCTION: GAME 0x31CF30
float func_0031CF30(void)
{
    float r = func_0031CF78();
    if (r <= 0.0f)
        r += 1.0f;
    return r;
}

// FUNCTION: GAME 0x31CF78
float func_0031CF78(void)
{
    unsigned r = D_00747B14 * 0x10DCD;
    D_00747B14 = r;
    {
        float f = (float)r * 2.3283064e-10f;
        return f + f;
    }
}

// FUNCTION: GAME 0x31D658
unsigned short func_0031D658(char *s, unsigned char b)
{
    int i;
    for (i = 0; i < *(unsigned short *)(s + 8); i++) {
        int p = ((int *)(s + 0x10))[i] + (int)s;
        func_0031D3D0(p, *(int *)p + p, i, b);
    }
    return *(unsigned short *)(s + 8);
}
