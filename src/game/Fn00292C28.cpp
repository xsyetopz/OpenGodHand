// Fn00292C28: VU0/MMI units from slice F162 (0x292C28, 0x2951B0, 0x2A8608, 0x2BA020).
extern "C" int func_00292AF0(char *a0, char *sp);
extern "C" char *Getplayer__Fv(void);
extern "C" int EntryEm__9cEmManageP11SET_EM_DATAiP7cEmBase(char *self, char *data, int a2, char *a3);
float capVu0Atan2__Fff(float, float);
extern char g_EmManage[];
extern "C" char *func_002BA300(void *, int);
extern "C" void func_002B8A70(char *, int);
extern "C" void func_002BB160(char *, int, int, char *);
extern int D_0044BB20;

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

// FUNCTION: GAME 0x292C28
extern "C" int func_00292C28(char *a0, char *a1)
{
    char sp[0x70] __attribute__((aligned(16)));
    char *s1 = sp + 0x10;
    ZQ(sp, 0x10);
    *(unsigned char *)(sp + 0x31) = 0xFF;
    if (func_00292AF0(a0, sp) == 0xFFFF)
        return 0;
    ZQ(sp, 0x40);
    char *pl = Getplayer__Fv();
    float *pos = *(float **)(pl + 0xF0);
    ZQ(sp, 0x60);
    __asm__ volatile(
        "lqc2 $vf4,0(%0)\n"
        "lqc2 $vf5,0(%1)\n"
        "vsub.xyz $vf4,$vf4,$vf5\n"
        "sqc2 $vf4,0x60(%2)\n"
        : : "r"(pos), "r"(a1), "r"(sp) : "memory");
    char *p60 = sp + 0x60;
    __asm__ volatile(
        "lqc2 $vf4,0(%0)\n"
        "sqc2 $vf4,0x50(%1)\n"
        : : "r"(p60), "r"(sp) : "memory");
    float *f = (float *)sp;
    float x = f[0x50 / 4];
    float z = f[0x58 / 4];
    float y = f[0x54 / 4];
    f[0x40 / 4] = x;
    f[0x44 / 4] = y;
    f[0x48 / 4] = z;
    float a = capVu0Atan2__Fff(x, z);
    if (s1 != a1) {
        float t0 = ((float *)a1)[0];
        float t1 = ((float *)a1)[1];
        float t2 = ((float *)a1)[2];
        f[0x10 / 4] = t0;
        f[0x14 / 4] = t1;
        f[0x18 / 4] = t2;
    }
    *(float *)(sp + 0x20) = a;
    *(int *)(sp + 0x24) = 0x44000000;
    *(int *)(sp + 0x2C) = 0;
    *(unsigned char *)(sp + 0x30) = 8;
    return EntryEm__9cEmManageP11SET_EM_DATAiP7cEmBase(g_EmManage, sp, 0, 0);
}

// DRAFT: GAME 0x2951B0
#ifdef NONMATCHING
// 43 words: x,y,z = s16 * 0.05f into sp+0x50; w = 1.0f; lqc2/sqc2 copy to sp+0x40. Diff starts at the a1 copy register and ra store; hoisted k, fx/fy/fz locals and id store order all stayed at 43.
extern "C" int func_002951B0(char *a0, char *a1)
{
    char sp[0x60] __attribute__((aligned(16)));
    float *f = (float *)sp;
    char *p50 = sp + 0x50;
    float *q = (float *)p50;
    ZQ(sp, 0x10);
    int id = *(unsigned char *)(a1 + 0x12);
    *(unsigned char *)(sp + 0x31) = 0xFF;
    id += 0x200;
    *(int *)(sp + 0x00) = id;
    short sx = *(short *)(a1 + 0x0);
    float k = 0.05f;
    float fx = (float)sx * k;
    short sy = *(short *)(a1 + 0x2);
    float fy = (float)sy * k;
    short sz = *(short *)(a1 + 0x4);
    float fz = (float)sz * k;
    q[0] = fx;
    q[1] = fy;
    q[2] = fz;
    q[3] = 1.0f;
    __asm__ volatile(
        "lqc2 $vf4,0(%0)\n"
        "sqc2 $vf4,0x40(%1)\n"
        : : "r"(p50), "r"(sp) : "memory");
    float ang = (float)*(short *)(a1 + 0x6) * 0.017453292f;
    float t0 = f[0x40 / 4];
    float t1 = f[0x44 / 4];
    float t2 = f[0x48 / 4];
    f[0x10 / 4] = t0;
    f[0x14 / 4] = t1;
    f[0x18 / 4] = t2;
    f[0x20 / 4] = ang;
    *(int *)(sp + 0x28) = *(unsigned char *)(a1 + 0x11) + 0x200;
    *(int *)(sp + 0x24) = *(int *)(a1 + 0x8);
    *(int *)(sp + 0x2C) = *(int *)(a1 + 0xC);
    *(unsigned char *)(sp + 0x30) = *(unsigned char *)(a1 + 0x10);
    *(unsigned char *)(sp + 0x31) = *(unsigned char *)(a1 + 0x13);
    return EntryEm__9cEmManageP11SET_EM_DATAiP7cEmBase(g_EmManage, sp, 0, 0);
}
#endif

