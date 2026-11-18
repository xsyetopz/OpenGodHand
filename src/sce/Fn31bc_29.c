// COMPILER: ee-gcc2.9-991111
#ifdef NONMATCHING
// DRAFT: GAME 0x31BC98
// diff: 31 words, register allocation of e/f/c
struct Fn31Ch { unsigned char f, lvl, hi, lo; short _4; unsigned short rate; short _8; short step; short cur; };
struct Fn31Ctx { char _0[0x160]; struct Fn31Ch ch[16]; };
void func_0031BC98(struct Fn31Ctx *c, int idx)
{
    unsigned f;
    struct Fn31Ch *e = (struct Fn31Ch *)((char *)c + ((idx << 4) + 0x160));
    if (e->f & 1)
        ((char *)c)[0x360] = 1;
    f = e->f;
    if (f & 4) {
        e->step = ((e->hi - e->lo) << 4) / e->rate;
        e->lvl = e->hi;
        e->f = f & 3;
        e->cur = 0;
    }
    if (e->f & 2) {
        if (e->cur) {
            int v = (e->hi << 4) - e->cur;
            e->lvl = v / 16;
        }
        if (((unsigned char *)c)[0x361] < e->lvl)
            ((unsigned char *)c)[0x361] = e->lvl;
    }
    if (e->step)
        e->cur += e->step;
}
#endif
