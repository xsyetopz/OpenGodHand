// Unnamed small functions of the 0x170000-0x17FFFF range, shared by the cOl* object classes.
#include "game/cOl0.h"

// FUNCTION: GAME 0x1832F0
extern "C" void *func_001832F0()
{
    if (D_00785A98 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00785A98, D_00422B30, D_00785878);
    }
    return &D_00785A98;
}

// FUNCTION: GAME 0x183380
extern "C" void func_00183380(sOlDmg600 *s, void *a)
{
    s->m_vt = D_00422B48;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001BFB00(s, a);
}

// FUNCTION: GAME 0x183628
extern "C" void func_00183628(sOlObj *s, void *a)
{
    s->m_vt = D_00422C18;
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x1867C0
extern "C" void func_001867C0(sOlObj *s, void *a)
{
    s->m_vt = D_00422F90;
    func_001BBF00(s, a);
}

// FUNCTION: GAME 0x186A20
extern "C" void func_00186A20(sOlDmg650 *s, void *a)
{
    s->m_vt = D_00423078;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C7DE0(s, a);
}

// FUNCTION: GAME 0x1877D8
extern "C" void func_001877D8(sOlDmg600 *s, void *a)
{
    s->m_vt = D_00423148;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x187A50
extern "C" void func_00187A50(sOlObj *s, void *a)
{
    s->m_vt = D_00423230;
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x188AF0
extern "C" void func_00188AF0(sOlDmg600 *s, void *a)
{
    s->m_vt = D_00423400;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x188D80
extern "C" void func_00188D80(sOlDmg600 *s, void *a)
{
    s->m_vt = D_004234E8;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x18A620
extern "C" void func_0018A620(sOlDmg600 *s, void *a)
{
    s->m_vt = D_00423700;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001B6F38(s, a);
}

// FUNCTION: GAME 0x18B318
extern "C" void func_0018B318(sOlDmg650 *s, void *a)
{
    s->m_vt = D_004237E8;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C7DE0(s, a);
}

// FUNCTION: GAME 0x18C120
extern "C" void func_0018C120(sOlDmg650 *s, void *a)
{
    s->m_vt = D_004238D8;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C7DE0(s, a);
}

// FUNCTION: GAME 0x18CF28
extern "C" void func_0018CF28(sOlDmg650 *s, void *a)
{
    s->m_vt = D_004239C8;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C7DE0(s, a);
}

// FUNCTION: GAME 0x18DCE0
extern "C" void func_0018DCE0(sOlDmg650 *s, void *a)
{
    s->m_vt = D_00423AB8;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C7DE0(s, a);
}

// FUNCTION: GAME 0x18EA98
extern "C" void func_0018EA98(sOlDmg600 *s, void *a)
{
    s->m_vt = D_00423B88;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001C2820(s, a);
}

// FUNCTION: GAME 0x18ECD0
extern "C" void func_0018ECD0(sOlDmg600 *s, void *a)
{
    s->m_vt = D_00423C70;
    if (s->m_dmg) {
        func_001FE278(&g_DmgManage, s->m_dmg);
        s->m_dmg = 0;
    }
    func_001BFB00(s, a);
}

// FUNCTION: GAME 0x18EF30
extern "C" void func_0018EF30(sOlObj *s, void *a)
{
    s->m_vt = D_00423D40;
    func_001BBF00(s, a);
}
