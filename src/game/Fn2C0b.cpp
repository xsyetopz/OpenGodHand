extern char Snd[];
extern "C" void *GetBgmData__4cSndi(void *, int);
extern "C" int func_002CFF68(void *);
extern "C" int func_002CC728(void *, int, void *, int);

struct BgmArgs {
    int a, b, c;
    short d, e;
};

// FUNCTION: GAME 0x2CC9C0
extern "C" int func_002CC9C0(void *self, int idx, int a, int b, int c, int d, int e)
{
    int ok = func_002CFF68(GetBgmData__4cSndi(Snd, idx));
    if (!ok) {
        return 0;
    }
    BgmArgs args;
    args.a = a;
    args.b = b;
    args.c = c;
    args.d = d;
    args.e = e;
    return func_002CC728(self, idx, &args, 1);
}

struct Blk {
    void *owner;
    Blk *prev;
    Blk *next;
    int size;
    int cur;
    int end;
    int req;
};
extern "C" Blk *func_002CD968(void *, int);
extern "C" Blk *func_002CD930(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2CD7C8 - self/sz saved in swapped s1/s2, store order and beql differ (20 words)
extern "C" int func_002CD7C8(void *self, unsigned n)
{
    int sz = (n + 15) & 0xFFFFFFF0u;
    Blk *s = func_002CD968(self, sz);
    if (s) {
        Blk *b = func_002CD930(self);
        if (b) {
            b->prev = s;
            b->next = s->next;
            b->req = sz;
            b->owner = self;
            b->size = s->size - sz;
            b->cur = s->cur + sz;
            b->end = s->cur;
            if (s->next) {
                s->next->prev = b;
            }
            s->size = 0;
            s->next = b;
            return b->end;
        }
    }
    return 0;
}
#endif

extern "C" void func_002C0E20(void *);

// FUNCTION: GAME 0x2C2EB8
extern "C" void func_002C2EB8(void *unused, char *u)
{
    if ((unsigned char)u[5] == 1 && (u[0x34] & 1)) {
        func_002C0E20(u);
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2CCB58 - Snd base lands in a1 not a3 and sltiu result skips the daddu temp (34 words, 136 vs 160 bytes)
extern "C" int func_002CCB58(int *self)
{
    self[0x30] = self[0x2F];
    int a1 = self[0x24];
    char *snd = Snd;
    int r = 0;
    if (self[0x23] - 0x80 == *(int *)(snd + 0x118)) {
        r = a1 == *(int *)(snd + 0x11C);
    }
    if (r == 1) {
        self[0x26] |= 8;
        r = 1;
        self[0x2F] = *(int *)(snd + 0x120);
    } else {
        unsigned f = self[0x26];
        self[0x26] = f & ~8u;
        r = 1;
        int *p = (int *)self[0x29];
        if (!(f & 8)) {
            r = 0;
        }
        if (p) {
            self[0x2F] = p[1];
        }
    }
    return r;
}
#endif

struct PolyInfo {
    int flags;
    char _p0[0x2C];
    long attr;
    char _p1[0x18];
    float v[12];
    float w, h;
    int z;
    float one;
};
extern "C" long Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(float *, unsigned, unsigned, PolyInfo *, int, unsigned);

// FUNCTION: GAME 0x2C7850
extern "C" void func_002C7850(void *unused, int ot, unsigned n)
{
    PolyInfo info;
    long k = 0x32001;
    info.flags = 0x20;
    info.attr = k;
    info.v[0] = 0;
    info.v[1] = 0;
    info.v[2] = 0;
    info.v[3] = 1.0f;
    info.v[4] = 512.0f;
    info.v[5] = 0;
    info.v[6] = 0;
    info.v[7] = 1.0f;
    info.v[8] = 0;
    info.v[9] = 448.0f;
    info.v[10] = 0;
    info.v[11] = 1.0f;
    info.w = 512.0f;
    info.h = 448.0f;
    info.one = 1.0f;
    info.z = 0;
    Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(info.v, 0x80808080, 1, &info, ot, n);
}

// FUNCTION: GAME 0x2CBD10
extern "C" int func_002CBD10(char *self, short a, short b, int key, short lo, short hi, int skip)
{
    int idx = *(int *)(self + 0x1E0);
    char *kp = self + 0x164;
    int i;
    for (i = 0; i < 16; i++, idx--) {
        if (idx < 0) {
            idx += 16;
        }
        if (key && key != *(int *)(&kp[idx << 3])) {
            continue;
        }
        char *e = self + idx * 8;
        if (a != *(short *)(e + 0x160)) {
            continue;
        }
        short y = *(short *)(e + 0x162);
        if (b == y) {
            return 1;
        }
        if (y < lo || hi < y) {
            continue;
        }
        if (--skip == -1) {
            break;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x2CC900
extern "C" int func_002CC900(void *self, int idx, int a, int b, int c, int d, int e)
{
    if (func_002CFF68(GetBgmData__4cSndi(Snd, idx)) && a < 0x38) {
        BgmArgs args;
        args.a = a;
        args.b = b;
        args.c = c;
        args.d = d;
        args.e = e;
        return func_002CC728(self, idx, &args, 0);
    }
    return 0;
}

extern "C" void func_002CDA80(void *);
extern "C" void func_002CE430(void *);

struct LNode {
    int a;
    LNode *next;
    int b;
    int flags;
};

// FUNCTION: GAME 0x2CA5D8
extern "C" void func_002CA5D8(char *self)
{
    unsigned a = *(unsigned *)(self + 0xB0);
    unsigned b = *(unsigned *)(self + 0xAC);
    LNode *p = *(LNode **)(self + 0x1C);
    *(unsigned *)(self + 0xB0) = a & 0xFBFFFFFF;
    *(unsigned *)(self + 0xAC) = b & 0xFBFFFFFF;
    while (p) {
        func_002CDA80(p);
        p = p->next;
    }
    if (*(unsigned *)(self + 0xAC) & 0x4000000) {
        for (p = *(LNode **)(self + 0x1C); p; p = p->next) {
            unsigned long f = (unsigned long)p->flags;
            unsigned long b = (f >> 2) & 1;
            if (b) {
                func_002CE430(p);
            }
        }
    }
}

extern char Sys[];
extern char WorldTime[];
extern "C" void func_002D9BD0(void *);
extern "C" void func_002D9BD8(void *);

// FUNCTION: GAME 0x2C3440
extern "C" void func_002C3440(char *self)
{
    char *sys = Sys;
    *(unsigned short *)(self + 0x112) = 0xFFFF;
    *(int *)(self + 0x104) = 0;
    *(int *)(self + 0xEC) = 0;
    *(int *)(self + 0xF0) = 0;
    *(int *)(self + 0xF4) = 0;
    *(int *)(self + 0xF8) = 0;
    *(int *)(self + 0xFC) = 0;
    *(int *)(self + 0x100) = 0;
    self[0x108] = 0;
    *(short *)(self + 0xE8) = 0;
    *(int *)(sys + 0x610) = 0xFFFF;
    int f = *(int *)(self + 0x48);
    f &= -2;
    f &= -3;
    *(int *)(self + 0x48) = f;
    unsigned st = *(unsigned *)(sys + 0x590);
    if ((st & 1) == 0) {
        func_002D9BD0(WorldTime);
        void (*fn)() = *(void (**)())(*(char **)(self + 0xD4) + 8);
        if (fn) {
            fn();
        }
        func_002D9BD8(WorldTime);
    }
}

extern int D_00747A24;
extern char Door[];
extern void *g_Sce;
extern "C" int getJumpData__5cDoorUcUcUcbUc(void *, int, int, int, int, int);
extern "C" void setDoorJump__5cDoor(void *);
extern "C" void func_002C4DD0(void *, int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x2C2078 - 20 words differ; bit test and frame/branch layout
extern "C" int func_002C2078(char *self)
{
    char *p = self + 0x5C;
    unsigned long f = D_00747A24;
    unsigned long b = (f >> 3) & 1;
    if (b) {
        return 0;
    }
    if (!getJumpData__5cDoorUcUcUcbUc(Door, (unsigned char)p[0x1D], (unsigned char)p[2], 2, 0, 0)) {
        return 0;
    }
    unsigned char m = p[0x1E];
    if (m == 1) {
        return 0;
    }
    if (*(int *)(p + 0x18)) {
        func_002C4DD0(g_Sce, *(int *)(p + 0x18), *(int *)(p + 0x14));
        if (*(unsigned short *)(Door + 0x14) != 0xFFFF) {
            *(int *)(p + 0x18) = 0;
        }
    }
    setDoorJump__5cDoor(Door);
    return 0;
}
#endif
