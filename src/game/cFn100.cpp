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

extern void *R16_SetEffect(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
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

extern const char D_0041D930[];
extern const char D_0041B598[];
extern const char D_0041B590[];
extern "C" void *__7cCamera(void *);
extern "C" void *__8cGameObj(void *);
extern "C" void func_00138558(void *);
extern "C" void update__7cCamera(void *);
extern "C" void move__7cIDBase(void *);
extern char *pCamWork;

// FUNCTION: GAME 0x1398D0
extern "C" void *func_001398D0(char *self)
{
    __7cCamera(self);
    *(const void **)(self + 0x35C) = D_0041D930;
    *(int *)(self + 0x364) = 0;
    *(int *)(self + 0x368) = 0;
    return self;
}

// FUNCTION: GAME 0x13F2F8
extern "C" void func_0013F2F8(char *self)
{
    *(int *)(self + 0xA0) = 0;
    unsigned short i = 0;
    char *p = self + 0x250;
    do {
        *(int *)((int)p + (i << 2)) = 0;
        i++;
    } while (i < 5);
    self[0x358] = 0;
}

// FUNCTION: GAME 0x13F1C0
extern "C" void func_0013F1C0(char *self)
{
    if (*(int *)(self + 0x9C) != 0xFFFF) {
        *(unsigned short *)(*(char **)(self + 0x90) + 0x90) = *(unsigned short *)(self + 0x9C);
        *(unsigned short *)(*(char **)(self + 0x94) + 0x90) = *(unsigned short *)(self + 0x9C);
    }
    move__7cIDBase(self);
}

// FUNCTION: GAME 0x100280
extern "C" void *__7cPlBase(char *self)
{
    __8cGameObj(self);
    *(const void **)(self + 0x214) = D_0041B598;
    *(const void **)(self + 0x4AC) = D_0041B590;
    return self;
}

// FUNCTION: GAME 0x138600
extern "C" void move__7cCamera(char *self)
{
    char *vt = *(char **)(self + 0x35C);
    ((void (*)(char *))*(void **)(vt + 0x14))(self + *(short *)(vt + 0x10));
    func_00138558(self);
    update__7cCamera(self);
}

// FUNCTION: GAME 0x138F40
extern "C" void func_00138F40(char *self)
{
    int a = *(int *)(self + 0x1028);
    if (a != 0x10) {
        char *v = *(char **)(self + 0xFF0);
        char *old = pCamWork;
        if (v == 0) {
            *(int *)(self + 0x1028) = 1;
            pCamWork = self;
        } else {
            *(int *)(self + 0x1028) = *(int *)(self + 0x102C);
            pCamWork = v;
        }
        *(int *)(self + 0x102C) = a;
        *(char **)(self + 0xFF0) = old;
    }
}

extern "C" void func_001344A0(void *);
extern "C" void func_0030F5A0(void *);

// FUNCTION: GAME 0x134458
extern "C" void func_00134458(void *self, int flag)
{
    func_001344A0(self);
    if (flag & 1)
        func_0030F5A0(self);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x12C4F0
// diff: original keeps ld result in v0 and ends with li 1 + movn; compiled uses a1 and bne/branches (8-9 words).
extern "C" int func_0012C4F0(char *self)
{
    unsigned long m = *(unsigned long *)(self + 0x2F0) & 0xFFFF00000000UL;
    return m == (0xC020UL << 27) || m == (0xA020UL << 27);
}
#endif

extern "C" void *func_0012B328(void *);
extern "C" void SetParent__8cOmThrowP8cGameObj(void *, void *);
extern "C" void *Getplayer__Fv(void);
extern "C" void func_00139FF8(void *);
extern "C" void func_0013AD90(void *);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(void *, void *);
extern "C" void _$_7cPlBase(char *, int);
extern const char D_0041D220[];
extern char g_CollSolidManage[];

// FUNCTION: GAME 0x137A48
extern "C" void *func_00137A48(char *self)
{
    *(int *)self = 0;
    *(int *)(self + 0x30) = 0;
    memset(self + 4, 0, 0x2C);
    *(float *)(self + 0x1C) = 1.06f;
    return self;
}

// FUNCTION: GAME 0x13DA98
extern "C" void func_0013DA98(char *self)
{
    if (*(unsigned *)(*(char **)(self + 0x94) + 0x2C) & 0x400) {
        move__7cIDBase(self);
        *(unsigned short *)(self + 0x92) = *(unsigned short *)(self + 0x92) + 1;
    }
}

// FUNCTION: GAME 0x107EC8
extern "C" void func_00107EC8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_0041D220;
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
    _$_7cPlBase(self, flag);
}

// FUNCTION: GAME 0x12B5C0
extern "C" void func_0012B5C0(char *self)
{
    int t = *(int *)(self + 0x6A4);
    if (t)
        *(int *)(self + 0x6A0) = t;
    if (*(int *)(self + 0x6A0) == 0) {
        void *v = func_0012B328(self);
        *(void **)(self + 0x6A0) = v;
        if (v == 0)
            return;
    }
    SetParent__8cOmThrowP8cGameObj(*(void **)(self + 0x6A0), self);
}

// FUNCTION: GAME 0x139FA8
extern "C" void func_00139FA8(void *self)
{
    char *p = (char *)Getplayer__Fv();
    if (*(int *)(p + 0x5D8) != 4)
        func_00139FF8(self);
    else
        func_0013AD90(self);
}

extern "C" void _$_8cGameObj(void *, int);
extern "C" void func_00137F38(void *, void *);
extern "C" void release__7cIDBase(void *);

// FUNCTION: GAME 0x1002C0
extern "C" void _$_7cPlBase(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_0041B598;
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
    _$_8cGameObj(self, flag);
}

// FUNCTION: GAME 0x13C5C8
extern "C" void func_0013C5C8(char *self)
{
    *(int *)(self + 0x50) = 0;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x5C) = 0;
    *(int *)(self + 0x60) = 0;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x6C) = 0;
    *(short *)(self + 0x70) = 0;
    *(short *)(self + 0x72) = 0;
    self[0x74] = 0;
    self[0x75] = 0;
    self[0x76] = 0;
    self[0x77] = 0;
    self[0x78] = 0;
    self[0x79] = 0;
    self[0x7A] = 0;
    self[0x7B] = 0;
    self[0x7C] = 0;
}

