// Unnamed small functions of the 0x170000-0x17FFFF range, shared by the cOl* object classes.
#ifndef GAME_COL0_H
#define GAME_COL0_H

#include "game/cVec.h"

class cObj;
class cParts;
class cDamageTake;
struct tagEFF_PARAM;

enum eEffDataType { eEffDataType_0 };
enum eEffId { eEffId_0 };
enum eSeBlk { eSeBlk_0 };

// The original passes the second parameter's type again (`T2` in the mangled name).
void SetEffect(eEffDataType type, eEffId id, cObj *obj, tagEFF_PARAM *param, int a, eEffId b)
    __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");

class cSnd {
public:
    int SeCall(eSeBlk blk, short s, cObj &obj, cObj *o2, cParts *parts, unsigned u, int i);
};
extern cSnd Snd;

class espSys {
public:
    void effDataRelease(eEffDataType t);
    void effDataRegist(eEffDataType t, void *p);
};
extern espSys EspSys;

extern "C" {
void func_001B6F38(void *self, void *a);
void func_001B6FB8(void *self);
void func_001BD650(void *self);
void func_001BDE00();
void func_001C29D0();
void func_001C2820(void *self, void *a);
void func_001C3BE8();
void func_001FE278(void *mgr, void *p);
void func_002AD288(void *p, int n);
void func_0017DF88(void *self);
void func_0017DCB8(void *self);
void func_001717C0(void *self, void *a, void *b);
void func_0031EEA8(void *obj, const void *a, void *b);
}

extern char g_DmgManage;

// Common object header: vtable pointer at 0x214.
struct sOlObj {
    char _pad0[0x214];
    const void *m_vt;
};

extern int D_007857D8;
extern const char D_004204E0[];
extern char D_00785798[];

extern const char D_004204F8[];

struct sOlDmg {
    char _pad0[0x214];
    const void *m_vt;
    char _pad218[0x600 - 0x218];
    void *m_dmg;
};

extern const char D_00420920[];

extern int D_00785848;
extern const char D_004209D0[];
extern char D_00785858[];

extern const char D_00420CA0[];

struct sOlRes {
    char _pad0[0x214];
    const void *m_vt;
    char _pad218[0x1AE0 - 0x218];
};

extern const char D_00420D68[];

struct sOlPos {
    char _pad0[0xF0];
    cVec *m_pos;
    char _padF4[0x100 - 0xF4];
    cVec m_v100;
};

struct sOlVec {
    char _pad0[0x20];
    cVec m_v20;
    char _pad2C[4];
    cVec m_v30;
    char _pad3C[0x50 - 0x3C];
    int m_i50;
    unsigned char m_b54;
};

struct sOlState {
    char _pad0[0x2F4];
    unsigned char m_mode0, m_mode1, m_mode2, m_mode3;
    char _pad2F8[0x654 - 0x2F8];
    unsigned short m_timer;
};

struct sOlB {
    char _pad0[0x601];
    unsigned char m_b601;
    char _pad602[4];
    short m_s606;
};

extern const char D_00421F20[];

extern const char D_00422240[];

