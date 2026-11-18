// Tiny leaf units (empty stubs and field accessors) in .text 0x160000-0x1BFFFF.

struct S780 { char _p[0x780]; };
struct S600 { char _p[0x600]; unsigned char m_600; };
struct S770 { char _p[0x770]; float m_770; unsigned char m_774; unsigned char m_775; };

// FUNCTION: GAME 0x161610
extern "C" void func_00161610() { }

// FUNCTION: GAME 0x161618
extern "C" void func_00161618() { }

// FUNCTION: GAME 0x161620
extern "C" void func_00161620() { }

// FUNCTION: GAME 0x164978
extern "C" void func_00164978() { }

// FUNCTION: GAME 0x17E2F0
extern "C" void func_0017E2F0() { }

// FUNCTION: GAME 0x17EDC8
extern "C" void func_0017EDC8() { }

// FUNCTION: GAME 0x17F1C8
extern "C" void func_0017F1C8() { }

// FUNCTION: GAME 0x17FD78
extern "C" void func_0017FD78() { }

// FUNCTION: GAME 0x1A8680
extern "C" void func_001A8680() { }

// FUNCTION: GAME 0x1A50F8
extern "C" S780 *func_001A50F8(char *p) { return (S780 *)(p + 0x780); }

// FUNCTION: GAME 0x1B8640
extern "C" unsigned char func_001B8640(S600 *s) { return s->m_600; }

// FUNCTION: GAME 0x1BD778
extern "C" void func_001BD778(S770 *s) { s->m_775 = 0; }

// FUNCTION: GAME 0x1BDD88
extern "C" void func_001BDD88(S770 *s, float f) { s->m_770 = f; }

// FUNCTION: GAME 0x1BDD90
extern "C" unsigned char func_001BDD90(S770 *s) { return s->m_774; }

// FUNCTION: GAME 0x1BDD98
extern "C" unsigned char func_001BDD98(S770 *s) { return s->m_775; }
