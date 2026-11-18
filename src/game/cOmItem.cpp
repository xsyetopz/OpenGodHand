#include "game/cOmItem.h"

// FUNCTION: GAME 0x1C25A0
void cOmItem::setGetRangeLong(bool on)
{
    if (on == 1)
        m_itemFlags |= 4;
    else
        m_itemFlags &= 0xFB;
}

// FUNCTION: GAME 0x1C25C8
void cOmItem::setScrCheck(bool on)
{
    if (on == 1)
        m_itemFlags |= 1;
    else
        m_itemFlags &= 0xFE;
}

// 0x1C2558: char -> long shift compiles to lbu+dsll32/dsra32 instead of the original lb+dsllv; loop shape also differs
#ifdef NONMATCHING
void cOmItem::setBlockObj(const char *name)
{
    long id = 0;
    int i = 0;
    while (*name) {
        long c = *name;
        id |= c << (i * 8);
        i++;
        name++;
        if (i >= 8)
            break;
    }
    m_blockObj = id;
}
#endif
