// Small units in .text 0x140000-0x16FFFF.

extern int D_007476B0;
extern "C" {
void func_0015B0C0();
void func_00155DC8(int a, int b);
void func_001574F0(int a, int b);
void func_00141678(void *p);
void func_002A9790(void *a);
void func_001508F8(void *p);
void func_001612C8(void *p);
}
extern char D_004A6E10[];
extern char *D_00566E10;
extern char D_00464080[];
extern char D_00466470[];
extern char cVram_work[];
extern char D_00566E50[];

// FUNCTION: GAME 0x158CC8
extern "C" float func_00158CC8(int, char *p) { return *(float *)(p + 8); }

// FUNCTION: GAME 0x15B0A0
extern "C" void func_0015B0A0() { func_0015B0C0(); }

// FUNCTION: GAME 0x1563D0
extern "C" void func_001563D0() { func_00155DC8(1, 0xFFFF); }

// FUNCTION: GAME 0x157540
extern "C" void func_00157540() { func_001574F0(1, 0xFFFF); }

// FUNCTION: GAME 0x15B0C0
extern "C" void func_0015B0C0()
{
    D_00566E10 = D_004A6E10 + (D_007476B0 & 1) * 0x60000;
}

// FUNCTION: GAME 0x15EEE0
extern "C" void func_0015EEE0(long *p)
{
    float f = 1.0f;
    int i = *(int *)&f;
    p[4] = 0;
    p[16] = 0;
    p[12] = 0;
    p[8] = 0;
    p[0] = (long)i << 32;
}

// FUNCTION: GAME 0x1614D0
extern "C" void func_001614D0(char *p)
{
    *(int *)(p + 0x60) = -1;
    p[0x58] = 0;
    p[0x59] = 0;
    *(int *)(p + 0x50) = 0;
    p[0x64] = 0;
    p[0x5A] = 0;
    p[0x5B] = 0;
    p[0x5C] = 0;
    p[0x5D] = 0;
}

// FUNCTION: GAME 0x141AC8
extern "C" void func_00141AC8(int a, int b)
{
    if (b == 0xFFFF && a)
        func_00141678(D_00464080);
}

// FUNCTION: GAME 0x150608
extern "C" void func_00150608(int a, int b)
{
    if (b == 0xFFFF && a)
        func_002A9790(D_00466470);
}

// FUNCTION: GAME 0x1523F8
extern "C" void func_001523F8(int a, int b)
{
    if (b == 0xFFFF && a)
        func_001508F8(cVram_work);
}

// FUNCTION: GAME 0x161480
extern "C" void func_00161480(int a, int b)
{
    if (b == 0xFFFF && a)
        func_001612C8(D_00566E50);
}

// DRAFT: GAME 0x151368
// diff: original adds the 0x3DC88 base to a0 first, then a0 += (flag<<3)+(i<<4); compiled folds into a1 (ld via a1)
#ifdef NONMATCHING
extern "C" long func_00151368(char *p, int i)
{
    return *(long *)(p + 0x3DC88 + (D_007476B0 & 1) * 8 + i * 16);
}
#endif

// FUNCTION: GAME 0x140C58
extern "C" int func_00140C58(char *self)
{
    int *p = (int *)(self + 0x22F4);
    for (int i = 0; i < 0x11; i++) {
        if (*p == 0)
            return i;
        p = (int *)((char *)p + 0xC);
    }
    return -1;
}

// FUNCTION: GAME 0x15FD68
extern "C" int func_0015FD68(char *self)
{
    int *p = (int *)(self + 4);
    for (int i = 0; i < 9; i++) {
        if (*p == 0)
            return i;
        p = (int *)((char *)p + 8);
    }
    return -1;
}

#define MODE60_A(ADDR)                                       \
    extern "C" int func_00##ADDR(char *self)                 \
    {                                                        \
        unsigned char t = self[0x64];                        \
        if (t == 0) {                                        \
            *(int *)(self + 0x60) = 10;                      \
            return 10;                                       \
        }                                                    \
        if (t == 1) {                                        \
            *(int *)(self + 0x60) = -1;                      \
            return -1;                                       \
        }                                                    \
        return -1;                                           \
    }

// FUNCTION: GAME 0x161B30
MODE60_A(161B30)
// FUNCTION: GAME 0x162720
MODE60_A(162720)

// FUNCTION: GAME 0x16EDE0
extern "C" int func_0016EDE0(char *self)
{
    unsigned char t = self[0x64];
    if (t == 0) {
        *(int *)(self + 0x60) = -1;
        return -1;
    }
    if (t == 1) {
        *(int *)(self + 0x60) = 10;
        return 10;
    }
    return 10;
}

// FUNCTION: GAME 0x15FEE0
extern "C" void func_0015FEE0(char *self)
{
    int *q = (int *)(self + 0xF08);
    for (int i = 8; i >= 0; i--)
        *q-- = -1;
    self[0xF15] = 0;
}
