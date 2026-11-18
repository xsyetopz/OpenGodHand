// Small units in 0x1E0000-0x1F0000 (continued from Fn1E0r.cpp).

extern char *Cockpit;
extern "C" void func_00143A90(char *);

// FUNCTION: GAME 0x1E31B0
extern "C" void func_001E31B0(int *self)
{
    switch (self[2]) {
    case 0:
        func_00143A90(Cockpit + 0x1AE0);
        self[2] = self[2] + 1;
    case 1:
        self[0x15] |= 1;
        break;
    }
}

// FUNCTION: GAME 0x1E6718
extern "C" void func_001E6718(int *self)
{
    switch (self[2]) {
    case 0:
        func_00143A90(Cockpit + 0x1AE0);
        self[2] = self[2] + 1;
    case 1:
        self[0x15] |= 1;
        break;
    }
}

class CustomIDWork {
public:
    CustomIDWork();
    void SetMessNo(int);
    void SetDisp(bool);
    void SetNumber(int);
};

// FUNCTION: GAME 0x1ECFE8
extern "C" void func_001ECFE8(char *self, unsigned short i, int m)
{
    if (i < 5) {
        int off = i * 0x7C;
        ((CustomIDWork *)(self + 0x4BC + off))->SetMessNo(m);
        ((CustomIDWork *)(self + 0x12C8 + off))->SetMessNo(m);
    }
}

// FUNCTION: GAME 0x1ED7E0
extern "C" void func_001ED7E0(char *self)
{
    ((CustomIDWork *)(self + 0x60))->SetDisp(false);
    ((CustomIDWork *)(self + 0xDC))->SetDisp(false);
    ((CustomIDWork *)(self + 0x158))->SetDisp(false);
    ((CustomIDWork *)(self + 0x1D4))->SetDisp(false);
    *(int *)(self + 0x348) = 0;
    *(int *)self &= -2;
}

void displayScrollLayer(unsigned int, bool);

// FUNCTION: GAME 0x1E3DD0
extern "C" void func_001E3DD0(char *self)
{
    unsigned int u = *(unsigned short *)(self + 0x4A8);
    if (u & 0x8000) {
        u++;
        *(unsigned short *)(self + 0x4A8) = u;
        if ((u & 0x3FFF) >= 8) {
            unsigned short w = (~u & 0x4000) | 0x8000;
            *(unsigned short *)(self + 0x4A8) = w;
            if (w & 0x4000)
                displayScrollLayer(*(unsigned *)(self + 0x430), true);
            else
                displayScrollLayer(*(unsigned *)(self + 0x430), false);
        }
    }
}

// FUNCTION: GAME 0x1E6CD8
extern "C" void func_001E6CD8(char *self)
{
    unsigned int u = *(unsigned short *)(self + 0x3E2);
    if (u & 0x8000) {
        u++;
        *(unsigned short *)(self + 0x3E2) = u;
        if ((u & 0x3FFF) >= 8) {
            unsigned short w = (~u & 0x4000) | 0x8000;
            *(unsigned short *)(self + 0x3E2) = w;
            if (w & 0x4000)
                displayScrollLayer(*(unsigned *)(self + 0x3C8), true);
            else
                displayScrollLayer(*(unsigned *)(self + 0x3C8), false);
        }
    }
}

// FUNCTION: GAME 0x1E6DA0
extern "C" void func_001E6DA0(char *self)
{
    unsigned int u = *(unsigned short *)(self + 0x3E4);
    if (u & 0x8000) {
        u++;
        *(unsigned short *)(self + 0x3E4) = u;
        if ((u & 0x3FFF) >= 8) {
            unsigned short w = (~u & 0x4000) | 0x8000;
            *(unsigned short *)(self + 0x3E4) = w;
            if (w & 0x4000)
                displayScrollLayer(*(unsigned *)(self + 0x3C8), true);
            else
                displayScrollLayer(*(unsigned *)(self + 0x3C8), false);
        }
    }
}

