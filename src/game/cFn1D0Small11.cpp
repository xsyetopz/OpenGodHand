extern "C" void BgmEventStart__4cSnd9eBgmReqNoii(void *, int, int, int);
extern "C" void SetBgmState__4cSnd9eBgmState(void *, int);
extern "C" void func_001DD258(char *, int, int);
extern "C" void func_001DF528(char *, int, int);
extern "C" void func_001DEE40(char *, int);
struct SndQ { int x; };
extern SndQ Snd;
extern long D_00747640;
struct T10 { int a[5][2]; };
extern T10 D_0042B600;

static inline unsigned char tick(char *s)
{
    int *c = (int *)(s + 0x3028);
    if (*c == 0)
        return 1;
    (*c)--;
    return 0;
}

// FUNCTION: GAME 0x1DA158
extern "C" void func_001DA158(char *s)
{
    switch (*(unsigned char *)(s + 0x3025)) {
    default:
        break;
    case 0:
        *(int *)(s + 0x3028) = 60;
        (*(unsigned char *)(s + 0x3025))++;
        break;
    case 1:
        if (tick(s)) {
            func_001DF528(s + 0x25B0, 1, 4);
            *(int *)(s + 0x3028) = 120;
            (*(unsigned char *)(s + 0x3025))++;
        }
        break;
    case 2:
        if ((D_00747640 & 0x30000000L) || tick(s)) {
            func_001DF528(s + 0x25B0, 1, 3);
            *(int *)(s + 0x3028) = 30;
            (*(unsigned char *)(s + 0x3025))++;
        }
        break;
    case 3:
        if (tick(s)) {
            SetBgmState__4cSnd9eBgmState(&Snd, 0);
            *(unsigned char *)(s + 0x3025) = 0;
            *(unsigned char *)(s + 0x3024) = 0xB;
        }
        break;
    }
}

// FUNCTION: GAME 0x1DB440
extern "C" void func_001DB440(char *s)
{
    switch (*(unsigned char *)(s + 0x3025)) {
    default:
        break;
    case 0:
        *(int *)(s + 0x3028) = 30;
        (*(unsigned char *)(s + 0x3025))++;
        break;
    case 1: {
        if (tick(s)) {
            BgmEventStart__4cSnd9eBgmReqNoii(&Snd, 0x28, 0, 0);
            func_001DF528(s + 0x25B0, 1, 4);
            *(int *)(s + 0x3028) = 30;
            (*(unsigned char *)(s + 0x3025))++;
        }
        break;
    }
    case 2: {
        if (tick(s)) {
            *(int *)(s + 0x3034) = 0;
            func_001DEE40(s + 0x25B0, 0);
            func_001DF528(s + 0x25B0, 1, 3);
            *(unsigned char *)(s + 0x3025) = 0;
            *(unsigned char *)(s + 0x3024) = 0x14;
        }
        break;
    }
    }
}

// FUNCTION: GAME 0x1DDDB0
extern "C" void func_001DDDB0(char *s, unsigned char k, unsigned char m)
{
    if (k < 5) {
        T10 t = D_0042B600;
        switch (m) {
        case 0:
            func_001DD258(s, t.a[k][0], 0);
            func_001DD258(s, t.a[k][1], 0);
            break;
        case 1:
            func_001DD258(s, t.a[k][0], 0);
            func_001DD258(s, t.a[k][1], 1);
            break;
        case 2:
            func_001DD258(s, t.a[k][0], 1);
            func_001DD258(s, t.a[k][1], 0);
            break;
        }
    }
}
