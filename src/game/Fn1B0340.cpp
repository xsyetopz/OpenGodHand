struct Vq {
    float x, y, z, w;
    Vq(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
static inline int Ltp(const int &v, int n) { return n < v; }
extern char g_DmgManage[];
extern char g_CollSolidManage[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
extern "C" void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, char *, const Vq &, float);
extern "C" void CreateUnit__21cCollisionSolidManageP8cGameObjQ225cCollisionSolidManageUnit9ePRIORITYf(void *, char *, int, float);
extern "C" void CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf(void *, char *, char *, const Vq &, float);

// FUNCTION: GAME 0x1B0340
extern "C" int func_001B0340(char *self)
{
    func_001B6FB8(self);
    Vq a(0.0f, 0.0f, 0.0f, 1.0f);
    if ((*(void **)(self + 0x600) = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 1))) {
        char *m = Ltp(*(unsigned char *)(self + 0x2B4), 0) ? **(char ***)(self + 0x278) : 0;
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(void **)(self + 0x600), m + 0x80, a, 1.5f);
        *(unsigned *)*(char **)(self + 0x600) |= 1;
    }
    *(short *)(self + 0x548) = 1000;
    *(short *)(self + 0x54A) = 1000;
    CreateUnit__21cCollisionSolidManageP8cGameObjQ225cCollisionSolidManageUnit9ePRIORITYf(g_CollSolidManage, self, 1, 0.3f);
    CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf(g_CollSolidManage, self, self + 0x80, Vq(0.0f, 1.5f, 0.0f, 1.0f), 1.5f);
    *(short *)(self + 0x622) = 0;
    *(unsigned char *)(self + 0x624) = 0;
    *(unsigned *)(self + 0x5B8) |= 8;
    return 1;
}
