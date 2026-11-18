#include "game/cDvd.h"

void KeyStop();
extern "C" void func_002009E8(int, int);
extern "C" int func_001FFA68(void *);
extern "C" int func_003244C8(int);
extern "C" int func_00399508(int);
extern "C" int func_00329298();
extern "C" int func_00201A00(void *);
extern "C" int func_00323918(int, int);
extern "C" void func_00324258(int, int, int);
extern "C" void func_00323E80(int, int, int);
extern "C" void func_00323A70(int);
extern "C" void func_002A9648(int, int, int, int);
extern "C" void *func_00200AB0(void *);
extern "C" void func_00201A80(int, int);
extern "C" void func_00201F20(int, int);
extern "C" void *memset(void *, int, unsigned int);
extern char D_00580D40[];
extern char Dvd[];
extern unsigned char D_0058503A;

struct DvdSelf {
    int *m_p;
};

struct DvdCnt {
    char _pad0[0x1104];
    int m_cnt;
    char _pad1108[4];
    unsigned char m_flag;
};

// FUNCTION: GAME 0x200638
extern "C" void func_00200638()
{
    KeyStop();
}

// FUNCTION: GAME 0x2006B0
extern "C" unsigned short func_002006B0(unsigned int a)
{
    return a;
}

// FUNCTION: GAME 0x200A90
extern "C" void func_00200A90()
{
    func_002009E8(1, 0xFFFF);
}

// FUNCTION: GAME 0x200AB0
extern "C" void *func_00200AB0(void *a)
{
    return a;
}

// FUNCTION: GAME 0x2011F8
bool cDvd::FileExist(const char *)
{
    return func_001FFA68(D_00580D40) != 0;
}

// FUNCTION: GAME 0x201228
extern "C" void func_00201228(void *, void *p)
{
    memset(p, 0, 0x88);
}

// FUNCTION: GAME 0x201788
extern "C" int func_00201788(DvdCnt *s)
{
    s->m_cnt++;
    if (s->m_cnt == 0)
        s->m_cnt = 1;
    return s->m_cnt;
}

// FUNCTION: GAME 0x2018D0
extern "C" int func_002018D0(DvdSelf *s)
{
    return func_003244C8(((int *)*(int **)s)[0x84 / 4]);
}

// FUNCTION: GAME 0x2019F8
extern "C" unsigned char func_002019F8(DvdCnt *s)
{
    return s->m_flag;
}

// FUNCTION: GAME 0x201A50
extern "C" bool func_00201A50(void *)
{
    return func_00399508(1) == 2;
}

// FUNCTION: GAME 0x201AB0
extern "C" void func_00201AB0()
{
    func_00201A80(1, 0xFFFF);
}

// FUNCTION: GAME 0x201AD0
extern "C" void func_00201AD0(char *p)
{
    p[0] = 0;
    p[1] = 0;
}

// FUNCTION: GAME 0x201F20
extern "C" void func_00201F20(int a, int b)
{
    if (b == 0xFFFF && a)
        D_0058503A = 15;
}

// FUNCTION: GAME 0x201F80
extern "C" void func_00201F80()
{
    func_00201F20(1, 0xFFFF);
}

// FUNCTION: GAME 0x201A80
extern "C" void func_00201A80(int a, int b)
{
    if (b == 0xFFFF && a)
        func_00200AB0(Dvd);
}

// FUNCTION: GAME 0x208260
extern "C" void func_00208260()
{
}

// FUNCTION: GAME 0x20D138
extern "C" int func_0020D138()
{
    return 0;
}

struct DvdSlot {
    int m_used;
    int m_id;
    int m_pad[32];
};

struct DvdMgr {
    int *m_cur;
    DvdSlot m_slot[32];
    int m_cnt;
    int m_state;
};

extern "C" void func_00201290(DvdMgr *);
extern "C" void func_00201250(DvdMgr *);
extern "C" void func_00201718(DvdMgr *);
extern "C" int func_002018D0(DvdSelf *);
extern "C" void func_002018F0(DvdMgr *);
extern "C" void func_00324008(int);
extern "C" void func_002011B0(DvdMgr *);

// FUNCTION: GAME 0x200AC0
extern "C" void func_00200AC0(DvdMgr *self)
{
    int i = 31;
    DvdSlot *s = self->m_slot;
    do {
        func_00201228(self, s);
        i--;
        s++;
    } while (i >= 0);
    self->m_cnt = 0;
    self->m_state = 0;
    self->m_cur = 0;
}

