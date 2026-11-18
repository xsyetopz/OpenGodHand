#include "game/cEvCmd.h"

// FUNCTION: GAME 0x2B22E0
extern "C" void func_002B22E0(cEvCmd *self, int v)
{
    self->m_18 = v;
}

// FUNCTION: GAME 0x2B2400
extern "C" void func_002B2400(cEvCmd *self)
{
    self->m_flags |= 0x40;
    if ((unsigned char)(self->m_c - 6) >= 2) {
        self->m_c = 6;
        self->m_d = 0;
        self->m_e = 0;
        self->m_f = 0;
    }
}

// FUNCTION: GAME 0x2B22E8
extern "C" void func_002B22E8(cEvNode *n, cEvNode *prev, cEvNode *next, short s, unsigned short t)
{
    if (prev)
        prev->m_next = n;
    if (next)
        next->m_prev = n;
    n->m_prev = prev;
    n->m_next = next;
    n->m_h2 = s;
    n->m_h0 = t;
}

// FUNCTION: GAME 0x2B2318
extern "C" cEvNode *func_002B2318(cEvNode *n)
{
    if (n->m_prev)
        n->m_prev->m_next = n->m_next;
    if (n->m_next)
        n->m_next->m_prev = n->m_prev;
    return n->m_next;
}

// FUNCTION: GAME 0x2B4F78
extern "C" int func_002B4F78(cEvCmd *self)
{
    if (++self->m_10 == 0)
        self->m_10 = 1;
    return self->m_10;
}

// FUNCTION: GAME 0x2B2D08
extern "C" int func_002B2D08(cEvCmd *self)
{
    self->m_34 = 1;
    return 0;
}

// FUNCTION: GAME 0x2B2D18
extern "C" int func_002B2D18(cEvCmd *self)
{
    self->m_34 = 2;
    return 0;
}

// FUNCTION: GAME 0x2B2FB0
extern "C" int func_002B2FB0(cEvCmd *self)
{
    self->m_31 = self->m_data->m_arg;
    self->m_flags |= 0x200;
    return 0;
}

// FUNCTION: GAME 0x2B2FD8
extern "C" int func_002B2FD8(cEvCmd *self)
{
    self->m_38 = self->m_data->m_arg;
    return 0;
}

// FUNCTION: GAME 0x2B3008
extern "C" int func_002B3008(cEvCmd *self)
{
    self->m_3c = self->m_data->m_arg;
    return 0;
}

// FUNCTION: GAME 0x2B3020
extern "C" int func_002B3020(cEvCmd *self)
{
    self->m_flags |= 0x4000;
    return 0;
}

// FUNCTION: GAME 0x2B3038
extern "C" int func_002B3038(cEvCmd *self)
{
    self->m_flags |= 4;
    return 0;
}

// FUNCTION: GAME 0x2B3230
extern "C" void func_002B3230(cEvCmd *self)
{
    self->m_flags |= 0x10;
}

// FUNCTION: GAME 0x2B4518
extern "C" int func_002B4518(cEvCmd *self, int v)
{
    return self->m_b4 == v;
}

// FUNCTION: GAME 0x2B4598
extern "C" void func_002B4598(cEvCmd *self)
{
    if (self->m_b8 != 1)
        self->m_b8 = 1;
}

// FUNCTION: GAME 0x2B45B0
extern "C" void func_002B45B0(cEvCmd *self)
{
    if (self->m_b8 == 1)
        self->m_b8 = 0;
}

// FUNCTION: GAME 0x2B2F68
extern "C" int func_002B2F68() { return 0; }
// FUNCTION: GAME 0x2B2F70
extern "C" int func_002B2F70() { return 0; }
// FUNCTION: GAME 0x2B2F78
extern "C" int func_002B2F78() { return 0; }
// FUNCTION: GAME 0x2B2FA8
extern "C" int func_002B2FA8() { return 0; }
// FUNCTION: GAME 0x2B2FD0
extern "C" int func_002B2FD0() { return 0; }
// FUNCTION: GAME 0x2B2FF0
extern "C" int func_002B2FF0() { return 0; }
// FUNCTION: GAME 0x2B2FF8
extern "C" int func_002B2FF8() { return 0; }
// FUNCTION: GAME 0x2B3000
extern "C" int func_002B3000() { return 0; }
// FUNCTION: GAME 0x2B2580
extern "C" void func_002B2580() { }


// FUNCTION: GAME 0x2B2A30
extern "C" int func_002B2A30(cEvCmd *self)
{
    self->m_70 = 0;
    self->m_a4 = 0;
    func_002B2A88(self);
    return 0;
}

// FUNCTION: GAME 0x2B2A58
extern "C" int func_002B2A58(cEvCmd *self)
{
    self->m_70 = 1;
    self->m_a4 = 0;
    func_002B2A88(self);
    return 0;
}

// FUNCTION: GAME 0x2B2B78
extern "C" int func_002B2B78(cEvCmd *self)
{
    self->m_70 = 2;
    self->m_a4 = 4;
    self->m_18 = 0;
    self->m_94 = self->m_data->m_arg;
    self->m_96 = 0;
    self->m_3c = 0;
    return 0;
}

// FUNCTION: GAME 0x2B2BA8
extern "C" int func_002B2BA8(cEvCmd *self)
{
    self->m_70 = 2;
    self->m_a4 = 5;
    self->m_18 = 0;
    self->m_94 = self->m_data->m_arg;
    self->m_96 = 0;
    self->m_3c = 0;
    return 0;
}

// FUNCTION: GAME 0x2B2F80
extern "C" int func_002B2F80(cEvCmd *self)
{
    func_002B45E0(self, self->m_data->m_arg);
    return 0;
}

// FUNCTION: GAME 0x2B3050
extern "C" int func_002B3050(cEvCmd *self)
{
    func_002B4528(self, (const char *)self->m_data + 2);
    return 0;
}

// FUNCTION: GAME 0x2B4528
extern "C" void func_002B4528(cEvCmd *self, const char *name)
{
    func_002B4428(self, 1, SearchCameraData(name));
}

// FUNCTION: GAME 0x2B41F0
extern "C" void func_002B41F0(cEvCmd *self)
{
    func_002B45F0(self);
    self->m_10 = 0;
    self->m_flags &= ~0x10;
}

// FUNCTION: GAME 0x2B4560
extern "C" void func_002B4560(cEvCmd *self)
{
    if (func_002B4518(self, 1))
        func_002B4598(self);
}
