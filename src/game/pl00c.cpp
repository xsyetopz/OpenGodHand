#include "game/pl00Decls.h"

// FUNCTION: GAME 0x2CA690
extern "C" void func_002CA690()
{
    func_00325DC0(0);
}

#ifdef NONMATCHING
// 0x2CC5C0: 4 words differ; original uses bnel with the m84 store in the delay slot, mine uses bnez plus nop
extern "C" void func_002CC5C0(sSndNode *n)
{
    n->m_unk88 = Snd.m_unk18;
    if (!Snd.m_unk18) {
        Snd.m_unk18 = n;
        return;
    }
    Snd.m_unk18->m_unk84 = n;
}
#endif

#ifdef NONMATCHING
// 0x2CFF30: 8 words differ; mine hoists the m18 store above m20 and the byte stores
extern "C" sClr *func_002CFF30(sClr *f)
{
    f->m20 = -1;
    f->m0 = 0;
    f->m1 = 0;
    f->m4 = 0;
    f->mC = 0;
    f->m10 = 0;
    f->m14 = 0;
    f->m18 = -1;
    return f;
}
#endif
