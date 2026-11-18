#include "game/cCoreSave.h"

// FUNCTION: GAME 0x1FAEE0
int cCoreSave::getReelItem()
{
    if (m_save == 0)
        return 0;
    if (D_00747A38 & 0x8000000)
        m_save->m_reelItem = 6;
    return m_save->m_reelItem;
}

// FUNCTION: GAME 0x1FBFD0
int cCoreSave::ckClearStage(unsigned short n)
{
    if (m_save == 0)
        return 0;
    if (n >= 9)
        return 0;
    if (D_00747A3C & 0x80000)
        return 1;
    if (m_save->m_clearStage & (1 << n))
        return 1;
    return 0;
}

// FUNCTION: GAME 0x1FB928
int cCoreSave::ckGodReel(eCommandNo n)
{
    if (m_save == 0)
        return 0;
    if (n >= 0x1F)
        return 0;
    unsigned long f = (int)D_00747A34;
    unsigned long b = (f >> 1) & 1;
    if (b)
        return 1;
    int r = 1;
    if (!(m_save->m_godReel & (1 << n)))
        r = 0;
    return r;
}

// FUNCTION: GAME 0x1FAF20
void cCoreSave::setSkill(PL_SKILL i, signed char v)
{
    if (m_save) {
        if (i < 0x80) {
            if (i < 0x72)
                m_save->m_skill[i] = v;
        }
    }
}

// FUNCTION: GAME 0x1FAF58
signed char cCoreSave::getSkill(PL_SKILL i)
{
    if (m_save == 0)
        return -1;
    if (i >= 0x80)
        return -1;
    if (i >= 0x72)
        return -1;
    if (D_00747A34 & 0x800000)
        return 0;
    return m_save->m_skill[i];
}

// FUNCTION: GAME 0x1FABB0
int cCoreSave::getGodItemNum()
{
    unsigned i;
    int n = 0;
    for (i = 0; i < 6 && i < m_save->m_reelItem; i++) {
        if (m_save->m_godItem[i])
            n++;
    }
    return n;
}

// FUNCTION: GAME 0x1FAB50
int cCoreSave::addGodItem(unsigned char c)
{
    for (unsigned i = 0; i < 6 && i < m_save->m_reelItem; i++) {
        if (m_save->m_godItem[i] == 0) {
            m_save->m_godItem[i] = c;
            return 1;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x1FAC00
void cCoreSave::useGodItem()
{
    if (!(D_00747A2C & 0x80000)) {
        for (unsigned i = 0; i < 5; i++)
            m_save->m_godItem[i] = m_save->m_godItem[i + 1];
        m_save->m_godItem[5] = 0;
    }
}

// FUNCTION: GAME 0x1FB6C8
int cCoreSave::getCombo(unsigned int i, unsigned int j)
{
    if (m_save == 0)
        return 0;
    if (j >= 6)
        return 0;
    if (getComboMax(i) <= j)
        return 0;
    if (i >= 6)
        return 0;
    return m_save->m_combo[i].m_skill[j];
}

// FUNCTION: GAME 0x1FB750
signed char cCoreSave::getComboLv(unsigned int i, unsigned int j)
{
    if (m_save == 0)
        return 0;
    if (j >= 6)
        return 0;
    if (getComboMax(i) <= j)
        return 0;
    if (i >= 6)
        return 0;
    return m_save->m_combo[i].m_lv[j];
}

// FUNCTION: GAME 0x1FB7D8
void cCoreSave::setCombo(unsigned int i, unsigned int j, PL_SKILL skill, signed char lv)
{
    if (m_save && j < 6 && i < 6) {
        m_save->m_combo[i].m_skill[j] = skill;
        m_save->m_combo[i].m_lv[j] = lv;
    }
}

extern "C" void *memset(void *, int, unsigned int);

// FUNCTION: GAME 0x1FC518
extern "C" void func_001FC518(cCoreSave *self, int v)
{
    if (self->m_save)
        self->m_save->m_fightingRingEmListNo = v;
}

// FUNCTION: GAME 0x1FC5B8
extern "C" void func_001FC5B8(cCoreSave *self)
{
    if (self->m_save)
        self->m_save->m_allKillNpcNum = 0;
}

// FUNCTION: GAME 0x1FC5E8
extern "C" void func_001FC5E8(cCoreSave *self)
{
    if (self->m_save)
        self->m_save->m_allContinueNum = 0;
}

// FUNCTION: GAME 0x1FC618
extern "C" void func_001FC618(cCoreSave *self)
{
    if (self->m_save)
        self->m_save->m_allStageTime = 0;
}

// FUNCTION: GAME 0x1FC6C8
extern "C" void func_001FC6C8(cCoreSave *self)
{
    if (self->m_save)
        self->m_save->m_oliviaFlags &= 0xFFFE;
}

// FUNCTION: GAME 0x1FC6E8
extern "C" void func_001FC6E8(cCoreSave *self)
{
    if (self->m_save)
        self->m_save->m_oliviaFlags |= 1;
}

// FUNCTION: GAME 0x1FC708
extern "C" int func_001FC708(cCoreSave *self)
{
    if (self->m_save == 0)
        return 0;
    return self->m_save->m_oliviaFlags & 1;
}

// FUNCTION: GAME 0x1FC548
extern "C" void func_001FC548(cCoreSave *self)
{
    if (self->m_save) {
        for (unsigned i = 0; i < 5; i++)
            self->m_save->m_allKillEmNum[i] = 0;
    }
}

// FUNCTION: GAME 0x1FC438
extern "C" void func_001FC438(cCoreSave *self)
{
    if (self->m_save)
        memset((char *)self->m_save + 0xB98, 0, 0x10);
}
