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
