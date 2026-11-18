#include "game/cObj.h"
class cOlT : public cObj {
public:
    void tick();
    char _pad2F8[0x654 - 0x2F8];
    short m_timer;
};
// FUNCTION: GAME 0x181C98
extern "C" void func_00181C98(cOlT *self)
{
    switch (self->m_act1) {
    case 0:
        self->m_timer = 15;
        self->m_act1 = 1;
        self->m_act2 = 0;
        self->m_act3 = 0;
    case 1:
        if (--self->m_timer <= 0) {
            self->m_act0 = 0;
            self->m_act1 = 0;
            self->m_act2 = 0;
            self->m_act3 = 0;
        }
    }
}
