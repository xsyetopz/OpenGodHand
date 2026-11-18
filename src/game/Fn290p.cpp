// Small helpers from 0x290000-0x2A0000.
#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

extern "C" void func_00290000(void *);
extern "C" void *func_002BEF60(void *, unsigned);
extern char g_RoomSave[];

// FUNCTION: GAME 0x290090
extern "C" char *func_00290090(char *self)
{
    char *p = self;
    for (int i = 63; i != -1; i--) {
        func_00290000(p);
        p += 0x14;
    }
    *(int *)(self + 0x500) = 0;
    *(int *)(self + 0x504) = 0;
    ZQ(self, 0x520);
    *(int *)(self + 0x508) = 0;
    *(int *)(self + 0x50C) = 0;
    return self;
}

// FUNCTION: GAME 0x292048
extern "C" int func_00292048(int, int id)
{
    if (id < 0x900)
        return id;
    if (id < 0x940)
        return 0x3DA;
    if (id < 0xA00) {
        switch (id) {
        case 0x9C0:
            return 0x9C0;
        case 0x9C2:
            return 0x3DC;
        }
        return id;
    }
    int r = 0x3DB;
    if (id >= 0xB00)
        r = 0xFFFF;
    return r;
}

extern "C" int strcmp(const char *, const char *);
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern char D_0044A7A8[];

struct Link {
    void *_a;
    Link *next;
    char *obj;
};

// FUNCTION: GAME 0x292DC8
extern "C" char *func_00292DC8(char *self, const float *pos, float r)
{
    for (Link *n = *(Link **)(self + 0x500); n; n = n->next) {
        char *o = n->obj;
        if (o && strcmp(D_0044A7A8, *(char **)(o + 0x4AC)) == 0 && *(short *)(o + 0x54A) > 0 &&
            !(capVu0MagnitudeSqXZ__FPCfT0(*(float **)(o + 0xF0), pos) > r * r))
            return o;
    }
    return 0;
}

extern char *g_Sce;
extern "C" char *func_002951B0(char *, char *);

// DRAFT: GAME 0x295860 - 2 words differ: original sets s2 (n = 0) before s0 (e = self + 0x10)
#ifdef NONMATCHING
extern "C" int func_00295860(char *self)
{
    int n;
    if (*(unsigned char *)(g_Sce + 0x14) == 1)
        return 0;
    n = 0;
    char *e = self + 0x10;
    for (unsigned i = 0; i < 2; i++, e += 0x18) {
        if (*(unsigned char *)(e + 0x13)) {
            char *o = func_002951B0(self, e);
            short a = *(short *)(e + 0x16);
            if (a >= *(short *)(o + 0x548))
                *(short *)(o + 0x54A) = *(unsigned short *)(o + 0x548);
            else
                *(short *)(o + 0x54A) = a;
            *(int *)(self + 4) = *(unsigned char *)(e + 0x12) + 0x200;
            n++;
            *(unsigned char *)(e + 0x13) = 0;
        }
    }
    return n != 0;
}
#endif

extern "C" int func_0026ECC0(char *);

// DRAFT: GAME 0x291AC8 - 31 words: original has slti+xori+bnel for the t<0x250 test; >=, ==0, int flag, compound and unsigned-subtract forms all failed
#ifdef NONMATCHING
extern "C" int func_00291AC8(char *self, const float *pos, char *skip, float r)
{
    for (Link *n = *(Link **)(self + 0x500); n; n = n->next) {
        char *o = n->obj;
        if (!o)
            continue;
        if (o == skip)
            continue;
        int t = *(unsigned short *)(o + 0x2FE);
        if (t < 0x200)
            continue;
        if (!(t < 0x250))
            continue;
        if (!func_0026ECC0(o))
            continue;
        if (capVu0MagnitudeSqXZ__FPCfT0(*(float **)(o + 0xF0), pos) < r * r)
            return 1;
    }
    return 0;
}
#endif

extern char D_00754C80[];
extern "C" void func_0031A600(void *, int, int);

// DRAFT: GAME 0x299948 - registers differ: original copies the buffer pointer to a3 and derives q=a3+8 in a2 (28 words differ)
#ifdef NONMATCHING
extern "C" void func_00299948(char *buf)
{
    unsigned n = ((*(unsigned *)(buf + 0x10000) & 0xFFFFFFF) - (unsigned)buf) >> 4;
    n--;
    *(unsigned long *)buf = n | 0x70000000;
    *(unsigned *)(buf + 8) = 0x11000000;
    *(unsigned *)(buf + 0xC) = 0;
    if (n)
        *(unsigned *)(buf + 0xC) = n | 0x50000000;
    func_0031A600(D_00754C80, 4, 4);
}
#endif

extern "C" void func_00290028(void *);
extern "C" unsigned irand__Fv();
extern volatile char scrArray[];

// DRAFT: GAME 0x290110 - scrArray address is hoisted into s3 across the calls (frame 0x50 vs 0x40), about 30 words shift
#ifdef NONMATCHING
extern "C" void func_00290110(char *self)
{
    char *p = self;
    do {
        func_00290028(p);
        p += 0x14;
    } while (p < self + 0x500);
    *(int *)(self + 0x500) = 0;
    *(int *)(self + 0x504) = 0;
    *(int *)(self + 0x508) = 0;
    *(int *)(self + 0x50C) = 0;
    *(int *)(self + 0x55C) = 0;
    *(float *)(self + 0x548) = 1.0f;
    unsigned r = irand__Fv();
    self[0x53E] = 0;
    self[0x540] = 0;
    self[0x541] = 0;
    *(int *)(self + 0x560) = 0;
    *(int *)(self + 0x564) = 0;
    *(int *)(self + 0x568) = 0;
    *(int *)(self + 0x56C) = 0;
    *(int *)(self + 0x570) = 0;
    *(int *)(self + 0x588) = 0;
    *(int *)(self + 0x58C) = 0;
    *(int *)(self + 0x590) = 0;
    *(int *)(self + 0x594) = 0;
    self[0x53F] = r % 5;
    int *a = (int *)(self + 0x5AC);
    for (unsigned i = 0; i < 2; i++)
        *a++ = 0;
    int *b = (int *)(self + 0x574);
    for (unsigned i = 0; i < 5; i++)
        *b++ = 0;
    self[0x518] = 0;
    *(volatile int *)(scrArray + 0xC) = 0;
    scrArray[4] = 0;
    *(volatile int *)(scrArray + 8) = 0;
    self[0x5B5] = 0;
}
#endif
