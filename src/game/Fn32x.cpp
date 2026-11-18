// Small leaf units in .text 0x320000-0x32FFFF (compiled with sd/ld prologues in the original).

extern int D_003C80A8;
extern int D_003C80A4;
extern int D_003D1400;
extern int D_003C4F00;
extern "C" void abort();

struct S48 { char _p[0x48]; int m_48; int m_4c; };
struct S38 { char _p[0x38]; int m_38; int m_3c; };
struct S18 { char _p[0x18]; int m_18; int m_1c; };
struct S2C { char _p[0x2C]; int m_2c; };

// FUNCTION: GAME 0x325610
extern "C" int func_00325610() { return D_003C80A8; }

// FUNCTION: GAME 0x325620
extern "C" int func_00325620() { return D_003C80A4 != 0; }

// FUNCTION: GAME 0x327748
extern "C" void func_00327748(S48 *s, int a, int b) { s->m_48 = a; s->m_4c = b; }

// FUNCTION: GAME 0x328438
extern "C" void func_00328438(S38 *s, int a, int b) { s->m_38 = a; s->m_3c = b; }

// FUNCTION: GAME 0x328CD8
extern "C" int func_00328CD8(S18 *s, int a, int b) { s->m_1c = a; s->m_18 = b; return 1; }

// FUNCTION: GAME 0x328D30
extern "C" int func_00328D30(S2C *s, int a) { s->m_2c = a; return 1; }

// FUNCTION: GAME 0x329260
extern "C" void func_00329260(int a) { D_003D1400 = a; }

// FUNCTION: GAME 0x321218
extern "C" int func_00321218(int a) { int o = D_003C4F00; D_003C4F00 = a; return o; }

// FUNCTION: GAME 0x320270
extern "C" void func_00320270() { abort(); }

// DRAFT: GAME 0x32F4D0
// diff: original `addu a1,a1,a0` / `lw 0xB4(a1)`; compiled `addu a0,a0,a1` / `lw 0xB4(a0)` (operand order)
#ifdef NONMATCHING
extern "C" int func_0032F4D0(char *p, int i) { return *(int *)((i << 4) + p + 0xB4); }
#endif
