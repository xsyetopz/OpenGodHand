// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn38Pad { char _p0[5]; unsigned char m_5; char _p6[0x32]; unsigned m_38; };

struct Fn38G { char _p0[8]; int m_8; };
struct Fn38H { char _p0[2]; unsigned char m_2; };
struct Fn38R { char _p0[0x38]; unsigned m_38; };

struct Fn38L { char _p0[8]; int m_8; char _pC[0xC]; unsigned char m_18[1]; };


struct Fn38K { char _p0[4]; unsigned char m_4; char _p5[0xA7]; int m_AC; };

extern "C" int func_0032B0B0(int);
extern "C" void func_0032B118(int);
struct Fn38M { char _p0[0x30]; int m_30; };
extern "C" void func_00380EB0(int, Fn38M *, int);

struct Fn38T { char _p0[4]; unsigned char m_4; };
extern "C" void func_00381150(Fn38T *, int);
extern "C" void func_003812B0(Fn38T *, int, unsigned char);
extern "C" void func_003813C8(Fn38T *, int);

extern "C" void func_00381F18(Fn38T *);
extern "C" void func_003822D0(Fn38T *, int, unsigned char);
extern "C" void func_00382660(Fn38T *);

struct Fn38Y { char _p0[2]; unsigned char m_2; char _p3[0x2D]; int m_30; int m_34; int m_38; };
struct Fn38Z { char _p0[8]; int m_8; };

struct Fn38V { char _p0[3]; unsigned char m_3; };
struct Fn38U { char _p0[0x370]; char _p370[3]; unsigned char m_373; char _p374[0x60]; int m_3D4; char _p3D8[0x5C]; int m_434; };
extern "C" void func_00383F50(void);
extern "C" void func_00383EB0(void);

extern "C" void func_00383690(Fn38T *);
extern "C" void func_00383878(Fn38T *);
extern "C" void func_00383B60(Fn38T *, int, unsigned char);

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
