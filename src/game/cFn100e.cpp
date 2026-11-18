#include "cFn100Decl.h"

#ifdef NONMATCHING
// DRAFT: GAME 0x13F558
// diff: original keeps one v0 = self+n*4 and copies it to a0/a1; compiled uses distinct regs (~12 words).
extern "C" void func_0013F558(char *self, char *o)
{
    if ((D_00747A84 & 0x20000000) == 0) {
        if ((*(unsigned *)(o + 0x2F0) & 0x1000) == 0) {
            unsigned char n = self[0x358];
            if (n < 5) {
                char *v = self + n * 4;
                *(char **)(v + 0x250) = o;
                char *w = v;
                *(char **)(w + 0x35C) = self + (n * 0x50 + 0xC0);
                *(int *)(v + 0xA8) = 0;
                self[0x358] = self[0x358] + 1;
            }
        }
    }
}
#endif

extern char *CoreSave;

#ifdef NONMATCHING
// DRAFT: GAME 0x13DAE0
// diff: 2 words; original's third test is a plain beqz to the shared epilogue, compiled emits beql with a duplicated epilogue.
extern "C" void func_0013DAE0(char *self)
{
    unsigned f = D_00747A84;
    if ((f & 0x8000000) == 0) {
        if (f & 0x2000000)
            return;
        if (*(unsigned *)(CoreSave + 0x14) & 0x4000000) {
            trans__7cIDBase(self + 0xD0);
            trans__7cIDBase(self);
        }
    }
}
#endif

extern "C" void func_00138CA8(char *self, char *dst, char *src, unsigned char m);
extern "C" void reset__7cCamera(void *);
extern int D_00460D18;
extern char D_00747A24[];

#define CAM_SET(NAME, ST, OFF)                                                \
    extern "C" void NAME(char *self, unsigned char a)                         \
    {                                                                         \
        int st = *(int *)(self + 0x1028);                                     \
        if (st != (ST) && st != 0x10) {                                       \
            char *c = self + (OFF);                                           \
            if (a)                                                            \
                func_00138CA8(self, c, pCamWork, a);                          \
            *(int *)(self + 0x102C) = *(int *)(self + 0x1028);                \
            *(char **)(self + 0xFF0) = pCamWork;                              \
            pCamWork = c;                                                     \
            *(int *)(self + 0x1028) = (ST);                                   \
        }                                                                     \
    }

// FUNCTION: GAME 0x138D40
CAM_SET(setPlCamera__11cCamManagerUc, 1, 0)
// FUNCTION: GAME 0x138DB8
CAM_SET(setMotCamera__11cCamManagerUc, 4, 0x530)
// FUNCTION: GAME 0x138E38
CAM_SET(setPartsCamera__11cCamManagerUc, 0x40, 0x920)

#ifdef NONMATCHING
// DRAFT: GAME 0x138EB8
// diff: 2 words; original emits daddu a0 before the 0x102C store; all 6 store permutations and local placements tried.
extern "C" void setSubScrCamera__11cCamManagerUc(char *self, unsigned char a)
{
    int st = *(int *)(self + 0x1028);
    if (st != 0x80 && st != 0x10) {
        if (a) {
            func_00138CA8(self, self + 0xC90, pCamWork, a);
            st = *(int *)(self + 0x1028);
        }
        *(int *)(self + 0x102C) = st;
        char *c = self + 0xC90;
        *(char **)(self + 0xFF0) = pCamWork;
        pCamWork = c;
        reset__7cCamera(c);
        *(int *)(self + 0x1028) = 0x80;
    }
}
#endif

// FUNCTION: GAME 0x13C298
extern "C" void func_0013C298(char *self)
{
    unsigned short i = 0;
    char *p = self + 0x98;
    *(int *)(self + 0x90) = 0;
    restartAnim__7cIDBase(self);
    self[0x1C] = 1;
    do {
        *(int *)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 4);
    *(int *)(self + 0x94) = 0;
}

