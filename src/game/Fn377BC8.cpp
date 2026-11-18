extern "C" {
void *memset(void *, int, unsigned);
void *memcpy(void *, const void *, unsigned);
void func_00377CB8();
void func_00377D58();
void func_00377D80();
void func_00377E28();
void func_00377ED0();
void func_00378540();
}

struct Fn377Ver {
    int a, b, c;
    short d;
};
struct Fn377Sde {
    Fn377Ver ver;
    char _p10[0xC];
    int m1C;
    short m20;
    char _p22[0x86];
    unsigned mA8;
    char _pAC[0x18];
};
extern const Fn377Ver D_0045A600;
extern Fn377Sde D_0076A790;
extern char D_0076A880[];
extern char D_0076A9C0[];
extern char D_0076B1C0[];

#ifdef NONMATCHING
// DRAFT: GAME 0x377BC8
extern "C" void func_00377BC8()
{
    memset(&D_0076A790, 0, 0xC4);
    memcpy(&D_0076A790.ver, &D_0045A600, 14);
    D_0076A790.m1C = 1;
    D_0076A790.mA8 = 0xFFFFFFFFu;
    D_0076A790.m20 = 0xD37;
    func_00377CB8();
    memset(D_0076A880, 0, 0x104);
    memset(D_0076A9C0, 0, 0x800);
    memset(D_0076B1C0, 0, 0x800);
    func_00377D58();
    func_00377D80();
    func_00377E28();
    func_00377ED0();
    func_00378540();
}
#endif
