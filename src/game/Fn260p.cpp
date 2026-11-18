// Small helpers from 0x260000-0x280000.

// DRAFT: GAME 0x27DC50 - original compare chain is 1,0,2,3 (about 12 words differ)
#ifdef NONMATCHING
extern "C" void func_0027DC50(char *self, int k)
{
    int b;
    switch (k) {
    case 1:
        b = 2;
        break;
    case 2:
        b = 4;
        break;
    case 3:
        b = 6;
        break;
    case 0:
    default:
        self[0x2F7] = 0;
        self[0x2F5] = 8;
        self[0x2F4] = 0;
        self[0x2F6] = 0;
        return;
    }
    self[0x2F5] = 8;
    self[0x2F6] = b;
    self[0x2F7] = 0;
    self[0x2F4] = 0;
}
#endif

// FUNCTION: GAME 0x278570
struct UF {
    char pad[0x60];
    unsigned f;
};
extern "C" void func_00278570(char *self)
{
    if (*(int *)(self + 0x564) != 0x232 && *(short *)(self + 0x54A) > 0) {
        char *p = *(char **)(self + 0x670);
        if (p) {
            unsigned long f = (unsigned long)((UF *)p)->f;
            unsigned long b = f & 1;
            if (b && !(0.0f < *(float *)(self + 0x54C))) {
                self[0x2F5] = 1;
                self[0x2F4] = 0;
                self[0x2F6] = 0;
                self[0x2F7] = 0;
            }
        }
    }
}

extern "C" void calcParts__6cModel(char *);

static inline int IsSet(const int &v) { return v != 0; }
static inline char *Slot0(char *o)
{
    if (IsSet(*(unsigned char *)(o + 0x2B4)))
        return **(char ***)(o + 0x278);
    return 0;
}
// FUNCTION: GAME 0x279C20
extern "C" void func_00279C20(char *self)
{
    char *m = Slot0(self);
    if (m)
        *(char **)(m + 0x148) = self;
    *(float *)(self + 0x24C) = 1.0f;
    *(unsigned *)(self + 0x250) &= 0xFFFFFFEF;
    *(int *)(self + 0x1580) = 0;
    calcParts__6cModel(self);
}