// FUNCTION: GAME 0x1344A0
extern "C" void func_001344A0(char *self)
{
    if (*(int *)(self + 4)) {
        do {
            char *a = *(char **)(self + 4);
            char *nx = *(char **)a;
            if (a) {
                char *vt = *(char **)(a + 0x30);
                ((void (*)(char *, int))*(void **)(vt + 0xC))(a + *(short *)(vt + 8), 3);
            }
            *(char **)(self + 4) = nx;
            D_00460D18 = D_00460D18 - 1;
        } while (*(int *)(self + 4));
    }
}

// FUNCTION: GAME 0x13E6E0
extern "C" void func_0013E6E0(char *self)
{
    unsigned long f = *(unsigned *)D_00747A24;
    if (((f >> 3) & 1) == 0) {
        char *a = D_00747A24;
        if (*(int *)(a + 8) >= 0) {
            if (((unsigned char *)a)[0x2D])
                trans__7cIDBase(self);
            if (*(int *)(self + 0x90))
                trans__7cIDBase(self + 0xB0);
        }
    }
}

struct sSysR22 { char _p0[0x5B0]; unsigned short a; char _p1[0x5E4 - 0x5B2]; unsigned f; };
extern sSysR22 Sys;

// FUNCTION: GAME 0x13BCC0
extern "C" void func_0013BCC0(char *self)
{
    unsigned short i = 0;
    char *p = self + 0xB0;
    *(int *)(self + 0x90) = 0;
    restartAnim__7cIDBase(self);
    self[0x1C] = 1;
    do {
        *(int *)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 0xD);
    self[0x94] = 0;
    self[0x95] = 0;
}

// FUNCTION: GAME 0x13BC28
extern "C" void func_0013BC28(char *self)
{
    unsigned short i;
    char *p = self + 0xB0;
    *(int *)(self + 0x90) = 0;
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 4);
    i = 0;
    do {
        *(int *)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 0xD);
    float *q = *(float **)(self + 0xB0);
    *(float *)(self + 0xA0) = q[0xE];
    *(float *)(self + 0xA4) = q[0xF];
    *(int *)(self + 0xE4) = -1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x13D200
// diff: clamp tail; compiled re-extends the stored halfword (andi/sll/sra) instead of reloading lh/lhu from memory.
extern "C" void func_0013D200(char *self)
{
    if (Sys.a != 0x20 && ((unsigned char *)self)[0x93] == 0) {
        unsigned short h;
        if (Sys.f & 0x40000000)
            h = *(unsigned short *)(self + 0x90) - 1;
        else if (((unsigned char *)self)[0x92])
            h = *(unsigned short *)(self + 0x90) - 1;
        else
            h = *(unsigned short *)(self + 0x90) + 1;
        *(unsigned short *)(self + 0x90) = h;
        short t = *(short *)(self + 0x90);
        unsigned short x = *(unsigned short *)(self + 0x90);
        if (t < 0)
            x = 0;
        else if (t >= 7)
            x = 6;
        *(unsigned short *)(self + 0x90) = x;
    }
}
#endif

extern unsigned short D_00747A50;
extern char g_SceAt[];
extern "C" int func_002C2568(void *, int, int);
extern "C" void func_002DBE98(void);

#ifdef NONMATCHING
// DRAFT: GAME 0x12C758
// diff: original uses a1=self and a leaf-style 0x10 frame with v0=0 set in the first branch delay slot; compiled differs in regs and branch-likely use.
extern "C" int func_0012C758(char *self)
{
    if (D_00747A50 == 0x608) {
        if (*(int *)(self + 0x698) == 0 && *(int *)(self + 0x6A0) == 0) {
            if (func_002C2568(g_SceAt, *(int *)(self + 0xF0), 0) == 1) {
                func_002DBE98();
                return 1;
            }
        }
    }
    return 0;
}
#endif
