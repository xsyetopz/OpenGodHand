#ifndef PL00_H
#define PL00_H

#include "game/cVec.h"

// Minimal player layout; base classes (cPlBase, cGameObj) are owned elsewhere.
class pl00 {
public:
    void SetCannonReflect(unsigned char v);
    bool ckMotionCam();
    void DiscardWeapon();
    int CkSubScreen();
    int ckAtkActBtnEnable();
    void setEventWait();
    void setJump(float v);
    void setIgnition(const cVec &pos, float v);
    void setPyramidIn();
    void lookCliff(const cVec &pos, float v);
    void SubscreenMotSet(unsigned int a);
    void CannonGameMode(unsigned int on);
    void clearMotionCam(unsigned int a, unsigned int b);
    void reset();

    char _pad000[0x2F4];
    unsigned char m_modeA;      // 0x2F4
    unsigned char m_modeB;      // 0x2F5
    unsigned char m_modeC;      // 0x2F6
    unsigned char m_modeD;      // 0x2F7
    char _pad2F8[0x54A - 0x2F8];
    short m_unk54A;
    float m_unk54C;
    char _pad550[0x660 - 0x550];
    cVec m_unk660;
    char _pad66C[4];
    float m_unk670;
    char _pad674[0x698 - 0x674];
    void *m_unk698;
    char _pad69C[0x6A0 - 0x69C];
    int m_unk6A0;
    char _pad6A4[0x15F4 - 0x6A4];
    int m_unk15F4;
};

#endif
