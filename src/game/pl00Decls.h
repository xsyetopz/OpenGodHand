#ifndef PL00DECLS_H_
#define PL00DECLS_H_

#include "game/pl00.h"

#include "game/cMessage.h"

extern "C" void func_001CF8B0(void *p);

extern "C" int func_0010B698(pl00 *p);

class cEmManage {
public:
    int CkPlCatched();
};

extern cEmManage g_EmManage;

extern "C" void func_001269E0(pl00 *p, unsigned int a, int b);

class cPlCamera {
public:
    void setCamUpdate(unsigned int a);
};

class cCamManager : public cPlCamera {
public:
    void setPlCamera(unsigned char v);
    int isCk_CamClass(unsigned int a);
};

extern cCamManager CamManager;

class cObjBase {
public:
    void R0_scenario();
    void KageDraw();
};

extern const unsigned short D_00747A50;

class cSceAtManager {
public:
    char _pad[0x68];
    void *m_unk68;
    void *m_unk6C;
};

extern cSceAtManager g_SceAt;

extern "C" int func_002C2568(cSceAtManager *m, cVec *p, int a);

extern "C" void func_002DBE98();

class cEm00 {
public:
    int ckDown();
    char _pad[0x2FE];
    unsigned short m_unk2FE;
};

extern "C" void func_00100FB8(int a, int b);

class cActionButtonUnit {
public:
    void setOk();
};

class cOmWeapon {
public:
    void setFall();
};

enum eEffDataType { EFF_DATA_0 = 0 };

enum eEffId { EFF_61 = 0x61, EFF_79 = 0x79 };

enum eEspEraseMode { ESP_ERASE_2 = 2 };

void KillEffect(eEffDataType type, eEffId id, eEspEraseMode mode);

struct cEffObj {
    char _pad[0x564];
    int m_unk564;
};

struct cFlagObj {
    char _pad[0x2F0];
    unsigned int m_flags;
};

struct cVTab {
    char _pad[0x68];
    short m_delta;
    short m_pad;
    const cVec *(*m_fn)(void *);
};

struct cVObj {
    char _pad[0x214];
    cVTab *m_vtab;
};

class cGameObj {
public:
    void SetTgtTurn(const cVec &v, float a);
    int isClip() const;
};

struct cHolder {
    struct pl00 *m_first;
};

static inline pl00 *getHolderObj(pl00 *self, const unsigned int &i)
{
    if (i)
        return self->m_unk278->m_first;
    return 0;
}

struct sD_004615F0 {
    float x, y, z, w;
};

extern sD_004615F0 D_004615F0;

class cModel {
public:
    int isClip() const;
};

extern int D_00747A80;

void capVu0Length(const float *p);

struct cDtorObj {
    char _pad[0x214];
    void *m_vptr;
};

extern char D_0041B730[];

extern char D_0041B6A0[];

extern "C" void _$_7cPlBase(cDtorObj *);

extern "C" void _$_8cObjBase(cDtorObj *);

extern int D_005FEAC0;

extern "C" void func_002AE740(int);

extern "C" void func_002AE7F0(int);

extern "C" void func_002D56A8(char *);

extern "C" void func_002D50E8(char *, int, int, int);

extern "C" void func_002D51F0(char *);

struct cSubS {
    char _pad[0x14];
    char m_unk14;
};

struct cBitSet {
    char _pad[0x68];
    unsigned *m_unk68;
};

struct cMsgHolder {
    char _pad[0x112];
    unsigned short m_unk112;
};

extern cMessage *Message;

struct sIdPair {
    short m_id0;
    short m_id1;
    int m_unk4;
};

struct sTblBase {
    char _pad[0x34];
    char *m_unk34;
};

struct sFlagWord {
    int m_unk0;
    int m_unk4;
    int _pad8[3];
    int m_unk14;
};

struct sHasPtrC {
    char _pad[0xC];
    void *m_unkC;
};

extern "C" void func_002CD7C8(void *);

extern "C" void func_002CD890(void *);

extern "C" int func_00375128(int);

struct sHasShort2C {
    char _pad[0x2C];
    short m_unk2C;
};

extern "C" void func_00325DC0(int);

struct sSndNode {
    char _pad[0x84];
    sSndNode *m_unk84;
    sSndNode *m_unk88;
};

struct sSndList {
    char _pad[0x18];
    sSndNode *m_unk18;
};

extern sSndList Snd;

struct sClr {
    char m0;
    char m1;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

#endif
