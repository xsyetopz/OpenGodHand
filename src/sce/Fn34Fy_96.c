// COMPILER: ee-gcc2.96
extern int func_00348968(char *);
extern int func_00346E20(char *, int);
extern int func_00346C48(char *);
extern int func_0035FC58(int, int);

// FUNCTION: GAME 0x3484F0
int func_003484F0(char *p)
{
    int rv = 0;
    char *o;
    int (*fn)(int);
    int arg;
    if (func_00348968(p) != 1)
        return 0;
    o = *(char **)(p + 8);
    arg = *(int *)(p + 0x1C);
    if (o != 0) {
        fn = *(int (**)(int))(o + 0x1C);
        if (fn != 0)
            rv = fn(arg);
    }
    return rv;
}

// FUNCTION: GAME 0x346D08
int func_00346D08(char *p, char *b)
{
    int s;
    int t = *(int *)(p + 0x4C);
    if (t == 0) {
        int v = func_00346E20(p, *(int *)(b + 0x30));
        if (v != -1)
            *(int *)(p + 0x50) = v;
        else
            *(int *)(p + 0x50) = 0x11;
        s = *(int *)(p + 0x50);
    } else {
        s = t;
    }
    return func_0035FC58(func_00346C48(p), s);
}