// Generated-shape forwarders, SetEffect wrappers and singleton accessors (same families as above).
extern "C" {
extern int D_007857D8; extern const char D_004204E0[]; extern char D_00785798[]; void func_001C3BE8();
extern int D_007857E8; extern const char D_004205C8[]; extern char D_00785798[]; void func_001C3BE8();
extern int D_007857F8; extern const char D_00420698[]; extern char D_00785808[]; void func_001C0018();
extern int D_00785818; extern const char D_00420768[]; extern char D_00785808[]; void func_001C0018();
extern int D_00785828; extern const char D_00420838[]; extern char D_00785808[]; void func_001C0018();
extern int D_00785838; extern const char D_00420908[]; extern char D_00785808[]; void func_001C0018();
extern int D_00785848; extern const char D_004209D0[]; extern char D_00785858[]; void func_001BDE00();
extern int D_00785888; extern const char D_00420E18[]; extern char D_00785858[]; void func_001BDE00();
extern int D_00785898; extern const char D_00420FA0[]; extern char D_00785878[]; void func_001B8058();
extern int D_007858A8; extern const char D_00421098[]; extern char D_007858B8[]; void func_001C8F30();
extern int D_007858C8; extern const char D_00421188[]; extern char D_007858B8[]; void func_001C8F30();
extern int D_007858D8; extern const char D_00421288[]; extern char D_00785878[]; void func_001B8058();
extern int D_007858E8; extern const char D_00421398[]; extern char D_00785878[]; void func_001B8058();
extern int D_007858F8; extern const char D_00421490[]; extern char D_00785798[]; void func_001C3BE8();
extern int D_00785908; extern const char D_00421578[]; extern char D_00785798[]; void func_001C3BE8();
extern int D_00785918; extern const char D_00421640[]; extern char D_00785878[]; void func_001B8058();
extern int D_00785928; extern const char D_00421728[]; extern char D_00785798[]; void func_001C3BE8();
extern int D_00785938; extern const char D_00421810[]; extern char D_00785798[]; void func_001C3BE8();
extern int D_00785948; extern const char D_00421900[]; extern char D_007858B8[]; void func_001C8F30();
extern int D_00785958; extern const char D_004219F0[]; extern char D_007858B8[]; void func_001C8F30();
extern int D_00785968; extern const char D_00421AB8[]; extern char D_00785878[]; void func_001B8058();
extern int D_00785988; extern const char D_00421D30[]; extern char D_00785858[]; void func_001BDE00();
extern int D_00785998; extern const char D_00421E20[]; extern char D_007858B8[]; void func_001C8F30();
extern int D_007859A8; extern const char D_00421EE8[]; extern char D_007859B8[]; void func_001BD528();
extern int D_007859C8; extern const char D_00421FD0[]; extern char D_00785878[]; void func_001B8058();
extern int D_007859D8; extern const char D_00422098[]; extern char D_00785878[]; void func_001B8058();
extern int D_007859E8; extern const char D_00422160[]; extern char D_007859B8[]; void func_001BD528();
extern int D_007859F8; extern const char D_00422228[]; extern char D_00785858[]; void func_001BDE00();
extern int D_00785A08; extern const char D_004222F0[]; extern char D_00785878[]; void func_001B8058();
extern int D_00785A18; extern const char D_004223B8[]; extern char D_00785878[]; void func_001B8058();
extern int D_00785A28; extern const char D_00422480[]; extern char D_007859B8[]; void func_001BD528();
extern int D_00785A38; extern const char D_00422548[]; extern char D_00785878[]; void func_001B8058();
void func_001B6FB8();
void func_001BC0A0();
void func_001BD6B0();
void func_001BFB80();
}

// Per-class SeCall pairs, constructors that return this, and destructors releasing the damage unit.
extern "C" {
extern const char D_004205E0[];
extern const char D_004206B0[];
extern const char D_00420780[];
extern const char D_00420850[];
extern const char D_00421590[];
extern const char D_00421740[];
extern const char D_00421C80[];
extern const char D_00422178[];
extern const char D_00422308[];
void func_001B6E90(void *self);
void func_001BD580(void *self);
void func_001BFAC8(void *self);
void func_001BFB00(void *self, void *a);
}

// Round 7: field accessors, cOmBase::dieCommon forwarders and vtable-reset destructors.
class cOmBase {
public:
    void dieCommon();
};

struct sOlFlags {
    char _pad0[0x764];
    unsigned char m_b764;
    unsigned char m_b765;
};

extern const char D_004213C0[];
extern const char D_004214A8[];
extern const char D_00421658[];

struct sOlDmgSlot {
    char _pad0[0x600];
    void *m_dmg;
};

// Round 8: remaining dieCommon forwarders and vtable-reset destructors.
extern "C" {
void func_001BBF00(void *self, void *a);
}

// 0x180000-0x18FFFF: forwarders, singleton accessors, vtable resets and destructors.
extern "C" {
extern const char D_004226A8[];
extern const char D_00422858[];
extern const char D_00422928[];
extern const char D_00422B30[];
extern const char D_00422B48[];
extern const char D_00422C18[];
extern const char D_00422F90[];
extern const char D_00423078[];
extern const char D_00423148[];
extern const char D_00423230[];
extern const char D_00423400[];
extern const char D_004234E8[];
extern const char D_00423700[];
extern const char D_004237E8[];
extern const char D_004238D8[];
extern const char D_004239C8[];
extern const char D_00423AB8[];
extern const char D_00423B88[];
extern const char D_00423C70[];
extern const char D_00423D40[];
extern int D_00785A98;
void func_001C7DE0(void *self, void *a);
}

struct sOlDmg60C {
    char _pad0[0x214];
    const void *m_vt;
    char _pad218[0x60C - 0x218];
    void *m_dmg;
};
struct sOlDmg650 {
    char _pad0[0x214];
    const void *m_vt;
    char _pad218[0x650 - 0x218];
    void *m_dmg;
};
struct sOlDmg600 {
    char _pad0[0x214];
    const void *m_vt;
    char _pad218[0x600 - 0x218];
    void *m_dmg;
};

#endif
