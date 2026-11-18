// Mid-size units in 0x1E0000-0x200000.
#include "game/cSceAtUnit.h"

class cDataHolder {
public:
    void systemInit();
};

// FUNCTION: GAME 0x1FF028
void cDataHolder::systemInit()
{
    int *s = (int *)this;
    int *q;
    int i;
    s[3] = -1;
    s[0] = 0;
    s[1] = 0;
    s[4] = 0;
    s[2] = 0;
    s[7] = 0;
    s[8] = 0xFFFF;
    s[0x4C / 4] = 0xFFFF;
    s[0x50 / 4] = 0xFFFF;
    s[0x54 / 4] = 0xFFFF;
    s[6] = 0;
    s[0x58 / 4] = 0xFFFF;
    int m = -1;
    for (i = 9, q = s + 0x48 / 4; i >= 0; i--, q--) // hoisted m and comma increment order the setup insns
        *q = m;
    s[5] = 0;
}

// FUNCTION: GAME 0x1FF710
extern "C" int func_001FF710(char *self, int v)
{
    int *p = (int *)(self + 0x4C);
    int empty = 0;
    int found = 0;
    unsigned i;
    for (i = 0; i < 4; i++) {
        if (*p == v) {
            *p = 0xFFFF;
            found = 1;
        } else if (*p == 0xFFFF) {
            empty++;
        }
        p++;
    }
    if (empty == 3 && found)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x1FC210
extern "C" int func_001FC210(char **self)
{
    signed char i;
    if (*self == 0)
        return -1;
    for (i = 0; i < 10; i++) {
        if (*(unsigned char *)(i + *self + 0x98) == 0x1F)
            break;
    }
    return i == 10 ? -1 : i;
}

struct sNode1F {
    char _pad0[0x24];
    sNode1F *m_next;
    unsigned int *m_flags;
    short m_id;
    char _pad1[2];
    short m_val;
};

// FUNCTION: GAME 0x1FD6B8
extern "C" void func_001FD6B8(char *self, int id, int set, short val)
{
    sNode1F *n = *(sNode1F **)(self + 0x3C);
    while (n) {
        if (n->m_id == id) {
            unsigned int *f = n->m_flags;
            if (set == 1)
                *f |= 2;
            else
                *f &= ~2;
            n->m_val = val;
            return;
        }
        n = n->m_next;
    }
}

struct sSaveGold1F {
    char _pad[0x20];
    int m_gold;
};

class cCoreSave {
public:
    void subGold(int);
    sSaveGold1F *m_save;
};

extern unsigned int D_00747A34;

// FUNCTION: GAME 0x1FA870
void cCoreSave::subGold(int v)
{
    if (m_save) {
        m_save->m_gold -= v;
        if (m_save->m_gold > 999999)
            m_save->m_gold = 999999;
        if (m_save->m_gold < 0)
            m_save->m_gold = 0;
        if (D_00747A34 & 0x2000000)
            m_save->m_gold = 999999;
    }
}

extern unsigned int D_00747A78;
extern unsigned int D_00747A80;

// FUNCTION: GAME 0x1F6C40
extern "C" void func_001F6C40(void *self, int on)
{
    if (on) {
        D_00747A78 |= 0x80000000;
        D_00747A78 |= 0x40000000;
        D_00747A78 |= 0x20000000;
        D_00747A78 |= 0x10000000;
        D_00747A78 |= 0x80000;
        D_00747A78 |= 0x40000;
    } else {
        D_00747A78 &= ~0x80000000;
        D_00747A78 &= ~0x40000000;
        D_00747A78 &= ~0x20000000;
        D_00747A78 &= ~0x10000000;
        D_00747A78 &= ~0x80000;
        D_00747A78 &= ~0x40000;
    }
}

// FUNCTION: GAME 0x1F6B78
extern "C" void func_001F6B78(void *self, int on)
{
    if (on) {
        D_00747A80 |= 0x4000000;
        D_00747A80 |= 0x2000000;
        D_00747A80 |= 0x40000000;
        D_00747A80 |= 0x80000000;
        D_00747A80 |= 0x200000;
        D_00747A80 |= 0x20000000;
        D_00747A80 |= 0x10000000;
        D_00747A80 |= 0x8000000;
    } else {
        D_00747A80 &= ~0x4000000;
        D_00747A80 &= ~0x2000000;
        D_00747A80 &= ~0x40000000;
        D_00747A80 &= ~0x80000000;
        D_00747A80 &= ~0x200000;
        D_00747A80 &= ~0x20000000;
        D_00747A80 &= ~0x10000000;
        D_00747A80 &= ~0x8000000;
    }
}

// FUNCTION: GAME 0x1F89A8
void cArea::AreaGetCenterPos(cVec &out)
{
    float *p = (float *)this;
    switch (((unsigned char *)this)[1]) {
    case 1:
        out.x = (p[4] + p[6] + p[8] + p[10]) * 0.25f;
        out.y = p[1];
        out.z = (p[5] + p[7] + p[9] + p[11]) * 0.25f;
        break;
    case 2:
        out.x = p[4];
        out.y = p[1];
        out.z = p[5];
        break;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1F88A8 - 20 words: type-2 case fp register choice and store order
extern "C" void func_001F88A8(char *a, cVec *c, unsigned char type, float w, float d, float h)
{
    float *p = (float *)a;
    a[0] = 1;
    a[1] = type;
    *(short *)(a + 2) = 0;
    switch (type) {
    case 1: {
        float hw = w * 0.5f;
        float hd = d * 0.5f;
        p[2] = h;
        p[1] = c->y;
        p[3] = hw;
        p[4] = c->x - hw;
        p[5] = c->z - hd;
        p[6] = c->x - hw;
        p[7] = c->z + hd;
        p[8] = c->x + hw;
        p[9] = c->z + hd;
        p[10] = c->x + hw;
        p[11] = c->z - hd;
        break;
    }
    case 2:
        p[4] = c->x;
        p[5] = c->z;
        p[2] = h;
        p[1] = c->y;
        p[3] = w * 0.5f;
        *(int *)(a + 0x2C) = 0;
        *(int *)(a + 0x18) = 0;
        *(int *)(a + 0x1C) = 0;
        *(int *)(a + 0x20) = 0;
        *(int *)(a + 0x24) = 0;
        *(int *)(a + 0x28) = 0;
        break;
    }
}
#endif

// FUNCTION: GAME 0x1FD448
extern "C" void func_001FD448(char *self)
{
    int f = *(int *)(self + 0x60);
    f &= -2;
    *(int *)(self + 0x34) = 0;
    f &= -3;
    f &= -5;
    f &= -9;
    f &= -0x11;
    f &= -0x21;
    f &= -0x81;
    f &= -0x101;
    f &= -0x201;
    *(int *)(self + 0x40) = -1;
    *(short *)(self + 0x44) = 0;
    *(int *)(self + 0x60) = f;
    float *v = (float *)(self + 0x10);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    if ((int)D_00747A78 >= 0) {
        char *o = *(char **)(self + 0x30);
        if (o) {
            float lim = v[1];
            if (*(float *)(o + 0x54C) != lim) {
                *(float *)(o + 0x54C) = *(float *)(o + 0x54C) - *(float *)(o + 0x5A8) * *(float *)((char *)&D_00747A78 - 0x64);
                char *o2 = *(char **)(self + 0x30);
                if (*(float *)(o2 + 0x54C) < lim)
                    *(float *)(o2 + 0x54C) = lim;
            }
        }
    }
}
