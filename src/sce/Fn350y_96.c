// COMPILER: ee-gcc2.96
extern int func_0035A1C8();
extern int func_0036A668();
extern int func_0034CA30();
extern int func_00350988();
extern void func_0034CA00();
extern void func_00350B38();

// FUNCTION: GAME 0x350820
void func_00350820(char *s)
{
    int *p = *(int **)(s + 0x1FC0);
    int q = *p;
    int buf[8];
    buf[0] = func_0035A1C8(s, 0x5D);
    buf[1] = func_0035A1C8(s, 0x5E);
    if (buf[0] != 0 && buf[1] != 0) {
        if (p[0x78 / 4] == 0xC0) {
            if (func_0036A668(q, buf, buf + 4) == 0) {
                p[0x74 / 4] = 2;
                p[0x78 / 4] = 0xC8;
            }
        }
    }
}

// FUNCTION: GAME 0x3508D8
void func_003508D8(char *s)
{
    int *p = (int *)(s + 0x1FB8);
    int b = p[5];
    int a = p[4];
    if (func_0034CA30(s, b) != 1 && func_0034CA30(s, a) == 1) {
        if (func_00350988(s)) {
            func_0034CA00(s, b, 1);
            func_00350B38(s);
        }
    }
}
