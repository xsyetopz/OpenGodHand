#include "game/cEmWrap.h"

extern "C" int func_00295978(cEmWrap *);
extern "C" void func_0028FB08(cEmBase *);
extern cVec ZeroVec;

// FUNCTION: GAME 0x295AB8
const cVec *cEmWrap::getPos()
{
    if (!func_00295978(this)) {
        return &ZeroVec;
    }
    return m_em->m_pos;
}

// FUNCTION: GAME 0x295AF8
const cVec *cEmWrap::getRot()
{
    if (!func_00295978(this)) {
        return &ZeroVec;
    }
    return &m_em->m_rot;
}

// FUNCTION: GAME 0x295B80
void cEmWrap::setMutekiTimer(float t)
{
    if (func_00295978(this)) {
        m_em->m_mutekiTimer = t;
    }
}

// FUNCTION: GAME 0x295C70
void cEmWrap::setDead()
{
    if (func_00295978(this)) {
        func_0028FB08(m_em);
    }
}

// FUNCTION: GAME 0x295CA8
int cEmWrap::isDead()
{
    if (!func_00295978(this)) {
        return 1;
    }
    return m_em->checkDeadFlag();
}

// FUNCTION: GAME 0x295D30
void cEmWrap::SetVital(int v)
{
    if (func_00295978(this)) {
        if (v >= m_em->m_vitalMax) {
            m_em->m_vital = m_em->m_vitalMax;
        } else {
            m_em->m_vital = v;
        }
    }
}

// FUNCTION: GAME 0x295D88
void cEmWrap::SetVitalMax(int v)
{
    if (func_00295978(this)) {
        m_em->m_vitalMax = v;
    }
}

// FUNCTION: GAME 0x295DC8
int cEmWrap::GetVital()
{
    if (!func_00295978(this)) {
        return 0;
    }
    return m_em->m_vital;
}

// FUNCTION: GAME 0x295E00
int cEmWrap::GetVitalMax()
{
    if (!func_00295978(this)) {
        return 0;
    }
    return m_em->m_vitalMax;
}

// FUNCTION: GAME 0x295E38
void cEmWrap::setDropItem(eObjId id)
{
    if (func_00295978(this)) {
        m_em->m_dropItem = id;
    }
}

// FUNCTION: GAME 0x295EE0
void cEmWrap::SetRaderType(signed char t)
{
    if (func_00295978(this)) {
        m_em->m_raderType = t;
    }
}

extern "C" int strcmp(const char *, const char *);
extern "C" void func_00276090(cEmBase *, int);
extern "C" int func_0026ECC0(cEmBase *);
extern "C" void calcParts__6cModel(cEmBase *);
extern char D_0044A870[];
extern cEmManage g_EmManage;

#ifdef NONMATCHING
// 0x295B38: 5 words differ: original branches bnez a1 to a call block placed last; ours beqz with call inline
int cEmWrap::release()
{
    return (func_00295978(this) && m_em) ? g_EmManage.ReleaseEm(m_em) : 0;
}
#endif

// FUNCTION: GAME 0x2959B0
void cEmWrap::setPos(const cVec &p)
{
    if (func_00295978(this)) {
        m_em->vcall(0x70, &p);
        calcParts__6cModel(m_em);
    }
}

#ifdef NONMATCHING
// 0x295A08: 10 words differ: original reloads vtable into a2 right after first call, before lui/mtc1; ours schedules lw v1 later
void cEmWrap::setPos(const cVec &p, float f)
{
    if (func_00295978(this)) {
        cEmBase *em = m_em;
        em->vcall(0x70, &p);
        cVEnt *vt = em->m_vt;
        float v[4];
        v[0] = 0.0f;
        v[1] = f;
        v[2] = 0.0f;
        v[3] = 1.0f;
        vt[15].fn((char *)em + vt[15].delta, v);
        calcParts__6cModel(m_em);
    }
}
#endif

// FUNCTION: GAME 0x295C10
void cEmWrap::setLockOff(bool b)
{
    if (func_00295978(this)) {
        if (strcmp(D_0044A870, m_em->m_name) == 0) {
            func_00276090(m_em, b);
        }
    }
}

// FUNCTION: GAME 0x295CE8
void cEmWrap::StartAction()
{
    if (func_00295978(this)) {
        m_em->vcall0(0xD8);
    }
}

// FUNCTION: GAME 0x295E78
void cEmWrap::setScrCollEnable(bool b)
{
    if (func_00295978(this)) {
        if (b == 1) {
            m_em->m_flags &= ~4;
        } else {
            m_em->m_flags |= 4;
        }
    }
}

#ifdef NONMATCHING
// 0x295F28: 12 words differ (88 vs 84 bytes): original puts the func_0026ECC0 call block last, both false paths join one return-0 block
int cEmWrap::CkActive()
{
    return (func_00295978(this) && strcmp(D_0044A870, m_em->m_name) == 0) ? func_0026ECC0(m_em) : 0;
}
#endif
