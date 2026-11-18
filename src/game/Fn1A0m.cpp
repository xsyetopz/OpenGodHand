#include "game/Fn17y.h"

extern "C" int irand__Fv(void);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int setObjCollision__7cOmDoor(void *);
extern "C" void func_001BBF68(void *);

// FUNCTION: GAME 0x1AEEA8
extern "C" void func_001AEEA8(char *self, short a)
{
    *(short *)(self + 0x986) = a;
    if (*(unsigned char *)(self + 0x2F5) != 1)
        return;
    if (irand__Fv() & 1) {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x14) + (int)t, 0, 0, 0, 0, 0.0f);
    } else {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x18) + (int)t, 0, 0, 0, 0, 0.0f);
    }
}

struct sD1 {
    char _p0[0x548];
    short m_548, m_54a;
    char _p54c[0x5B8 - 0x54C];
    unsigned m_5b8;
    char _p5bc[0x610 - 0x5BC];
    cVec m_610;
    char _p61c[0x624 - 0x61C];
    unsigned char m_624;
    char _p625[3];
    void *m_628;
    char _p62c[0x650 - 0x62C];
    char m_650[1];
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1A8200
// diff: 33 words, float reg order/store order of t,u and beq distance
extern "C" int func_001A8200(sD1 *s)
{
    func_001B6FB8(s);
    struct { cVec v; float w; } t, u;
    t.v.x = 2.5f;
    t.v.y = 3.7f;
    t.v.z = 0.2f;
    u.v.x = -1.25f;
    u.w = 1.0f;
    t.w = 1.0f;
    u.v.y = 0;
    u.v.z = 0;
    s->m_548 = 1;
    s->m_54a = 1;
    s->m_610 = t.v;
    setObjCollision__7cOmDoor(s);
    s->m_624 = 1;
    s->m_628 = s->m_650;
    func_001BBF68(s);
    s->m_5b8 |= 2;
    return 1;
}
#endif

extern "C" int isOpen__5cOm4f(void *);
extern "C" int func_001BDD90(void *);
extern "C" int func_001BDD98(void *);
extern "C" void setOpen__8cOmDoor2(void *);
extern "C" void setClose__8cOmDoor2(void *);

// FUNCTION: GAME 0x1A4F38
extern "C" void func_001A4F38(char *self)
{
    void *d = *(void **)(self + 0x790);
    if (!d)
        return;
    if (isOpen__5cOm4f(self) == 1) {
        if (!func_001BDD90(*(void **)(self + 0x790)) && !func_001BDD98(*(void **)(self + 0x790)))
            setOpen__8cOmDoor2(*(void **)(self + 0x790));
    }
    if (!isOpen__5cOm4f(self)) {
        if (func_001BDD90(*(void **)(self + 0x790)) == 1 && !func_001BDD98(*(void **)(self + 0x790)))
            setClose__8cOmDoor2(*(void **)(self + 0x790));
    }
}

struct V4 {
    float x, y, z, w;
};
extern char g_DmgManage[];
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" int AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff(void *, void *, void *, void *, float, float);

struct sD2 {
    char _p0[0x548];
    short m_548, m_54a;
    char _p54c[0x5B8 - 0x54C];
    unsigned m_5b8;
    char _p5bc[0x760 - 0x5BC];
    unsigned char m_760;
    char _p761;
    unsigned char m_762;
    char _p763;
    void *m_764;
    char _p768[8];
    cVec m_770;
};
extern char g_DmgManage[];
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, void *, void *, float);
extern "C" void setOpenCloseRot__5cOm4fff(void *, float, float);
extern "C" void setCloseFix__5cOm4f(void *);
extern "C" void setEventMode__5cOm4fb(void *, int);

// FUNCTION: GAME 0x1A4430
extern "C" int func_001A4430(sD2 *s)
{
    func_001B6FB8(s);
    struct { cVec v; float w; } t;
    t.v.x = 0;
    t.v.y = 0;
    t.v.z = 0.7f;
    t.w = 1.0f;
    void *d = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, s, 1);
    s->m_764 = d;
    if (d)
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(d, (char *)s + 0x80, &t, 0.5f);
    s->m_548 = 0x270F;
    s->m_54a = 0x270F;
    s->m_770 = t.v;
    setOpenCloseRot__5cOm4fff(s, 1.047197580f, -1.047197580f);
    s->m_5b8 |= 8;
    s->m_762 = 0;
    s->m_760 = 0;
    setCloseFix__5cOm4f(s);
    setEventMode__5cOm4fb(s, 1);
    return 1;
}
