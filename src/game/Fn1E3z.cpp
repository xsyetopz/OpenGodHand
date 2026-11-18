extern "C" void func_001E87E0(char *, void *, void *, unsigned short);
extern "C" void func_001E79A8(char *, void *);
extern "C" void func_001E67A8(char *, int);
extern "C" void displayScrollLayer__FUib(unsigned, int);
#define CASE(k) \
    *(unsigned short *)(self + 0x49C + 2 * (k)) = 0; \
    if (a3) \
        *(unsigned short *)(self + 0x49C + 2 * (k)) = 0x8000; \
    if (a2) { \
        displayScrollLayer__FUib(*(unsigned *)(self + 0x448 + 4 * (k)), 1); \
        *(unsigned short *)(self + 0x49C + 2 * (k)) |= 0x4000; \
    } else \
        displayScrollLayer__FUib(*(unsigned *)(self + 0x448 + 4 * (k)), 0); \
    break;
// FUNCTION: GAME 0x1E3758
extern "C" void func_001E3758(char *self, unsigned short idx, int a2, int a3)
{
    switch (idx) {
    case 0:
        CASE(0)
    case 1:
        CASE(1)
    case 2:
        CASE(2)
    }
}

#define L(o, f) displayScrollLayer__FUib(*(unsigned *)(self + o), f)
// FUNCTION: GAME 0x1E4520
extern "C" void func_001E4520(char *self, unsigned char m)
{
    if (m < 2 && *(int *)(self + 0x4B0) && *(int *)(self + 0x4B4)) {
        L(0x454, 0);
        L(0x458, 0);
        L(0x45C, 0);
        L(0x460, 0);
        L(0x484, 0);
        L(0x488, 0);
        *(int *)(self + 0x54) &= -0x201;
        switch (m) {
        case 0:
            break;
        case 1:
            {
            **(int **)(*(char **)(self + 0x4B0) + 0xF0) = 0;
            **(int **)(*(char **)(self + 0x4B4) + 0xF0) = 0;
            L(0x454, 1);
            L(0x484, 1);
            *(int *)(self + 0x54) |= 0x200;
            }
            break;
        }
    }
}

// FUNCTION: GAME 0x1E47C0
extern "C" void Initialize__5Slot2UsP9objScrollPQ212SlotReelBase7ePattIdT2T3T2T3UsT2(char *self, unsigned short id, void *p2, void *p3, void *p4, void *p5, void *p6, void *p7, unsigned short n, void *p9)
{
    if (p2 && p4 && p6 && p3 && p5 && p7 && p9 && n < 0x16) {
        func_001E87E0(self + 0x58, p2, p3, n);
        func_001E87E0(self + 0x140, p4, p5, n);
        func_001E87E0(self + 0x228, p6, p7, n);
        func_001E79A8(self + 0x310, p9);
        *(unsigned short *)(self + 0x3D0) = id;
        func_001E67A8(self, 0);
        *(unsigned short *)(self + 0x3E0) = 0;
        *(unsigned short *)(self + 0x3E2) = 0;
        *(unsigned short *)(self + 0x3E4) = 0;
        *(unsigned short *)(self + 0x3E6) = 0;
        *(unsigned short *)(self + 0x3E8) = 0;
        *(unsigned char *)(self + 0x3D8) = 0;
    }
}

// FUNCTION: GAME 0x1E3630
extern "C" void func_001E3630(char *self)
{
    switch (*(unsigned short *)(self + 0x48E)) {
    case 0:
        L(0x434, 0); L(0x438, 0); L(0x43C, 0); L(0x440, 0); L(0x444, 0);
        break;
    case 1:
        L(0x434, 1); L(0x438, 0); L(0x43C, 0); L(0x440, 0); L(0x444, 0);
        break;
    case 2:
        L(0x434, 1); L(0x438, 1); L(0x43C, 1); L(0x440, 0); L(0x444, 0);
        break;
    case 3:
        L(0x434, 1); L(0x438, 1); L(0x43C, 1); L(0x440, 1); L(0x444, 1);
        break;
    }
}
