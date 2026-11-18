extern "C" {
void clearGodItem__9cCoreSave(char *);
void setGold__9cCoreSavei(char *, int);
void setGameLevel__9cCoreSavei(char *, int);
void func_001FACB0(char *);
int getVitalMax__9cCoreSave(char *);
void setVital__9cCoreSavei(char *, int);
void func_001FB980(char *);
void func_001FBDA0(char *, int);
void func_001FBD00(char *, int);
void func_001FAA68(char *, int, int);
void setClearNum__9cCoreSaveUs(char *, unsigned short);
void clearKillEmNum__9cCoreSave(char *);
void clearKillNpcNum__9cCoreSave(char *);
void initAddGold__9cCoreSave(char *);
void initContinueNum__9cCoreSave(char *);
void func_001FC090(char *);
void func_001FC100(char *, int);
void func_001F9FC0(char *);
void func_001FC278(char *);
void func_001FC320(char *);
void func_001FAE28(char *, int);
void func_001FC438(char *);
void func_001FC5E8(char *);
void func_001FC548(char *);
void func_001FC5B8(char *);
void func_001FC618(char *);
int getGameDifficulty__9cCoreSave(char *);
void func_001F9AD0(char *);
void func_001F9A98(char *);
void func_001F9AF0(char *);
void addGodItem__9cCoreSaveUc(char *, unsigned char);
}

// FUNCTION: GAME 0x1F98D0
extern "C" void gameInit__9cCoreSave(char *self)
{
    clearGodItem__9cCoreSave(self);
    setGold__9cCoreSavei(self, 0);
    setGameLevel__9cCoreSavei(self, 1);
    func_001FACB0(self);
    setVital__9cCoreSavei(self, getVitalMax__9cCoreSave(self));
    func_001FB980(self);
    func_001FBDA0(self, 0x80);
    func_001FBD00(self, 4);
    func_001FAA68(self, 0, 0);
    func_001FAA68(self, 1, 0);
    func_001FAA68(self, 2, 0);
    func_001FAA68(self, 3, 0);
    setClearNum__9cCoreSaveUs(self, 0);
    clearKillEmNum__9cCoreSave(self);
    clearKillNpcNum__9cCoreSave(self);
    initAddGold__9cCoreSave(self);
    initContinueNum__9cCoreSave(self);
    func_001FC090(self);
    func_001FC100(self, 0);
    func_001F9FC0(self);
    func_001FC278(self);
    func_001FC320(self);
    func_001FAE28(self, 2);
    func_001FC438(self);
    func_001FC5E8(self);
    func_001FC548(self);
    func_001FC5B8(self);
    func_001FC618(self);
    switch (getGameDifficulty__9cCoreSave(self)) {
    case 1:
    default:
        func_001F9AD0(self);
        break;
    case 0:
        func_001F9A98(self);
        break;
    case 2:
        func_001F9AF0(self);
        break;
    }
    addGodItem__9cCoreSaveUc(self, 1);
    addGodItem__9cCoreSaveUc(self, 1);
    addGodItem__9cCoreSaveUc(self, 1);
}
