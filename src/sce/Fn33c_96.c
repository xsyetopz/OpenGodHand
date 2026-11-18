// COMPILER: ee-gcc2.96
extern char D_00454458[], D_00454960[], D_00455130[], D_004551B8[], D_004551D0[];
extern int D_003D8484;
void func_00332808(int *, char *);
void func_00334008(int *, char *);
void func_00336330(int *, char *);
extern void func_0033B6A0(), func_0033B6D0();

// FUNCTION: GAME 0x332E68
int func_00332E68(int *p)
{
    if (p == 0) {
        func_00332808((int *)p, D_00454458);
        return 0;
    }
    return p[3];
}

// FUNCTION: GAME 0x333130
int func_00333130(char *p)
{
    if (p == 0) {
        func_00332808((int *)p, D_00454458);
        return 0;
    }
    return p[2];
}

// FUNCTION: GAME 0x3347D0
int func_003347D0(int *p)
{
    if (p == 0) {
        func_00334008((int *)p, D_00454960);
        return 0;
    }
    return p[7];
}

// FUNCTION: GAME 0x334A90
int func_00334A90(char *p)
{
    if (p == 0) {
        func_00334008((int *)p, D_00454960);
        return 0;
    }
    return p[2];
}

// FUNCTION: GAME 0x3367C0
int func_003367C0(int *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_00455130);
        return 0;
    }
    return p[4];
}

// FUNCTION: GAME 0x3369D0
int func_003369D0(char *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_004551B8);
        return 0;
    }
    return p[1];
}

// FUNCTION: GAME 0x336A08
int func_00336A08(int *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_004551D0);
        return 0;
    }
    return p[1];
}

// FUNCTION: GAME 0x33FA70
int func_0033FA70(int *p, int a, int b, int c, int d)
{
    if (p[3] == 0) {
        p[5] = 1;
        p[6] = a;
        p[7] = b;
        p[8] = c;
        p[9] = d;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x33FAA0
int func_0033FAA0(int *p, int a, int b, int c, int d)
{
    if (p[3] == 0) {
        p[5] = 2;
        p[6] = a;
        p[7] = b;
        p[8] = c;
        p[9] = d;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x33FAD0
int func_0033FAD0(int *p, int a, int b, int c, int d)
{
    if (p[3] == 0) {
        p[5] = 1;
        p[6] = a;
        p[7] = b;
        p[8] = c;
        p[9] = d;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x331D40
void func_00331D40(void)
{
    if (D_003D8484 == 1)
        func_0033B6A0();
}

// FUNCTION: GAME 0x331D78
void func_00331D78(void)
{
    if (D_003D8484 == 1)
        func_0033B6D0();
}
