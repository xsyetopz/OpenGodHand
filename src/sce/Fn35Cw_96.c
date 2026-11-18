// COMPILER: ee-gcc2.96
typedef struct { char c[0x20]; } S35C;
extern void *memset();
extern int func_0035D800(), func_0035C200(), func_0035C140();

// FUNCTION: GAME 0x0035C080
void func_0035C080(int a, int *b)
{
    func_0035C200(a, 2, 3);
    func_0035C140(a, 3, 4);
    if (b[5]) {
        func_0035C200(a, 4, 5);
        func_0035C140(a, 5, 6);
        func_0035C200(a, 6, 7);
    } else {
        func_0035C200(a, 4, 7);
    }
}

// FUNCTION: GAME 0x0035DAA0
int func_0035DAA0(int *a, char *b)
{
    char *p;
    *b = 0;
    p = (char *)a[1] + 0x60;
    if (func_0035D800(a)) {
        memset(b, 0, 0x21);
        *(S35C *)b = *(S35C *)p;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x0035DDB0
char *func_0035DDB0(char *s, int *out)
{
    int v = 0;
    int c = *s;
    while (c != '.' && c != ' ' && c != 0 && (unsigned)(c - '0') < 10) {
        v = v * 10 + c - '0';
        s++;
        c = *s;
    }
    *out = v;
    return s;
}

typedef struct { char c[0x80]; } S80;
extern int func_0036D688(), func_0036D8E8(), func_0036C5F8(), func_00369F20();

// FUNCTION: GAME 0x36DA80
void func_0036DA80(char *a, char *b)
{
    if (func_0036D688()) {
        func_0036D8E8(0, 0xFF03020C);
        return;
    }
    *(S80 *)b = *(S80 *)(a + 0x58);
}

// FUNCTION: GAME 0x36A0D0
int func_0036A0D0(char *a, char *b)
{
    if (func_0036C5F8()) {
        return func_00369F20(0, 0xFF03020C);
    }
    *(S80 *)b = *(S80 *)(a + 0x1D0);
    return 0;
}

extern char D_0045A3C0[], D_0045A3C8[];
extern int strncmp(), atoi(), func_003691D8();

// FUNCTION: GAME 0x36BA50
int func_0036BA50(char *o, char *b, int n)
{
    int i = 0;
    int e = n - 4;
    char *p;
    b += 4;
    if (e > 0) {
        do {
            p = b + i;
            i++;
            if (strncmp(p, D_0045A3C0, 7) == 0)
                *(int *)(o + 0x398) = atoi(p + 0x10) ? 3 : 0;
            if (strncmp(p, D_0045A3C8, 7) == 0) {
                *(int *)(o + 0x360) = atoi(p + 0x10);
                *(int *)(o + 0x364) = atoi(p + 0x18);
                *(int *)(o + 0x368) = atoi(p + 0x20);
            }
            if (func_003691D8(p)) break;
        } while (i < e);
    }
    {
        int v = *(int *)(o + 0x360);
        int r = (v != 8) ? 0 : -1;
        if (v == 9) r = -1;
        return r;
    }
}

extern char D_0045A068[], D_0045A078[], D_0045A080[], D_0045A088[], D_0045A090[];
extern int func_00360200(), func_003A6CE0();
extern long func_0031DE10();

// FUNCTION: GAME 0x3600E8
void func_003600E8(char *a, int b, int *o1, int *o2)
{
    char *x, *t;
    int z;
    long l, p, q, r;
    func_00360200(a, D_0045A078, D_0045A068, &x, &z);
    if (x == 0) {
        *o1 = 0;
        *o2 = 0x7FFFFFFF;
        return;
    }
    func_003A6CE0(x, D_0045A080, &l);
    func_00360200(a, D_0045A088, D_0045A068, &x, &z);
    t = x;
    if (t == 0) {
        *o1 = 0x7FFFFFFF;
        return;
    }
    func_003A6CE0(t + (int)func_0031DE10(l, b), D_0045A090, &p, &q, &r);
    *o1 = q;
    *o2 = r;
}
