// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn37EA {
    unsigned char b0;
    char _1;
    unsigned char b2;
};
struct Fn37EB {
    char _0[0x34];
    unsigned int w34;
};
extern "C" {
void func_0037E488(Fn37EA *);
void func_0037E4C0(Fn37EA *);
void func_0037FAC8(Fn37EA *);
void func_0037FB70(Fn37EA *);
void func_0037FC28(Fn37EA *);
void func_0037FCC8(Fn37EA *);
void func_0037FE40(Fn37EA *);
void func_0037FF98(Fn37EA *);
void func_00380048(Fn37EA *);
void func_00380138(Fn37EA *);
void func_00380280(Fn37EA *);
void func_00380638(Fn37EA *);
}

// DRAFT: GAME 0x37E368
#ifdef NONMATCHING
extern "C" int func_0037E368(Fn37EA *a, Fn37EB *b)
{
    if ((b->w34 & 0x40) && a->b2 == 1) {
        a->b0 = 0;
        a->b2 = 0;
        return 1;
    }
    switch (a->b2) {
    case 0: func_0037E488(a); break;
    case 1: func_0037E4C0(a); break;
    case 2: func_0037FAC8(a); break;
    case 3: func_0037FB70(a); break;
    case 4: func_0037FC28(a); break;
    case 5: func_0037FCC8(a); break;
    case 6: func_0037FE40(a); break;
    case 7: func_0037FF98(a); break;
    case 8:
    case 9:
    case 10:
    case 11: func_00380048(a); break;
    case 12: func_00380138(a); break;
    }
    func_00380280(a);
    func_00380638(a);
    return 1;
}
#endif
