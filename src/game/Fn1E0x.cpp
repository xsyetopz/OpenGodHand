extern "C" void SetNumber__12CustomIDWorki(void *, int);
extern "C" void displayScrollLayer__FUib(unsigned, int);
extern "C" void SetDisp__12CustomIDWorkb(void *, int);
extern "C" void SetLocalPosY__12CustomIDWorki(void *, int);
extern "C" void *memset(void *, int, unsigned);
extern "C" void __7cIDBase(void *);
extern "C" void __12CustomIDWork(void *);
extern "C" void func_001E8798(char *);
extern "C" void func_001E7960(char *);
struct T5 { int a[5]; };
extern T5 D_0042BD40;
extern T5 D_0042BD58;
#define L(o, v) displayScrollLayer__FUib(*(unsigned *)(s + (o)), v)

// FUNCTION: GAME 0x1E6BE8
extern "C" void func_001E6BE8(char *s)
{
    unsigned v = *(unsigned short *)(s + 0x3E0);
    if (v & 0x8000) {
        v++;
        *(unsigned short *)(s + 0x3E0) = v;
        if ((v & 0x3FFF) >= 8) {
            unsigned short w = (~v & 0x4000) | 0x8000;
            *(unsigned short *)(s + 0x3E0) = w;
            if (w & 0x4000) {
                L(0x3C8, 1);
                L(0x3CC, 1);
            } else {
                L(0x3C8, 0);
                L(0x3CC, 0);
            }
        }
    }
}

// FUNCTION: GAME 0x1E7118
extern "C" char *func_001E7118(char *s)
{
    char *p;
    int i;
    __7cIDBase(s);
    p = s + 0x50;
    i = 9;
    do {
        __12CustomIDWork(p);
        p += 0x7C;
    } while (--i != -1);
    __7cIDBase(s + 0x530);
    p = s + 0x580;
    i = 1;
    do {
        __12CustomIDWork(p);
        p += 0x7C;
    } while (--i != -1);
    return s;
}

// FUNCTION: GAME 0x1E4730
extern "C" char *__5Slot2(char *s)
{
    char *p;
    int i;
    memset(s, 0, 0x54);
    *(int *)(s + 0x54) = 0;
    p = s + 0x58;
    i = 2;
    do {
        func_001E8798(p);
        p += 0xE8;
    } while (--i != -1);
    func_001E7960(s + 0x310);
    func_001E7118(s + 0x400);
    *(unsigned short *)(s + 0x3D0) = 0xFFFF;
    *(unsigned short *)(s + 0xA80) = 0;
    *(int *)(s + 0x3DC) = 0;
    return s;
}

// FUNCTION: GAME 0x1ECF30
extern "C" void func_001ECF30(char *s, unsigned short k)
{
    if (k < 5) {
        T5 t = D_0042BD40;
        SetLocalPosY__12CustomIDWorki(s + 0x60, t.a[k]);
        T5 u = D_0042BD58;
        SetLocalPosY__12CustomIDWorki(s + 0x11D0, u.a[k]);
    }
}

// FUNCTION: GAME 0x1ECE30
#define LOOP(v) { \
    char *p = s + 0x60; \
    int i = 0; \
    for (; i < 0x2D; i++) { \
        if (i != 8) \
            SetDisp__12CustomIDWorkb(p, v); \
        p += 0x7C; \
    } \
}
extern "C" void func_001ECE30(char *s, int idx, int on)
{
    if (on) {
        if (idx == 0x2D)
            LOOP(1)
        else if (idx != 8)
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 1);
    } else {
        if (idx == 0x2D)
            LOOP(0)
        else if (idx != 8)
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 0);
    }
}