// FUNCTION: GAME 0x138FC8
extern "C" void func_00138FC8(char *self)
{
    func_00137F38(self + 0xFF4, self);
    if ((*(unsigned *)(self + 0x1028) & 4) == 0)
        move__7cCamera(pCamWork);
}

// FUNCTION: GAME 0x13E908
extern "C" void func_0013E908(char *self)
{
    if (*(int *)(self + 0x94)) {
        release__7cIDBase(self);
        *(int *)(self + 0x94) = 0;
        *(float *)(self + 0xA4) = 1.0f;
        *(int *)(self + 0x9C) = 0;
        *(int *)(self + 0xA0) = 0;
    }
    *(float *)(self + 0xA4) = 1.0f;
    *(int *)(self + 0x94) = 0;
    *(int *)(self + 0x9C) = 0;
    *(int *)(self + 0xA0) = 0;
}

// FUNCTION: GAME 0x12ECF0
extern "C" void func_0012ECF0(void *vself)
{
    char *self = (char *)vself;
    if (*(int *)(self + 0x190)) {
        char *nx;
        do {
            char *a = *(char **)(self + 0x190);
            nx = *(char **)a;
            if (a) {
                char *vt = *(char **)(a + 0x5C);
                ((void (*)(char *, int))*(void **)(vt + 0xC))(a + *(short *)(vt + 8), 3);
            }
            *(char **)(self + 0x190) = nx;
            *(int *)(self + 0x194) = *(int *)(self + 0x194) - 1;
        } while (nx);
    }
}

extern "C" void restartAnim__7cIDBase(void *);
extern "C" int getIDWork__7cIDBasei(void *, int);
extern unsigned int D_00747A84;

// FUNCTION: GAME 0x13F150
extern "C" void func_0013F150(char *self)
{
    unsigned short i = 0;
    char *p = self + 0x90;
    restartAnim__7cIDBase(self);
    self[0x1C] = 1;
    do {
        *(int *)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 3);
}

// FUNCTION: GAME 0x13E380
extern "C" void func_0013E380(char *self)
{
    unsigned short i;
    char *p = self + 0x9C;
    initialize__7cIDBase7eIdData5eIdNo(self, 1, 0x1F);
    i = 0;
    do {
        *(int *)((int)p + (i << 2)) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 2);
    *(int *)(self + 0x90) = 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x13F558
// diff: original keeps one v0 = self+n*4 and copies it to a0/a1; compiled uses distinct regs (~12 words).
extern "C" void func_0013F558(char *self, char *o)
{
    if ((D_00747A84 & 0x20000000) == 0) {
        if ((*(unsigned *)(o + 0x2F0) & 0x1000) == 0) {
            unsigned char n = self[0x358];
            if (n < 5) {
                char *v = self + n * 4;
                *(char **)(v + 0x250) = o;
                char *w = v;
                *(char **)(w + 0x35C) = self + (n * 0x50 + 0xC0);
                *(int *)(v + 0xA8) = 0;
                self[0x358] = self[0x358] + 1;
            }
        }
    }
}
#endif
