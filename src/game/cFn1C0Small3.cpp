// Small unnamed functions in 0x1C0000-0x1DFFFF (round 17).
extern "C" void func_001B6F38(void *self, int flag);
extern "C" void func_001C6A90(void *, int, void *, int, int);
extern "C" void func_001DD1A0(void *);
extern "C" void func_001DEDC8(void *);
extern "C" void release__7cIDBase(void *);
extern const char D_00429DD8[];
extern const char D_00429EC8[];

// FUNCTION: GAME 0x1C7DE0
extern "C" void func_001C7DE0(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00429DD8;
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x1C8FC8
extern "C" void func_001C8FC8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00429EC8;
    func_001B6F38(self, flag);
}

struct OmS {
    char _pad[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
    char _pad2[0x5B8 - 0x2F8];
    unsigned m_f;
};


// FUNCTION: GAME 0x1C6A60
extern "C" void func_001C6A60(char *self, int a, int b, int c)
{
    func_001C6A90(self, a, self + 0x70, b, c | 2);
}

class cCamManager {
public:
    void setPlCamera(unsigned char v);
};
extern cCamManager CamManager;

// FUNCTION: GAME 0x1D4578
extern "C" void ClearBlackJackCamera__9BlackJack(void)
{
    CamManager.setPlCamera(0);
}

// FUNCTION: GAME 0x1DBDF0
extern "C" void ClearPokerCamera__5Poker(void)
{
    CamManager.setPlCamera(0);
}

// FUNCTION: GAME 0x1DF988
extern "C" void Move__7PokerId(char *self)
{
    func_001DD1A0(self);
    func_001DEDC8(self + 0x25B0);
}

struct IdInner {
    char _pad[0x98];
    int m_98;
    int m_9C;
};
struct IdSysP {
    IdInner *m_inner;
};
extern IdSysP *IDSys;

#ifdef NONMATCHING
// DRAFT: GAME 0x1D4F48
// diff: register allocation only (IDSys lui/lw use v1/v0 in the original, v0/v1 here)
extern "C" void func_001D4F48(char *self)
{
    release__7cIDBase(self + 0x10);
    IdInner *i = IDSys->m_inner;
    i->m_9C = 0;
    i->m_98 = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1C7E08
// diff: store/and schedule differs (orig sb 2F4, and, sb 2F5, sw 5B8, sb 2F6, sb 2F7)
extern "C" int func_001C7E08(OmS *self)
{
    unsigned f = self->m_f;
    self->m_a = 0;
    self->m_b = 0;
    self->m_f = f & ~0x40;
    self->m_c = 0;
    self->m_d = 0;
    return 1;
}
#endif

// Vtable-setting destructor wrappers in 0x190000-0x19FFFF.
extern "C" void func_001BBF00(void *self, int flag);
extern const char D_00424128[];
extern const char D_004241F0[];
extern const char D_00424D18[];
extern const char D_00425B90[];

// FUNCTION: GAME 0x191DC0
extern "C" void func_00191DC0(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00424128;
    func_001BBF00(self, flag);
}

// FUNCTION: GAME 0x192028
extern "C" void func_00192028(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_004241F0;
    func_001BBF00(self, flag);
}

// FUNCTION: GAME 0x195ED0
extern "C" void func_00195ED0(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00424D18;
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x19C3A8
extern "C" void func_0019C3A8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00425B90;
    func_001BBF00(self, flag);
}
