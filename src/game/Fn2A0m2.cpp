// Medium units of 0x2A0000-0x2BFFFF.
extern char Event[];
extern int D_00747A84;
extern "C" {
unsigned func_00297B98(void *);
float getCutFrame__C6cEvent(void *);

struct P2B {
    char _p[2];
    union { unsigned short h; unsigned char b; } m_2;
    unsigned short m_4;
    union { unsigned short h; unsigned char b; } m_6;
    unsigned short m_8;
};
struct E2B {
    char _p[0x44];
    unsigned char m_44;
    char _p1[3];
    int m_48;
    unsigned char m_4c;
    char _p2[3];
    int m_50;
    char _p3[0x8C - 0x54];
    P2B *m_8c;
};

// FUNCTION: GAME 0x2B2D88
int func_002B2D88(E2B *self)
{
    if (!(D_00747A84 & 0x20000000))
        return 0;
    self->m_44 = self->m_8c->m_2.h == 0xFF ? func_00297B98(Event) : self->m_8c->m_2.b;
    self->m_48 = self->m_8c->m_4;
    self->m_4c = self->m_8c->m_6.h == 0xFF ? func_00297B98(Event) : self->m_8c->m_6.b;
    self->m_50 = self->m_8c->m_8;
    if (func_00297B98(Event) < self->m_44)
        return 1;
    if (getCutFrame__C6cEvent(Event) >= (float)self->m_48)
        return 0;
    return 1;
}
}

extern "C" {
// FUNCTION: GAME 0x2AA2D0
void func_002AA2D0(void *, char *s, char *d)
{
#define W(T, o) *(T *)(d + o)
#define R(T, o) *(T *)(s + o)
    W(int, 0x1C) = (int)s;
    W(int, 0x84) = 0xBC614E;
    W(unsigned char, 0x88) = R(unsigned char, 0x66);
    W(int, 0x2C) = R(int, 0x4);
    W(float, 0x38) = R(float, 0x8);
    W(float, 0x3C) = R(float, 0xC);
    W(float, 0x40) = R(float, 0x28);
    W(float, 0x44) = R(float, 0x2C);
    W(float, 0x48) = R(float, 0x24);
    W(int, 0x4C) = R(int, 0x50);
    W(float, 0x68) = R(float, 0x14);
    W(float, 0x6C) = R(float, 0x18);
    W(float, 0x70) = R(float, 0x40);
    W(float, 0x74) = R(float, 0x44);
    W(float, 0x78) = R(float, 0x48);
    W(float, 0x7C) = R(float, 0x4C);
    W(unsigned char, 0x89) = R(unsigned char, 0x54);
    W(unsigned char, 0x28) = R(unsigned char, 0x1);
    W(unsigned char, 0x29) = R(unsigned char, 0x2);
    W(unsigned char, 0x2A) = R(unsigned char, 0x3);
    W(unsigned char, 0x8A) = R(unsigned char, 0x55);
    W(unsigned char, 0x8B) = R(unsigned char, 0x56);
    W(unsigned char, 0x8D) = R(unsigned char, 0x58);
    W(unsigned short, 0x8E) = R(unsigned short, 0x5A);
    W(float, 0x80) = R(float, 0x60);
    W(unsigned char, 0x2B) = R(unsigned char, 0x59);
    W(unsigned char, 0x8C) = R(unsigned char, 0x65);
    W(char *, 0x0) = s + 0x130;
    W(char *, 0x4) = s + 0x70;
    W(char *, 0x8) = s + 0x1B4;
    W(char *, 0xC) = s + 0x218;
    W(char *, 0x10) = s + 0x27C;
    W(unsigned short, 0x90) = 0;
}
}

extern char CoreSave[];
extern char *Cockpit;
extern unsigned short D_00747A50;
extern "C" {
int getGameDifficulty__9cCoreSave(void *);
void func_002A9B50(void *);
struct G2A {
    float m_0;
    float m_4;
    float m_8;
    char _p[4];
    unsigned char m_10;
};

// FUNCTION: GAME 0x2A9978
void AddHeatGage__8cHeatSysfUi(G2A *self, float amt, int a1)
{
    float old = self->m_4;
    if (a1 == 0 && self->m_10 != 0 && 0.0f < amt)
        return;
    if (!(*(unsigned *)(*(char **)CoreSave + 0x14) & 0x4000000) && getGameDifficulty__9cCoreSave(CoreSave) == 0)
        amt *= 1.25f;
    if (amt >= 120.0f)
        *(unsigned *)(Cockpit + 0x4F0) |= 0x1000000;
    if (D_00747A50 == 0x801)
        amt *= 1.25f;
    self->m_4 = self->m_4 + amt;
    if (self->m_0 < self->m_4)
        self->m_4 = self->m_0;
    if (0.0f < amt) {
        self->m_8 = self->m_8 + (self->m_4 - old);
        if (self->m_0 < self->m_8)
            self->m_8 = self->m_0;
    }
    func_002A9B50(self);
}
}
