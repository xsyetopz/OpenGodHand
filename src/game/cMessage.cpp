#include "game/cMessage.h"

// FUNCTION: GAME 0x2AEDA0
bool cMessage::ckMessage(unsigned short no)
{
    return func_002AED40(this, no) != 0;
}

#ifdef NONMATCHING
// 0x2AEAD0 NEAR-MISS: 1 word: addu operand order (original addu a1,v1,a1; ours a1,a1,v1)
char *cMessage::getMessageAddr(unsigned short no) const
{
    char *base = m_table[no >> 12];
    return base + *(int *)(base + (no & 0xFFF) * 8 + 4);
}
#endif

// FUNCTION: GAME 0x2AED10
cMessageNode *cMessage::searchWorkId(unsigned short id) const
{
    for (cMessageNode *n = m_list; n; n = n->m_next) {
        if (n->m_workId == id)
            return n;
    }
    return 0;
}

#ifdef NONMATCHING
// 0x2AECD0 NEAR-MISS: original has an extra nop before the bnez loop branch (60 vs 64 bytes); -Wa,-g no help
void cMessage::closeAll()
{
    for (cMessageNode *n = m_list; n; n = n->m_next)
        func_002B2400(n);
}
#endif

#ifdef NONMATCHING
// 0x2AEC88 NEAR-MISS: original has two nops before bnez (64 vs 72 bytes)
void cMessage::deleteAll()
{
    cMessageNode *n = m_list;
    while (n)
        n = func_002AEF10(this, n);
}
#endif
