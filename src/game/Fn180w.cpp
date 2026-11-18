// Small cOm* object units in 0x180000-0x1A8000.
extern const char D_00427230[];
extern "C" void *func_001B6E90(void *);
#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
static inline int IsSet(const int &v) { return v != 0; }
static inline char *Slot0(char *o)
{
    if (IsSet(*(unsigned char *)(o + 0x2B4)))
        return **(char ***)(o + 0x278);
    return 0;
}

extern const char g_EmManage[];
extern "C" void func_0030A3F8(void *, void *);
extern "C" void func_001A6FB0(void *);
extern "C" char *Getplayer__Fv(void);
extern "C" void func_001A70D8(void *, void *, float);
extern "C" char *func_00293130(const char *);
struct Nd {
    int _0;
    Nd *next;
    char *obj;
};
struct V16 {
    float x, y, z, w;
} __attribute__((aligned(16)));
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int, int, void *, void *, float, int);

// FUNCTION: GAME 0x1A4218
extern "C" void func_001A4218(char *self)
{
    V16 v;
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&v) : "memory");
    char *vt = *(char **)(self + 0x214);
    V16 *p = ((V16 * (*)(char *))*(void **)(vt + 0x84))(self + *(short *)(vt + 0x80));
    if (&v != p) {
        v.x = p->x;
        v.y = p->y;
        v.z = p->z;
    }
    SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(1, *(int *)(self + 0x5EC), 0, &v, 1.0f, -1);
}

// FUNCTION: GAME 0x19B4D0
extern "C" void func_0019B4D0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0: {
        V16 v;
        __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&v) : "memory");
        char *vt = *(char **)(self + 0x214);
        V16 *p = ((V16 * (*)(char *))*(void **)(vt + 0x84))(self + *(short *)(vt + 0x80));
        if (&v != p) {
            v.x = p->x;
            v.y = p->y;
            v.z = p->z;
        }
        *(unsigned short *)(self + 0xA90) = 15;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
    case 1:
        *(unsigned short *)(self + 0xA90) -= 1;
        if ((short)*(unsigned short *)(self + 0xA90) <= 0) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x1A42E8
extern "C" char *func_001A42E8(char *s)
{
    func_001B6E90(s);
    char *b = s + 0x600;
    *(const void **)(s + 0x214) = D_00427230;
    ZQ(s, 0x650); ZQ(s, 0x660); ZQ(s, 0x670); ZQ(s, 0x680); ZQ(s, 0x690);
    ZQ(s, 0x6A0); ZQ(s, 0x6B0); ZQ(s, 0x6C0); ZQ(s, 0x6D0); ZQ(s, 0x6E0);
    ZQ(s, 0x6F0); ZQ(s, 0x700); ZQ(s, 0x710); ZQ(s, 0x720);
    *(unsigned char *)b = 0;
    *(unsigned char *)(b + 1) = 0;
    *(unsigned char *)(b + 2) = 0;
    *(int *)(b + 4) = 0;
    *(int *)(b + 8) = 0;
    *(int *)(b + 0x30) = 0;
    *(int *)(b + 0x34) = 0;
    *(int *)(b + 0x38) = 0;
    *(int *)(b + 0x3C) = 0;
    *(int *)(b + 0x130) = 0;
    *(int *)(b + 0x134) = 0;
    *(int *)(b + 0x138) = 0;
    *(int *)(b + 0x13C) = 0;
    unsigned i = 0;
    int *p = (int *)(s + 0x60C);
    for (; i < 8; i++)
        *p++ = 0;
    ZQ(s, 0x770); ZQ(s, 0x780);
    *(int *)(s + 0x790) = 0;
    return s;
}

// FUNCTION: GAME 0x1A4FE0
class cOm4f {
public:
    void setOpenCloseRot(float a, float b);
};
void cOm4f::setOpenCloseRot(float a, float b)
{
    char *self = (char *)this;
    *(float *)(self + 0x794) = a;
    *(float *)(self + 0x798) = b;
    float f;
    if (*(unsigned char *)(self + 0x761) == 1) {
        if (!Slot0(self))
            return;
        char *t = Slot0(self);
        f = *(float *)(self + 0x794);
        float *v = (float *)(t + 0x100);
        v[0] = f;
        v[1] = 0;
        v[2] = 0;
    } else {
        if (!Slot0(self))
            return;
        char *t = Slot0(self);
        f = *(float *)(self + 0x798);
        float *v = (float *)(t + 0x100);
        v[0] = f;
        v[1] = 0;
        v[2] = 0;
    }
}

// FUNCTION: GAME 0x1A6F00
extern "C" void func_001A6F00(char *self)
{
    func_0030A3F8(self + 0x600, self + 0x80);
    func_001A6FB0(self);
    V16 v;
    char *pl = Getplayer__Fv();
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(v) : "r"(*(void **)(pl + 0xF0)));
    func_001A70D8(self, &v, 0.5f);
    for (Nd *n = (Nd *)func_00293130(g_EmManage); n; n = n->next) {
        if (n->obj)
            func_001A70D8(self, *(void **)(n->obj + 0xF0), 0.5f);
    }
}
