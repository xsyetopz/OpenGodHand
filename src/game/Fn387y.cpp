// COMPILER: ee-gcc2.9-991111
// SCE-built C++ library code in 0x3875A8-0x390000.
struct Base { char p0[4]; Base *m4; char p8[0x12]; unsigned char m1A; };
struct IS { Base *m0; int m4; };
extern "C" {
void flush__7ostream(void *);
long _IO_sgetn(void *, char *, long);
// FUNCTION: GAME 0x387890
IS *func_00387890(IS *s, char *buf, long n)
{
    Base *b = s->m0;
    int ok;
    if (b->m1A) {
        b->m1A |= 2;
        ok = 0;
    } else if (b->m4 == 0) {
        ok = 1;
    } else {
        int *sbuf = *(int **)b;
        if (sbuf[2] == sbuf[1]) {
            flush__7ostream(b->m4);
            ok = 1;
        } else
            ok = 1;
    }
    if (ok) {
        int r = _IO_sgetn(*(void **)s->m0, buf, (int)n);
        s->m4 = r;
        if (r != n)
            s->m0->m1A |= 3;
    } else {
        s->m4 = 0;
    }
    return s;
}
}
