// Small free functions after cParts::setRotationOrder (0x150000-0x152FFF).

extern char D_00466470[];
extern "C" void func_00150418(void *);
extern "C" void func_001504B0(void *, void *);
extern "C" void func_001505A8(void *, void *);
extern "C" void func_001523F8(int a, unsigned int b);
extern "C" int func_00151630(char *);

// FUNCTION: GAME 0x150078
extern "C" void func_00150078()
{
    func_00150418(D_00466470);
}

// FUNCTION: GAME 0x150098
extern "C" void func_00150098(void *a)
{
    func_001504B0(D_00466470, a);
}

// FUNCTION: GAME 0x150100
extern "C" void func_00150100(void *a)
{
    func_001505A8(D_00466470, a);
}

// FUNCTION: GAME 0x152428
extern "C" void func_00152428()
{
    func_001523F8(1, 0xFFFF);
}

struct sSlot {
    char _pad0[0x14];
    int m_key;
    char _pad18[0xB0 - 0x18];
};
extern sSlot D_00747BA0[256];

extern int D_00460D30;
extern const char D_0041ECB8[];
extern "C" void func_0031EEC8(void *, const char *);

// FUNCTION: GAME 0x150638
extern "C" int *func_00150638()
{
    if (!D_00460D30)
        func_0031EEC8(&D_00460D30, D_0041ECB8);
    return &D_00460D30;
}

// FUNCTION: GAME 0x1522C0
extern "C" char *func_001522C0(void *self, char *p, unsigned char idx)
{
    if (func_00151630(p) == 3) {
        char *q = p + idx * 4;
        return (char *)*(int *)(q + 0x10) + (int)p;
    }
    return p;
}

struct sPair {
    int m_key;
    int m_val;
};

// FUNCTION: GAME 0x15FD18
extern "C" int func_0015FD18(sPair *tbl, int key)
{
    if (key == -1)
        return 0;
    int i = 0;
    sPair *p = tbl;
    for (; i < 9; i++, p++) {
        int off = i << 3;
        if (p->m_key == key)
            return *(int *)((char *)tbl + off + 4);
    }
    return 0;
}

extern "C" void sceVu0CopyVector(float *, float *);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" char *func_001551E0(void *);
extern "C" char *func_001552F0(void *);
extern "C" void func_0015B0F0(void *);

class cObjBase {
public:
    char _pad[0x434];
    unsigned short m_flags;
    char _pad1[0x444 - 0x436];
    float m_x;
};


// FUNCTION: GAME 0x158FB8
extern "C" float func_00158FB8()
{
    return 0.0f;
}

// FUNCTION: GAME 0x159490
extern "C" float func_00159490()
{
    return 0.0f;
}

// FUNCTION: GAME 0x158288
void SetMotionStep(cObjBase *self, float v)
{
    if (self->m_flags & 4)
        v = -v;
    self->m_x = v;
}

// FUNCTION: GAME 0x1506F0
extern "C" void func_001506F0(float *a, float *b)
{
    sceVu0CopyVector(a, b);
}

// FUNCTION: GAME 0x150710
extern "C" void func_00150710(float *v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 1.0f;
}

// FUNCTION: GAME 0x1508D8
extern "C" void func_001508D8(float *a, float *b, float *c)
{
    sceVu0ApplyMatrix(a, b, c);
}

// FUNCTION: GAME 0x1551C0
extern "C" char *func_001551C0(void *self)
{
    return func_001551E0(self) + 0x40;
}

// FUNCTION: GAME 0x1552D0
extern "C" char *func_001552D0(void *self)
{
    return func_001552F0(self) + 0x40;
}

// FUNCTION: GAME 0x155D98
extern "C" void func_00155D98(char *base, long v, int i)
{
    *(long *)(base + i * 0xB0 + 0x50) = v;
}

// FUNCTION: GAME 0x15B080
extern "C" void func_0015B080(void *self)
{
    func_0015B0F0(self);
}
