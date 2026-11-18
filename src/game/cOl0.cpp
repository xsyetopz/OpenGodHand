// Unnamed small functions of the 0x170000-0x17FFFF range, shared by the cOl* object classes.
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

// FUNCTION: GAME 0x170130
extern "C" void func_00170130()
{
    func_001C29D0();
}

// FUNCTION: GAME 0x170150
extern "C" void func_00170150(cObj *o)
{
    SetEffect((eEffDataType)1, (eEffId)4, o, 0, -1, (eEffId)-1);
}

// FUNCTION: GAME 0x170438
extern "C" void func_00170438(cObj *o)
{
    SetEffect((eEffDataType)1, (eEffId)5, o, 0, -1, (eEffId)-1);
}

// FUNCTION: GAME 0x170188
extern "C" void func_00170188(cObj *o)
{
    Snd.SeCall((eSeBlk)2, 0, *o, 0, 0, 0, 0);
    Snd.SeCall((eSeBlk)2, 2, *o, 0, 0, 0, 0);
}

extern int D_007857D8;
extern const char D_004204E0[];
extern char D_00785798[];

// FUNCTION: GAME 0x170200
extern "C" void *func_00170200()
{
    if (D_007857D8 == 0) {
        func_001C3BE8();
        func_0031EEA8(&D_007857D8, D_004204E0, D_00785798);
    }
    return &D_007857D8;
}

extern const char D_004204F8[];

struct sOlDmg {
    char _pad0[0x214];
    const void *m_vt;
    char _pad218[0x600 - 0x218];
    void *m_dmg;
};

// FUNCTION: GAME 0x1702D8
extern "C" void func_001702D8(sOlDmg *s, void *a)
{
    s->m_vt = D_004204F8;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C2820(s, a);
}

extern const char D_00420920[];

// FUNCTION: GAME 0x170F38
extern "C" void func_00170F38(sOlObj *s)
{
    s->m_vt = D_00420920;
    func_001BD650(s);
}

extern int D_00785848;
extern const char D_004209D0[];
extern char D_00785858[];

// FUNCTION: GAME 0x171020
extern "C" void *func_00171020()
{
    if (D_00785848 == 0) {
        func_001BDE00();
        func_0031EEA8(&D_00785848, D_004209D0, D_00785858);
    }
    return &D_00785848;
}

extern const char D_00420CA0[];

struct sOlRes {
    char _pad0[0x214];
    const void *m_vt;
    char _pad218[0x1AE0 - 0x218];
};

// FUNCTION: GAME 0x1710F0
extern "C" void func_001710F0(sOlRes *s, void *a)
{
    s->m_vt = D_00420CA0;
    func_002AD288((char *)s + 0x1AE0, 2);
    func_001B6F38(s, a);
}

extern const char D_00420D68[];

// FUNCTION: GAME 0x171B48
extern "C" void func_00171B48(sOlObj *s)
{
    s->m_vt = D_00420D68;
    func_001BD650(s);
}

struct sOlPos {
    char _pad0[0xF0];
    cVec *m_pos;
    char _padF4[0x100 - 0xF4];
    cVec m_v100;
};

// FUNCTION: GAME 0x171A70
extern "C" void func_00171A70(sOlPos *s, const cVec *v)
{
    s->m_v100 = *v;
    func_001717C0(s, s->m_pos, &s->m_v100);
}

struct sOlVec {
    char _pad0[0x20];
    cVec m_v20;
    char _pad2C[4];
    cVec m_v30;
    char _pad3C[0x50 - 0x3C];
    int m_i50;
    unsigned char m_b54;
};

// FUNCTION: GAME 0x173900
extern "C" unsigned char func_00173900(sOlVec *s)
{
    return s->m_b54;
}

// FUNCTION: GAME 0x173908
extern "C" void func_00173908(sOlVec *s, const cVec *v)
{
    s->m_v20 = *v;
}

// FUNCTION: GAME 0x173938
extern "C" void func_00173938(sOlVec *s, const cVec *v)
{
    s->m_v30 = *v;
}

// FUNCTION: GAME 0x173998
extern "C" void func_00173998(sOlVec *s, int v)
{
    s->m_i50 = v;
}

struct sOlState {
    char _pad0[0x2F4];
    unsigned char m_mode0, m_mode1, m_mode2, m_mode3;
    char _pad2F8[0x654 - 0x2F8];
    unsigned short m_timer;
};

// FUNCTION: GAME 0x173E60
extern "C" void func_00173E60(sOlState *s)
{
    switch (s->m_mode1) {
    case 0:
        s->m_timer = 0xF;
        s->m_mode1 = 1;
        s->m_mode2 = 0;
        s->m_mode3 = 0;
    case 1:
        s->m_timer--;
        if ((short)s->m_timer <= 0) {
            s->m_mode0 = 0;
            s->m_mode1 = 0;
            s->m_mode2 = 0;
            s->m_mode3 = 0;
        }
        break;
    }
}

// FUNCTION: GAME 0x178978
extern "C" void func_00178978()
{
}

// FUNCTION: GAME 0x178980
extern "C" void func_00178980(float *s)
{
    s[0x600 / 4] += 0.008f;
    if (s[0x600 / 4] >= 2.0f)
        s[0x600 / 4] = 2.0f;
    s[0x100 / 4] += s[0x600 / 4] * s[0x600 / 4] * 0.017453292f;
    if (s[0x100 / 4] >= 1.5707964f)
        s[0x100 / 4] = 1.5707964f;
}

struct sOlB {
    char _pad0[0x601];
    unsigned char m_b601;
    char _pad602[4];
    short m_s606;
};

// FUNCTION: GAME 0x17AEA0
extern "C" void func_0017AEA0(sOlB *s)
{
    s->m_s606 = 6;
}

// FUNCTION: GAME 0x17B810
extern "C" unsigned char func_0017B810(sOlB *s)
{
    return s->m_b601;
}

extern const char D_00421F20[];

// FUNCTION: GAME 0x17D638
extern "C" void func_0017D638(sOlObj *s, void *a)
{
    s->m_vt = D_00421F20;
    func_0017DF88(s);
    func_001B6F38(s, a);
}

// FUNCTION: GAME 0x17D680
extern "C" int func_0017D680(sOlObj *s)
{
    func_001B6FB8(s);
    func_0017DCB8(s);
    return 1;
}

extern const char D_00422240[];

// FUNCTION: GAME 0x17EC40
extern "C" void func_0017EC40(sOlObj *s, void *a)
{
    s->m_vt = D_00422240;
    EspSys.effDataRelease((eEffDataType)0x27D);
    func_001B6F38(s, a);
}

#ifdef NONMATCHING
struct sOlHdr {
    int _pad[3];
    int m_off;
};
struct sOlRsrc {
    char _pad0[0x304];
    sOlHdr *m_hdr;
};

// 0x17EC98: matches except the register holding m_hdr (original v1, compiled v0 in the
// lw 0x304 / lw 0xC / addu sequence before effDataRegist).
extern "C" int func_0017EC98(sOlRsrc *s)
{
    func_001B6FB8(s);
    sOlHdr *h = s->m_hdr;
    EspSys.effDataRegist((eEffDataType)0x27D, (char *)h + h->m_off);
    SetEffect((eEffDataType)0x27D, (eEffId)1, (cObj *)s, 0, -1, (eEffId)-1);
    return 1;
}
#endif
