// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2
// SCE runtime helpers in 0x394000-0x3A4AF0.

#ifdef NONMATCHING
typedef struct { int a, key, b; } SceEnt;
typedef struct { unsigned n; int pad; SceEnt e[1]; } SceTab;
extern SceTab D_003F5520;

// DRAFT: GAME 0x394D00
int func_00394D00(int key)
{
    unsigned i;
    if (D_003F5520.n) {
        SceEnt *p = D_003F5520.e;
        for (i = 0; i < D_003F5520.n; i++, p++) {
            if (p->key == key) {
                p->b = 0;
                p->a = 0;
                p->key = 0;
                return i;
            }
        }
    }
    return -1;
}
#endif

extern int func_003970A0();
extern int func_00397028();

// FUNCTION: GAME 0x39AC58
int func_0039AC58(char *obj)
{
    char *t = *(char **)(obj + 0x40);
    int *q;
    q = *(int **)(t + 0x1C8); if (q) q[10] = 0;
    q = *(int **)(t + 0x1D8); if (q) q[10] = 0;
    q = *(int **)(t + 0x1E8); if (q) q[10] = 0;
    q = *(int **)(t + 0x1CC); if (q) q[10] = 0;
    q = *(int **)(t + 0x1DC); if (q) q[10] = 0;
    q = *(int **)(t + 0x1EC); if (q) q[10] = 0;
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3973E8
void func_003973E8(int *s, int a)
{
    int v = func_003970A0(a);
    func_00397028(s);
    { unsigned m = 0xFFFFFFFFu; if (m != (unsigned)s[0x30 / 4])
        s[0x30 / 4] = v; }
    s[0x20 / 4] = 0;
    s[0] = (s[0] & ~0xC) | 0x105;
}

// DRAFT: GAME 0x397450
void func_00397450(int *s, int a, int b)
{
    int v = func_003970A0(a);
    func_00397028(s);
    { unsigned m = 0xFFFFFFFFu; if (m != (unsigned)s[0x10 / 4])
        s[0x10 / 4] = v; }
    s[0x20 / 4] = b;
    s[0] = (s[0] & ~0xC) | 0x101;
}
#endif

extern int func_003968E8();
extern int func_00396D60();
extern int func_0039C390();
extern char D_0045E588[];

// FUNCTION: GAME 0x396440
int func_00396440(char *obj, unsigned flag)
{
    int r;
    flag &= 1;
    func_003968E8(obj + flag * 0x28);
    if (flag)
        r = func_00396D60(obj + 0x1C0);
    else
        r = func_00396D60(obj + 0x50);
    return r;
}

// FUNCTION: GAME 0x39ADE0
unsigned func_0039ADE0(int ctx, unsigned *s, unsigned off, unsigned d)
{
    unsigned sz = (s[2] + d - 1) / d * d;
    unsigned end = sz + off;
    if (end <= s[0] + s[1]) {
        s[2] = end;
        return sz;
    }
    func_0039C390(ctx, D_0045E588);
    return 0;
}
