// Shared bodies for jump-table switch units. Each unit lives in its own Jt<ADDR>.cpp so the
// object's .rodata is exactly the jump table.

#pragma once
#include "game/cVec.h"

struct JtVt {
    char _p[0x40];
    short adj;
    short _pad;
    int (*fn)(void *);
};
extern char *CreateObj__F6eObjIdT0(int, int);

// Clears four channels, then re-arms the one selected by `sel` (1..4).
#define JT_SEL4(NAME, F1, F2, F3, F4)                                           \
    extern "C" void F1(void *, int);                                            \
    extern "C" void F2(void *, int);                                            \
    extern "C" void F3(void *, int);                                            \
    extern "C" void F4(void *, int);                                            \
    extern "C" void NAME(void *self, unsigned char sel)                         \
    {                                                                           \
        F1(self, 0);                                                            \
        F2(self, 0);                                                            \
        F3(self, 0);                                                            \
        F4(self, 0);                                                            \
        switch (sel) {                                                          \
        case 0:                                                                 \
            break;                                                              \
        case 1:                                                                 \
            F1(self, 1);                                                        \
            break;                                                              \
        case 2:                                                                 \
            F2(self, 1);                                                        \
            break;                                                              \
        case 3:                                                                 \
            F3(self, 1);                                                        \
            break;                                                              \
        case 4:                                                                 \
            F4(self, 1);                                                        \
            break;                                                              \
        }                                                                       \
    }

// Spawns the cObj for object id `id` (one of the 28 ids in the table), initialising its
// vectors from `self`. Other ids return 0.
#define JT_SPAWN(NAME)                                                          \
    extern "C" char *NAME(char *self, int id)                                   \
    {                                                                           \
        switch (id) {                                                           \
        case 0x361: case 0x362: case 0x363: case 0x365: case 0x366: case 0x367: \
        case 0x368: case 0x369: case 0x36A: case 0x36B: case 0x36C: case 0x36D: \
        case 0x36E: case 0x36F: case 0x370: case 0x372: case 0x373: case 0x374: \
        case 0x375: case 0x377: case 0x378: case 0x379: case 0x37A: case 0x37D: \
        case 0x37E: case 0x37F: case 0x380: case 0x3B7: {                       \
            char *o = CreateObj__F6eObjIdT0(id, 0xFFFF);                        \
            if (!o)                                                             \
                return 0;                                                       \
            JtVt *vt = *(JtVt **)(o + 0x214);                                   \
            if (!vt->fn(o + vt->adj))                                           \
                return 0;                                                       \
            *(cVec *)*(char **)(o + 0xF0) = **(cVec **)(self + 0xF0);           \
            *(cVec *)(o + 0x490) = **(cVec **)(o + 0xF0);                       \
            cVec *z = (cVec *)(o + 0x100);                                      \
            z->x = 0;                                                           \
            z->y = 0;                                                           \
            z->z = 0;                                                           \
            return o;                                                           \
        }                                                                       \
        }                                                                       \
        return 0;                                                               \
    }
