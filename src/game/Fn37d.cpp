// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn37H { unsigned short f; short h2; char _4; unsigned char b5; char _6[0xE]; int w14; char _18[0x38]; };
struct Fn37A { unsigned short f; char _2[2]; int w4; };
extern Fn37H D_0076CF20[];
extern "C" void func_0037D8B8(void *, int);
// FUNCTION: GAME 0x376AE0
extern "C" void func_00376AE0(Fn37A *a, short k)
{
    Fn37H *p = D_0076CF20;
    Fn37H *e = (Fn37H *)((char *)p + 0xF00);
    do {
        if (p->f && (p->b5 & 4) && p->w14 == a->w4) func_0037D8B8(p, k);
        p++;
    } while ((int)p < (int)e);
    a->f = 0;
    a->w4 = 0;
}
struct Fn37P { char d[0x30]; };
struct Fn37D { unsigned short h0; char _2[2]; int w4; unsigned char b8; unsigned char b9; unsigned short ha; char _c[4]; Fn37P p; };
extern "C" Fn37D *func_00376978(void);
// FUNCTION: GAME 0x375CD0
extern "C" int func_00375CD0(int a, Fn37P *src)
{
    Fn37D *d = func_00376978();
    if (!d) return -1;
    d->b8 = 0x10;
    d->w4 = a;
    d->b9 = 4;
    d->h0 = 1;
    d->ha = 1;
    d->p = *src;
    return 0;
}
struct Fn37X { unsigned short h0; unsigned short h2; int w4; int w8; unsigned char bc; unsigned char bd; unsigned short he; unsigned short h10; unsigned short h12; unsigned short h14; char _16[0x14]; unsigned short h2a; char _2c[4]; unsigned short h30; unsigned short h32; unsigned short h34; char _36[6]; unsigned short h3c; };
struct Fn37Y { unsigned short h0; unsigned short h2; int w4; char _8[4]; unsigned short hc; unsigned short he; unsigned short h10; };
extern "C" void func_003768B0(Fn37X *, Fn37Y *);
extern "C" Fn37X *func_0037D170(void);
extern "C" void func_00376CF8(Fn37X *, Fn37X *);
// FUNCTION: GAME 0x376618
extern "C" int func_00376618(Fn37X *a, Fn37Y *b)
{
    Fn37X *d;
    func_003768B0(a, (Fn37Y *)b);
    d = func_0037D170();
    if (!d) return 0;
    {
        d->h0 = 1;
        d->w4 = b->w4;
        d->w8 = a->w4;
        d->bc = 0x10;
        d->bd = 4;
        d->he = 1;
        d->h10 = 0;
        d->h12 = a->h2;
        d->h14 = b->h2;
        func_00376CF8(a, d);
        d->h2a = 0xD;
        d->h30 = b->hc;
        d->h32 = b->hc;
        d->h34 = b->he;
        d->h3c = b->h10;
    }
    return 0;
}
struct Fn37Z { char _0[0x14]; int w14; };
struct Fn37W { char _0[5]; unsigned char b5; char _6[0x1E]; unsigned short h24; char _26[6]; unsigned short h2c; char _2e[0x12]; unsigned short h40; unsigned short h42; unsigned short h44; };
extern Fn37Z D_0076A790;
// FUNCTION: GAME 0x37D680
extern "C" void func_0037D680(Fn37W *s)
{
    if (D_0076A790.w14 == 0) {
        s->h44 = 0x40;
        return;
    }
    switch (s->b5) {
    case 1:
    case 9:
        if (D_0076A790.w14 == 1) s->h44 = s->h40;
        else s->h44 = s->h42;
        break;
    case 4:
        if (s->h24 & 2) {
            s->h44 = s->h40;
            break;
        }
    case 2:
        s->h44 = s->h2c;
        break;
    }
}
struct Fn37Q { char _0[0xC]; int w0c; };
extern char D_0045BD90[], D_0045BDA0[], D_0045BDA8[], D_0045BDB8[];
extern "C" void func_002E0DE8(int, int, int, const char *);
extern "C" int func_003750E0(int);
// FUNCTION: GAME 0x37B338
extern "C" void func_0037B338(Fn37Q *s)
{
    int r;
    func_002E0DE8(3, 4, 8, D_0045BD90);
    if (!s->w0c) {
        func_002E0DE8(0xC, 4, 0xF, D_0045BDA0);
        return;
    }
    r = func_003750E0(s->w0c);
    if (r == 0) {
        func_002E0DE8(0xC, 4, 0xF, D_0045BDA0);
        return;
    }
    if (r & 1) func_002E0DE8(0xC, 4, 0xD, D_0045BDA8);
    if (r & 2) func_002E0DE8(0xC, 4, 0xC, D_0045BDB8);
}

struct Fn37K { unsigned char b0; char _1[3]; char b4; };
extern "C" {
int func_0037E200(Fn37K *, Fn37K *);
int func_0037E368(Fn37K *, Fn37K *);
int func_003808A0(Fn37K *, Fn37K *);
int func_00381940(Fn37K *, Fn37K *);
int func_00382D30(Fn37K *, Fn37K *);
int func_00384CA0(Fn37K *, Fn37K *);
}
struct Fn37L { char _0[7]; signed char c7; char _8[0xE]; short h16[3]; short h1c[3]; char _22[0x12]; int w34; };
extern "C" int func_0037A0F0(Fn37L *, short, int);
// FUNCTION: GAME 0x37A020
extern "C" int func_0037A020(Fn37L *s)
{
    short cur = s->h16[s->c7];
    int v = cur;
    if (s->w34 & 0x20000000) v = func_0037A0F0(s, cur - 1, -1);
    if (s->w34 & 0x10000000) v = func_0037A0F0(s, cur + 1, 1);
    if (v != cur) {
        s->h16[s->c7] = v;
        s->h1c[s->c7] = 0;
        return 1;
    }
    return 0;
}
struct Fn37M { char _0[7]; signed char c7; };
struct Fn37N { void *p; char _4[4]; signed char b8; };
extern "C" {
int func_0037A8F8(Fn37M *, Fn37N *, int);

void func_0037A9C8(Fn37M *, Fn37N *);
void func_0037AAB0(Fn37M *, Fn37N *);
void func_0037AB00(Fn37M *, Fn37N *);
}
// FUNCTION: GAME 0x37A818
extern "C" void func_0037A818(Fn37M *a, Fn37N *b)
{
    if (b->b8 == 0) *(signed char *)b->p = func_0037A8F8(a, b, *(signed char *)b->p);
    if (b->b8 == 1) *(short *)b->p = func_0037A8F8(a, b, *(short *)b->p);
    switch (a->c7) {
    case 0: func_0037A9C8(a, b); break;
    case 1: func_0037AAB0(a, b); break;
    case 2: func_0037AB00(a, b); break;
    }
}
struct Fn37O { char _0[6]; signed char c6; signed char c7; char _8[6]; unsigned short he; char _10[8]; short h18; short h1a; char _1c[2]; signed char c1e; };
struct Fn37V { char _0[0x25]; signed char c25; char _26[0x76]; Fn37O e; };
struct Fn37R { char _0[0x18]; short h18; short h1a; };
extern "C" int func_00377FA0(void);
// FUNCTION: GAME 0x37D760
extern "C" short func_0037D760(Fn37R *s)
{
    short d;
    short lo = s->h18;
    short hi = s->h1a;
    short r;
    if (lo == hi) return lo;
    d = hi - lo;
    if (d < 0x11) r = func_00377FA0() % (d + 1);
    else r = (unsigned)func_00377FA0() % 0x11 * (d / 16);
    return r + lo;
}
