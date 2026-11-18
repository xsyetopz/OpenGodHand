// Validate and store a 0x20-byte table entry at 0x3749D8.
struct Fn374In { unsigned short m0, m2, m4, m6, m8, mA; int mC; };
struct Fn374Ent { unsigned short m0, m2, m4, m6, m8, mA; int mC; int m10; char _14[0xC]; };
extern Fn374Ent D_0076A7D4[];
extern "C" int func_00374AE0(short);

// FUNCTION: GAME 0x3749D8
extern "C" int func_003749D8(short i, Fn374In *p)
{
    Fn374Ent *e = D_0076A7D4 + i;
    int v = 0;
    if (i == 0) v = p->m2 & 1;
    unsigned short m = p->m0;
    if (m >= 0xA) v++;
    if (p->m4 >= 0x81) v++;
    if (p->m6 >= 0x81) v++;
    if (p->m8 >= 0x80) v++;
    if (p->mA >= 0x80) v++;
    if ((p->mC & 0x1FFFF) != 0x1FFFF) v++;
    if (v) return -1;
    e->m0 = m;
    e->m2 = p->m2;
    e->m4 = p->m4;
    e->m6 = p->m6;
    e->m8 = p->m8;
    e->mA = p->mA;
    e->mC = p->mC;
    e->m10 = func_00374AE0(m);
    return 0;
}
