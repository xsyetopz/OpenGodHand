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
