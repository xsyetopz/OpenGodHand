struct V3 {
    float x, y, z;
};
extern const char D_00429EC8[];
extern "C" void func_001B6E90(void *);
extern "C" int moveMotion__FP8cObjBase(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1CA1F8
// diff: 6 differing words (60 vs 60 bytes)
extern "C" void func_001CA1F8(char *self)
{
    unsigned char v = *(unsigned char *)(self + 0x2F6);
    if (v == 0)
        *(unsigned char *)(self + 0x2F6) = 1;
    else if (v != 1)
        return;
    moveMotion__FP8cObjBase(self);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1C2328
// diff: 16 differing words (76 vs 68 bytes)
extern "C" int func_001C2328(char *self)
{
    if (*(unsigned char *)(self + 0x2F4) != 0)
        return 0;
    int v = *(unsigned char *)(self + 0x2F6);
    if (v < 2)
        return 0;
    if (v < 4)
        return 1;
    if (v >= 8)
        return 0;
    if (v < 6)
        return 0;
    return 1;
}
#endif

// FUNCTION: GAME 0x001C24A0
extern "C" int func_001C24A0(char *self)
{
    switch (*(unsigned short *)(self + 0x2FE)) {
    case 0x3BC:
    case 0x3D9:
    case 0x3E3:
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x001CD7A8
extern "C" void func_001CD7A8(char *self)
{
    char *o = *(char **)(self + 0x670);
    if (o) {
        V3 *src = *(V3 **)(o + 0xF0);
        V3 *dst = *(V3 **)(self + 0xF0);
        if (dst != src) {
            dst->x = src->x;
            dst->y = src->y;
            dst->z = src->z;
        }
        dst = *(V3 **)(self + 0xF0);
        dst->y -= 0.6f;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1C3C58
// diff: 22 differing words (92 vs 96 bytes)
extern "C" int func_001C3C58(int *out, int *a)
{
    if (a) {
        out[0] = (int)a;
        if (a[0] == 0x534D4F) {
            if (a[1] != 0) {
                out[1] = a[2] < 2 ? (int)(a + 3) : (int)(a + 4);
                return 1;
            }
        }
        out[0] = 0;
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1DBEB0
// diff: 16 differing words (104 vs 104 bytes)
extern "C" void func_001DBEB0(char *self)
{
    int i = 0x33;
    int *p = (int *)(self + 0x2E68);
    do {
        char *o = *(char **)(p - 1);
        *(unsigned *)(o + 0x250) |= 2;
        *p = 9;
        *(int *)(*(char **)(p - 1) + 0x104) = 0;
        p += 2;
    } while (--i >= 0);
    int *q = (int *)(self + 0x3014);
    i = 4;
    do {
        *q = 0;
        q--;
    } while (--i >= 0);
}
#endif

extern "C" void __7cIDBase(void *);
extern "C" void __12CustomIDWork(void *);

// FUNCTION: GAME 0x001D4D80
extern "C" void *func_001D4D80(char *self)
{
    *(int *)self = 0;
    __7cIDBase(self + 0x10);
    char *w = self + 0x60;
    int i = 44;
    do {
        __12CustomIDWork(w);
        w += 0x7C;
    } while (--i != -1);
    return self;
}

// FUNCTION: GAME 0x001DD068
extern "C" void *func_001DD068(char *self)
{
    *(int *)self = 0;
    __7cIDBase(self + 0x10);
    char *w = self + 0x60;
    int i = 76;
    do {
        __12CustomIDWork(w);
        w += 0x7C;
    } while (--i != -1);
    return self;
}

extern char g_DmgManage[];
extern "C" int ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
extern "C" void dieCommon__7cOmBase(void *);

// FUNCTION: GAME 0x001C8DD8
extern "C" void func_001C8DD8(char *self)
{
    void *g = *(void **)(self + 0x600);
    if (g) {
        if (ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, g)) {
            *(int *)(self + 0x600) = 0;
            *(int *)(self + 0x604) = -1;
        }
    }
    if (*(unsigned char *)(self + 0x640)) {
        dieCommon__7cOmBase(self);
    } else {
        char *vt = *(char **)(self + 0x214);
        ((void (*)(char *))*(void **)(vt + 0xA4))(self + *(short *)(vt + 0xA0));
    }
}

extern const char D_00429C80[];
extern "C" void func_001FE278(void *, void *);
extern "C" void func_001B6F38(void *, void *);
extern "C" void func_001DEE60(void *, int, void *);

// FUNCTION: GAME 0x001DEC70
extern "C" void *func_001DEC70(char *self)
{
    *(int *)self = 0;
    __7cIDBase(self + 0x10);
    char *w = self + 0x60;
    int i = 0x10;
    do {
        __12CustomIDWork(w);
        w += 0x7C;
    } while (--i != -1);
    return self;
}

// FUNCTION: GAME 0x001DF758
extern "C" void func_001DF758(void *a, void *b)
{
    func_001DEE60(a, 6, b);
    func_001DEE60(a, 7, b);
    func_001DEE60(a, 8, b);
    func_001DEE60(a, 9, b);
    func_001DEE60(a, 10, b);
}

// FUNCTION: GAME 0x001C2820
extern "C" void func_001C2820(char *self, void *d)
{
    *(const char **)(self + 0x214) = D_00429C80;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(int *)(self + 0x600) = 0;
    }
    if (*(int *)(self + 0x604)) {
        func_001FE278(g_DmgManage, *(void **)(self + 0x600));
        *(int *)(self + 0x600) = 0;
    }
    func_001B6F38(self, d);
}

struct V16 {
    float x, y, z, w;
} __attribute__((aligned(16)));
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int, int, void *, void *, float, int);

// FUNCTION: GAME 0x001C2B80
extern "C" void func_001C2B80(char *self)
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
    int e = *(int *)(self + 0x5E4);
    if (e)
        SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0, e, 0, &v, 1.0f, -1);
}

// FUNCTION: GAME 0x001C2CE0
extern "C" void func_001C2CE0(char *self)
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
    int e = *(int *)(self + 0x5EC);
    if (e)
        SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0, e, 0, &v, 1.0f, -1);
}

struct T5 {
    int a[5];
};
extern const T5 D_0042B5D0;
extern "C" void func_001DD258(void *, int);
