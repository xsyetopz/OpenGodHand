#ifndef CEVENT_H
#define CEVENT_H

class cEvent {
public:
    int isPlaying() const;

    char _pad0[4];
    signed char m_state;
};

#endif
