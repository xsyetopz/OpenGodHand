// Unnamed small functions of the 0x170000-0x17FFFF range, shared by the cOl* object classes.
#include "game/cOl0.h"

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

// FUNCTION: GAME 0x17F6B0
extern "C" void func_0017F6B0(sOlFlags *s)
{
    s->m_b765 = 0;
    s->m_b764 = 0;
}

// FUNCTION: GAME 0x1717A0
extern "C" void func_001717A0(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x173198
extern "C" void func_00173198(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x1741E8
extern "C" void func_001741E8(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x178340
extern "C" void func_00178340(sOlObj *s, void *a)
{
    s->m_vt = D_004213C0;
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x1785F0
extern "C" void func_001785F0(sOlObj *s, void *a)
{
    s->m_vt = D_004214A8;
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x178AF8
extern "C" void func_00178AF8(sOlObj *s, void *a)
{
    s->m_vt = D_00421658;
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x178848
extern "C" void func_00178848(sOlObj *s, void *a)
{
    s->m_vt = D_00421590;
    func_001B6F38(s, a);
}

// FUNCTION: GAME 0x17C4E0
extern "C" void func_0017C4E0(sOlObj *s)
{
    s->m_vt = D_00421C80;
    func_001BD650(s);
}

// FUNCTION: GAME 0x178870
extern "C" int func_00178870(sOlDmgSlot *s)
{
    func_001B6FB8(s);
    s->m_dmg = 0;
    return 1;
}

// FUNCTION: GAME 0x174FB0
extern "C" void func_00174FB0(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x176738
extern "C" void func_00176738(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x177DC0
extern "C" void func_00177DC0(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x1789F8
extern "C" void func_001789F8(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x179798
extern "C" void func_00179798(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17A508
extern "C" void func_0017A508(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17B548
extern "C" void func_0017B548(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17C008
extern "C" void func_0017C008(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17CE18
extern "C" void func_0017CE18(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17DB40
extern "C" void func_0017DB40(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17E658
extern "C" void func_0017E658(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17EDD0
extern "C" void func_0017EDD0(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17F1D0
extern "C" void func_0017F1D0(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17F990
extern "C" void func_0017F990(cOmBase *s)
{
    s->dieCommon();
}

// FUNCTION: GAME 0x17FD80
extern "C" void func_0017FD80(cOmBase *s)
{
    s->dieCommon();
}

extern const char D_00421E38[];
// FUNCTION: GAME 0x17D460
extern "C" void func_0017D460(sOlObj *s, void *a)
{
    s->m_vt = D_00421E38;
    func_001BBF00(s, a);
}

extern const char D_004220B0[];
// FUNCTION: GAME 0x17E8B0
extern "C" void func_0017E8B0(sOlObj *s, void *a)
{
    s->m_vt = D_004220B0;
    func_001BBF00(s, a);
}

extern const char D_004223D0[];
// FUNCTION: GAME 0x17F2F8
extern "C" void func_0017F2F8(sOlObj *s, void *a)
{
    s->m_vt = D_004223D0;
    func_001BBF00(s, a);
}

extern const char D_00421FE8[];
// FUNCTION: GAME 0x17E1C0
extern "C" void func_0017E1C0(sOlObj *s, void *a)
{
    s->m_vt = D_00421FE8;
    func_001B6F38(s, a);
}

extern const char D_00422308[];
// FUNCTION: GAME 0x17EE78
extern "C" void func_0017EE78(sOlObj *s, void *a)
{
    s->m_vt = D_00422308;
    func_001B6F38(s, a);
}

extern const char D_00422498[];
// FUNCTION: GAME 0x17F5A8
extern "C" void func_0017F5A8(sOlObj *s, void *a)
{
    s->m_vt = D_00422498;
    func_001B6F38(s, a);
}

extern const char D_00422560[];
// FUNCTION: GAME 0x17FC30
extern "C" void func_0017FC30(sOlObj *s, void *a)
{
    s->m_vt = D_00422560;
    func_001B6F38(s, a);
}

extern const char D_00422178[];
// FUNCTION: GAME 0x17EAD0
extern "C" void func_0017EAD0(sOlObj *s)
{
    s->m_vt = D_00422178;
    func_001BD650(s);
}

// FUNCTION: GAME 0x1809B0
extern "C" void func_001809B0(sOlDmg60C *s, void *a)
{
    s->m_vt = D_004226A8;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001B6F38(s, a);
}

// FUNCTION: GAME 0x1818C0
extern "C" void func_001818C0(sOlDmg650 *s, void *a)
{
    s->m_vt = D_00422858;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C7DE0(s, a);
}

// FUNCTION: GAME 0x182668
extern "C" void func_00182668(sOlObj *s, void *a)
{
    s->m_vt = D_00422928;
    func_001C2820(s, a);
}
