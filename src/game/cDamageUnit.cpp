#include "game/cDamageUnit.h"

extern "C" {
int func_001FD908(cDamageUnit *);
int func_001FCA38(sDmgNode *, int, const cMatrix &, const cVec &, float, cDamageUnit *);
int func_001FCAE8(sDmgNode *, int, const cMatrix &, const cVec &, const cVec &, float, float, cDamageUnit *);
}

#ifdef NONMATCHING
// 0x1FDAF0: only diff is 3 nops the original emits between the list-walk lw and its bnel
int cDamageUnit::AddDamageCollSphere(const cMatrix &m, const cVec &v, float r)
{
    if (!m_enabled)
        return -1;
    sDmgNode *n = m_vt->m_alloc((char *)this + m_vt->m_delta);
    if (!n)
        return -1;
    if (!func_001FD908(this))
        return -1;
    int id = func_001FCA38(n, func_001FD908(this), m, v, r, this);
    if (id == -1)
        return id;
    if (m_head) {
        sDmgNode *p = m_head;
        while (p->m_next)
            p = p->m_next;
        p->m_next = n;
        n->m_prev = p;
    } else {
        m_head = n;
    }
    return id;
}
#endif

#ifdef NONMATCHING
// 0x1FDC00: only diff is 3 nops the original emits between the list-walk lw and its bnel
int cDamageUnit::AddDamageCollCylinder(const cMatrix &m, const cVec &a, const cVec &b, float r, float h)
{
    if (!m_enabled)
        return -1;
    sDmgNode *n = m_vt->m_alloc((char *)this + m_vt->m_delta);
    if (!n)
        return -1;
    if (!func_001FD908(this))
        return -1;
    int id = func_001FCAE8(n, func_001FD908(this), m, a, b, r, h, this);
    if (id == -1)
        return id;
    if (m_head) {
        sDmgNode *p = m_head;
        while (p->m_next)
            p = p->m_next;
        p->m_next = n;
        n->m_prev = p;
    } else {
        m_head = n;
    }
    return id;
}
#endif

// FUNCTION: GAME 0x1FD668
void cDamageUnit::SetDamageCollActive(bool on)
{
    for (sDmgNode *n = m_head; n; n = n->m_next) {
        if (on == 1)
            n->m_coll->m_flags |= 2;
        else
            n->m_coll->m_flags &= ~2;
    }
}

// FUNCTION: GAME 0x1FD610
void cDamageUnit::SetDamageCollActive(int id, bool on)
{
    for (sDmgNode *n = m_head; n; n = n->m_next) {
        if (n->m_id == id) {
            if (on == 1)
                n->m_coll->m_flags |= 2;
            else
                n->m_coll->m_flags &= ~2;
            return;
        }
    }
}

// FUNCTION: GAME 0x1FD718
void cDamageUnit::SetDamageCollFlashActive(bool on, short flash)
{
    for (sDmgNode *n = m_head; n; n = n->m_next) {
        if (on == 1)
            n->m_coll->m_flags |= 2;
        else
            n->m_coll->m_flags &= ~2;
        n->m_flash = flash;
    }
}

// FUNCTION: GAME 0x1FD7B0
void cDamageUnit::SetDamageCollRadius(int id, float r)
{
    for (sDmgNode *n = m_head; n; n = n->m_next) {
        if (n->m_id == id) {
            cCollisionShape *s = n->m_coll->m_shape;
            s->m_vt->m_setRadius((char *)s + s->m_vt->m_delta, r);
            return;
        }
    }
}

// FUNCTION: GAME 0x1FD888
void cDamageUnit::SetDamageCollOffset(const cVec &v)
{
    for (sDmgNode *n = m_head; n; n = n->m_next)
        n->m_coll->m_shape->setOffsetPos(v);
}
