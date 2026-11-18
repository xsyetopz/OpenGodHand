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

// FUNCTION: GAME 0x295B38
int cEmWrap::release()
{
    if (func_00295978(this) == 0) {
        return 0;
    }
    cEmBase *e = m_em;
    if (e != 0) {
        return g_EmManage.ReleaseEm(e);
    }
    return 0;
}

// FUNCTION: GAME 0x2959B0
void cEmWrap::setPos(const cVec &p)
{
    if (func_00295978(this)) {
        m_em->vcall(0x70, &p);
        calcParts__6cModel(m_em);
    }
}

// FUNCTION: GAME 0x295A08
void cEmWrap::setPos(const cVec &p, float f)
{
    if (func_00295978(this)) {
        cEmBase *em = m_em;
        em->vcall(0x70, &p);
        cVEnt *t = em->m_vt + 15;
        short d = t->delta;
        float v[4];
        v[0] = 0.0f;
        v[1] = f;
        v[2] = 0.0f;
        v[3] = 1.0f;
        t->fn((char *)em + d, v);
        calcParts__6cModel(m_em);
    }
}

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

// FUNCTION: GAME 0x295F28
int cEmWrap::CkActive()
{
    if (func_00295978(this) == 0) {
        return 0;
    }
    if (strcmp(D_0044A870, m_em->m_name) == 0) {
        return func_0026ECC0(m_em);
    }
    return 0;
}

extern "C" void setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(cEmBase *, const cVec *, EM00_GOTO_TYPE, unsigned, float);
extern "C" int func_0026EA28(cEmBase *);
extern "C" void func_0026E7A8(cEmBase *, const cVec *);
extern "C" void func_0026E7A0(cEmBase *, float);
extern "C" void func_002736F8(cEmBase *);
extern "C" void func_00289028(cEmBase *);
extern "C" void SetEscPos__5cEma2RC4cVec(cEmBase *, const cVec *);
extern "C" void setAlphaMode__5cEm00b(cEmBase *, int);
extern char D_0044A878[];

// FUNCTION: GAME 0x295BC0
void cEmWrap::setSuspend(bool b)
{
    if (func_00295978(this)) {
        m_em->vcallI(0x60, b);
    }
}

// FUNCTION: GAME 0x295F80
void cEmWrap::setGoto(const cVec &p, EM00_GOTO_TYPE t, unsigned u, float f)
{
    if (func_00295978(this)) {
        if (m_em->m_vital > 0) {
            if (strcmp(D_0044A870, m_em->m_name) == 0) {
                setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(m_em, &p, t, u, f);
            }
        }
    }
}

// FUNCTION: GAME 0x296018
int cEmWrap::ckGoto()
{
    if (func_00295978(this) == 0) {
        return 0;
    }
    if (strcmp(D_0044A870, m_em->m_name) == 0) {
        return func_0026EA28(m_em);
    }
    return 0;
}

// FUNCTION: GAME 0x296070
void cEmWrap::SetKeepPos(const cVec &p)
{
    if (func_00295978(this)) {
        if (strcmp(D_0044A870, m_em->m_name) == 0) {
            func_0026E7A8(m_em, &p);
        }
    }
}

// FUNCTION: GAME 0x2960D0
void cEmWrap::SetKeepLength(float f)
{
    if (func_00295978(this)) {
        if (strcmp(D_0044A870, m_em->m_name) == 0) {
            func_0026E7A0(m_em, f);
        }
    }
}

// FUNCTION: GAME 0x296130
void cEmWrap::clearNoMove()
{
    if (func_00295978(this)) {
        if (strcmp(D_0044A870, m_em->m_name) == 0) {
            func_002736F8(m_em);
        }
    }
}

// FUNCTION: GAME 0x296180
void cEmWrap::StartEscape()
{
    if (func_00295978(this)) {
        if (strcmp(D_0044A878, m_em->m_name) == 0) {
            func_00289028(m_em);
        }
    }
}

// FUNCTION: GAME 0x2961D0
void cEmWrap::SetEscPos(const cVec &p)
{
    if (func_00295978(this)) {
        if (strcmp(D_0044A878, m_em->m_name) == 0) {
            SetEscPos__5cEma2RC4cVec(m_em, &p);
        }
    }
}

// FUNCTION: GAME 0x296230
void cEmWrap::setAlphaMode(bool b)
{
    if (func_00295978(this)) {
        if (strcmp(D_0044A870, m_em->m_name) == 0) {
            setAlphaMode__5cEm00b(m_em, b);
            if (!b) {
                m_em->m_alphaTimer = 0x1770;
            } else {
                m_em->m_alphaTimer = 0x258;
            }
        }
    }
}
