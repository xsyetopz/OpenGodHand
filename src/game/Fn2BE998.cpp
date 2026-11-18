#include "game/cVec.h"

class cRoomJump {
public:
    void setNextPos(unsigned short room, unsigned char n, cVec *out);
};

struct sSysRJ {
    char _pad0[0x5B4];
    unsigned short m_room;
    char _pad5B6[0x5BA - 0x5B6];
    unsigned char m_5BA;
    char _pad5BB[0x5C0 - 0x5BB];
    float m_x, m_y, m_z;
    char _pad5CC[0x5D0 - 0x5CC];
    float m_ang;
};
extern sSysRJ Sys;
extern "C" float *func_002BEB00(cRoomJump *, unsigned short, unsigned char);

// FUNCTION: GAME 0x2BE998
void cRoomJump::setNextPos(unsigned short room, unsigned char n, cVec *out)
{
    float *p = func_002BEB00(this, room, n);
    if (p) {
        Sys.m_x = p[0];
        Sys.m_y = p[1];
        Sys.m_z = p[2];
        float a = p[3];
        if (a < -3.1415927f || a > 3.1415927f)
            Sys.m_ang = a * 0.017453292f;
        else
            Sys.m_ang = a;
    } else {
        Sys.m_x = 0;
        Sys.m_y = 0;
        Sys.m_z = 0;
        Sys.m_ang = 0;
    }
    if (out) {
        float x = Sys.m_x;
        float y = Sys.m_y;
        float z = Sys.m_z;
        float a = Sys.m_ang;
        out->x = x;
        out->y = y;
        out->z = z;
        *(float *)((char *)out + 0xC) = a;
    }
    Sys.m_room = room;
    Sys.m_5BA = 0;
}
