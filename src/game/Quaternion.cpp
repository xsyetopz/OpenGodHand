// Small free functions around the Quaternion helpers (0x155000-0x15BFFF).

struct sMotState {
    char _pad0[4];
    int m_unk4;
    int m_unk8;
    unsigned short m_unkC;
    unsigned short m_unkE;
};

// FUNCTION: GAME 0x159998
extern "C" void func_00159998(sMotState *self)
{
    self->m_unk4 = 0;
    self->m_unk8 = 0;
    self->m_unkC = 0;
    self->m_unkE = 0;
}

// FUNCTION: GAME 0x1595E8
extern "C" void func_001595E8(char *self, int v)
{
    *(int *)(self + 0x424) = v;
}
