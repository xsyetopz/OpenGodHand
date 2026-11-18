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

// FUNCTION: GAME 0x38B530
int func_0038B530(void)
{
    *func_003A4FB8() = 5;
    return -1;
}

// FUNCTION: GAME 0x38B578
void *func_0038B578(void *p)
{
    func_0038CFC0(p);
    return p;
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

// FUNCTION: GAME 0x38C3F0
void func_0038C3F0(char *o)
{
    struct VT {
        char pad[0x14];
        void (*fn)(char *);
    } *vt = *(struct VT **)(o + 0x50);
    vt->fn(o);
}

// FUNCTION: GAME 0x38C9E8
void func_0038C9E8(char *o)
{
    struct VT {
        char pad[0x3C];
        void (*fn)(char *);
    } *vt = *(struct VT **)(o + 0x50);
    vt->fn(o);
}

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
