extern "C" void SetOffsetPosX__12CustomIDWorki(void *, int);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(void *, int, int, unsigned short);
extern "C" void SetOffsetPosY__12CustomIDWorki(void *, int);
extern "C" void SetMoveOffsetPosY__12CustomIDWorkiiUs(void *, int, int, unsigned short);
extern "C" void func_001D51B8(char *, int, int);
extern "C" void func_001DD258(char *, int, int);
extern "C" void func_001DEE60(char *, int, int);

// FUNCTION: GAME 0x1D60F8
extern "C" void func_001D60F8(char *s, unsigned short k)
{
    switch (k) {
    default:
    case 0:
        SetOffsetPosX__12CustomIDWorki(s + 0x2CC, -0x140);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(s + 0x2CC, 0);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x2CC, -0x140, 0, 10);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x2CC, 0, -0x140, 10);
        break;
    }
    func_001D51B8(s, 5, 0);
    func_001D51B8(s, 6, k != 0);
}

#define YMOVE(name, fn) \
extern "C" void name(char *s, unsigned char k) \
{ \
    switch (k) { \
    default: \
    case 0: \
        SetOffsetPosY__12CustomIDWorki(s + 0xDC, -0x46); \
        fn(s, 1, 0); \
        break; \
    case 1: \
        SetOffsetPosY__12CustomIDWorki(s + 0xDC, 0); \
        fn(s, 1, 1); \
        break; \
    case 2: \
        SetMoveOffsetPosY__12CustomIDWorkiiUs(s + 0xDC, -0x46, 0, 10); \
        fn(s, 1, 1); \
        break; \
    case 3: \
        SetMoveOffsetPosY__12CustomIDWorkiiUs(s + 0xDC, 0, -0x46, 10); \
        fn(s, 1, 1); \
        break; \
    } \
}
// FUNCTION: GAME 0x1DE428
YMOVE(func_001DE428, func_001DD258)
// FUNCTION: GAME 0x1DF358
YMOVE(func_001DF358, func_001DEE60)

#define XSW(name, T, fn, off, V, x, y, z) \
extern "C" void name(char *s, T k) \
{ \
    switch (k) { \
    default: \
    case 0: \
        SetOffsetPosX__12CustomIDWorki(s + off, V); \
        fn(s, x, 0); \
        fn(s, y, 0); \
        fn(s, z, 0); \
        break; \
    case 1: \
        SetOffsetPosX__12CustomIDWorki(s + off, 0); \
        fn(s, x, 0); \
        fn(s, y, 1); \
        fn(s, z, 0); \
        break; \
    case 2: \
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + off, V, 0, 10); \
        fn(s, x, 0); \
        fn(s, y, 1); \
        fn(s, z, 0); \
        break; \
    case 3: \
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + off, 0, V, 10); \
        break; \
    } \
}
// FUNCTION: GAME 0x1DE088
XSW(func_001DE088, unsigned char, func_001DD258, 0x1D4, 0xFA, 3, 4, 5)
// FUNCTION: GAME 0x1DE170
XSW(func_001DE170, unsigned char, func_001DD258, 0x348, 0xFA, 6, 7, 8)
// FUNCTION: GAME 0x1DE258
XSW(func_001DE258, unsigned char, func_001DD258, 0x4BC, 0xFA, 9, 0xA, 0xB)
// FUNCTION: GAME 0x1DE340
XSW(func_001DE340, unsigned char, func_001DD258, 0x630, 0xFA, 0xC, 0xD, 0xE)
// FUNCTION: GAME 0x1D5C38
XSW(func_001D5C38, unsigned short, func_001D51B8, 0x5B4, -0x140, 0xB, 0xC, 0x23)
// FUNCTION: GAME 0x1D5D20
XSW(func_001D5D20, unsigned short, func_001D51B8, 0x4BC, -0x140, 9, 0xA, 0x24)
