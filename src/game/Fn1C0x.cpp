// Medium integer units of the card-game objects (BlackJack, poker hand checks) in 0x1D0000-0x1E0000.
extern "C" void func_001DBFB8(void *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);

extern "C" void func_001D4D80(void *);
extern "C" void func_001D0C78(void *);
extern "C" void func_001DBF18(void *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);

// FUNCTION: GAME 0x1D0EA8
class BlackJack {
public:
    BlackJack();
    char _p0[0x1634];
    char card[0x34][8];
    int a[5];
    int b[5];
    char _p1[0x1800 - 0x17FC];
    int m1800, m1804, m1808;
    char _p2[0x1814 - 0x180C];
    int m1814, m1818, m181c;
    char m1820;
    char _p3;
    short s1[5];
    short s2[5];
};
BlackJack::BlackJack()
{
    char *c;
    int i, j, k, l, m;
    short w;
    int *pb;
    short *p1;
    short *p2;
    func_001D4D80(this);
    c = card[0];
    for (i = 0x33; i != -1; i--) {
        func_001D0C78(c);
        c += 8;
    }
    pb = b;
    p1 = s1;
    p2 = s2;
    m1800 = 0;
    m1804 = 0;
    m1808 = 0;
    m181c = 0;
    m1814 = 0;
    m1818 = 0;
    for (j = 4; j >= 0; j--)
        a[j] = 0;
    for (k = 4; k >= 0; k--)
        pb[k] = 0;
    w = 0x34;
    for (l = 4; l >= 0; l--)
        p1[l] = w;
    w = 0x34;
    for (m = 4; m >= 0; m--)
        p2[m] = w;
    m1820 = 0;
}

// FUNCTION: GAME 0x1DC1A8
extern "C" int func_001DC1A8(char *self)
{
    unsigned short a[4];
    unsigned short x[5], y[5];
    func_001DBF18(self, &a[0], &a[1], &a[2], &a[3]);
    if (a[0] == 5 || a[1] == 5 || a[2] == 5 || a[3] == 5) {
        func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
        if (x[0] == 0 && x[1] == 9 && x[2] == 10 && x[3] == 11 && x[4] == 12) {
            int **pp = (int **)(self + 0x3004);
            int i;
            for (i = 4; i >= 0; i--) {
                (*pp)[1] |= 4;
                pp++;
            }
            return 1;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x1DC5F8
extern "C" int func_001DC5F8(char *self)
{
    unsigned short y[5], x[5];
    unsigned short n;
    int i;
    func_001DBFB8(self, &y[0], &x[0], &y[1], &x[1], &y[2], &x[2], &y[3], &x[3], &y[4], &x[4]);
    n = 0;
    for (i = 0; i < 5; i++) {
        if (x[i] == 3) {
            n = 1;
            break;
        }
    }
    for (i = 0; i < 5; i++) {
        if (x[i] == 2) {
            n++;
            break;
        }
    }
    if (n == 2) {
        int **pp = (int **)(self + 0x3004);
        for (i = 4; i >= 0; i--) {
            (*pp)[1] |= 4;
            pp++;
        }
        return 1;
    }
    return 0;
}

class objScroll;
class SlotReelBase {
public:
    enum ePattId { P0 };
};
extern "C" void func_001E7E68(void *, objScroll *, SlotReelBase::ePattId *, unsigned);
extern "C" void func_001E79A8(void *, objScroll *);
extern "C" void func_001E3240(void *, int);
class Slot1 {
public:
    void Initialize(unsigned short, objScroll *, SlotReelBase::ePattId *, objScroll *, SlotReelBase::ePattId *, objScroll *, SlotReelBase::ePattId *, unsigned short, objScroll *);
    char _p[0x48C];
    unsigned short m_48c;
};
// FUNCTION: GAME 0x1DFC48
void Slot1::Initialize(unsigned short us, objScroll *a, SlotReelBase::ePattId *ap, objScroll *b, SlotReelBase::ePattId *bp, objScroll *c, SlotReelBase::ePattId *cp, unsigned short n, objScroll *d)
{
    char *self = (char *)this;
    if (a && b && c && ap && bp && cp && d && n < 22) {
        func_001E7E68(self + 0x58, a, ap, n);
        func_001E7E68(self + 0x160, b, bp, n);
        func_001E7E68(self + 0x268, c, cp, n);
        func_001E79A8(self + 0x370, d);
        m_48c = us;
        func_001E3240(this, 0);
    }
}
