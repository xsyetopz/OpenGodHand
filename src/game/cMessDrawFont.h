#ifndef CMESSDRAWFONT_H
#define CMESSDRAWFONT_H

enum eMessDrawFontPosAttr { MESSDRAWFONT_POS_0 };

class cMessDrawFont {
public:
    void setBodyData(const unsigned short *a, const unsigned short *b, const unsigned short *c);
    void setRubyData(const unsigned short *a, const unsigned short *b);
    void setDrawCounter(int a, int b);
    void setDrawPos(float x, float y, eMessDrawFontPosAttr attr);

    char _pad0[4];
    const unsigned short *m_body;
    const unsigned short *m_ruby;
    const unsigned short *m_body2;
    const unsigned short *m_body3;
    const unsigned short *m_ruby2;
    int m_counter0;
    int m_counter1;
    float m_x;
    float m_y;
    eMessDrawFontPosAttr m_attr;
};

#endif
