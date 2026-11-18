// COMPILER: ee-gcc2.96
extern int func_0034DD70();
extern int func_003562F8();

// FUNCTION: GAME 0x350040
void func_00350040()
{
}

// FUNCTION: GAME 0x35A2A8
void func_0035A2A8()
{
}

// FUNCTION: GAME 0x359218
int func_00359218(int *a, int b)
{
    int v = a[0x58 / 4];
    if (!v) {
        a[0x58 / 4] = b;
        return 0;
    }
    if (v == b)
        return 0;
    return func_0034DD70(a, 0xFF000207);
}

// FUNCTION: GAME 0x356988
void func_00356988(char *a, int b)
{
    char *g = *(char **)(a + 0x1FC0);
    int *s = (int *)(g + 0x1128);
    if (s[0x1C / 4] != 1) {
        func_003562F8(g + 0x1198);
        s[0x1C / 4] = 1;
        s[0x20 / 4] = b;
    }
}
