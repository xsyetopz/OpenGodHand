// COMPILER: ee-gcc2.96
int func_0034C2D0(int, int, int, int);
int func_0034C3A8(int, int, int, int);
void func_0035D538(int, char *);
void func_0035D5C8(void);
void func_0034DD58(void);
void func_003394A0(void);
void func_00339520(void);
void func_003571D0(void);
void func_0033B658(void);
void func_0033B670(void);
int func_0034DD70(int, int);
int func_0034E1F0(void);
extern char D_00761E50[];
void func_0034D048(void);
void func_0034D068(void);
int func_0034C2A0(char *, int, int);

// FUNCTION: GAME 0x34C2A0
int func_0034C2A0(char *a, int b, int c) { return func_0034C2D0((int)a, b, c, 0); }
// FUNCTION: GAME 0x34C2B8
int func_0034C2B8(char *a, int b, int c) { return func_0034C2D0((int)a, b, c, 1); }
// FUNCTION: GAME 0x34C378
int func_0034C378(char *a, int b, int c) { return func_0034C3A8((int)a, b, c, 0); }
// FUNCTION: GAME 0x34C390
int func_0034C390(char *a, int b, int c) { return func_0034C3A8((int)a, b, c, 1); }
// FUNCTION: GAME 0x34D048
void func_0034D048(void) { func_0035D538(0x20, D_00761E50); }
// FUNCTION: GAME 0x34D068
void func_0034D068(void) { func_0035D5C8(); }
// FUNCTION: GAME 0x34DD40
void func_0034DD40(void) { func_0034DD58(); }
// FUNCTION: GAME 0x34DEF0
void func_0034DEF0(void) { func_003394A0(); }
// FUNCTION: GAME 0x34DF08
void func_0034DF08(void) { func_00339520(); }
// FUNCTION: GAME 0x34DF20
void func_0034DF20(void) { func_003571D0(); func_0034D048(); }
// FUNCTION: GAME 0x34DF40
void func_0034DF40(void) { func_0034D068(); }
// FUNCTION: GAME 0x34DF68
void func_0034DF68(void) { func_0033B658(); }
// FUNCTION: GAME 0x34DF80
void func_0034DF80(void) { func_0033B670(); }
// FUNCTION: GAME 0x34E000
int func_0034E000(char *a, int b) { return func_0034C2A0(a, *(int *)(a + 0x1F44), b); }
// FUNCTION: GAME 0x34E048
int func_0034E048(int a) { return func_0034DD70(a, 0xFF000501); }
// FUNCTION: GAME 0x34E068
int func_0034E068(int a) { return func_0034DD70(a, 0xFF000501); }
// FUNCTION: GAME 0x34E1D8
void func_0034E1D8(void) { func_0034E1F0(); }

void func_00369188(void);

// FUNCTION: GAME 0x34FE78
int func_0034FE78(int a, int b) { return func_0034DD70(a, b); }
// FUNCTION: GAME 0x34FEE0
void func_0034FEE0(void) { func_00369188(); }
// FUNCTION: GAME 0x34FF18
int func_0034FF18(int a) { return func_0034DD70(a, 0xFF000D0B); }
// FUNCTION: GAME 0x34FF38
int func_0034FF38(int a) { return func_0034DD70(a, 0xFF000D0B); }
// FUNCTION: GAME 0x34FF58
int func_0034FF58(int a) { return func_0034DD70(a, 0xFF000D0B); }
// FUNCTION: GAME 0x34FF78
int func_0034FF78(int a) { return func_0034DD70(a, 0xFF000D0B); }

int func_0034CA30(char *, int);

// FUNCTION: GAME 0x34F7A0
int func_0034F7A0(char *a)
{
    int r = 0;
    int *s = (int *)(a + 0x1F74);
    if (s[6] != 8) r = func_0034CA30(a, s[6]);
    if (s[5] != 8) r |= func_0034CA30(a, s[5]);
    if (s[7] != 8) r |= func_0034CA30(a, s[7]);
    return r;
}
