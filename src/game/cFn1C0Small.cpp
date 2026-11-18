// Small unnamed functions in 0x1C0000-0x1FFFFF (0x20-0x40 bytes).
extern "C" void func_0030F5A0(void *);
extern "C" void func_001F4778(void *, int);
extern "C" void func_001C6A90(void *, int, int, void *, int);
extern "C" void dieCommon__7cOmBase(void *);
extern "C" void func_001D4B78(int, int);
extern "C" void func_001DCEF0(int, int);
extern "C" void func_001D51B8(void *, int, int);

struct cBoundingBox2 {
    int m_v[6];
};

// FUNCTION: GAME 0x1F8A60
extern "C" void _$_12cBoundingBox(cBoundingBox2 *self, int flags)
{
    if (flags & 1)
        func_0030F5A0(self);
}

struct Slot1 {
    char _pad[0x400];
    int m_layer[0x23];
};
struct Slot2 {
    char _pad[0x3A0];
    int m_layer[0xC];
};

// FUNCTION: GAME 0x1E3218
extern "C" void SetSlotLayer__5Slot1Pi(Slot1 *self, int *src)
{
    for (int i = 0; i < 0x23; i++)
        self->m_layer[i] = src[i];
}

// FUNCTION: GAME 0x1E6780
extern "C" void SetSlotLayer__5Slot2Pi(Slot2 *self, int *src)
{
    for (int i = 0; i < 0xC; i++)
        self->m_layer[i] = src[i];
}

// FUNCTION: GAME 0x1F5278
extern "C" void func_001F5278(void *self, unsigned short n)
{
    if (n < 7)
        func_001F4778(self, n + 0x49);
}

// FUNCTION: GAME 0x1C6968
extern "C" void func_001C6968(char *self, int a, int b)
{
    func_001C6A90(self, a, b, self + 0x80, 1);
}

struct OmB {
    char _pad[0x531];
    signed char m_x;
};

// FUNCTION: GAME 0x1CF140
extern "C" void func_001CF140(OmB *self)
{
    self->m_x = -1;
    dieCommon__7cOmBase(self);
}

// FUNCTION: GAME 0x1D4D60
extern "C" void func_001D4D60(void)
{
    func_001D4B78(1, 0xFFFF);
}

// FUNCTION: GAME 0x1DD048
extern "C" void func_001DD048(void)
{
    func_001DCEF0(1, 0xFFFF);
}

// FUNCTION: GAME 0x1D6BC0
extern "C" void func_001D6BC0(void *self, int v)
{
    func_001D51B8(self, 0x20, v);
}

// FUNCTION: GAME 0x1D6C70
extern "C" void func_001D6C70(void *self, int v)
{
    func_001D51B8(self, 0x1F, v);
}

struct OmWeapon {
    char _pad[0x668];
    int m_hp;
};

// FUNCTION: GAME 0x1D07F0
extern "C" int SetDamage__9cOmWeaponi(OmWeapon *self, int d)
{
    int v = self->m_hp - d;
    self->m_hp = v;
    if (v <= 0) {
        self->m_hp = 0;
        return 1;
    }
    return 0;
}

struct Flags2F4 {
    char _pad[0x2F4];
    unsigned char m_a;
    unsigned char m_b;
};

// FUNCTION: GAME 0x1D0B08
extern "C" int func_001D0B08(Flags2F4 *self)
{
    if (self->m_a)
        return 0;
    return self->m_b == 4;
}
