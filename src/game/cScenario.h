#ifndef CSCENARIO_H
#define CSCENARIO_H

#include "game/cMessage.h"
#include "game/cTaskWork.h"

class cVec;
class cPlCamera {
public:
    void setCamUpdate(unsigned int on);
};
class cCamManager : public cPlCamera {
public:
    void setPlCamera(unsigned char on);
};
class pl00 {
public:
    void clearMotionCam(unsigned int a, unsigned int b);
    char _pad0[0x54A];
    short m_x54A;
};


struct sScenarioTask {
    int m_unk0;
    cTaskWork *m_work;
};

class cOmBase {
public:
    char _pad0[0x250];
    unsigned int m_f250;
    char _pad254[0x2FE - 0x254];
    unsigned short m_kind;
    char _pad300[0x538 - 0x300];
    long m_id;
    char _pad540[0x5B0 - 0x540];
    unsigned int m_flags;
    char _pad5B4[4];
    unsigned int m_flags2;
};

struct sOmVec {
    int m_unk0;
    cOmBase **m_begin;
    cOmBase **m_end;
};

class cObjBaseArray {
public:
    cOmBase *SearchOM(unsigned long id);
    sOmVec *m_vec;
};

struct sSaveManager;
struct sVec4 {
    float x, y, z, w;
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
    void resetCam();
    void endExtraGame();
    void setOmSuspend(bool on);
    void endMess();
    void setCam(const char *name);
    void beginRoomJump(unsigned char a, unsigned char b, unsigned int c, unsigned char d);
    void beginRoomJump(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c);
    void beginRoomJumpForce(unsigned short room, const cVec &pos, float ang, unsigned char a, unsigned int b, unsigned char c);

    sVec4 m_jumpPos;
    float m_jumpAng;
    unsigned char m_jumpPending;
    char _pad15;
    unsigned short m_jumpRoom;
    char _pad18[0x1C - 0x18];
    sScenarioTask m_task;
    char _pad24[0xEC - 0x24];
    void *m_roomExitFunc;
    void *m_roomExitArg;
    char _padF4[0x111 - 0xF4];
    unsigned char m_camWait;
    unsigned short m_messNo;
};

#endif
