#include "game/cEvent.h"

extern unsigned int D_00747A84;

// FUNCTION: GAME 0x297C20
int cEvent::isPlaying() const
{
    if (!(D_00747A84 & 0x20000000))
        return 0;
    return m_state == 3;
}

struct EvPair {
    char _pad0[0x10];
    void *m_p;
    int m_q;
};

struct EvSrc {
    char _pad0[4];
    int m_q;
    char _pad8[8];
    char m_data[1];
};

struct EvTable {
    char _pad0[4];
    char *m_arr;
    char _pad8[8];
    int m_idx;
};

struct EvFlags {
    char _pad0[8];
    unsigned m_flags;
    char _pad[0x14 - 0xC];
};

extern char D_Ev297AA8[];
extern "C" int func_0(char *);
extern int D_Ev297B98;
extern EvTable D_Ev297BF8;

// FUNCTION: GAME 0x297AA8
extern "C" int func_00297AA8()
{
    return func_0(D_Ev297AA8) != 0;
}

// FUNCTION: GAME 0x297B20
extern "C" void func_00297B20(void *, void *)
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297B40
extern "C" void func_00297B40(void *, void *)
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297B60
extern "C" void func_00297B60()
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297BA8
extern "C" void func_00297BA8()
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297B80
extern "C" int func_00297B80(char *self)
{
    return *(int *)(self + 0x18);
}

// FUNCTION: GAME 0x297B98
extern "C" int func_00297B98()
{
    return D_Ev297B98;
}

// FUNCTION: GAME 0x297BF8
extern "C" void func_00297BF8()
{
    D_Ev297BF8.m_arr[D_Ev297BF8.m_idx * 16] = 0;
}

// FUNCTION: GAME 0x297C80
extern "C" void func_00297C80(int *self, int v)
{
    *self = v;
}

// FUNCTION: GAME 0x297C88
extern "C" void func_00297C88(char *self, short v)
{
    *(short *)(self + 0x3C) = v;
    *(unsigned *)(self + 8) |= 0x200;
}

// FUNCTION: GAME 0x297CA0
extern "C" void func_00297CA0(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297CB0
extern "C" void func_00297CB0(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297CA0(self, src->m_data, src->m_q);
    } else {
        func_00297CA0(self, 0, 0);
    }
}

// FUNCTION: GAME 0x298028
extern "C" int func_00298028(char *self, unsigned mask)
{
    return (*(unsigned *)(self + 0x28) & mask) != 0;
}

