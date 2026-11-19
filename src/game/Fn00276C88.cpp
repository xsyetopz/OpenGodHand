#include "game/cVec.h"
extern "C" void func_001038E0(void *, void *, void *, void *, float, float);
extern "C" void *Getplayer__Fv();
extern "C" void reset__4pl00(void *);
extern "C" void ReleaseEmAll__9cEmManage(void *);
extern "C" void clear__12cDataManager(void *);
extern "C" void systemInit__11cDataHolder(void *);
extern char g_EmManage[], g_EmdManager[], EventConfig[];

extern int D_003BF958, D_003BF970, D_003BF988, D_003BF9A0, D_003BF9B8, D_003BFA10, D_003BFA68, D_005850C0;
extern int D_003BFFD0, D_003BFFE8, D_003C0000, D_003C0018, D_003C0030, D_003C0088, D_003C00E0, D_00585660;

struct Q {
    char _p0[0x2130];
    int m2130; void *m2134; void *m2138; int m213C, m2140, m2144; void *m2148; void *m214C; int m2150, m2154;
    void *m2158; void *m215C; void *m2160; void *m2164; int m2168; float m216C, m2170; int m2174; float m2178, m217C, m2180; int m2184, m2188, m218C;
    cVec m2190; char _p1[4];
};

// DRAFT: GAME 0x276C88 - 70 differing words: store and constant-load order follow the source, but the self/cVec pointer registers and the early D_003BF988 hoist differ (variants tried: char* offsets, reordered stores, early cVec pointer)
#ifdef NONMATCHING
extern "C" void func_00276C88(Q *self)
{
    self->m2130 = 0x15;
    self->m2134 = &D_003BF958; self->m2138 = &D_003BF9A0;
    self->m213C = 0; self->m2140 = 0; self->m2144 = 0;
    self->m2148 = &D_003BF970; self->m214C = &D_003BF988;
    self->m2150 = 0; self->m2154 = 0;
    self->m2158 = &D_003BF9B8; self->m215C = &D_003BFA10; self->m2160 = &D_003BFA68; self->m2164 = &D_005850C0;
    self->m2168 = 0;
    self->m216C = 0.015f; self->m2170 = 0.8f; self->m2174 = 1;
    self->m2188 = 0; self->m2178 = 0; self->m217C = 0.8f; self->m2180 = 0.5f;
    self->m2184 = 0; self->m218C = 256;
    struct { cVec c; float w; } v;
    v.c.x = 0; v.c.y = 0; v.c.z = 0; v.w = 1.0f;
    self->m2190 = v.c;
    *(float *)((char *)self + 0x21A0) = 0;
    func_001038E0(self, (char *)self + 0x2130, (char *)self + 0x5B0, &D_003BF988, 0.1f, *(float *)((char *)self + 0x21A0));
}
#endif

// DRAFT: GAME 0x283968 - same shape as 0x276C88 with its own data symbols; same 70-word register pattern
#ifdef NONMATCHING
extern "C" void func_00283968(Q *self)
{
    self->m2130 = 0x15;
    self->m2134 = &D_003BFFD0; self->m2138 = &D_003C0018;
    self->m213C = 0; self->m2140 = 0; self->m2144 = 0;
    self->m2148 = &D_003BFFE8; self->m214C = &D_003C0000;
    self->m2150 = 0; self->m2154 = 0;
    self->m2158 = &D_003C0030; self->m215C = &D_003C0088; self->m2160 = &D_003C00E0; self->m2164 = &D_00585660;
    self->m2168 = 0;
    self->m216C = 0.015f; self->m2170 = 0.8f; self->m2174 = 1;
    self->m2188 = 0; self->m2178 = 0; self->m217C = 0.8f; self->m2180 = 0.5f;
    self->m2184 = 0; self->m218C = 256;
    struct { cVec c; float w; } v;
    v.c.x = 0; v.c.y = 0; v.c.z = 0; v.w = 1.0f;
    self->m2190 = v.c;
    *(float *)((char *)self + 0x21A0) = 0;
    func_001038E0(self, (char *)self + 0x2130, (char *)self + 0x5B0, &D_003C0000, 0.1f, *(float *)((char *)self + 0x21A0));
}
#endif

// DRAFT: GAME 0x296818 - 52 differing words (308 vs 316 bytes): prologue matches; the jump-table dispatch, EventConfig hoist and set-tail store order differ, and case 8 uses another base register (variants tried: char* offsets, separate lbu index which gave 69)
#ifdef NONMATCHING
extern "C" int func_00296818(char *self)
{
    reset__4pl00(Getplayer__Fv());
    if (*(unsigned *)(EventConfig + 4) & 1)
        goto set;
    {
        int v = *(signed char *)(self + 5);
        if ((unsigned)v >= 9)
            return 0;
        switch (v) {
        case 0:
            ReleaseEmAll__9cEmManage(g_EmManage);
            *(unsigned char *)(self + 5) += 1;
            return 0;
        case 6:
            if (*(unsigned *)(EventConfig + 4) & 0x400)
                goto set;
            /* fallthrough */
        case 1: case 2: case 3: case 4: case 5: case 7:
            *(unsigned char *)(self + 5) = v + 1;
            return 0;
        case 8: {
            char *base;
            int n;
            clear__12cDataManager(g_EmdManager);
            base = *(char **)(g_EmdManager + 8);
            if (!base)
                goto set;
            for (n = *(int *)(g_EmdManager + 4) - 1; n != -1; n--)
                systemInit__11cDataHolder(base + n * 0x5C);
            goto set;
        }
        default:
            return 0;
        }
    }
set:
    *(unsigned char *)(self + 7) = 0;
    *(unsigned char *)(self + 4) = 2;
    *(unsigned char *)(self + 5) = 0;
    *(unsigned char *)(self + 6) = 0;
    return 1;
}
#endif
