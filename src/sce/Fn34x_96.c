// COMPILER: ee-gcc2.96
extern int func_00346828();
extern int func_00346AE8();
extern void func_00345D40();
extern void func_00346228();
extern void func_00348BE0();
extern char D_00458110[];
extern int func_00348FF0();
extern void func_00348DD8();
extern int func_00359E80();

// FUNCTION: GAME 0x346078
void func_00346078(int a, int b, int c)
{
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00458110);
    } else {
        func_00345D40(a, func_00346AE8(a));
        func_00346228(a, b, c);
    }
}

// FUNCTION: GAME 0x348D58
void func_00348D58(char *o)
{
    int s1 = *(int *)(o + 0x1AC);
    int s2 = *(int *)(o + 0x3C);
    int r;
    if (s1 == 1 && func_00348FF0() == s1)
        *(int *)(o + 0x1AC) = 0;
    func_00348DD8(o);
    r = func_00359E80(s2);
    if (r == 4 || r == 6)
        *(int *)(o + 4) = 2;
}

#ifdef NONMATCHING
extern void func_00335638();
extern char D_004590D8[];
extern int func_0035A1C8();
extern void func_0034FA28();
extern void func_00345B38();
extern void func_00345F48();
extern int func_0034CCE8();
extern char D_004592D0[];

// DRAFT: GAME 0x347C80
// diff: orig hoists a1/a2/a3/t0 once before the branch and shares them in both tail calls; ours re-derives them in the else arm (10 words)
void func_00347C80(char *a, int b, int c, int d)
{
    if (func_00346828(a) != 1)
        func_00348BE0(D_004590D8, b, 0, c, d);
    else
        func_00335638(*(int *)(a + 0x48), b, 0, c, d);
}

// DRAFT: GAME 0x348F68
// diff: orig loads lb 0x72 into v1 and bnez v1; ours uses v0 (2 words)
void func_00348F68(char *o)
{
    if (func_00359E80(*(int *)(o + 0x3C)) == 3) {
        func_00345B38(o);
        if (o[0x72] == 0)
            func_00345F48(o, 0);
        if (o[0x70] == 1 && func_0034CCE8(*(int *)(o + 0x3C)))
            func_00348BE0(D_004592D0);
    }
}

// DRAFT: GAME 0x34EEE0
// diff: orig tests s==1 / s<2 / s==2 in sequence with movn select and saves s1 first; ours folds the tests and spills differently (28 words)
int func_0034EEE0(int a, int b)
{
    int t[2];
    int s = func_0035A1C8(a, 0x3B);
    int r = b;
    switch (s) {
    case 1:
        break;
    case 2:
        func_0034FA28(a, t, t + 1);
        r = s;
        if (t[1] < 2)
            r = b;
        break;
    }
    return r;
}
#endif
