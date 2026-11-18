#ifndef COBJ_H
#define COBJ_H

class cObj {
public:
    void R0_scenario();
    void Release();
    void setSuspend(bool b);

    char _pad0[0x250];
    unsigned int m_flags;
    char _pad254[0x2F4 - 0x254];
    unsigned char m_act0;
    unsigned char m_act1;
    unsigned char m_act2;
    unsigned char m_act3;
};

#endif
