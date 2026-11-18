struct V3 {
    float x, y, z;
};
extern char g_CollSolidManage[];
extern char g_DmgManage[];
struct V16 {
    float x, y, z, w;
};
extern "C" void CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf(void *, void *, void *, V16 *, float);
extern "C" int ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
extern char D_004282F0[];
extern char Snd[];
extern "C" float Turn_dest_dir__Ffff(float, float, float);
extern "C" float Adjust_theta__Ff(float);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, void *, void *, unsigned, int);
extern "C" int func_001B6FB8(void *);
extern "C" void func_001B6F38(void *, int);
extern "C" void CreateUnit__21cCollisionSolidManageP8cGameObjQ225cCollisionSolidManageUnit9ePRIORITYf(void *, void *, int, float);
extern "C" void SeStop__4cSnd6eSndId(void *, int);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);

// FUNCTION: GAME 0x001B1BD0
extern "C" int func_001B1BD0(char *self)
{
    func_001B6FB8(self);
    *(unsigned *)(self + 0x5B8) |= 8;
    CreateUnit__21cCollisionSolidManageP8cGameObjQ225cCollisionSolidManageUnit9ePRIORITYf(g_CollSolidManage, self, 6, 0.1f);
    V16 v;
    v.x = 0.0f;
    v.y = 0.5f;
    v.z = 0.0f;
    v.w = 1.0f;
    CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf(g_CollSolidManage, self, self + 0x80, &v, 0.4f);
    self[0x2F4] = 0;
    return 1;
}

// FUNCTION: GAME 0x001B0D30
extern "C" void func_001B0D30(char *self, int n)
{
    *(char **)(self + 0x214) = D_004282F0;
    if (*(int *)(self + 0x668)) {
        SeStop__4cSnd6eSndId(Snd, *(int *)(self + 0x668));
        *(int *)(self + 0x668) = 0;
    }
    if (ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, *(void **)(self + 0x66C))) {
        *(int *)(self + 0x66C) = 0;
        *(int *)(self + 0x674) = -1;
    }
    if (ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, *(void **)(self + 0x670))) {
        *(int *)(self + 0x670) = 0;
        *(int *)(self + 0x678) = -1;
    }
    KillEffect__FPC4cObji13eEspEraseMode(self, 7, 2);
    func_001B6F38(self, n);
}

// FUNCTION: GAME 0x001BC538
extern "C" void func_001BC538(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        if (*(unsigned short *)(self + 0x2FE) != 0x314 && *(unsigned short *)(self + 0x2FE) != 0x354)
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 3, self, 0, 0, 0, 0);
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned char *)(self + 0x2F6) = 1;
    case 1: {
        float t = Turn_dest_dir__Ffff(*(float *)(self + 0x104), *(float *)(self + 0x640), 0.13962634f);
        float f = *(float *)(self + 0x104) + t;
        *(float *)(self + 0x104) = f;
        float r = Adjust_theta__Ff(f);
        *(float *)(self + 0x104) = r;
        if (r == *(float *)(self + 0x640)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
    }
}

// FUNCTION: GAME 0x001BC610
extern "C" void func_001BC610(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        if (*(unsigned short *)(self + 0x2FE) != 0x314 && *(unsigned short *)(self + 0x2FE) != 0x354)
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 3, self, 0, 0, 0, 0);
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned char *)(self + 0x2F6) = 1;
    case 1: {
        float t = Turn_dest_dir__Ffff(*(float *)(self + 0x104), *(float *)(self + 0x638), 0.13962634f);
        float f = *(float *)(self + 0x104) + t;
        *(float *)(self + 0x104) = f;
        float r = Adjust_theta__Ff(f);
        *(float *)(self + 0x104) = r;
        if (r == *(float *)(self + 0x638)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
    }
}

extern "C" float capVu0Atan2__Fff(float, float);
extern "C" int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);
extern char D_004296F0[];
extern char D_00429620[];
extern "C" void *func_001B6E90(void *);

// FUNCTION: GAME 0x001B1760
extern "C" void setThrow__5cOm60RC4cVecf(char *self, V3 *v, float f)
{
    *(int *)(self + 0x600) = 0;
    V3 *p = (V3 *)(self + 0x640);
    if (p != v) {
        p->x = v->x;
        p->y = v->y;
        p->z = v->z;
    }
    if (0.0f < f)
        *(float *)(self + 0x630) = f;
    *(float *)(self + 0x104) = capVu0Atan2__Fff(v->x, v->z);
    *(float *)(self + 0x650) = 0.5235988f;
    *(float *)(self + 0x24C) = 1.0f;
    *(unsigned *)(self + 0x250) &= ~0x10;
    *(unsigned char *)(self + 0x666) = 0;
    if (*(unsigned char *)(self + 0x667) == 0) {
        *(unsigned char *)(self + 0x667) = 1;
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x58, 5, self, 0, 7, 0xFFFFFFFF);
        *(int *)(self + 0x668) = SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 0x117, self, 0, 0, 0, 0);
    }
}

// FUNCTION: GAME 0x001BF478
extern "C" char *func_001BF478(char *self)
{
    func_001B6E90(self);
    *(signed char *)(self + 0x600) = -1;
    *(char **)(self + 0x214) = D_004296F0;
    return self;
}

// FUNCTION: GAME 0x001BE8B0
extern "C" char *func_001BE8B0(char *self)
{
    func_001B6E90(self);
    *(int *)(self + 0x604) = 0x3E9;
    *(char **)(self + 0x214) = D_00429620;
    *(int *)(self + 0x600) = 0;
    return self;
}
