// Small functions in the ProDG game-code island 0x370000-0x387500.
struct B8 {
    char c[8];
};
extern short deciBelTbl[];
extern B8 D_0045B170;
extern char D_00773318[];
extern "C" void *memset(void *, int, unsigned);
extern "C" {
int func_00380AE8(char *, char *, char *);
void func_0032B188(int, int);
void func_0032A9F0(int, int);
void func_0032A6D0(int, int, int);
void func_0032B300(int, int);
void func_0032BDC0(int, int, int);
}

// FUNCTION: GAME 0x3807E0
extern "C" int func_003807E0(int unused, short x)
{
    short j = 0;
    do {
        unsigned short v = deciBelTbl[j];
        if (x == deciBelTbl[j])
            return j;
        if (x < deciBelTbl[j]) {
            short m = v - (short)((short)(v - deciBelTbl[j - 1]) >> 1);
            if (x < m)
                return (short)(j - 1);
            return j;
        }
        j++;
    } while (j < 0x80);
    return -1;
}

// FUNCTION: GAME 0x378540
extern "C" void func_00378540(void) {
    char *p = D_00773318;
    int i;
    memset(p, 0, 0x8B5C);
    p[4] = 1;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    *(B8 *)(p + 0x1B2) = D_0045B170;
    *(B8 *)(p + 0x2B2) = D_0045B170;
    *(B8 *)(p + 0x3B2) = D_0045B170;
    *(short *)(p + 0x12) = 4;
    *(short *)(p + 0x10) = 0x30;
    *(short *)(p + 0x14) = 0x30;
    for (i = 0x1F; i >= 0; i--) {
        p[0x5C + (0x1F - i)] = 4;
        p[0x7C + (0x1F - i)] = 4;
    }
}

// FUNCTION: GAME 0x384EC8
extern "C" int func_00384EC8(char *a, char *s) {
    char *d = s + 0x14;
    char *e = s + 0x4C;
    int r = func_00380AE8(a, d, s);
    if (r) {
        s[1] = r;
        return 1;
    }
    func_0032B188(*(int *)(d + 0x30), 1);
    *(int *)(s + 0x14) = *(int *)(s + 0x4C);
    *(int *)(d + 4) = *(int *)(e + 4);
    *(int *)(d + 8) = *(int *)(e + 8);
    *(int *)(d + 0xC) = *(int *)(e + 0xC);
    func_0032A9F0(*(int *)(d + 0x30), *(short *)(s + 4));
    func_0032A6D0(*(int *)(d + 0x30), 0, *(short *)(s + 8));
    func_0032A6D0(*(int *)(d + 0x30), 1, *(short *)(s + 0xA));
    s[0] = 0;
    func_0032B300(*(int *)(d + 0x30), 0);
    func_0032BDC0(*(int *)(d + 0x30), *(int *)(s + 0x84), *(unsigned char *)(a + 7));
    return 0;
}
