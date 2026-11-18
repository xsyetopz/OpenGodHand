#include "game/cEventShared.h"

// FUNCTION: GAME 0x297C20
int cEvent::isPlaying() const
{
    if (!(D_00747A84 & 0x20000000))
        return 0;
    return m_state == 3;
}

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
extern "C" void func_00297B60(void *, void *)
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

// FUNCTION: GAME 0x298000
extern "C" void func_00298000(int a, int b)
{
    if (b == 0xFFFF) {
        if (a) {
            __asm__ volatile("sqc2 $vf0,32(%0)" : : "r"(Event) : "memory");
        }
    }
}

// FUNCTION: GAME 0x298038
extern "C" void func_00298038()
{
    func_00298000(1, 0xFFFF);
}
