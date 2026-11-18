struct Vq {
    float x, y, z, w;
    Vq(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
extern char g_DmgManage[];
extern char ZeroMat[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(void *, int, char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
extern "C" void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, char *, const Vq &, float);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);

// FUNCTION: GAME 0x1B8868
extern "C" int func_001B8868(char *self)
{
    func_001B6FB8(self);
    if ((*(void **)(self + 0x620) = CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(g_DmgManage, 3, self))) {
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(void **)(self + 0x620), ZeroMat, Vq(0.0f, 0.0f, 0.0f, 1.0f), 2.5f);
        *(short *)(*(char **)(self + 0x620) + 0x46) = 0x52;
        *(int *)(*(char **)(self + 0x620) + 0x4C) = 20;
        SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x620), 0);
        *(unsigned *)*(char **)(self + 0x620) |= 1;
    }
    if ((*(void **)(self + 0x624) = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 1))) {
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(void **)(self + 0x624), self + 0x80, Vq(0.0f, 0.0f, 3.0f, 1.0f), 1.5f);
        SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x624), 0);
    }
    *(int *)(self + 0x5B8) &= -2;
    return 1;
}
