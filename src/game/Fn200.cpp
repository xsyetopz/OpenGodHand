// Small free units in 0x200000-0x20FFFF.
extern "C" {
struct Slot200 {
    int m_0;
    int m_4;
    char _p[0x88 - 8];
};
struct Obj200 {
    int m_0;
    int m_4;
    char _p[0x84 - 8];
    void *m_84;
};
struct Tbl200 {
    Obj200 *m_0;
    Slot200 m_s[32];
    int m_1104;
    int m_1108;
};

void func_00201290(Tbl200 *);
void func_00324008(void *);
void func_002018F0(Tbl200 *);
void func_00201228(Tbl200 *, Slot200 *);
void func_002011B0(Tbl200 *);
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

}

extern "C" {
// FUNCTION: GAME 0x201018
void func_00201018(Tbl200 *self)
{
    if (self->m_0 != 0) {
        if (self->m_0->m_84 != 0) {
            func_00324008(self->m_0->m_84);
            func_002018F0(self);
        }
        self->m_0 = 0;
    }
    for (int i = 0; i < 32; i++)
        func_00201228(self, &self->m_s[i]);
    self->m_1108 = 0;
}
}



struct Qa200 { float f[4] __attribute__((aligned(16))); };
#define QZ200(f) __asm__ volatile("sqc2 $vf0,%0" : "=m"(f))
extern const char D_004479C8[];
extern const char D_0042C7F0[];
extern "C" void *func_0028EB00(void *);
// FUNCTION: GAME 0x201FA0
extern "C" void *func_00201FA0(char *self)
{
    func_0028EB00(self);
    *(const void **)(self + 0x214) = D_004479C8;
    QZ200(*(Qa200 *)(self + 0x6C0));
    QZ200(*(Qa200 *)(self + 0x6D0));
    Qa200 *p = (Qa200 *)(self + 0x1620);
    QZ200(*(Qa200 *)(self + 0x1630));
    ((unsigned char *)p)[0x31] = 0xFF;
    QZ200(*(Qa200 *)(self + 0x1660));
    QZ200(*(Qa200 *)(self + 0x1680));
    QZ200(*(Qa200 *)(self + 0x1690));
    QZ200(*(Qa200 *)(self + 0x16A0));
    QZ200(*(Qa200 *)(self + 0x16B0));
    QZ200(*(Qa200 *)(self + 0x1840));
    Qa200 *q = (Qa200 *)(self + 0x18A0);
    for (int i = 3; i != -1;) {
        int ni = i - 1;
        Qa200 *nx = q + 2;
        for (int j = 1; j != -1; j--) {
            QZ200(*q);
            q++;
        }
        q = nx;
        i = ni;
    }
    QZ200(*(Qa200 *)(self + 0x1950));
    *(const void **)(self + 0x4AC) = D_0042C7F0;
    return self;
}

class classFADE {
public:
    char _p[0x1C];
    unsigned char m_1c;
    void start(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    void kill();
};
extern classFADE Fade;
extern unsigned D_00747A78;
extern int D_00747A24;
extern "C" void Set_bg_mode__FUiUcUcUc(unsigned, unsigned char, unsigned char, unsigned char);

extern "C" {
// FUNCTION: GAME 0x201D20
void func_00201D20(unsigned char *self)
{
    switch (self[1]) {
    case 0:
        if (self[3])
            Fade.start(0, 10, 0, 0, 0xFF000000, 60);
        else
            Fade.start(0, 10, 0, 0xFF000000, 0xFF000000, 60);
        self[1]++;
    case 1:
        if ((Fade.m_1c >> 2) & 1) {
            unsigned f = D_00747A78;
            f |= 0x80000000;
            f |= 0x40000000;
            f |= 0x20000000;
            f |= 0x10000000;
            f |= 0x8000000;
            f |= 0x4000000;
            f |= 0x804000;
            D_00747A78 = f;
            Set_bg_mode__FUiUcUcUc(1, 0, 0, 0);
            Fade.kill();
            self[1]++;
        }
        break;
    case 2:
        D_00747A24 = (D_00747A24 & ~8) | 0x8000;
        break;
    }
}
}
