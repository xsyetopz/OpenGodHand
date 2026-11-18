// Medium unnamed functions in the 0x1D0000-0x1EFFFF owner classes.
extern "C" void func_001D51B8(void *, int, int);
extern "C" int func_001D4720(void *);
extern "C" int func_001D47E8(void *);

struct IdSelf {
    char _pad[1];
};

// FUNCTION: GAME 0x1D69A0
extern "C" void func_001D69A0(IdSelf *self, int v)
{
    func_001D51B8(self, 0x1C, v);
    func_001D51B8(self, 0x1D, v);
}

// FUNCTION: GAME 0x1D69E8
extern "C" void func_001D69E8(IdSelf *self, int v)
{
    func_001D51B8(self, 0x1A, v);
    func_001D51B8(self, 0x1B, v);
}

// FUNCTION: GAME 0x1D6BE0
extern "C" void func_001D6BE0(IdSelf *self, int v)
{
    func_001D51B8(self, 0x29, v);
    func_001D51B8(self, 0x2A, v);
}

// FUNCTION: GAME 0x1D6C28
extern "C" void func_001D6C28(IdSelf *self, int v)
{
    func_001D51B8(self, 0x2B, v);
    func_001D51B8(self, 0x2C, v);
}

// FUNCTION: GAME 0x1D6C90
extern "C" void func_001D6C90(IdSelf *self, int v)
{
    func_001D51B8(self, 0x25, v);
    func_001D51B8(self, 0x26, v);
}

// FUNCTION: GAME 0x1D6CD8
extern "C" void func_001D6CD8(IdSelf *self, int v)
{
    func_001D51B8(self, 0x27, v);
    func_001D51B8(self, 0x28, v);
}

// FUNCTION: GAME 0x1D55D0
extern "C" void func_001D55D0(IdSelf *self, int v)
{
    func_001D51B8(self, 0x21, v);
    func_001D51B8(self, 0x22, 1);
}

// FUNCTION: GAME 0x1D5610
extern "C" void func_001D5610(IdSelf *self, int v)
{
    func_001D51B8(self, 0x7, v);
    func_001D51B8(self, 0x8, 1);
}

// FUNCTION: GAME 0x1D5650
extern "C" void func_001D5650(IdSelf *self, int v)
{
    func_001D51B8(self, 0x5, v);
    func_001D51B8(self, 0x6, 1);
}

struct Obj2B {
    char _pad[0x2B];
    unsigned char m_v;
};
struct Slot {
    int _0;
    Obj2B *m_obj;
    char _8[0x70];
    unsigned char m_val;
    char _79[3];
};
struct SlotOwner {
    char _pad[0xDC];
    Slot m_a;
    Slot m_b;
};

// FUNCTION: GAME 0x1D6D20
extern "C" void func_001D6D20(SlotOwner *self, int on)
{
    if (on) {
        self->m_a.m_obj->m_v = 3;
        self->m_b.m_obj->m_v = 4;
        return;
    }
    Slot *a = &self->m_a;
    Slot *b = &self->m_b;
    a->m_obj->m_v = a->m_val;
    b->m_obj->m_v = b->m_val;
}

// FUNCTION: GAME 0x1D4980
extern "C" int func_001D4980(char *self)
{
    if (*(unsigned short *)(self + 0x17FC) != 5)
        return 0;
    return func_001D4720(self) < 0x16;
}

// FUNCTION: GAME 0x1D49B0
extern "C" int func_001D49B0(char *self)
{
    if (*(unsigned short *)(self + 0x17FE) != 5)
        return 0;
    return func_001D47E8(self) < 0x16;
}

struct FlagBody {
    char _pad[0x104];
    int m_104;
};
struct FlagObj {
    FlagBody *m_body;
    int m_flags;
};

// FUNCTION: GAME 0x1D6DD0
extern "C" void func_001D6DD0(FlagObj *self, int a)
{
    long f = (unsigned)self->m_flags;
    long x = (f >> 3) & 1;
    if (x)
        return;
    long y = (f >> 4) & 1;
    if (y)
        return;
    if (a) {
        self->m_flags |= 0x10;
        return;
    }
    self->m_body->m_104 = 0;
    self->m_flags |= 0x8;
}

// FUNCTION: GAME 0x1D0C98
extern "C" void func_001D0C98(FlagObj *self, int a)
{
    long f = (unsigned)self->m_flags;
    long x = (f >> 1) & 1;
    if (x)
        return;
    long y = (f >> 2) & 1;
    if (y)
        return;
    if (a) {
        self->m_flags |= 0x4;
        return;
    }
    self->m_body->m_104 = 0;
    self->m_flags |= 0x2;
}

struct SlotOwner2 {
    char _pad[0x1D4];
    Slot m_a;
    Slot m_b;
};

// FUNCTION: GAME 0x1D6D68
extern "C" void func_001D6D68(SlotOwner2 *self, int on)
{
    if (on) {
        self->m_a.m_obj->m_v = 3;
        self->m_b.m_obj->m_v = 4;
        return;
    }
    Slot *a = &self->m_a;
    Slot *b = &self->m_b;
    a->m_obj->m_v = a->m_val;
    b->m_obj->m_v = b->m_val;
}
