struct COL {
    unsigned r : 8;
    unsigned g : 8;
    unsigned b : 8;
    unsigned a : 8;
};
extern "C" void SetColorAnimSin__12CustomIDWorkG3COLT1Us(void *, COL, COL, unsigned short);
extern "C" void ResetColorAnim__12CustomIDWork(void *);
#define PULSE(name, off) \
extern "C" void name(char *self, int on) \
{ \
    COL c1, c2; \
    if (on) { \
        c1.r = 0x60; \
        c1.g = 0x60; \
        c1.b = 0x60; \
        c1.a = 0x50; \
        c2.r = 0xA0; \
        c2.g = 0xA0; \
        c2.b = 0xA0; \
        c2.a = 0x80; \
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + off, c1, c2, 3); \
    } else { \
        ResetColorAnim__12CustomIDWork(self + off); \
    } \
}
// FUNCTION: GAME 0x1DDB10
PULSE(func_001DDB10, 0x1D4)
// FUNCTION: GAME 0x1DDBB8
PULSE(func_001DDBB8, 0x348)
// FUNCTION: GAME 0x1DDC60
PULSE(func_001DDC60, 0x4BC)
// FUNCTION: GAME 0x1DDD08
PULSE(func_001DDD08, 0x630)
// FUNCTION: GAME 0x1DF048
PULSE(func_001DF048, 0x158)
// FUNCTION: GAME 0x1DF0F0
PULSE(func_001DF0F0, 0x250)
extern "C" void func_001DD258(char *, int, int);
struct T5 { int a[5]; };
extern T5 D_0042B5D0;
// FUNCTION: GAME 0x1DDAB0
extern "C" void func_001DDAB0(char *s, unsigned char k, int c)
{
    if (k < 5) {
        T5 t = D_0042B5D0;
        func_001DD258(s, t.a[k], c);
    }
}
#define TRIO(name, n) \
extern "C" void name(char *s, unsigned char k) \
{ \
    switch (k) { \
    case 0: \
        func_001DD258(s, n, 1); \
        func_001DD258(s, n + 1, 1); \
        func_001DD258(s, n + 2, 1); \
        break; \
    case 1: \
        func_001DD258(s, n, 0); \
        func_001DD258(s, n + 1, 1); \
        func_001DD258(s, n + 2, 1); \
        break; \
    case 2: \
        func_001DD258(s, n, 0); \
        func_001DD258(s, n + 1, 0); \
        func_001DD258(s, n + 2, 1); \
        break; \
    } \
}
// FUNCTION: GAME 0x1DD770
TRIO(func_001DD770, 3)
// FUNCTION: GAME 0x1DD840
TRIO(func_001DD840, 6)
// FUNCTION: GAME 0x1DD910
TRIO(func_001DD910, 9)
// FUNCTION: GAME 0x1DD9E0
TRIO(func_001DD9E0, 12)
extern "C" void SetOffsetPosX__12CustomIDWorki(void *, int);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(void *, int, int, unsigned short);
extern "C" void func_001DEE60(char *, int, int);
// FUNCTION: GAME 0x1DF198
extern "C" void func_001DF198(char *s, unsigned char k)
{
    switch (k) {
    default:
    case 0:
        SetOffsetPosX__12CustomIDWorki(s + 0x158, -0x12C);
        func_001DEE60(s, 2, 0);
        func_001DEE60(s, 3, 0);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(s + 0x158, 0);
        func_001DEE60(s, 2, 0);
        func_001DEE60(s, 3, 1);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x158, -0x12C, 0, 10);
        func_001DEE60(s, 2, 0);
        func_001DEE60(s, 3, 1);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x158, 0, -0x12C, 10);
        break;
    }
}
// FUNCTION: GAME 0x1DF278
extern "C" void func_001DF278(char *s, unsigned char k)
{
    switch (k) {
    default:
    case 0:
        SetOffsetPosX__12CustomIDWorki(s + 0x250, 0x12C);
        func_001DEE60(s, 4, 0);
        func_001DEE60(s, 5, 0);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(s + 0x250, 0);
        func_001DEE60(s, 4, 0);
        func_001DEE60(s, 5, 1);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x250, 0x12C, 0, 10);
        func_001DEE60(s, 4, 0);
        func_001DEE60(s, 5, 1);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x250, 0, 0x12C, 10);
        break;
    }
}
// FUNCTION: GAME 0x1DE7C8
extern "C" void func_001DE7C8(char *s, unsigned char k)
{
    switch (k) {
    default:
    case 0:
        SetOffsetPosX__12CustomIDWorki(s + 0x994, -0xDC);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(s + 0x994, 0);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x994, -0xDC, 0, 10);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x994, 0, -0xDC, 10);
        break;
    }
}
extern "C" void func_001D51B8(char *, int, int);
#define TRI3(name, x, y, z) \
extern "C" void name(char *s, unsigned char k) \
{ \
    switch (k) { \
    case 0: \
        func_001D51B8(s, x, 1); \
        func_001D51B8(s, y, 1); \
        func_001D51B8(s, z, 1); \
        break; \
    case 1: \
        func_001D51B8(s, x, 0); \
        func_001D51B8(s, y, 1); \
        func_001D51B8(s, z, 1); \
        break; \
    case 2: \
        func_001D51B8(s, x, 0); \
        func_001D51B8(s, y, 0); \
        func_001D51B8(s, z, 1); \
        break; \
    } \
}
// FUNCTION: GAME 0x1D5360
TRI3(func_001D5360, 0xB, 0xC, 0x23)
// FUNCTION: GAME 0x1D5430
TRI3(func_001D5430, 9, 0xA, 0x24)
// FUNCTION: GAME 0x1D5500
TRI3(func_001D5500, 0xD, 0xE, 0xF)
// FUNCTION: GAME 0x1D5690
TRI3(func_001D5690, 0x10, 0x11, 0x12)
extern "C" void SetOffsetPosX__12CustomIDWorki(void *, int);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(void *, int, int, unsigned short);
// FUNCTION: GAME 0x1D6030
extern "C" void func_001D6030(char *s, unsigned short k)
{
    switch (k) {
    default:
    case 0:
        SetOffsetPosX__12CustomIDWorki(s + 0x3C4, -0x140);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(s + 0x3C4, 0);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x3C4, -0x140, 0, 10);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x3C4, 0, -0x140, 10);
        break;
    }
    func_001D51B8(s, 7, 0);
    func_001D51B8(s, 8, k != 0);
}
