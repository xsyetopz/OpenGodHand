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

// DRAFT: GAME 0x161B30, 0x162720 (same body) and 0x16EDE0 (0 -> -1, 1 -> 10, else 10)
// diff: original stores and returns the constant in v0 on two duplicated `jr; sw v0` tails; compiled
// keeps -1 in v1 for the store (11 differing words, 56 vs 48 bytes). Tried r-variable, assignment-as-value.
#ifdef NONMATCHING
extern "C" int func_00161B30(char *self)
{
    unsigned char t = self[0x64];
    if (t == 0) {
        *(int *)(self + 0x60) = 10;
        return 10;
    }
    if (t == 1) {
        *(int *)(self + 0x60) = -1;
        return -1;
    }
    return -1;
}
#endif

// FUNCTION: GAME 0x15FEE0
extern "C" void func_0015FEE0(char *self)
{
    int *a = (int *)(self + 0xEE8);
    int m = -1;
    for (int i = 8; i >= 0; i--)
        a[i] = m;
    self[0xF15] = 0;
}

// DRAFT: GAME 0x1415E8
// diff: original loop is `beqz; (v1--) sb sb; bgez; (a0+=0xC)` (52 bytes); compiled uses bgezl with a lw copy (60 bytes). for/do-while/struct forms tried.
#ifdef NONMATCHING
extern "C" void func_001415E8(char *self, char v)
{
    char **p = (char **)(self + 0x22F4);
    for (int i = 16; i >= 0; i--) {
        char *e = *p;
        if (e) {
            e[0x75] = 1;
            e[0x76] = v;
        }
        p = (char **)((char *)p + 0xC);
    }
}
#endif

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

// FUNCTION: GAME 0x15B0F0
extern "C" char *func_0015B0F0(int n)
{
    char *cur = D_00566E10;
    char *nw = cur + n;
    if (D_00506E10 + (D_007476B0 & 1) * 0x60000 < nw)
        return 0;
    D_00566E10 = nw;
    return cur;
}

// FUNCTION: GAME 0x146E20
extern "C" void func_00146E20(char *self)
{
    signed char t = self[0x79];
    if (t != 0 && t != 6) {
        if (*(unsigned short *)(self + 0xF8) == 0)
            trans__7cIDBase(self);
        else
            trans__7cIDBase(self + 0xA0);
    }
}

extern void *func_SetEffect(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");

// FUNCTION: GAME 0x16FE68
extern "C" void func_0016FE68(void *self)
{
    func_SetEffect(1, 3, self, 0, -1, 0xFFFFFFFF);
}

extern "C" {
void func_0013E400(void *p);
void func_0013C930(void *p);
void func_0013F510(void *p);
void func_0013E908(void *p);
void func_00147188(void *p);
void initData__10cCockPlBar(void *p);
void func_00144C90(void *p);
}

// FUNCTION: GAME 0x141628
extern "C" void func_00141628(char *self)
{
    func_0013E400(self + 0x1910);
    func_0013C930(self + 0x1DC0);
    func_0013F510(self + 0x1E90);
    func_0013E908(self + 0x2220);
    func_00147188(self + 0x1A20);
    initData__10cCockPlBar(self + 0x460);
}

// FUNCTION: GAME 0x145410
extern "C" void func_00145410(char *self)
{
    if (*(int *)(self + 0x90) & 0x40000000) {
        func_00144C90(self);
        *(int *)(self + 0x90) &= 0xEFFFFFFF;
    }
}

// DRAFT: GAME 0x148200
// diff: 1.0f stores at 0x14/0x38 get hoisted by the scheduler; original keeps source order (9-14 words differ per permutation).
#ifdef NONMATCHING
extern "C" void func_00148200(float *self, float a, float b)
{
    self[8] = a;
    self[9] = b;
    self[10] = 1.0f;
    self[15] = 0;
    self[0] = 1.0f;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    self[4] = 0;
    self[6] = 0;
    self[7] = 0;
    self[11] = 0;
    self[12] = 0;
    self[13] = 0;
    self[5] = 1.0f;
    self[14] = 0;
}
#endif

extern "C" {
char *getMeshPtr__6cModeli(void *self, int i);
void func_002A9680(void *heap, void *p);
void func_0030F5A0(void *p);
}
// DRAFT: GAME 0x14D7D0
// diff: original is bnez with 0x16 in the delay slot then 0x18 (sltiu/xori); compiled gives beql or movz forms (if/else, ?:, int ok tried).
#ifdef NONMATCHING
extern "C" void func_0014D7D0(char *self)
{
    char *mesh = getMeshPtr__6cModeli(self, 0);
    char *x = *(char **)(mesh + 0x388);
    char *volatile keep = x;
    (void)keep;
    self[0x2BE] = (*(unsigned short *)(x + 8) >= 2) ? 0x16 : 0x18;
}
#endif

// FUNCTION: GAME 0x1483C8
extern "C" void func_001483C8(char *self, int flags)
{
    char *p = *(char **)(self + 0x408);
    if (p)
        func_002A9680(*(void **)(p - 0x20), p);
    if (flags & 1)
        func_0030F5A0(self);
}

extern "C" void func_002AAC28(void *p);
// FUNCTION: GAME 0x1678B8
extern "C" void func_001678B8(char *self)
{
    int s = self[0x5A];
    if (s >= 0) {
        if (s >= 2) {
            if (s < 4)
                func_002AAC28(self + 0xC0);
        }
    }
    func_002AAC28(self);
}

extern "C" void func_0013C618(void *p);
extern unsigned short D_00747A50;
// FUNCTION: GAME 0x146F18
extern "C" void func_00146F18(float *self)
{
    func_0013C618(self);
    if (D_00747A50 == 0x20) {
        self[0x18] = -130.0f;
        self[0x19] = 5.0f;
    } else {
        self[0x18] = 0;
        self[0x19] = 0;
    }
}

struct D747BA0 { char _pad[0x14]; int key; char _pad2[0xB0 - 0x18]; };
extern D747BA0 D_00747BA0[];
// FUNCTION: GAME 0x150D78
extern "C" int func_00150D78(int unused, int key)
{
    int n = 0x100;
    int i = 0;
    if (!key)
        return 0;
    int *b = (int *)D_00747BA0;
    int *p = b + 5;
    do {
        if (*p == key)
            return (short)i;
        p += 0x2C;
        n--;
        i++;
    } while (n);
    return -1;
}

// FUNCTION: GAME 0x151630
extern "C" int func_00151630(char *s)
{
    if (s[0] == 0x54) {
        if (s[3] == 0x33)
            return s[5] == 6;
        if (s[3] == 0x32)
            return 0;
        if (s[1] == 0x4D)
            return 3;
    }
    return 2;
}
