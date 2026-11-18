// Medium integer units of the card-game objects (Poker, BlackJack, hand tally) in 0x1D0000-0x1E0000.
extern "C" void func_001DF858(void *);
extern "C" void func_001D6DB0(void *);
extern "C" int func_001D4720(void *);
extern "C" int func_001D47E8(void *);
extern "C" int func_001D48B0(void *);
extern "C" int func_001D4918(void *);
extern "C" int func_001D49B0(void *);
extern "C" void initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void restartAnim__7cIDBase(void *);
extern "C" void *getIDWork__7cIDBasei(void *, int);
extern "C" void Initialize__12CustomIDWorkP7cIDWork(void *, void *);
extern "C" void SetDisp__12CustomIDWorkb(void *, int);
extern "C" void SetMessNo__12CustomIDWorki(void *, int);
extern "C" void func_001DEE60(void *, int, int);
extern "C" int func_001DC1A8(void *);
extern "C" int func_001DC2B8(void *);
extern "C" int func_001DC4C0(void *);
extern "C" int func_001DC5F8(void *);
extern "C" int func_001DC710(void *);
extern "C" int func_001DC798(void *);
extern "C" int func_001DC980(void *);
extern "C" int func_001DCAD8(void *);
extern "C" int func_001DCC30(void *);

// FUNCTION: GAME 0x1D6FE0
class Poker {
public:
    Poker();
    char _p0[0x2E64];
    char card[0x34][8];
    int a[5];
    char _p1[0x3018 - 0x3018];
    char hand[8];
    int m3020;
    char m3024, m3025;
    char _p2[0x3034 - 0x3026];
    int m3034, m3038;
    char _p3[0x3048 - 0x303C];
    int m3048, m304C;
    char m3050;
    char _p4;
    short s[5];
};
Poker::Poker()
{
    char *c;
    int i, j, k;
    short w;
    short *ps;
    func_001DF858(this);
    c = card[0];
    for (i = 0x33; i != -1; i--) {
        func_001D6DB0(c);
        c += 8;
    }
    func_001D6DB0(this->hand - 0);
    m3020 = 0;
    m3048 = 9;
    m3024 = 0;
    m3025 = 0;
    m304C = 0;
    m3034 = 0;
    m3038 = 0;
    for (j = 4; j >= 0; j--)
        a[j] = 0;
    ps = s;
    w = 0x34;
    for (k = 4; k >= 0; k--)
        ps[k] = w;
    m3050 = 0;
}

// FUNCTION: GAME 0x1D3430
extern "C" void func_001D3430(char *self)
{
    int a = func_001D4720(self);
    int b = func_001D47E8(self);
#define SET(v) { *(int *)(self + 0x1808) = 0; *(int *)(self + 0x1804) = (v); }
    if (func_001D48B0(self)) {
        if (func_001D4918(self))
            SET(0x10)
        else
            SET(0x11)
    } else if (func_001D49B0(self)) {
        SET(0xF)
    } else if (a == 0x15) {
        if (func_001D4918(self))
            SET(0xF)
        else if (b == a)
            SET(0x10)
        else
            SET(0xE)
    } else if (a < 0x15) {
        if (b < a)
            SET(0xE)
        else if (b >= 0x16)
            SET(0xE)
        else if (a == b)
            SET(0x10)
        else
            SET(0xF)
    }
}

// FUNCTION: GAME 0x1DECE0
extern "C" void func_001DECE0(char *self)
{
    char *base = self + 0x10;
    char *p;
    int i = 0;
    initialize__7cIDBase7eIdData5eIdNo(base, 0x12, 1);
    p = self + 0x60;
    restartAnim__7cIDBase(base);
    do {
        void *w = getIDWork__7cIDBasei(self + 0x10, i);
        i++;
        Initialize__12CustomIDWorkP7cIDWork(p, w);
        p += 0x7C;
    } while (i < 0x11);
    SetDisp__12CustomIDWorkb(self + 0x60, 0);
    SetMessNo__12CustomIDWorki(self + 0x3C4, 0x1000);
    SetMessNo__12CustomIDWorki(self + 0x4BC, 0x1001);
    SetMessNo__12CustomIDWorki(self + 0x538, 0x1002);
    func_001DEE60(self, 0x11, 0);
}

// FUNCTION: GAME 0x1DCDA8
extern "C" int func_001DCDA8(void *self)
{
    if (func_001DC1A8(self))
        return 0;
    if (func_001DC2B8(self))
        return 1;
    if (func_001DC4C0(self))
        return 2;
    if (func_001DC5F8(self))
        return 3;
    if (func_001DC710(self))
        return 4;
    if (func_001DC798(self))
        return 5;
    if (func_001DC980(self))
        return 6;
    if (func_001DCAD8(self))
        return 7;
    int r = func_001DCC30(self);
    int t = 8;
    if (!r)
        t = 9;
    return t;
}
