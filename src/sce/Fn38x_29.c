// COMPILER: ee-gcc2.9-991111
// SCE library units in 0x3875A8-0x3A3FFF built by SCE ee-gcc 2.9x (sd s0 prologues), -O2 -G0.

struct Obj39 {
    char pad[0x40];
    char *m_40;
};

void func_003BAA68(char *);
void func_003BAB50(char *);
int *func_003A4FB8(void);
void *func_0038CFC0(void *);

struct F39 { unsigned char *p; int cnt; };
struct O39 { char pad[0x58]; struct F39 *f; };
int func_003A6C10(struct F39 *);
unsigned func_003A6308(char *, int, int, struct F39 *);

// FUNCTION: GAME 0x39AE50
int func_0039AE50(struct Obj39 *o)
{
    func_003BAA68(o->m_40 + 0x68);
    return 1;
}

// FUNCTION: GAME 0x39AE78
int func_0039AE78(struct Obj39 *o)
{
    func_003BAB50(o->m_40 + 0x68);
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x38B0B0
// diff: 5 words, register allocation of the vtable slot ($v0 vs $a1) and the adjust ($a2 vs $v1)
void func_0038B0B0(char *o)
{
    struct VT {
        char pad[0x10];
        short adj;
        short pad2;
        void (*fn)(char *);
    } *vt = *(struct VT **)(o + 0x50);
    vt->fn(o + vt->adj);
}
#endif

int func_00399910(void);

// FUNCTION: GAME 0x3999A8
int func_003999A8(void)
{
    int r = func_00399910();
    return r == -1 ? 0 : r;
}

// FUNCTION: GAME 0x393628
long func_00393628(struct O39 *o, char *b, long n)
{
    if (n == 1) {
        struct F39 *f = o->f;
        int c;
        if (--f->cnt < 0)
            c = func_003A6C10(f);
        else
            c = *f->p++;
        if (c == -1)
            return 0;
        *b = c;
        return 1;
    }
    return func_003A6308(b, 1, (int)n, o->f);
}

int func_003B63A0(void);
void func_003B63F0(void);

// FUNCTION: GAME 0x397590
int func_00397590(volatile unsigned *p)
{
    int en = func_003B63A0();
    unsigned a = *(volatile unsigned *)0x1000F520;
    unsigned s;
    if (!(a & 0x10000))
        *(volatile unsigned *)0x1000F590 = a | 0x10000;
    (void)*(volatile unsigned *)0x1000E000;
    s = *p;
    *p = s & 0xFFFFFEFF;
    *(volatile unsigned *)0x1000F590 = a;
    if (en)
        func_003B63F0();
    return s;
}

extern char D_003F9840[], D_003FA1C0[], D_003F9810[], D_003F86C0[];
extern int D_003F866C, D_003F8668;
int func_00398EB0(int);
int func_00398BB0(int);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int SignalSema(int);

// FUNCTION: GAME 0x399910
int func_00399910(void)
{
    int r;
    if (!func_00398EB0(1))
        return -1;
    if (sceSifCallRpc(D_003FA1C0, 3, 0, 0, 0, D_003F9840, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        return -1;
    }
    r = *(int *)((unsigned)D_003F9840 | 0x20000000);
    SignalSema(D_003F866C);
    return r;
}

// FUNCTION: GAME 0x398D08
int func_00398D08(void)
{
    int r;
    if (!func_00398BB0(2))
        return 0;
    if (sceSifCallRpc(D_003F9810, 0xE, 0, 0, 0, D_003F86C0, 4, 0, 0) < 0) {
        SignalSema(D_003F8668);
        return 0;
    }
    r = *(int *)((unsigned)D_003F86C0 | 0x20000000);
    SignalSema(D_003F8668);
    return r;
}

// FUNCTION: GAME 0x3999D0
int func_003999D0(void)
{
    int r;
    if (!func_00398EB0(3))
        return -1;
    if (sceSifCallRpc(D_003FA1C0, 4, 0, 0, 0, D_003F9840, 4, 0, 0) < 0) {
        SignalSema(D_003F866C);
        return -1;
    }
    r = *(int *)((unsigned)D_003F9840 | 0x20000000);
    SignalSema(D_003F866C);
    return r;
}

#include "iostream.h"

int func_0038B168(struct SB *, int);
int func_0038EAE0(struct SB *);

int func_0038AB70(struct SB *, long *, char);

// FUNCTION: GAME 0x38ACB0
struct Is *func_0038ACB0(struct Is *s, int *out, char c)
{
    struct SB *sb;
    long tmp;
    if (ipfx(s)) {
        int r;
        sb = s->ios->sb;
        tmp = 0;
        r = func_0038AB70(sb, &tmp, c);
        *out = r;
        s->cnt = r ? tmp : 0;
        if (sb->flags & 0x10) {
            s->ios->st |= 1;
            if (!s->cnt)
                s->ios->st |= 2;
        }
    } else {
        *out = 0;
        s->cnt = 0;
    }
    return s;
}
