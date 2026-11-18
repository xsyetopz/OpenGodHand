// COMPILER: ee-gcc2.96
int func_00346828();
void func_00348BE0();
void func_00335950();
void func_00347AF8();
void func_00347908();
void func_00347868();
extern char D_004590A8[];
void func_00349718();
void func_00349728();
void func_003572F8();
int func_00357258();
void func_00349158();
extern int D_003EE0A0;
int *func_00348938();
void func_0033BF88();
void func_0033BFA0();
void func_00348B78();
void func_00348B90();
void func_00349988();
int func_0034C378();
int func_00348968();

// FUNCTION: GAME 0x347BC0
void func_00347BC0(char *a, int b, int c)
{
    int s = func_00346828(a);
    if (s != 1) {
        func_00348BE0(D_004590A8);
        return;
    }
    func_00335950(*(int *)(a + 0x48));
    func_00347AF8(a, b, c);
    func_00347908(a, 1);
    func_00347868(a);
    *(int *)(a + 0x2E4) = 2;
    *(int *)(a + 0x2EC) = b;
    *(int *)(a + 0x2F0) = c;
    *(int *)(a + 0x2DC) = s;
    if (*(int *)(a + 0x2E0) == 0) *(int *)(a + 0x2E8) = s;
}

// FUNCTION: GAME 0x349630
int func_00349630(int *a)
{
    int s2 = a[0xF];
    int s1;
    func_00349718(a, 1);
    s1 = a[0];
    if (s1 != 1) {
        func_00349718(a, 0);
        return 0;
    }
    D_003EE0A0 = (int)a;
    func_00349728(a, 1);
    func_003572F8(s2);
    func_00349728(a, 0);
    if (a[1] == 0) {
        a[0x1A] = 0;
    } else {
        a[0x1A] = s1;
        func_00349158(a);
    }
    func_00349718(a, 0);
    return func_00357258(s2) != 1;
}

// FUNCTION: GAME 0x348338
int func_00348338(int a, int b, int c, int d)
{
    int r = 0;
    int *v = func_00348938(a);
    if (v && v[2]) r = ((int (*)())v[2])(b, c, d);
    return r;
}

// FUNCTION: GAME 0x3483A0
int func_003483A0(int a, int b, int c)
{
    int r = 0;
    int *v = func_00348938(a);
    if (v && v[3]) r = ((int (*)())v[3])(b, c);
    return r;
}

// FUNCTION: GAME 0x348B20
void func_00348B20()
{
    func_0033BF88(func_00348B78, 0);
    func_0033BFA0(func_00348B90, 0);
}

// FUNCTION: GAME 0x348B50
void func_00348B50()
{
    func_0033BF88(0, 0);
    func_0033BFA0(0, 0);
}

// FUNCTION: GAME 0x349960
void func_00349960(int a, int *b, int c)
{
    func_00349988(a, b, c, 0, 0, b[3], b[4]);
}

// FUNCTION: GAME 0x34E020
int func_0034E020(char *a, int b, int c)
{
    return func_0034C378(a, *(int *)(a + 0x1F44), b, c);
}

// FUNCTION: GAME 0x348498
void func_00348498(int *a)
{
    if (func_00348968(a) == 1) {
        int x = a[7];
        int *v = (int *)a[2];
        if (x && v && v[6]) ((void (*)())v[6])(x);
    }
}

// FUNCTION: GAME 0x348440
void func_00348440(int *a)
{
    if (func_00348968(a) == 1) {
        int *v = (int *)a[2];
        int q = a[7];
        int p = a[5];
        if (v && v[5]) ((void (*)())v[5])(q, p);
    }
}
