#include "game/cEvent.h"

extern unsigned int D_00747A84;

// FUNCTION: GAME 0x297C20
int cEvent::isPlaying() const
{
    if (!(D_00747A84 & 0x20000000))
        return 0;
    return m_state == 3;
}

struct EvPair {
    char _pad0[0x10];
    void *m_p;
    int m_q;
};

struct EvSrc {
    char _pad0[4];
    int m_q;
    char _pad8[8];
    char m_data[1];
};

struct EvTable {
    char _pad0[4];
    char *m_arr;
    char _pad8[8];
    int m_idx;
};

struct EvFlags {
    char _pad0[8];
    unsigned m_flags;
    char _pad[0x14 - 0xC];
};

extern char D_Ev297AA8[];
extern "C" int func_0(char *);
extern int D_Ev297B98;
extern EvTable D_Ev297BF8;

// FUNCTION: GAME 0x297AA8
extern "C" int func_00297AA8()
{
    return func_0(D_Ev297AA8) != 0;
}

// FUNCTION: GAME 0x297B20
extern "C" void func_00297B20(void *, void *)
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297B40
extern "C" void func_00297B40(void *, void *)
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297B60
extern "C" void func_00297B60()
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297BA8
extern "C" void func_00297BA8()
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297B80
extern "C" int func_00297B80(char *self)
{
    return *(int *)(self + 0x18);
}

// FUNCTION: GAME 0x297B98
extern "C" int func_00297B98()
{
    return D_Ev297B98;
}

// FUNCTION: GAME 0x297BF8
extern "C" void func_00297BF8()
{
    D_Ev297BF8.m_arr[D_Ev297BF8.m_idx * 16] = 0;
}

// FUNCTION: GAME 0x297C80
extern "C" void func_00297C80(int *self, int v)
{
    *self = v;
}

// FUNCTION: GAME 0x297C88
extern "C" void func_00297C88(char *self, short v)
{
    *(short *)(self + 0x3C) = v;
    *(unsigned *)(self + 8) |= 0x200;
}

// FUNCTION: GAME 0x297CA0
extern "C" void func_00297CA0(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297CB0
extern "C" void func_00297CB0(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297CA0(self, src->m_data, src->m_q);
    } else {
        func_00297CA0(self, 0, 0);
    }
}

// FUNCTION: GAME 0x298028
extern "C" int func_00298028(char *self, unsigned mask)
{
    return (*(unsigned *)(self + 0x28) & mask) != 0;
}

