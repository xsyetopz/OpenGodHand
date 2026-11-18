// COMPILER: ee-gcc2.96
extern char D_00766CE8[];
void func_0036C080(char *);
void func_0036D6B0(char *, char *, int);
void func_00369E80(char *);
void func_0036A380(char *, int, int, int, int);
void func_0036A3A8(char *, int, int);
void func_0036C448(void);
void func_0036C518(int, void *);
int func_0036C5F8(char *);
int func_00369F20(int, int);
void func_0036C6A0(char *, int, void *);
void func_0036C170(char *);

struct G { char pad[0x54]; int n; char *p; };

// FUNCTION: GAME 0x0036C038
void func_0036C038(void)
{
    struct G *g = (struct G *)D_00766CE8;
    int n = g->n;
    char *p = g->p;
    int i;
    for (i = 0; i < n; i++) {
        *(int *)(p + 0x188) = 1;
        p += 0x440;
    }
}

// FUNCTION: GAME 0x0036C170
void func_0036C170(char *p)
{
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1C) = 0;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2C) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 3;
    *(int *)(p + 0x3C) = 1;
    *(int *)(p + 0x40) = 1;
    *(int *)(p + 0x44) = 1;
    *(int *)(p + 0x48) = 0;
    *(int *)(p + 0x4C) = 0;
    *(short *)(p + 0x50) = -1;
    *(short *)(p + 0x52) = -1;
    *(char *)(p + 0x54) = 0;
    *(char *)(p + 0x55) = -1;
    *(char *)(p + 0x56) = -1;
    *(char *)(p + 0x57) = -1;
    *(char *)(p + 0x58) = 0;
    *(char *)(p + 0x59) = 1;
    *(char *)(p + 0x5A) = 0;
    *(char *)(p + 0x5B) = 0;
    *(char *)(p + 0x5C) = 0;
    *(char *)(p + 0x5D) = -1;
    *(char *)(p + 0x5E) = -1;
    *(char *)(p + 0x5F) = -1;
    *(char *)(p + 0x60) = -1;
    *(char *)(p + 0x61) = 0;
    *(char *)(p + 0x62) = -1;
    *(char *)(p + 0x63) = -1;
    *(char *)(p + 0x64) = -1;
    *(int *)(p + 0x68) = 0;
}

// FUNCTION: GAME 0x0036C2F0
char *func_0036C2F0(char *p)
{
    int i;
    func_0036C080(p);
    *(int *)(p + 0x18C) = 0;
    func_0036D6B0(p + 0x190, D_00766CE8, 0x10);
    func_00369E80(p + 0x250);
    func_0036C170(p + 0x1D0);
    *(int *)(p + 0x384) = 0;
    *(int *)(p + 0x388) = 0;
    *(int *)(p + 0x3A8) = *(int *)(p + 0x1AC);
    *(int *)(p + 0x35C) = 0;
    *(int *)(p + 0x360) = 0;
    *(int *)(p + 0x364) = 0;
    *(int *)(p + 0x368) = 0;
    *(int *)(p + 0x398) = 0;
    for (i = 0; i < 4; i++)
        func_0036A380(p, i, 0, 0, 0);
    func_0036A3A8(p, 0, 0);
    *(int *)(p + 0x408) = 0;
    *(int *)(p + 0x188) = 2;
    return p;
}

// FUNCTION: GAME 0x0036C450
int func_0036C450(char *p, int idx, void *cb)
{
    int *base;
    if (idx == 8 && cb == 0)
        cb = (void *)func_0036C448;
    if (p == 0) {
        func_0036C518(idx, cb);
        base = (int *)D_00766CE8;
    } else {
        if (func_0036C5F8(p))
            return func_00369F20(0, 0xFF030202);
        base = (int *)(p + 0x190);
    }
    base[idx] = (int)cb;
    func_0036C6A0(p, idx, cb);
    return 0;
}

// FUNCTION: GAME 0x0036D320
void func_0036D320(char *p)
{
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1C) = 0;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2C) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 3;
    *(int *)(p + 0x3C) = 1;
    *(int *)(p + 0x40) = 0;
    *(int *)(p + 0x44) = 1;
    *(int *)(p + 0x48) = 0;
    *(int *)(p + 0x4C) = 0;
    *(short *)(p + 0x50) = -1;
    *(short *)(p + 0x52) = -1;
    *(char *)(p + 0x54) = 0;
    *(char *)(p + 0x55) = 1;
    *(char *)(p + 0x56) = 0;
    *(char *)(p + 0x57) = 0;
    *(char *)(p + 0x58) = 0;
    *(char *)(p + 0x59) = 1;
    *(char *)(p + 0x5A) = 0;
    *(char *)(p + 0x5B) = 0;
    *(char *)(p + 0x5C) = 0;
    *(char *)(p + 0x5D) = -1;
    *(char *)(p + 0x5E) = 0;
    *(char *)(p + 0x5F) = -1;
    *(char *)(p + 0x60) = -1;
    *(char *)(p + 0x61) = 0;
    *(char *)(p + 0x62) = -1;
    *(char *)(p + 0x63) = -1;
    *(char *)(p + 0x64) = -1;
    *(int *)(p + 0x68) = 0;
}

// FUNCTION: GAME 0x00366B80
void func_00366B80(char *a, char v, unsigned n)
{
    unsigned r = n & 15;
    a += n;
    if (r) {
        do {
            *--a = v;
        } while (--r);
    }
    n >>= 4;
    if (n) {
        do {
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        } while (--n);
    }
}

// FUNCTION: GAME 0x00366C50
void func_00366C50(int *a, int v, unsigned n)
{
    unsigned r = n & 15;
    a += n;
    if (r) {
        do {
            *--a = v;
        } while (--r);
    }
    n >>= 4;
    if (n) {
        do {
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        *--a = v;
        } while (--n);
    }
}

// FUNCTION: GAME 0x00368A28
int func_00368A28(unsigned char *p)
{
    int c;
    if (p[0] == 0 && p[1] == 0 && p[2] == 1) {
        c = p[3];
        switch (c) {
        case 0xB9: return 0x80000;
        case 0xBA: return 0x10000;
        case 0xBB: return 0x20000;
        default:
            if ((unsigned)c >= 0xBC) return 0x40000;
        }
    }
    return 0;
}

void func_003670E8(char *, char *, int *);
void func_00367550(char *, char *, int *);
void func_00367DC0(char *, char *, int *, int);

// FUNCTION: GAME 0x00366FE0
int func_00366FE0(char *s, char *a, int *b, int *c, int *d)
{
    int r = 0;
    int k;
    *c = 0;
    k = func_00368A28((unsigned char *)a);
    *d = k;
    switch (k) {
    case 0x10000:
        func_003670E8(s, a, c);
        r = 1;
        break;
    case 0x20000:
        func_00367550(s, a, c);
        r = 1;
        break;
    case 0x40000:
        func_00367DC0(s, a, c, *(int *)(s + 0x10));
        if (*(void **)(s + 0xF4))
            ((void (*)(int, int, long))*(void **)(s + 0xF4))(*(int *)(s + 0xF8), *(unsigned char *)(s + 0xB8), *(long *)(s + 0xA8));
        break;
    }
    return r;
}

void func_0036DD18(char *);
struct B { char b[0x40]; };
extern struct B D_0076A590;

// FUNCTION: GAME 0x0036D460
char *func_0036D460(char *p)
{
    *(struct B *)(p + 0x18) = D_0076A590;
    func_0036DD18(p);
    func_0036D320(p + 0x58);
    *(int *)(p + 0x118) = 0;
    *(int *)p = 2;
    return p;
}
