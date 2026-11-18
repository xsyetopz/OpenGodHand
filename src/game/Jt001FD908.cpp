// Jump-table switch unit (own file: its .rodata must be exactly the table).
struct Jb { char _p[0x48]; signed char m_48; signed char m_49; };

// FUNCTION: GAME 0x1FD908
static inline int Pick2(Jb *s, int a, int b)
{
    return s->m_49 != 1 ? a : b;
}
extern "C" int func_001FD908(Jb *self)
{
    switch (self->m_48) {
    case 0:
        return Pick2(self, 2, 1);
    case 1:
        return Pick2(self, 4, 3);
    case 2:
        return Pick2(self, 6, 5);
    case 3:
        return Pick2(self, 8, 7);
    case 4:
    default:
        return 0;
    }
}

