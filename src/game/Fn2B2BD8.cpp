extern char Event[];
extern int D_00747A84;
extern "C" {
unsigned char func_00297B98(void *);
void func_00297BA8(void *, int);

struct P2C {
    char _p[2];
    union { unsigned short h; unsigned char b; } m_2;
    union { unsigned short h; unsigned char b; } m_4;
};
struct E2C {
    char _p[0x44];
    unsigned char m_44;
    char _p1[7];
    unsigned char m_4c;
    char _p2[0x8C - 0x4D];
    P2C *m_8c;
};

// FUNCTION: GAME 0x2B2BD8
int func_002B2BD8(E2C *self)
{
    if (!(D_00747A84 & 0x20000000))
        return 0;
    self->m_44 = self->m_8c->m_2.h == 0xFF ? func_00297B98(Event) : self->m_8c->m_2.b;
    self->m_4c = self->m_8c->m_4.h == 0xFF ? func_00297B98(Event) : self->m_8c->m_4.b;
    func_00297BA8(Event, self->m_4c);
    return func_00297B98(Event) < self->m_44;
}
}