// FUNCTION: GAME 0x1E6E68
extern "C" void func_001E6E68(char *self)
{
    unsigned int u = *(unsigned short *)(self + 0x3E6);
    if (u & 0x8000) {
        u++;
        *(unsigned short *)(self + 0x3E6) = u;
        if ((u & 0x3FFF) >= 8) {
            unsigned short w = (~u & 0x4000) | 0x8000;
            *(unsigned short *)(self + 0x3E6) = w;
            if (w & 0x4000)
                displayScrollLayer(*(unsigned *)(self + 0x3C8), true);
            else
                displayScrollLayer(*(unsigned *)(self + 0x3C8), false);
        }
    }
}

class cVec;
class cArea {
public:
    int HitCheck(const cVec &) const;
    int HitCheck(const cVec &, float) const;
};
extern "C" int func_001F8488(const cArea *, const cVec *);
extern "C" int func_001F8550(const cArea *, const cVec *);
extern "C" int func_001F85D0(const cArea *, const cVec *, float);
extern "C" int func_001F8810(const cArea *, const cVec *, float);

// FUNCTION: GAME 0x1F83E8
int cArea::HitCheck(const cVec &p) const
{
    switch (((const unsigned char *)this)[1]) {
    case 1:
        return func_001F8488(this, &p);
    case 2:
        return func_001F8550(this, &p);
    }
    return 0;
}

// FUNCTION: GAME 0x1F8438
int cArea::HitCheck(const cVec &p, float r) const
{
    switch (((const unsigned char *)this)[1]) {
    case 1:
        return func_001F85D0(this, &p, r);
    case 2:
        return func_001F8810(this, &p, r);
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1FAA68 - 13 words: conditional-move register allocation
extern "C" void func_001FAA68(int **self, unsigned int i, int v)
{
    int *t = *self;
    if (t) {
        if (i >= 5)
            i = 0;
        int a = v < 10 ? v : 9;
        if (a < 0)
            a = 0;
        t[0x70 / 4 + i] = a;
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1FC4D0 - 16 words: bit test folds to srav/andi where target uses sllv/and/sltu
extern "C" int func_001FC4D0(int **self, unsigned int idx)
{
    int *t = *self;
    if (!t)
        return 0;
    unsigned int w = idx >> 5;
    if (w < 4) {
        unsigned int m = 1u << (idx & 31);
        unsigned int v = t[0xB98 / 4 + w];
        if (v & m)
            return 1;
        return 0;
    }
    return 0;
}
#endif

extern "C" void func_001F29C0(char *, int, int);

// FUNCTION: GAME 0x1F2B28
extern "C" void func_001F2B28(char *self, int m, int n)
{
    ((CustomIDWork *)(self + 0x348))->SetNumber(m);
    func_001F29C0(self, 6, n);
    func_001F29C0(self, 5, n);
}

// FUNCTION: GAME 0x1E4438
extern "C" void func_001E4438(char *self, unsigned short i, int on)
{
    if (i < 3) {
        if (on) {
            *(unsigned short *)(self + 0x4C0) = (i << 11) | 0x8000;
        } else {
            *(unsigned short *)(self + 0x4C0) = 0;
            switch (i) {
            case 0:
                displayScrollLayer(*(unsigned *)(self + 0x480), false);
                break;
            case 1:
                displayScrollLayer(*(unsigned *)(self + 0x480), false);
                break;
            }
        }
    }
}

class ColiseumBattle;
typedef void (ColiseumBattle::*CbFn)();
extern "C" CbFn D_003BE548[];
extern short D_005CAE40;

class ColiseumBattle {
public:
    void Main();
    int m_pad0;
    int m_st;
    char m_pad8[0x4C];
    unsigned int m_f0 : 1;
    unsigned int m_f1 : 1;
    unsigned int m_f2 : 1;
};

// FUNCTION: GAME 0x1EEC98
void ColiseumBattle::Main()
{
    (this->*D_003BE548[m_st])();
    long l = *(unsigned *)((char *)this + 0x54);
    long b = (l >> 2) & 1;
    if (b)
        D_005CAE40 = 0xF;
}
