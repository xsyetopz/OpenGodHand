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
