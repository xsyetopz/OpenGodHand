#ifndef CSCENARIO_H
#define CSCENARIO_H

class cScenario {
public:
    void SetRoomExitFunc(void *func, void *arg);

    char _pad0[0xEC];
    void *m_roomExitFunc;
    void *m_roomExitArg;
    char _padF4[0x111 - 0xF4];
    unsigned char m_camWait;
};

#endif
