// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn38Pad { char _p0[5]; unsigned char m_5; char _p6[0x32]; unsigned m_38; };
// FUNCTION: GAME 0x3810F8
extern "C" void func_003810F8(Fn38Pad *a, Fn38Pad *b)
{
    if (b->m_38 & 0x8000) {
        if (a->m_5 == 0)
            a->m_5 = 9;
        else
            a->m_5 = a->m_5 - 1;
    }
    if (b->m_38 & 0x2000) {
        if (a->m_5 < 9)
            a->m_5 = a->m_5 + 1;
        else
            a->m_5 = 0;
    }
}

struct Fn38G { char _p0[8]; int m_8; };
struct Fn38H { char _p0[2]; unsigned char m_2; };
struct Fn38R { char _p0[0x38]; unsigned m_38; };
// FUNCTION: GAME 0x381E30
extern "C" void func_00381E30(char *a, Fn38R *b)
{
    Fn38H *h = (Fn38H *)(a + 0x318);
    Fn38G *g = (Fn38G *)(a + 0x348);
    if (g->m_8 > 0) {
        if (b->m_38 & 4) {
            if (h->m_2 == 0)
                h->m_2 = ((unsigned char *)g)[8];
            else
                h->m_2 = h->m_2 - 1;
        }
        if (b->m_38 & 8) {
            if (h->m_2 < g->m_8)
                h->m_2 = h->m_2 + 1;
            else
                h->m_2 = 0;
        }
    }
}

struct Fn38L { char _p0[8]; int m_8; char _pC[0xC]; unsigned char m_18[1]; };
// FUNCTION: GAME 0x382850
extern "C" int func_00382850(int, Fn38L *s)
{
    int i;
    for (i = 0; i < s->m_8; i++)
        if (s->m_18[i + 1])
            return 1;
    return 0;
}

// FUNCTION: GAME 0x383280
extern "C" int func_00383280(int, Fn38L *s)
{
    int i;
    for (i = 0; i < s->m_8; i++)
        if (s->m_18[i + 1])
            return 1;
    return 0;
}

struct Fn38K { char _p0[4]; unsigned char m_4; char _p5[0xA7]; int m_AC; };
// FUNCTION: GAME 0x383DD0
extern "C" int func_00383DD0(int, Fn38K *o, unsigned char f)
{
    short *p = (short *)((char *)o + 0x1C);
    if (f)
        p = (short *)((char *)o + 0x26);
    int i;
    for (i = 0; i < o->m_AC; i++) {
        if (i != o->m_4 - 1) {
            if (p[i + 1] != p[o->m_4])
                return 0;
        }
    }
    return 1;
}

extern "C" int func_0032B0B0(int);
extern "C" void func_0032B118(int);
struct Fn38M { char _p0[0x30]; int m_30; };
extern "C" void func_00380EB0(int, Fn38M *, int);
// FUNCTION: GAME 0x380F80
extern "C" int func_00380F80(int a, Fn38M *o, int c)
{
    if (o->m_30 != 0) {
        int r = func_0032B0B0(o->m_30);
        if (r != 0) {
            func_0032B118(o->m_30);
            func_00380EB0(a, o, c);
            return r != -1 ? 4 : 3;
        }
    }
    return 0;
}
