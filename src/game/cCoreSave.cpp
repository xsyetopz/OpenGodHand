#include "game/cCoreSave.h"

extern unsigned int D_00747A34;
extern unsigned int D_00747A3C;
extern int D_003BF160[5];

// FUNCTION: GAME 0x1FA620
int cCoreSave::getGameLevelPoint()
{
    if (!m_save)
        return 0;
    return m_save->m_gameLevelPoint;
}

// FUNCTION: GAME 0x1FA658
void cCoreSave::setGameDifficulty(eDifficulty d)
{
    if (m_save && (unsigned)d < 3)
        m_save->m_difficulty = d;
}

// FUNCTION: GAME 0x1FA678
int cCoreSave::getGameDifficulty()
{
    if (!m_save)
        return 1;
    return m_save->m_difficulty;
}

// FUNCTION: GAME 0x1FA6F8
void cCoreSave::setGold(int v)
{
    if (m_save)
        m_save->m_gold = v;
}

// FUNCTION: GAME 0x1FA710
int cCoreSave::getGold()
{
    if (!m_save)
        return 0;
    if (D_00747A34 & 0x2000000)
        m_save->m_gold = 999999;
    return m_save->m_gold;
}

// FUNCTION: GAME 0x1FA820
void cCoreSave::initAddGold()
{
    if (m_save)
        m_save->m_addGold = 0;
}

// FUNCTION: GAME 0x1FA950
int cCoreSave::getKeyCardNum()
{
    if (!m_save)
        return 0;
    return m_save->m_keyCardNum;
}

// FUNCTION: GAME 0x1FAA00
int cCoreSave::getKeyNum()
{
    if (!m_save)
        return 0;
    return m_save->m_keyNum;
}

// FUNCTION: GAME 0x1FAC58
unsigned char cCoreSave::getGodItem()
{
    return m_save->m_godItem[0];
}

// FUNCTION: GAME 0x1FAC68
int cCoreSave::getVital()
{
    if (!m_save)
        return 100;
    return m_save->m_vital;
}

// FUNCTION: GAME 0x1FAC80
int cCoreSave::getVitalMax()
{
    if (!m_save)
        return 100;
    return m_save->m_vitalMax;
}

// FUNCTION: GAME 0x1FAC98
void cCoreSave::setVital(int v)
{
    if (m_save)
        m_save->m_vital = v;
}

// FUNCTION: GAME 0x1FBEB8
void cCoreSave::clearKillNpcNum()
{
    if (m_save)
        m_save->m_killNpcNum = 0;
}

// FUNCTION: GAME 0x1FBED0
int cCoreSave::getKillNpcNum()
{
    if (!m_save)
        return 0;
    return (short)m_save->m_killNpcNum;
}

// FUNCTION: GAME 0x1FBF48
int cCoreSave::getContinueNum()
{
    if (!m_save)
        return 0;
    return m_save->m_continueNum;
}

// FUNCTION: GAME 0x1FBF60
void cCoreSave::initContinueNum()
{
    if (m_save)
        m_save->m_continueNum = 0;
}

// FUNCTION: GAME 0x1FC0A8
int cCoreSave::getCostumeNo()
{
    if (!m_save)
        return 0;
    return m_save->m_costumeNo;
}

// FUNCTION: GAME 0x1FC3D0
int cCoreSave::getCasinoTicketNum()
{
    if (!m_save)
        return 0;
    return m_save->m_casinoTicketNum;
}

// FUNCTION: GAME 0x1FC530
int cCoreSave::GetFightingRingEmListNo()
{
    if (!m_save)
        return 0;
    return m_save->m_fightingRingEmListNo;
}

// FUNCTION: GAME 0x1FC5D0
int cCoreSave::getAllKillNpcNum()
{
    if (!m_save)
        return 0;
    return m_save->m_allKillNpcNum;
}

// FUNCTION: GAME 0x1FC600
int cCoreSave::getAllContinueNum()
{
    if (!m_save)
        return 0;
    return m_save->m_allContinueNum;
}

// FUNCTION: GAME 0x1FC728
void cCoreSave::SetOliviaCostumeNo(unsigned int v)
{
    if (m_save)
        m_save->m_oliviaCostumeNo = v;
}

