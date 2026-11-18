// Medium unnamed functions in 0x300000-0x31BFFF.
#ifndef GAME_CFN300MID_H
#define GAME_CFN300MID_H

extern "C" void func_002A9528(void *);
extern "C" void func_002C53A8(void *);
extern char D_00754200[], SoundHeap[], RoomHeap[], SubScrHeap[], D_00754240[];
extern char D_00754C10[], D_00754C20[], scrArray[], D_00754C50[];
extern int objArray, objbaseArray;
unsigned int *SearchData(unsigned int *, const char *, unsigned int);
extern char D_0044FEA0[];

struct SrchPair { unsigned *b; unsigned *a; };

struct LNode { LNode *prev; LNode *next; int _8; unsigned key; };
extern "C" void func_00307060(void *);
extern "C" int func_00305858(void *, int);
extern "C" void *func_003058D8(void *, int);
extern "C" void getEffTypeString__FPc12eEffDataType(char *, int);

class cHeap;
void *_MemoryAlloc(unsigned int size, unsigned int align, cHeap &heap);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void *__4cObj(void *);
extern char D_00450CE8[];

struct S309028 { char _p0[0x40]; float f40; char _p1[8]; unsigned c4C; char _p2[0x28]; float f78; float f7C; char _p3[0xD]; unsigned char b8D; unsigned short s8E; char _p4[0x10]; unsigned short sA0, sA2, sA4, sA6, sA8; };

// ---- Round 27 ----
extern "C" void func_002FB6C8(void *);
extern "C" void func_002FB7B0(void *);
extern "C" void func_00300AE8(void *, int);
extern "C" void func_00300C00(void *, int);
extern "C" void *func_00305FB0(char *self, int id);

extern char D_00747BA0[];
extern "C" void func_00397550(unsigned, int, int);
extern "C" void func_003973E8(unsigned, int);

extern unsigned D_00747A24;
extern char D_00754C80[];
extern char D_007476C0[];
extern char GlobalTask[];
extern void *g_Sce;
extern "C" void func_0031A0E8(void *);
extern "C" void func_002C3280(void *);
extern "C" void func_002D50E8(void *, int, int, int);
extern "C" void func_002D51C0(void *, int, int);
extern "C" void func_002D51F0(void *);
extern "C" void func_002E1348();
extern "C" void func_0030B870(int);
extern "C" void func_003AFF50(int);
extern "C" void FlushCache(int);
extern "C" void func_00396440(void *, int);
extern "C" void func_0030CB30();

#endif
