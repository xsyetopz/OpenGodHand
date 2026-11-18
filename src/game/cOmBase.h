#ifndef COMBASE_H
#define COMBASE_H

// Offsets 0x538 (id) and 0x5B0 (flags) agree with the minimal cOmBase in cScenario.h.
// Size is 0x5B8 (unsigned long alignment pads the end); derived classes pad from there.
class cOmBase {
public:
    unsigned long canCarry();
    void setScrSollEnable(bool enable);

    char _pad0[0x538];
    unsigned long m_id;
    unsigned long m_collId;
    char _pad548[0x5B0 - 0x548];
    unsigned int m_flags;
};

#endif
