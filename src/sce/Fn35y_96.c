// COMPILER: ee-gcc2.96
int func_00355508(int);
int func_00350BE8(int, int);
void func_00350C58(int, int);
void func_0035A000(int, int, int);
int func_00356358(int);
void func_003562A0(int);
int func_00358A38(void);
int func_0039A998(int);
void func_0039AA48(void);
int func_00356868(int);

// FUNCTION: GAME 0x350B60
void func_00350B60(int a)
{
    int *s = (int *)(a + 0x950);
    int r = func_00355508(a);
    if (r == -1 || func_00350BE8(a, r) != 0) {
        func_00350C58(a, 1);
        if (*s == 0) func_0035A000(a, 5, 0);
    }
}

// FUNCTION: GAME 0x357720
void func_00357720(int a)
{
    int *s = (int *)(a + 0xA0C);
    if (s[0x18 / 4] == 0 && s[0x3C / 4] == 2) func_0035A000(a, 0xF, 1);
    if (s[0x14 / 4] == 0 && s[0x3C / 4] == 1) func_0035A000(a, 0xF, 2);
}

// FUNCTION: GAME 0x3567E0
int func_003567E0(int a)
{
    int s;
    if (func_00356358(a)) {
        s = *(int *)(a + 0x1FC0);
        func_003562A0(s + 0x1198);
        if (func_00358A38() != 1) {

            return func_0039A998(s + 0x1150);
        }
        func_0039AA48();
        return func_00356868(a);
    }
    return 0;
}

extern int D_003EE2C4[];
int func_0034DEC8(int);
int func_0034DD70();
void func_00359848(void);
int func_00359CB8(int);

// FUNCTION: GAME 0x358328
int func_00358328(void)
{
    int *p = D_003EE2C4;
    int i;
    for (i = 0; i < 8; i++, p++)
        if (*p == 0) return i;
    return -1;
}

// FUNCTION: GAME 0x3596F0
int func_003596F0(int a, int b)
{
    int *p = (int *)(a + b * 0x74 + 0x1348);
    if (p[0] == 0) return 0;
    return (p[2] < p[1]) ^ 1;
}

// FUNCTION: GAME 0x359800
void func_00359800(int a)
{
    if (*(int *)(a + 0x36B0) != 0) {
        func_00359848();
        func_00359CB8(a);
    }
}

// FUNCTION: GAME 0x359E80
int func_00359E80(int a)
{
    if (func_0034DEC8(a) != 0) func_0034DD70(0, 0xFF000111);
    return *(int *)(a + 0x48);
}
