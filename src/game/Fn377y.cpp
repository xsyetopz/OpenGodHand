// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

extern "C" void *memset(void *, int, unsigned);

struct Fn377Ent {
    unsigned short m0;
    char _p2[3];
    unsigned char m5;
    unsigned short m6;
    char _p8[0xC];
    int m14;
    char _p18[0xE];
    unsigned short m26, m28, m2A, m2C, m2E;
    char _p30[0x20];
};
struct Fn377Req {
    char _p0[4];
    int m4;
    char _p8[0x1C];
    unsigned short m24, m26, m28, m2A;
};
extern Fn377Ent D_0076CF20[48];

// FUNCTION: GAME 0x376D28
extern "C" void func_00376D28(Fn377Req *r, unsigned short k)
{
    int i;
    for (i = 0; i < 48; i++) {
        Fn377Ent *e = &D_0076CF20[i];
        if (e->m0 != 0 && (e->m5 & 4) && e->m14 == r->m4) {
            switch (k) {
            case 1:
                e->m26 = r->m24;
                e->m28 = r->m26;
                e->m6 |= 9;
                break;
            case 2:
                e->m2C = r->m28;
                e->m6 |= 0xA;
                break;
            case 4:
                e->m2E = r->m2A;
                e->m6 |= 4;
                break;
            }
        }
    }
}

struct Fn377A {
    char _p0[2];
    short m2;
    char _p4[8];
    char mC, mD;
    short mE;
    char _p10[2];
    short m12;
    char _p14[0x3C];
};
struct Fn377B {
    char _p0[2];
    short m2;
    char m4, m5;
    char _p6[0x18];
    char m1E;
    char _p1F;
};
struct Fn377C {
    char _p0[2];
    short m2;
    char m4, m5;
    char _p6[0x4A];
};
extern Fn377A D_0076B9C0[0x30];
extern Fn377B D_0076C8C0[0x33];
extern Fn377C D_0076CF20x[0x33] __asm__("D_0076CF20");

// FUNCTION: GAME 0x377ED0
extern "C" void func_00377ED0(void)
{
    int i;
    memset(D_0076B9C0, 0, 0xF00);
    memset(D_0076C8C0, 0, 0x660);
    memset(D_0076CF20x, 0, 0xFF0);
    for (i = 0; i < 0x30; i++) {
        D_0076B9C0[i].m2 = i;
        D_0076B9C0[i].mC = 0;
        D_0076B9C0[i].mD = 0;
        D_0076B9C0[i].mE = -1;
        D_0076B9C0[i].m12 = -1;
    }
    for (i = 0; i < 0x33; i++) {
        D_0076C8C0[i].m2 = i;
        D_0076CF20x[i].m2 = i;
        D_0076C8C0[i].m4 = 0;
        D_0076C8C0[i].m5 = 0;
        D_0076C8C0[i].m1E = 0;
        D_0076CF20x[i].m4 = 0;
        D_0076CF20x[i].m5 = 0;
    }
}

struct Fn3768In { char p0[8]; unsigned short m8, mA, mC; short mE; };
struct Fn3768Src { char p0[0x30]; Fn3768In *m30; };
struct Fn3768Out { char p0[0xC]; unsigned short mC, mE, m10; short m12; };
extern "C" int func_00377FA0(void);

// FUNCTION: GAME 0x3768B0
extern "C" void func_003768B0(Fn3768Src *a, Fn3768Out *o)
{
    Fn3768In *i = a->m30;
    int s;
    short v;
    o->mC = i->m8;
    o->mE = i->mA;
    o->m10 = i->mC;
    s = i->mE;
    if (s == 0) {
        o->m12 = 0;
    } else {
        if (s <= 16)
            v = func_00377FA0() % (s + 1);
        else
            v = (int)((unsigned)func_00377FA0() % 17) * (s / 16);
        o->m12 = v;
    }
}
