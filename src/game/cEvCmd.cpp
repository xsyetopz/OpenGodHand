// Event script command handlers (.text 0x2B0000 range).

struct cEvCmdData {
    unsigned short m_op;
    unsigned short m_arg;
    short m_s4;
};

struct cEvNode {
    unsigned short m_h0;
    short m_h2;
    cEvNode *m_prev;
    cEvNode *m_next;
};

struct cEvCmd {
    char _pad0[0xC];
    unsigned char m_c;
    unsigned char m_d;
    unsigned char m_e;
    unsigned char m_f;
    int m_10;
    unsigned int m_flags;
    int m_18;
    int m_1c;
    int m_20;
    unsigned short m_24[2];
    unsigned short m_28;
    char _pad2A[2];
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned short m_2e;
    unsigned char m_30;
    unsigned char m_31;
    char _pad32[2];
    int m_34;
    unsigned short m_38;
    char _pad3A[2];
    unsigned char m_3c;
    char _pad3D[0x44 - 0x3D];
    unsigned char m_44;
    char _pad45[0x4C - 0x45];
    unsigned char m_4c;
    char _pad4D[3];
    int m_50;
    char _pad54[0x70 - 0x54];
    unsigned char m_70;
    char _pad71[0x8C - 0x71];
    cEvCmdData *m_data;
    char _pad90[0x94 - 0x90];
    unsigned short m_94;
    short m_96;
    float m_98;
    float m_9c;
    float m_a0;
    unsigned char m_a4;
    char _padA5[0xB2 - 0xA5];
    unsigned char m_b2;
    char _padB3;
    int m_b4;
    int m_b8;
};

extern "C" {
void func_002B22E0(cEvCmd *self, int v);
void func_002B21F0(cEvCmd *self, unsigned short v);
}

// 002B22E0
extern "C" void func_002B22E0(cEvCmd *self, int v)
{
    self->m_18 = v;
}

extern "C" void func_002B2400(cEvCmd *self)
{
    self->m_flags |= 0x40;
    if ((unsigned char)(self->m_c - 6) >= 2) {
        self->m_f = 0;
        self->m_c = 6;
        self->m_d = 0;
        self->m_e = 0;
    }
}

extern "C" void func_002B22E8(cEvNode *n, cEvNode *prev, cEvNode *next, short s, unsigned short t)
{
    if (prev)
        prev->m_next = n;
    if (next)
        next->m_prev = n;
    n->m_h0 = t;
    n->m_prev = prev;
    n->m_next = next;
    n->m_h2 = s;
}

extern "C" cEvNode *func_002B2318(cEvNode *n)
{
    if (n->m_prev)
        n->m_prev->m_next = n->m_next;
    if (n->m_next)
        n->m_next->m_prev = n->m_prev;
    return n->m_next;
}

extern "C" int func_002B4F78(cEvCmd *self)
{
    if (++self->m_10 == 0)
        self->m_10 = 1;
    return self->m_10;
}

extern "C" int func_002B2D08(cEvCmd *self)
{
    self->m_34 = 1;
    return 0;
}

extern "C" int func_002B2D18(cEvCmd *self)
{
    self->m_34 = 2;
    return 0;
}

extern "C" int func_002B2FB0(cEvCmd *self)
{
    cEvCmdData *d = self->m_data;
    self->m_flags |= 0x200;
    self->m_31 = d->m_arg;
    return 0;
}

extern "C" int func_002B2FD8(cEvCmd *self)
{
    self->m_38 = self->m_data->m_arg;
    return 0;
}

extern "C" int func_002B3008(cEvCmd *self)
{
    self->m_3c = self->m_data->m_arg;
    return 0;
}

extern "C" int func_002B3020(cEvCmd *self)
{
    self->m_flags |= 0x4000;
    return 0;
}

extern "C" int func_002B3038(cEvCmd *self)
{
    self->m_flags |= 4;
    return 0;
}

extern "C" void func_002B3230(cEvCmd *self)
{
    self->m_flags |= 0x10;
}

extern "C" int func_002B4518(cEvCmd *self, int v)
{
    return self->m_b4 == v;
}

extern "C" void func_002B4598(cEvCmd *self)
{
    if (self->m_b8 != 1)
        self->m_b8 = 1;
}

extern "C" void func_002B45B0(cEvCmd *self)
{
    if (self->m_b8 == 1)
        self->m_b8 = 0;
}

extern "C" int func_002B2F68() { return 0; }
extern "C" int func_002B2F70() { return 0; }
extern "C" int func_002B2F78() { return 0; }
extern "C" int func_002B2FA8() { return 0; }
extern "C" int func_002B2FD0() { return 0; }
extern "C" int func_002B2FF0() { return 0; }
extern "C" int func_002B2FF8() { return 0; }
extern "C" int func_002B3000() { return 0; }
extern "C" void func_002B2580() { }
