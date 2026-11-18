#ifndef CUSTOMIDWORK_H
#define CUSTOMIDWORK_H

struct cIDWork {
    char _pad0[0x2B];
    unsigned char m_unk2B;
    int m_flags;
    float m_offsetX;
    float m_offsetY;
    float m_posX;
    float m_posY;
    float m_scaleX;
    float m_scaleY;
    char _pad48[4];
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
    void SetLocalPosY(int);
    void SetOffsetPosX(int);
    void SetOffsetPosY(int);
    void SetOffsetPosXY(int, int);
    void SetScaleAnimNormal(float, float, unsigned short);
    void ResetScaleAnim();

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
    float m_unk60;
    float m_unk64;
    float m_unk68;
    float m_unk6C;
    float m_unk70;
    unsigned short m_unk74;
    unsigned short m_unk76;
    unsigned char m_unk78;
};

#endif
