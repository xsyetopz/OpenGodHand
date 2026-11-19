typedef int TI128 __attribute__((mode(TI)));
extern "C" void Light_curent_set2__11cWorldLightUi(char *self, unsigned id);
extern unsigned D_00747A84;
extern "C" void func_001C6A60(char *self, unsigned a1, char *vec, unsigned flags);
extern "C" void func_001331B8(char *coll, long id, bool enable);
extern char g_CollScr;
extern char g_DmgManage[];
extern "C" void *CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(char *, int, char *);
extern "C" void *AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(char *, char *, float *, float);
extern "C" void SetDamageCollActive__11cDamageUnitb(char *, int);
extern "C" void func_001F9B88(void *);
extern "C" void func_0031C350(int, int);
extern void *CoreSave;
extern char D_005E9CB8[];

#ifdef NONMATCHING
// DRAFT: GAME 0x2D90B0 (draft: 128-bit copies via TI128)
extern "C" int Set_LightData__11cWorldLightP14LIGHT_DATA_TBL(char *self, char *src)
{
    if (*(unsigned short *)(src + 2) == 0) {
        return 0;
    }
    int n = *(int *)(self + 0x78);
    if (n >= 0x100) {
        return 0;
    }
    char *d = self + n * 0x70 + 0x80;
    char *s = src;
    char *end = src + 0x60;
    do {
        *(TI128 *)d = *(TI128 *)s;
        *(TI128 *)(d + 0x10) = *(TI128 *)(s + 0x10);
        s += 0x20;
        d += 0x20;
    } while (s != end);
    *(TI128 *)d = *(TI128 *)s;
    *(int *)(self + 0x78) += 1;
    if (!(D_00747A84 & 0x08000000)) {
        Light_curent_set2__11cWorldLightUi(self, *(unsigned *)(self + 0x16288));
    }
    return 1;
}

// DRAFT: GAME 0x1C6988 (draft: straight-line field stores, tail call on all paths)
extern "C" void initMove1_ang__6cOmSubP4cObjiUiRC4cVecffUi(char *self, char *obj, int idx, unsigned a3, char *vec, float f0, float f1, unsigned flags)
{
    flags |= 2;
    if (obj != 0) {
        char *t2 = obj;
        if (idx >= 0) {
            int cnt = *(unsigned char *)(obj + 0x2B4);
            t2 = (idx < cnt) ? ((char **)*(char **)(obj + 0x278))[idx] : 0;
        }
        if (t2 != 0) {
            *(char **)(self + 0x4) = obj;
            *(char **)(self + 0x8) = t2;
            *(char **)(self + 0x40) = (idx < 0) ? *(char **)(t2 + 0xF0) : *(char **)(t2 + 0xD0);
            char *p = *(char **)(self + 0x40);
            if (p != self + 0x70) {
                *(float *)(self + 0x70) = *(float *)p;
                *(float *)(self + 0x74) = *(float *)(p + 4);
                *(float *)(self + 0x78) = *(float *)(p + 8);
            }
            char *q = t2 + 0x100;
            if (self + 0x80 != q) {
                *(float *)(self + 0x80) = *(float *)q;
                *(float *)(self + 0x84) = *(float *)(q + 4);
                *(float *)(self + 0x88) = *(float *)(q + 8);
            }
        }
    }
    func_001C6A60(self, a3, vec, flags);
}

// DRAFT: GAME 0x1C8AB0 (draft: m2c structure; vtable call, sphere temp, float copies)
extern "C" void SetParent__8cOmThrowP8cGameObj(char *self, char *parent)
{
    char *v = *(char **)(self + 0x214);
    ((void (*)(char *))(*(void **)(v + 0xAC)))(self + *(short *)(v + 0xA8));
    func_001331B8(&g_CollScr, *(long *)(self + 0x540), 0);
    *(char **)(self + 0x600) = (char *)CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(g_DmgManage, 0, self);
    unsigned cnt = *(unsigned char *)(self + 0x2B4);
    char *a1 = cnt ? ((char **)*(char **)(self + 0x278))[0] : 0;
    float vq[4];
    vq[0] = 0.0f;
    vq[1] = 0.0f;
    vq[2] = 0.0f;
    vq[3] = 1.0f;
    *(char **)(self + 0x604) = (char *)AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(char **)(self + 0x600), a1 + 0x80, vq, 0.5f);
    SetDamageCollActive__11cDamageUnitb(*(char **)(self + 0x600), 0);
    *(char **)(self + 0x644) = parent;
    *(unsigned char *)(self + 0x2F4) = 0;
    *(unsigned char *)(self + 0x2F5) = 0;
    *(unsigned char *)(self + 0x2F6) = 0;
    *(unsigned char *)(self + 0x2F7) = 0;
    cnt = *(unsigned char *)(self + 0x2B4);
    char *v2 = cnt ? ((char **)*(char **)(self + 0x278))[0] : 0;
    if (v2 != 0) {
        char *t = *(char **)(v2 + 0xD0);
        char *d = self + 0x630;
        if (d != t) {
            *(float *)(self + 0x630) = *(float *)t;
            *(float *)(d + 4) = *(float *)(t + 4);
            *(float *)(d + 8) = *(float *)(t + 8);
        }
        *(unsigned char *)(self + 0x640) = 0;
        *(int *)(self + 0x624) = 0;
    }
}

// DRAFT: GAME 0x2C05B0 (draft: 32-byte loops; unaligned ldl/ldr/sdl/sdr tail approximated by byte copy)
extern "C" void *setCheckPoint__12cSaveManagerbPC4cVecT2(char *self, int a1, int a2, char *src)
{
    func_001F9B88(&CoreSave);
    func_0031C350(a2, (int)src);
    char *v0 = (char *)CoreSave;
    char *v1 = self;
    char *end = v0 + 0x14A0;
    do {
        *(TI128 *)v1 = *(TI128 *)v0;
        *(TI128 *)(v1 + 0x10) = *(TI128 *)(v0 + 0x10);
        v0 += 0x20;
        v1 += 0x20;
    } while (v0 != end);
    char *w = self + 0x14A0;
    char *a = D_005E9CB8;
    char *stop = D_005E9CB8 + 0x9C20;
    do {
        *(unsigned long *)w = *(unsigned long *)a;
        *(unsigned long *)(w + 8) = *(unsigned long *)(a + 8);
        *(unsigned long *)(w + 0x10) = *(unsigned long *)(a + 0x10);
        *(unsigned long *)(w + 0x18) = *(unsigned long *)(a + 0x18);
        a += 0x20;
        w += 0x20;
    } while (a != stop);
    *(unsigned long *)w = *(unsigned long *)a;
    *(unsigned long *)(w + 8) = *(unsigned long *)(a + 8);
    for (int i = 0; i < 0x20; ++i) {
        w[0x10 + i] = src[i];
    }
    return self + 0x8000;
}
#endif
