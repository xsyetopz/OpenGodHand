// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn374Blk { char d[0x30]; };
struct Fn374Ent {
    unsigned short h0;
    char _2[2];
    int w4;
    int w8;
    unsigned char bc;
    unsigned char bd;
    short he;
    short h10;
    short h12;
    short h14;
    short h16;
    short h18;
    short h1a;
    short h1c;
    short h1e;
    short h20;
    char _22[0x26];
    unsigned short h48;
};
extern "C" Fn374Ent *func_0037D170(void);
extern int D_00773250[];

// FUNCTION: GAME 0x374F30
extern "C" int func_00374F30(int a, Fn374Blk *b)
{
    Fn374Ent *e = func_0037D170();
    if (!e)
        return -1;
    e->h0 = 1;
    e->bd = 1;
    e->he = 1;
    e->w4 = a;
    e->bc = 0x10;
    e->h12 = -1;
    e->w8 = 0;
    e->h10 = 0;
    e->h14 = 0;
    e->h16 = 0;
    e->h18 = 0;
    e->h1a = 0;
    e->h1c = 0;
    e->h1e = 0;
    *(Fn374Blk *)((char *)e + 0x20) = *b;
    if (D_00773250[e->h20]) {
        if (e->h48 == 0xFFFF)
            return 0;
        e->bd |= 8;
    }
    return 0;
}
