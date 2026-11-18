#include "cDvdDecl.h"

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

extern "C" void func_002D5250(int);
