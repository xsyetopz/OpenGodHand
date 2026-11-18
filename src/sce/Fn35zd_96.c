// COMPILER: ee-gcc2.96

extern int func_0034C930();
extern int func_0036CBC0();
extern int func_0036CC08();
extern int func_0036CC40();
extern int func_0035EDE0();
extern int func_0035C200();
extern int func_0035C1C0();
extern int func_0034DD70();
extern int func_003603D8();
extern int func_0034C990();
extern int func_0034CA68();
extern int func_0034CA98();
extern int func_00350718();
extern int func_0035A620();
extern int func_0035AB98();
extern int func_0035BC50();
extern int func_0035C238();
extern int func_0035D1B0();
extern int func_0035EBB0();
extern int func_0035FEA8();
extern int func_00360740();
extern int func_003607A0();
extern int func_00366918();
extern int func_00366C50();
extern int func_0036C3D0();
extern int func_0036CC80();
extern int func_0035D728();
extern int D_00766C90[];

// FUNCTION: GAME 0x3557C8
int func_003557C8(int *a, int b)
{
    if (b == (int)((a[2] * 16 + a[1] + 0x10) & 0xFFFFFFF))
        return 0;
    return (b - a[0]) / 2048;
}

// FUNCTION: GAME 0x35D4A8
int func_0035D4A8(char *a, int *b, int c)
{
    int r;
    if ((unsigned)(*(int *)(a + 0x48) - 3) >= 2) {
        *b = 0;
        return 0;
    }
    r = func_0034C930(a, *(int *)(a + 0x20D8), b, c);
    /* barrier: keeps the call non-tail, as in the original */
    __asm__ volatile("" ::: "memory");
    return r;
}

// FUNCTION: GAME 0x35E9E8
int func_0035E9E8(unsigned x)
{
    if (x - 0xC0 < 0x20)
        return 0xC0;
    if (x - 0xE0 < 0x10)
        return 0xE0;
    if (x == 0xBD || x == 0xBF)
        return 0xBD;
    return 0;
}

// FUNCTION: GAME 0x35C120
int func_0035C120(int a) { return func_0035C200(a, 7, 8); }

// FUNCTION: GAME 0x35C140
int func_0035C140(int a, int b, int c) { return func_0035C1C0(a, b, 0, c); }

// FUNCTION: GAME 0x35C160
int func_0035C160(int a, int b, int c) { return func_0035C1C0(a, b, 0, c); }

// FUNCTION: GAME 0x35C180
int func_0035C180(int a, int b, int c) { return func_0035C1C0(a, b, 1, c); }

// FUNCTION: GAME 0x35C1A0
int func_0035C1A0(int a, int b, int c) { return func_0035C1C0(a, b, 2, c); }

// FUNCTION: GAME 0x35D1F0
int func_0035D1F0(int a) { return func_0034DD70(a, 0xFF000601); }

// FUNCTION: GAME 0x35D210
int func_0035D210(int a) { return func_0034DD70(a, 0xFF000601); }

// FUNCTION: GAME 0x35D230
int func_0035D230(int a) { return func_0034DD70(a, 0xFF000601); }

// FUNCTION: GAME 0x35D250
int func_0035D250(int a) { return func_0034DD70(a, 0xFF000601); }

// FUNCTION: GAME 0x35EDA8
int func_0035EDA8(int *a, int *b) { return func_003603D8(a[9], b[0x13], a[0xE]); }

// FUNCTION: GAME 0x35D428
int func_0035D428() { return 1; }

// FUNCTION: GAME 0x35D430
int func_0035D430() { return 0; }

// FUNCTION: GAME 0x35D438
int func_0035D438() { return 0; }

// FUNCTION: GAME 0x35D440
int func_0035D440() { return 0; }

// FUNCTION: GAME 0x35D448
int func_0035D448() { return 0; }

// FUNCTION: GAME 0x35D450
int func_0035D450() { return 0; }

// FUNCTION: GAME 0x35D458
int func_0035D458() { return 0; }

// FUNCTION: GAME 0x35D460
int func_0035D460() { return 0; }

// FUNCTION: GAME 0x35D270
int func_0035D270() { return 0; }

// FUNCTION: GAME 0x35D278
int func_0035D278() { return 0; }

// FUNCTION: GAME 0x35D280
int func_0035D280() { return 0; }

// FUNCTION: GAME 0x35D468
int func_0035D468(int a) { return func_0034DD70(a, 0xFF000701); }

// FUNCTION: GAME 0x35D488
int func_0035D488(int a) { return func_0034DD70(a, 0xFF000701); }

// FUNCTION: GAME 0x35EE98
int func_0035EE98(int *a, int *b) { return func_0036CBC0(a[0xC], b[0x13], a[0xE]); }

// FUNCTION: GAME 0x35EEB8
int func_0035EEB8(int *a, int *b) { return func_0036CC08(a[0xC], b[0x13], a[0xE]); }

// FUNCTION: GAME 0x35EED8
int func_0035EED8(int *a, int *b) { return func_0036CC40(a[0xC], b[0x13], a[0xE]); }

// FUNCTION: GAME 0x35EDC8
int func_0035EDC8(int *a) { return func_0035EDE0(a[0xE]); }

// FUNCTION: GAME 0x35CF70
int func_0035CF70() { return 0; }

// FUNCTION: GAME 0x35CF78
int func_0035CF78() { return 0; }

