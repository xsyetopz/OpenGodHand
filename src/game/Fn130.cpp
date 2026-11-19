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

// FUNCTION: GAME 0x1332D0
class cCollisionScroll {
public:
    void SetCollEnable(const char *name, bool on);
};
extern "C" void func_001331B8(cCollisionScroll *, long, bool);

void cCollisionScroll::SetCollEnable(const char *name, bool on)
{
    long key = 0;
    int i = 0;
    if (*name)
        do {
            key |= (long)*name << (i * 8);
            name++;
            i++;
        } while (i < 8 && *name);
    func_001331B8(this, key, on);
}

extern unsigned D_00747A84;

// DRAFT: GAME 0x13F558 - 16 words, 108 vs 116 bytes: original keeps the slot pointer in v0 and copies it to a0 (0xA8 store) and a1 (0x35C store); mine emits no copies. Tried: separate pointer locals (q=p, s1/s2/s3 copies), int slot arithmetic (21 words), n*0x50 hoisted temp, unsigned off = n<<2, store orders 0x250/0x35C/0xA8 and 0x250/0xA8/0x35C.
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
        p[0x35C / 4] = (int)(self + (n * 0x50 + 0xC0));
        p[0xA8 / 4] = 0;
        *(unsigned char *)(self + 0x358) = *(unsigned char *)(self + 0x358) + 1;
    }
}

extern "C" void trans__7cIDBase(void *self);
extern char *CoreSave;
#endif

// FUNCTION: GAME 0x133330
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

void cCollisionScroll2::SetLayerCollEnable(unsigned char layer, bool on)
{
    if (!m_h)
        return;
    unsigned i = 0;
    for (; i < m_h->count; i++) {
        char *e = (char *)(i * 0x14 + (int)m_ent);
        if (*(unsigned char *)((*(unsigned short *)(e + 0xC) << 4) + (int)m_tbl + 0xD) == layer) {
            if (on)
                *(unsigned *)(e + 0x10) &= ~2u;
            else
                *(unsigned *)(e + 0x10) |= 2;
        }
    }
}
