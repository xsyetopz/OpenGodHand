#include "game/cDamageManage.h"

extern "C" {
cDamageGive *func_001FE1E0(cDamageManage *);
int func_001FD2C0(cDamageGive *, DMG_KIND, cGameObj *);
void func_001FD580(cDamageGive *);
void func_001FCDB8(cDamageGive *);
cDamageTake *func_001FE310(cDamageManage *);
int func_001FD530(cDamageTake *, cGameObj *, DMG_KIND);
}

// FUNCTION: GAME 0x1FE0E8
cDamageGive *cDamageManage::CreateDamageGive(DMG_KIND kind, cGameObj *obj)
{
    cDamageGive *g = func_001FE1E0(this);
    if (!g)
        return 0;
    if (!func_001FD2C0(g, kind, obj))
        g = 0;
    return g;
}

// FUNCTION: GAME 0x1FE148
int cDamageManage::ReleaseDamageGive(cDamageGive *give)
{
    if (!give)
        return 0;
    func_001FD580(give);
    func_001FCDB8(give);
    return 1;
}

// FUNCTION: GAME 0x1FE218
cDamageTake *cDamageManage::CreateDamageTake(cGameObj *obj, DMG_KIND kind)
{
    cDamageTake *t = func_001FE310(this);
    if (!t)
        return 0;
    if (!func_001FD530(t, obj, kind))
        t = 0;
    return t;
}

// FUNCTION: GAME 0x1FE358
int cDamageManage::CkHitStop()
{
    return m_hitStop != 0;
}
