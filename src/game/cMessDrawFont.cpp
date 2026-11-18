#include "game/cMessDrawFont.h"

// FUNCTION: GAME 0x2AF628
void cMessDrawFont::setBodyData(const unsigned short *a, const unsigned short *b, const unsigned short *c)
{
    m_body = a;
    m_body2 = b;
    m_body3 = c;
}

// FUNCTION: GAME 0x2AF638
void cMessDrawFont::setRubyData(const unsigned short *a, const unsigned short *b)
{
    m_ruby = a;
    m_ruby2 = b;
}

// FUNCTION: GAME 0x2AF648
void cMessDrawFont::setDrawCounter(int a, int b)
{
    m_counter0 = a;
    m_counter1 = b;
}

// FUNCTION: GAME 0x2AF658
void cMessDrawFont::setDrawPos(float x, float y, eMessDrawFontPosAttr attr)
{
    m_x = x;
    m_y = y;
    m_attr = attr;
}
