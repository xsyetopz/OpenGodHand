// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn37S {
    char _0[5];
    signed char c5;
    signed char c6;
    signed char c7;
    char _8[0x1D];
    signed char c25;
    char _26[6];
    int w2c;
    char _30[4];
    int w34;
    int w38;
};
extern signed char D_003F2620[];

extern "C" {
int func_00378B58(Fn37S *);
int func_00379EC0(Fn37S *);
void func_0037A1F0(Fn37S *);
int func_0037A4C8(Fn37S *);
int func_0037A6A8(Fn37S *);
int func_0037A740(Fn37S *);
void func_0037A298(Fn37S *);
int func_0037A0F0(Fn37S *, int, int);
int func_00387430(int);
void *func_00386FA0(int, void *);
void func_003870E0(int);
}

// FUNCTION: GAME 0x378AE0
extern "C" void func_00378AE0(Fn37S *a)
{
    if (func_00378B58(a)) return;
    if (func_00379EC0(a)) return;
    func_0037A1F0(a);
    if (!func_0037A4C8(a) && !func_0037A6A8(a)) func_0037A740(a);
    func_0037A298(a);
}

struct Fn37Q { char _0[7]; signed char c7; char _8[0x38]; int w40; };
struct Fn37R { char _0[0xC]; void *w0c; char _10[0xBC]; Fn37Q q; };

// FUNCTION: GAME 0x37A5F0
extern "C" void func_0037A5F0(Fn37R *a)
{
    Fn37Q *s = &a->q;
    if (func_00387430(0)) return;
    if (s->w40 == 2 && s->c7 == 0x2F) return;
    a->w0c = func_00386FA0(0, s);
    if (a->w0c) func_003870E0(0);
}

// FUNCTION: GAME 0x378B58
extern "C" int func_00378B58(Fn37S *s)
{
    signed char o5, o7;
    if (!(s->w34 & 0xF000000)) return 0;
    o5 = s->c5;
    o7 = s->c7;
    if (o5 == 0) {
        s->c5 = 2;
        s->c7 = 2;
    } else {
        s->c5 = 0;
        s->c7 = 0;
    }
    if (func_0037A0F0(s, *(short *)((char *)s + (s->c7 << 1) + 0x16), 1) < 0) {
        s->c5 = o5;
        s->c7 = o7;
        return 0;
    }
    return 1;
}

// FUNCTION: GAME 0x378C48
extern "C" void func_00378C48(Fn37S *s)
{
    int r;
    if (func_00379EC0(s)) return;
    if (s->w34 & 4) {
        *(unsigned char *)&s->c6 ^= 1;
        return;
    }
    func_0037A1F0(s);
    r = func_0037A4C8(s);
    if (!s->c6 && !r && !func_0037A6A8(s)) func_0037A740(s);
    func_0037A298(s);
}

// FUNCTION: GAME 0x37A6A8
extern "C" int func_0037A6A8(Fn37S *s)
{
    signed char lim = D_003F2620[s->c7];
    unsigned char o = s->c25;
    signed char old = s->c25;
    if (s->w2c & 0x80) return 0;
    if (s->w38 & 0x1000) s->c25 = o - 1;
    if (s->w38 & 0x4000) s->c25 = (unsigned char)s->c25 + 1;
    if (s->c25 < 0) s->c25 = lim - 1;
    if (!(s->c25 < lim)) s->c25 = 0;
    return s->c25 != old;
}

struct Fn37E { unsigned short f; char _2[2]; int w4; char _8[0xD8]; };
struct Fn37H { unsigned short f; short h2; char _4; unsigned char b5; unsigned short h6; int w8; char _c[4]; int w10; char _14[0x3C]; };
struct Fn37A { char _0[4]; int w4; char _8[5]; unsigned char b0d; char _e[2]; short h10; };
struct Fn37B { char _0[0x84]; };
struct Fn37I { char _0[0xC]; int w0c; char _10[0x15]; signed char c25; };
struct Fn37J { char _0[0xA]; short ha; char _c[2]; unsigned short he; char _10[0x16]; signed char c26; };
extern Fn37E D_00770850[48];
extern Fn37H D_0076CF20[];
extern Fn37H D_0076C8C0[];
extern Fn37B D_0076A600[];
extern "C" {
int func_00375E78(int, int, int);
void func_0037D8B8(void *, int);
void func_00373430(void *);
void func_003733C8(void *);
void func_0037D148(Fn37H *);
void func_0037D3B0(Fn37H *);
int func_00375EF8(int);
void func_00375CD0(int, void *);
}

