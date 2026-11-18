// COMPILER: ee-gcc2.9-991111
// SCE libstdc++ dtoa (upstream gcc-2.95 floatconv.c) and libio helpers.

#include "iostream.h"

int _IO_getc(struct SB *);

typedef struct Bigint {
    struct Bigint *next;
    int k;
    int maxwds;
    short on_stack;
    short sign;
    int wds;
    unsigned int x[1];
} Bigint;

extern Bigint *func_0038F630(Bigint *, int, int);
extern int D_003F5160[6];

// pow5mult
// FUNCTION: GAME 0x38FBF0
Bigint *func_0038FBF0(Bigint *b, int k)
{
    for (; k > 6; k -= 6)
        b = func_0038F630(b, 15625, 0);
    if (k == 0)
        return b;
    else
        return func_0038F630(b, D_003F5160[k - 1], 0);
}

// istream::get()
// FUNCTION: GAME 0x389F38
int func_00389F38(struct Is *s)
{
    int ch;
    if (!ipfx(s))
        return -1;
    ch = _IO_getc(s->ios->sb);
    if (ch == -1)
        s->ios->st |= 1;
    return ch;
}

int _skip_ws__7istream(struct Is *);

// istream::ipfx(int)
// FUNCTION: GAME 0x38A0C0
int func_0038A0C0(struct Is *s, int need)
{
    if (s->ios->st) {
        s->ios->st |= 2;
        return 0;
    }
    if (s->ios->tie && (need == 0 || s->ios->sb->m8 - s->ios->sb->m4 < need))
        func_00389268(s->ios->tie);
    if (!need && (int)(s->ios->fl & 1))
        return _skip_ws__7istream(s);
    return 1;
}

int sputbackc__9streambufc(struct SB *, char);
int sungetc__9streambuf(struct SB *);

// istream::putback(char)
// FUNCTION: GAME 0x389E30
struct Is *func_00389E30(struct Is *s, char c)
{
    if (!s->ios->st) {
        if (sputbackc__9streambufc(s->ios->sb, c) == -1)
            s->ios->st = 4;
    }
    return s;
}

// FUNCTION: GAME 0x389ED8
struct Is *func_00389ED8(struct Is *s, char c)
{
    if (!s->ios->st) {
        if (sputbackc__9streambufc(s->ios->sb, c) == -1)
            s->ios->st = 4;
    }
    return s;
}

// istream::unget()
// FUNCTION: GAME 0x389E88
struct Is *func_00389E88(struct Is *s)
{
    if (!s->ios->st && sungetc__9streambuf(s->ios->sb) == -1)
        s->ios->st = 4;
    return s;
}
