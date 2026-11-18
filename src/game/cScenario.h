#ifndef CSCENARIO_H
#define CSCENARIO_H

class cVec;
class cMessage {
public:
    unsigned short create(unsigned int no, void *obj, unsigned char a, short b);
    void deleteMessNo(unsigned short no);
};

class cTaskWork {
public:
    void sleep(unsigned short n);
};

struct sScenarioTask {
    int m_unk0;
    cTaskWork *m_work;
};

class cOmBase {
public:
    char _pad0[0x538];
    long m_id;
    char _pad540[0x5B0 - 0x540];
    unsigned int m_flags;
};

class cObjBaseArray {
public:
    cOmBase *SearchOM(unsigned long id);
};

class cScenario {
public:
    void SetRoomExitFunc(void *func, void *arg);
    int isCamEnd();
    int isOmBreak(unsigned short room, unsigned long flag);
    void setOmBreak(unsigned long flag);
    int isEventStartOk();
    void waitEventStartOk();
    void waitCam();
    void setMess(unsigned int no);
    void waitMess();
    void setOmBreak(const char *name);
    int isOmBreak(cOmBase *om);
    int isOmBreak(const char *name);
    int isOmBreak(unsigned short room, const char *name);
    void endMess();
    void setCam(const char *name);
    void beginRoomJump(unsigned char a, unsigned char b, unsigned int c, unsigned char d);
    void beginRoomJump(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c);
    void beginRoomJumpForce(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c);

    char _pad0[0x1C];
    sScenarioTask m_task;
    char _pad24[0xEC - 0x24];
    void *m_roomExitFunc;
    void *m_roomExitArg;
    char _padF4[0x111 - 0xF4];
    unsigned char m_camWait;
    unsigned short m_messNo;
};

#endif
