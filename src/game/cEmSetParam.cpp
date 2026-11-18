#include "game/cEmSetParam.h"
#include "game/cEmManage.h"

struct sRoomSave {
    unsigned int *m_flags;
};
extern sRoomSave g_RoomSave;
struct sEmSetData {
    short m_pos[3];
    short m_rot;
    unsigned int m_flag;
    char _pad0C[4];
    unsigned char m_pat;
    char _pad11[2];
    unsigned char m_emId;
    unsigned char m_flag14;
};
extern "C" {
void func_00295600(cEmSetParam *);
int func_00294B98(cEmSetParam *);
int func_002951B0(cEmSetParam *, sEmSetData *);
sEmSetData *func_002BEF60(sRoomSave *, unsigned int);
}

// FUNCTION: GAME 0x2952D0
int cEmSetParam::setEm(unsigned char idx)
{
    if (!(*g_RoomSave.m_flags & 0x80000000))
        return 0;
    sEmSetData *d = func_002BEF60(&g_RoomSave, idx);
    if (!d)
        return 0;
    if ((d->m_flag14 ^ 1) < 1)
        return 0;
    if (g_EmManage.GetEm(d->m_emId))
        return 0;
    if (d->m_flag & 0x80000000)
        d->m_flag &= 0x7FFFFFFF;
    return func_002951B0(this, d);
}

extern cVec ZeroVec;

#ifdef NONMATCHING
// 0x295510: instruction scheduling differs (original defers all 4 swc1 until after the third mul; stores interleave here); 23 words
cVec16 cEmSetParam::getSetDataPos(unsigned int idx) return r
{
    sEmSetData *d = func_002BEF60(&g_RoomSave, idx);
    if (d) {
        cVec16 v;
        v.x = d->m_pos[0] * 0.05f;
        v.y = d->m_pos[1] * 0.05f;
        v.z = d->m_pos[2] * 0.05f;
        v.w = 1.0f;
        cObjCopyVec(&r, (cVec *)&v);
    } else {
        cObjCopyVec(&r, &ZeroVec);
    }
}
#endif

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

#ifdef NONMATCHING
// 0x295380: only diff is cvt.w.s dest ($f2/$f1 instead of the original's reused $f0)
void cEmSetParam::updateSetDataPos(unsigned int idx, const cVec &pos)
{
    sEmSetData *d = func_002BEF60(&g_RoomSave, idx);
    if (d) {
        short x = (short)(pos.x * 20.0f);
        d->m_pos[0] = x;
        short y = (short)(pos.y * 20.0f);
        d->m_pos[1] = y;
        short z = (short)(pos.z * 20.0f);
        d->m_pos[2] = z;
    }
}
#endif
