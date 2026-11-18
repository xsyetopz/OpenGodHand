// COMPILER: ee-gcc2.96
int func_0033FCD0();
extern int D_007588FC;
void func_00347450();
int strncpy();
extern char D_003EADC0[];
extern int (*D_003EADB8)();
extern int D_003EADBC;
extern char D_00456930[];
int func_0033B6E8();

// FUNCTION: GAME 0x33FD70
int func_0033FD70(int a, int *b)
{
    int *p;
    if (D_007588FC == 0) return -1;
    p = (int *)func_0033FCD0();
    if (p == 0) return -3;
    *b = p[3];
    return 0;
}

// FUNCTION: GAME 0x3448F8
void func_003448F8(char *a, char *b)
{
    int v = *(int *)(b + 0x30);
    if (*(int *)(a + 0x190) < v) func_00347450(a);
    *(int *)(a + 0x190) = *(int *)(b + 0x30);
}

// FUNCTION: GAME 0x33F130
void func_0033F130(char *a)
{
    char *s;
    if (a == 0) {
        func_0033B6E8(D_00456930);
        return;
    }
    s = D_003EADC0;
    strncpy(s, a, 0xFF);
    if (D_003EADB8) D_003EADB8(D_003EADBC, s);
    func_0033B6E8(s);
}
