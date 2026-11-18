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

#define SW2(name, ax, fn, off, V, x, y) \
extern "C" void name(char *s, unsigned char k) \
{ \
    switch (k) { \
    default: \
    case 0: \
        SetOffsetPos##ax##__12CustomIDWorki(s + off, V); \
        fn(s, x, 0); \
        fn(s, y, 0); \
        break; \
    case 1: \
        SetOffsetPos##ax##__12CustomIDWorki(s + off, 0); \
        fn(s, x, 1); \
        fn(s, y, 1); \
        break; \
    case 2: \
        SetMoveOffsetPos##ax##__12CustomIDWorkiiUs(s + off, V, 0, 10); \
        fn(s, x, 1); \
        fn(s, y, 1); \
        break; \
    case 3: \
        SetMoveOffsetPos##ax##__12CustomIDWorkiiUs(s + off, 0, V, 10); \
        fn(s, x, 1); \
        fn(s, y, 1); \
        break; \
    } \
}
// FUNCTION: GAME 0x1DE4F8
SW2(func_001DE4F8, Y, func_001DD258, 0x89C, 0x46, 0x11, 0x12)
// FUNCTION: GAME 0x1DF428
SW2(func_001DF428, X, func_001DEE60, 0x728, 0xC8, 0xE, 0xF)

#define SW3(name, T, ax, fn, off, V, x, y) \
extern "C" void name(char *s, T k) \
{ \
    switch (k) { \
    default: \
    case 0: \
        SetOffsetPos##ax##__12CustomIDWorki(s + off, V); \
        fn(s, x, 0); \
        fn(s, y, 0); \
        break; \
    case 1: \
        SetOffsetPos##ax##__12CustomIDWorki(s + off, 0); \
        fn(s, x, 0); \
        fn(s, y, 1); \
        break; \
    case 2: \
        SetMoveOffsetPos##ax##__12CustomIDWorkiiUs(s + off, V, 0, 10); \
        fn(s, x, 0); \
        fn(s, y, 1); \
        break; \
    case 3: \
        SetMoveOffsetPos##ax##__12CustomIDWorkiiUs(s + off, 0, V, 10); \
        break; \
    } \
}
// FUNCTION: GAME 0x1D5F50
SW3(func_001D5F50, unsigned short, Y, func_001D51B8, 0x105C, 0x46, 0x21, 0x22)

// FUNCTION: GAME 0x1D5E08
extern "C" void func_001D5E08(char *s, unsigned short k)
{
    switch (k) {
    default:
    case 0:
        SetOffsetPosX__12CustomIDWorki(s + 0x6AC, -0x140);
        func_001D51B8(s, 0xD, 0);
        func_001D51B8(s, 0xE, 0);
        func_001D51B8(s, 0xF, 0);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(s + 0x6AC, 0);
        func_001D51B8(s, 0xD, 0);
        func_001D51B8(s, 0xE, 1);
        func_001D51B8(s, 0xF, 0);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x6AC, -0x140, 0, 10);
        func_001D51B8(s, 0xD, 0);
        func_001D51B8(s, 0xE, 0);
        func_001D51B8(s, 0xF, 1);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s + 0x6AC, 0, -0x140, 10);
        func_001D51B8(s, 0xD, 0);
        func_001D51B8(s, 0xE, 1);
        func_001D51B8(s, 0xF, 1);
        break;
    }
}

extern "C" void SetDisp__12CustomIDWorkb(void *, int);
#define LOOP(N, v) { \
    char *p = s + 0x60; \
    int i = 0; \
    for (; i < N; i++) { \
        if (i) \
            SetDisp__12CustomIDWorkb(p, v); \
        p += 0x7C; \
    } \
}
#define DISP(name, N) \
extern "C" void name(char *s, int idx, int on) \
{ \
    if (on) { \
        if (idx == N) \
            LOOP(N, 1) \
        else if (idx) \
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 1); \
    } else { \
        if (idx == N) \
            LOOP(N, 0) \
        else if (idx) \
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 0); \
    } \
}
extern "C" void SetScaleAnimSin__12CustomIDWorkffUs(void *, float, float, unsigned short);
extern "C" void ResetScaleAnim__12CustomIDWork(void *);
struct T5 { int a[5]; };
extern T5 D_0042B5D0;

// FUNCTION: GAME 0x1D51B8
DISP(func_001D51B8, 0x2D)
// FUNCTION: GAME 0x1DD258
DISP(func_001DD258, 0x4D)

// FUNCTION: GAME 0x1DEE60
DISP(func_001DEE60, 0x11)

// FUNCTION: GAME 0x1DEA50
extern "C" void func_001DEA50(char *s, unsigned char k, int on)
{
    if (k < 5) {
        T5 t = D_0042B5D0;
        if (on)
            SetScaleAnimSin__12CustomIDWorkffUs(s + (t.a[k] * 0x7C + 0x60), 0.6f, 1.0f, 12);
        else
            ResetScaleAnim__12CustomIDWork(s + (t.a[k] * 0x7C + 0x60));
    }
}
