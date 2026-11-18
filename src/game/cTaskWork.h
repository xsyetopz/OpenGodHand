#ifndef CTASKWORK_H
#define CTASKWORK_H

struct sTaskOwner {
    char _pad0[0x28];
    int m_sema;
};

class cTaskWork {
public:
    void sleep(unsigned short n);
    void kill();
    void exit();

    sTaskOwner *m_owner;
    int m_thread;
    char _pad8[4];
    unsigned short m_active;
    unsigned short m_sleep;
};

#endif
