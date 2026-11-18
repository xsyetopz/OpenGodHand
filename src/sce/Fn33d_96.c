// COMPILER: ee-gcc2.96
extern int D_00758400, D_003E8DCC, D_003E9944;
extern char D_004551B8[];
extern void func_00336330();
extern void *memset(void *, int, unsigned);
extern char D_003E9D60[];
extern void func_00338990(), func_003389F8(), func_00338AC0(), func_00338A10(), func_00338B40(), func_003389C8();
extern void func_003394D0(), func_00339550(), func_0033A0C0(), func_0033A140(), func_00332670();
extern void func_0033F9D8(), func_0033FA10(), func_0033F9B0(), func_0033FA00(), func_0033FB48();
extern void func_003325F8(), func_0033BDD8(), func_0033F888(), func_0033C520(), func_0033C708();

extern char D_00454458[], D_00454960[], D_004551B8[];
extern void func_00332808(), func_00334008(), func_003362E8(), func_00336300(), func_00336330(), func_00335950(), func_003350F0();
extern int func_00330480();
extern char D_00454150[], D_003D84C0[];
extern int *D_00755E80[];
extern int D_003D90DC;
extern int strlen(), sceClose(), scePrintf();
extern void func_00331D40(), func_00331D78(), func_003389F8(), func_00332398(), func_00338A10(), func_00331C78();
extern int func_00398890();
extern int D_003DA380[], D_007561C0, D_007562C0[];
extern int sceSifCallRpc();
extern char D_003D8D40[], D_003D9FE0[];
extern void func_003350F0();
extern int D_003E0710, D_003E0708;
extern char D_004558C8[], D_003DED70[];
extern void func_003260C8(), func_00336498();
// FUNCTION: GAME 0x33AF28
void func_0033AF28(int a)
{
    D_00758400 = a;
    func_00332670(0x23, &D_00758400, 1, 0, 0);
}

// FUNCTION: GAME 0x33CFB8
void func_0033CFB8(char *p)
{
    func_0033F9D8(*(int *)(p + 8), p + 0xAC, p + 0xB0);
    func_0033FA10(*(int *)(p + 8), p + 0xA6, p + 0xA8, p + 0xAA);
}

// FUNCTION: GAME 0x33CFF8
void func_0033CFF8(char *p)
{
    func_0033F9B0(*(int *)(p + 8), p + 0xAC, p + 0xB0);
    func_0033FA00(*(int *)(p + 8), *(short *)(p + 0xA6), *(short *)(p + 0xA8), *(short *)(p + 0xAA));
}

// FUNCTION: GAME 0x33D278
void func_0033D278(int *p)
{
    if (p[1] == 3) {
        func_0033FB48(p[2]);
        p[35] = 0;
        p[1] = 0;
    }
}

// FUNCTION: GAME 0x33B010
void func_0033B010(void)
{
    if (--D_003E8DCC == 0)
        func_003325F8();
}

// FUNCTION: GAME 0x33C728
void func_0033C728(void)
{
    func_0033F888();
    func_0033C520();
    memset(D_003E9D60, 0, 0x1040);
    func_0033C708(0);
}

// FUNCTION: GAME 0x336AC0
int func_00336AC0(int *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_004551B8);
        return 0;
    }
    return p[5];
}

// FUNCTION: GAME 0x330EC0
int func_00330EC0(void)
{
    int *p = (int *)func_00330480();
    int (*f)(int, int, int, int);
    if (p) {
        f = (int (*)(int, int, int, int))p[24];
        if (f)
            return f(0, 100, 0, 0);
        return 0;
    }
}

// FUNCTION: GAME 0x333170
int func_00333170(char *p)
{
    if (p == 0) {
        func_00332808((int *)p, D_00454458);
        return 0;
    }
    if (p[2] == 1)
        return *(int *)(p + 20) << 11;
    return 0;
}

// FUNCTION: GAME 0x334AD0
int func_00334AD0(char *p)
{
    if (p == 0) {
        func_00334008((int *)p, D_00454960);
        return 0;
    }
    if (p[2] == 1)
        return *(int *)(p + 40) << 11;
    return 0;
}

// FUNCTION: GAME 0x336980
void func_00336980(char *p)
{
    if (p == 0) {
        func_00336330(p, D_004551B8);
        return;
    }
    func_003362E8();
    p[1] = 0;
    func_00336300();
}

// FUNCTION: GAME 0x335530
void func_00335530(char *p)
{
    if (p) {
        func_00335950();
        p[0] = 0;
        memset(p, 0, 0x238);
    }
}

// FUNCTION: GAME 0x330C88
void func_00330C88(void)
{
    int **p = D_00755E80;
    int i;
    for (i = 31; i >= 0; i--) {
        int *q = *p;
        p += 4;
        if (q) {
            void (*f)(void) = (void (*)(void))*q;
            if (f)
                f();
        }
    }
}

// FUNCTION: GAME 0x332838
int func_00332838(int a, int b)
{
    int r;
    func_00331C78(0x8000);
    r = func_00398890(a, b, D_003D90DC);
    func_00331C78(0x8001);
    return r;
}

// FUNCTION: GAME 0x331F50
int func_00331F50(int fd)
{
    int r;
    func_00331D40();
    r = sceClose(fd);
    if (r < 0) {
        scePrintf(D_00454150, r);
    }
    func_00331D78();
    return r;
}

// FUNCTION: GAME 0x3351C0
void func_003351C0(int a, int *r)
{
    int *t = D_003DA380;
    r[0] = 0;
    r[1] = 0;
    if (t[0])
        func_003350F0(r, a, t[0], t[1]);
}

// FUNCTION: GAME 0x332090
void func_00332090(int a)
{
    D_007561C0 = a;
    sceSifCallRpc(D_003D8D40, 3, 0, &D_007561C0, 4, D_007562C0, 0, 0, 0);
}

// FUNCTION: GAME 0x334038
int func_00334038(void)
{
    char *p = D_003D9FE0;
    int i;
    for (i = 0; i < 13; i++) {
        if (p[0] == 1) {
            if (p[2] == 2)
                return 1;
        }
        p += 0x30;
    }
    return 0;
}

// FUNCTION: GAME 0x3388F8
int PS2RNA_SetStmHdInfo(void)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0)
        return 0;
    func_003260C8(D_004558C8);
    return 0;
}

// FUNCTION: GAME 0x3364A0
void func_003364A0(void)
{
    char *p = D_003DED70;
    int i;
    for (i = 39; i >= 0; i--) {
        if (*p)
            func_00336498(p);
        p += 0x38;
    }
}
