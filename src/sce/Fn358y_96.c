// COMPILER: ee-gcc2.96
extern int func_0035B4A0();
extern int func_003570D0();
extern int func_0035A1C8();
extern int func_0035C368();
extern int func_0034CA98();
extern void func_0034DF68();
extern void func_0034DF80();
extern int func_00357AA0();
extern int func_00357C20();
extern int func_00356FD8();

// FUNCTION: GAME 0x357068
int func_00357068(char *s, int a)
{
    if ((unsigned)(*(int *)(s + 0x4C) - 3) >= 2)
        return 0;
    func_0035B4A0();
    return func_003570D0(s, a);
}

// FUNCTION: GAME 0x3579F0
int func_003579F0(char *s)
{
    int *p = (int *)(s + 0x950);
    int r = 0;
    char buf[16];
    func_0034DF68(buf);
    if (p[0x20 / 4] == 0) {
        if (func_00357AA0(s)) {
            p[0x20 / 4] = 1;
            p[0x24 / 4] += 1;
            r = func_00356FD8(s, 1);
        }
    } else {
        if (func_00357C20(s)) {
            p[0x20 / 4] = 0;
            r = func_00356FD8(s, 0);
        }
    }
    func_0034DF80(buf);
    return r;
}

// FUNCTION: GAME 0x357D00
int func_00357D00(int *s)
{
    unsigned i;
    if (func_0035A1C8(s, 5) && func_0035C368(s, 6))
        return 1;
    if (func_0035A1C8(s, 6) && func_0035C368(s, 7))
        return 1;
    i = 0;
    do {
        if (func_0034CA98(s, i++))
            return 1;
    } while (i < 8);
    return 0;
}