extern "C" void setTextureExchange__6cModelPCUiPCvi(void *, const unsigned *, const void *, int);
extern "C" void func_002A8578(char *, char *, char *, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(char *);

// FUNCTION: GAME 0x273F98
extern "C" void func_00273F98(char *self)
{
    if ((*(int *)(self + 0x564) ^ 0x265) != 0)
        return;
    if (self[0x186A])
        self[0x186A] = (unsigned char)self[0x186A] - 1, *(unsigned *)(self + 0x254) &= 0xEFFFFFFF;
    else
        *(unsigned *)(self + 0x254) |= 0x10000000;
    char *p = *(char **)(self + 0x304);
    setTextureExchange__6cModelPCUiPCvi(self, *(unsigned **)(self + 0x284), (char *)(*(int *)(p + 0x8C) + (int)p), 0);
}

// FUNCTION: GAME 0x27F570
extern "C" void func_0027F570(char *self)
{
    switch ((unsigned char)self[0x2F6]) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(self, (char *)(*(int *)(p + 0xC) + (int)p), (char *)(*(int *)(p + 0x10) + (int)p), 5, 0, 0, 0.0f);
        self[0x2F6]++;
    }
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

extern "C" void func_0026B1E8(char *);

// FUNCTION: GAME 0x270C78
extern "C" void func_00270C78(char *self)
{
    int st = *(int *)(self + 0x564);
    if (st == 0x265 && (*(unsigned *)(self + 0x16D4) & 0x20000000)) {
        unsigned char c = 0x9F;
        self[0x2F7] = 1;
        *(unsigned char *)(self + 0x2F5) = c;
        self[0x2F4] = 0;
    } else {
        if (*(int *)(self + 0x564) == 0x279)
            func_0026B1E8(self);
        self[0x2F4] = 1;
        self[0x2F5] = 0xF;
        self[0x2F7] = 0;
    }
    self[0x2F6] = 0;
}

extern unsigned short D_00747A50;
extern char g_EmManage[];

// FUNCTION: GAME 0x274F50
extern "C" int func_00274F50(char *self)
{
    if ((*(int *)(self + 0x564) ^ 0x21C) != 0) return 0;
    if (D_00747A50 != 0x403) return 0;
    if (0.0f < *(float *)(self + 0x1748)) return 0;
    char *g = g_EmManage;
    char *a = *(char **)(g + 0x56C);
    if (!a) return 0;
    if (*(short *)(a + 0x54A) <= 0) return 0;
    char *b = *(char **)(g + 0x568);
    if (!b) return 0;
    if (*(short *)(b + 0x54A) <= 0) return 0;
    self[0x2F4] = 0;
    self[0x2F5] = 0x7A;
    self[0x2F6] = 0;
    self[0x2F7] = 0;
    return 1;
}

// FUNCTION: GAME 0x26A338
extern "C" void func_0026A338(char *self)
{
    int st = *(int *)(self + 0x564);
    if (st == 0x223)
        goto small;
    if (st < 0x223)
        goto big;
    if (st < 0x277) {
        if (st < 0x275)
            goto big;
        goto small;
    }
big:
    if (self[0x1700] & 1)
        *(float *)(self + 0x16FC) = 0.2617993950843811f;
    else
        *(float *)(self + 0x16FC) = -0.2617993950843811f;
    goto done;
small:
    if (self[0x1700] & 1)
        *(float *)(self + 0x16FC) = 0.12217304855585098f;
    else
        *(float *)(self + 0x16FC) = -0.12217304855585098f;
done:
    self[0x1700]++;
}

extern "C" void func_001CFE88(void *, int);

// FUNCTION: GAME 0x26BAD8
extern "C" void func_0026BAD8(char *self, unsigned n, int arg)
{
    if ((*(int *)(self + 0x564) ^ 0x211) == 0) {
        unsigned i = 0;
        unsigned cnt = 0;
        if (n) {
            void **p = (void **)(self + 0x710);
            do {
                if (*p) {
                    cnt++;
                    func_001CFE88(*p, arg);
                    *p = 0;
                }
                i++;
                p++;
            } while (i < 8 && cnt < n);
        }
    }
}

struct cVecZ;
extern cVecZ ZeroVec;
extern "C" void SetDamageCollRadius__11cDamageUnitif(void *, int, float);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" void SetDmgGiveHitVec__11cDamageGiveRC4cVec(void *, void *);

// DRAFT: GAME 0x262980 - 11 words: 0x49 emitted inside each arm (orig: before beq), tail sh scheduled after ld ra, lui a1 order; tried hoisted k/c locals, store swap, ZeroVec temp
#ifdef NONMATCHING
extern "C" void func_00262980(char *self)
{
    float r;
    char *d;
    if (*(int *)(self + 0x564) != 0x260) {
        r = 2.0f;
        d = *(char **)(self + 0x680);
    } else {
        d = *(char **)(self + 0x680);
        r = 3.0f;
    }
    *(short *)(d + 0x46) = 0x49;
    SetDamageCollRadius__11cDamageUnitif(*(void **)(self + 0x680), *(int *)(self + 0x684), r);
    *(int *)(*(char **)(self + 0x680) + 0x4C) = 0;
    SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x680), 1);
    SetDmgGiveHitVec__11cDamageGiveRC4cVec(*(void **)(self + 0x680), &ZeroVec);
    d = *(char **)(self + 0x680);
    *(int *)(d + 0x40) = -1;
    *(short *)(d + 0x44) = 0;
}
#endif

extern "C" int ReleaseEm__9cEmManageP7cEmBase(void *, void *);

// FUNCTION: GAME 0x279838
extern "C" void func_00279838(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    switch ((unsigned char)self[0x2F6]) {
    case 0:
        self[0x2F6]++;
    case 1:
        break;
    default:
        return;
    }
    {
        float f = *(float *)(self + 0x24C) - 0.1f;
        *(float *)(self + 0x24C) = f;
        if (f <= 0.0f) {
            *(float *)(self + 0x24C) = 0.0f;
            ReleaseEm__9cEmManageP7cEmBase(g_EmManage, self);
            self[0x2F6]++;
        }
    }
}
