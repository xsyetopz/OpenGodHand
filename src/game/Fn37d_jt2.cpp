// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn37H { unsigned short f; short h2; char _4; unsigned char b5; char _6[0xE]; int w14; char _18[0x38]; };
struct Fn37A { unsigned short f; char _2[2]; int w4; };
extern Fn37H D_0076CF20[];
extern "C" void func_0037D8B8(void *, int);
struct Fn37P { char d[0x30]; };
struct Fn37D { unsigned short h0; char _2[2]; int w4; unsigned char b8; unsigned char b9; unsigned short ha; char _c[4]; Fn37P p; };
extern "C" Fn37D *func_00376978(void);
struct Fn37X { unsigned short h0; unsigned short h2; int w4; int w8; unsigned char bc; unsigned char bd; unsigned short he; unsigned short h10; unsigned short h12; unsigned short h14; char _16[0x14]; unsigned short h2a; char _2c[4]; unsigned short h30; unsigned short h32; unsigned short h34; char _36[6]; unsigned short h3c; };
struct Fn37Y { unsigned short h0; unsigned short h2; int w4; char _8[4]; unsigned short hc; unsigned short he; unsigned short h10; };
extern "C" void func_003768B0(Fn37X *, Fn37Y *);
extern "C" Fn37X *func_0037D170(void);
extern "C" void func_00376CF8(Fn37X *, Fn37X *);
struct Fn37Z { char _0[0x14]; int w14; };
struct Fn37W { char _0[5]; unsigned char b5; char _6[0x1E]; unsigned short h24; char _26[6]; unsigned short h2c; char _2e[0x12]; unsigned short h40; unsigned short h42; unsigned short h44; };
extern Fn37Z D_0076A790;
struct Fn37Q { char _0[0xC]; int w0c; };
extern char D_0045BD90[], D_0045BDA0[], D_0045BDA8[], D_0045BDB8[];
extern "C" void func_002E0DE8(int, int, int, const char *);
extern "C" int func_003750E0(int);

struct Fn37K { unsigned char b0; char _1[3]; char b4; };
extern "C" {
int func_0037E200(Fn37K *, Fn37K *);
int func_0037E368(Fn37K *, Fn37K *);
int func_003808A0(Fn37K *, Fn37K *);
int func_00381940(Fn37K *, Fn37K *);
int func_00382D30(Fn37K *, Fn37K *);
int func_00384CA0(Fn37K *, Fn37K *);
}
// FUNCTION: GAME 0x37E128
extern "C" void func_0037E128(Fn37K *a, Fn37K *b)
{
    int r = 1;
    switch (a->b0) {
    case 0: r = func_0037E200(a, b); break;
    case 1: r = func_0037E368(a, b); break;
    case 2: r = func_003808A0(a, b); break;
    case 3: r = func_00381940(a, b); break;
    case 4: r = func_00382D30(a, b); break;
    case 5: r = func_00384CA0(a, b); break;
    }
    if (!r) b->b4 = 1;
}
struct Fn37L { char _0[7]; signed char c7; char _8[0xE]; short h16[3]; short h1c[3]; char _22[0x12]; int w34; };
extern "C" int func_0037A0F0(Fn37L *, short, int);
struct Fn37M { char _0[7]; signed char c7; };
struct Fn37N { void *p; char _4[4]; signed char b8; };
extern "C" {
int func_0037A8F8(Fn37M *, Fn37N *, int);

void func_0037A9C8(Fn37M *, Fn37N *);
void func_0037AAB0(Fn37M *, Fn37N *);
void func_0037AB00(Fn37M *, Fn37N *);
}
struct Fn37O { char _0[6]; signed char c6; signed char c7; char _8[6]; unsigned short he; char _10[8]; short h18; short h1a; char _1c[2]; signed char c1e; };
struct Fn37V { char _0[0x25]; signed char c25; char _26[0x76]; Fn37O e; };
