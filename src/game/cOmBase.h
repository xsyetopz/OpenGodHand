#ifndef COMBASE_H
#define COMBASE_H

class cObj;
void ReleaseObj(cObj *obj);

// Offsets 0x538 (id) and 0x5B0 (flags) agree with the minimal cOmBase in cScenario.h.
// Size is 0x5B8 (unsigned long alignment pads the end); derived classes pad from there.
class cOmBase {
public:
    unsigned long canCarry();
    void dieCommon();
    void setScrSollEnable(bool enable);

    char _pad0[0x2F4];
    unsigned char m_mode2F4;
    unsigned char m_mode2F5;
    unsigned char m_mode2F6;
    unsigned char m_mode2F7;
    char _pad2F8[0x538 - 0x2F8];
    unsigned long m_id;
    unsigned long m_collId;
    char _pad548[0x5B0 - 0x548];
    unsigned int m_flags;
};

#endif
