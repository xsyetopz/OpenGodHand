struct V3 {
    float x, y, z;
};
extern "C" void func_001A4BD0(void *);
extern "C" void setCloseFix__5cOm5a(void *);
extern "C" void setOpenFix__5cOm5a(void *);
extern "C" float fRand1_1__Fv(void);

// FUNCTION: GAME 0x001AAD88
extern "C" void setParent__5cOm59P8cGameObjiRC4cVecT3(char *self, void *obj, int n, V3 *a, V3 *b)
{
    *(void **)(self + 0x9A0) = obj;
    *(int *)(self + 0x9A4) = n;
    V3 *p = (V3 *)(self + 0x9B0);
    if (p != a) {
        p->x = a->x;
        p->y = a->y;
        p->z = a->z;
    }
    V3 *q = (V3 *)(self + 0x9C0);
    if (q != b) {
        q->x = b->x;
        q->y = b->y;
        q->z = b->z;
    }
}

// FUNCTION: GAME 0x001A4DA8
extern "C" void setClose__5cOm4f(unsigned char *self)
{
    if (self[0x762] != 1 && self[0x761] == 1) {
        self[0x760] = self[0x761];
        func_001A4BD0(self);
        self[0x2F4] = 2;
        self[0x2F5] = 0;
        self[0x2F6] = 0;
        self[0x2F7] = 0;
    }
}

// FUNCTION: GAME 0x001A4D48
extern "C" void setOpen__5cOm4f(unsigned char *self)
{
    if (self[0x762] != 1 && self[0x761] == 0) {
        self[0x760] = 1;
        func_001A4BD0(self);
        self[0x2F4] = 1;
        self[0x2F5] = 0;
        self[0x2F6] = 0;
        self[0x2F7] = 0;
    }
}

// FUNCTION: GAME 0x001ADA88
extern "C" void setOpenType__5cOm5aQ25cOm5a9eOpenType(char *self, int t)
{
    if (*(int *)(self + 0x600) != t) {
        if (*(unsigned char *)(self + 0x60D) == 1) {
            setCloseFix__5cOm5a(self);
            *(int *)(self + 0x600) = t;
            setOpenFix__5cOm5a(self);
        } else {
            *(int *)(self + 0x600) = t;
        }
    }
}

// FUNCTION: GAME 0x001AC908
extern "C" void func_001AC908(char *self)
{
    if (*(short *)(self + 0x610) > 0) {
        *(unsigned short *)(self + 0x610) = *(unsigned short *)(self + 0x610) - 1;
        if (*(short *)(self + 0x610) != 0) {
            float r = fRand1_1__Fv();
            *(float *)(*(char **)(self + 0xF0) + 4) = *(float *)(self + 0x614) + r * 0.015f;
        } else {
            *(float *)(*(char **)(self + 0xF0) + 4) = *(float *)(self + 0x614);
        }
    }
}

extern "C" void setCloseFix__8cOmDoor2(void *);
extern "C" void setOpenFix__8cOmDoor2(void *);
extern char g_CollSolidManage[];
extern char g_EmManage[];
extern char g_CollScr[];
extern char g_DmgManage[];
extern "C" float GetSpeedRate__9cEmManage(void *);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" void func_0012EC58(void *, void *);
extern "C" void func_001FE278(void *, void *);
extern "C" void ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
struct V16 {
    float x, y, z, w;
};
extern "C" void CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf(void *, void *, void *, V16 *, float);
extern "C" void initMove3_y__6cOmSubP4cObjiRC4cVecfff(void *, void *, int, V3 *, float, float, float);

// FUNCTION: GAME 0x001BDDA0
extern "C" void setOpenType__8cOmDoor2Q28cOmDoor29eOpenType(char *self, int t)
{
    if (*(int *)(self + 0x778) != t) {
        if (*(unsigned char *)(self + 0x774) == 1) {
            setCloseFix__8cOmDoor2(self);
            *(int *)(self + 0x778) = t;
            setOpenFix__8cOmDoor2(self);
        } else {
            *(int *)(self + 0x778) = t;
        }
    }
}

// FUNCTION: GAME 0x001B35D0
extern "C" void SetCollision__5cOmb0(char *self)
{
    V16 v;
    v.x = 0.0f;
    v.y = 1.75f;
    v.z = 0.0f;
    self[0x62C] = 1;
    v.w = 1.0f;
    CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf(g_CollSolidManage, self, self + 0x80, &v, 1.75f);
}

// FUNCTION: GAME 0x001B3910
extern "C" void SetMove__5cOmb2G4cVecT1f(unsigned char *self, V3 *a, V3 *b, float f)
{
    V3 *p = (V3 *)(self + 0x100);
    if (p != a) {
        p->x = a->x;
        p->y = a->y;
        p->z = a->z;
    }
    initMove3_y__6cOmSubP4cObjiRC4cVecfff(self + 0x610, self, -1, b, f, -50.0f, 0.0f);
    self[0x2F4] = 1;
}

// FUNCTION: GAME 0x001B1A80
extern "C" int func_001B1A80(char *self)
{
    float r = GetSpeedRate__9cEmManage(g_EmManage);
    float f = *(float *)(self + 0x630);
    if (0.0f < f)
        *(float *)(self + 0x630) = f - r;
    return *(float *)(self + 0x630) <= 0.0f;
}

// FUNCTION: GAME 0x001B18B8
extern "C" void func_001B18B8(char *self)
{
    *(short *)(*(char **)(self + 0x66C) + 0x46) = 0x30;
    *(int *)(*(char **)(self + 0x66C) + 0x4C) = 0x32;
    SetDamageCollActive__11cDamageUnitb(*(char **)(self + 0x66C), 1);
    *(short *)(*(char **)(self + 0x670) + 0x46) = 0x48;
    *(int *)(*(char **)(self + 0x670) + 0x4C) = 0x32;
    SetDamageCollActive__11cDamageUnitb(*(char **)(self + 0x670), 1);
}

// FUNCTION: GAME 0x001B55A0
extern "C" void func_001B55A0(char *self)
{
    if (*(void **)(self + 0x64C)) {
        func_0012EC58(g_CollScr, *(void **)(self + 0x64C));
        *(void **)(self + 0x64C) = 0;
    }
    if (*(void **)(self + 0x650)) {
        func_001FE278(g_DmgManage, *(void **)(self + 0x650));
        *(void **)(self + 0x650) = 0;
    }
    if (*(void **)(self + 0x654)) {
        ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, *(void **)(self + 0x654));
        *(void **)(self + 0x654) = 0;
    }
    if (*(void **)(self + 0x658)) {
        ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, *(void **)(self + 0x658));
        *(void **)(self + 0x658) = 0;
    }
}