// FUNCTION: GAME 0x297CE8
extern "C" void func_00297CE8(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297CF8
extern "C" void func_00297CF8(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297CE8(self, src->m_data, src->m_q);
    } else {
        func_00297CE8(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297D30
extern "C" void func_00297D30(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297D40
extern "C" void func_00297D40(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297D30(self, src->m_data, src->m_q);
    } else {
        func_00297D30(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297D78
extern "C" void func_00297D78(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297D88
extern "C" void func_00297D88(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297D78(self, src->m_data, src->m_q);
    } else {
        func_00297D78(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297DC0
extern "C" void func_00297DC0(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297DD0
extern "C" void func_00297DD0(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297DC0(self, src->m_data, src->m_q);
    } else {
        func_00297DC0(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297E08
extern "C" void func_00297E08(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297E18
extern "C" void func_00297E18(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297E08(self, src->m_data, src->m_q);
    } else {
        func_00297E08(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297E50
extern "C" void func_00297E50(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297E60
extern "C" void func_00297E60(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297E50(self, src->m_data, src->m_q);
    } else {
        func_00297E50(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297E98
extern "C" void func_00297E98(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297EA8
extern "C" void func_00297EA8(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297E98(self, src->m_data, src->m_q);
    } else {
        func_00297E98(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297EE0
extern "C" void func_00297EE0(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297EF0
extern "C" void func_00297EF0(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297EE0(self, src->m_data, src->m_q);
    } else {
        func_00297EE0(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297F28
extern "C" void func_00297F28(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297F38
extern "C" void func_00297F38(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297F28(self, src->m_data, src->m_q);
    } else {
        func_00297F28(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297F70
extern "C" void func_00297F70(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297F80
extern "C" void func_00297F80(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297F70(self, src->m_data, src->m_q);
    } else {
        func_00297F70(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297FB8
extern "C" void func_00297FB8(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297FC8
extern "C" void func_00297FC8(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297FB8(self, src->m_data, src->m_q);
    } else {
        func_00297FB8(self, 0, 0);
    }
}

struct EvObj {
    char _pad0[0x250];
    unsigned m_flags;
    char _pad254[0x2FE - 0x254];
    unsigned short m_kind;
};

extern char D_Ev586AF0[];
extern char D_Ev569B90[];
extern char D_Ev44A9B0[];
extern char D_Ev44A9B8[];
extern char D_Ev44A9D0[];
extern char D_Ev44A9D8[];
extern "C" int func_001FC0A8(char *);
extern "C" void func_0014A338(EvObj *, char *, int);
extern "C" void func_002DB2B0(int, int);
extern "C" void func_00298088(EvObj *);
extern "C" void func_00298110(EvObj *, int, int);
extern "C" void func_002981D8(EvObj *, int, int);
extern "C" void func_002982A0(EvObj *);
extern "C" void func_00298338(int, float);
extern "C" void func_002983D0(int, float);
extern "C" void func_00298460();

// FUNCTION: GAME 0x298000
extern "C" void func_00298000(int a, int b)
{
    if (b == 0xFFFF) {
        if (a) {
            __asm__ volatile("sqc2 $vf0,32(%0)" : : "r"(D_Ev586AF0) : "memory");
        }
    }
}

// FUNCTION: GAME 0x298038
extern "C" void func_00298038()
{
    func_00298000(1, 0xFFFF);
}

// FUNCTION: GAME 0x298088
extern "C" void func_00298088(EvObj *self)
{
    if (self) {
        unsigned k = self->m_kind;
        int v = func_001FC0A8(D_Ev569B90);
        if (k == 1639) {
            if (v) {
                self->m_flags |= 2;
            }
        }
    }
}

// FUNCTION: GAME 0x2980E8
extern "C" void func_002980E8()
{
    func_00297B40(D_Ev586AF0, (void *)func_00298110);
}

// FUNCTION: GAME 0x298110
extern "C" void func_00298110(EvObj *self, int, int n)
{
    if (self) {
        switch (self->m_kind) {
        case 1541:
            if (n >= 16) {
                func_0014A338(self, D_Ev44A9B0, 0);
                func_0014A338(self, D_Ev44A9B8, 1);
            }
            break;
        case 1543:
            if (n >= 16) {
                func_0014A338(self, D_Ev44A9B0, 0);
            }
            break;
        }
    }
}

// FUNCTION: GAME 0x2981B0
extern "C" void func_002981B0()
{
    func_00297B40(D_Ev586AF0, (void *)func_002981D8);
}

// FUNCTION: GAME 0x2981D8
extern "C" void func_002981D8(EvObj *self, int, int n)
{
    if (self) {
        switch (self->m_kind) {
        case 1541:
            if (n >= 18) {
                func_0014A338(self, D_Ev44A9D0, 0);
                func_0014A338(self, D_Ev44A9D8, 1);
            }
            break;
        case 1543:
            if (n >= 18) {
                func_0014A338(self, D_Ev44A9D0, 0);
            }
            break;
        }
    }
}

// FUNCTION: GAME 0x298278
extern "C" void func_00298278()
{
    func_00297B40(D_Ev586AF0, (void *)func_002982A0);
}

// FUNCTION: GAME 0x2982A0
extern "C" void func_002982A0(EvObj *self)
{
    if (self) {
        unsigned k = self->m_kind;
        int v = func_001FC0A8(D_Ev569B90);
        if (k == 1539) {
            if ((unsigned char)(v - 4) < 2) {
                self->m_flags |= 2;
            }
        }
    }
}

// FUNCTION: GAME 0x298310
extern "C" void func_00298310()
{
    func_00297B20(D_Ev586AF0, (void *)func_00298338);
}

// FUNCTION: GAME 0x298338
extern "C" void func_00298338(int a, float f)
{
    if (f == 0.0f) {
        if (a == 0 || a == 4) {
            func_002DB2B0(30, 0);
            func_002DB2B0(31, 0);
        }
    }
}

// FUNCTION: GAME 0x298388
extern "C" void func_00298388()
{
    char *d = D_Ev586AF0;
    func_00297B20(d, (void *)func_002983D0);
    func_00297B40(d, (void *)func_00298460);
}

// FUNCTION: GAME 0x2983D0
extern "C" void func_002983D0(int a, float f)
{
    switch (a) {
    case 0:
        if (f == 0.0f) {
            func_002DB2B0(30, 0);
            func_002DB2B0(31, 0);
        }
        break;
    case 13:
        if (f == 101.0f) {
            func_002DB2B0(30, 0);
            func_002DB2B0(31, 0);
        }
        break;
    }
}
