#ifndef CUSTOMIDWORK_H
#define CUSTOMIDWORK_H

struct cIDWork {
    char _pad0[0x2B];
    unsigned char m_unk2B;
    unsigned int m_flags;
    float m_offsetX;
    float m_offsetY;
    float m_posX;
    float m_posY;
    char _pad40[0xC];
    int m_unk4C;
    char _pad50[0x34];
    int m_number;
    char _pad88[0x8];
    short m_messNo;
};

class CustomIDWork {
public:
    CustomIDWork();
    void Initialize(cIDWork *work);
    void SetDisp(bool);
    void SetChildNoDisp(bool);
    void SetNumber(int);
    void SetMessNo(int);
    void SetLocalPosX(int);
    void SetLocalPosXY(int, int);
    void ResetMoveOffsetPos();
    void ResetColorAnim();

    int m_unk0;
    cIDWork *m_work;
    int m_unk8;
    float m_unkC;
    float m_unk10;
    char _pad14[0x14];
    int m_unk28;
    char _pad2C[0x1C];
    int m_unk48;
    int m_unk4C;
    char _pad50[0xC];
    int m_unk5C;
    char _pad60[0x18];
    unsigned char m_unk78;
};

#endif
