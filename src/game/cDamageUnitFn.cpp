class cDamageUnit {
public:
    void SetDamageCollActive(bool on);

    char _pad0[0x46];
    short m_flash;
    char _pad48[4];
    int m_f4C;
};

struct sDmgOwner {
    char _pad0[0x670];
    struct sUnitRef {
        cDamageUnit *m_unit;
        int _pad;
    } m_ref[5];
};

// FUNCTION: GAME 0x20F310
extern "C" void func_0020F310(sDmgOwner *self)
{
    self->m_ref[0].m_unit->m_flash = 0;
    self->m_ref[0].m_unit->m_f4C = 0;
    self->m_ref[0].m_unit->SetDamageCollActive(false);
    self->m_ref[1].m_unit->m_flash = 0;
    self->m_ref[1].m_unit->m_f4C = 0;
    self->m_ref[1].m_unit->SetDamageCollActive(false);
    self->m_ref[2].m_unit->m_flash = 0;
    self->m_ref[2].m_unit->m_f4C = 0;
    self->m_ref[2].m_unit->SetDamageCollActive(false);
    self->m_ref[3].m_unit->m_flash = 0;
    self->m_ref[3].m_unit->m_f4C = 0;
    self->m_ref[3].m_unit->SetDamageCollActive(false);
    self->m_ref[4].m_unit->m_flash = 0;
    self->m_ref[4].m_unit->m_f4C = 0;
    self->m_ref[4].m_unit->SetDamageCollActive(false);
}
