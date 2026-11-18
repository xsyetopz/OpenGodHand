#ifndef CDAMAGEUNIT_H
#define CDAMAGEUNIT_H

struct sDmgColl {
    unsigned int m_flags;
};

struct sDmgNode {
    char _pad0[0x24];
    sDmgNode *m_next;
    sDmgColl *m_coll;
    short m_id;
    char _pad2E[2];
    short m_flash;
};

class cDamageUnit {
public:
    void SetDamageCollActive(int id, bool on);
    void SetDamageCollActive(bool on);
    void SetDamageCollFlashActive(bool on, short flash);

    char _pad0[0x3C];
    sDmgNode *m_head;
};

#endif
