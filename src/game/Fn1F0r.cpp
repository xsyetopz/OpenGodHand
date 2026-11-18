// Small helpers in 0x1F0000-0x200000, over raw offsets (continued from Fn1F0q.cpp).
extern "C" void func_001F7228(void *);
extern "C" void func_001FD988(char *, int);
extern char *Cockpit;

struct F1F38F0Ent {
    short off;
    void (*fn)(void *);
};
extern F1F38F0Ent D_003BF0A8[];

// FUNCTION: GAME 0x1F38F0
extern "C" void Main__16ColiseumEmSelect(char *self)
{
    int i = *(int *)(self + 4) << 3;
    short off = *(short *)((char *)D_003BF0A8 + i);
    (*(void (**)(void *))((char *)D_003BF0A8 + 4 + i))(self + off);
}

// FUNCTION: GAME 0x1F6F10
extern "C" void setExit__17cActionButtonUnit(unsigned char *self)
{
    if (self[0x35] == 1)
        *(unsigned *)((char *)Cockpit + 0xF30) |= 0x20000000;
    func_001F7228(self);
}

// FUNCTION: GAME 0x1FD2C0
extern "C" int func_001FD2C0(char *self, int a1, int a2)
{
    if (!self[0x49])
        return 1;
    *(int *)(self + 0x34) = 0;
    *(int *)(self + 0x30) = a2;
    func_001FD988(self, a1);
    self[0x4A] = 1;
    return 1;
}

// FUNCTION: GAME 0x1FD530
extern "C" int func_001FD530(char *self, int a1, int a2)
{
    if (!self[0x49])
        return 1;
    *(int *)(self + 0x30) = a1;
    self[0x4A] = 1;
    func_001FD988(self, a2);
    *(int *)(self + 0x34) = 0;
    return 1;
}

// FUNCTION: GAME 0x1F6F58
extern "C" void func_001F6F58(unsigned char *p)
{
    if (p[0x36] == 1) {
        if (*(short *)(p + 0x32) <= 0)
            func_001F7228(p);
        else
            *(unsigned short *)(p + 0x32) -= 1;
    }
}

// FUNCTION: GAME 0x1F8A88
extern "C" void func_001F8A88(float *o, float x0, float x1, float y0, float y1, float z0, float z1)
{
    float hx = (x1 - x0) * 0.5f;
    float hy = (y1 - y0) * 0.5f;
    float hz = (z1 - z0) * 0.5f;
    o[3] = hx;
    o[4] = hy;
    o[5] = hz;
    o[0] = hx + x0;
    o[1] = hy + y0;
    o[2] = hz + z0;
}

// FUNCTION: GAME 0x1FACB0
extern "C" int func_001FAE60(void *);
extern "C" void func_001FACB0(char **self)
{
    if (*self) {
        int n = func_001FAE60(self);
        *(int *)(*self + 0x80) = n * 0x14 + 0x64;
    }
}

// FUNCTION: GAME 0x1FAFA8
extern "C" void func_001FAFA8(char **self)
{
    if (*self) {
        unsigned i = 0;
        do {
            *(unsigned short *)((char *)(i << 4) + (int)*self + 0x28A) = 0xFFFF;
            i++;
        } while (i < 0x80);
        *(short *)(*self + 0x288) = 1;
    }
}

// FUNCTION: GAME 0x1FC1C8
extern "C" int func_001FC1C8(char **self, unsigned v)
{
    unsigned char *q = (unsigned char *)*self;
    if (!q)
        return 0;
    unsigned char *p = q + 0x98;
    for (unsigned i = 0; i < 10; i++) {
        if (p[i] == v)
            return 1;
    }
    return 0;
}

extern "C" int func_001FEE00(void *);
extern "C" int func_001FF238(void *);
extern "C" void systemInit__11cDataHolder(void *);

// FUNCTION: GAME 0x1FE9B8
extern "C" int func_001FE9B8(char *self)
{
    int i = func_001FEE00(self);
    int r;
    if (i < 0)
        r = 0;
    else
        r = func_001FF238(*(char **)(self + 8) + i * 0x5C);
    return r;
}

// FUNCTION: GAME 0x1FEA00
extern "C" int seeDataAddress__12cDataManager6eObjId(char *self)
{
    int i = func_001FEE00(self);
    if (i >= 0)
        return *(int *)(*(char **)(self + 8) + i * 0x5C + 0x10);
    return 0;
}

// FUNCTION: GAME 0x1FEC90
extern "C" int func_001FEC90(char *self)
{
    int i = func_001FEE00(self);
    if (i < 0)
        return 0;
    systemInit__11cDataHolder(*(char **)(self + 8) + i * 0x5C);
    return 1;
}

extern "C" void func_001F7D18(void *, int);
extern char D_0042C320[];

// FUNCTION: GAME 0x1F7CC8
extern "C" void func_001F7CC8(char *self, unsigned a1)
{
    *(char **)(self + 8) = D_0042C320;
    *(unsigned *)self &= 0xFFFFF9FC;
    if (a1 & 1)
        func_001F7D18(self, 0xC);
}

extern "C" void func_001FF0B0(void *);
extern "C" void func_001FF5B8(void *);

// FUNCTION: GAME 0x1FF2E0
extern "C" void func_001FF2E0(char *self, int a1)
{
    if (a1)
        *(int *)(self + 4) = 0;
    func_001FF0B0(self);
    int r;
    if (*(int *)(self + 4) == 0) {
        func_001FF5B8(self);
        r = 5;
    } else
        r = 3;
    *(int *)self = r;
}

extern "C" void func_002000F8(void *);
extern unsigned D_00747A84;

// FUNCTION: GAME 0x1FFE10
extern "C" void func_001FFE10(short *p)
{
    if (*p)
        *(unsigned short *)p -= 1;
    if (D_00747A84 & 0x2000000)
        func_002000F8(p);
}

extern "C" int getJumpData__5cDoorUcUcUcbUc(void *, unsigned char, unsigned char, unsigned char, int, unsigned char);
extern "C" void setDoorJump__5cDoor(void *);

// FUNCTION: GAME 0x1FFE60
extern "C" void func_001FFE60(void *self, unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    if (getJumpData__5cDoorUcUcUcbUc(self, a, b, c, 0, d) == 1)
        setDoorJump__5cDoor(self);
}

extern "C" void func_001F46E0(void *);
extern "C" void free__5cHeapPv(void *, void *);
struct F1F38A0Sys {
    char *p;
};
extern F1F38A0Sys *IDSys;

// FUNCTION: GAME 0x1F38A0
extern "C" void func_001F38A0(char *self)
{
    func_001F46E0(self + 0x60);
    char *q = IDSys->p;
    *(int *)(q + 0xAC) = 0;
    *(int *)(q + 0xA8) = 0;
    char *m = *(char **)(self + 0x37D8);
    if (m)
        free__5cHeapPv(*(void **)(m - 0x20), m);
}