// FUNCTION: GAME 0x1E4308
extern T5 D_0042B8D0;
extern "C" void func_001E4308(char *s)
{
    unsigned v = *(unsigned short *)(s + 0x4AC);
    if (v & 0x8000) {
        v++;
        *(unsigned short *)(s + 0x4AC) = v;
        if ((v & 0x3FF) >= 8) {
            T5 t = D_0042B8D0;
            unsigned short w = (~v & 0x4000) | (v & 0x3800) | 0x8000;
            unsigned k;
            *(unsigned short *)(s + 0x4AC) = w;
            k = (w >> 11) & 7;
            if (w & 0x4000) {
                unsigned *p = (unsigned *)(s + 0x400);
                int i = 0;
                for (; i < 5; i++)
                    displayScrollLayer__FUib(*(unsigned *)((char *)p + ((unsigned)t.a[i] << 2)), i == k);
            } else {
                unsigned *p = (unsigned *)(s + 0x400);
                int i = 0;
                for (; i < 5; i++)
                    displayScrollLayer__FUib(*(unsigned *)((char *)p + ((unsigned)t.a[i] << 2)), 0);
            }
        }
    }
}

#undef LOOP
#define LOOPB(v) { \
    char *p = s + 0x50; \
    int i = 9; \
    for (; i >= 0; i--) { \
        SetDisp__12CustomIDWorkb(p, v); \
        p += 0x7C; \
    } \
}

// FUNCTION: GAME 0x1E7470
extern "C" void func_001E7470(char *s, int idx, int on)
{
    if (on) {
        if (idx == 10)
            LOOPB(1)
        else
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x50), 1);
    } else {
        if (idx == 10)
            LOOPB(0)
        else
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x50), 0);
    }
}

#define LOOPE(v) { \
    char *p = s + 0x580; \
    int i = 1; \
    for (; i >= 0; i--) { \
        SetDisp__12CustomIDWorkb(p, v); \
        p += 0x7C; \
    } \
}
// FUNCTION: GAME 0x1E7538
extern "C" void func_001E7538(char *s, int idx, int on)
{
    if (on) {
        if (idx == 2)
            LOOPE(1)
        else
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x580), 1);
    } else {
        if (idx == 2)
            LOOPE(0)
        else
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x580), 0);
    }
}
#undef LOOPE

#undef LOOPB
#define LOOPC(v) { \
    char *p = s + 0x60; \
    int i = 5; \
    for (; i >= 0; i--) { \
        SetDisp__12CustomIDWorkb(p, v); \
        p += 0x7C; \
    } \
}

// FUNCTION: GAME 0x1ED700
extern "C" void func_001ED700(char *s, int idx, int on)
{
    if (on) {
        if (idx == 6)
            LOOPC(1)
        else
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 1);
    } else {
        if (idx == 6)
            LOOPC(0)
        else
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 0);
    }
}

#undef LOOPC
#define LOOPD(N, v) { \
    char *p = s + 0x60; \
    int i = 0; \
    for (; i < N; i++) { \
        if (i) \
            SetDisp__12CustomIDWorkb(p, v); \
        p += 0x7C; \
    } \
}

// FUNCTION: GAME 0x1EE1C0
extern "C" void func_001EE1C0(char *s, int idx, int on)
{
    if (on) {
        if (idx == 0x1D)
            LOOPD(0x1D, 1)
        else if (idx)
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 1);
    } else {
        if (idx == 0x1D)
            LOOPD(0x1D, 0)
        else if (idx)
            SetDisp__12CustomIDWorkb(s + (idx * 0x7C + 0x60), 0);
    }
}

// FUNCTION: GAME 0x1ED3C0
extern "C" void func_001ED3C0(char *s, int n)
{
    int v = *(int *)(s + 0x162C);
    if (!(v < n))
        v = n;
    SetNumber__12CustomIDWorki(s + 0xFE0, v);
    if (v <= 0) {
        func_001ECE30(s, 0x22, 1);
        func_001ECE30(s, 0x23, 0);
    } else if (!(n < *(int *)(s + 0x162C))) {
        func_001ECE30(s, 0x22, 0);
        func_001ECE30(s, 0x23, 1);
    } else {
        func_001ECE30(s, 0x22, 1);
        func_001ECE30(s, 0x23, 1);
    }
}
