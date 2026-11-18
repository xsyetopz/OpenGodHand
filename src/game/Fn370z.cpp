// Small functions in the ProDG game-code island 0x370000-0x387500.
struct B8 {
    char c[8];
};
extern short deciBelTbl[];
extern B8 D_0045B170;
extern char D_00773318[];
extern "C" void *memset(void *, int, unsigned);
extern "C" {
int func_00380AE8(char *, char *, char *);
void func_0032B188(int, int);
void func_0032A9F0(int, int);
void func_0032A6D0(int, int, int);
void func_0032B300(int, int);
void func_0032BDC0(int, int, int);
}

// FUNCTION: GAME 0x3807E0
extern "C" int func_003807E0(int unused, short x)
{
    short j = 0;
    do {
        unsigned short v = deciBelTbl[j];
        if (x == deciBelTbl[j])
            return j;
        if (x < deciBelTbl[j]) {
            short m = v - (short)((short)(v - deciBelTbl[j - 1]) >> 1);
            if (x < m)
                return (short)(j - 1);
            return j;
        }
        j++;
    } while (j < 0x80);
    return -1;
}

// FUNCTION: GAME 0x378540
extern "C" void func_00378540(void) {
    char *p = D_00773318;
    int i;
    memset(p, 0, 0x8B5C);
    p[4] = 1;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    *(B8 *)(p + 0x1B2) = D_0045B170;
    *(B8 *)(p + 0x2B2) = D_0045B170;
    *(B8 *)(p + 0x3B2) = D_0045B170;
    *(short *)(p + 0x12) = 4;
    *(short *)(p + 0x10) = 0x30;
    *(short *)(p + 0x14) = 0x30;
    for (i = 0x1F; i >= 0; i--) {
        p[0x5C + (0x1F - i)] = 4;
        p[0x7C + (0x1F - i)] = 4;
    }
}

// FUNCTION: GAME 0x384EC8
extern "C" int func_00384EC8(char *a, char *s) {
    char *d = s + 0x14;
    char *e = s + 0x4C;
    int r = func_00380AE8(a, d, s);
    if (r) {
        s[1] = r;
        return 1;
    }
    func_0032B188(*(int *)(d + 0x30), 1);
    *(int *)(s + 0x14) = *(int *)(s + 0x4C);
    *(int *)(d + 4) = *(int *)(e + 4);
    *(int *)(d + 8) = *(int *)(e + 8);
    *(int *)(d + 0xC) = *(int *)(e + 0xC);
    func_0032A9F0(*(int *)(d + 0x30), *(short *)(s + 4));
    func_0032A6D0(*(int *)(d + 0x30), 0, *(short *)(s + 8));
    func_0032A6D0(*(int *)(d + 0x30), 1, *(short *)(s + 0xA));
    s[0] = 0;
    func_0032B300(*(int *)(d + 0x30), 0);
    func_0032BDC0(*(int *)(d + 0x30), *(int *)(s + 0x84), *(unsigned char *)(a + 7));
    return 0;
}

struct Q382 {
    int q0, q4, n;
    char pad[0x0C];
    unsigned char b[8];
    int m20;
};
struct P382 {
    int p0;
    short s[22];
    Q382 q;
};
extern "C" {
int func_00382850(int, Q382 *);
void func_0032EC78(int, int, int);
}

// FUNCTION: GAME 0x3821D8
extern "C" void func_003821D8(int a, P382 *p)
{
    Q382 *q = &p->q;
    if (func_00382850(a, q)) {
        for (int i = 0; i < q->n; i++) {
            if (q->b[i + 1])
                func_0032EC78(q->m20, i, -0x3C0);
            else
                func_0032EC78(q->m20, i, p->s[i + 1]);
        }
    } else {
        for (int i = 0; i < q->n; i++)
            func_0032EC78(q->m20, i, p->s[i + 1]);
    }
}

