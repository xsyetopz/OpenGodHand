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

struct Fn38T { char _p0[4]; unsigned char m_4; };
extern "C" void func_00381150(Fn38T *, int);
extern "C" void func_003812B0(Fn38T *, int, unsigned char);
extern "C" void func_003813C8(Fn38T *, int);
// FUNCTION: GAME 0x381070
extern "C" void func_00381070(Fn38T *o, Fn38Pad *p)
{
    switch (o->m_4) {
    case 0: func_003810F8((Fn38Pad *)o, p); break;
    case 1: func_00381150(o, (int)p); break;
    case 2:
    case 3: func_003812B0(o, (int)p, o->m_4 - 2); break;
    case 4: func_003813C8(o, (int)p); break;
    }
}

extern "C" void func_00381F18(Fn38T *);
extern "C" void func_003822D0(Fn38T *, int, unsigned char);
extern "C" void func_00382660(Fn38T *);
// FUNCTION: GAME 0x381EA0
extern "C" void func_00381EA0(Fn38T *o, int p)
{
    int k = o->m_4;
    switch (k) {
    case 0: func_00381F18(o); break;
    case 1:
    case 2: func_003822D0(o, p, k - 1); break;
    case 3: func_00382660(o); break;
    }
}

struct Fn38Y { char _p0[2]; unsigned char m_2; char _p3[0x2D]; int m_30; int m_34; int m_38; };
struct Fn38Z { char _p0[8]; int m_8; };
// FUNCTION: GAME 0x382520
extern "C" int func_00382520(int, Fn38Y *o, unsigned char f)
{
    Fn38Z *s = (Fn38Z *)((char *)o + 0x30);
    short *p;
    short *q;
    int k;
    if (f) {
        k = o->m_2;
        p = (short *)((char *)o + 0x22);
        q = (short *)((char *)o + (k * 2 + 0x22));
    } else {
        k = o->m_2;
        p = (short *)((char *)o + 0x18);
        q = (short *)((char *)o + (k * 2 + 0x18));
    }
    int i;
    for (i = 0; i < s->m_8; i++) {
        if (i != k - 1) {
            if (p[i + 1] != *q)
                return 0;
        }
    }
    return 1;
}

struct Fn38V { char _p0[3]; unsigned char m_3; };
struct Fn38U { char _p0[0x370]; char _p370[3]; unsigned char m_373; char _p374[0x60]; int m_3D4; char _p3D8[0x5C]; int m_434; };
extern "C" void func_00383F50(void);
extern "C" void func_00383EB0(void);
// FUNCTION: GAME 0x383E40
extern "C" void func_00383E40(Fn38U *o)
{
    Fn38V *q = (Fn38V *)((char *)o + 0x370);
    if (q->m_3 & 1) {
        if (o->m_434) {
            func_00383F50();
            return;
        }
    } else {
        if (o->m_3D4) {
            func_00383EB0();
            return;
        }
    }
    if (q->m_3 & 2)
        func_00383F50();
    else
        func_00383EB0();
}

extern "C" void func_00383690(Fn38T *);
extern "C" void func_00383878(Fn38T *);
extern "C" void func_00383B60(Fn38T *, int, unsigned char);
// FUNCTION: GAME 0x383518
extern "C" void func_00383518(Fn38T *o, int p)
{
    switch (o->m_4) {
    case 0: func_00383690(o); break;
    case 1: func_00383878(o); break;
    case 2:
    case 3: func_00383B60(o, p, o->m_4 - 2); break;
    case 4: func_00383E40((Fn38U *)o); break;
    }
}

extern "C" void func_00385030(Fn38T *);
extern "C" void func_003851C0(Fn38T *);
extern "C" void func_00385308(Fn38T *, int, unsigned char);
extern "C" void func_00385410(Fn38T *);
// FUNCTION: GAME 0x384FA8
extern "C" void func_00384FA8(Fn38T *o, int p)
{
    switch (o->m_4) {
    case 0: func_00385030(o); break;
    case 1: func_003851C0(o); break;
    case 2:
    case 3: func_00385308(o, p, o->m_4 - 2); break;
    case 4: func_00385410(o); break;
    }
}

extern int D_003F2870[];
extern char D_0045CD50[];
extern char D_0045CD60[];
extern "C" void func_002E0DE8(int, int, int, const char *, ...);
// FUNCTION: GAME 0x384BC8
extern "C" void func_00384BC8(int, Fn38T *o, unsigned char *b)
{
    if (o->m_4 != 0) {
        int k = o->m_4;
        func_002E0DE8(3, 0x18, 8, D_0045CD50, k - 1, D_003F2870[(k + b)[0x18]]);
    } else {
        func_002E0DE8(3, 0x18, 8, D_0045CD60, D_003F2870[(o->m_4 + b)[0x18]]);
    }
}
