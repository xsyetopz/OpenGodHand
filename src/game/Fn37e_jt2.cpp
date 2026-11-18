// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn37E2 { char _0[0x22]; struct { unsigned short h0; short _2; unsigned short h4; short _6; } e[4]; };
struct Fn37E1 { unsigned short h0; char _2[0x36]; struct { char _0[2]; unsigned short h2; short _4; unsigned short h6; } e[4]; int w58; };
extern "C" void func_00378020(void *);

// FUNCTION: GAME 0x37B518
extern "C" void func_002E0DE8(int, int, int, const char *);
extern "C" unsigned func_00375EF8(int);
extern const char D_0045BDE8[];
struct Fn37G { char _0[0xC]; int w0c; };
extern "C" void func_0037B518(Fn37G *s)
{
    unsigned f;
    func_002E0DE8(3, 4, 8, "STATUS :");
    f = func_00375EF8(s->w0c);
    if (f == 0) {
        func_002E0DE8(0xC, 4, 0xF, "STOP");
        return;
    }
    if (f & 1) func_002E0DE8(0xC, 4, 0xD, "STAND-BY");
    if (f & 2) func_002E0DE8(0xC, 4, 0xC, "PLAY");
    if (f & 4) func_002E0DE8(0x10, 4, 0xD, D_0045BDE8);
}

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

struct Fn37F { int w0; char _4[0x10]; float f14; char _18[0x14]; float f2c; char _30[4]; float f34; };
extern struct Fn37Snd { float a[3]; float b[3]; } Snd;
extern short deciBelTbl[];
extern "C" int SdeSystemOutModeGet(void);
extern "C" void func_0032A9F0(int, int);

struct Fn37Hd { char _0[0x10]; int w10; char _14[0xC]; };
extern Fn37Hd Sde_iss_hed[];
struct Fn37Sd { short h0; char _2[0xC]; unsigned short he; short h10; short h12; char _14[8]; unsigned short h1c; };
extern "C" int func_003781F8(short, Fn37Sd *, short *);
extern "C" int func_00378398(short, Fn37Sd *, short *);

struct Fn37Rp { char d[0x30]; };
struct Fn37Rs { char _0[6]; unsigned char b6; char _7[7]; unsigned short he; };
struct Fn37Rd { short h0; char _2[2]; int w4; unsigned char b8; unsigned char b9; short ha; char _c[4]; Fn37Rp p; };
extern "C" Fn37Rd *func_00376978(void);
extern "C" int func_00377FF8(void);

struct Fn37Ke { unsigned short h0; char _2[3]; unsigned char b5; char _6[0xA]; int w10; char _14[0x3C]; };
struct Fn37Ko { char _0[4]; int w4; char _8[5]; unsigned char bd; char _e[0x1C]; unsigned short h2a; };
extern Fn37Ke D_0076CF20[];
extern "C" void func_0037C5C8(Fn37Ke *, Fn37Ko *, int);
extern "C" void func_0037C5F8(Fn37Ke *, Fn37Ko *, int);
extern "C" void func_0037C618(Fn37Ke *, Fn37Ko *, int);
extern "C" void func_0037C6A0(Fn37Ke *);

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
