#ifndef COMFN190DECLS_H_
#define COMFN190DECLS_H_

// Constructors of map objects that own an array of 0x60-byte sub-records (count+1 entries),
// each cleared with five zero quad stores and a flag reset.
extern "C" void func_0016F640(char *self, char v);

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

extern "C" void func_001BBEB8(void *self);

extern "C" void func_001C27E8(void *self);

extern const char D_00424040[];

extern const char D_00424128[];

extern const char D_004243F0[];

extern const char D_004244D8[];

extern const char D_004245C0[];

extern const char D_004246A8[];

extern const char D_00424790[];

extern const char D_00424878[];

extern const char D_00424960[];

extern const char D_00424A48[];

extern "C" void func_001C7D98(void *self);

extern const char D_004241F0[];

extern const char D_00424C30[];

extern const char D_004250F0[];

extern const char D_00425290[];

extern const char D_00425378[];

extern const char D_00425460[];

extern const char D_00425548[];

extern const char D_00420070[];

extern const char D_00420158[];

extern const char D_00420240[];

extern const char D_00420328[];

extern const char D_00420410[];

extern const char D_004204F8[];

extern const char D_00420FE0[];

extern const char D_004210D0[];

extern const char D_004213C0[];

extern const char D_004214A8[];

extern const char D_00421658[];

extern const char D_00421740[];

extern const char D_00421848[];

extern const char D_00421938[];

extern const char D_00421D68[];

extern const char D_00421E38[];

extern const char D_004220B0[];

extern const char D_004223D0[];

extern const char D_00422770[];

extern const char D_00422858[];

extern const char D_00422928[];

extern const char D_00422C18[];

#endif
