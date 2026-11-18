struct VE { short adj; short pad; void *(*fn)(void *); };
struct VS { short adj; short pad; void (*fn)(void *, void *); };
struct V4 { float x, y, z, w; };

// FUNCTION: GAME 0x1AD918
extern "C" void setOpenFix__5cOm5a(char *self)
{
    if (*(unsigned char *)(self + 0x60D) == 0) {
        char *vt = *(char **)(self + 0x214);
        void *pp = ((void *(*)(void *))*(void **)(vt + 0x84))(self + *(short *)(vt + 0x80));
        V4 v;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(v) : "r"(pp));
        if (*(int *)(self + 0x600) == 0)
            v.y = v.y + *(float *)(self + 0x790);
        else
            v.y = v.y - *(float *)(self + 0x790);
        char *vt2 = *(char **)(self + 0x214);
        ((void (*)(void *, void *))*(void **)(vt2 + 0x74))(self + *(short *)(vt2 + 0x70), &v);
        *(int *)(self + 0x5B8) &= -0x101;
        self[0x60D] = 1;
        self[0x2F4] = 3;
        self[0x2F5] = 0;
        self[0x2F6] = 0;
        self[0x2F7] = 0;
    }
}

// FUNCTION: GAME 0x1AD9C8
extern "C" void setCloseFix__5cOm5a(char *self)
{
    if (*(unsigned char *)(self + 0x60D) == 1) {
        char *vt = *(char **)(self + 0x214);
        void *pp = ((void *(*)(void *))*(void **)(vt + 0x84))(self + *(short *)(vt + 0x80));
        V4 v;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(v) : "r"(pp));
        if (*(int *)(self + 0x600) == 0)
            v.y = v.y - *(float *)(self + 0x790);
        else
            v.y = v.y + *(float *)(self + 0x790);
        char *vt2 = *(char **)(self + 0x214);
        ((void (*)(void *, void *))*(void **)(vt2 + 0x74))(self + *(short *)(vt2 + 0x70), &v);
        self[0x2F7] = 0;
        self[0x60D] = 0;
        self[0x2F4] = 0;
        self[0x2F5] = 0;
        self[0x2F6] = 0;
        *(int *)(self + 0x5B8) |= 0x100;
    }
}

extern char g_DmgManage[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" int AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff(void *, void *, void *, void *, float, float);

// FUNCTION: GAME 0x1A6098
extern "C" int func_001A6098(char *self)
{
    func_001B6FB8(self);
    V4 a, b, c, d;
    a.x = 1.6f; a.y = 2.24f; a.z = 1.6f; a.w = 1.0f;
    b.x = 1.6f; b.y = 2.24f; b.z = 1.6f; b.w = 1.0f;
    V4 *pc = &c;
    c.x = 0; c.y = 0; c.z = 0; pc->w = 1.0f;
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 1);
    *(void **)(self + 0x608) = t;
    if (t) {
        V4 *pd = &d;
        d.x = 0; d.y = 0; d.z = 0; pd->w = 1.0f;
        AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff(t, self + 0x80, &c, &d, b.y, b.x * 0.5f);
    }
    *(unsigned char *)(self + 0x604) = 0;
    *(short *)(self + 0x548) = 0x28;
    *(short *)(self + 0x54A) = 0x28;
    return 1;
}
