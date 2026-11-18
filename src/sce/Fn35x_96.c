// COMPILER: ee-gcc2.96

extern int D_003EE2C4[];

int func_0034DEC8(int);
int func_0034DD70();
int func_0035A1C8(int, int);
int func_00357140(int);
int func_00358930(int);
int func_0034CA98(int, int);
void func_0034CA68(int, int, int);
void func_003589C0(int);
void func_0034D098(int);
void func_0034BD58(int);
int func_00358888(int);
int func_003582C0(void);
int func_00358328(void);
int func_00358368(int, int);

// FUNCTION: GAME 0x3588B0
int func_003588B0(int a) {
    int r;
    if (func_0034DEC8(a) != 0) return func_0034DD70(0, 0xFF000132);
    if (func_0035A1C8(a, 0x2F) == 1) r = func_00357140(a);
    else r = func_00358930(a);
    *(int *)(a + 0x44) = 1;
    return r;
}

// FUNCTION: GAME 0x358F68
int func_00358F68(int a) {
    int s;
    if (func_0034DEC8(a) != 0) return func_0034DD70(0, 0xFF000135);
    s = *(int *)(a + 0x1F44);
    if (func_0034CA98(a, s) == 1) return 0;
    func_0034CA68(a, s, 1);
    *(int *)(a + 0x44) = 1;
    return 0;
}

// FUNCTION: GAME 0x3587E8
int func_003587E8(int a) {
    int v, i;
    int *p;
    if (func_0034DEC8(a) != 0) return func_0034DD70(0, 0xFF000131);
    func_003589C0(a);
    func_0034D098(a + 0x78);
    func_0034BD58(a);
    v = func_00358888(a);
    p = D_003EE2C4;
    for (i = 7; i >= 0; i--, p++)
        if (*p == a) *p = 0;
    return v;
}

// FUNCTION: GAME 0x358228
int func_00358228(int a, int b) {
    int *p = D_003EE2C4;
    int i;
    if (func_003582C0() != 0) return 0;
    i = func_00358328();
    if (i == -1) {
        func_0034DD70(0, 0xFF000206);
        return 0;
    }
    return p[i] = func_00358368(a, b);
}

int func_00359218(int, int);
int func_0035C2D0(int, int, int, int, int);

// FUNCTION: GAME 0x359168
int func_00359168(int a, int b) {
    int r;
    if (func_0034DEC8(a) != 0) return func_0034DD70(0, 0xFF00013B);
    r = func_00359218(a, 2);
    if (r != 0) return r;
    *(int *)(a + 0x96C) += 1;
    return func_0035C2D0(a, 6, 0xC, 0, b);
}
