// COMPILER: ee-gcc2.96

int func_0036C568(int, int, int);
int func_0034DEC8(int);
int func_0034DD70();
void func_00350528(int, int);
int func_00355508(int);
int func_00350BE8(int, int);
void func_00350C58(int, int);
void func_0035A000(int, int, int);

// DRAFT: GAME 0x350390
// diff: 10 words; i and q swap s1/s2 (orig s2=i, s1=q)
#ifdef NONMATCHING
int func_00350390(int *a, int *b, unsigned c) {
    int *h = (int *)a[0x1FC0 / 4];
    int o = *h;
    int n;
    int *q;
    int i;
    if (o == 0) return 0;
    n = c >> 2;
    if ((unsigned)n > 16) n = 16;
    for (q = b, i = 0; i < n;) {
        func_0036C568(o, i, (int)q);
        i++;
        q++;
    }
    return n;
}
#endif

// FUNCTION: GAME 0x3504A0
void func_003504A0(int a, int b, int c, int d) {
    if (func_0034DEC8(a) != 0) {
        func_0034DD70(0, 0xFF000185, c, d);
        return;
    }
    func_00350528(a, b);
}

// DRAFT: GAME 0x350B60
// diff: 8 words; orig shares the return block and tail-calls 0x35A000 after bnez; ours differs in block layout
#ifdef NONMATCHING
void func_00350B60(int a) {
    int *p = (int *)(a + 0x950);
    int r = func_00355508(a);
    if (r == -1) return;
    if (func_00350BE8(a, r) == 0) return;
    func_00350C58(a, 1);
    if (*p != 0) return;
    func_0035A000(a, 5, 0);
}
#endif

int func_0035A1C8(int, int);
int func_003508C0(int);
void func_003507B0(int);
void func_00350820(int);
int func_00350C78(int);
void func_003508D8(int);
int func_00350D08(int, int *, int *, int *);
int func_003514B8(int, int, int, int, int *);
void func_003545F8(int);
int func_0034C7B0(int, int);
int func_0034CAD0(int, int);

// FUNCTION: GAME 0x350718
int func_00350718(int a) {
    int r;
    if (!func_0035A1C8(a, 5)) return 0;
    if (func_003508C0(a) == 1) return 0;
    func_003507B0(a);
    if (*(int *)(a + 0x48) == 2) func_00350820(a);
    r = func_00350C78(a);
    func_003508D8(a);
    func_00350B60(a);
    return r;
}

// FUNCTION: GAME 0x350C78
int func_00350C78(int a) {
    int l[4];
    int r = 0;
    while (*(int *)(a + 0x60) == 0) {
        r = func_00350D08(a, &l[0], &l[1], &l[2]);
        if (r != 0) break;
        r = func_003514B8(a, l[0], l[1], l[2], &l[3]);
        if (r != 0) break;
        if (l[3] == 0) break;
    }
    func_003545F8(a);
    return r;
}

// FUNCTION: GAME 0x351170
int func_00351170(int a) {
    int s = *(int *)(a + 0x1FC8);
    int x = func_0034C7B0(a, s);
    int y = func_0034CAD0(a, s);
    if (x - y < *(int *)(a + 0x28)) return func_0034DD70(a, 0xFF000F1C);
    return 0;
}
