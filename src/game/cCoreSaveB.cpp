#include "game/cCoreSave.h"

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

// FUNCTION: GAME 0x1FAB28
void cCoreSave::clearGodItem()
{
    for (int i = 0; i < 6; i++)
        m_save->m_godItem[i] = 0;
}

// FUNCTION: GAME 0x1FBDD0
void cCoreSave::clearKillEmNum()
{
    if (m_save) {
        for (unsigned i = 0; i < 5; i++)
            m_save->m_killEmNum[i] = 0;
    }
}

// FUNCTION: GAME 0x1FA908
void cCoreSave::setKeyCardNum(int n)
{
    if (m_save) {
        m_save->m_keyCardNum = n;
        if (m_save->m_keyCardNum > 9)
            m_save->m_keyCardNum = 9;
        if (m_save->m_keyCardNum < 0)
            m_save->m_keyCardNum = 0;
    }
}

// FUNCTION: GAME 0x1FA9B8
void cCoreSave::setKeyNum(int n)
{
    if (m_save) {
        m_save->m_keyNum = n;
        if (m_save->m_keyNum > 9)
            m_save->m_keyNum = 9;
        if (m_save->m_keyNum < 0)
            m_save->m_keyNum = 0;
    }
}

// FUNCTION: GAME 0x1FC388
void cCoreSave::setCasinoTicketNum(int n)
{
    if (m_save) {
        m_save->m_casinoTicketNum = n;
        if (m_save->m_casinoTicketNum > 9)
            m_save->m_casinoTicketNum = 9;
        if (m_save->m_casinoTicketNum < 0)
            m_save->m_casinoTicketNum = 0;
    }
}

// FUNCTION: GAME 0x1FC3E8
void cCoreSave::addCasinoTicket(int n)
{
    if (m_save) {
        m_save->m_casinoTicketNum += n;
        if (m_save->m_casinoTicketNum > 9)
            m_save->m_casinoTicketNum = 9;
        if (m_save->m_casinoTicketNum < 0)
            m_save->m_casinoTicketNum = 0;
    }
}

// FUNCTION: GAME 0x1FADF0
void cCoreSave::addTensionItem(unsigned char n)
{
    if (m_save) {
        m_save->m_tensionItem += n;
        if (m_save->m_tensionItem > 5)
            m_save->m_tensionItem = 5;
    }
}

// FUNCTION: GAME 0x1FBD28
void cCoreSave::addComboST(unsigned char n)
{
    if (m_save) {
        m_save->m_comboST += n;
        if (m_save->m_comboST > 6)
            m_save->m_comboST = 6;
    }
}

// FUNCTION: GAME 0x1FBD60
int cCoreSave::getComboST()
{
    if (m_save == 0)
        return 0;
    if (D_00747A34 & 0x1000000)
        m_save->m_comboST = 6;
    return m_save->m_comboST;
}

// FUNCTION: GAME 0x1FBE08
int cCoreSave::getKillEmNum(int n)
{
    if (m_save == 0)
        return 0;
    n -= 1;
    if (n < 0)
        return 0;
    if (n >= 5)
        return 0;
    return (short)m_save->m_killEmNum[n];
}

// FUNCTION: GAME 0x1FC580
int cCoreSave::getAllKillEmNum(int n)
{
    if (m_save == 0)
        return 0;
    n -= 1;
    if (n < 0)
        return 0;
    if (n >= 5)
        return 0;
    return m_save->m_allKillEmNum[n];
}

// FUNCTION: GAME 0x1FBF90
void cCoreSave::setClearStage(unsigned short n)
{
    if (m_save) {
        unsigned int f = 0;
        unsigned int i = 0;
        do {
            f |= 1 << i;
            i++;
        } while (i <= n);
        m_save->m_clearStage = f;
    }
}

// FUNCTION: GAME 0x1FB868
void cCoreSave::setComboMax(unsigned int i, int v)
{
    // Clamping v in place keeps it in its argument register, as the original does.
    if (m_save && i < 6) {
        if (v < 0)
            v = 0;
        if (v > 6)
            v = 6;
        m_save->m_combo[i].m_comboMax = v;
    }
}
