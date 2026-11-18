// COMPILER: ee-gcc2.96
extern char D_00458E80[], D_00458EB0[], D_00458EE0[];
void func_00348BE0();
int func_0034DEC8(char *);
void func_0034DD70(int, int);
int func_0035A1C8(char *, int);
int func_003468B8(char *);
int func_00346828(char *);
int func_003355C8(int, int);
void func_0034B478(int, char *, int);

// FUNCTION: GAME 0x0034B648
void func_0034B648(char *p, int a)
{
    if (func_0034DEC8(p)) {
        func_0034DD70(0, 0xFF0001A3);
        return;
    }
    if (func_0035A1C8(p, 6))
        (*(void (**)(char *, int))(*(char **)(p + 0x2114) + 0xC))(p, a);
}

// FUNCTION: GAME 0x00346848
int func_00346848(char *p)
{
    int r = func_003468B8(p);
    if (*(int *)(p + 0x2D8) == 1 && *(int *)(p + 0x2DC) == *(int *)(p + 0x2D8)
        && (unsigned)(*(int *)(p + 0x2E8) - 2) < 2) {
        if (r == 1 || r == 3)
            r = 2;
    }
    return r;
}

// FUNCTION: GAME 0x003477A8
void func_003477A8(char *p, int a)
{
    if (func_00346828(p) != 1) {
        func_00348BE0(D_00458E80);
        return;
    }
    if (a == 0) {
        func_00348BE0(D_00458EB0);
        return;
    }
    if (func_003355C8(*(int *)(p + 0x48), a) < 0) {
        *(int *)(p + 4) = 4;
        func_00348BE0(D_00458EE0, a);
        return;
    }
    *(int *)(p + 0x74) += 1;
}

// FUNCTION: GAME 0x0034B430
void func_0034B430(char *p, int b)
{
    char *t = *(char **)(p + 0x2004);
    int h = *(int *)t;
    char *q = p + 0x1020;
    if (b == 0 && *(int *)(t + 0x2C) == 1)
        return;
    func_0034B478(h, q, b);
}

extern char D_004577D0[];
void func_003448B0(char *, int);
int func_003466F8(char *);
int func_00359080(int, int *, int *);
void func_00344D50(char *, int);
void func_00344948(char *, int, int *);
void func_003448F8(char *, int *);
int func_00341480(int, int, int *, int *, int *, int *, int);
int func_00340B00(int, int *, int *, int *, int *);

// FUNCTION: GAME 0x003447A8
int func_003447A8(char *p, int *q, int *o)
{
    int t;
    int r;
    memset(o, 0, 0x90);
    o[0] = 0;
    o[1] = -1;
    *q = -1;
    r = func_00346828(p);
    if (r != 1) {
        func_00348BE0(D_004577D0);
        return 0;
    }
    func_003448B0(p, 2);
    {
        int v = func_003466F8(p);
        int k;
        if (!v)
            return 0;
        k = func_00359080(v, q, &t);
        if (k != r)
            return k;
    }
    *(int *)(p + 0x78) = t;
    func_00344D50(p, t);
    func_00344948(p, t, o);
    o[1] = *q;
    *(int *)(p + 0xB8) = o[0x30 / 4];
    func_003448F8(p, o);
    return 1;
}

// FUNCTION: GAME 0x003417F0
int func_003417F0(int a0, int a1, short *a2, char *a3, char *t0, char *t1, char *t2, int *t3, int *s50, int *s58, int s60)
{
    int w0;
    int w1;
    int w2;
    int w3;
    int r, d;
    if (a1 < 8) {
        *a2 = 0;
        return -1;
    }
    r = func_00341480(a0, a1, &w0, &w1, &w2, &w3, s60);
    if (!r)
        return -1;
    d = r - a0;
    *a2 = d;
    if ((short)d <= 0)
        return -1;
    *t3 = w0;
    *t2 = (unsigned char)w1;
    *t0 = (unsigned char)w2;
    *s50 = w3;
    *a3 = -1;
    *t1 = (*t2 * *t0) / 8;
    *s58 = 1;
    return 0;
}

// FUNCTION: GAME 0x00340EF8
int func_00340EF8(int a0, int a1, short *a2, char *a3, char *t0, char *t1, char *t2, int *t3, int *s50, int *s58)
{
    int w0;
    int w1;
    int w2;
    int w3;
    int r, d;
    if (a1 < 0x1000) {
        *a2 = 0;
        return -1;
    }
    r = func_00340B00(a0, &w0, &w1, &w2, &w3);
    if (!r)
        return -1;
    d = r - a0;
    *a2 = d;
    if ((short)d <= 0)
        return -1;
    *t3 = w0;
    *t2 = (unsigned char)w1;
    *t0 = (unsigned char)w2;
    *s50 = w3;
    *a3 = -1;
    *t1 = (*t2 * *t0) / 8;
    *s58 = 1;
    return 0;
}

void *func_00329438(int, char *, int);
void *func_003B9998(void *, char *, int);
// FUNCTION: GAME 0x00342988
void *func_00342988(char *a, int b)
{
    int n = b - 0x1800;
    void *r = func_00329438(2, a, n);
    if (r == 0) {
        for (;;)
            ;
    }
    func_003B9998(r, a + n, 0x1800);
    return r;
}

// FUNCTION: GAME 0x0034BD98
void func_0034BD98(char *p, int i)
{
    char *b = p + 0x1310;
    char *e = b + i * 0x74;
    int **s = (int **)(e + 0x10);
    if (*(int *)e == 5) {
        int *o = s[1];
        if (o) {
            (*(void (**)(int *))(*(char **)o + 0xC))(o);
            s[1] = 0;
        }
    }
}

int func_0032A4A8(int);
int func_0032A530(int);
void func_0034CE80(char *, int, int);
// FUNCTION: GAME 0x00349DA0
void func_00349DA0(char *p)
{
    char *q = p + 0xD30;
    int h = **(int **)(p + 0x2004);
    if (*(int *)(q + 0x1F4) == *(int *)(q + 0x1F8)) {
        int a = func_0032A4A8(h);
        int b = func_0032A530(h);
        if (a > 0 && b > 0)
            func_0034CE80(p, a, b);
    }
}
