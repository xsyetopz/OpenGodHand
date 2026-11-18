// Mode-table dispatch units (cluster of 0x138-byte functions): the 4-entry
// pointer-to-member table is copied to the stack and indexed by the mode byte.
class cFn173;
typedef void (cFn173::*cFn173Pmf)();
struct cFn173Tab {
    cFn173Pmf f[4];
};

class cFn173 {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
    char pad2[0x5B0 - 0x2F5];
    unsigned flags;
};

extern "C" {
int func_001B76B0(cFn173 *self);
void func_002A87E8(cFn173 *self, int a);
void func_001B76D8(cFn173 *self);
void func_001C7E30(cFn173 *self);
}

#define CFN173_MODE_UNIT(ADDR, TAB)                         \
    extern cFn173Tab TAB;                                    \
    extern "C" void func_00##ADDR(cFn173 *self)              \
    {                                                        \
        if (func_001B76B0(self)) {                           \
            long f = (unsigned)self->flags;                  \
            long x = (f >> 2) & 1;                           \
            if (!x) {                                        \
                cFn173Tab t = TAB;                           \
                (self->*t.f[self->type])();                  \
                func_002A87E8(self, 0);                      \
                func_001B76D8(self);                         \
            } else {                                         \
                func_001C7E30(self);                         \
            }                                                \
        }                                                    \
    }

// FUNCTION: GAME 0x173CB0
CFN173_MODE_UNIT(173CB0, D_00420FC0)

// FUNCTION: GAME 0x174A78
CFN173_MODE_UNIT(174A78, D_004210B0)

// FUNCTION: GAME 0x179220
CFN173_MODE_UNIT(179220, D_00421828)

// FUNCTION: GAME 0x179FD0
CFN173_MODE_UNIT(179FD0, D_00421918)

// FUNCTION: GAME 0x17C8E0
CFN173_MODE_UNIT(17C8E0, D_00421D48)

// FUNCTION: GAME 0x181AE8
CFN173_MODE_UNIT(181AE8, D_00422838)

// FUNCTION: GAME 0x186C58
CFN173_MODE_UNIT(186C58, D_00423058)

// FUNCTION: GAME 0x18B568
CFN173_MODE_UNIT(18B568, D_004237C8)

// FUNCTION: GAME 0x18C370
CFN173_MODE_UNIT(18C370, D_004238B8)

// FUNCTION: GAME 0x18D160
CFN173_MODE_UNIT(18D160, D_004239A8)

// FUNCTION: GAME 0x18DF18
CFN173_MODE_UNIT(18DF18, D_00423A98)

// FUNCTION: GAME 0x199290
CFN173_MODE_UNIT(199290, D_004250D0)

// FUNCTION: GAME 0x19C848
CFN173_MODE_UNIT(19C848, D_00425C58)

// FUNCTION: GAME 0x19F378
CFN173_MODE_UNIT(19F378, D_004267D8)
