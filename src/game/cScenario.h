#ifndef CSCENARIO_H
#define CSCENARIO_H

class cVec;
class cMessage {
public:
    void deleteMessNo(unsigned short no);
};

class cScenario {
public:
    void SetRoomExitFunc(void *func, void *arg);
    int isCamEnd();
    int isOmBreak(unsigned short room, unsigned long flag);
    void setOmBreak(unsigned long flag);
    void endMess();
    void setCam(const char *name);
    void beginRoomJump(unsigned char a, unsigned char b, unsigned int c, unsigned char d);
    void beginRoomJump(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c);
    void beginRoomJumpForce(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c);

    char _pad0[0xEC];
    void *m_roomExitFunc;
    void *m_roomExitArg;
    char _padF4[0x111 - 0xF4];
    unsigned char m_camWait;
    unsigned short m_messNo;
};

#endif
