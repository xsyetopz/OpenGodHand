#ifndef CDAMAGEUNIT_H
#define CDAMAGEUNIT_H

class cVec;
class cMatrix;
class cCollisionShape;

struct sShapeVTable {
    char _pad0[0x18];
    short m_delta;
    char _pad1A[2];
    void (*m_setRadius)(void *, float);
};

class cCollisionShape {
public:
    void setOffsetPos(const cVec &v);

    char _pad0[0x100];
    sShapeVTable *m_vt;
};

struct sDmgColl {
    unsigned int m_flags;
    char _pad4[0x34 - 4];
    cCollisionShape *m_shape;
};

struct sDmgNode {
    char _pad0[0x20];
    sDmgNode *m_prev;
    sDmgNode *m_next;
    sDmgColl *m_coll;
    short m_id;
    char _pad2E[2];
    short m_flash;
};

struct sDmgUnitVTable {
    char _pad0[0x10];
    short m_delta;
    char _pad12[2];
    sDmgNode *(*m_alloc)(void *);
};

class cDamageUnit {
public:
    void SetDamageCollActive(int id, bool on);
    void SetDamageCollActive(bool on);
    int AddDamageCollSphere(const cMatrix &m, const cVec &v, float r);
    int AddDamageCollCylinder(const cMatrix &m, const cVec &a, const cVec &b, float r, float h);
    void SetDamageCollRadius(int id, float r);
    void SetDamageCollOffset(const cVec &v);
    void SetDamageCollFlashActive(bool on, short flash);

    char _pad0[0x3C];
    sDmgNode *m_head;
    char _pad40[0x49 - 0x40];
    char m_enabled;
    char _pad4A[0x50 - 0x4A];
    sDmgUnitVTable *m_vt;
};

#endif
