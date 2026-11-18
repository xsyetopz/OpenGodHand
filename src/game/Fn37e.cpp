// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

// FUNCTION: GAME 0x377378
struct Fn37E2 { char _0[0x22]; struct { unsigned short h0; short _2; unsigned short h4; short _6; } e[4]; };
struct Fn37E1 { unsigned short h0; char _2[0x36]; struct { char _0[2]; unsigned short h2; short _4; unsigned short h6; } e[4]; int w58; };
extern "C" void func_00378020(void *);
extern "C" void func_00377378(Fn37E1 *a, Fn37E2 *b)
{
    int i;
    int m = 1;
    unsigned short *src = &b->e[0].h4;
    void *ent = &a->e[0];
    unsigned short *dst = &a->e[0].h6;
    a->w58 = *(int *)((char *)b + 0x40);
    for (i = 3; i >= 0; i--) {
        if (a->w58 & m) {
            dst[-2] = src[-2] << 8;
            *dst = *src;
            func_00378020(ent);
        }
        m <<= 1;
        ent = (char *)ent + 8;
        dst += 4;
        src += 4;
    }
    a->h0 |= 0x10;
}

extern "C" void func_002E0DE8(int, int, int, const char *);
extern "C" unsigned func_00375EF8(int);
struct Fn37G { char _0[0xC]; int w0c; };

struct Fn37J3 { int w0; };
struct Fn37J1 { int w0; int w4; int w8; int wc; char _10[0x20]; int w30; };
struct Fn37J2 { char _0[0x10]; int w10; char _14[0x70]; Fn37J3 *p84; };
struct Fn37J0 { char _0[2]; char b2; };
extern "C" {
int func_00329F98(int);
int func_0032A4A8(int);
int func_0032A530(int);
int func_0032A5B8(int);
int func_0032A648(int);
void func_00380EB0(Fn37J0 *, Fn37J1 *, Fn37J2 *);
int func_00380870(int);
}
// FUNCTION: GAME 0x37FF98
extern "C" void func_0037FF98(Fn37J0 *a)
{
    Fn37J1 *s0 = (Fn37J1 *)((char *)a + 0x4BC);
    Fn37J2 *s2 = (Fn37J2 *)((char *)a + 0x470);
    if (func_00329F98(s0->w30) >= 2) {
        s0->w0 = func_0032A4A8(s0->w30);
        s0->w4 = func_0032A530(s0->w30);
        s0->w8 = func_0032A5B8(s0->w30);
        s0->wc = func_0032A648(s0->w30);
        func_00380EB0(a, s0, s2);
        s2->w10 = *(int *)((char *)s2->p84 + 4);
        s2->w10 = func_00380870(s2->w10);
        a->b2 = 1;
    }
}

// FUNCTION: GAME 0x373FF0
struct Fn37F { int w0; char _4[0x10]; float f14; char _18[0x14]; float f2c; char _30[4]; float f34; };
extern struct Fn37Snd { float a[3]; float b[3]; } Snd;
extern short deciBelTbl[];
extern "C" int SdeSystemOutModeGet(void);
extern "C" void func_0032A9F0(int, int);
extern "C" void func_00373FF0(Fn37F *s, float vol, int idx)
{
    if (s->w0) {
        float v = vol * Snd.a[idx] / 127.0f;
        v = v * Snd.b[idx] / 127.0f;
        if (SdeSystemOutModeGet() == 2) v *= s->f34;
        v *= s->f2c;
        if (v >= 127.0f) v = 127.0f;
        func_0032A9F0(s->w0, deciBelTbl[(int)v]);
        s->f14 = vol;
    }
}

