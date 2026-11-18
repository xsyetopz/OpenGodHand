// Small free functions of 0x100000-0x13FFFF.
extern "C" void func_00107DE0(int a, int b);
extern "C" void _$_15cCollisionSolid(void *self);
extern const char D_0041D7E0[];
extern const char D_0041D7B8[];
extern "C" void trans__7cIDBase(void *);

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

// FUNCTION: GAME 0x107E20
extern "C" void func_00107E20()
{
    func_00107DE0(1, 0xFFFF);
}

// FUNCTION: GAME 0x133A80
extern "C" void func_00133A80(char *self)
{
    *(const void **)(self + 0x30) = D_0041D7E0;
    _$_15cCollisionSolid(self);
}

// FUNCTION: GAME 0x133B58
extern "C" void func_00133B58(char *self)
{
    *(const void **)(self + 0x30) = D_0041D7B8;
    _$_15cCollisionSolid(self);
}

// FUNCTION: GAME 0x134430
extern "C" char *func_00134430(char *self, int a, int b, float c)
{
    ZQ(self, 0x20);
    ZQ(self, 0x30);
    *(int *)self = a;
    *(int *)(self + 8) = b;
    *(float *)(self + 0xC) = c;
    *(int *)(self + 4) = 0;
    *(int *)(self + 0x10) = 0;
    return self;
}

// FUNCTION: GAME 0x12CDF0
extern "C" void func_0012CDF0(char *self, float *v)
{
    float *d = (float *)(self + 0x650);
    if (d != v) {
        d[0] = v[0];
        d[1] = v[1];
        d[2] = v[2];
    }
}

// FUNCTION: GAME 0x13C168
extern "C" void func_0013C168(char *self)
{
    unsigned char t = self[0x94] ^ 1;
    if ((t & 1) == 0)
        trans__7cIDBase(self);
}

extern const char D_0041D790[];
extern "C" void func_0012ECF0(void *);
extern "C" void *initialize__7cIDBase7eIdData5eIdNo(void *, int, int);

// FUNCTION: GAME 0x133BA0
extern "C" void func_00133BA0(char *self)
{
    *(const void **)(self + 0x30) = D_0041D790;
    _$_15cCollisionSolid(self);
}

// FUNCTION: GAME 0x12E800
extern "C" void func_0012E800(int *self)
{
    self[0] = 0; self[1] = 0; self[2] = 0; self[3] = 0; self[4] = 0;
    self[5] = 0; self[6] = 0; self[7] = 0; self[8] = 0;
    func_0012ECF0(self);
}

// FUNCTION: GAME 0x13ECF0
extern "C" void *func_0013ECF0(char *self)
{
    void *r = initialize__7cIDBase7eIdData5eIdNo(self, 1, 2);
    *(short *)(self + 0xBE) = -1;
    return r;
}

extern void *R16_SetEffect(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAM");
extern "C" void *SetDamage__9cOmWeaponi(void *);
extern "C" void SetBreak__9cOmWeapon(void *);
extern "C" void SetActionJumpUp__Fv(void);
extern "C" void SetActionJumpDown__Fv(void);
extern "C" void *memset(void *, int, unsigned);
extern "C" void Circle_line2__FPCffUibi(void *, float, int, unsigned, int);

// FUNCTION: GAME 0x12C708
extern "C" void func_0012C708(char *self)
{
    *(int *)(self + 0x5FC) = 600;
    R16_SetEffect(0, 0x4E, self, 0, 5, 0xFFFFFFFF);
}

// FUNCTION: GAME 0x13D3C0
extern "C" void func_0013D3C0(char *self)
{
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 3);
    initialize__7cIDBase7eIdData5eIdNo(self + 0xD0, 1, 0x20);
    *(short *)(self + 0x92) = 0;
}

// FUNCTION: GAME 0x12B2E0
extern "C" void func_0012B2E0(char *self)
{
    void *w = *(void **)(self + 0x698);
    if (w) {
        if (SetDamage__9cOmWeaponi(w)) {
            SetBreak__9cOmWeapon(*(void **)(self + 0x698));
            *(void **)(self + 0x698) = 0;
        }
    }
}

// FUNCTION: GAME 0x12BFB8
extern "C" void func_0012BFB8(char *self)
{
    if (*(int *)(self + 0x6A0) == 0) {
        SetActionJumpUp__Fv();
        SetActionJumpDown__Fv();
        *(unsigned *)(self + 0x15F4) |= 0x100;
    }
}

// FUNCTION: GAME 0x137AA0
extern "C" void func_00137AA0(char *self)
{
    *(int *)self = 0;
    *(int *)(self + 0x30) = 0;
    memset(self + 4, 0, 0x2C);
    *(float *)(self + 0x1C) = 1.06f;
}

// FUNCTION: GAME 0x133B28
extern "C" void func_00133B28(char *self)
{
    int u;
    Circle_line2__FPCffUibi(self + 0x60, *(float *)(self + 0x70), u, 1, 1);
}

extern "C" void *func_001346C8(void *, void *);
extern "C" void func_00134608(void *, int);
extern "C" void func_00134648(void *, int);

// FUNCTION: GAME 0x1351D8
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *self, void *obj, int on)
{
    void *u = func_001346C8(self, obj);
    if (u)
        func_00134608(u, on);
}

// FUNCTION: GAME 0x135210
extern "C" void SetPriority__21cCollisionSolidManageP8cGameObjQ225cCollisionSolidManageUnit9ePRIORITY(void *self, void *obj, int p)
{
    void *u = func_001346C8(self, obj);
    if (u)
        func_00134648(u, p);
}
