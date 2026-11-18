#ifndef CFN100DECL_H
#define CFN100DECL_H
// Small free functions of 0x100000-0x13FFFF.
extern "C" void func_00107DE0(int a, int b);
extern "C" void _$_15cCollisionSolid(void *self);
extern const char D_0041D7E0[];
extern const char D_0041D7B8[];
extern "C" void trans__7cIDBase(void *);

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern "C" void *initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void move__7cCamera(char *);
extern "C" int getIDWork__7cIDBasei(void *, int);
extern "C" void *memset(void *, int, unsigned);
extern "C" void move__7cIDBase(void *);
extern "C" void restartAnim__7cIDBase(void *);
extern const char D_0041B598[];
extern char *pCamWork;
#endif
