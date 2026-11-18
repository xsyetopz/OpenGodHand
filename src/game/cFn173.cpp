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

#ifdef NONMATCHING
// DRAFT: GAME 0x174208
// diff: frame/spill/lqc2 match; original accessor keeps `slt; andi 0xFF` and loads obj into $v1, ours drops andi and uses $a0 (121 words).
typedef int fn173_u128 __attribute__((mode(TI)));
struct Fn173V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Fn173Obj { char pad[0x154]; unsigned flags; };
struct Fn173Slot { char pad[0x58]; float f58; char pad2[0x60 - 0x5C]; };
struct Fn173Host { char pad[0x278]; Fn173Obj **arr; char pad2[0x2B4 - 0x27C]; unsigned char count; char pad3[0x660 - 0x2B5]; Fn173Slot slots[1]; };
extern "C" {
float fRand1_1__Fv();
float fRand0_1__Fv();
void func_0016F640(Fn173Slot *, int);
void func_00173998(Fn173Slot *, char *);
void func_00147C60(Fn173Slot *, char *);
void func_00147C88(void *, char *, int);
void func_00173908(Fn173Slot *, Fn173V4 *);
void func_00173938(Fn173Slot *, Fn173V4 *);
void func_00173968(Fn173Slot *, Fn173V4 *);
}
// const int& binds a stack temp for the lbu'd count (spill at sp+0).
static inline unsigned char fn173InR(int i, const int &n) { return i >= 0 && i < n; }
static inline Fn173Obj *fn173GetObj(Fn173Host *h, int i) { Fn173Obj *r = 0; if (fn173InR(i, h->count)) r = h->arr[i]; return r; }
extern "C" void func_00174208(Fn173Host *h, int i, Fn173V4 *a, Fn173V4 *b)
{
    fn173GetObj(h, i)->flags |= 8;
    fn173GetObj(h, i)->flags |= 0x10;
    Fn173V4 p, q, s;
    { register fn173_u128 t asm("vf4"); t = *(fn173_u128 *)a; *(fn173_u128 *)&p = t; }
    { register fn173_u128 t asm("vf4"); t = *(fn173_u128 *)b; *(fn173_u128 *)&q = t; }
    p.x += fRand1_1__Fv() * 0.2f; p.y += fRand0_1__Fv() * 0.2f; p.z += fRand1_1__Fv() * 0.2f;
    q.x += fRand1_1__Fv() * 0.1f; q.y += fRand1_1__Fv() * 0.1f; q.z += fRand1_1__Fv() * 0.1f;
    char *o = (char *)fn173GetObj(h, i) + 0x80;
    Fn173Slot *sl = &h->slots[i];
    func_0016F640(sl, 1); func_00173998(sl, o); func_00147C60(sl, o); func_00147C88((char *)sl + 0x10, o, 0);
    func_00173908(sl, &p); func_00173938(sl, &q);
    s.x = s.y = s.z = s.w = 1.0f;
    func_00173968(sl, &s);
    sl->f58 = -0.02f;
}
#endif
