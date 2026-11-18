#include "game/cEmSetParam.h"

struct sRoomSave {
    unsigned int *m_flags;
};
extern sRoomSave g_RoomSave;
struct sEmSetData {
    char _pad0[6];
    short m_rot;
    unsigned int m_flag;
    char _pad0C[4];
    unsigned char m_pat;
};
extern "C" {
void func_00295600(cEmSetParam *);
int func_00294B98(cEmSetParam *);
sEmSetData *func_002BEF60(sRoomSave *, unsigned int);
}

// FUNCTION: GAME 0x294B38
void cEmSetParam::roomInit()
{
    m_unk08 = 0;
    m_unk0C = 0;
    func_00295600(this);
}

// FUNCTION: GAME 0x294B60
void cEmSetParam::rewriteDataSet(void *p)
{
    register unsigned int *q asm("$6") = g_RoomSave.m_flags;
    *q &= 0x7FFFFFFF;
    func_00294B98(this);
}

// FUNCTION: GAME 0x294C68
void cEmSetParam::setEmData(void *p)
{
    if (func_00294B98(this))
        setEmAll();
}

// FUNCTION: GAME 0x295458
void cEmSetParam::updateSetDataAppPattern(unsigned int idx, unsigned char pat)
{
    sEmSetData *d = func_002BEF60(&g_RoomSave, idx);
    if (d)
        d->m_pat = pat;
}

// FUNCTION: GAME 0x295498
void cEmSetParam::updateSetDataFlag(unsigned int idx, unsigned int flag)
{
    sEmSetData *d = func_002BEF60(&g_RoomSave, idx);
    if (d)
        d->m_flag = flag;
}

// FUNCTION: GAME 0x295400
void cEmSetParam::updateSetDataRot(unsigned int idx, float rot)
{
    sEmSetData *d = func_002BEF60(&g_RoomSave, idx);
    if (d)
        d->m_rot = (short)(rot * 57.295776f);
}

// FUNCTION: GAME 0x2955F0
void cEmSetParam::stopEmSet1Time()
{
    m_stop1Time = 1;
}
