#ifndef CWORLDTIME_H
#define CWORLDTIME_H

class cWorldTime {
public:
    void gameInit();
    void setGlobalTime(unsigned int t);
    void getGlobalHMS(unsigned int *h, unsigned int *m, unsigned int *s);
    void getStageHMS(unsigned int *h, unsigned int *m, unsigned int *s);

    unsigned int m_globalTime;
    unsigned int m_stageTime;
};

#endif
