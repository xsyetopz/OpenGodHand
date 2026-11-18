#include "cDvdDecl.h"

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
// DRAFT: GAME 0x200B20 - 2 words: gcc emits slti/bnez range check where the target has nop/beqz
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

// FUNCTION: GAME 0x201098
int cDvd::Check(eDvdId id)
{
    DvdMgr *self = (DvdMgr *)this;
    if (id == 0)
        return 0;
    int *end = (int *)&self->m_cnt;
    if (self->m_cur && self->m_cur[1] == id)
        return 2;
    int *f = &self->m_slot[0].m_used;
    int *g = &self->m_slot[0].m_id;
    do {
        if (*f && *g == id)
            return 1;
        f += 0x22;
        g += 0x22;
    } while ((int)f < (int)end);
    return 0;
}
