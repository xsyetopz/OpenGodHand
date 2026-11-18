#ifndef CDAMAGEMANAGE_H
#define CDAMAGEMANAGE_H

class cGameObj;
class cDamageGive;
class cDamageTake;
enum DMG_KIND { DMG_KIND_0 };

class cDamageManage {
public:
    cDamageGive *CreateDamageGive(DMG_KIND kind, cGameObj *obj);
    int ReleaseDamageGive(cDamageGive *give);
    cDamageTake *CreateDamageTake(cGameObj *obj, DMG_KIND kind);
    int CkHitStop();

    char _pad0[0xACD0];
    unsigned int m_hitStop;
};

#endif
