#ifndef CCORESAVE_H
#define CCORESAVE_H

enum eDifficulty { DIFFICULTY_0, DIFFICULTY_1, DIFFICULTY_2 };

struct sSaveData {
    char _pad0[0x12];
    unsigned short m_continueNum;
    char _pad14[0x8];
    short m_gameLevelPoint;
    char _pad1E[0x1];
    char m_difficulty;
    int m_gold;
    int m_addGold;
    char _pad28[0x40];
    int m_keyCardNum;
    int m_keyNum;
    char _pad70[0x10];
    int m_vitalMax;
    int m_vital;
    char _pad88[0xE];
    short m_killNpcNum;
    char _pad98[0x10];
    unsigned char m_godItem;
    char _padA9[0x5];
    unsigned char m_costumeNo;
    char _padAF[0xAE5];
    int m_casinoTicketNum;
    char _padB98[0x10];
    int m_fightingRingEmListNo;
    char _padBAC[0xA];
    unsigned short m_allKillNpcNum;
    unsigned short m_allContinueNum;
    char _padBBA[0x6];
    int m_oliviaCostumeNo;
};

class cCoreSave {
public:
    int getGameLevelPoint();
    void setGameDifficulty(eDifficulty);
    int getGameDifficulty();
    void setGold(int);
    int getGold();
    void initAddGold();
    int getKeyCardNum();
    int getKeyNum();
    unsigned char getGodItem();
    int getVital();
    int getVitalMax();
    void setVital(int);
    void clearKillNpcNum();
    int getKillNpcNum();
    int getContinueNum();
    void initContinueNum();
    int getCostumeNo();
    int getCasinoTicketNum();
    int GetFightingRingEmListNo();
    int getAllKillNpcNum();
    int getAllContinueNum();
    void SetOliviaCostumeNo(unsigned int);
    int GetOliviaCostumeNo();

    sSaveData *m_save;
};

#endif
