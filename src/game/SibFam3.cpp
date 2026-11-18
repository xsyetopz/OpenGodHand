// Sibling families of 0x14E598, 0x1352F8, 0x100508 and 0x1004C8.

class cModel {
public:
    int isClip() const;
};
extern int D_00747A80;

extern "C" {
extern char D_00422B48[];
extern char D_00423C70[];
extern char D_00425000[];
extern char D_004251C0[];
extern char D_00425AC0[];
extern char D_00425E10[];
extern char D_00425EE0[];
extern char D_00428228[];
extern char D_00429C80[];
extern char D_00447AD0[];
extern char D_00447F70[];
extern char D_00448028[];
extern char D_00448890[];
extern char D_00448948[];
extern char D_0044AE28[];
extern char D_0044CEE8[];
extern char D_00450CE8[];
extern char D_00580D40[];
extern char D_005E75B0[];
extern char D_005FEC58[];
extern char D_00603A40[];
extern char Debug[];
extern char GlobalTask[];
extern char World_light_work[];
extern char g_CasinoWork[];
extern char g_CollisionManager[];
extern void *_$_4cObj(char *);
extern void *_$_8cObjBase(char *);
void _$_8cGameObj(char *);
extern void *__7cCamera(char *);
extern void *func_001B6E90(char *);
extern void *func_001BD580(char *);
extern void *func_001BFAC8(char *);
extern void *func_001F6CE0(char *);
extern void *func_001FF800(char *);
extern void *func_002B8AE0(char *);
extern void *func_002C8E60(char *);
extern void *func_002D2DC8(char *);
extern void *func_002D50C0(char *);
extern void *func_002D6D80(char *);
extern void *func_002D9E18(char *);
extern void *func_00372C80(char *);

// FUNCTION: GAME 0x183348
void *func_00183348(char *p)
{
    func_001BFAC8(p);
    *(const void **)(p + 0x214) = D_00422B48;
    return p;
}

// FUNCTION: GAME 0x18EC98
void *func_0018EC98(char *p)
{
    func_001BFAC8(p);
    *(const void **)(p + 0x214) = D_00423C70;
    return p;
}

// FUNCTION: GAME 0x198CA8
void *func_00198CA8(char *p)
{
    func_001BFAC8(p);
    *(const void **)(p + 0x214) = D_00425000;
    return p;
}

// FUNCTION: GAME 0x199DC0
void *func_00199DC0(char *p)
{
    func_001BFAC8(p);
    *(const void **)(p + 0x214) = D_004251C0;
    return p;
}

// FUNCTION: GAME 0x19C118
void *func_0019C118(char *p)
{
    func_001BFAC8(p);
    *(const void **)(p + 0x214) = D_00425AC0;
    return p;
}

// FUNCTION: GAME 0x19D5A8
void *func_0019D5A8(char *p)
{
    func_001BFAC8(p);
    *(const void **)(p + 0x214) = D_00425E10;
    return p;
}

// FUNCTION: GAME 0x19D7B0
void *func_0019D7B0(char *p)
{
    func_001BFAC8(p);
    *(const void **)(p + 0x214) = D_00425EE0;
    return p;
}

// FUNCTION: GAME 0x1B0B70
void *func_001B0B70(char *p)
{
    func_001BD580(p);
    *(const void **)(p + 0x214) = D_00428228;
    return p;
}

// FUNCTION: GAME 0x1C27E8
void *func_001C27E8(char *p)
{
    func_001B6E90(p);
    *(const void **)(p + 0x214) = D_00429C80;
    return p;
}

// FUNCTION: GAME 0x1F6E18
void func_001F6E18(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_001F6CE0(g_CasinoWork);
}

// FUNCTION: GAME 0x1FFDB0
void func_001FFDB0(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_001FF800(D_00580D40);
}

// FUNCTION: GAME 0x2B4850
void func_002B4850(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        __7cCamera(D_005E75B0);
}

// FUNCTION: GAME 0x2BA428
void func_002BA428(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_002B8AE0(g_CollisionManager);
}

// FUNCTION: GAME 0x2C9C38
void func_002C9C38(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_002C8E60(D_005FEC58);
}

// FUNCTION: GAME 0x2D31B0
void func_002D31B0(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_002D2DC8(D_00603A40);
}

// FUNCTION: GAME 0x2D9B70
void func_002D9B70(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_002D6D80(World_light_work);
}

// FUNCTION: GAME 0x2D9E98
void func_002D9E98(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_002D9E18(Debug);
}

// FUNCTION: GAME 0x30E568
void func_0030E568(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_002D50C0(GlobalTask);
}

// FUNCTION: GAME 0x276980
void func_00276980(char *self)
{
    *(const void **)(self + 0x214) = D_00447AD0;
    _$_8cGameObj(self);
}

// FUNCTION: GAME 0x27A2F8
void func_0027A2F8(char *self)
{
    *(const void **)(self + 0x214) = D_00447F70;
    _$_8cGameObj(self);
}

// FUNCTION: GAME 0x27ADE8
void func_0027ADE8(char *self)
{
    *(const void **)(self + 0x214) = D_00448028;
    _$_8cGameObj(self);
}

// FUNCTION: GAME 0x283660
void func_00283660(char *self)
{
    *(const void **)(self + 0x214) = D_00448890;
    _$_8cGameObj(self);
}

// FUNCTION: GAME 0x284040
void func_00284040(char *self)
{
    *(const void **)(self + 0x214) = D_00448948;
    _$_8cGameObj(self);
}

// FUNCTION: GAME 0x2A73C8
void _$_8cGameObj(char *self)
{
    *(const void **)(self + 0x214) = D_0044AE28;
    _$_8cObjBase(self);
}

// FUNCTION: GAME 0x2CC540
void func_002CC540(char *self)
{
    *(const void **)(self + 0x80) = D_0044CEE8;
    func_00372C80(self);
}

// FUNCTION: GAME 0x31A018
void func_0031A018(char *self)
{
    *(const void **)(self + 0x214) = D_00450CE8;
    _$_4cObj(self);
}

// FUNCTION: GAME 0x276940
int func_00276940(cModel *self)
{
    if (D_00747A80 & 0x40000000)
        return 1;
    return self->isClip() != 0;
}

// FUNCTION: GAME 0x27A2B8
int func_0027A2B8(cModel *self)
{
    if (D_00747A80 & 0x40000000)
        return 1;
    return self->isClip() != 0;
}

// FUNCTION: GAME 0x27ADA8
int func_0027ADA8(cModel *self)
{
    if (D_00747A80 & 0x40000000)
        return 1;
    return self->isClip() != 0;
}

// FUNCTION: GAME 0x283620
int func_00283620(cModel *self)
{
    if (D_00747A80 & 0x40000000)
        return 1;
    return self->isClip() != 0;
}

// FUNCTION: GAME 0x284000
int func_00284000(cModel *self)
{
    if (D_00747A80 & 0x40000000)
        return 1;
    return self->isClip() != 0;
}
}
