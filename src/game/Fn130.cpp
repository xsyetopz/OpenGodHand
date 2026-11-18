// Helpers in 0x130000-0x140000.
#include "game/cVec.h"

class cCockMess {
public:
    void SetMessNo(unsigned short no, float a, float b, unsigned char c);
    char _pad[0x90];
    char *m_p90;
    char *m_p94;
    char *m_p98;
    int m_no;
};

// FUNCTION: GAME 0x13F238
void cCockMess::SetMessNo(unsigned short no, float a, float b, unsigned char c)
{
    if (m_no == 0xFFFF) {
        m_no = no;
        *(float *)(m_p90 + 0x38) = a;
        *(float *)(m_p90 + 0x3C) = b;
        *(unsigned char *)(m_p98 + 0x4F) = c;
    }
}

// FUNCTION: GAME 0x13F510
extern "C" void func_0013F510(char *self)
{
    int i = 0x30000;
    int *p = (int *)(self + 0xB8);
    int k;
    do {
        *(int *)((char *)p + 0x1A8) = 0;
        k = i;
        *(float *)((char *)p + 0x218) = 1.0f;
        i -= 0x10000;
        *p = 0;
        p--;
    } while (k >= 0);
    *(int *)(self + 0xA0) = 0;
    *(unsigned char *)(self + 0x358) = 0;
    *(unsigned char *)(self + 0x384) = 0;
}

class cGameObj;
class cMatrix;
class cCollisionSolidManage {
public:
    void CreateSphere(cGameObj *obj, const cMatrix &m, const cVec &v, float r);
};
extern "C" void *func_001346C8(cCollisionSolidManage *);
extern "C" void func_00134520(void *, const cMatrix &, const cVec &, float);

// FUNCTION: GAME 0x134880
void cCollisionSolidManage::CreateSphere(cGameObj *obj, const cMatrix &m, const cVec &v, float r)
{
    void *s = func_001346C8(this);
    if (s)
        func_00134520(s, m, v, r);
}

// DRAFT: GAME 0x1332D0 - 18 words: original loads each char with lb and shifts it with dsllv directly; mine adds a dsra32 sign-extend and re-loads the loop test with lbu
#ifdef NONMATCHING
class cCollisionScroll {
public:
    void SetCollEnable(const char *name, bool on);
};
extern "C" void func_001331B8(cCollisionScroll *, long, bool);

// FUNCTION: GAME 0x1332D0
void cCollisionScroll::SetCollEnable(const char *name, bool on)
{
    long key = 0;
    const signed char *q = (const signed char *)name;
    for (int i = 0; i < 8 && *q; i++, q++)
        key |= (long)*q << (i * 8);
    func_001331B8(this, key, on);
}
#endif

extern unsigned D_00747A84;

// DRAFT: GAME 0x13F558 - 19 words: original keeps one slot pointer (self + n*4) in a0/a1 copies for the 0x35C and 0xA8 stores after a mult; mine recomputes the address
#ifdef NONMATCHING
extern "C" void func_0013F558(char *self, char *obj)
{
    if (D_00747A84 & 0x20000000)
        return;
    if (*(unsigned *)(obj + 0x2F0) & 0x1000)
        return;
    unsigned n = *(unsigned char *)(self + 0x358);
    if (n < 5) {
        int *p = (int *)(self + n * 4);
        p[0x250 / 4] = (int)obj;
        p[0x35C / 4] = (int)(self + n * 0x50 + 0xC0);
        p[0xA8 / 4] = 0;
        *(unsigned char *)(self + 0x358) = *(unsigned char *)(self + 0x358) + 1;
    }
}

extern "C" void trans__7cIDBase(void *self);
extern char *CoreSave;
#endif

// DRAFT: GAME 0x13DAE0 - 2 words: original ends the CoreSave flag test with beqz+nop and a shared epilogue; mine emits beql with the lq in the delay slot
#ifdef NONMATCHING
extern "C" void func_0013DAE0(char *self)
{
    if (D_00747A84 & 0x8000000)
        return;
    if (D_00747A84 & 0x2000000)
        return;
    if (*(unsigned *)(CoreSave + 0x14) & 0x4000000) {
        trans__7cIDBase(self + 0xD0);
        trans__7cIDBase(self);
        return;
    }
}
#endif

// DRAFT: GAME 0x133330 - 7 words: original sets t3 after the beqz and uses addu t3,v1 / (x<<4)+tbl operand order; mine swaps the two addu operands and hoists the t3 init
#ifdef NONMATCHING
class cCollisionScroll2 {
public:
    void SetLayerCollEnable(unsigned char layer, bool on) __asm__("SetLayerCollEnable__16cCollisionScrollUcb");
    struct H {
        char _pad[0x28];
        unsigned short count;
    } *m_h;
    char _pad4[4];
    char *m_tbl;
    char _padC[4];
    char _pad10[4];
    char *m_ent;
};

// FUNCTION: GAME 0x133330
void cCollisionScroll2::SetLayerCollEnable(unsigned char layer, bool on)
{
    if (!m_h)
        return;
    unsigned off = 0;
    unsigned i = 0;
    for (; i < m_h->count; i++, off += 0x14) {
        char *e = off + m_ent;
        if (*(unsigned char *)((*(unsigned short *)(e + 0xC) << 4) + m_tbl + 0xD) == layer) {
            if (on)
                *(unsigned *)(e + 0x10) &= ~2u;
            else
                *(unsigned *)(e + 0x10) |= 2;
        }
    }
}
#endif

// DRAFT: GAME 0x133AA8 - 23 words: original schedules the six adds/subs interleaved with the lw flags and stores max.x, min.xyz, max.yz in that order; mine stores in a different order and is one nop short
#ifdef NONMATCHING
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);

class cFn130Box {
public:
    char _pad0[8];
    unsigned m_flags;
    char _padC[4];
    float m_min[3];
    char _pad1C[4];
    float m_max[3];
    char _pad2C[0x40 - 0x2C];
    float *m_mat;
    char _pad44[0xC];
    float m_in[4];
    float m_out[4];
    float m_r;
};

// FUNCTION: GAME 0x133AA8
extern "C" void func_00133AA8(cFn130Box *b)
{
    sceVu0ApplyMatrix(b->m_out, b->m_mat, b->m_in);
    float r = b->m_r;
    b->m_max[0] = b->m_out[0] + r;
    b->m_flags &= ~3u;
    b->m_min[0] = b->m_out[0] - r;
    b->m_min[1] = b->m_out[1] - r;
    b->m_min[2] = b->m_out[2] - r;
    b->m_max[1] = b->m_out[1] + r;
    b->m_max[2] = b->m_out[2] + r;
}
#endif
