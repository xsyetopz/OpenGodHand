// Units in 0x13D540, 0x148BD8, 0x16FA80 (slice F135).

#ifdef NONMATCHING
extern "C" int getIDWork__7cIDBasei(void *, int);
extern "C" void Main__12CustomIDWork(void *);
extern "C" void move__7cIDBase(void *);
extern "C" void func_0013D698(void *, unsigned int);
extern "C" void func_0013D7B0(void *, unsigned int);
extern "C" void func_0013DA98(void *, unsigned int);
extern "C" void func_0013DB50(void *, void *, unsigned int);
extern char *CoreSave;

// DRAFT: GAME 0x13D540
// 50 words differ: switch-case target placement, case-2 a1 reload, flag-block lui a2/a3 order, slots/p reloads.
extern "C" void func_0013D540(char *self)
{
    unsigned int i = 0;
    int *slots = (int *)(self + 0x94);
    do {
        *(int *)((int)slots + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i = (i + 1) & 0xFFFF;
    } while (i < 0xB);
    switch (*(unsigned short *)(self + 0x92)) {
    case 0:
        func_0013D698(self, i);
        break;
    case 1:
        func_0013D7B0(self, i);
        break;
    case 2:
        func_0013DA98(self, i);
        break;
    }
    if (*(unsigned int *)(CoreSave + 0x14) & 0x04000000) {
        unsigned int flag = 0x08000000;
        char *a = *(char **)(self + 0x98);
        *(unsigned int *)(a + 0x2C) |= flag;
        char *b = *(char **)(self + 0xA4);
        *(unsigned int *)(b + 0x2C) |= flag;
        char *p = *(char **)(self + 0x94);
        *(unsigned int *)(p + 0x2C) |= flag;
        func_0013DB50(self, p, flag);
    }
    char *w = self + 0x120;
    int n = 4;
    do {
        n -= 1;
        Main__12CustomIDWork(w);
        w += 0x7C;
    } while (n >= 0);
    move__7cIDBase(self + 0xD0);
    move__7cIDBase(self);
}
#endif

#ifdef NONMATCHING
extern char g_DmgManage[];
extern char EspSys[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(char *, char *, int, int);
extern "C" void effDataRegist__6espSys12eEffDataTypePv(void *, int, void *);

struct Vec4 {
    float x, y, z, w;
};

// DRAFT: GAME 0x16FA80
// 55 words differ: compiler hoists d.w store above the zero stores; p uses v0 where target uses v1; frame and constant-load order differ.
extern "C" int func_0016FA80(char *self)
{
    func_001B6FB8(self);
    volatile Vec4 a;
    Vec4 b, c, d;
    Vec4 *pb = &b;
    Vec4 *pc = &c;
    a.x = 2.6f;
    a.y = 1.8f;
    a.z = 1.2f;
    a.w = 1.0f;
    b.x = 2.6f;
    b.y = 1.8f;
    b.z = 1.2f;
    pb->w = 1.0f;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = t;
    if (t) {
        d.x = 0;
        d.y = 0;
        d.z = 0;
        d.w = 1.0f;
        func_001FD9D8(t, self + 0x80, &c, &d, &b);
    }
    *(int *)(self + 0x5E4) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(int *)(self + 0x5F0) = 0x25A;
    *(int *)(self + 0x5E8) = 0x25A;
    *(char **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 9;
    *(short *)(self + 0x5F4) = -1;
    *(int *)(self + 0x5EC) = 1;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x54A) = 1;
    func_001C28A0(self, (char *)9, -1, 0x25A);
    char *p = *(char **)(self + 0x304);
    effDataRegist__6espSys12eEffDataTypePv(EspSys, 0x25A, p + *(int *)(p + 0xC));
    *(int *)(self + 0x5A0) |= 0x10;
    return 1;
}
#endif

#ifdef NONMATCHING
extern int D_007476B0;
extern char cVram_work[];
extern "C" unsigned long long func_00151368(void *, int);
extern "C" int func_00151398(void *, int, int);

// DRAFT: GAME 0x148BD8
// 85 words differ: target keeps 64-bit masks in s-registers (fp, s7, s5); compiled frame is 0xF0 against target 0xB0.
extern "C" void func_00148BD8(char *self, int a1, int a2, unsigned int a3)
{
    int i = 0;
    char *hdr = *(char **)(self + 0x388);
    unsigned short n = *(unsigned short *)(hdr + 0xA);
    int t6 = func_00151398(cVram_work, a2, a1);
    if (n != 0) {
        union { unsigned long long v; unsigned int w[2]; } s5u;
        s5u.w[0] = 0;
        s5u.w[1] = (a3 & 3) << 3;
        unsigned long long s5 = s5u.v;
        int *p = (int *)(self + 0x300 + ((D_007476B0 & 1) << 6));
        unsigned long long fp = 0xFFF8001FFFFFFFFFULL;
        unsigned long long s7 = 0xFFFFFFE7FFFFFFFFULL;
        do {
            int off = *(int *)(hdr + (i << 2) + 0x20);
            char *e = hdr + off;
            if ((unsigned char)e[0x16] != 0xFF) {
                char *s0 = (char *)*p;
                unsigned long long v = func_00151368(cVram_work, t6);
                *(unsigned long long *)(s0 + 0x20) = v;
                union { unsigned long long v; unsigned int w[2]; } vu;
                vu.v = v;
                int t = (int)((vu.w[1] >> 5) & 0x3FFF) + *(signed char *)(self + 0x387);
                union { unsigned long long v; unsigned int w[2]; } wu;
                wu.w[0] = 0;
                wu.w[1] = ((unsigned int)t & 0x3FFF) << 5;
                unsigned long long w = wu.v;
                union { unsigned long long v; unsigned int w[2]; } ru;
                ru.w[0] = vu.w[0];
                ru.w[1] = (((vu.w[1] & 0xFFF8001Fu) | wu.w[1]) & 0xFFFFFFE7u) | s5u.w[1];
                *(unsigned long long *)(s0 + 0x20) = ru.v;
            }
            i += 1;
            p += 1;
        } while (i < (int)n);
    }
}
#endif
