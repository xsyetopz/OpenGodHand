// State handlers: motion-switch stepper and member-pointer state dispatch.
struct cObjBase;
extern "C" void func_002A8578(cObjBase *, float, int, int, int, int, int);
int moveMotion(cObjBase *);
struct Mot { char _p[0x158]; int o158, o15C, o160, o164; };
struct cObjBase {
    char _p0[0x2F6];
    unsigned char b2F6;
    char _p1[0x304 - 0x2F7];
    Mot *mot;
};

// FUNCTION: GAME 0x280688
extern "C" void func_00280688(cObjBase *s)
{
    switch (s->b2F6) {
    case 0:
        func_002A8578(s, 0.0f, s->mot->o158 + (int)s->mot, s->mot->o15C + (int)s->mot, 2, 0, 0);
        s->b2F6++;
    case 1:
        moveMotion(s);
        break;
    case 2:
        func_002A8578(s, 0.0f, s->mot->o160 + (int)s->mot, s->mot->o164 + (int)s->mot, 2, 0, 0);
        s->b2F6++;
    case 3:
        moveMotion(s);
        break;
    }
}

struct cObj;
typedef void (cObj::*Fn)();
struct T { Fn f[2]; };
extern T D_00448578;
extern T D_00448768;
extern T D_00448C68;
extern "C" void func_002A87E8(cObj *, int);
struct cObj {
    virtual void v();
    char _p[0x2F5];
    unsigned char st;
};

// FUNCTION: GAME 0x280A10
extern "C" void func_00280A10(cObj *self)
{
    T t = D_00448578;
    if (self->st >= 2)
        self->st = 0;
    (self->*t.f[self->st])();
}

// FUNCTION: GAME 0x282D70
extern "C" void func_00282D70(cObj *self)
{
    T t = D_00448768;
    if (self->st >= 2)
        self->st = 0;
    (self->*t.f[self->st])();
}

// FUNCTION: GAME 0x288570
extern "C" void func_00288570(cObj *self)
{
    T t = D_00448C68;
    if (self->st >= 2)
        self->st = 0;
    (self->*t.f[self->st])();
    func_002A87E8(self, 0);
}

struct cObjH {
    virtual void v();
    char _p[0x2F5];
    unsigned char st;
    char _q[0x15B0 - 0x2F6];
    int h15B0;
    char _r[0x15C4 - 0x15B4];
    int h15C4;
};
typedef void (cObjH::*FnH)();
struct T2H { FnH f[2]; };
struct T3H { FnH f[3]; };
extern T3H D_00448C78;
extern T2H D_00448E00;
extern "C" int func_001C2490(...);
extern "C" void func_001C2370(...);

// FUNCTION: GAME 0x288930
extern "C" void func_00288930(cObjH *self)
{
    T3H t = D_00448C78;
    if (self->h15C4) {
        if (func_001C2490(self->h15C4))
            self->h15C4 = 0;
        else
            func_001C2370(self->h15C4);
        self->h15C4 = 0;
    }
    if (self->st >= 3)
        self->st = 0;
    (self->*t.f[self->st])();
}

// FUNCTION: GAME 0x28A8D0
extern "C" void func_0028A8D0(cObjH *self)
{
    T2H t = D_00448E00;
    if (self->h15B0) {
        if (func_001C2490(self->h15B0))
            self->h15B0 = 0;
        else
            func_001C2370(self->h15B0);
        self->h15B0 = 0;
    }
    if (self->st >= 2)
        self->st = 0;
    (self->*t.f[self->st])();
}

// Redundant `if (x) t = 2` keeps 2 in a register so gcc emits movn instead of movz.
// FUNCTION: GAME 0x282928
extern "C" void func_00282928(char *self0)
{
    char *self = self0;
    unsigned char x = *(unsigned char *)(self + 0x15B0);
    int t = x ? 2 : 0;
    if (x) t = 2;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x158) + (int)tb, *(int *)(tb + 0x15C) + (int)tb, 2, t, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        break;
    case 2: {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x160) + (int)tb, *(int *)(tb + 0x164) + (int)tb, 2, t, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 3:
        moveMotion((cObjBase *)self);
    }
}

// FUNCTION: GAME 0x281E60
extern "C" void func_00281E60(char *self0)
{
    char *self = self0;
    unsigned char x = *(unsigned char *)(self + 0x15B0);
    int t = x ? 2 : 0;
    if (x) t = 2;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        if (*(unsigned char *)(self + 0x2F7)) {
            char *tb = *(char **)(self + 0x304);
            func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x54) + (int)tb, *(int *)(tb + 0x5C) + (int)tb, 5, t, 0);
        } else {
            char *tb = *(char **)(self + 0x304);
            func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x54) + (int)tb, *(int *)(tb + 0x58) + (int)tb, 5, t, 0);
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            *(unsigned char *)(self + 0x2F7) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F4) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F5) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F6) = 0;
        }
    }
}

// FUNCTION: GAME 0x282388
extern "C" void func_00282388(char *self0)
{
    char *self = self0;
    unsigned char x = *(unsigned char *)(self + 0x15B0);
    int t = x ? 2 : 0;
    if (x) t = 2;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        if (*(unsigned char *)(self + 0x2F7)) {
            char *tb = *(char **)(self + 0x304);
            func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x94) + (int)tb, *(int *)(tb + 0x9C) + (int)tb, 5, t, 0);
        } else {
            char *tb = *(char **)(self + 0x304);
            func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x94) + (int)tb, *(int *)(tb + 0x98) + (int)tb, 5, t, 0);
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            *(unsigned char *)(self + 0x2F7) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F4) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F5) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F6) = 0;
        }
    }
}

// FUNCTION: GAME 0x282080
extern "C" void func_00282080(char *self0)
{
    char *self = self0;
    unsigned char x = *(unsigned char *)(self + 0x15B0);
    int t = x ? 2 : 0;
    if (x) t = 2;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x7C) + (int)tb, *(int *)(tb + 0x80) + (int)tb, 5, t, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            *(unsigned char *)(self + 0x2F7) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F4) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F5) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F6) = 0;
        }
    }
}
