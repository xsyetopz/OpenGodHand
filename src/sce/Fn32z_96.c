// COMPILER: ee-gcc2.96
// SCE framed units (continued from Fn32y_96.c), -O2 -G0.

int func_003228C0();
int adxf_Stop();
extern char D_004518B0[], D_004518D8[], D_00451800[], D_00451828[], D_00451858[], D_00451880[];
void func_0033F130();
void func_00328368();
int func_00328140();
void func_00323A00();
void func_003282D0();

// FUNCTION: GAME 0x3242B0
int adxf_Seek(int *s, int off, int w)
{
    func_003228C0(6, 0, s, off, w);
    if (!s) {
        func_0033F130(D_004518B0);
        return -3;
    }
    if (((char *)s)[1] == 2)
        adxf_Stop(s);
    if (w == 0)
        s[5] = off;
    else if (w == 1)
        s[5] = s[5] + off;
    else if (w == 2)
        s[5] = s[3] + off;
    else {
        func_0033F130(D_004518D8);
        return -3;
    }
    if (s[5] < 0)
        s[5] = 0;
    else if (s[5] > s[3])
        s[5] = s[3];
    func_003228C0(6, 1, s, off, w);
    return s[5];
}

// FUNCTION: GAME 0x323F18
int adxf_Stop(char *s)
{
    func_003228C0(5, 0, s, -1, -1);
    if (!s) {
        func_0033F130(D_00451800);
        return -3;
    }
    if (s[1] != 1) {
        if (s[1] == 3)
            s[1] = 1;
        else {
            if (!*(int *)(s + 4)) {
                func_0033F130(D_00451828);
                return -1;
            }
            func_00328368(*(int *)(s + 4));
            func_0033E678();
            *(int *)(s + 0x20) = func_00328140(*(int *)(s + 4)) - *(int *)(s + 0x14);
            func_00323A00(s);
            s[1] = 1;
            func_0033E690();
            func_003228C0(5, 1, s, -1, -1);
        }
    }
    return *(int *)(s + 0x14);
}

// FUNCTION: GAME 0x324040
int adxf_StopNw(char *s)
{
    func_003228C0(7, 0, s, -1, -1);
    if (!s) {
        func_0033F130(D_00451858);
        return -3;
    }
    if (s[1] != 1) {
        if (s[1] == 3)
            s[1] = 1;
        else {
            if (!*(int *)(s + 4)) {
                func_0033F130(D_00451880);
                return -1;
            }
            func_003282D0(*(int *)(s + 4));
            s[3] = 1;
            func_003228C0(7, 1, s, -1, -1);
        }
    }
    return *(int *)(s + 0x14);
}

// FUNCTION: GAME 0x324108
void func_00324108(char *s)
{
    char c;
    int r, d;
    if (s[1] == 2) {
        s[1] = func_00328098(*(int *)(s + 4));
        d = func_00328140(*(int *)(s + 4)) - *(int *)(s + 0x14);
        *(int *)(s + 0x20) = d;
        if ((unsigned char)(s[1] - 3) < 2) {
            *(int *)(s + 0x14) += d;
            func_00323A00(s);
        }
    }
    c = s[3];
    if (c == 1) {
        r = func_00328098(*(int *)(s + 4));
        if (r == c) {
            *(int *)(s + 0x20) = func_00328140(*(int *)(s + 4)) - *(int *)(s + 0x14);
            func_00323A00(s);
            s[1] = r;
            s[3] = 0;
        }
    }
}
