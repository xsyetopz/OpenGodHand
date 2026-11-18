// Small units in 0x180000-0x1A0000.

#define B(o) (*(unsigned char *)((char *)this + (o)))

class cOm1f {
public:
    void setStart();
};

#ifdef NONMATCHING
// DRAFT: GAME 0x195B30 - 12 words: target duplicates the store tails per case; tried goto/dup tails, k!=0&&k==1, store orders (14-15 words)
void cOm1f::setStart()
{
    int k = *(int *)((char *)this + 0x600);
    if (k == 0 || k != 1) {
        B(0x2F4) = 1;
        B(0x2F5) = 0;
    } else {
        B(0x2F4) = k;
        B(0x2F5) = k;
    }
    B(0x2F6) = 0;
    B(0x2F7) = 0;
}
#endif

// FUNCTION: GAME 0x194CB0
extern "C" void func_00194CB0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        *(unsigned short *)(self + 0xAF0) = 0;
        *(unsigned char *)(self + 0x2F6) = 1;
        *(unsigned char *)(self + 0x2F7) = 0;
    case 1: {
        int t = *(unsigned short *)(self + 0xAF0) - 1;
        *(unsigned short *)(self + 0xAF0) = t;
        if (t << 16 < 0) {
            unsigned char p = *(unsigned char *)(self + 0x2F5);
            *(unsigned char *)(self + 0x2F5) = 2;
            *(unsigned char *)(self + 0xAF2) = p;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
    }
}
