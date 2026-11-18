// COMPILER: ee-gcc2.96
extern char D_00457EC8[];
extern char D_00458168[];
extern int func_00356EF8();
extern void func_00348BE0();
extern int func_003245B0();

// FUNCTION: GAME 0x345B88
int func_00345B88(char *p)
{
    int r;
    int h = *(int *)(p + 0x3C);
    int v;
    if (h == 0)
        return 0;
    v = func_00356EF8(h);
    if (v == 0) {
        r = 0;
    } else if (v == 1) {
        r = 1;
    } else {
        func_00348BE0(D_00457EC8, v);
        r = 0;
    }
    return r;
}

// FUNCTION: GAME 0x346228
void func_00346228(char *p, int a, int b)
{
    int v[3];
    if (func_003245B0(a, b, *(int *)(p + 0x1A4), v, v + 1, v + 2) == 0) {
        *(int *)(p + 0x1B0) = v[0];
        *(int *)(p + 0x1B4) = v[1];
        *(int *)(p + 0x1B8) = v[2];
        *(int *)(p + 0x1AC) = 1;
    } else {
        func_00348BE0(D_00458168);
    }
}
