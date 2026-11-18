// Small functions in the ProDG game-code island 0x370000-0x383FFF.
#ifndef GAME_FN37X_H
#define GAME_FN37X_H


struct Fn37Obj {
    char _pad0[0x30];
    int m_30;
    int m_34;
    char _pad38[0x10];
    int m_48;
    int m_4C;
    char _pad50[8];
    int m_58;
};

extern int D_0076A7A4;
extern int D_0076B080;

struct Fn37Flags {
    unsigned short m_0;
};

extern "C" void func_003757A0(int, int);
extern "C" void func_00386D70(void);
extern "C" void func_0037BE98(void);
extern "C" void func_00329EA8(void *);
extern "C" void func_0032B300(void *, int);
extern "C" void func_0032A6D0(void *);
extern "C" void func_00336D08(void *);
extern char D_0076C8C0[];

extern "C" int func_00373B20(Fn37Obj *o);
extern "C" void func_00374318(Fn37Obj *o);
extern "C" void func_00373D48(Fn37Obj *o);
extern "C" void func_00374548(Fn37Obj *o);
extern "C" void *memset(void *, int, unsigned);

extern "C" void func_00374570(Fn37Obj *o);
extern "C" void func_00374598(Fn37Obj *o);
extern "C" void func_00373FA0(void **o);
extern "C" void func_00373FC8(void **o);

struct Fn37Obj3 {
    char _pad0[0x48];
    int m_48;
    int m_4C;
    char _pad50[0x1C];
    int m_6C;
    char _pad70[4];
    int m_74;
    char _pad78[4];
    int m_7C;
};

struct Fn37Obj4 {
    char _pad0[0x54];
    int m_54;
};
extern "C" void func_003745C0(float, Fn37Obj4 *, int, int);
extern "C" void func_00373FF0(float, Fn37Obj4 *, int);

extern "C" void func_00374820(Fn37Obj *, int, int);
extern "C" int func_003748A8(Fn37Obj *);
extern "C" int func_00374170(Fn37Obj *);

struct Fn37Pk {
    char b[15];
} __attribute__((packed));

struct Fn37Ent {
    char _pad0[0xA];
    unsigned char m_0A;
    unsigned char m_0B;
    char _pad0C[4];
    unsigned char m_10;
    Fn37Pk m_11;
    char _pad20[1];
};

struct Fn37Sel {
    char _pad0[0x4C];
    int m_4C;
    char _pad50[4];
    int m_54;
    int m_58;
    Fn37Pk m_5C;
    char _pad6B[1];
    Fn37Ent *m_6C;
    Fn37Ent *m_70;
    int m_74;
    int m_78;
    int m_7C;
};

extern "C" int func_00374508(Fn37Sel *o, int, Fn37Ent *);
extern "C" int func_00373F38(Fn37Sel *o, int, Fn37Ent *, int, int);

extern "C" int func_00373A50(Fn37Obj *o);

#endif
