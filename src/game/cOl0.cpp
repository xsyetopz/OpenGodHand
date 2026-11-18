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

// FUNCTION: GAME 0x1704E8
extern "C" void *func_001704E8() { if (D_007857E8 == 0) { func_001C3BE8(); func_0031EEA8(&D_007857E8, D_004205C8, D_00785798); } return &D_007857E8; }
// FUNCTION: GAME 0x170778
extern "C" void *func_00170778() { if (D_007857F8 == 0) { func_001C0018(); func_0031EEA8(&D_007857F8, D_00420698, D_00785808); } return &D_007857F8; }
// FUNCTION: GAME 0x170A08
extern "C" void *func_00170A08() { if (D_00785818 == 0) { func_001C0018(); func_0031EEA8(&D_00785818, D_00420768, D_00785808); } return &D_00785818; }
// FUNCTION: GAME 0x170C98
extern "C" void *func_00170C98() { if (D_00785828 == 0) { func_001C0018(); func_0031EEA8(&D_00785828, D_00420838, D_00785808); } return &D_00785828; }
// FUNCTION: GAME 0x170EB0
extern "C" void *func_00170EB0() { if (D_00785838 == 0) { func_001C0018(); func_0031EEA8(&D_00785838, D_00420908, D_00785808); } return &D_00785838; }
// FUNCTION: GAME 0x171C40
extern "C" void *func_00171C40() { if (D_00785888 == 0) { func_001BDE00(); func_0031EEA8(&D_00785888, D_00420E18, D_00785858); } return &D_00785888; }
// FUNCTION: GAME 0x1739A0
extern "C" void *func_001739A0() { if (D_00785898 == 0) { func_001B8058(); func_0031EEA8(&D_00785898, D_00420FA0, D_00785878); } return &D_00785898; }
// FUNCTION: GAME 0x174758
extern "C" void *func_00174758() { if (D_007858A8 == 0) { func_001C8F30(); func_0031EEA8(&D_007858A8, D_00421098, D_007858B8); } return &D_007858A8; }
// FUNCTION: GAME 0x175558
extern "C" void *func_00175558() { if (D_007858C8 == 0) { func_001C8F30(); func_0031EEA8(&D_007858C8, D_00421188, D_007858B8); } return &D_007858C8; }
// FUNCTION: GAME 0x176BE0
extern "C" void *func_00176BE0() { if (D_007858D8 == 0) { func_001B8058(); func_0031EEA8(&D_007858D8, D_00421288, D_00785878); } return &D_007858D8; }
// FUNCTION: GAME 0x178268
extern "C" void *func_00178268() { if (D_007858E8 == 0) { func_001B8058(); func_0031EEA8(&D_007858E8, D_00421398, D_00785878); } return &D_007858E8; }
// FUNCTION: GAME 0x178518
extern "C" void *func_00178518() { if (D_007858F8 == 0) { func_001C3BE8(); func_0031EEA8(&D_007858F8, D_00421490, D_00785798); } return &D_007858F8; }
// FUNCTION: GAME 0x1787C0
extern "C" void *func_001787C0() { if (D_00785908 == 0) { func_001C3BE8(); func_0031EEA8(&D_00785908, D_00421578, D_00785798); } return &D_00785908; }
// FUNCTION: GAME 0x178A18
extern "C" void *func_00178A18() { if (D_00785918 == 0) { func_001B8058(); func_0031EEA8(&D_00785918, D_00421640, D_00785878); } return &D_00785918; }
// FUNCTION: GAME 0x178CE0
extern "C" void *func_00178CE0() { if (D_00785928 == 0) { func_001C3BE8(); func_0031EEA8(&D_00785928, D_00421728, D_00785798); } return &D_00785928; }
// FUNCTION: GAME 0x178F78
extern "C" void *func_00178F78() { if (D_00785938 == 0) { func_001C3BE8(); func_0031EEA8(&D_00785938, D_00421810, D_00785798); } return &D_00785938; }
// FUNCTION: GAME 0x179D08
extern "C" void *func_00179D08() { if (D_00785948 == 0) { func_001C8F30(); func_0031EEA8(&D_00785948, D_00421900, D_007858B8); } return &D_00785948; }
// FUNCTION: GAME 0x17AA88
extern "C" void *func_0017AA88() { if (D_00785958 == 0) { func_001C8F30(); func_0031EEA8(&D_00785958, D_004219F0, D_007858B8); } return &D_00785958; }
// FUNCTION: GAME 0x17B820
extern "C" void *func_0017B820() { if (D_00785968 == 0) { func_001B8058(); func_0031EEA8(&D_00785968, D_00421AB8, D_00785878); } return &D_00785968; }
// FUNCTION: GAME 0x17C5D0
extern "C" void *func_0017C5D0() { if (D_00785988 == 0) { func_001BDE00(); func_0031EEA8(&D_00785988, D_00421D30, D_00785858); } return &D_00785988; }
// FUNCTION: GAME 0x17D388
extern "C" void *func_0017D388() { if (D_00785998 == 0) { func_001C8F30(); func_0031EEA8(&D_00785998, D_00421E20, D_007858B8); } return &D_00785998; }
// FUNCTION: GAME 0x17D580
extern "C" void *func_0017D580() { if (D_007859A8 == 0) { func_001BD528(); func_0031EEA8(&D_007859A8, D_00421EE8, D_007859B8); } return &D_007859A8; }
// FUNCTION: GAME 0x17E0A8
extern "C" void *func_0017E0A8() { if (D_007859C8 == 0) { func_001B8058(); func_0031EEA8(&D_007859C8, D_00421FD0, D_00785878); } return &D_007859C8; }
// FUNCTION: GAME 0x17E7D8
extern "C" void *func_0017E7D8() { if (D_007859D8 == 0) { func_001B8058(); func_0031EEA8(&D_007859D8, D_00422098, D_00785878); } return &D_007859D8; }
// FUNCTION: GAME 0x17EA48
extern "C" void *func_0017EA48() { if (D_007859E8 == 0) { func_001BD528(); func_0031EEA8(&D_007859E8, D_00422160, D_007859B8); } return &D_007859E8; }
// FUNCTION: GAME 0x17EBB8
extern "C" void *func_0017EBB8() { if (D_007859F8 == 0) { func_001BDE00(); func_0031EEA8(&D_007859F8, D_00422228, D_00785858); } return &D_007859F8; }
// FUNCTION: GAME 0x17EDF0
extern "C" void *func_0017EDF0() { if (D_00785A08 == 0) { func_001B8058(); func_0031EEA8(&D_00785A08, D_004222F0, D_00785878); } return &D_00785A08; }
// FUNCTION: GAME 0x17F220
extern "C" void *func_0017F220() { if (D_00785A18 == 0) { func_001B8058(); func_0031EEA8(&D_00785A18, D_004223B8, D_00785878); } return &D_00785A18; }
// FUNCTION: GAME 0x17F490
extern "C" void *func_0017F490() { if (D_00785A28 == 0) { func_001BD528(); func_0031EEA8(&D_00785A28, D_00422480, D_007859B8); } return &D_00785A28; }
// FUNCTION: GAME 0x17FAF8
extern "C" void *func_0017FAF8() { if (D_00785A38 == 0) { func_001B8058(); func_0031EEA8(&D_00785A38, D_00422548, D_00785878); } return &D_00785A38; }
// FUNCTION: GAME 0x170418
extern "C" void func_00170418() { func_001C29D0(); }
// FUNCTION: GAME 0x1706E0
extern "C" void func_001706E0() { func_001BFB80(); }
// FUNCTION: GAME 0x170970
extern "C" void func_00170970() { func_001BFB80(); }
// FUNCTION: GAME 0x170C00
extern "C" void func_00170C00() { func_001BFB80(); }
// FUNCTION: GAME 0x170E90
extern "C" void func_00170E90() { func_001BFB80(); }
// FUNCTION: GAME 0x171000
extern "C" void func_00171000() { func_001BD6B0(); }
// FUNCTION: GAME 0x171C20
extern "C" void func_00171C20() { func_001BD6B0(); }
// FUNCTION: GAME 0x1784F8
extern "C" void func_001784F8() { func_001C29D0(); }
// FUNCTION: GAME 0x1787A0
extern "C" void func_001787A0() { func_001C29D0(); }
// FUNCTION: GAME 0x178CC0
extern "C" void func_00178CC0() { func_001C29D0(); }
// FUNCTION: GAME 0x178F58
extern "C" void func_00178F58() { func_001C29D0(); }
// FUNCTION: GAME 0x17C5B0
extern "C" void func_0017C5B0() { func_001BD6B0(); }
// FUNCTION: GAME 0x17D560
extern "C" void func_0017D560() { func_001BC0A0(); }
// FUNCTION: GAME 0x17EA28
extern "C" void func_0017EA28() { func_001BC0A0(); }
// FUNCTION: GAME 0x17EB98
extern "C" void func_0017EB98() { func_001BD6B0(); }
// FUNCTION: GAME 0x17F470
extern "C" void func_0017F470() { func_001BC0A0(); }

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

