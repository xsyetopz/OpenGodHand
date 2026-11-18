struct V3 {
    float x, y, z;
};
extern char Snd[];
extern char g_CollSolidManage[];
extern const char D_004296F0[];
extern const char D_00429620[];
extern const char D_004283D8[];
extern unsigned int D_00747A80;
extern "C" void func_001B6E90(void *);
extern "C" void func_001B6F38(void *, void *);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" int isClip__C8cGameObj(void *);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(void *, void *);
extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *, void *);

// FUNCTION: GAME 0x001BFCE8
extern "C" void func_001BFCE8(void *o)
{
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 10, o, 0, 0, 0, 0);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1B80B0
// diff: 18 words: original keeps a0 (no a2 copy), stores before frame; 8 B larger
extern "C" int func_001B80B0(char *self, int v)
{
    *(int *)(self + 0x5E8) = v;
    *(int *)(self + 0x5F0) = v;
    if (D_00747A80 & 0x20000000)
        return 1;
    return isClip__C8cGameObj(self) != 0;
}
#endif

// FUNCTION: GAME 0x001B7118
// The virtual call is cast to an int-returning pointer: that gives the original v1 (vtable) / v0 (slot) allocation; a void cast swaps them.
extern "C" int func_001B7118(char *self, char *a)
{
    *(char **)(self + 0x5E0) = a;
    unsigned v = *(unsigned *)(a + 0x20);
    if (v) {
        if (v < 0x200)
            *(unsigned *)(self + 0x560) = v + 0x300;
        else
            *(unsigned *)(self + 0x560) = v + 0x700;
    }
    char *vt = *(char **)(self + 0x214);
    ((int (*)(char *))*(void **)(vt + 0x44))(self + *(short *)(vt + 0x40));
    return 1;
}

// FUNCTION: GAME 0x001B15C8
extern "C" void func_001B15C8(char *self, int a, int b, V3 *c, V3 *d)
{
    *(int *)(self + 0x600) = a;
    *(int *)(self + 0x604) = b;
    V3 *p = (V3 *)(self + 0x610);
    if (p != c) {
        p->x = c->x;
        p->y = c->y;
        p->z = c->z;
    }
    V3 *q = (V3 *)(self + 0x620);
    if (q != d) {
        q->x = d->x;
        q->y = d->y;
        q->z = d->z;
    }
}

// FUNCTION: GAME 0x001B1B78
extern "C" void func_001B1B78(char *self, void *a)
{
    *(const char **)(self + 0x214) = D_004283D8;
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
    func_001B6F38(self, a);
}

// FUNCTION: GAME 0x001BFC88
extern "C" void func_001BFC88(char *self)
{
    if (checkDamage__7cOmBaseP11cDamageTake(self, *(void **)(self + 0x600)) == 1) {
        *(unsigned char *)(self + 0x2F4) = 2;
        *(unsigned char *)(self + 0x2F5) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned *)(self + 0x5B0) |= 1;
    }
}

extern "C" char *getMeshPtr__6cModeli(void *, int);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);

// FUNCTION: GAME 0x001BFB28
extern "C" int func_001BFB28(char *self)
{
    char *m = getMeshPtr__6cModeli(self, 0);
    *(unsigned *)(m + 0x380) &= 0xFFFFFFFE;
    unsigned *p = *(unsigned **)(self + 0x600);
    if (p)
        *p |= 1;
    return 1;
}

// FUNCTION: GAME 0x001B1860
extern "C" void func_001B1860(char *self)
{
    *(short *)(*(char **)(self + 0x66C) + 0x46) = 0;
    *(int *)(*(char **)(self + 0x66C) + 0x4C) = 0;
    SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x66C), 0);
    *(short *)(*(char **)(self + 0x670) + 0x46) = 0;
    *(int *)(*(char **)(self + 0x670) + 0x4C) = 0;
    SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x670), 0);
}

// FUNCTION: GAME 0x001B7E50
extern "C" void func_001B7E50(char *self, V3 *a)
{
    V3 *p = (V3 *)(self + 0x490);
    if (p != a) {
        p->x = a->x;
        p->y = a->y;
        p->z = a->z;
    }
    V3 *q = *(V3 **)(self + 0xF0);
    if (q != p) {
        q->x = p->x;
        q->y = p->y;
        q->z = p->z;
    }
    *(unsigned *)(self + 0x5B8) |= 0x10;
}

// FUNCTION: GAME 0x001B7220
extern "C" void func_001B7220(void *o, float f, int id)
{
    char *m = getMeshPtr__6cModeli(o, 0);
    for (; m; m = *(char **)(m + 0x404))
        if (*(unsigned char *)(m + 0x40C) == id)
            *(float *)(m + 0x3AC) = f;
}
