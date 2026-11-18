#ifndef CCAMERA_H
#define CCAMERA_H

class cCamera {
public:
    enum eMode { MODE_0 };

    void setMode(eMode mode);
    void resetVib();

    char _pad0[0x254];
    int m_unk254;
    int m_unk258;
    int m_unk25C;
    int m_unk260;
    unsigned char m_unk264;
    char _pad265[3];
    int m_unk268;
    int m_unk26C;
    int m_unk270;
    int m_unk274;
    unsigned char m_unk278;
};

#endif
