// COMPILER: ee-gcc2.96
// One-argument tail-call wrappers: 24 bytes each (dead frame, constant in a0, `j` to the callee).

void func_0033B568(int);
void func_0033B5C8(int);
void func_0033BC48(int);

#define WRAP(name, callee, v) void name(void) { callee(v); }

void func_00329070(void);
void func_00329088(void);
void func_0033E6A8(void);
void func_0033E6B0(void);
void func_0033FCA0(void);
void func_0033FCA8(void);
void func_00335CD8(void);
void func_00335CE0(void);
void func_0033F130(char *);
void func_0033FCB0(char *);
void func_00335D40(char *);
extern char D_00452088[], D_00452B48[], D_00454D38[];

// Lock wrappers: enter, run the body, leave through a tail call.
#define LOCK(name, enter, body, leave) void name(void) { enter(); body(); leave(); }

// Null-checked byte getters: report through `err` and return -1 on a null handle.
#define GETB(name, err, msg) int name(char *a) { if (a == 0) { err(msg); return -1; } return a[1]; }

// FUNCTION: GAME 0x33B670
WRAP(func_0033B670, func_0033B5C8, 1)

// FUNCTION: GAME 0x33B688
WRAP(func_0033B688, func_0033B568, 2)

// FUNCTION: GAME 0x33B6A0
WRAP(func_0033B6A0, func_0033B568, 4)

// FUNCTION: GAME 0x33B6B8
WRAP(func_0033B6B8, func_0033B5C8, 2)

// FUNCTION: GAME 0x33B6D0
WRAP(func_0033B6D0, func_0033B5C8, 4)

// FUNCTION: GAME 0x33BD30
WRAP(func_0033BD30, func_0033BC48, 1)

// FUNCTION: GAME 0x33BD48
WRAP(func_0033BD48, func_0033BC48, 2)

// FUNCTION: GAME 0x33BD60
WRAP(func_0033BD60, func_0033BC48, 3)

// FUNCTION: GAME 0x33BD78
WRAP(func_0033BD78, func_0033BC48, 4)

// FUNCTION: GAME 0x33BD90
WRAP(func_0033BD90, func_0033BC48, 5)

// FUNCTION: GAME 0x33BDA8
WRAP(func_0033BDA8, func_0033BC48, 6)

// FUNCTION: GAME 0x33BDC0
WRAP(func_0033BDC0, func_0033BC48, 7)

// FUNCTION: GAME 0x328B88
void func_00328BB0(void);
LOCK(func_00328B88, func_00329070, func_00328BB0, func_00329088)

// FUNCTION: GAME 0x328C30
void func_00328C58(void);
LOCK(func_00328C30, func_00329070, func_00328C58, func_00329088)

// FUNCTION: GAME 0x329AC8
void func_00329AF0(void);
LOCK(func_00329AC8, func_0033E6A8, func_00329AF0, func_0033E6B0)

// FUNCTION: GAME 0x32AF88
void func_0032AFB0(void);
LOCK(func_0032AF88, func_0033E6A8, func_0032AFB0, func_0033E6B0)

// FUNCTION: GAME 0x32EBD8
void func_0032EC00(void);
LOCK(func_0032EBD8, func_0033FCA0, func_0032EC00, func_0033FCA8)

// FUNCTION: GAME 0x335A18
void func_00335A40(void);
LOCK(func_00335A18, func_00335CD8, func_00335A40, func_00335CE0)

// FUNCTION: GAME 0x33F590
void func_0033F5B8(void);
LOCK(func_0033F590, func_0033E6A8, func_0033F5B8, func_0033E6B0)

// FUNCTION: GAME 0x329FD0
GETB(func_00329FD0, func_0033F130, D_00452088)

// FUNCTION: GAME 0x32DC90
GETB(func_0032DC90, func_0033FCB0, D_00452B48)

// FUNCTION: GAME 0x335AD8
GETB(func_00335AD8, func_00335D40, D_00454D38)
