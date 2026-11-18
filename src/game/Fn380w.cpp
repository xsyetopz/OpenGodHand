// Medium functions in the ProDG game-code island 0x380000-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn38A { char _0[0x20]; int w20; int w24; char _28[8]; int w30; int w34; };
extern "C" {
int printf(const char *, ...);
void func_00380E88(void);
void func_00381D38(void);
int func_0031C890(int);
void func_0031C900(int);
int func_00329438(int, int, int);
int func_0032D340(int, int, int, int);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x387430
// diff: 1 word, or operand order (a1,v0 vs v0,a1)
struct Fn38S { unsigned short h0; char _2[0x9E]; };
extern Fn38S D_0076E910[];
extern "C" int func_003779D0(short);

extern "C" int func_00387430(short a)
{
    unsigned h, v;
    if (func_003779D0(a)) return 1;
    h = D_0076E910[a].h0;
    if (h) {
        v = (h & 2) ? 6 : 2;
        if (h & 4) v |= 8;
        v = (h & 0x10) | v;
        if (h & 0x8000) v |= 0x20;
        return v;
    }
    return 0;
}
#endif
