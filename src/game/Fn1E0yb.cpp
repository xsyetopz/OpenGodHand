// FUNCTION: GAME 0x1FC468
extern "C" void SetFightingRingClearFlag__9cCoreSaveUib(char **self, unsigned idx, int on)
{
    char *p = *self;
    if (p == 0) return;
    unsigned w = idx >> 5;
    unsigned b = idx & 0x1F;
    if (w >= 4) return;
    if (on) {
        unsigned *q = (unsigned *)(p + 0xB98);
        q += w;
        *q |= 1u << b;
    } else {
        unsigned *q = (unsigned *)(p + 0xB98);
        q += w;
        *q &= ~(1u << b);
    }
}

// FUNCTION: GAME 0x1FA750
struct G { char pad[0x20]; int gold; int n; int log[16]; };
extern unsigned D_00747A34;
extern "C" void initAddGold__9cCoreSave(void *);
extern "C" void addGold__9cCoreSaveib(G **self, int amt, int flag)
{
    if (*self) {
        if ((*self)->n < 0x10) {
            (*self)->log[(*self)->n] = amt;
            (*self)->n++;
        }
        if (flag == 1) initAddGold__9cCoreSave(self);
        (*self)->gold += amt;
        if ((*self)->gold > 999999) (*self)->gold = 999999;
        if ((*self)->gold < 0) (*self)->gold = 0;
        if (D_00747A34 & 0x2000000) (*self)->gold = 999999;
    }
}
