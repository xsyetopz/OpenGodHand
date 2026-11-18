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
extern "C" void func_00297B20()
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297B40
extern "C" void func_00297B40()
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
