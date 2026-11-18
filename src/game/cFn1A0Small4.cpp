// Small unnamed functions in 0x1A0000-0x1DFFFF (round 19).
extern "C" void func_001B6F38(void *self, int flag);
extern "C" void func_001BBF00(void *self, int flag);
extern const char D_004274D0[];
extern const char D_004275C8[];
extern const char D_00427690[];
extern const char D_00427880[];
extern const char D_00427B20[];
extern const char D_00427F48[];

// FUNCTION: GAME 0x1A6DA0
extern "C" void func_001A6DA0(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_004274D0;
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x1A77F8
extern "C" void func_001A77F8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_004275C8;
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x1A81D8
extern "C" void func_001A81D8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00427690;
    func_001BBF00(self, flag);
}

// FUNCTION: GAME 0x1A8730
extern "C" void func_001A8730(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00427880;
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x1A96C0
extern "C" void func_001A96C0(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00427B20;
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x1ADBC0
extern "C" void func_001ADBC0(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00427F48;
    func_001B6F38(self, flag);
}

struct Door {
    char _pad[0x2F4];
    unsigned char m_a, m_b, m_c, m_d;
    char _pad2[0x774 - 0x2F8];
    unsigned char m_state;
};

// FUNCTION: GAME 0x1BDBF8
extern "C" void setOpen__8cOmDoor2(Door *self)
{
    if (self->m_state == 0) {
        self->m_a = 1;
        self->m_b = 0;
        self->m_c = 0;
        self->m_d = 0;
    }
}

// FUNCTION: GAME 0x1BDC20
extern "C" void setClose__8cOmDoor2(Door *self)
{
    if (self->m_state == 1) {
        self->m_a = 2;
        self->m_b = 0;
        self->m_c = 0;
        self->m_d = 0;
    }
}

struct F604 {
    char _pad[0x604];
    float m_f;
};

// FUNCTION: GAME 0x1B8648
extern "C" int func_001B8648(F604 *self)
{
    return 0.0f < self->m_f;
}

extern int D_00747A78;
struct F5B4 {
    char _pad[0x5B4];
    int m_v;
};

// FUNCTION: GAME 0x1B76B0
extern "C" int func_001B76B0(F5B4 *self)
{
    if (D_00747A78 & 0x20000000)
        return 0;
    self->m_v = 0;
    return 1;
}

extern "C" void func_001B6E90(void *self);
extern "C" void func_001B6FB8(void *self);
extern "C" void func_001B7EE0(void *self, float f);
extern "C" void func_001C29D0(void *self);
extern "C" void SetMotionWait__5cOm71(void *self);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(void *mgr, void *obj);
struct CollMgr {
    int _x;
};
extern CollMgr g_CollSolidManage;

struct OmFlags {
    char _pad[0x2F4];
    unsigned char m_a;
    char _pad2[0x5B8 - 0x2F5];
    unsigned m_f;
};
struct Om62C {
    char _pad[0x62C];
    unsigned char m_c;
};
struct VtSelf {
    char _pad[0x214];
    const void *m_vt;
};

// FUNCTION: GAME 0x1B3628
extern "C" void ReleaseCollision__5cOmb0(Om62C *self)
{
    self->m_c = 0;
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(&g_CollSolidManage, self);
}

// FUNCTION: GAME 0x1B1E00
extern "C" void func_001B1E00(OmFlags *self)
{
    SetMotionWait__5cOm71(self);
    self->m_a = 1;
}

// FUNCTION: GAME 0x1B37D0
extern "C" int func_001B37D0(OmFlags *self)
{
    func_001B6FB8(self);
    self->m_a = 0;
    return 1;
}

// FUNCTION: GAME 0x1A3FD8
extern "C" void func_001A3FD8(void *self)
{
    func_001C29D0(self);
    func_001B7EE0(self, 2.0f);
}

// FUNCTION: GAME 0x1A6DC8
extern "C" int func_001A6DC8(OmFlags *self)
{
    func_001B6FB8(self);
    self->m_f |= 8;
    return 1;
}

// FUNCTION: GAME 0x1A6D68
extern "C" VtSelf *func_001A6D68(VtSelf *self)
{
    func_001B6E90(self);
    self->m_vt = D_004274D0;
    return self;
}

// FUNCTION: GAME 0x1A86F8
extern "C" VtSelf *func_001A86F8(VtSelf *self)
{
    func_001B6E90(self);
    self->m_vt = D_00427880;
    return self;
}

// FUNCTION: GAME 0x1A9688
extern "C" VtSelf *func_001A9688(VtSelf *self)
{
    func_001B6E90(self);
    self->m_vt = D_00427B20;
    return self;
}
