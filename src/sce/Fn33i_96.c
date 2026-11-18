// COMPILER: ee-gcc2.96
extern void func_0033B790();
extern char D_00455F70[], D_00455F98[], D_00455FC0[], D_00455EF0[];
struct F { int m0; int m4; void *m8; };
extern struct F D_00758620[8][6];
// FUNCTION: GAME 0x33BA80
void func_0033BA80(unsigned a, unsigned b, int c, int d, void *e)
{
    struct F *s;
    if (b >= 6) {
        func_0033B790(D_00455F70);
        return;
    }
    if (a >= 8) {
        func_0033B790(D_00455F98);
        return;
    }
    s = &D_00758620[a][b];
    if (s->m0)
        func_0033B790(D_00455FC0);
    s->m0 = c;
    s->m4 = d;
    if (e)
        s->m8 = e;
    else
        s->m8 = D_00455EF0;
}

extern int sprintf(char *, const char *, ...);
extern int func_0033C548();
extern char D_004568F8[];
extern short D_003E9D54, D_003E9D56, D_003E9D58;
struct G { char _0[0xA0]; unsigned short hA0, hA2; short hA4; };
// FUNCTION: GAME 0x33D090
int func_0033D090(struct G *o, unsigned char a, unsigned char b, int c, unsigned short *p0, unsigned short *p1, unsigned short *p2)
{
    char buf[16];
    if (a >= 4) {
        if (b >= 16) {
            sprintf(buf, D_004568F8, c);
            func_0033C548(buf, 8, p0, p1, p2);
        } else if (b < 8) {
            *p0 = 0;
            *p1 = 0;
            *p2 = 0;
        } else {
            if (*(int *)&o->hA0 == 0 && o->hA4 == 0) {
                o->hA0 = D_003E9D54;
                o->hA2 = D_003E9D56;
                o->hA4 = D_003E9D58;
            }
            *p0 = o->hA0;
            *p1 = o->hA2;
            *p2 = o->hA4;
        }
    } else {
        *p0 = 0;
        *p1 = 0;
        *p2 = 0;
    }
    return 0;
}

extern void func_00338A48();
extern char D_00455A10[], D_00455920[], D_00455A20[], D_00455950[];
struct HH { char _0[4]; int m4; char _8[4]; int mC; int m10; int m14; int m18; void (*m1C)(int, int); int m20; };
struct R2 { int m0; int m4; };
// FUNCTION: GAME 0x3391F8
void func_003391F8(struct HH *o, int mode, struct R2 *r)
{
    int n, t, a0, a1, a2;
    if (o == 0) {
        func_00338A48(D_00455A10, D_00455920);
        return;
    }
    if (o->m4 == 0) {
        func_00338A48(D_00455A20, D_00455950);
        return;
    }
    n = r->m4;
    if (n <= 0)
        return;
    t = r->m0;
    if (t == 0)
        return;
    if (mode == 0)
        goto call;
    if (mode == 1) {
        a0 = o->m10 - n;
        a1 = o->mC;
        a2 = t - o->m14;
        if (a0 < 0) a0 = 0;
        o->m10 = a0;
        a1 += r->m4;
        if (o->m18 < a1) a1 = o->m18;
        o->mC = a1;
        if (a0 == a2)
            return;
call:
        if (o->m1C)
            o->m1C(o->m20, -3);
        return;
    }
    r->m4 = 0;
    r->m0 = 0;
    if (o->m1C)
        o->m1C(o->m20, -3);
}
