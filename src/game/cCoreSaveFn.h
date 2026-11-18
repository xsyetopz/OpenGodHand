// Unnamed accessors of the cCoreSave save-data pointer (first member).
#ifndef GAME_CCORESAVEFN_H
#define GAME_CCORESAVEFN_H

// The save block is viewed by byte offset until its layout is known.
#include "game/cCoreSave.h"

struct SaveSelf {
    char *m_save;
};

#define AT(T, o) (*(T *)(s + (o)))

extern "C" int setGameLevel__9cCoreSavei(SaveSelf *, int);
extern "C" int SdeSystemOutModeGet();
extern "C" void SdeSystemOutModeSet(int);
extern unsigned char D_005E85F8;
extern unsigned int D_00747A38;
extern int D_00747A0C;

struct WorldTimeT {
    unsigned int m_0, m_4;
};
struct SysT {
    char _pad[0x5B0];
    unsigned short m_5B0;
    char _5B2[4];
    unsigned short m_5B6;
};
extern WorldTimeT WorldTime;
struct TimeSelf {
    WorldTimeT *m_save;
};
extern SysT Sys;

#endif
