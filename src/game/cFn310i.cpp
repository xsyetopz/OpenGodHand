#include "game/cFn310.h"

// Small non-factory units.
extern "C" {
void _$_8cObjBase(void *self);
void *__8cObjBase(void *self);
void free__5cHeapPv(void *heap, void *p);
void func_0030F5A0(void *p);
int func_0030FB70(void *p);
void *func_00312B00(void *a, void *b);
void __tf8cObjBase();
void func_0031EEA8(void *obj, const void *a, const void *b);
void func_003182D8(int a, int b);
void func_0031CE90(int a, int b);
extern int D_007865F8;
extern const char D_00450B28[], D_00450C08[], D_00450C38[], __ti8cObjBase[];
extern cHeap *MemDefalutHeapPtr;

// FUNCTION: GAME 0x3128B0
void func_003128B0(int **pp)
{
    int *o = *pp;
    if (o) {
        int *a = (int *)o[1];
        if (a)
            free__5cHeapPv((void *)a[-8], a);
        func_0030F5A0(o);
    }
    *pp = 0;
}

// FUNCTION: GAME 0x312AB0
void *func_00312AB0(void *a, void *b)
{
    if (!func_0030FB70(a))
        return 0;
    return func_00312B00(a, b);
}

// FUNCTION: GAME 0x318338
void func_00318338(void *p) { _$_8cObjBase(p); }

// FUNCTION: GAME 0x318358
void *func_00318358()
{
    if (D_007865F8 == 0) {
        __tf8cObjBase();
        func_0031EEA8(&D_007865F8, D_00450C08, __ti8cObjBase);
    }
    return &D_007865F8;
}

// FUNCTION: GAME 0x3183A8
int func_003183A8(char *p) { p[0x2F4] = 1; return 1; }

// FUNCTION: GAME 0x3183B8
void func_003183B8() {}

// FUNCTION: GAME 0x318418
void func_00318418(char *p) { *(const void **)(p + 0x214) = D_00450B28; _$_8cObjBase(p); }

// FUNCTION: GAME 0x318440
int func_00318440(char *p) { *(unsigned *)(p + 0x254) |= 0x8000000; *(unsigned *)(p + 0x4A8) |= 0x10000000; return 1; }

// FUNCTION: GAME 0x3184C0
void func_003184C0() { func_003182D8(1, 0xFFFF); }

// FUNCTION: GAME 0x3184E0
void *func_003184E0(void *self)
{
    char *p = (char *)self;
    __8cObjBase(p);
    *(const void **)(p + 0x214) = D_00450C38;
    return p;
}

// FUNCTION: GAME 0x318518
void func_00318518(char *p) { *(const void **)(p + 0x214) = D_00450C38; _$_8cObjBase(p); }

struct cFn310Slot { int a, b; };
struct cFn310SlotOwner { char pad[0xB00]; cFn310Slot s[1]; };
// FUNCTION: GAME 0x31A320
void func_0031A320(cFn310SlotOwner *p, int i) { p->s[i].a = 0; p->s[i].b = 0; }

struct cFn310Ent { char c; char q[15]; };
struct cFn310EntOwner { char pad[0x160]; cFn310Ent e[1]; };
// FUNCTION: GAME 0x31BD78
void func_0031BD78(cFn310EntOwner *p, int i) { p->e[i].c = 0; }

// FUNCTION: GAME 0x31C348
void func_0031C348() {}

// FUNCTION: GAME 0x31C890
void *func_0031C890(unsigned n) { return _MemoryAlloc(n, 0x10, *MemDefalutHeapPtr); }

// FUNCTION: GAME 0x31CE90
void func_0031CE90() {}

// FUNCTION: GAME 0x31CE98
void func_0031CE98() { func_0031CE90(1, 0xFFFF); }
}
