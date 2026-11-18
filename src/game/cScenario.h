#ifndef CSCENARIO_H
#define CSCENARIO_H

#include "game/cMessage.h"
#include "game/cTaskWork.h"
#include "game/cOmBase.h"
#include "game/cGameObj.h"

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


class cTaskManager {
public:
    int execute(void (&fn)(), int n);
    int m_unk0;
    cTaskWork *m_work;
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

struct sCallback;

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
    void move();
    void resetCam();
    int taskExec(void (&fn)(), int n);
    int taskExec(void *fn, void *arg, int n);
    void execUpCut(unsigned short a, const char *name, bool b, unsigned char c, int d);
    void moveObjPos(cGameObj *obj, float x, float y, float z, float ang);
    void endExtraGame();
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
    cTaskManager m_task;
    char _pad24[0x48 - 0x24];
    unsigned int m_flags48;
    char _pad4C[0xD4 - 0x4C];
    sCallback *m_cb;
    char _padD8[0xEC - 0xD8];
    void *m_roomExitFunc;
    void *m_roomExitArg;
    char _padF4[0x111 - 0xF4];
    unsigned char m_camWait;
    unsigned short m_messNo;
};

#endif
