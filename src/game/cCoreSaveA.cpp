#include "game/cCoreSave.h"

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
// NONMATCHING 0x1FA010
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
// NONMATCHING 0x1FA6C0
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
