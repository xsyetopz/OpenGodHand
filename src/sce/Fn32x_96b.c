// COMPILER: ee-gcc2.96

extern char D_004515E8[], D_00451620[], D_00451928[];
extern int D_003C80E0, D_003C80B0, D_003CF9D0, D_003CF9D4;
extern volatile int D_003C8138;

void func_00324880(void);
int func_00324640(int, int, int, int, int, int, int *);
void func_00324898(void);
int *func_00323478(void);
int func_00327D00(int, int);
void func_0033F130(char *);
void func_00327F00(int);
int func_00328098(int);
void func_00328018(int);
void func_00328F70(int);
int func_00328D40(int);
int GetThreadId(void);
int func_003AFB30(int, int);
void func_003252F8(int);

// FUNCTION: GAME 0x3245B0
int func_003245B0(int a, int b, int c, int d, int e, int f) {
    int buf[4];
    int r;
    func_00324880();
    r = func_00324640(a, b, c, d, e, f, buf);
    func_00324898();
    return r;
}

// FUNCTION: GAME 0x323700
int func_00323700(int *a, int b, int c, int d, int e) {
    a[0x34 / 4] = c;
    a[0x30 / 4] = a[0x3C / 4] = d;
    a[0x38 / 4] = b;
    a[0x40 / 4] = e;
    a[0x14 / 4] = 0;
    func_00327F00(a[1]);
    if (func_00328098(a[1]) == 4) {
        func_00328018(a[1]);
        return -1;
    }
    a[0xC / 4] = e;
    a[0x10 / 4] = e << 11;
    return 0;
}

// FUNCTION: GAME 0x324440
int func_00324440(int *a) {
    int v;
    if (a == 0) {
        func_0033F130(D_00451928);
        return -3;
    }
    v = a[0x10 / 4];
    if (v > 0x7FFFF7FF) {
        func_00328F70(a[1]);
        if (func_00328098(a[1]) == 4) return -5;
        v = func_00328D40(a[1]);
        a[0x10 / 4] = v;
    }
    return v;
}

// FUNCTION: GAME 0x3234D0
char *func_003234D0(void) {
    char *s = (char *)func_00323478();
    int v;
    if (s == 0) {
        func_0033F130(D_004515E8);
        return 0;
    }
    v = func_00327D00(0, 0x100);
    *(int *)(s + 4) = v;
    if (v == 0) {
        func_0033F130(D_00451620);
        return 0;
    }
    s[0] = 1;
    s[1] = 1;
    *(int *)(s + 0x18) = 0;
    *(int *)(s + 0x1C) = 0;
    *(int *)(s + 0x20) = 0;
    s[2] = 0;
    *(int *)(s + 8) = 0;
    s[3] = 0;
    *(int *)(s + 0x2C) = 0x200;
    return s;
}

// FUNCTION: GAME 0x324C90
void func_00324C90(void) {
    int id, t;
    if (D_003C80E0 == 0) {
        id = GetThreadId();
        D_003CF9D0 = func_003AFB30(id, D_003C80B0);
        D_003CF9D4 = id;
        func_003252F8(D_003C8138);
        t = D_003C8138;
    }
    D_003C80E0 = D_003C80E0 + 1;
}
