// COMPILER: ee-gcc2.9-991111
// SCE libstdc++ iostream helpers (0x38AE80-0x38F140).

struct Fn38Ios { int m0; void *m4; int m8, mc; long m10; short m18; unsigned char m1a; };
struct Fn38Is { struct Fn38Ios *ios; };
struct Fn38Vt { char pad[0x34]; int (*xsputn)(void *, const char *, int); };
struct Fn38Sb { char pad[0x50]; struct Fn38Vt *vt; };
struct Fn38R { int m0, m4, m8, mc; long long m10; short m18; char m1a, m1b; int m1c, m20; };
struct Fn38W { struct Fn38R *p; int m4; };

extern int D_003F3D18;
extern char *D_003F3D28, *D_003F3D68, *D_003F3DB0, *D_003F3DF0;
extern char D_003F4ED0[], D_003F4F28[], D_003F4F80[], D_003F4FD8[], D_003F5038[], D_003F5098[];
extern char D_0045D7E0[], D_0045D7F0[];
extern void flush__7ostream(void *);
extern int _skip_ws__7istream(struct Fn38Is *);
extern void func_0038AF30(int, int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x38AE80
// diff: 2 words (final call loads is->ios into a3 in the original, v0 here)
struct Fn38Is *func_0038AE80(struct Fn38Is *is, int a, int b)
{
    int ok;
    if (is->ios->m1a) {
        is->ios->m1a |= 2;
        ok = 0;
    } else {
        if (is->ios->m4)
            flush__7ostream(is->ios->m4);
        if ((int)(is->ios->m10 & 1))
            ok = _skip_ws__7istream(is);
        else
            ok = 1;
    }
    if (ok) {
        struct Fn38Ios *t = is->ios;
        func_0038AF30(t->m0, a, b);
    }
    return is;
}
#endif

// FUNCTION: GAME 0x38AFB0
int func_0038AFB0(int a)
{
    if (a == D_003F3D18) return a;
    if (a) {
        D_003F3DB0 = D_003F4FD8; D_003F3D28 = D_003F5038;
        D_003F3D68 = D_003F5098; D_003F3DF0 = D_003F5098;
    } else {
        D_003F3DB0 = D_003F4ED0; D_003F3D28 = D_003F4F28;
        D_003F3D68 = D_003F4F80; D_003F3DF0 = D_003F4F80;
    }
    {
        int old = D_003F3D18;
        D_003F3D18 = a;
        return old;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x38E138
// diff: 3 words (zero-extend of the return value is scheduled after the epilogue loads)
unsigned long func_0038E138(struct Fn38Sb *f, int ch, long n)
{
    char buf[16];
    char *p;
    unsigned w = 0;
    int i;
    if (ch == ' ') {
        p = D_0045D7E0;
    } else if (ch == '0') {
        p = D_0045D7F0;
    } else {
        for (i = 15; i >= 0; i--)
            buf[i] = ch;
        p = buf;
    }
    for (i = n; i >= 16; i -= 16) {
        int r = f->vt->xsputn(f, p, 16);
        w += r;
        if (r != 16)
            goto done;
    }
    if (i > 0)
        w += f->vt->xsputn(f, p, i);
done:
    return w;
}

// DRAFT: GAME 0x38F140
// diff: 7 words (store order of the init block differs)
struct Fn38W *func_0038F140(struct Fn38W *a, struct Fn38W *b)
{
    struct Fn38R *r;
    int x;
    if (b != a) {
        x = *(int *)b->p;
        r = a->p;
        if (x == 0) r->m1a = 4; else r->m1a = 0;
        r->m1b = 0;
        r->m1c = 6;
        r->m8 = 0;
        r->m0 = x;
        r->m18 = 0x20;
        r->m10 = 0x11;
        r->m20 = 0;
        r->m4 = 0;
        a->m4 = 0;
    }
    return a;
}
#endif
