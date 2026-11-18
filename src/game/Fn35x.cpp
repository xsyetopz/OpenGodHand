// Small leaf units in .text 0x350000-0x35FFFF.
struct S1FC0 { char _p[0x1FC0]; char *m_1fc0; };

// FUNCTION: GAME 0x3554F8
extern "C" void func_003554F8(S1FC0 *s, int v) { *(int *)(s->m_1fc0 + 0x80) = v; }
