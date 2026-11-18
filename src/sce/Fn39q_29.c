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

#ifdef NONMATCHING
// istream::putback(char)
// DRAFT: GAME 0x389E30
// diff: 2 words, original keeps the constant 4 in $a0 (return value already in $v0)
struct Is *func_00389E30(struct Is *s, char c)
{
    if (!s->ios->st) {
        if (sputbackc__9streambufc(s->ios->sb, c) == -1)
            s->ios->st = 4;
    }
    return s;
}

// DRAFT: GAME 0x389ED8
// diff: 2 words, same as 0x389E30
struct Is *func_00389ED8(struct Is *s, char c)
{
    if (!s->ios->st) {
        if (sputbackc__9streambufc(s->ios->sb, c) == -1)
            s->ios->st = 4;
    }
    return s;
}

// istream::unget()
// DRAFT: GAME 0x389E88
// diff: 9 words, return copy placed at the tail instead of the bne delay slot; 4 forms tried
struct Is *func_00389E88(struct Is *s)
{
    if (!s->ios->st && sungetc__9streambuf(s->ios->sb) == -1)
        s->ios->st = 4;
    return s;
}
#endif

extern int D_00786708, D_00786728;
extern char D_0045D188[], D_0045D1A8[], D_0045D1B0[], D_0045D1D0[];
void func_0038A7E0(void);
void func_0038A340(void);
void func_0031EE80(void *, void *, void *, int);

// FUNCTION: GAME 0x389828
void *func_00389828(void)
{
    if (!D_00786708) {
        func_0038A7E0();
        func_0031EE80(&D_00786708, D_0045D188, D_0045D1A8, 1);
    }
    return &D_00786708;
}

// FUNCTION: GAME 0x389980
void *func_00389980(void)
{
    if (!D_00786728) {
        func_0038A340();
        func_0031EE80(&D_00786728, D_0045D1B0, D_0045D1D0, 1);
    }
    return &D_00786728;
}

struct Imp { int pad[2]; void *out; void *err; };
extern struct Imp *_impure_ptr;
int func_003A6020(void *);

// ostream::osfx()
// FUNCTION: GAME 0x389548
int func_00389548(struct Is *s)
{
    if (s->ios->fl & 0x2000)
        func_00389268((struct Ios *)s);
    if (s->ios->fl & 0x4000) {
        func_003A6020(_impure_ptr->out);
        return func_003A6020(_impure_ptr->err);
    }
}