struct T376 { char pad[0x1C]; char *base; };
struct S376 {
    int w0, w4, w8, wC;
    unsigned short h10, h12, h14;
    unsigned char b16, b17, b18, b19;
    unsigned short h1A, h1C, h1E, h20, h22, h24, h26, h28, h2A, h2C, h2E, h30, h32, h34;
};
struct D376 {
    short h0;
    short h2;
    int w4;
    short h8, hA, hC;
    unsigned char bE, bF, b10, b11;
    short h12, h14, h16, h18, h1A, h1C, h1E, h20, h22, h24, h26, h28, h2A;
    int w2C, w30, w34, w38;
    unsigned char b3C, b3D;
};
extern T376 D_0076EA50[];
extern "C" {
D376 *func_00376A10(unsigned short *);
short func_003780B0(short, short);
void func_003761D0(D376 *);

// FUNCTION: GAME 0x376080
int func_00376080(S376 *s) {
    D376 *d = func_00376A10(&s->h10);
    if (d == 0)
        return -1;
    {
        d->h0 = 1;
        d->w4 = s->w4;
        d->h8 = s->h10;
        d->hA = s->h12;
        d->hC = s->h14;
        d->bE = s->b16;
        d->bF = s->b17;
        d->b10 = s->b18;
        d->h12 = 0;
        d->h14 = s->h1C;
        d->h16 = s->h1E;
        unsigned short a = s->h20;
        d->h1A = 0;
        d->h18 = a;
        d->h1C = 0;
        d->h1E = 0;
        unsigned short b = s->h28;
        d->h20 = b;
        d->h22 = s->h2A;
        d->h24 = func_003780B0(b, a);
        d->h26 = func_003780B0(d->h22, d->h18);
        d->h28 = s->h2C;
        d->h2A = s->h34;
        char *base = D_0076EA50[d->h8].base;
        char *p = base + ((int *)base)[d->hC];
        d->w2C = (int)p;
        d->w30 = (int)p;
        d->w34 = (int)p;
        d->w38 = *(int *)p;
        d->b3C = p[4];
        d->b3D = p[5];
        func_003761D0(d);
        return 0;
    }
}
}

struct A3777 { unsigned short h0; int w4; char pad[0x10]; int w18[8]; char pad2[0xA0 - 0x38]; };
struct B3777 { unsigned short h0; int w4; char pad[0x100 - 8]; };
extern A3777 D_0076E910[2];
extern B3777 D_0076B340[2];
// FUNCTION: GAME 0x3777C0
extern "C" void func_003777C0(void) {
    for (int i = 0; i < 2; i++) {
        A3777 *a = &D_0076E910[i];
        B3777 *b = &D_0076B340[i];
        unsigned a0 = a->h0;
        if (a0 == 0 || a->w4 != b->w4)
            continue;
        if (b->h0 & 0x8000) {
            if (!(a0 & 0x8000))
                a->h0 = a0 | 0x8000;
            continue;
        }
        if (a0 & 0x8000)
            a->h0 = a0 & 0x7FFF;
        if (b->h0 & 8) {
            if (!(a->h0 & 8))
                a->h0 |= 8;
        }
        a0 = b->h0;
        if (a0 & 0x200) {
            a->h0 = 0;
            a->w4 = 0;
            for (int j = 7; j >= 0; j--)
                a->w18[j] = 0;
            continue;
        }
        unsigned v1 = a->h0;
        if (!(v1 & 2)) {
            if (a0 & 2)
                a->h0 = v1 | 2;
        }
    }
}

struct W37D { char pad[0xC]; int wC; };
struct P37D { unsigned short h0; char pad[3]; unsigned char b5; char pad2[2]; W37D *w8; int wC; char pad3[0x20]; short h30, h32, h34, h36; };
extern "C" {
void func_0037D820(...);
void func_0037D148(P37D *);
void func_0037D3B0(P37D *);
void func_00378020(short *);
// FUNCTION: GAME 0x37D8B8
void func_0037D8B8(P37D *p, short x) {
    if (p->wC == 0) {
        if (p->b5 & 8) {
            func_0037D820();
            return;
        }
        if (p->h0 & 2) {
            if (p->w8 && p->w8->wC == 0) {
                func_0037D148(p);
                func_0037D3B0(p);
                return;
            }
        } else
            func_0037D820(p);
    }
    if (x == 0) {
        p->h0 |= 0x20;
        func_0037D820(p);
    } else if (x == -1) {
        func_0037D820(p);
    } else if (p->h30) {
        p->h36 = x;
        p->h32 = 0;
        func_00378020(&p->h30);
        p->h0 |= 0x40;
    }
}
}
