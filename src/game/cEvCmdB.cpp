#include "game/cEvCmd.h"

// FUNCTION: GAME 0x2B17A8
extern "C" int func_002B17A8(cEvCmd *self)
{
    self->m_aa = 0x1E0;
    self->m_ac = 0x88;
    self->m_a6 = 0x100;
    self->m_ae = 0x100;
    self->m_a8 = 0x182;
    self->m_b0 = 0x182;
    return func_002B1C80(self);
}

// FUNCTION: GAME 0x2B1BE8
extern "C" int func_002B1BE8(cEvCmd *self)
{
    self->m_aa = 0x1E0;
    self->m_ac = 0x78;
    self->m_a6 = 0x100;
    self->m_ae = 0x100;
    self->m_a8 = 0x170;
    self->m_b0 = 0x170;
    return func_002B1C80(self);
}

// FUNCTION: GAME 0x2B1C30
extern "C" int func_002B1C30(cEvCmd *self)
{
    self->m_aa = 0x1E0;
    self->m_ac = 0x78;
    self->m_a6 = 0x100;
    self->m_ae = 0x100;
    self->m_a8 = 0x144;
    self->m_b0 = 0x144;
    return func_002B1C80(self);
}

// FUNCTION: GAME 0x2B2058
extern "C" void func_002B2058(float a, float b, float c, float d)
{
    func_002B1F80(a, b, a + c, b + d);
}

// FUNCTION: GAME 0x2B43B0
extern "C" void func_002B43B0(cEvCmd *self)
{
    if (func_002B45F8(self, self->m_data, 0xD200))
        return;
    if (func_002B45F8(self, self->m_data, 0xD900))
        return;
    if (func_002B45F8(self, self->m_data, 0xDA00))
        return;
    func_002B4428(self, 0, 0);
}

// FUNCTION: GAME 0x2B3158
extern "C" void func_002B3158(cEvCmd *self)
{
    self->m_10 = 0;
    self->m_98 = 0;
    self->m_flags |= 8;
    self->m_9c = 0;
    self->m_a0 = 0;
    func_002B45C8(self);
}

// FUNCTION: GAME 0x2B4188
extern "C" void func_002B4188(cEvCmd *self)
{
    switch (self->m_d) {
    case 0:
        func_002B41F0(self);
        self->m_d = self->m_d + 1;
    case 1:
        if (func_002B4228(self))
            func_002B42F0(self);
    }
}

// FUNCTION: GAME 0x2B2158
extern "C" void func_002B2158(cEvCmd *self, unsigned short a, unsigned char b, int c)
{
    self->m_flags |= 0x1000;
    func_002B22E0(self, c);
    self->m_2c = b;
    self->m_1c = 0;
    self->m_2d = 0;
    self->m_b2 = 0;
    self->m_2e = 0;
    self->m_44 = 0;
    self->m_4c = 0;
    self->m_50 = 0;
    self->m_20 = -1;
    self->m_30 = -1;
    func_002B21F0(self, a);
    self->m_c = 0;
    self->m_d = 0;
    self->m_e = 0;
    self->m_f = 0;
}

struct cEvView {
    char _pad0[0x1C];
    int m_1c;
    char _pad20[0x6C - 0x20];
    int m_6c;
    char _pad70[0x88 - 0x70];
    float m_88;
    float m_8c;
};

extern "C" {
unsigned short func_002B1290();
void func_002AFED0(cEvView *self, int a, int b, int c, float d, float e);
}

// FUNCTION: GAME 0x2B0420
extern "C" void func_002B0420(cEvView *self, int a)
{
    int d = self->m_1c - self->m_6c;
    func_002AFED0(self, func_002B1290(), a, d, self->m_88, self->m_8c);
}

struct cEvSlot {
    int m_first;
    char _pad4[0xAC - 4];
};

struct cEvSlotList {
    cEvSlot *m_slots;
};

static inline unsigned char isSlotUsed(cEvSlot *p)
{
    if (p->m_first)
        return 1;
    return 0;
}

extern "C" void func_002B4A50(cEvSlotList *l);

// FUNCTION: GAME 0x2B4E48
extern "C" int func_002B4E48(cEvSlotList *l)
{
    func_002B4A50(l);
    cEvSlot *p = l->m_slots;
    for (int i = 0; i < 3; i++, p++) {
        if (isSlotUsed(p) == 1)
            return 0;
    }
    return 1;
}

// FUNCTION: GAME 0x2B4F38
extern "C" int func_002B4F38(cEvSlotList *l)
{
    cEvSlot *p = l->m_slots;
    for (int i = 0; i < 3; i++, p++) {
        if (isSlotUsed(p) == 0)
            return i;
    }
    return -1;
}

struct cEvLink {
    char _pad0[4];
    struct cEvLinkList *m_list;
    cEvLink *m_head;
    cEvLink *m_prev;
    cEvLink *m_next;
};

struct cEvLinkList {
    char _pad0[8];
    cEvLink *m_first;
};

// FUNCTION: GAME 0x2B5E58
extern "C" int func_002B5E58(cEvLinkList *l)
{
    cEvLink *p = l->m_first;
    int n = 0;
    if (p) {
        n = 1;
        p = p->m_next;
        while (p) {
            p = p->m_next;
            n++;
        }
    }
    return n;
}

// FUNCTION: GAME 0x2B5E90
extern "C" cEvLink *func_002B5E90(cEvLinkList *l, int n)
{
    cEvLink *p = l->m_first;
    while (n-- != 0)
        p = p->m_next;
    return p;
}

// FUNCTION: GAME 0x2B5EC0
extern "C" void func_002B5EC0(cEvLink *self)
{
    if (self->m_list) {
        if (self->m_next)
            self->m_next->m_prev = self->m_prev;
        if (self->m_prev)
            self->m_prev->m_next = self->m_next;
        else
            self->m_list->m_first = self->m_next;
        self->m_next = 0;
        self->m_prev = 0;
        self->m_list = 0;
    }
}

// FUNCTION: GAME 0x2B5E50
extern "C" int func_002B5E50(cEvLinkList *l)
{
    return *(int *)((char *)l + 4);
}