// FUNCTION: GAME 0x35D0D8
int func_0035D0D8() { return 0; }

// FUNCTION: GAME 0x35D1C8
int func_0035D1C8() { return 0; }

// FUNCTION: GAME 0x35D1D0
int func_0035D1D0() { return 0; }

// FUNCTION: GAME 0x35D1D8
int func_0035D1D8() { return 0; }

// FUNCTION: GAME 0x35D1E0
int func_0035D1E0() { return 0; }

// FUNCTION: GAME 0x35D1E8
int func_0035D1E8() { return 0; }

// FUNCTION: GAME 0x35D518
int func_0035D518() { return 0; }

// FUNCTION: GAME 0x354DB0
int func_00354DB0() { return 0; }

// FUNCTION: GAME 0x354DB8
int func_00354DB8() { return 0; }

// FUNCTION: GAME 0x354DC0
int func_00354DC0() { return 0; }

// FUNCTION: GAME 0x3506D8
int func_003506D8() { return 0; }

// FUNCTION: GAME 0x35D048
int func_0035D048() { return 1; }

// FUNCTION: GAME 0x35D0D0
int func_0035D0D0() { return 1; }

// FUNCTION: GAME 0x35F830
int func_0035F830() { return 0x11; }

// FUNCTION: GAME 0x355258
int func_00355258(int a, int b) { return b - 8; }

// FUNCTION: GAME 0x35FB78
int func_0035FB78(int a) { return a >= 0x181F; }

// FUNCTION: GAME 0x357980
int func_00357980(int *a) { return a[0x12]; }

// FUNCTION: GAME 0x35FD78
int func_0035FD78(int *a) { return a[0x19]; }

// FUNCTION: GAME 0x35BA48
void func_0035BA48(char *a, int b) { *(int *)(a + 0xFDC) = b; }

// FUNCTION: GAME 0x35BA50
int func_0035BA50(char *a) { return *(int *)(a + 0xFDC); }

// FUNCTION: GAME 0x35C4C0
void func_0035C4C0(int *a, int b) { a[0] = b; }

// FUNCTION: GAME 0x35C538
void func_0035C538(int *a, int b) { a[1] = b; }

// FUNCTION: GAME 0x35C540
void func_0035C540(int *a, int b) { a[3] = b; }

// FUNCTION: GAME 0x35EF30
void func_0035EF30(int *a, int b) { a[26] = b; }

// FUNCTION: GAME 0x35EF38
void func_0035EF38(int *a, int b) { a[27] = b; }

// FUNCTION: GAME 0x35EF70
void func_0035EF70(int *a, int b) { a[28] = b; }

// FUNCTION: GAME 0x350700
int func_00350700() { return func_00350718(); }

// FUNCTION: GAME 0x3508C0
int func_003508C0(char *a) { return func_0034CA98(a, *(int *)(a + 0x1FCC)); }

// FUNCTION: GAME 0x350C58
int func_00350C58(char *a, int b) { return func_0034CA68(a, *(int *)(a + 0x1FCC), b); }

// FUNCTION: GAME 0x351C00
int func_00351C00(char *a) { return func_0034CA98(a, *(int *)(a + 0x1FC8)); }

// FUNCTION: GAME 0x354B20
int func_00354B20(int a) { return func_00366C50(a, -1, 0x20); }

// FUNCTION: GAME 0x354D68
int func_00354D68() { return func_0036C3D0(); }

// FUNCTION: GAME 0x354DC8
int func_00354DC8(int a) { return func_0034DD70(a, 0xFF000F0D); }

// FUNCTION: GAME 0x354DE8
int func_00354DE8(int a) { return func_0034DD70(a, 0xFF000F0D); }

// FUNCTION: GAME 0x357240
int func_00357240() { return func_0035A620(); }

// FUNCTION: GAME 0x357490
int func_00357490(int a) { return func_0035C238(a, 2); }

// FUNCTION: GAME 0x3587D0
int func_003587D0(int a) { return func_0035C238(a, 3); }

// FUNCTION: GAME 0x358888
int func_00358888(int *a) { a[0x12] = 0; a[0x13] = 0; return func_0035C238(a, 4); }

// FUNCTION: GAME 0x35AB80
int func_0035AB80() { return func_0035AB98(); }

// FUNCTION: GAME 0x35AEC8
int func_0035AEC8() { return func_00366918(); }

// FUNCTION: GAME 0x35BC38
int func_0035BC38(int a) { return func_0035BC50(a, 1); }

// FUNCTION: GAME 0x35D188
int func_0035D188(int a) { return func_0035D1B0(a, 0, 0, 0, 0); }

// FUNCTION: GAME 0x35D4F0
int func_0035D4F0(char *a, int b, int c) { return func_0034C990(a, *(int *)(a + 0x20D8), b, c); }

// FUNCTION: GAME 0x35EB98
int func_0035EB98() { return func_0035EBB0(); }

// FUNCTION: GAME 0x35FD58
int func_0035FD58(int *a) { return func_0036CC80(a[0xC]); }

// FUNCTION: GAME 0x35FE60
int func_0035FE60() { return func_00360740(); }

// FUNCTION: GAME 0x35FE78
int func_0035FE78() { return func_003607A0(); }

// FUNCTION: GAME 0x35FE90
int func_0035FE90() { return func_0035FEA8(); }

// FUNCTION: GAME 0x35D6D8
void func_0035D6D8() { func_0035D728(); D_00766C90[1]--; }
