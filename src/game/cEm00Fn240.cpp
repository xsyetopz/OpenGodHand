// Small unnamed functions in 0x240000-0x267FFF.

class cObjBase {
public:
    void addNullSpeed(float);
    void addNullSpeed_Rotation(float);
};
int moveMotion(cObjBase *);

extern "C" {
void func_002705D8(void *);
int func_00276468(void *);
void func_002A8578(void *self, int a, int b, int c, float f, int d, int e);
}

#define B(o) (*(unsigned char *)((char *)self + (o)))

struct Fn2478B8Obj {
    char _pad0[0x2F4];
    char m_unk2F4;
    unsigned char m_unk2F5;
    char m_unk2F6;
    char m_unk2F7;
};

// FUNCTION: GAME 0x2478B8
extern "C" void func_002478B8(Fn2478B8Obj *self)
{
    self->m_unk2F5 = 0x99;
    self->m_unk2F6 = 2;
    self->m_unk2F4 = 0;
    self->m_unk2F7 = 0;
}

struct Fn2609Obj {
    char _pad0[0x1870];
    int m_unk1870;
    int m_unk1874;
    int m_unk1878;
    int m_unk187C;
    short m_unk1880;
    char _pad1882[2];
    int m_unk1884;
    int m_unk1888;
    int m_unk188C;
    int m_unk1890;
    short m_unk1894;
};

// FUNCTION: GAME 0x2609A8
extern "C" void func_002609A8(Fn2609Obj *self, int a, int b, int c, int d, short e)
{
    self->m_unk1874 = a;
    self->m_unk1870 = b;
    self->m_unk1878 = c;
    self->m_unk187C = d;
    self->m_unk1880 = e;
    self->m_unk1888 = a;
    self->m_unk1884 = b;
    self->m_unk188C = c;
    self->m_unk1890 = d;
    self->m_unk1894 = e;
}

// FUNCTION: GAME 0x2609E0
extern "C" void func_002609E0(Fn2609Obj *self, int a, int b, int c, int d, short e)
{
    self->m_unk1874 = a;
    self->m_unk1870 = b;
    self->m_unk1878 = c;
    self->m_unk187C = d;
    self->m_unk1880 = e;
}

// FUNCTION: GAME 0x2609F8
extern "C" void func_002609F8(Fn2609Obj *self, int a, int b, int c, int d, short e)
{
    self->m_unk1888 = a;
    self->m_unk1884 = b;
    self->m_unk188C = c;
    self->m_unk1890 = d;
    self->m_unk1894 = e;
}

// FUNCTION: GAME 0x2477F0
extern "C" void func_002477F0(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    *(unsigned int *)(self + 0x16D0) |= 0x20000;
    switch (B(0x2F6)) {
    case 0: {
        int m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x23F8) + (int)t, *(int *)(t + 0x23FC) + (int)t, 0, 0.0f, m & 0xFFFF, 0);
        B(0x2F6)++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x247708
extern "C" void func_00247708(char *self)
{
    *(unsigned int *)(self + 0x16D0) |= 0x30000;
    *(float *)(self + 0x54C) = 3.0f;
    *(unsigned int *)(self + 0x250) |= 0x10000;
    switch (B(0x2F6)) {
    case 0: {
        int m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x2148) + (int)t, *(int *)(t + 0x214C) + (int)t, 0, 0.0f, m & 0xFFFF, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// func_00247218 @ 0x247218: near-miss, 7 words differ. The original keeps the
// cEmParam base in v0 and the two offsets in v1/a0 across the branch; every
// source form tried allocates the base in a0 and the sums in a1/a2.
#ifdef NONMATCHING
extern "C" void func_00247218(char *self)
{
    B(0x617) = 1;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short m = func_00276468(self);
        char *t;
        int a, b;
        if (*(int *)(self + 0x564) == 0x24F) {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x1F70); b = *(int *)(t + 0x1F74);
        } else {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x1F78); b = *(int *)(t + 0x1F7C);
        }
        func_002A8578(self, a + (int)t, b + (int)t, 10, 0.0f, m, 0);
        *(short *)(self + 0x568) = 10;
        B(0x623) = 1;
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(short *)(self + 0x568) > 0)
            (*(short *)(self + 0x568))--;
        else
            B(0x623) = 0;
    }
}
#endif
