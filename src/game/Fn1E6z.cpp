extern "C" void *memset(void *, int, unsigned);
extern "C" void func_001F2708(char *);
struct V4 { float x, y, z, w; };
extern char ZeroMat[];
extern char g_DmgManage[];
extern "C" char *CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(char *, int, void *);
extern "C" void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(char *, char *, V4 *, float);
extern "C" void SetDamageCollActive__11cDamageUnitb(char *, int);
extern char Snd[];
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int, int, void *, void *, float, int);
extern "C" void SeCall__4cSnd6eSeBlksPfUii(char *, int, int, void *, unsigned, int);
extern "C" void SetDamageCollOffset__11cDamageUnitRC4cVec(char *, void *);
extern "C" void SetDmgGiveHitVec__11cDamageGiveRC4cVec(char *, void *);
extern "C" void SetDamageCollFlashActive__11cDamageUnitbs(char *, int, int);
extern "C" void displayScrollLayer__FUib(unsigned, int);
#define L(o, f) displayScrollLayer__FUib(*(unsigned *)(self + o), f)
// FUNCTION: GAME 0x1EE9C8
extern "C" char *__14ColiseumBattle(char *self)
{
    memset(self, 0, 0x54);
    *(int *)(self + 0x54) = 0;
    func_001F2708(self + 0x60);
    *(int *)(self + 0xBAC) = 0;
    char *p = self + 0xBD0;
    for (int i = 8; i != -1; i--) {
        __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(p) : "memory");
        p += 16;
    }
    return self;
}

// FUNCTION: GAME 0x1EFFF8
extern "C" void func_001EFFF8(char *self)
{
    char **slot = (char **)(self + 0xBB0);
    for (unsigned i = 0; i < 6; i++, slot++) {
        char *d = CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(g_DmgManage, 3, 0);
        *slot = d;
        if (d) {
            V4 v;
            v.x = 0;
            v.y = 0;
            v.z = 0;
            v.w = 1.0f;
            AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(d, ZeroMat, &v, 1.0f);
            *(short *)(*slot + 0x46) = 0x55;
            *(int *)(*slot + 0x4C) = 100;
            SetDamageCollActive__11cDamageUnitb(*slot, 0);
            *(unsigned *)*slot |= 1;
        }
    }
}

// FUNCTION: GAME 0x1EFED0
extern "C" void func_001EFED0(char *self, char *pos, char *hit)
{
    unsigned i = *(unsigned *)(self + 0xBC8);
    if (i < 6) {
        char **tab0 = (char **)(self + 0xBB0);
        char **tab = tab0;
        if (*(char **)((char *)tab + (i << 2))) {
            SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0, 0x57, 0, pos, 1.0f, -1);
            float v[4] __attribute__((aligned(16)));
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tsqc2 $vf4,0(%1)" : : "r"(pos), "r"(v) : "memory");
            SeCall__4cSnd6eSeBlksPfUii(Snd, 2, 0xD2, v, 0, 0);
            SeCall__4cSnd6eSeBlksPfUii(Snd, 2, 0xD3, v, 0, 0);
            register unsigned k __asm__("$3") = *(unsigned *)(self + 0xBC8);
            SetDamageCollOffset__11cDamageUnitRC4cVec(*(char **)((char *)tab + (k << 2)), pos);
            SetDmgGiveHitVec__11cDamageGiveRC4cVec(*(char **)((char *)tab + (*(unsigned *)(self + 0xBC8) << 2)), hit);
            SetDamageCollFlashActive__11cDamageUnitbs(*(char **)((char *)tab + (*(unsigned *)(self + 0xBC8) << 2)), 1, 1);
        }
        *(unsigned *)(self + 0xBC8) += 1;
    }
}

// FUNCTION: GAME 0x1E6A48
extern "C" void func_001E6A48(char *self)
{
    switch (*(unsigned short *)(self + 0x3D2)) {
    case 0:
        L(0x3B4, 0); L(0x3B8, 0); L(0x3C0, 0); L(0x3BC, 0); L(0x3C4, 0);
        break;
    case 1:
        L(0x3B4, 1); L(0x3B8, 0); L(0x3C0, 0); L(0x3BC, 0); L(0x3C4, 0);
        break;
    case 2:
        L(0x3B4, 1); L(0x3B8, 1); L(0x3C0, 1); L(0x3BC, 0); L(0x3C4, 0);
        break;
    case 3:
        L(0x3B4, 1); L(0x3B8, 1); L(0x3C0, 1); L(0x3BC, 1); L(0x3C4, 1);
        break;
    }
}
