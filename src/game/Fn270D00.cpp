extern "C" void *Getplayer__Fv();
struct V { float x, y; };
struct P { char pad[0xF0]; V *pos; };
struct A { char pad[0xF0]; V *pos; char pad2[0x470]; int state; };
#ifdef NONMATCHING
// DRAFT: GAME 0x00270D00
// DRAFT: float regs swapped (f0/f1/f2 allocation); tried abs via ternary, copy-then-neg, goto form, return forms
extern "C" int func_00270D00(A *a) {
    P *pl = (P *)Getplayer__Fv();
    int s = a->state;
    switch (s) {
    case 0x20B:
    case 0x221:
    case 0x242:
        return 0;
    }
    float d;
    d = pl->pos->y - a->pos->y;
    float f;
    if (d < 0.0f) f = -d; else f = d;
    int r = 0;
    if (!(f > 0.1f)) r = 1;
    return r;
}
#endif
