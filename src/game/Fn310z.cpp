// COP2-initialised object factories in 0x312F70-0x313450. The laundered copy keeps the ctor pointer in its own register.
class cHeap;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
extern "C" void *memset(void *, int, unsigned int);
extern int D_00747A34;
extern cHeap D_00754C10;
extern cHeap RoomHeap;
extern "C" void __7cPlBase(void *);
extern "C" void __8cObjBase(void *);
extern "C" void __8cGameObj(void *);
extern void *D_0041B730[];
extern void *D_0041B6A0[];
extern void *D_00447AD0[];
extern void *D_00447F70[];
extern void *D_00448028[];
extern void *D_00448948[];
extern void *D_00448890[];

#define Z(q, o) __asm__ volatile("sqc2 $vf0,%c1(%0)" : : "r"(q), "i"(o) : "memory")
#define ZE(q) Z(q, 0); Z(q, 0x10); Z(q, 0x30); Z(q, 0x40); Z(q, 0x50); Z(q, 0x80)
#define OBJ(name, flag, sz, heap, ctor, vt, base, cnt, lastoff) \
    extern "C" void *name() \
    { \
        if (!(D_00747A34 & flag)) { \
            char *p = (char *)_MemoryAlloc(sz, 0x10, heap); \
            if (p) { \
                memset(p, 0, sz); \
                char *o = p; \
                __asm__("" : "+r"(o)); \
                ctor(o); \
                *(void **)(o + 0x214) = vt; \
                char *q = o + base; \
                int i = cnt; \
                do { \
                    ZE(q); \
                    q += 0xA0; \
                } while (--i != -1); \
                Z(p, lastoff); \
                return p; \
            } \
        } \
        return 0; \
    }

// FUNCTION: GAME 0x312F70
OBJ(func_00312F70, 0x10000, 0x20E0, D_00754C10, __8cObjBase, D_0041B6A0, 0x4D0, 0x2B, 0x20B0)

// FUNCTION: GAME 0x313030
extern "C" void *func_00313030()
{
    if (!(D_00747A34 & 0x10000)) {
        char *p = (char *)_MemoryAlloc(0x14C0, 0x10, D_00754C10);
        if (p) {
            memset(p, 0, 0x14C0);
            char *o = p;
            __asm__("" : "+r"(o));
            __7cPlBase(o);
            *(void **)(o + 0x214) = D_0041B730;
            char *q = o + 0x1460;
            int i = 1;
            do {
                Z(q, 0);
                q += 0x10;
            } while (--i != -1);
            return p;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x313210
OBJ(func_00313210, 0x100000, 0x21C0, RoomHeap, __8cGameObj, D_00447AD0, 0x5B0, 0x2B, 0x2190)
// FUNCTION: GAME 0x3132D0
OBJ(func_003132D0, 0x100000, 0x21C0, RoomHeap, __8cGameObj, D_00447F70, 0x5B0, 0x2B, 0x2190)
// FUNCTION: GAME 0x313390
OBJ(func_00313390, 0x100000, 0x21C0, RoomHeap, __8cGameObj, D_00448028, 0x5B0, 0x2B, 0x2190)
// FUNCTION: GAME 0x313450
OBJ(func_00313450, 0x100000, 0x21C0, RoomHeap, __8cGameObj, D_00448948, 0x5B0, 0x2B, 0x2190)
// FUNCTION: GAME 0x313150
OBJ(func_00313150, 0x100000, 0x21C0, RoomHeap, __8cGameObj, D_00448890, 0x5B0, 0x2B, 0x2190)

// FUNCTION: GAME 0x304938
extern "C" void func_00304938() {}
