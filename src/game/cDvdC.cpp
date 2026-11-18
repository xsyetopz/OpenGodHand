#include "cDvdDecl.h"

// FUNCTION: GAME 0x201108
extern "C" void func_00201108(cDvd *d, eDvdId id)
{
    while (d->Check(id))
        func_002D5250(1);
    func_002D5250(1);
}

class cRoomJump {
public:
    cRoomJump();
    void setTblAddr(unsigned int *p);
};
inline void *operator new(unsigned, void *p) { return p; }
extern unsigned int *D_00747A44;
extern "C" float *func_002BEB00(cRoomJump *, unsigned short, unsigned char);
class cDoor {
public:
    char _p0[4];
    float m_jp[4];
    unsigned short m_14;
    unsigned char m_16;
    unsigned char m_17;
    int m_18;
    float m_pos[3];
    float m_rot;
    unsigned short m_id;
    unsigned char m_f;
    char _p1[0x34 - 0x2F];
    cRoomJump m_rj;
    char _p2[0x3A - 0x34 - 1];
    unsigned char m_3A;
    void setCasinoJumpPoint(unsigned short, unsigned char);
    bool getJumpData(unsigned char, unsigned char, unsigned char, bool, unsigned char);
};
extern cDoor Door;
struct DvdV4 {
    float x, y, z, w;
};
extern DvdV4 CasinoPos[2];

// FUNCTION: GAME 0x2008B8
void cDoor::setCasinoJumpPoint(unsigned short id, unsigned char f)
{
    m_rj.setTblAddr(D_00747A44);
    float *v = func_002BEB00(&m_rj, id, f);
    if (v) {
        m_pos[0] = v[0];
        m_pos[1] = v[1];
        m_pos[2] = v[2];
        if (v[3] < -3.1415927f || v[3] > 3.1415927f)
            m_rot = v[3] * 0.017453292f;
        else
            m_rot = v[3];
    } else {
        m_pos[0] = 0;
        m_pos[1] = 0;
        m_pos[2] = 0;
        m_rot = 0;
    }
    m_id = id;
    m_f = 0xFF;
}

