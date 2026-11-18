// Small accessors in 0x2D0000-0x2D7FFF.

extern "C" {

// FUNCTION: GAME 0x002D0350
void func_002D0350(int *a, int b) { a[1] |= b; }

// FUNCTION: GAME 0x002D03D0
int func_002D03D0(int *a, int b) { return (~a[1] & b) == 0; }

// FUNCTION: GAME 0x002D2DB0
char *func_002D2DB0(char *a, int b) { return *(char **)(a + 0x38) + b * 0xDC; }

}

extern int D_00747A94;
extern int D_00747A98;
extern char D_0044D388[];

// FUNCTION: GAME 0x2DB6B0
int Getplayer()
{
    return D_00747A94;
}

// FUNCTION: GAME 0x2DB6C0
int GetJacket()
{
    return D_00747A98;
}

// FUNCTION: GAME 0x2D9E18
extern "C" char *func_002D9E18(char *p)
{
    *(char **)p = D_0044D388;
    return p;
}

// FUNCTION: GAME 0x2D42E0
extern "C" void func_002D42E0(int *p)
{
    if (*p)
        p[0x18] = 1;
}

// FUNCTION: GAME 0x2D0578
extern "C" char *func_002D0578(char *p, int i)
{
    char *t = *(char **)(p + 0x30);
    if (!t)
        return 0;
    return *(char **)(t + 0x10) + i * 8;
}

// FUNCTION: GAME 0x2D0598
extern "C" char *func_002D0598(char *p, int i)
{
    char *t = *(char **)(p + 0x30);
    if (!t)
        return 0;
    return *(char **)(t + 0x14) + i * 16;
}

// FUNCTION: GAME 0x2D05B8
extern "C" char *func_002D05B8(char *p, int i)
{
    char *t = *(char **)(p + 0x30);
    if (!t)
        return 0;
    return *(char **)(t + 0x1C) + i * 2;
}

// FUNCTION: GAME 0x2D3190
extern "C" int func_002D3190(char *p)
{
    int *c = (int *)(p + 0xC40);
    if (++*c == 0)
        *c = 1;
    return *c;
}

extern "C" void func_002D31B0(int, unsigned);
extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x2D31E0
extern "C" void func_002D31E0()
{
    func_002D31B0(1, 0xFFFF);
}

// FUNCTION: GAME 0x2D3220
extern "C" void func_002D3220(void *p)
{
    memset(p, 0, 0xC0);
}