// FUNCTION: GAME 0x297CE8
extern "C" void func_00297CE8(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297CF8
extern "C" void func_00297CF8(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297CE8(self, src->m_data, src->m_q);
    } else {
        func_00297CE8(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297D30
extern "C" void func_00297D30(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297D40
extern "C" void func_00297D40(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297D30(self, src->m_data, src->m_q);
    } else {
        func_00297D30(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297D78
extern "C" void func_00297D78(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297D88
extern "C" void func_00297D88(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297D78(self, src->m_data, src->m_q);
    } else {
        func_00297D78(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297DC0
extern "C" void func_00297DC0(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297DD0
extern "C" void func_00297DD0(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297DC0(self, src->m_data, src->m_q);
    } else {
        func_00297DC0(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297E08
extern "C" void func_00297E08(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297E18
extern "C" void func_00297E18(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297E08(self, src->m_data, src->m_q);
    } else {
        func_00297E08(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297E50
extern "C" void func_00297E50(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297E60
extern "C" void func_00297E60(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297E50(self, src->m_data, src->m_q);
    } else {
        func_00297E50(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297E98
extern "C" void func_00297E98(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297EA8
extern "C" void func_00297EA8(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297E98(self, src->m_data, src->m_q);
    } else {
        func_00297E98(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297EE0
extern "C" void func_00297EE0(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297EF0
extern "C" void func_00297EF0(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297EE0(self, src->m_data, src->m_q);
    } else {
        func_00297EE0(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297F28
extern "C" void func_00297F28(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297F38
extern "C" void func_00297F38(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297F28(self, src->m_data, src->m_q);
    } else {
        func_00297F28(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297F70
extern "C" void func_00297F70(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297F80
extern "C" void func_00297F80(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297F70(self, src->m_data, src->m_q);
    } else {
        func_00297F70(self, 0, 0);
    }
}

// FUNCTION: GAME 0x297FB8
extern "C" void func_00297FB8(EvPair *self, void *p, int q)
{
    self->m_p = p;
    self->m_q = q;
}

// FUNCTION: GAME 0x297FC8
extern "C" void func_00297FC8(EvPair *self, EvSrc *src)
{
    if (src) {
        func_00297FB8(self, src->m_data, src->m_q);
    } else {
        func_00297FB8(self, 0, 0);
    }
}

struct EvObj {
    char _pad0[0x250];
    unsigned m_flags;
    char _pad254[0x2FE - 0x254];
    unsigned short m_kind;
};

extern char D_Ev586AF0[];
extern char CoreSave[]; // 0x569B70
extern char D_Ev44A9B0[];
extern char D_Ev44A9B8[];
extern char D_Ev44A9D0[];
extern char D_Ev44A9D8[];
extern "C" int getCostumeNo__9cCoreSave(char *);
extern "C" void setMeshDisplay__6cModelPCcb(EvObj *, char *, int);
extern "C" void displayScrollLayer__FUib(int, int);
extern "C" void func_00298088(EvObj *);
extern "C" void func_00298110(EvObj *, int, int);
extern "C" void func_002981D8(EvObj *, int, int);
extern "C" void func_002982A0(EvObj *);
extern "C" void func_00298338(int, float);
extern "C" void func_002983D0(int, float);
extern "C" void func_00298460();

// FUNCTION: GAME 0x298000
extern "C" void func_00298000(int a, int b)
{
    if (b == 0xFFFF) {
        if (a) {
            __asm__ volatile("sqc2 $vf0,32(%0)" : : "r"(D_Ev586AF0) : "memory");
        }
    }
}

// FUNCTION: GAME 0x298038
extern "C" void func_00298038()
{
    func_00298000(1, 0xFFFF);
}

// FUNCTION: GAME 0x298088
extern "C" void func_00298088(EvObj *self)
{
    if (self) {
        unsigned k = self->m_kind;
        int v = getCostumeNo__9cCoreSave(CoreSave);
        if (k == 1639) {
            if (v) {
                self->m_flags |= 2;
            }
        }
    }
}

// FUNCTION: GAME 0x2980E8
extern "C" void func_002980E8()
{
    func_00297B40(D_Ev586AF0, (void *)func_00298110);
}

// FUNCTION: GAME 0x298110
extern "C" void func_00298110(EvObj *self, int, int n)
{
    if (self) {
        switch (self->m_kind) {
        case 1541:
            if (n >= 16) {
                setMeshDisplay__6cModelPCcb(self, D_Ev44A9B0, 0);
                setMeshDisplay__6cModelPCcb(self, D_Ev44A9B8, 1);
            }
            break;
        case 1543:
            if (n >= 16) {
                setMeshDisplay__6cModelPCcb(self, D_Ev44A9B0, 0);
            }
            break;
        }
    }
}

// FUNCTION: GAME 0x2981B0
extern "C" void func_002981B0()
{
    func_00297B40(D_Ev586AF0, (void *)func_002981D8);
}

// FUNCTION: GAME 0x2981D8
extern "C" void func_002981D8(EvObj *self, int, int n)
{
    if (self) {
        switch (self->m_kind) {
        case 1541:
            if (n >= 18) {
                setMeshDisplay__6cModelPCcb(self, D_Ev44A9D0, 0);
                setMeshDisplay__6cModelPCcb(self, D_Ev44A9D8, 1);
            }
            break;
        case 1543:
            if (n >= 18) {
                setMeshDisplay__6cModelPCcb(self, D_Ev44A9D0, 0);
            }
            break;
        }
    }
}

// FUNCTION: GAME 0x298278
extern "C" void func_00298278()
{
    func_00297B40(D_Ev586AF0, (void *)func_002982A0);
}

// FUNCTION: GAME 0x2982A0
extern "C" void func_002982A0(EvObj *self)
{
    if (self) {
        unsigned k = self->m_kind;
        int v = getCostumeNo__9cCoreSave(CoreSave);
        if (k == 1539) {
            if ((unsigned char)(v - 4) < 2) {
                self->m_flags |= 2;
            }
        }
    }
}

// FUNCTION: GAME 0x298310
extern "C" void func_00298310()
{
    func_00297B20(D_Ev586AF0, (void *)func_00298338);
}

// FUNCTION: GAME 0x298338
extern "C" void func_00298338(int a, float f)
{
    if (f == 0.0f) {
        if (a == 0 || a == 4) {
            displayScrollLayer__FUib(30, 0);
            displayScrollLayer__FUib(31, 0);
        }
    }
}

// FUNCTION: GAME 0x298388
extern "C" void func_00298388()
{
    char *d = D_Ev586AF0;
    func_00297B20(d, (void *)func_002983D0);
    func_00297B40(d, (void *)func_00298460);
}

// FUNCTION: GAME 0x2983D0
extern "C" void func_002983D0(int a, float f)
{
    switch (a) {
    case 0:
        if (f == 0.0f) {
            displayScrollLayer__FUib(30, 0);
            displayScrollLayer__FUib(31, 0);
        }
        break;
    case 13:
        if (f == 101.0f) {
            displayScrollLayer__FUib(30, 0);
            displayScrollLayer__FUib(31, 0);
        }
        break;
    }
}

struct EvQw {
    long lo, hi;
};

struct EvPk {
    EvQw *cur;
    EvQw *start;
    long x8;
    unsigned cnt;
    unsigned short tag;
};

struct EvBuf {
    char _pad[0x10000];
    EvPk pk;
};

struct EvPk2 {
    char _p[0x4080];
    EvQw *cur;
    EvQw *start;
    long x8;
    int cnt;
    char _q[0x24 - 0x14];
    int m_a4, m_a8, m_ac, m_b0;
    char _r[0x48 - 0x34];
    long m_c8;
};

extern "C" void func_002987F8();
extern "C" void func_002988A8();
extern "C" void func_00298A78();
extern "C" void func_00298C18(int);
extern "C" void func_00298EF8();
extern "C" void func_002991D8();

// FUNCTION: GAME 0x2987B0
extern "C" void func_002987B0()
{
    char *d = D_Ev586AF0;
    func_00297B20(d, (void *)func_002987F8);
    func_00297B40(d, (void *)func_002988A8);
}

// FUNCTION: GAME 0x298A50
extern "C" void func_00298A50()
{
    func_00297B40(D_Ev586AF0, (void *)func_00298A78);
}

// FUNCTION: GAME 0x298BF0
extern "C" void func_00298BF0()
{
    func_00297B20(D_Ev586AF0, (void *)func_00298C18);
}

// FUNCTION: GAME 0x298C18
extern "C" void func_00298C18(int a)
{
    if (a == 3) {
        displayScrollLayer__FUib(22, 0);
    } else {
        displayScrollLayer__FUib(22, 1);
    }
}

// FUNCTION: GAME 0x298ED0
extern "C" void func_00298ED0()
{
    func_00297B40(D_Ev586AF0, (void *)func_00298EF8);
}

// FUNCTION: GAME 0x2991B0
extern "C" void func_002991B0()
{
    func_00297B40(D_Ev586AF0, (void *)func_002991D8);
}

// FUNCTION: GAME 0x299860
extern "C" void func_00299860()
{
}

// FUNCTION: GAME 0x299868
extern "C" void func_00299868(EvBuf *self, long a, long b)
{
    EvPk *p = &self->pk;
    p->cur->lo = b;
    p->cur->hi = a;
    p->cur++;
    p->cnt++;
}

// FUNCTION: GAME 0x299348
extern "C" void func_00299348(EvBuf *self0)
{
    EvPk2 *self = (EvPk2 *)&self0->pk;
    self->m_c8 = 0;
    self->m_a8 = 0;
    self->m_ac = 0;
    self->m_b0 = 0;
    self->m_a4 = 0;
}

// FUNCTION: GAME 0x2998A0
extern "C" void func_002998A0(EvBuf *self, long a, float x, float y)
{
    EvPk *p = &self->pk;
    float *c = (float *)p->cur;
    c[0] = x;
    c[1] = y;
    p->cur->hi = a;
    p->cur++;
    p->cnt++;
}

// FUNCTION: GAME 0x2998D8
extern "C" void func_002998D8(EvBuf *self, int tag, long b)
{
    EvPk *p = &self->pk;
    EvQw *c = p->cur;
    p->tag = (unsigned char)tag;
    p->x8 = b;
    p->cnt = 0;
    p->start = c;
    p->cur = c + 1;
}

// FUNCTION: GAME 0x2999D0
extern "C" void func_002999D0(EvBuf *self, long a, long b)
{
    EvPk2 *p = (EvPk2 *)&self->pk;
    p->cur->lo = b;
    p->cur->hi = a;
    p->cur++;
    p->cnt++;
}

// FUNCTION: GAME 0x299908
extern "C" void func_00299908(EvBuf *self)
{
    EvPk *p = &self->pk;
    p->start->lo = p->cnt | ((long)p->tag << 15) | (1L << 60);
    p->start->hi = p->x8;
}
