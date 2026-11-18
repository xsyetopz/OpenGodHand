#ifndef FN2F8DECLS_H_
#define FN2F8DECLS_H_

// Small functions in 0x2D0000-0x2FFFFF.
#include "cSnd.h"

#include "cTaskWork.h"

#include "cHeap.h"

#include "cWorldLight.h"

struct cObj;

void ReleaseObj(cObj *);

extern "C" {

void func_002F1AA0(int, unsigned);

void func_002FBED0(void *);

void func_002FBE50(void *);

void func_002FBE28(char *, int);

void func_002FBDD8(void *);

void *func_002E9B68(void *);

void *func_002EBF08(void *);

void *func_002F56C0(void *);

void *func_002F61C8(void *);

extern char D_0044E820[];

extern char D_0044EA10[];

extern char D_0044F880[];

extern char D_0044FAD0[];

void func_002D4FC0(int, unsigned);

void func_002D9B70(int, unsigned);

void func_002D9E98(int, unsigned);

void func_002D9458(char *, char *);

void func_002D5918(char *);

void func_002D5990(char *);

void func_0031EEC8(void *, const char *);

void func_0031EEA8(void *, const void *, void *);

void func_00300148();

extern int D_00460D78; extern const char D_0044D200[];

extern int D_00460D80; extern const char D_0044D210[];

extern int D_00460D88; extern const char D_0044D3A0[];

extern int D_00460D90; extern const char D_0044D3D8[];

extern int D_007863F8; extern const char D_0044E9F8[]; extern char D_007863C8[];

extern int D_007864C8; extern const char D_0044F030[];

extern int D_007863E8; extern const char D_0044E398[];

extern int D_00786508; extern const char D_0044F398[];

extern int D_00786558; extern const char D_0044F6C0[];

extern int D_007864C8;

void func_002EBC50(char *, int);

extern int D_00786578; extern const char D_0044F868[];

extern const char D_0044E640[], D_0044F448[], D_0044F1C8[];

void func_002D5790(char *);

void func_0030F5A0(char *);

int func_00345B88(int);

void func_00345F48(int, int);

extern char *g_Sce;

extern void *D_00752C04;

extern const char D_0044D1E8[];

} // extern "C"

#include "CustomIDWork.h"

#include "cCoreSave.h"

extern cCoreSave CoreSave;

extern "C" void *func_002EFA60();

#endif
