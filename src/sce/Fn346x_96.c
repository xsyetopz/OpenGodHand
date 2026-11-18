// COMPILER: ee-gcc2.96
extern char D_004588B0[];
extern char D_00458928[];
extern char D_00458900[];
extern char D_004588D8[];
void func_00348BE0();
void func_00349840(char *);
int func_003492E8(void);
int func_00349468(char *);
char *func_00348938(char *);

// FUNCTION: GAME 0x00346E70
int func_00346E70(unsigned a)
{
    int r;
    switch (a) {
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    default:
        func_00348BE0(D_004588B0);
        r = 3;
        break;
    }
    return r;
}

// FUNCTION: GAME 0x00347080
int func_00347080(char *p)
{
    int r = 3;
    switch (*(unsigned *)(p + 0x88)) {
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: break;
    default: func_00348BE0(D_004588D8); break;
    }
    return r;
}

// FUNCTION: GAME 0x003470F0
int func_003470F0(char *p)
{
    int r = 1;
    switch (*(unsigned *)(p + 0x8C)) {
    case 1: break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    default: func_00348BE0(D_00458900); break;
    }
    return r;
}

// FUNCTION: GAME 0x00347160
int func_00347160(int a)
{
    int r = 1;
    switch (a) {
    case 0: r = 0; break;
    case 1: break;
    default:
        func_00348BE0(D_00458928);
        break;
    }
    return r;
}

// FUNCTION: GAME 0x003483F8
void func_003483F8(char *p, int a)
{
    char *v = func_00348938(p);
    if (a && v && *(void (**)(int))(v + 0x10))
        (*(void (**)(int))(v + 0x10))(a);
}

// FUNCTION: GAME 0x00349250
int func_00349250(char *p)
{
    int r = 0;
    func_00349840(p);
    if (func_003492E8() == 1)
        r = func_00349468(p);
    return r;
}