// FUNCTION: GAME 0x3751B8
struct Fn37Hd { char _0[0x10]; int w10; char _14[0xC]; };
extern Fn37Hd Sde_iss_hed[];
struct Fn37Sd { short h0; char _2[0xC]; unsigned short he; short h10; short h12; char _14[8]; unsigned short h1c; };
extern "C" int func_003781F8(short, Fn37Sd *, short *);
extern "C" int func_00378398(short, Fn37Sd *, short *);
extern "C" int func_003751B8(Fn37Sd *s, short a)
{
    short buf[8];
    int r;
    Fn37Hd *hd = Sde_iss_hed;
    if (hd[s->h0].w10 == 0) return 0;
    if (s->he & 1) return 0;
    r = func_003781F8(a, s, buf);
    if (r == -1) return -1;
    if (r == 0) s->h12 = s->h10 = s->h10 * buf[0] / 127;
    r = func_00378398(a, s, buf);
    if (r == -1) return -1;
    if (r == 0) s->h1c = buf[0];
    return 0;
}

// FUNCTION: GAME 0x375BF0
struct Fn37Rp { char d[0x30]; };
struct Fn37Rs { char _0[6]; unsigned char b6; char _7[7]; unsigned short he; };
struct Fn37Rd { short h0; char _2[2]; int w4; unsigned char b8; unsigned char b9; short ha; char _c[4]; Fn37Rp p; };
extern "C" Fn37Rd *func_00376978(void);
extern "C" int func_00377FF8(void);
extern "C" int func_00375BF0(Fn37Rs *s)
{
    Fn37Rd *d;
    if (s->he & 0x8000) return 0;
    d = func_00376978();
    if (!d) return 0;
    d->h0 = 1;
    d->w4 = func_00377FF8();
    d->b8 = s->b6;
    d->b9 = 4;
    d->ha = -1;
    d->p = *(Fn37Rp *)s;
    return d->w4;
}

// FUNCTION: GAME 0x37C4C0
struct Fn37Ke { unsigned short h0; char _2[3]; unsigned char b5; char _6[0xA]; int w10; char _14[0x3C]; };
struct Fn37Ko { char _0[4]; int w4; char _8[5]; unsigned char bd; char _e[0x1C]; unsigned short h2a; };
extern Fn37Ke D_0076CF20[];
extern "C" void func_0037C5C8(Fn37Ke *, Fn37Ko *, int);
extern "C" void func_0037C5F8(Fn37Ke *, Fn37Ko *, int);
extern "C" void func_0037C618(Fn37Ke *, Fn37Ko *, int);
extern "C" void func_0037C6A0(Fn37Ke *);
extern "C" void func_0037C4C0(Fn37Ko *o)
{
    Fn37Ke *e = D_0076CF20;
    int i;
    unsigned f;
    for (i = 0x32; i >= 0; i--, e++) {
        if (e->h0 && (e->b5 & o->bd) && e->w10 == o->w4) {
            f = o->h2a;
            if (f & 1) func_0037C5C8(e, o, 1);
            if (f & 2) func_0037C5C8(e, o, 2);
            if ((o->bd & 8) && (f & 3)) func_0037C6A0(e);
            if (f & 4) func_0037C5F8(e, o, 4);
            if (f & 8) func_0037C618(e, o, 8);
        }
    }
}

struct Fn37Q4 { int w0, w4, w8, wc; };
struct Fn37Qa { char _0[6]; unsigned char b6; };
struct Fn37Qb { char _0[1]; unsigned char b1; char _2; unsigned char b3; };
extern "C" {
void func_00323A70(int);
int func_003A92E0(Fn37Q4 *, const char *, int);
void func_0031C900(Fn37Q4 *);
int func_00381B38(Fn37Qa *, char *, Fn37Qb *);
int func_00380AE8(Fn37Qa *, char *, Fn37Qb *);
void func_0032DA28(int, int, int);
void func_0032BB48(int, int, int);
}

struct Fn37Ym { char _0[4]; signed char b4; signed char b5; char _6[0x2E]; int w34; };
extern int D_003F21B8;
extern "C" {
void func_00378AA8(Fn37Ym *);
void func_00378BF8(Fn37Ym *);
void func_00378CE0(Fn37Ym *);
void func_0037B620(Fn37Ym *);
void func_0037AC68(Fn37Ym *);
void func_0037E128(int, Fn37Ym *);
void func_0037DC88(int, int);
}
