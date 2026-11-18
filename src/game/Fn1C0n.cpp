struct V3 {
    float x, y, z;
};
extern const char D_00429EC8[];
extern "C" void func_001B6E90(void *);
extern "C" int moveMotion__FP8cObjBase(void *);

// FUNCTION: GAME 0x001CA1F8
extern "C" void func_001CA1F8(char *self)
{
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        *(unsigned char *)(self + 0x2F6) = 1;
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

// FUNCTION: GAME 0x001C2328
extern "C" int func_001C2328(char *self)
{
    if (*(unsigned char *)(self + 0x2F4) != 0)
        return 0;
    int v = *(unsigned char *)(self + 0x2F6);
    if (v < 2)
        return 0;
    if (v < 4)
        return 1;
    if (v >= 8)
        return 0;
    if (v < 6)
        return 0;
    return 1;
}

// FUNCTION: GAME 0x001C24A0
extern "C" int func_001C24A0(char *self)
{
    switch (*(unsigned short *)(self + 0x2FE)) {
    case 0x3BC:
    case 0x3D9:
    case 0x3E3:
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x001C8F80
extern "C" void *func_001C8F80(char *self)
{
    func_001B6E90(self);
    *(const char **)(self + 0x214) = D_00429EC8;
    *(int *)(self + 0x600) = 5;
    *(int *)(self + 0x604) = 0xE;
    *(int *)(self + 0x608) = 0;
    return self;
}

// FUNCTION: GAME 0x001CD7A8
extern "C" void func_001CD7A8(char *self)
{
    char *o = *(char **)(self + 0x670);
    if (o) {
        V3 *src = *(V3 **)(o + 0xF0);
        V3 *dst = *(V3 **)(self + 0xF0);
        if (dst != src) {
            dst->x = src->x;
            dst->y = src->y;
            dst->z = src->z;
        }
        dst = *(V3 **)(self + 0xF0);
        dst->y -= 0.6f;
    }
}

// FUNCTION: GAME 0x001C3C58
extern "C" int func_001C3C58(int *out, int *a)
{
    if (!a)
        return 0;
    out[0] = (int)a;
    if (a[0] != 0x534D4F) {
        out[0] = 0;
        return 0;
    }
    if (a[1] == 0) {
        out[0] = 0;
        return 0;
    }
    out[1] = a[2] < 2 ? (int)(a + 3) : (int)(a + 4);
    return 1;
}

// FUNCTION: GAME 0x001DBEB0
extern "C" void func_001DBEB0(char *self)
{
    int i = 0x33;
    int *p = (int *)(self + 0x2E68);
    do {
        char *o = *(char **)(p - 1);
        *(unsigned *)(o + 0x250) |= 2;
        *p = 9;
        *(int *)(*(char **)(p - 1) + 0x104) = 0;
        p += 2;
    } while (--i >= 0);
    int *q = (int *)(self + 0x3014);
    i = 4;
    do {
        *q = 0;
        q--;
    } while (--i >= 0);
}

extern "C" void __7cIDBase(void *);
extern "C" void __12CustomIDWork(void *);

// FUNCTION: GAME 0x001D4D80
extern "C" void *func_001D4D80(char *self)
{
    *(int *)self = 0;
    __7cIDBase(self + 0x10);
    char *w = self + 0x60;
    int i = 44;
    do {
        __12CustomIDWork(w);
        w += 0x7C;
    } while (--i != -1);
    return self;
}

// FUNCTION: GAME 0x001DD068
extern "C" void *func_001DD068(char *self)
{
    *(int *)self = 0;
    __7cIDBase(self + 0x10);
    char *w = self + 0x60;
    int i = 76;
    do {
        __12CustomIDWork(w);
        w += 0x7C;
    } while (--i != -1);
    return self;
}

extern char g_DmgManage[];
extern "C" int ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
extern "C" void dieCommon__7cOmBase(void *);

// FUNCTION: GAME 0x001C8DD8
extern "C" void func_001C8DD8(char *self)
{
    void *g = *(void **)(self + 0x600);
    if (g) {
        if (ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, g)) {
            *(int *)(self + 0x600) = 0;
            *(int *)(self + 0x604) = -1;
        }
    }
    if (*(unsigned char *)(self + 0x640)) {
        dieCommon__7cOmBase(self);
    } else {
        char *vt = *(char **)(self + 0x214);
        ((void (*)(char *))*(void **)(vt + 0xA4))(self + *(short *)(vt + 0xA0));
    }
}
