// Fn00292C28: VU0/MMI units from slice F162 (0x292C28, 0x2951B0, 0x2A8608, 0x2BA020).
extern "C" int func_00292AF0(char *a0, char *sp);
extern "C" char *Getplayer__Fv(void);
extern "C" int EntryEm__9cEmManageP11SET_EM_DATAiP7cEmBase(char *self, char *data, int a2, char *a3);
float capVu0Atan2__Fff(float, float);
extern char g_EmManage[];

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

// DRAFT: GAME 0x2A8608
#ifdef NONMATCHING
extern "C" void *SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, void *, int, unsigned);
// a5 == 0: self is cObj and the last arg. a5 != 0: a5 is cObj and self is the last arg.
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
#endif
