#include "game/cOl2b.h"

// FUNCTION: GAME 0x180310
void cOl2b::setOpen()
{
    if (m_state != 1) {
        m_act0 = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180338
void cOl2b::setClose()
{
    if (m_state != 2) {
        m_act0 = 2;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180360
void cOl2b::setInit()
{
    if (m_state != 0) {
        m_act0 = 3;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// FUNCTION: GAME 0x180688
int cOl2b::getState()
{
    return m_state;
}

// FUNCTION: GAME 0x180690
unsigned char cOl2b::isActive()
{
    return m_active;
}

extern cVec16 D_00567FF0[3];
extern cVec16 D_00568020[3];
extern cVec16 D_00567FC0[3];

#ifdef NONMATCHING
// 0x180388: ~10 words differ: original keeps the in-range bool in a1 (daddu a1,v0 + andi 0xFF) before testing it; ours tests slt result directly
void cOl2b::setOpenFix()
{
    if (m_state != 1) {
        for (int i = 0; i < 3; i++) {
            cObjParts *p = getParts(i);
            if (p)
                p->m_v = *(cVec *)&D_00567FF0[i];
        }
        m_act0 = 0;
        m_state = 1;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// 0x180440: same diff as setOpenFix (in-range bool copy + andi 0xFF)
void cOl2b::setCloseFix()
{
    if (m_state != 2) {
        for (int i = 0; i < 3; i++) {
            cObjParts *p = getParts(i);
            if (p)
                p->m_v = *(cVec *)&D_00568020[i];
        }
        m_act0 = 0;
        m_state = 2;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}

// 0x1804F8: same diff as setOpenFix (in-range bool copy + andi 0xFF)
void cOl2b::setInitFix()
{
    if (m_state != 0) {
        for (int i = 0; i < 3; i++) {
            cObjParts *p = getParts(i);
            if (p)
                p->m_v = *(cVec *)&D_00567FC0[i];
        }
        m_act0 = 0;
        m_state = 0;
        m_act1 = 0;
        m_act2 = 0;
        m_act3 = 0;
    }
}
#endif

struct cSndFwd {
    void SeCall(int, int, cObj *, int, cObjParts *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cSndFwd Snd;
extern void *func_SetEffect(int, int, cObj *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
extern void func_KillEffect(int, int, int) __asm__("KillEffect__F12eEffDataType6eEffId13eEspEraseMode");

#ifdef NONMATCHING
// 0x1805A8: ours hoists the lui/addiu of Snd above the parts lookup (a0/v1 allocation shifts, 26 words differ)
void cOl2b::setFire()
{
    if (m_fire == 0) {
        func_SetEffect(1, 3, this, 0, -1, 0xFFFFFFFFu);
        Snd.SeCall(2, 0xDD, this, 0, getParts(2), 0, 0);
        m_fire = 1;
    }
}
#endif

// FUNCTION: GAME 0x180648
void cOl2b::clearFire()
{
    if (m_fire) {
        func_KillEffect(1, 3, 2);
        m_fire = 0;
    }
}