#ifdef NONMATCHING
// NONMATCHING 0x200B20: 2 words differ (compiler emits slti/bnez range check instead of beqz)
extern "C" void func_00200B20(DvdMgr *self)
{
    switch (self->m_state) {
    case 1:
        func_00201290(self);
        break;
    case 2:
        func_00201718(self);
        break;
    case 0:
    default:
        func_00201250(self);
        break;
    }
}
#endif

#ifdef NONMATCHING
// NONMATCHING 0x201018: 16 words differ (loop pointer/counter/self register assignment s0/s1/s2 permuted)
extern "C" void func_00201018(DvdMgr *self)
{
    int *cur = self->m_cur;
    int i;
    DvdSlot *s = self->m_slot;
    if (cur) {
        int v = cur[0x84 / 4];
        if (v == 0) {
            self->m_cur = 0;
        } else {
            func_00324008(v);
            func_002018F0(self);
            self->m_cur = 0;
        }
    }
    i = 31;
    do {
        func_00201228(self, s);
        i--;
        s++;
    } while (i >= 0);
    self->m_state = 0;
}
#endif

// FUNCTION: GAME 0x201718
extern "C" void func_00201718(DvdMgr *self)
{
    switch (func_002018D0((DvdSelf *)self)) {
    case 2:
        break;
    case 1:
    case 3:
        func_002018F0(self);
        self->m_state = 1;
        func_00201290(self);
        break;
    }
}

#ifdef NONMATCHING
// NONMATCHING 0x201098: 13 words differ (original keeps two pointers a0/v1, slt on pointers; ours schedules the loop differently)
int cDvd::Check(eDvdId id)
{
    DvdMgr *self = (DvdMgr *)this;
    if (id == 0)
        return 0;
    if (self->m_cur && self->m_cur[1] == id)
        return 2;
    int *p = &self->m_slot[0].m_used;
    int *q = &self->m_slot[0].m_id;
    int end = (int)&self->m_cnt;
    do {
        int u = *p;
        p += 0x22;
        if (!u)
            break;
        if (*q == id)
            return 1;
        q += 0x22;
    } while ((int)p < end);
    return 0;
}
#endif

// FUNCTION: GAME 0x2018F0
extern "C" void func_002018F0(DvdMgr *self)
{
    if (self->m_cur) {
        func_00323A70(self->m_cur[0x84 / 4]);
        self->m_cur[0x84 / 4] = 0;
        if (self->m_cur[0x7C / 4])
            func_002A9648(self->m_cur[0x7C / 4], self->m_cur[0x80 / 4], self->m_cur[0x78 / 4], 16);
        memset(self->m_cur, 0, 0x88);
        self->m_cur = 0;
    }
}

// FUNCTION: GAME 0x201840
extern "C" void func_00201840(DvdMgr *self, int *req)
{
    int h = func_00323918(0, req[0x8 / 4]);
    req[0x84 / 4] = h;
    if (h == 0) {
        memset(self->m_cur, 0, 0x88);
        self->m_cur = 0;
        self->m_state = 1;
        func_00201290(self);
    } else {
        if (req[0x70 / 4])
            func_00324258(h, req[0x70 / 4], 0);
        func_00323E80(req[0x84 / 4], req[0x74 / 4], req[0x80 / 4]);
    }
}

struct DvdCnt2 {
    int *m_cur;
    char _pad4[0x1108];
    unsigned char m_flag;
    char _pad110D[3];
    int m_wait;
};

// FUNCTION: GAME 0x201960
extern "C" unsigned char func_00201960(DvdCnt2 *s)
{
    unsigned char f;
    if (func_00329298() == 1) {
        s->m_flag = 1;
        s->m_wait = 0x5A;
    } else {
        f = s->m_flag;
        if (f == 1 && func_00201A50(s) == f && s->m_cur == 0 && func_00201A00(s) == 0) {
            if (s->m_wait == 0)
                s->m_flag = 0;
            else
                s->m_wait--;
        }
    }
    return s->m_flag;
}

