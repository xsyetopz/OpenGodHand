// God Hand: cEvent::movePlayInit (0x296CA8)
extern char D_Ev296A0[];
extern char D_Ev296B0[], D_Ev296B1[], D_Ev296B2[], D_Ev296B3[], D_Ev296B4[];
extern char D_Ev296B5[], D_Ev296B6[], D_Ev296B7[], D_Ev296B8[], D_Ev296B9[];
extern char D_Ev296C0[], D_Ev296C1[], D_Ev296C2[], D_Ev296C3[], D_Ev296C4[];
extern "C" void func_0(char *);
extern unsigned D_00747A84;

class cEvent {
public:
    int m0, m4;
    int m8;
    void movePlayInit();
};

// FUNCTION: GAME 0x296CA8
void cEvent::movePlayInit()
{
    unsigned long u = m8;
    unsigned long b1 = (u >> 1) & 1;
    if (b1) {
        unsigned long b2 = (u >> 2) & 1;
        if (b2)
            return;
        {
            D_00747A84 |= 1;
            func_0(D_Ev296A0);
            func_0(D_Ev296A0);
            func_0(D_Ev296B0);
            func_0(D_Ev296B1);
            func_0(D_Ev296B2);
            func_0(D_Ev296B3);
            func_0(D_Ev296B4);
            func_0(D_Ev296B5);
            func_0(D_Ev296B6);
            func_0(D_Ev296B7);
            func_0(D_Ev296B8);
            func_0(D_Ev296B9);
            func_0(D_Ev296C0);
            func_0(D_Ev296C1);
            func_0(D_Ev296C2);
            func_0(D_Ev296C3);
            func_0(D_Ev296C4);
            m8 |= 4;
        }
    }
}
