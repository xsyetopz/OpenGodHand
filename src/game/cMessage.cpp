#include "game/cMessage.h"

// FUNCTION: GAME 0x2AEDA0
bool cMessage::ckMessage(unsigned short no)
{
    return func_002AED40(this, no) != 0;
}

// FUNCTION: GAME 0x2AEAD0
char *cMessage::getMessageAddr(unsigned short no) const
{
    char *base = m_table[no >> 12];
    int *e = (int *)base + (no & 0xFFF) * 2;
    return base + e[1];
}

// FUNCTION: GAME 0x2AED10
cMessageNode *cMessage::searchWorkId(unsigned short id) const
{
    for (cMessageNode *n = m_list; n; n = n->m_next) {
        if (n->m_workId == id)
            return n;
    }
    return 0;
}

// 0x2AECD0: differs only by the assembler hazard nop between the next-pointer load and the loop branch
#ifdef NONMATCHING
void cMessage::closeAll()
{
    cMessageNode *n = m_list;
    if (n) {
        do {
            func_002B2400(n);
            n = n->m_next;
        } while (n);
    }
}
#endif

// 0x2AEC88: differs only by two assembler nops after the call
#ifdef NONMATCHING
void cMessage::deleteAll()
{
    cMessageNode *n = m_list;
    if (n) {
        do {
            n = func_002AEF10(this, n);
        } while (n);
    }
}
#endif

// FUNCTION: GAME 0x2AEBF8
int cMessage::deleteWorkId(unsigned short id)
{
    cMessageNode *n = searchWorkId(id);
    if (!n)
        return 0;
    func_002AEF10(this, n);
    return 1;
}

// FUNCTION: GAME 0x2AEC40
int cMessage::deleteMessNo(unsigned short no)
{
    cMessageNode *n = func_002AED40(this, no);
    if (!n)
        return 0;
    func_002AEF10(this, n);
    return 1;
}

// FUNCTION: GAME 0x2AED70
int cMessage::closeMessNo(unsigned short no)
{
    cMessageNode *n = func_002AED40(this, no);
    if (!n)
        return 0;
    func_002B2400(n);
    return 1;
}

// FUNCTION: GAME 0x2AEB00
char *cMessage::getRubyAddr(unsigned short no) const
{
    if (!D_00747A0C) {
        char *base = m_table[no >> 12];
        int *e = (int *)base + (no & 0xFFF) * 2;
        int off = e[2];
        if (off)
            return base + off;
        return 0;
    }
    return 0;
}