#ifdef NONMATCHING
// NONMATCHING 0x2017A8: 33 words differ (original keeps slot base in s0 across the call; register allocation differs)
extern "C" DvdSlot *func_002017A8(DvdMgr *self)
{
    int i = 0;
    DvdSlot *base = self->m_slot;
    DvdSlot *r = base;
    int *q = &base->m_used;
    do {
        if (*q == 0)
            return r;
        i++;
        r++;
        q += 0x22;
    } while (i < 32);
    func_002011B0(self);
    q = &base->m_used;
    r = self->m_slot;
    int end = (int)q + 0x1100;
    do {
        if (*q == 0)
            return r;
        q += 0x22;
        r++;
    } while ((int)q < end);
    return 0;
}
#endif

#ifdef NONMATCHING
// NONMATCHING 0x200F50: 2 words differ (s1/s4 setup order: addiu s1,self,4 and addiu s4,self,0x1108 swapped)
extern "C" int func_00200F50(DvdMgr *self, int id)
{
    int r = 0;
    if (self->m_cur == 0)
        return 0;
    if (self->m_cur[1] == id) {
        int v = self->m_cur[0x84 / 4];
        if (v == 0) {
            self->m_cur = 0;
        } else {
            func_00324008(v);
            func_002018F0(self);
            self->m_cur = 0;
        }
        func_00201290(self);
        r = 1;
    } else {
        int end = (int)&self->m_state;
        int *q = &self->m_slot[0].m_id;
        DvdSlot *p = self->m_slot;
        do {
            if (*q == id) {
                func_00201228(self, p);
                r = 1;
            }
            q += 0x22;
            p++;
        } while ((int)q < end);
    }
    return r;
}
#endif

extern "C" void func_00200B20(DvdMgr *);
extern "C" void func_00201C28(void *);
extern "C" void func_00201D20(void *);
extern "C" int func_003999A8();
extern "C" int func_00323618(char *, int);
extern "C" void *Getplayer__Fv();
extern char D_0042C780[];
extern unsigned int D_00747A78[];
struct __attribute__((packed)) DvdB24 {
    char c[24];
};

// FUNCTION: GAME 0x200658
extern "C" void func_00200658()
{
    memset(D_00747A78, 0, 8);
    D_00747A78[2] &= 0xFFEFFFFF;
    *(float *)((char *)Getplayer__Fv() + 0x54C) = 30.0f;
}

// FUNCTION: GAME 0x2009B0
extern "C" void func_002009B0(char *d, char *s)
{
    *(DvdB24 *)(d + 0x1C) = *(DvdB24 *)s;
}

// FUNCTION: GAME 0x201160
void cDvd::CheckWait(eDvdId id)
{
    while (Check(id))
        func_00200B20((DvdMgr *)this);
}

// FUNCTION: GAME 0x2011B0
extern "C" void func_002011B0(DvdMgr *self)
{
    while (self->m_cur)
        func_00200B20(self);
}

// FUNCTION: GAME 0x201A00
extern "C" int func_00201A00(void *)
{
    if (func_003999A8() == 0x14) {
        int v = func_00323618(D_0042C780, 0);
        if (v) {
            func_00323A70(v);
            return 0;
        }
    }
    return 1;
}

// FUNCTION: GAME 0x201BE0
extern "C" void func_00201BE0(unsigned char *p)
{
    switch (*p) {
    case 0:
        func_00201C28(p);
        break;
    case 1:
        func_00201D20(p);
        break;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x201250
// diff: 8 words; the slot scan is strength-reduced to a pointer walk, the original keeps the i*0x88 mult.
extern "C" void func_00201250(DvdMgr *self)
{
    int i = 0;
    if (self->m_slot[0].m_used == 0) {
        while (1) {
            i = i + 1;
            if (!(i < 32))
                return;
            DvdSlot *s = self->m_slot + i;
            if (s->m_used)
                break;
        }
    }
    self->m_state = 1;
}
#endif

extern "C" void func_002D5250(int);

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
    int r = 0;
    unsigned int *t = SearchData(Sys.m_5AC, D_0042C768, 0);
    if (t && idx < *t) {
        r = 1;
        DvdJump *e = (DvdJump *)((char *)t + 4 + idx * 0x14);
        if (flag == 1) {
            m_14 = e->m_8;
        } else {
            unsigned short v = 0xFFFF;
            if ((short)e->m_8 != Sys.m_5B0)
                v = e->m_8;
            m_14 = v;
        }
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
