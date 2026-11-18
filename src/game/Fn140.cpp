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

// FUNCTION: GAME 0x15FEE0
extern "C" void func_0015FEE0(char *self)
{
    int *a = (int *)(self + 0xEE8);
    int m = -1;
    for (int i = 8; i >= 0; i--)
        a[i] = m;
    self[0xF15] = 0;
}

extern "C" void func_001468B0(void *self);
extern "C" void func_001614D0(char *p);
extern "C" void restartAnim__7cIDBase(void *self);

// FUNCTION: GAME 0x146878
extern "C" void func_00146878(char *self)
{
    func_001468B0(self);
    *(short *)(self + 0x100) = 0;
    restartAnim__7cIDBase(self);
    self[0x1C] = 1;
}

// FUNCTION: GAME 0x164EF8
extern "C" void func_00164EF8(char *self)
{
    func_001614D0(self);
    *(int *)(self + 0x298) = 0;
    self[0x5A] = 0;
    self[0x5B] = 0;
    self[0x5C] = 0;
    self[0x5D] = 0;
}

extern "C" void *memcpy(void *, const void *, unsigned);
extern "C" void trans__7cIDBase(void *self);
extern "C" int func_00150538(void *p);
extern int D_00747A34;

// FUNCTION: GAME 0x145160
extern "C" void func_00145160(char *self, const void *src)
{
    memcpy(self + 0x3B4, src, *(short *)(self + 0x3B2) * 2);
    *(int *)(self + 0x90) |= 0x40000000;
}

// FUNCTION: GAME 0x147460
extern "C" void func_00147460(char *self)
{
    if (*(int *)(self + 0xB0)) {
        signed char c = self[0xB8];
        if (c < 5) {
            if (c > 0)
                trans__7cIDBase(self);
        }
    }
}

// FUNCTION: GAME 0x1500C0
extern "C" int func_001500C0()
{
    if (D_00747A34 & 0x20000)
        return 0;
    return func_00150538(D_00466470);
}

#define VEC4_OP(ADDR, OP)                                    \
    extern "C" void func_00##ADDR(float *d, float *a, float *b) \
    {                                                        \
        d[0] = a[0] OP b[0];                                 \
        d[1] = a[1] OP b[1];                                 \
        d[2] = a[2] OP b[2];                                 \
        d[3] = 1.0f;                                         \
    }

// FUNCTION: GAME 0x150738
VEC4_OP(150738, +)
// FUNCTION: GAME 0x150778
VEC4_OP(150778, -)
// FUNCTION: GAME 0x1507B8
VEC4_OP(1507B8, *)

class cMatrix {
public:
    float m[16] __attribute__((aligned(16)));
};
class Quaternion;
void MtxInitRotQuaternion(cMatrix &, const Quaternion &);
void MtxMultiply(cMatrix &, const cMatrix &, const cMatrix &);

// FUNCTION: GAME 0x147BB0
extern "C" void func_00147BB0(cMatrix &dst, const cMatrix &src, const Quaternion &q)
{
    cMatrix m;
    MtxInitRotQuaternion(m, q);
    MtxMultiply(dst, src, m);
}

extern char D_00506E10[];