// FUNCTION: GAME 0x2009E8
extern "C" void func_002009E8(int a, int b)
{
    if (b == 0xFFFF && a) {
        cDoor *d = &Door;
        new (&d->m_rj) cRoomJump;
        DvdV4 *q = CasinoPos;
        q->x = 0.66f;
        q->y = 0.01f;
        q->z = -52.4f;
        q->w = 1.0f;
        q++;
        q->x = -48.0f;
        q->y = 0.25f;
        q->z = -57.3f;
        q->w = 1.0f;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x201C28
// diff: 1 word; original tests D_00747A24 bit 3 as `lw; dsrl 3` (64-bit shift), ours emits `srl`/`sra`.
#include "game/cWorldTime.h"
class cScenario {
public:
    void debugPrint(const char *, ...);
};
extern cScenario *g_Sce;
extern cWorldTime WorldTime;
extern const char D_0042C7D0[];
extern int D_00747A24;
struct DvdSysX {
    char _p[0x58C];
    int m_58C;
    char _p1[0x5B0 - 0x590];
    unsigned short m_5B0;
    char _p2[0x5E4 - 0x5B2];
    unsigned int m_5E4;
};
extern DvdSysX Sys;
class cE3 {
public:
    char m_0;
    char m_1;
    signed char m_2;
    char m_3;
    void setEnding(bool);
};
extern "C" void func_00201C28(cE3 *self)
{
    if (Sys.m_5B0 == 0x20)
        return;
    unsigned int fl = Sys.m_5E4;
    if (!(fl & 0x4000)) {
        if (fl & 0x2000000)
            return;
    }
    if (Sys.m_58C < 0)
        return;
    if (self->m_2 > 0) {
        unsigned int h;
        WorldTime.getGlobalHMS(0, &h, 0);
        if (h >= self->m_2)
            self->setEnding(true);
        int d = self->m_2 * 0x708 - WorldTime.m_globalTime;
        g_Sce->debugPrint(D_0042C7D0, d);
    }
    if (((unsigned long)D_00747A24 >> 3) & 1)
        self->setEnding(true);
}
#endif

extern "C" DvdSlot *func_002017A8(DvdMgr *);
extern "C" int func_001FF9C0(char *, char *, int *, int *);

// FUNCTION: GAME 0x200B88
extern "C" int func_00200B88(DvdMgr *self, char *name, unsigned int size, int id, unsigned int sz2, int a6, int a7)
{
    if (size & 0x3F)
        size = (size + 0x3F) & 0xFFFFFFC0;
    int *req = (int *)func_002017A8(self);
    if (!req)
        return 0;
    req[2] = func_001FF9C0(D_00580D40, name, &req[0x78 / 4], &req[0xC / 4]);
    req[0x74 / 4] = (unsigned int)(req[0x78 / 4] + 0x7FF) >> 11;
    req[0x7C / 4] = 0;
    if (req[2] < 0)
        return 0;
    req[0] = 1;
    if (id == 0)
        req[1] = func_00201788((DvdCnt *)self);
    else
        req[1] = id;
    req[0x80 / 4] = size;
    req[0x6C / 4] = a7;
    req[0x70 / 4] = a6;
    if (sz2)
        req[0x74 / 4] = (sz2 + 0x7FF) >> 11;
    if (self->m_cur == 0)
        func_00201290(self);
    return req[1];
}

struct DvdSys2 {
    char _p[0x5AC];
    unsigned int *m_5AC;
    unsigned short m_5B0;
};
extern DvdSys2 Sys;
extern const char D_0042C768[];
unsigned int *SearchData(unsigned int *, const char *, unsigned int);
struct DvdJump {
    short x, y, z, r;
    unsigned short m_8;
    unsigned char m_a;
};

// FUNCTION: GAME 0x2004C8
bool cDoor::getJumpData(unsigned char idx, unsigned char b, unsigned char c, bool flag, unsigned char d)
{
    unsigned int *t = SearchData(Sys.m_5AC, D_0042C768, 0);
    int r = 0;
    if (t && idx < *t) {
        DvdJump *e = (DvdJump *)((char *)t + 4 + idx * 0x14);
        if (flag == 1) {
            m_14 = e->m_8;
        } else {
            m_14 = ((short)e->m_8 == Sys.m_5B0) ? 0xFFFF : e->m_8;
        }
        r = 1;
        m_jp[0] = e->x * 0.01f;
        m_jp[1] = e->y * 0.01f;
        m_jp[2] = e->z * 0.01f;
        m_jp[3] = e->r * 0.017453292f;
        m_16 = e->m_a;
        m_17 = b;
        m_18 = c;
        m_3A = d;
    }
    return r;
}

class cHeap;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
extern "C" void func_00201228(void *, void *);

// FUNCTION: GAME 0x200DF8
extern "C" int func_00200DF8(DvdMgr *self, char *name, void **out, cHeap *heap, int id, unsigned int *sizeOut, int a7, int a6)
{
    *out = 0;
    int *req = (int *)func_002017A8(self);
    if (!req)
        return 0;
    req[2] = func_001FF9C0(D_00580D40, name, &req[0x78 / 4], &req[0xC / 4]);
    req[0x74 / 4] = (unsigned int)(req[0x78 / 4] + 0x7FF) >> 11;
    req[0x7C / 4] = (int)heap;
    if (req[2] < 0)
        return 0;
    req[0] = 1;
    if (id == 0)
        req[1] = func_00201788((DvdCnt *)self);
    else
        req[1] = id;
    req[0x6C / 4] = a6;
    req[0x70 / 4] = a7;
    req[0x80 / 4] = 0;
    req[0x80 / 4] = (int)_MemoryAlloc(req[0x74 / 4] << 11, 0x80, *heap);
    if (req[0x80 / 4] == 0) {
        func_00201228(self, req);
        return 0;
    }
    if (sizeOut)
        *sizeOut = req[0x74 / 4] << 11;
    *out = (void *)req[0x80 / 4];
    if (self->m_cur == 0)
        func_00201290(self);
    return req[1];
}
