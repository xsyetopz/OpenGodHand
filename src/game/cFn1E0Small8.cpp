extern "C" void func_001E8DF0(char *, int, int *, unsigned);
extern "C" void KeyStop__Fv();
extern int D_00747A78;
// FUNCTION: GAME 0x1E7E68
extern "C" void func_001E7E68(char *s, int a, int *b, unsigned c)
{
    c &= 0xFFFF;
    if (a && b && c < 0x16)
        func_001E8DF0(s, a, b, c);
}
// FUNCTION: GAME 0x1E87E0
extern "C" void func_001E87E0(int *s, int a, int *b, unsigned c)
{
    c &= 0xFFFF;
    if (a && b && c < 0x16) {
        func_001E8DF0((char *)s, a, b, c);
        s[1] = 0;
        s[2] = 0;
        s[3] = 0;
    }
}
// FUNCTION: GAME 0x1EFE70
extern "C" void PlCtrlOff__14ColiseumBattleb(char *s, int on)
{
    if (on) {
        KeyStop__Fv();
        *(unsigned *)(s + 0x54) |= 4;
    } else {
        D_00747A78 &= 0xFDFFFFFF;
        *(int *)(s + 0x54) &= ~4;
    }
}
extern "C" void displayScrollLayer__FUib(unsigned, int);
extern "C" void func_001E6820(void *);
#define L(o, v) displayScrollLayer__FUib(*(unsigned *)(s + (o)), v)
// FUNCTION: GAME 0x1E67A8
extern "C" void func_001E67A8(char *s, int a)
{
    func_001E6820(s);
    if (a) {
        L(0x3A0, 1);
        L(0x3A8, 1);
        L(0x3AC, 1);
        L(0x3B0, 1);
    } else
        L(0x3A4, 1);
}
// FUNCTION: GAME 0x1E6B70
extern "C" void func_001E6B70(char *s, int a, int b)
{
    *(unsigned short *)(s + 0x3E0) = 0;
    if (b)
        *(unsigned short *)(s + 0x3E0) = 0x8000;
    if (a) {
        *(unsigned short *)(s + 0x3E0) |= 0x4000;
        L(0x3C8, 1);
        L(0x3CC, 1);
    } else {
        L(0x3C8, 0);
        L(0x3CC, 0);
    }
}
// FUNCTION: GAME 0x1E3928
extern "C" void func_001E3928(char *s, int a, int b)
{
    *(unsigned short *)(s + 0x4A2) = 0;
    if (b)
        *(unsigned short *)(s + 0x4A2) = 0x8000;
    if (a) {
        *(unsigned short *)(s + 0x4A2) |= 0x4000;
        L(0x430, 1);
        L(0x47C, 1);
        L(0x464, 1);
        L(0x468, 1);
    } else {
        L(0x430, 0);
        L(0x47C, 0);
        L(0x464, 0);
        L(0x468, 0);
    }
}
#define SETD(name, fo, o3, o4) \
extern "C" void name(char *s, int a, int b) \
{ \
    *(unsigned short *)(s + fo) = 0; \
    if (b) \
        *(unsigned short *)(s + fo) = 0x8000; \
    if (a) { \
        *(unsigned short *)(s + fo) |= 0x4000; \
        L(0x430, 1); \
        L(0x47C, 1); \
        L(o3, 1); \
        L(o4, 1); \
    } else { \
        L(0x430, 0); \
        L(0x47C, 0); \
        L(o3, 0); \
        L(o4, 0); \
    } \
}
// FUNCTION: GAME 0x1E3A98
SETD(func_001E3A98, 0x4A4, 0x46C, 0x470)
// FUNCTION: GAME 0x1E3C08
SETD(func_001E3C08, 0x4A6, 0x474, 0x478)
#define TICK(name, fo, o3, o4) \
extern "C" void name(char *s) \
{ \
    unsigned v = *(unsigned short *)(s + fo); \
    if (v & 0x8000) { \
        v++; \
        *(unsigned short *)(s + fo) = v; \
        if ((v & 0x3FFF) >= 8) { \
            unsigned short w = (~v & 0x4000) | 0x8000; \
            *(unsigned short *)(s + fo) = w; \
            if (w & 0x4000) { \
                L(0x430, 1); \
                L(0x47C, 1); \
                L(o3, 1); \
                L(o4, 0); \
            } else { \
                L(0x430, 0); \
                L(0x47C, 0); \
                L(o3, 0); \
                L(o4, 1); \
            } \
        } \
    } \
}
// FUNCTION: GAME 0x1E39D0
TICK(func_001E39D0, 0x4A2, 0x464, 0x468)
// FUNCTION: GAME 0x1E3B40
TICK(func_001E3B40, 0x4A4, 0x46C, 0x470)
// FUNCTION: GAME 0x1E3CB0
TICK(func_001E3CB0, 0x4A6, 0x474, 0x478)
