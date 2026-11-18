#ifndef PL00_H
#define PL00_H

#include "game/cVec.h"

// Minimal player layout; base classes (cPlBase, cGameObj) are owned elsewhere.
class pl00 {
public:
    void SetCannonReflect(unsigned char v);
    int ckMotionCam();
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

    char _pad000[0xB0];
    cVec m_unkB0;
    char _padBC[0xF0 - 0xBC];
    cVec *m_pos;                // 0x0F0
    char _pad0F4[0x278 - 0xF4];
    struct cHolder *m_unk278;
    char _pad27C[0x2B4 - 0x27C];
    unsigned char m_unk2B4;
    char _pad2B5[0x2F4 - 0x2B5];
    unsigned char m_modeA;      // 0x2F4
    unsigned char m_modeB;      // 0x2F5
    unsigned char m_modeC;      // 0x2F6
    unsigned char m_modeD;      // 0x2F7
    char _pad2F8[0x490 - 0x2F8];
    cVec m_unk490;
    char _pad49C[0x54A - 0x49C];
    short m_unk54A;
    float m_unk54C;
    char _pad550[0x5FC - 0x550];
    int m_unk5FC;
    char _pad600[0x640 - 0x600];
    struct cVObj *m_unk640;
    struct cEffObj *m_unk644;
    char m_unk648;
    char _pad649[0x660 - 0x649];
    cVec m_unk660;
    char _pad66C[4];
    float m_unk670;
    char _pad674[0x68C - 0x674];
    struct cFlagObj *m_unk68C;
    char _pad690[0x698 - 0x690];
    void *m_unk698;
    char _pad69C[0x6A0 - 0x69C];
    int m_unk6A0;
    char _pad6A4[0x15F4 - 0x6A4];
    int m_unk15F4;
    char _pad15F8[0x1644 - 0x15F8];
    unsigned int m_unk1644[5];
    char _pad1658[0x165C - 0x1658];
    void *m_unk165C;
    int m_unk1660[8];
    short m_unk1680[2];
};

#endif