// FUNCTION: GAME 0x170470
extern "C" void func_00170470(cObj *o) { Snd.SeCall((eSeBlk)0x2, 0, *o, 0, 0, 0, 0); Snd.SeCall((eSeBlk)0x2, 0x2, *o, 0, 0, 0, 0); }
// FUNCTION: GAME 0x170538
extern "C" sOlObj *func_00170538(sOlObj *s) { func_001BFAC8(s); s->m_vt = D_004205E0; return s; }
// FUNCTION: GAME 0x170570
extern "C" void func_00170570(sOlDmg *s, void *a) { s->m_vt = D_004205E0; if (s->m_dmg) { func_001FE278(&g_DmgManage, s->m_dmg); s->m_dmg = 0; } func_001BFB00(s, a); }
// FUNCTION: GAME 0x170700
extern "C" void func_00170700(cObj *o) { Snd.SeCall((eSeBlk)0x2, 0xA, *o, 0, 0, 0, 0); Snd.SeCall((eSeBlk)0x2, 0xC, *o, 0, 0, 0, 0); }
// FUNCTION: GAME 0x1707C8
extern "C" sOlObj *func_001707C8(sOlObj *s) { func_001BFAC8(s); s->m_vt = D_004206B0; return s; }
// FUNCTION: GAME 0x170800
extern "C" void func_00170800(sOlDmg *s, void *a) { s->m_vt = D_004206B0; if (s->m_dmg) { func_001FE278(&g_DmgManage, s->m_dmg); s->m_dmg = 0; } func_001BFB00(s, a); }
// FUNCTION: GAME 0x170990
extern "C" void func_00170990(cObj *o) { Snd.SeCall((eSeBlk)0x2, 0xA, *o, 0, 0, 0, 0); Snd.SeCall((eSeBlk)0x2, 0xC, *o, 0, 0, 0, 0); }
// FUNCTION: GAME 0x170A58
extern "C" sOlObj *func_00170A58(sOlObj *s) { func_001BFAC8(s); s->m_vt = D_00420780; return s; }
// FUNCTION: GAME 0x170A90
extern "C" void func_00170A90(sOlDmg *s, void *a) { s->m_vt = D_00420780; if (s->m_dmg) { func_001FE278(&g_DmgManage, s->m_dmg); s->m_dmg = 0; } func_001BFB00(s, a); }
// FUNCTION: GAME 0x170C20
extern "C" void func_00170C20(cObj *o) { Snd.SeCall((eSeBlk)0x2, 0xA, *o, 0, 0, 0, 0); Snd.SeCall((eSeBlk)0x2, 0xC, *o, 0, 0, 0, 0); }
// FUNCTION: GAME 0x170CE8
extern "C" sOlObj *func_00170CE8(sOlObj *s) { func_001BFAC8(s); s->m_vt = D_00420850; return s; }
// FUNCTION: GAME 0x170D20
extern "C" void func_00170D20(sOlDmg *s, void *a) { s->m_vt = D_00420850; if (s->m_dmg) { func_001FE278(&g_DmgManage, s->m_dmg); s->m_dmg = 0; } func_001BFB00(s, a); }
// FUNCTION: GAME 0x170F00
extern "C" sOlObj *func_00170F00(sOlObj *s) { func_001BD580(s); s->m_vt = D_00420920; return s; }
// FUNCTION: GAME 0x171B10
extern "C" sOlObj *func_00171B10(sOlObj *s) { func_001BD580(s); s->m_vt = D_00420D68; return s; }
// FUNCTION: GAME 0x178810
extern "C" sOlObj *func_00178810(sOlObj *s) { func_001B6E90(s); s->m_vt = D_00421590; return s; }
// FUNCTION: GAME 0x178DB8
extern "C" void func_00178DB8(sOlDmg *s, void *a) { s->m_vt = D_00421740; if (s->m_dmg) { func_001FE278(&g_DmgManage, s->m_dmg); s->m_dmg = 0; } func_001C2820(s, a); }
// FUNCTION: GAME 0x17C4A8
extern "C" sOlObj *func_0017C4A8(sOlObj *s) { func_001BD580(s); s->m_vt = D_00421C80; return s; }
// FUNCTION: GAME 0x17EA98
extern "C" sOlObj *func_0017EA98(sOlObj *s) { func_001BD580(s); s->m_vt = D_00422178; return s; }
// FUNCTION: GAME 0x17EC08
extern "C" sOlObj *func_0017EC08(sOlObj *s) { func_001B6E90(s); s->m_vt = D_00422240; return s; }
// FUNCTION: GAME 0x17EE40
extern "C" sOlObj *func_0017EE40(sOlObj *s) { func_001B6E90(s); s->m_vt = D_00422308; return s; }