// FUNCTION: GAME 0x375DE0
extern "C" int func_00375DE0(short a, short b)
{
    Fn37E *p = D_00770850;
    Fn37E *e = p + 48;
    do {
        if (p->f && func_00375E78(p->w4, a, b) == -1) return -1;
        p++;
    } while ((int)p < (int)e);
    return 0;
}

// FUNCTION: GAME 0x37C388
extern "C" void func_0037C388(Fn37A *a)
{
    Fn37H *p = D_0076CF20;
    Fn37H *e = (Fn37H *)((char *)p + 0xFF0);
    do {
        if (p->f && (p->b5 & a->b0d)) {
            if (a->w4 == 0 || p->w10 == a->w4) {
                func_0037D8B8(p, a->h10);
                if (a->w4) break;
            }
        }
        p++;
    } while ((int)p < (int)e);
}

// FUNCTION: GAME 0x37C420
extern "C" void func_0037C420(Fn37A *a)
{
    Fn37H *p = D_0076C8C0;
    int i = 0;
    do {
        if (p->f && (p->b5 & a->b0d)) {
            if (a->w4 == 0 || p->w10 == a->w4) {
                func_0037D8B8((void *)p->w8, a->h10);
                if (a->w4) break;
            }
        }
        i++;
        p = (Fn37H *)((char *)p + 0x20);
    } while (i < 51);
}

// FUNCTION: GAME 0x37D820
extern "C" void func_0037D820(Fn37H *s)
{
    if (s->b5 & 8) {
        func_00373430(&D_0076A600[s->h2]);
        func_003733C8(&D_0076A600[s->h2]);
        func_0037D148(s);
        func_0037D3B0(s);
    } else {
        func_0037D148(s);
        s->w8 = 0;
        s->f |= 0x10;
    }
}

// FUNCTION: GAME 0x37D9B0
extern "C" void func_0037D9B0(unsigned a, unsigned b)
{
    Fn37H *p = D_0076CF20;
    Fn37H *e = (Fn37H *)((char *)p + 0xFF0);
    unsigned char m = a;
    unsigned short k = b;
    do {
        if (p->f && (p->b5 & m)) {
            switch (k) {
            case 1: p->h6 |= 9; break;
            case 2: p->h6 |= 0xA; break;
            }
        }
        p++;
    } while ((int)p < (int)e);
}

// FUNCTION: GAME 0x37AB00
extern "C" void func_0037AB00(Fn37I *s)
{
    Fn37J *t = (Fn37J *)((char *)s + 0x12C);
    switch (s->c25) {
    case 3:
        if (s->w0c) {
            if (func_00375EF8(s->w0c)) {
                t->ha = 1;
                func_00375CD0(s->w0c, t);
            }
        }
        break;
    case 10:
        if (t->c26 == -1) t->he |= 1;
        else t->he &= 0xFFFE;
        break;
    }
}

#ifdef NONMATCHING
struct Fn37V { float a, b; };
extern Fn37V D_0045A610[];

// DRAFT: GAME 0x3780F8
// diff: 2 words, lwc1/addu order in the even-quadrant branch
extern "C" void func_003780F8(unsigned short ang, float *s, float *c)
{
    unsigned short r = ang % 360;
    if ((ang / 360) & 1) {
        int i = 360 - r;
        float x = D_0045A610[i].a;
        float y = D_0045A610[i].b;
        *s = x;
        *c = -y;
    } else {
        float y = D_0045A610[r].b;
        float x = D_0045A610[r].a;
        *s = x;
        *c = y;
    }
}
#endif
