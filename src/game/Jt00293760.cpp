// Jump-table switch unit (own file: its .rodata must be exactly the table).
struct EvSlot {
    char _p0[0x564];
    int m_564;
};
struct EvHold {
    char _p0[0x574];
    EvSlot *m_574, *m_578, *m_57C, *m_580, *m_584;
};

// FUNCTION: GAME 0x293760
extern "C" void func_00293760(EvHold *self, EvSlot *p)
{
    if (p) {
        switch (p->m_564) {
        case 0x270:
            self->m_578 = p;
            break;
        case 0x271:
            self->m_57C = p;
            break;
        case 0x272:
            self->m_580 = p;
            break;
        case 0x273:
            self->m_584 = p;
            break;
        case 0x274:
            self->m_574 = p;
            break;
        }
    }
}
