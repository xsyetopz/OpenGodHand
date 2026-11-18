// Stack-copied method-pointer-table dispatchers outside the 0x18 block.

class cFnW;
typedef void (cFnW::*cFnWPmf)();
class cFnW {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
};
struct cFnWTab4 { cFnWPmf p[4]; };

extern "C" {
int func_001B76B0(cFnW *self);
void func_001B76D8(cFnW *self);
void func_002A87E8(cFnW *self, int a);
void func_001BD430(cFnW *self);
void func_001A6558(cFnW *self);
}

extern const char D_004297B8[];
extern const char D_00429258[];
extern const char D_004273C0[];
extern const char D_00429C60[];

#define FW_CALL(TAB) \
    { cFnWTab4 t = *(const cFnWTab4 *)TAB; (self->*t.p[self->type])(); }
#define FW_FLAGS (*(unsigned *)((char *)self + 0x5B0))

// FUNCTION: GAME 0x1BFB80
extern "C" void func_001BFB80(cFnW *self)
{
    if (func_001B76B0(self)) {
        FW_CALL(D_004297B8)
        func_001B76D8(self);
    }
}

// FUNCTION: GAME 0x1BC0A0
extern "C" void func_001BC0A0(cFnW *self)
{
    if (func_001B76B0(self)) {
        long f = (unsigned)FW_FLAGS;
        long x = (f >> 1) & 1;
        if (!x)
            func_001BD430(self);
        FW_CALL(D_00429258)
        func_001B76D8(self);
    }
}

