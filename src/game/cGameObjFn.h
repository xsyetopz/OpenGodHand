// Small unnamed helpers in 0x2A0000-0x2AFFFF, written as extern "C" free functions over raw offsets.
#ifndef GAME_CGAMEOBJFN_H
#define GAME_CGAMEOBJFN_H

#include "cVec.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

extern void func_002A48A8(int, int);
extern void func_002A72C8(int, int);
extern void func_002A9D30(int, int);
extern void func_002ACBE8(int, int);
extern void func_002AD1B0(int, int);

extern int D_00747A0C;
extern char g_HeatSys[];
extern char D_0044AEF8[];
extern void func_002A58D8(char *, u32);
void *func_002A98A8(int *self);
extern void func_0030F5A0();
extern void func_002B16F0(void *);
extern void *getTexAddr(void *, int, u32) __asm__("getTexAddr__10cIDManager7eIdDataUi");

inline void *operator new(unsigned, void *p) { return p; }
struct PathFinding {
    PathFinding();
};

struct HH {
    HH *s;
    int f4, f8, fC, f10;
};
struct SS {
    HH *h;
    int n;
};

struct NN {
    int a;
    NN *prev;
    NN *next;
};

char *func_002AE3D0(char *self);
}

#endif
