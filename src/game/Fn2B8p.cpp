// Unnamed units in 0x2B8000-0x2C0000 (flag setters, virtual-call setters).

// FUNCTION: GAME 0x2B8820
extern "C" int func_002B8820(char *self)
{
    *(unsigned *)(self + 0x254) |= 0x8000000;
    *(char *)(self + 0x4D4) = 0;
    *(unsigned *)(self + 0x4A8) |= 0x10000000;
    return 1;
}

// FUNCTION: GAME 0x2BA540
extern "C" void func_002BA540(char *self, float f)
{
    *(float *)(self + 0x110) = f;
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

// FUNCTION: GAME 0x2BA750
extern "C" void func_002BA750(char *self, float f)
{
    *(float *)(self + 0x114) = f;
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

// FUNCTION: GAME 0x2BA788
extern "C" void func_002BA788(char *self, float f)
{
    *(float *)(self + 0x110) = f;
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

// FUNCTION: GAME 0x2BAB00
extern "C" void func_002BAB00(char *self, float f)
{
    *(float *)(self + 0x114) = f;
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

extern char D_0044BED0[];
extern "C" void func_002BB018(char *, int);

// FUNCTION: GAME 0x2BAFE0
extern "C" void func_002BAFE0(char *self, int f)
{
    *(char **)(self + 0x100) = D_0044BED0;
    if (f & 1) func_002BB018(self, 0x110);
}

// FUNCTION: GAME 0x2BB098
extern "C" int *func_002BB098(int *p)
{
    for (unsigned i = 0; i < 4; i++, p += 2)
        if (!*p) return p;
    return 0;
}

extern "C" void func_002BE6C8(char *);

// FUNCTION: GAME 0x2BE670
extern "C" void func_002BE670(char *self)
{
    func_002BE6C8(self);
    *(char *)(self + 4) = 0;
    *(int *)self = 0;
}

extern int D_00747A88;

// FUNCTION: GAME 0x2BF518
extern "C" void func_002BF518(char *p)
{
    if (D_00747A88 >= 0) {
        p[0] = 5;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
    }
}

extern "C" void func_002B1C80(char *);

// FUNCTION: GAME 0x2B17F8
extern "C" void func_002B17F8(char *self)
{
    unsigned short a = *(unsigned short *)(self + 0xA6);
    unsigned short b = *(unsigned short *)(self + 0xA8);
    *(unsigned short *)(self + 0xAE) = a;
    *(unsigned short *)(self + 0xB0) = b;
    func_002B1C80(self);
}

// FUNCTION: GAME 0x2B2F38
extern "C" int func_002B2F38(char *self)
{
    *(float *)(self + 0x6C) = (float)*(unsigned short *)(*(char **)(self + 0x8C) + 2) / 100.0f;
    return 0;
}

extern "C" char *func_002B4F98();
extern "C" void func_002D42F8(char *);

// FUNCTION: GAME 0x2B4D38
extern "C" void func_002B4D38()
{
    char *p = func_002B4F98();
    if (p) func_002D42F8(p);
}

extern "C" void func_002BB760(float, char *, char *, char *);

// FUNCTION: GAME 0x2BD7F8
extern "C" void func_002BD7F8(char *a, char *b, char *c)
{
    func_002BB760(0.0f, c, a, b);
}

// FUNCTION: GAME 0x2BF170
extern "C" void func_002BF170(char *p)
{
    p[6] = 0;
    p[7] = 0;
    p[9] = 0;
    *(short *)(p + 4) = 0;
    p[10] = 0;
    p[12] = 0;
    p[13] = 0;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
}

extern "C" void func_002BE5F0(char *);

// DRAFT: GAME 0x2BE858
// diff: 1 word, addu operand order (a1,a0 in the original); ~25 source forms tried (int/long casts, shift, struct, unsigned, int param, commuted operands, temps)
#ifdef NONMATCHING
extern "C" void func_002BE858(char *p, int i)
{
    p = p + (i << 3);
    if (*(unsigned char *)(p + 4) == 1) func_002BE5F0(p);
}
#endif

// FUNCTION: GAME 0x2BF108
extern "C" char *getFree__9cRoomSaveUi(char *self, unsigned i)
{
    return i < 0x10 ? *(char **)self + 0x1610 + i * 4 : self + 0x1618 + i * 4;
}

extern char g_CollisionManager[];
extern "C" int func_002B8A30(void *, unsigned);

// FUNCTION: GAME 0x2B8A70
extern "C" void func_002B8A70(char *self, int v)
{
    *(int *)(self + 0x10) = v;
    *(char *)(self + 0xC) = func_002B8A30(g_CollisionManager, v);
}

extern char CoreSave[];
extern char g_RoomSave[];
extern "C" void stageInit__9cCoreSave(char *);
extern "C" void systemInit__9cRoomSave(char *);

// FUNCTION: GAME 0x2BF8C8
extern "C" void stageClear__12cSaveManager()
{
    stageInit__9cCoreSave(CoreSave);
    systemInit__9cRoomSave(g_RoomSave);
}

extern char D_0044BAB0[];
extern char D_0044BA68[];

// FUNCTION: GAME 0x2BA178
extern "C" char *func_002BA178(char *self, int n, char c)
{
    *(int *)(self + 8) = (n + 15) & ~15u;
    *(char **)(self + 0x18) = D_0044BAB0;
    *(char *)(self + 0xC) = c;
    *(int *)self = 0;
    *(int *)(self + 4) = 0;
    *(int *)(self + 0x10) = 0;
    return self;
}

// FUNCTION: GAME 0x2B8AE0
extern "C" char *func_002B8AE0(char *self)
{
    func_002BA178(self, 0x26C, 2);
    *(char **)(self + 0x18) = D_0044BA68;
    return self;
}

// FUNCTION: GAME 0x2BA6B0
extern "C" void func_002BA6B0(char *self)
{
    char *vt = *(char **)(self + 0x100);
    *(float *)(self + 0xE4) = ((float (*)(char *))(*(void **)(vt + 0x24)))(self + *(short *)(vt + 0x20));
}

// FUNCTION: GAME 0x2B3BE0
static inline void SetF14(char *s, unsigned m) { *(unsigned *)(s + 0x14) |= m; }
static inline void ClrF14(char *s, unsigned m) { *(unsigned *)(s + 0x14) &= ~m; }
extern "C" int func_002B3BE0(char *self)
{
    SetF14(self, 0x800);
    if (*(unsigned *)(self + 0x14) & 0x100) {
        ClrF14(self, 0x800);
        ClrF14(self, 0x100);
        return 0;
    }
    return 1;
}

// DRAFT: GAME 0x2B4FE8
// diff: 9 words, loop exit layout and which pointer is loaded vs returned
#ifdef NONMATCHING
extern "C" char *func_002B4FE8(char *self, int id)
{
    char *q = self + 0x1C;
    char *p = q;
    int n = 0;
    do {
        if (*(int *)q == id) return p;
        n++;
        q += 8;
        p += 8;
    } while (n < 0x40);
    return 0;
}
#endif

extern "C" void func_002BB2D8();

// FUNCTION: GAME 0x2BB258
extern "C" void setOffsetPos__15cCollisionShapeRC4cVec(char *self, float *v)
{
    float *d = (float *)(self + 0x50);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
    func_002BB2D8();
}

extern "C" void func_002BE670(char *);

// DRAFT: GAME 0x2BE8B0
// diff: 1 word, addu operand order (same as 0x2BE858)
#ifdef NONMATCHING
extern "C" void unlinkNoFree__7cRelSysQ27cRelSys8eRelType(char *p, int i)
{
    p = p + (i << 3);
    if (*(unsigned char *)(p + 4) == 1) func_002BE670(p);
}
#endif
