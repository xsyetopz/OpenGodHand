// Small free units in 0x200000-0x20FFFF.
extern "C" {
struct Slot200 {
    int m_0;
    int m_4;
    char _p[0x88 - 8];
};
struct Tbl200 {
    int m_0;
    Slot200 m_s[32];
    int m_1104;
    int m_1108;
};

void func_00201290(Tbl200 *);
void func_00201718(Tbl200 *);

// FUNCTION: GAME 0x201250
void func_00201250(Tbl200 *self)
{
    for (int i = 0; i < 32; i++) {
        if (self->m_s[i].m_0 != 0) {
            self->m_1108 = 1;
            break;
        }
    }
}

// DRAFT: GAME 0x200B20
#ifdef NONMATCHING
// diff: 2 words, switch tree emits slti/bnez instead of beqz/beq on 1,0,2
void func_00200B20(Tbl200 *self)
{
    switch (self->m_1108) {
    case 1:
        func_00201290(self);
        break;
    case 2:
        func_00201718(self);
        break;
    case 0:
    default:
        func_00201250(self);
        break;
    }
}
#endif
}
