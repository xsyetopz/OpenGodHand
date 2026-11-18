// Free units in 0x2B0000-0x2BFFFF, 0x80-0x200 bytes.
extern char Event[];
extern "C" {
unsigned func_00297B98(void *);
float getCutFrame__C6cEvent(void *);

struct Ev2B {
    char _p[0x44];
    unsigned char m_44;
    char _p1[7];
    unsigned char m_4c;
    char _p2[3];
    int m_50;
};

// FUNCTION: GAME 0x2B47C8
int func_002B47C8(Ev2B *self)
{
    if (func_00297B98(Event) < self->m_44)
        return 0;
    if (func_00297B98(Event) < self->m_4c)
        return 1;
    float g = getCutFrame__C6cEvent(Event);
    if ((float)self->m_50 < g)
        return 0;
    return 1;
}
}
