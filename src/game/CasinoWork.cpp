// Unnamed small functions in 0x1F0000-0x1F7FFF.
extern char *Cockpit;
extern "C" void release__7cIDBase(void *);
extern "C" void trans__7cIDBase(void *);
extern "C" void SetNumber__12CustomIDWorki(void *, int);
extern "C" void func_001F6E18(int, int);
extern "C" void func_001F7A30(int, int);
extern const char D_0042C320[];

struct SelfBlk {
    char _pad[1];
};
struct ListNode {
    int _0;
    ListNode *m_next;
};
struct FlagSet {
    unsigned int m_flags;
    int _4;
    const char *m_p;
};

struct ZeroBlk {
    int m_0;
    int _4;
    int m_8;
    short m_C, m_E, m_10, m_12;
};

// FUNCTION: GAME 0x1F0490
extern "C" void func_001F0490()
{
}

// FUNCTION: GAME 0x1F0530
extern "C" void func_001F0530()
{
}

// FUNCTION: GAME 0x1F05F0
extern "C" void func_001F05F0()
{
}

// FUNCTION: GAME 0x1F07B8
extern "C" void func_001F07B8()
{
}

// FUNCTION: GAME 0x1F0870
extern "C" void func_001F0870()
{
}

// FUNCTION: GAME 0x1F0A20
extern "C" void func_001F0A20()
{
}

// FUNCTION: GAME 0x1F0E10
extern "C" void func_001F0E10()
{
}

// FUNCTION: GAME 0x1F1140
extern "C" void func_001F1140()
{
}

// FUNCTION: GAME 0x1F6CE0
extern "C" int *func_001F6CE0(int *self)
{
    *self = 0;
    return self;
}

#ifdef NONMATCHING
// 0x1F6CF8: compiler hoists the last store (m_12) to the front; original stores in source order
extern "C" void func_001F6CF8(ZeroBlk *self)
{
    self->m_0 = 0;
    self->m_8 = 0;
    self->m_C = 0;
    self->m_E = 0;
    self->m_10 = 0;
    self->m_12 = 0;
}
#endif

// FUNCTION: GAME 0x1F6FA0
extern "C" int func_001F6FA0()
{
    return 1;
}

// FUNCTION: GAME 0x1F75B0
extern "C" void func_001F75B0()
{
    char *p = Cockpit + 0x1380;
    p[0x94] &= 0xFE;
}

// FUNCTION: GAME 0x1F46E0
extern "C" void func_001F46E0(SelfBlk *self)
{
    release__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1F4758
extern "C" void func_001F4758(SelfBlk *self)
{
    trans__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1F4B78
extern "C" void func_001F4B78(SelfBlk *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x158, n);
}

// FUNCTION: GAME 0x1F28C0
extern "C" void func_001F28C0(SelfBlk *self)
{
    release__7cIDBase((char *)self + 0x930);
    release__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1F7800
extern "C" void func_001F7800(char *base, int idx, ListNode *node)
{
    ListNode *head = (ListNode *)(base + (idx * 16 + 4));
    ListNode *old = head->m_next;
    head->m_next = node;
    node->m_next = old;
}

// FUNCTION: GAME 0x1F7B60
extern "C" void func_001F7B60(FlagSet *self)
{
    self->m_p = D_0042C320;
    self->m_flags &= 0xFFFFF9FC;
}

// FUNCTION: GAME 0x1F7C60
extern "C" void func_001F7C60(FlagSet *self)
{
    self->m_p = D_0042C320;
    self->m_flags &= 0xFFFFF9FC;
}

// FUNCTION: GAME 0x1F6E48
extern "C" void func_001F6E48()
{
    func_001F6E18(1, 0xFFFF);
}

// FUNCTION: GAME 0x1F7D20
extern "C" void func_001F7D20()
{
    func_001F7A30(1, 0xFFFF);
}

extern "C" int sceOpen(const char *, int);
extern const char D_0042C0E0[];
extern int D_00568280;

struct WarmRoom {
    unsigned int m_flags;
    int m_4;
    float m_8;
    short m_C;
    unsigned short m_E;
};
struct ActionBtn {
    char _pad[0x35];
    unsigned char m_ok;
};

// FUNCTION: GAME 0x1F2990
extern "C" void func_001F2990(SelfBlk *self)
{
    trans__7cIDBase((char *)self + 0x10);
    trans__7cIDBase((char *)self + 0x930);
}

// FUNCTION: GAME 0x1F6D18
// Source store order is not the emitted order: gcc moves the m_4 store ahead of the flags write.
extern "C" void SetWarmUpRoom__10CasinoWorkifsUs(WarmRoom *self, int a, float f, short s, unsigned short u)
{
    self->m_flags |= 1;
    self->m_8 = f;
    self->m_C = s;
    self->m_E = u;
    self->m_4 = a;
}

// FUNCTION: GAME 0x1F6E68
extern "C" int func_001F6E68()
{
    D_00568280 = sceOpen(D_0042C0E0, 2);
    return 1;
}

// FUNCTION: GAME 0x1F6EE0
extern "C" void setOk__17cActionButtonUnit(ActionBtn *self)
{
    if (self->m_ok == 1)
        *(unsigned int *)(Cockpit + 0xF30) |= 0x10000000;
}