extern "C" void *SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, void *, int, unsigned);
// a5 == 0: self is cObj and the last arg. a5 != 0: a5 is cObj and self is the last arg.
// FUNCTION: GAME 0x2A8608
extern "C" int func_002A8608(char *self, int a1, int a2, int a3, int a4, int a5)
{
    char sp[0x80] __attribute__((aligned(16)));
    float *f = (float *)sp;
    f[0] = 1.0f;
    f[1] = 1.0f;
    f[2] = 1.0f;
    f[3] = 1.0f;
    ZQ(sp, 0x10);
    ZQ(sp, 0x20);
    float *q = (float *)(sp + 0x30);
    f[0x30 / 4] = 1.0f;
    q[1] = 1.0f;
    q[2] = 1.0f;
    q[3] = 1.0f;
    f[0x40 / 4] = 1.0f;
    *(signed char *)(sp + 0x4C) = -1;
    *(unsigned char *)(sp + 0x4F) = 0xFF;
    *(int *)(sp + 0x44) = 0;
    *(int *)(sp + 0x48) = 0;
    *(unsigned char *)(sp + 0x4D) = 0;
    *(unsigned char *)(sp + 0x4E) = 0;
    *(int *)(sp + 0x50) = 0;
    ZQ(sp, 0x60);
    *(int *)(self + 0x574) = a4;
    *(short *)(sp + 0x70) = 0;
    *(short *)(sp + 0x72) = 0;
    *(unsigned char *)(sp + 0x74) = 0;
    *(int *)(sp + 0x78) = 0;
    *(short *)(self + 0x570) = (short)a3;
    int r;
    if (a5 == 0) {
        if (self != 0 && (*(unsigned short *)(self + 0x434) & 2) != 0) {
            *(int *)(sp + 0x48) |= 0x80;
            f[0x40 / 4] = *(float *)(self + 0x114);
        }
        r = (int)SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(a1, a2, self, sp, a3, (unsigned)self);
    } else {
        if (self != 0)
            f[0x40 / 4] = *(float *)(self + 0x114);
        r = (int)SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(a1, a2, (char *)a5, sp, a3, (unsigned)self);
    }
    return r;
}

// DRAFT: GAME 0x2BA020
#ifdef NONMATCHING
// 3 words: D_0044BB20 address temp is $v0 vs original $v1 (lui/addiu/sw at 0xA8-0xB0). Tried: vt local merge (11), typed fn-pointer locals (3, kept), unsigned temp (3), hoisted 4 (8), int* cast store (3, $v0 still).
extern "C" char *func_002BA020(char *self, int a1, int a2, int a3, char *a4, int a5)
{
    char *r = func_002BA300(self, 4);
    if (r == 0)
        return 0;
    if (((*(unsigned int *)r & 0x201) ^ 1) != 0) {
        int vt = *(int *)(self + 0x18);
        ((void (*)(char *, char *))(*(int *)(vt + 0x34)))(self + *(short *)(vt + 0x30), r);
        return 0;
    }
    func_002B8A70(r, a1);
    char *s0 = r + 0xE0;
    func_002BB160(s0, a2, a3, a4);
    *(int *)(s0 + 0x100) = (int)&D_0044BB20;
    ZQ(r, 0x1F0);
    ZQ(r, 0x200);
    *(int *)(r + 0xE0) = 4;
    int vt2 = *(int *)(s0 + 0x100);
    void (*fn1)(char *, int) = (void (*)(char *, int))(*(int *)(vt2 + 0x3C));
    fn1(s0 + *(short *)(vt2 + 0x38), a5);
    int vt3 = *(int *)(s0 + 0x100);
    void (*fn2)(char *) = (void (*)(char *))(*(int *)(vt3 + 0x54));
    fn2(s0 + *(short *)(vt3 + 0x50));
    *(char **)(r + 0x34) = s0;
    return r;
}
#endif
