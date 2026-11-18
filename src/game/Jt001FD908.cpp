// Jump-table switch unit (own file: its .rodata must be exactly the table).
struct Jb { char _p[0x48]; signed char m_48; signed char m_49; };

#ifdef NONMATCHING
// DRAFT: GAME 0x1FD908 - 15 words differ: original shares one `xori; jr; movz` tail across the four arms.
extern "C" int func_001FD908(Jb *self)
{
    switch (self->m_48) {
    case 0:
        return self->m_49 == 1 ? 1 : 2;
    case 1:
        return self->m_49 != 1 ? 4 : 3;
    case 2:
        return self->m_49 != 1 ? 6 : 5;
    case 3:
        return self->m_49 != 1 ? 8 : 7;
    case 4:
    default:
        return 0;
    }
}
#endif
