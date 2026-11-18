// More small unnamed functions in 0x300000-0x31FFFF.
class cHeap { public: void free(void *); };
void *_MemoryAlloc(unsigned int size, unsigned int align, cHeap &heap);
extern cHeap *MemDefalutHeapPtr;
extern int D_00755BC8;
extern "C" void func_0031DAA0();
extern "C" void func_0031EE10();
extern "C" int func_0031EE40();
extern char D_00450FD8[], D_00450FC0[], D_004511B8[];

struct Tri { void *a; void *b; void *c; void *d; };

// FUNCTION: GAME 0x31F1F8
extern "C" void func_0031F1F8() { func_0031EE10(); }
// FUNCTION: GAME 0x31F288
extern "C" void func_0031F288() { func_0031EE10(); }
// FUNCTION: GAME 0x31F310
extern "C" void func_0031F310() { func_0031EE10(); }
// FUNCTION: GAME 0x31FFA0
extern "C" void func_0031FFA0() { func_0031EE10(); }
// FUNCTION: GAME 0x31F460
extern "C" int func_0031F460() { return func_0031EE40() ^ 1; }
// FUNCTION: GAME 0x31EEA8
extern "C" void func_0031EEA8(Tri *p, void *a, void *c) { if (p) { p->c = c; p->a = a; p->b = D_00450FD8; } }
// FUNCTION: GAME 0x31FA20
extern "C" void func_0031FA20(Tri *p, void *a, void *c) { if (p) { p->c = c; p->a = a; p->b = D_004511B8; } }
// FUNCTION: GAME 0x31F188
extern "C" Tri *func_0031F188(Tri *p, void *a, void *c, void *d) { p->b = D_00450FC0; p->a = a; p->c = c; p->d = d; return p; }
// FUNCTION: GAME 0x30F550
extern "C" void *func_0030F550(unsigned n) { return _MemoryAlloc(n, 0x10, *MemDefalutHeapPtr); }
// FUNCTION: GAME 0x30F578
extern "C" void *func_0030F578(unsigned n) { return _MemoryAlloc(n, 0x10, *MemDefalutHeapPtr); }
