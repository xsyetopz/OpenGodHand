// Mid-size functions in the ProDG game-code island 0x370000-0x387430 (continued from Fn38g.cpp).

extern "C" short func_003780B0(int, int);

struct Fn38Ch {
    unsigned short m_00;
    char _pad02[8];
    short m_0A;
    short m_0C;
};

struct Fn38Rec {
    unsigned short m_00;
    char _pad02[0x14];
    short m_16;
    char _pad18[0x88];
};
extern Fn38Rec D_0076E910[];

extern "C" void func_00377378(Fn38Rec *, Fn38Ch *);
extern "C" void func_00377428(Fn38Rec *, Fn38Ch *);

// FUNCTION: GAME 0x3772D8
extern "C" int func_003772D8(Fn38Ch *o)
{
    Fn38Rec *e = &D_0076E910[o->m_0C];
    if (e->m_00 == 0)
        return -1;
    switch (o->m_0A) {
    case 0:
        func_00377378(e, o);
        return 0;
    case 1:
        func_00377428(e, o);
        return 0;
    case 2:
        e->m_16 = 1;
        return 0;
    default:
        return 0;
    }
}

struct Fn38Tk {
    unsigned short m_00;
    char _pad02[2];
    int m_04;
    char _pad08[0xC];
    unsigned short m_14;
};

struct Fn38Tk2 {
    unsigned short m_00;
    char _pad02[3];
    unsigned char m_05;
    unsigned short m_06;
    char _pad08[0xC];
    int m_14;
    char _pad18[2];
    short m_1A;
    char _pad1C[0xA];
    unsigned short m_26;
    unsigned short m_28;
    char _pad2A[2];
    unsigned short m_2C;
    char _pad2E[0x22];
};
extern Fn38Tk2 D_0076CF20[];
extern "C" void func_0037D8B8(Fn38Tk2 *, int);

// FUNCTION: GAME 0x377A28
extern "C" void func_00377A28(Fn38Tk *o)
{
    int i;
    for (i = 0; i < 0x30; i++) {
        Fn38Tk2 *e = &D_0076CF20[i];
        if (e->m_00 == 0)
            continue;
        if ((e->m_05 & 2) == 0)
            continue;
        if (e->m_14 != o->m_04)
            continue;
        func_0037D8B8(e, -1);
    }
    o->m_14 = 3;
    o->m_00 |= 0x28;
}

struct Fn38Pl2 {
    unsigned short m_00;
    char _pad02[0x36];
    short m_38;
    char _pad3A[0x1E];
    int m_58;
};

extern "C" void func_00377688(Fn38Pl2 *, int);
extern "C" void func_00377A28(Fn38Tk *);

// FUNCTION: GAME 0x3775F0
extern "C" void func_003775F0(Fn38Pl2 *o)
{
    int i;
    if (o->m_00 & 0x10) {
        for (i = 0; i < 4; i++)
            func_00377688(o, i);
        if (o->m_58 == 0) {
            short *p;
            o->m_00 &= 0xFFEF;
            for (i = 0, p = &o->m_38; i < 4; i++, p += 4)
                if (*p != 0)
                    return;
            func_00377A28((Fn38Tk *)o);
        }
    }
}

struct Fn38Pr {
    char _pad0[4];
    int m_04;
    char _pad8[8];
    unsigned short m_10;
    char _pad12[0x26];
    struct {
        short m_0;
        char _p2[6];
    } m_38[4];
    short m_58;
    short m_5A;
    short m_5C;
    short m_5E;
    short m_60[4];
    short m_68[4];
    short m_70[2];
};

extern "C" void func_00377AC0(Fn38Pr *, unsigned short);

// FUNCTION: GAME 0x377700
extern "C" void func_00377700(Fn38Pr *o)
{
    int i;
    if (o->m_10 & 1) {
        for (i = 0; i < 4; i++) {
            o->m_60[i] = func_003780B0(o->m_5C, o->m_38[i].m_0);
            o->m_68[i] = func_003780B0(o->m_5E, o->m_38[i].m_0);
        }
        func_00377AC0(o, 1);
    }
    if (o->m_10 & 2)
        func_00377AC0(o, 2);
    o->m_10 = 0;
}

// FUNCTION: GAME 0x377AC0
extern "C" void func_00377AC0(Fn38Pr *o, unsigned short kind)
{
    int i;
    for (i = 0; i < 0x30; i++) {
        Fn38Tk2 *e = &D_0076CF20[i];
        if (e->m_00 == 0)
            continue;
        if ((e->m_05 & 2) == 0)
            continue;
        if (e->m_14 != o->m_04)
            continue;
        switch (kind) {
        case 1:
            e->m_26 = o->m_60[e->m_1A / 2];
            e->m_28 = o->m_68[e->m_1A / 2];
            e->m_06 |= 9;
            break;
        case 2:
            e->m_2C = o->m_70[e->m_1A % 2];
            e->m_06 |= 0xA;
            break;
        }
    }
}
