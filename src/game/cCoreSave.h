#ifndef CCORESAVE_H
#define CCORESAVE_H

enum PL_SKILL { PL_SKILL_NONE = -1, PL_SKILL_0 = 0 };
enum eCommandNo { eCommandNo_NONE = -1, eCommandNo_0 = 0 };
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
    char _pad88[0x2];
    unsigned char m_comboST;
    char _pad8B[1];
    unsigned short m_killEmNum[5];
    unsigned short m_killNpcNum;
    char _pad98[0xC];
    unsigned int m_clearStage;
    unsigned char m_godItem[6];
    unsigned char m_costumeNo;
    unsigned char m_prevCostumeNo;
    signed char m_skill[0x72];
    char _pad122[0xE];
    unsigned int m_godReel;
    char _pad134[0x20];
    unsigned char m_vitalItem;
    unsigned char m_tensionItem;
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
    int getReelItem();
    int ckClearStage(unsigned short);
    int ckGodReel(eCommandNo);
    void setSkill(PL_SKILL, signed char);
    signed char getSkill(PL_SKILL);
    int getGodItemNum();
    int addGodItem(unsigned char);
    void useGodItem();
    void setKeyCardNum(int);
    void setKeyNum(int);
    void addTensionItem(unsigned char);
    void addComboST(unsigned char);
    int getComboST();
    int getKillEmNum(int);
    int getAllKillEmNum(int);
    void setCasinoTicketNum(int);
    void addCasinoTicket(int);
    void setClearStage(unsigned short);
    void setComboMax(unsigned int, int);
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
