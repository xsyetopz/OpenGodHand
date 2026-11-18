#include "game/cVec.h"
extern char g_CollisionManager[];
extern "C" char *func_002B9DF0(void *);
extern "C" char *func_002BA020(void *);
extern "C" char *func_002B9EF0(void *);
extern "C" void func_002BB0C8(char *, int, int);

struct Obj {
    cVec p0;
    int pad;
    cVec p1;
    char pad2[0xC];
    int h28;
    short s2C;
    char b2E;
};

// FUNCTION: GAME 0x1FCA38
extern "C" int func_001FCA38(Obj *self, int a1, int a2, int a3, int a4)
{
    char *h = func_002B9DF0(g_CollisionManager);
    *(char **)((char *)self + 0x28) = h;
    if (!h)
        return -1;
    func_002BB0C8(h + 0x14, 1, a4);
    cVec *src = *(cVec **)(*(char **)(*(char **)((char *)self + 0x28) + 0x34) + 0xC0);
    cVec *d = &self->p1;
    *d = *src;
    self->p0 = *d;
    self->b2E = 1;
    return self->s2C;
}

// FUNCTION: GAME 0x1FC988
extern "C" int func_001FC988(Obj *self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    char *h = func_002BA020(g_CollisionManager);
    *(char **)((char *)self + 0x28) = h;
    if (!h)
        return -1;
    func_002BB0C8(h + 0x14, 1, a6);
    cVec *src = *(cVec **)(*(char **)(*(char **)((char *)self + 0x28) + 0x34) + 0xC0);
    cVec *d = &self->p1;
    *d = *src;
    self->p0 = *d;
    self->b2E = 1;
    return self->s2C;
}

// FUNCTION: GAME 0x1FCAE8
extern "C" int func_001FCAE8(Obj *self, int a1, int a2, int a3, int a4, int a5)
{
    char *h = func_002B9EF0(g_CollisionManager);
    *(char **)((char *)self + 0x28) = h;
    if (!h)
        return -1;
    func_002BB0C8(h + 0x14, 1, a5);
    cVec *src = *(cVec **)(*(char **)(*(char **)((char *)self + 0x28) + 0x34) + 0xC0);
    cVec *d = &self->p1;
    *d = *src;
    self->p0 = *d;
    self->b2E = 1;
    return self->s2C;
}
