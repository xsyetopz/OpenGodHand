#ifndef CDVDDECL_H
#define CDVDDECL_H
#include "game/cDvd.h"

void KeyStop();
extern "C" void func_002009E8(int, int);
extern "C" int func_001FFA68(void *);
extern "C" int func_003244C8(int);
extern "C" int func_00399508(int);
extern "C" int func_00329298();
extern "C" int func_00201A00(void *);
extern "C" int func_00323918(int, int);
extern "C" void func_00324258(int, int, int);
extern "C" void func_00323E80(int, int, int);
extern "C" void func_00323A70(int);
extern "C" void func_002A9648(int, int, int, int);
extern "C" void *func_00200AB0(void *);
extern "C" void func_00201A80(int, int);
extern "C" void func_00201F20(int, int);
extern "C" void *memset(void *, int, unsigned int);
extern char D_00580D40[];
extern char Dvd[];
extern unsigned char D_0058503A;

struct DvdSelf {
    int *m_p;
};

struct DvdCnt {
    char _pad0[0x1104];
    int m_cnt;
    char _pad1108[4];
    unsigned char m_flag;
};
struct DvdSlot {
    int m_used;
    int m_id;
    int m_pad[32];
};

struct DvdMgr {
    int *m_cur;
    DvdSlot m_slot[32];
    int m_cnt;
    int m_state;
};

extern "C" void func_00201290(DvdMgr *);
extern "C" void func_00201250(DvdMgr *);
extern "C" void func_00201718(DvdMgr *);
extern "C" int func_002018D0(DvdSelf *);
extern "C" void func_002018F0(DvdMgr *);
extern "C" void func_00324008(int);
extern "C" void func_002011B0(DvdMgr *);

extern "C" bool func_00201A50(void *);
extern "C" void func_002D5250(int);
extern "C" int func_00201788(DvdCnt *s);
#endif