// FUNCTION: GAME 0x1A6188
extern "C" void func_001A6188(cFnW *self)
{
    if (func_001B76B0(self)) {
        FW_CALL(D_004273C0)
        func_001A6558(self);
        long f = (unsigned)FW_FLAGS;
        long x = (f >> 1) & 1;
        if (!x)
            func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

// FUNCTION: GAME 0x1C29D0
extern "C" void func_001C29D0(cFnW *self)
{
    if (func_001B76B0(self)) {
        short *tm = (short *)((char *)self + 0x610);
        if (*tm)
            (*tm)--;
        FW_CALL(D_00429C60)
        if (*(unsigned short *)((char *)self + 0x2FE) != 0x381)
            func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

// Timer state machines (anchor 0x173E60): mode byte 0x2F5, short timer at TOFF, reload 0xF.
struct sTmW {
    char _p[0x2F4];
    unsigned char m0, m1, m2, m3;
};
#define FW_TM(TOFF) (*(unsigned short *)((char *)s + (TOFF)))
#define FW_TIMER(NAME, TOFF) \
    extern "C" void NAME(sTmW *s) \
    { \
        switch (s->m1) { \
        case 0: \
            FW_TM(TOFF) = 0xF; \
            s->m1 = 1; \
            s->m2 = 0; \
            s->m3 = 0; \
        case 1: \
            FW_TM(TOFF)--; \
            if ((short)FW_TM(TOFF) <= 0) { \
                s->m0 = 0; \
                s->m1 = 0; \
                s->m2 = 0; \
                s->m3 = 0; \
            } \
            break; \
        } \
    }

// FUNCTION: GAME 0x186E08
FW_TIMER(func_00186E08, 0x654)

// FUNCTION: GAME 0x188190
FW_TIMER(func_00188190, 0x600)

// FUNCTION: GAME 0x1897B8
FW_TIMER(func_001897B8, 0xCD0)

// FUNCTION: GAME 0x18AA00
FW_TIMER(func_0018AA00, 0x604)

// FUNCTION: GAME 0x18B718
FW_TIMER(func_0018B718, 0x654)

// FUNCTION: GAME 0x18C520
FW_TIMER(func_0018C520, 0x654)

// FUNCTION: GAME 0x18D310
FW_TIMER(func_0018D310, 0x654)

// FUNCTION: GAME 0x18E0C8
FW_TIMER(func_0018E0C8, 0x654)

// FUNCTION: GAME 0x190CC8
FW_TIMER(func_00190CC8, 0xF84)

// FUNCTION: GAME 0x1926A0
FW_TIMER(func_001926A0, 0x600)

// FUNCTION: GAME 0x196978
FW_TIMER(func_00196978, 0x9D4)

// FUNCTION: GAME 0x197FA0
FW_TIMER(func_00197FA0, 0x9D4)

// FUNCTION: GAME 0x199440
FW_TIMER(func_00199440, 0x654)

// FUNCTION: GAME 0x19C9F8
FW_TIMER(func_0019C9F8, 0x654)

// FUNCTION: GAME 0x19F528
FW_TIMER(func_0019F528, 0x654)

// FUNCTION: GAME 0x1A1768
FW_TIMER(func_001A1768, 0xD94)

// FUNCTION: GAME 0x1A2E28
FW_TIMER(func_001A2E28, 0xD98)

// FUNCTION: GAME 0x1BC6E8
FW_TIMER(func_001BC6E8, 0x62C)

// Mode-table dispatchers (anchor 0x1841E8).
#define FW_DISP(NAME, TAB) \
    extern cFnWPmf TAB[]; \
    extern "C" void NAME(cFnW *self) \
    { \
        if (func_001B76B0(self)) { \
            (self->*TAB[self->type])(); \
            func_002A87E8(self, 0); \
            func_001B76D8(self); \
        } \
    }

// FUNCTION: GAME 0x171200
FW_DISP(func_00171200, D_003BD9F0)

// FUNCTION: GAME 0x17BA28
FW_DISP(func_0017BA28, D_003BDA40)

// FUNCTION: GAME 0x17ED00
FW_DISP(func_0017ED00, D_003BDA88)

// FUNCTION: GAME 0x182A18
FW_DISP(func_00182A18, D_003BDB20)

// FUNCTION: GAME 0x195F18
FW_DISP(func_00195F18, D_003BDB68)

// FUNCTION: GAME 0x1A85B8
FW_DISP(func_001A85B8, D_003BDBD0)

// FUNCTION: GAME 0x1A8A70
FW_DISP(func_001A8A70, D_003BDBF0)

// FUNCTION: GAME 0x1B3800
FW_DISP(func_001B3800, D_003BDD20)

// FUNCTION: GAME 0x1B6968
FW_DISP(func_001B6968, D_003BDD78)

// FUNCTION: GAME 0x1BD6B0
FW_DISP(func_001BD6B0, D_003BDDC8)

// FUNCTION: GAME 0x1BE950
FW_DISP(func_001BE950, D_003BDE08)

// FUNCTION: GAME 0x1BF518
FW_DISP(func_001BF518, D_003BDE30)

// Damage-check tails (anchor 0x173DE8): checkDamage(take at TOFF), then state change on a hit.
class cDamageTake;
class cOmBase { public: int checkDamage(cDamageTake *d); };
struct sDmW {
    char _p0[0x2F4];
    unsigned char m_2f4, m_2f5, m_2f6, m_2f7;
    char _p2f8[0x54A - 0x2F8];
    short m_54a;
    char _p54c[0x5B0 - 0x54C];
    unsigned m_5b0;
};
#define FW_DMG(NAME, TOFF) \
    extern "C" void NAME(sDmW *s) \
    { \
        int r = ((cOmBase *)s)->checkDamage(*(cDamageTake **)((char *)s + (TOFF))); \
        if (r == 1) { \
            if (s->m_54a <= 0) { \
                s->m_2f4 = 2; \
                s->m_5b0 |= 1; \
                s->m_2f6 = 0; \
                s->m_2f7 = 0; \
                s->m_2f5 = 0; \
            } else { \
                s->m_2f4 = r; \
                s->m_2f5 = 0; \
                s->m_2f6 = 0; \
                s->m_2f7 = 0; \
            } \
        } \
    }

// FUNCTION: GAME 0x181C20
FW_DMG(func_00181C20, 0x650)

// FUNCTION: GAME 0x186D90
FW_DMG(func_00186D90, 0x650)

// FUNCTION: GAME 0x188118
FW_DMG(func_00188118, 0x604)

// FUNCTION: GAME 0x18A988
FW_DMG(func_0018A988, 0x600)

// FUNCTION: GAME 0x18B6A0
FW_DMG(func_0018B6A0, 0x650)

// FUNCTION: GAME 0x18C4A8
FW_DMG(func_0018C4A8, 0x650)

// FUNCTION: GAME 0x18D298
FW_DMG(func_0018D298, 0x650)

// FUNCTION: GAME 0x18E050
FW_DMG(func_0018E050, 0x650)

// FUNCTION: GAME 0x1993C8
FW_DMG(func_001993C8, 0x650)

// FUNCTION: GAME 0x19B458
FW_DMG(func_0019B458, 0x600)

// FUNCTION: GAME 0x19C980
FW_DMG(func_0019C980, 0x650)

// FUNCTION: GAME 0x19F4B0
FW_DMG(func_0019F4B0, 0x650)

// FUNCTION: GAME 0x1C2B08
FW_DMG(func_001C2B08, 0x600)
