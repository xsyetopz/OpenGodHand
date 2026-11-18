#ifndef CEM00FN240DECLS_H_
#define CEM00FN240DECLS_H_

// Small unnamed functions in 0x240000-0x267FFF.
#include "game/cEm00State.h"

struct Fn2478B8Obj {
    char _pad0[0x2F4];
    char m_unk2F4;
    unsigned char m_unk2F5;
    char m_unk2F6;
    char m_unk2F7;
};

struct Fn2609Obj {
    char _pad0[0x1870];
    int m_unk1870;
    int m_unk1874;
    int m_unk1878;
    int m_unk187C;
    short m_unk1880;
    char _pad1882[2];
    int m_unk1884;
    int m_unk1888;
    int m_unk188C;
    int m_unk1890;
    short m_unk1894;
};

extern char g_EmManage[];

extern "C" int func_002919C0(void *, int, int);

class cVec;

extern cVec ZeroVec;

class cDmgUnitLocal {
public:
    void SetDamageCollRadius(int id, float r);
    void SetDamageCollActive(bool on);
};

class cDamageGive : public cDmgUnitLocal {
public:
    void SetDmgGiveHitVec(const cVec &v);
};

struct cDmgFwd25F {
    void SetDamageCollActive(bool) __asm__("SetDamageCollActive__11cDamageUnitb");
};

struct cSndFwd25F {
    int SeCall(int, short, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};

extern cSndFwd25F Snd;

extern "C" int GetSeqSEBase__FP8cObjBase(void *);

extern "C" int irand__Fv(void);

extern "C" void func_002814E8(void *, int);

extern "C" void func_002833C0(void *, int);

extern "C" int func_0026F1D8(void *);

extern char g_HeatSys[];

extern const float D_005850B0[];

extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);

extern "C" void func_00281260(void *);

extern "C" void func_00283170(void *);

extern "C" void func_002495E0(void *, float);

extern "C" void func_00262AA8(void *);

extern "C" void func_00281338(void *);

struct cCamMgr247 {
    void setPartsCamera(unsigned char) __asm__("setPartsCamera__11cCamManagerUc");
};

struct cPartsCam247 {
    void SetParts(void *, void *, void *, void *) __asm__("SetParts__12cPartsCameraP6cPartsN21");
};

struct pl00Fwd247 {
    void clearMotionCam(unsigned, unsigned) __asm__("clearMotionCam__4pl00UiUi");
};

extern cCamMgr247 CamManager;

extern "C" void func_001D0778(void *);

#endif
