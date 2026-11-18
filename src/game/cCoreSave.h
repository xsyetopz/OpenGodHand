#ifndef CCORESAVE_H
#define CCORESAVE_H

enum eDifficulty { DIFFICULTY_0, DIFFICULTY_1, DIFFICULTY_2 };

struct sSaveData {
    char _pad0[0x10];
    unsigned short m_clearNum;
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
    char _pad88[0x4];
    unsigned short m_killEmNum[5];
    unsigned short m_killNpcNum;
    char _pad98[0x10];
    unsigned char m_godItem[6];
    unsigned char m_costumeNo;
    unsigned char m_prevCostumeNo;
    char _padB0[0xA4];
    unsigned char m_vitalItem;
    char _pad155[1];
    unsigned char m_reelItem;
    unsigned char m_paper;
    char _pad158[0x78];
    struct { int m_comboMax; char _pad4[0x20]; } m_combo[6];
    char _pad2A8[0x8EC];
    int m_casinoTicketNum;
    char _padB98[0x10];
    int m_fightingRingEmListNo;
    unsigned short m_allKillEmNum[5];
    unsigned short m_allKillNpcNum;
    unsigned short m_allContinueNum;
    char _padBBA[2];
    int m_allStageTime;
    int m_oliviaCostumeNo;
};

class cCoreSave {
public:
    int getGameLevel();
    int getClearNum();
    int getComboMax(unsigned int);
    void addVitalItem(unsigned char);
    void addKillEmNum();
    int getGameLevelPoint();
    void setClearNum(unsigned short);
    void addKillNpcNum();
    void setCostumeNo(unsigned char);
    int ckPaper();
    void addAllStageTime(unsigned int);
    void addReelItem(unsigned char);
    void clearGodItem();
    void clearKillEmNum();
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
