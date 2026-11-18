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

struct Link {
    void *_a;
    Link *next;
    char *obj;
};

static inline unsigned char InRange(int t)
{
    unsigned char r;
    if (t < 0x200)
        r = 0;
    else
        r = t < 0x300;
    return r;
}

// FUNCTION: GAME 0x2948E8
extern "C" void func_002948E8(char *self, int arg)
{
    for (Link *n = *(Link **)(self + 0x500); n; n = n->next) {
        char *o = n->obj;
        if (!o)
            continue;
        if (InRange(*(unsigned short *)(o + 0x2FE))) {
            char *vt = *(char **)(o + 0x214);
            ((void (*)(char *, int))(*(void **)(vt + 0x64)))(o + *(short *)(vt + 0x60), arg);
        }
    }
}
