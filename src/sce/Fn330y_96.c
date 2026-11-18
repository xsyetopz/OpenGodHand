// COMPILER: ee-gcc2.96
extern char D_00454110[];
extern void func_00331D40();
extern int func_003B4D98();
extern void func_00331D78();
extern void scePrintf();
// FUNCTION: GAME 0x331E70
int func_00331E70(int a, int b, int c)
{
    int r;
    func_00331D40();
    r = func_003B4D98(a, b, c);
    if (r < 0) {
        scePrintf(D_00454110, r);
    }
    func_00331D78();
    return r;
}

extern char D_00454170[];
extern int sceRead();
// FUNCTION: GAME 0x331FA8
int func_00331FA8(int a, int b, int c)
{
    int r;
    func_00331D40();
    r = sceRead(a, b, c);
    if (r < 0) {
        scePrintf(D_00454170, r);
    }
    func_00331D78();
    return r;
}

extern int D_007561C0[4];
extern int D_007562C0[];
extern char D_003D8D40[];
extern int sceSifCallRpc();
// FUNCTION: GAME 0x332020
int func_00332020(int a, int b, int c, int d)
{
    D_007561C0[0] = a;
    D_007561C0[1] = b;
    D_007561C0[2] = c;
    D_007561C0[3] = d;
    sceSifCallRpc(D_003D8D40, 2, 0, D_007561C0, 0x10, D_007562C0, 4, 0, 0);
    return D_007562C0[0];
}

extern int D_003D84B4;
extern char D_004541C0[];
extern int sprintf();
// FUNCTION: GAME 0x3320F8
void func_003320F8(int unused, char *buf, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        buf[i] = -0x56;
    }
    sprintf(buf, D_004541C0, D_003D84B4);
    D_003D84B4++;
}

extern volatile int D_003DA5D8;
extern int D_003DA5F0;
extern char D_003DA5F8[];
extern void func_00335CE8(), func_00335DD0(), func_00335D18(), func_00335D00();
extern void *memset();
// FUNCTION: GAME 0x335DE0
void func_00335DE0()
{
    int buf[4];
    D_003DA5D8;
    func_00335CE8(buf);
    if (D_003DA5F0 == 0) {
        memset(D_003DA5F8, 0, 0x4700);
        func_00335DD0();
        func_00335D18(0, 0);
    }
    D_003DA5F0++;
    func_00335D00(buf);
}

extern char D_00454458[];
extern void func_00332808();
// FUNCTION: GAME 0x332DD0
int func_00332DD0(int *f, int off, int whence)
{
    int size, pos;
    if (f == 0) {
        func_00332808(f, D_00454458);
        return 0;
    }
    if (whence == 0) {
        f[3] = off;
    } else if (whence == 2) {
        f[3] = f[2] + off;
    } else if (whence == 1) {
        f[3] = f[3] + off;
    }
    size = f[2];
    pos = f[3];
    f[5] = 0;
    if (pos >= size) {
        pos = size;
    }
    if (pos < 0) {
        pos = 0;
    }
    f[3] = pos;
    return pos;
}

extern int strlen();
extern int func_00333470();
// FUNCTION: GAME 0x3334C8
int func_003334C8(char *a, char *b)
{
    int n = strlen(a);
    int i;
    if (n != strlen(b)) {
        return -1;
    }
    for (i = 0; i < n;) {
        if (func_00333470(a[i], b[i++]) != 0) {
            return -1;
        }
    }
    return 0;
}
