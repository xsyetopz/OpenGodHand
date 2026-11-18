// Entry initialisers at 0x387160 and 0x387328.
struct Fn38Slot { short a, b, c, d; };
struct Fn38E { unsigned short m0; char _2[2]; int m4; unsigned char m8, m9; unsigned short mA; short mC; char _e[0x12]; Fn38Slot s[4]; int m40; };
struct Blk60 { char d[0x60]; };
extern "C" Fn38E *func_00377998(int);

// FUNCTION: GAME 0x387160
extern "C" int func_00387160(int id, char *src)
{
    short s = id;
    Fn38E *e = func_00377998(id << 16);
    if (e == 0) return -1;
    e->m8 = 0x10;
    e->m9 = 2;
    e->m0 = 1;
    e->mA = 1;
    e->mC = s;
    e->m4 = 0;
    *(Blk60 *)((char *)e + 0x10) = *(Blk60 *)src;
    return 0;
}

#ifdef NONMATCHING
typedef Fn38E *(*Fn38Alloc3)(int, int, int);
// DRAFT: GAME 0x387328
// 11 differing words: s0/s1 swapped (mask vs z) and a0/a1 swapped (bit vs i); tried decl order, int copies, do-while, <<= variants.
extern "C" int func_00387328(int x, int y, int z, int mask)
{
    short sz = z;
    short sx = x;
    short sy = y;
    Fn38E *e = ((Fn38Alloc3)func_00377998)(x << 16, y << 16, z << 16);
    if (e == 0) return -1;
    e->m0 = 1;
    e->m8 = 0x10;
    e->m9 = 2;
    e->mC = sx;
    e->m4 = 0;
    e->mA = 0;
    if ((unsigned short)(sz + 1) < 2) {
        for (unsigned i = 0; i < 4; i++) {
            e->s[i].b = 0;
            e->s[i].d = 1;
        }
        e->m40 = 0xF;
        return 0;
    }
    unsigned bit = 1;
    for (unsigned i = 0; i < 4; i++) {
        if (mask & bit) {
            e->s[i].b = sy;
            e->s[i].d = sz;
        }
        bit <<= 1;
    }
    e->m40 = mask;
    return 0;
}
#endif
