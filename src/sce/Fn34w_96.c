// COMPILER: ee-gcc2.96

extern int D_003EE080;
extern char D_0075CC80[], D_00758C80[];
extern char D_00458110[], D_00458038[];

int func_003463F8(void);
void func_00346478(void);
void func_00346498(int, int, char *);
void func_00346578(char *, int, int);
void func_00346660(int);
int func_00346828(int);
int func_00346AE8(void);
void func_00345D40(int, int);
void func_00346228(int, int, int);
void func_00348BE0(char *);
void func_003497F8(int);
void func_00345DF0(int);
void func_00345BE0(int);
void func_00342FF8(int);

// FUNCTION: GAME 0x346368
void func_00346368(void) {
    if (func_003463F8() == 1) {
        int *p = &D_003EE080;
        if (*p == 0) return;
        func_00346478();
        func_00346498(0, 0x4000, D_0075CC80);
        func_00346660(8);
        func_00346578(D_00758C80, 0x4000, 0);
        func_00346660(9);
        *p = 0;
    }
}

// FUNCTION: GAME 0x3462D8
void func_003462D8(void) {
    int r = func_003463F8();
    int *p = &D_003EE080;
    if (r == 1 && *p != r) {
        func_00346478();
        func_00346498(0, 0x4000, D_00758C80);
        func_00346660(8);
        func_00346578(D_0075CC80, 0x4000, 0);
        func_00346660(9);
        *p = r;
    }
}

// FUNCTION: GAME 0x345D58
void func_00345D58(int *a, int b) {
    if (func_00346828((int)a) != 1) {
        func_00348BE0(D_00458038);
        return;
    }
    func_003497F8(1);
    func_00345DF0((int)a);
    a[0x1BC / 4] = b;
    a[0x1D4 / 4] = 0;
    a[0x1D0 / 4] = 2;
    a[0x1D8 / 4] = 0;
    a[0x1DC / 4] = 0;
    func_00345BE0((int)a);
    func_003497F8(0);
    func_00342FF8((int)a);
}

int func_00345750(int, int);
int func_00359E80(int);
extern char D_00458488[];

// DRAFT: GAME 0x3468B8
// diff: 39 words; ours if-converts the k<0 select and the 4/6 compare differently (orig 38 words, s2=2 shared)
#ifdef NONMATCHING
int func_003468B8(int *a) {
    int r = func_00346828((int)a);
    int v, k;
    if (r != 1) {
        func_00345750(-0xC, 2);
        func_00348BE0(D_00458488);
        return 0;
    }
    v = a[1];
    if (v != 2) return v;
    k = func_00359E80(a[0x3C / 4]);
    v = k < 0 ? 4 : r;
    if (k == 4) return v;
    if (k == 6) return 2;
    return v;
}
#endif

extern char D_004575C8[], D_004575F8[], D_00457620[];

// FUNCTION: GAME 0x344278
int func_00344278(int *a) {
    int r = 1;
    if (a[0] == 2) { func_00348BE0(D_004575C8); r = 0; }
    if (*(unsigned *)((char *)a + 0x24) >= 3) { func_00348BE0(D_004575F8); r = 0; }
    if (a[0x10 / 4] >= 0xF) { func_00348BE0(D_00457620); r = 0; }
    return r;
}
