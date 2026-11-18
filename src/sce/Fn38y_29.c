// COMPILER: ee-gcc2.9-991111
// SCE libstdc++ ostream/istream members in 0x3875A8-0x38F000 (opfx/ipfx sentry inlines).
#include "iostream.h"

void func_00388660(struct Is *, unsigned long, int);

// FUNCTION: GAME 0x388CA8
struct Is *func_00388CA8(struct Is *s, long v)
{
    if (opfx(s))
        func_00388660(s, v, 0);
    return s;
}

// FUNCTION: GAME 0x388C18
struct Is *func_00388C18(struct Is *s, long v)
{
    if (opfx(s)) {
        long t = v;
        int neg = 1;
        if (t < 0 && !(s->ios->fl & 0x60)) {
            t = -t;
            neg = -1;
        }
        func_00388660(s, t, neg);
    }
    return s;
}

int func_00389398(struct Is *);
void func_0038ADC8(struct Is *, void *, int);
extern char D_0045D0E8[], D_0045D0F0[];

// FUNCTION: GAME 0x388420
struct Is *func_00388420(struct Is *s, int a)
{
    int ok;
    if (s->ios->st) {
        s->ios->st |= 2;
        ok = 0;
    } else {
        if (s->ios->tie)
            func_00389268(s->ios->tie);
        ok = 1;
        if ((int)(s->ios->fl & 1))
            ok = func_00389398(s);
    }
    if (ok)
        func_0038ADC8(s, D_0045D0F0, a);
    return s;
}

// FUNCTION: GAME 0x389FE0
int func_00389FE0(struct Is *s)
{
    if (s->ios->st) {
        s->ios->st |= 2;
        return 0;
    }
    if (s->ios->tie) {
        if (s->ios->sb->m8 == s->ios->sb->m4)
            func_00389268(s->ios->tie);
    }
    return 1;
}

// FUNCTION: GAME 0x38A040
int func_0038A040(struct Is *s)
{
    if (s->ios->st) {
        s->ios->st |= 2;
        return 0;
    }
    if (s->ios->tie)
        func_00389268(s->ios->tie);
    if ((int)(s->ios->fl & 1))
        return func_00389398(s);
    return 1;
}

struct VTb {
    char pad[0x34];
    int (*fn)(void *, char *, int);
};
int func_0038C9E8(const char *, char *, int);
void func_00389548(struct Is *);

// FUNCTION: GAME 0x388380
struct Is *__rs__7istreamRd(struct Is *s, int a)
{
    int ok;
    if (s->ios->st) {
        s->ios->st |= 2;
        ok = 0;
    } else {
        if (s->ios->tie)
            func_00389268(s->ios->tie);
        ok = 1;
        if ((int)(s->ios->fl & 1))
            ok = func_00389398(s);
    }
    if (ok)
        func_0038ADC8(s, D_0045D0E8, a);
    return s;
}