// FUNCTION: GAME 0x1FC740
int cCoreSave::GetOliviaCostumeNo()
{
    if (!m_save)
        return 0;
    return m_save->m_oliviaCostumeNo;
}

#ifdef NONMATCHING
// FUNCTION: GAME 0x1FA010
// Remaining diff (4 words): the clamp `i < 3 ? i : 4` is emitted as
// `addiu 4; slti; movz a1; addiu` instead of `slti; addiu v0,4; movn v0,a1,v1; addiu +1`.
int cCoreSave::getGameLevel()
{
    if (m_save == 0)
        return 0;
    int i = 0;
    for (; i < 5; i++) {
        if (m_save->m_gameLevelPoint < D_003BF160[i])
            break;
    }
    if (i >= 3)
        i = 4;
    return i + 1;
}
#endif

#ifdef NONMATCHING
// FUNCTION: GAME 0x1FA6C0
// Remaining diff (4 words): original loads clear in the beqz delay slot and uses
// `beql r,0 -> 1`; compiler emits `movz` instead.
int cCoreSave::getClearNum()
{
    if (m_save == 0)
        return 0;
    int r = m_save->m_clearNum;
    if ((D_00747A3C & 0x40000) && r == 0)
        r = 1;
    return r;
}
#endif

// FUNCTION: GAME 0x1FAD88
void cCoreSave::addVitalItem(unsigned char n)
{
    if (m_save) {
        m_save->m_vitalItem += n;
        if (m_save->m_vitalItem > 13)
            m_save->m_vitalItem = 13;
    }
}

// FUNCTION: GAME 0x1FB830
int cCoreSave::getComboMax(unsigned int i)
{
    if (m_save == 0)
        return 0;
    if (i > 5)
        return 0;
    return m_save->m_combo[i].m_comboMax;
}

// FUNCTION: GAME 0x1FBE40
void cCoreSave::addKillEmNum()
{
    if (m_save) {
        int l = getGameLevel() - 1;
        if (l >= 0) {
            if (l < 5) {
                m_save->m_killEmNum[l]++;
                m_save->m_allKillEmNum[l]++;
            }
        }
    }
}

// FUNCTION: GAME 0x1FA690
void cCoreSave::setClearNum(unsigned short v)
{
    if (m_save) {
        m_save->m_clearNum = v;
        if (m_save->m_clearNum > 99)
            m_save->m_clearNum = 99;
    }
}

// FUNCTION: GAME 0x1FBEE8
void cCoreSave::addKillNpcNum()
{
    if (m_save) {
        m_save->m_killNpcNum++;
        m_save->m_allKillNpcNum++;
    }
}

// FUNCTION: GAME 0x1FC0D8
void cCoreSave::setCostumeNo(unsigned char n)
{
    if (m_save) {
        m_save->m_prevCostumeNo = m_save->m_costumeNo;
        m_save->m_costumeNo = n;
    }
}

// FUNCTION: GAME 0x1FC150
int cCoreSave::ckPaper()
{
    if (m_save == 0)
        return 0;
    return m_save->m_paper != 0;
}

// FUNCTION: GAME 0x1FC630
void cCoreSave::addAllStageTime(unsigned int t)
{
    if (m_save)
        m_save->m_allStageTime += t;
}

// FUNCTION: GAME 0x1FAE40
void cCoreSave::addReelItem(unsigned char n)
{
    if (m_save)
        m_save->m_reelItem += n;
}

#ifdef NONMATCHING
// FUNCTION: GAME 0x1FAB28
// Remaining diff (5 words): the loop-back `bnez` delay slot is a nop and the sb stays
// before it (44 vs 40 bytes); original fills the delay slot with the sb.
void cCoreSave::clearGodItem()
{
    for (int i = 0; i < 6; i++)
        m_save->m_godItem[i] = 0;
}
#endif

// FUNCTION: GAME 0x1FBDD0
void cCoreSave::clearKillEmNum()
{
    if (m_save) {
        for (unsigned i = 0; i < 5; i++)
            m_save->m_killEmNum[i] = 0;
    }
}
