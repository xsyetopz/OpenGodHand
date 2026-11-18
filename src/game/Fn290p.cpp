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

// DRAFT: GAME 0x295860 - 9 words differ: s3 counter init and a0/v1 use in the g_Sce test are scheduled differently
#ifdef NONMATCHING
extern "C" int func_00295860(char *self)
{
    int n = 0;
    if (*(unsigned char *)(*(char **)&g_Sce + 0x14) == 1)
        return 0;
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
