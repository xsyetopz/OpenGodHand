// Small free functions around cSubScr (0x160000-0x16FFFF).

#include "game/cIDBase.h"

struct sSys {
    char _pad0[0x5D8];
    int m_unk5D8;
    char _pad5DC[4];
    int m_unk5E0;
};
extern sSys Sys;

struct sSubScrWork {
    char _pad0[0x68];
    int m_unk68;
    int m_unk6C;
};

struct sVec3i {
    int m_a;
    int m_b;
    int m_c;
};

extern "C" void func_00161480(int a, unsigned int b);
extern "C" void func_00164980(int a, unsigned int b);
extern "C" void func_0015FD18(void *self, int v);

// FUNCTION: GAME 0x1614B0
extern "C" void func_001614B0()
{
    func_00161480(1, 0xFFFF);
}

// FUNCTION: GAME 0x164ED8
extern "C" void func_00164ED8()
{
    func_00164980(1, 0xFFFF);
}

// FUNCTION: GAME 0x161288
extern "C" void func_00161288(char *self)
{
    func_0015FD18(self, *(int *)(self + 0x48));
}

// FUNCTION: GAME 0x1615D0
extern "C" void func_001615D0(sSubScrWork *self)
{
    self->m_unk68 = Sys.m_unk5D8;
    self->m_unk6C = Sys.m_unk5E0;
}

// FUNCTION: GAME 0x1615F0
extern "C" void func_001615F0(sSubScrWork *self)
{
    Sys.m_unk5D8 = self->m_unk68;
    Sys.m_unk5E0 = self->m_unk6C;
}

// FUNCTION: GAME 0x1646B0
extern "C" void func_001646B0(sVec3i *self, int a, int b, int c)
{
    self->m_a = a;
    self->m_b = b;
    self->m_c = c;
}

// FUNCTION: GAME 0x16F640
extern "C" void func_0016F640(char *self, char v)
{
    self[0x54] = v;
}

extern "C" void func_001614D0(void *self);
extern "C" void func_001661D8(void *self);

struct sFlagWork {
    char _pad0[0x5A];
    unsigned char m_unk5A;
    unsigned char m_unk5B;
    unsigned char m_unk5C;
    unsigned char m_unk5D;
};

// FUNCTION: GAME 0x161970
extern "C" void func_00161970(cIDBase *self)
{
    self->trans();
}

// FUNCTION: GAME 0x162278
extern "C" void func_00162278(cIDBase *self)
{
    self->trans();
}

// FUNCTION: GAME 0x1682A8
extern "C" void func_001682A8(cIDBase *self)
{
    self->trans();
}

// FUNCTION: GAME 0x161BB0
extern "C" void func_00161BB0(void *self)
{
    func_001614D0(self);
}

// FUNCTION: GAME 0x166618
extern "C" void func_00166618(void *self)
{
    func_001614D0(self);
}

// FUNCTION: GAME 0x1673B0
extern "C" void func_001673B0(void *self)
{
    func_001614D0(self);
}

// FUNCTION: GAME 0x1627A0
extern "C" void func_001627A0(sFlagWork *self)
{
    func_001614D0(self);
    self->m_unk5A = 0;
    self->m_unk5B = 0;
    self->m_unk5C = 0;
    self->m_unk5D = 0;
}

// FUNCTION: GAME 0x168528
extern "C" void func_00168528(sFlagWork *self)
{
    func_001614D0(self);
    self->m_unk5A = 0;
    self->m_unk5B = 0;
    self->m_unk5C = 0;
    self->m_unk5D = 0;
}

// FUNCTION: GAME 0x16C238
extern "C" void func_0016C238(char *self)
{
    func_001614D0(self);
    *(int *)(self + 0x264) = 0;
}

// FUNCTION: GAME 0x165E88
extern "C" void func_00165E88(cIDBase *self)
{
    func_001661D8(self);
    self->trans();
}

extern "C" void func_0016B1F8(void *self, int v);
extern "C" void func_0015FF10(void *self);
extern "C" void func_001C29D0(void *self);
extern "C" void func_001FC6C8(void *);
extern "C" int SdeSystemOutModeSet(int);
extern int D_005FEC68;
extern char CoreSave[];
extern unsigned char D_005E85F8;

// FUNCTION: GAME 0x16BC78
extern "C" void func_0016BC78(void *self)
{
    func_0016B1F8(self, D_005FEC68);
}

// FUNCTION: GAME 0x16BCA0
extern "C" void func_0016BCA0(char *self)
{
    func_0016B1F8(self, *(short *)(self + 0x202));
}

// FUNCTION: GAME 0x16BCC0
extern "C" void func_0016BCC0(char *self)
{
    func_0016B1F8(self, *(short *)(self + 0x204));
}

// FUNCTION: GAME 0x1612A8
extern "C" void func_001612A8(void *self)
{
    func_0015FF10(self);
}

// FUNCTION: GAME 0x16F5E8
extern "C" void func_0016F5E8(void *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x16F8E0
extern "C" void func_0016F8E0(void *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x16FBD8
extern "C" void func_0016FBD8(void *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x16FE48
extern "C" void func_0016FE48(void *self)
{
    func_001C29D0(self);
}

// FUNCTION: GAME 0x1672F0
extern "C" void func_001672F0()
{
    func_001FC6C8(CoreSave);
    SdeSystemOutModeSet(1);
    D_005E85F8 = 1;
}

// FUNCTION: GAME 0x167EB0
extern "C" void func_00167EB0()
{
    func_001FC6C8(CoreSave);
    SdeSystemOutModeSet(1);
    D_005E85F8 = 1;
}

extern int D_00460D38;
extern const char D_0041F1D0[];
extern "C" void func_0031EEC8(void *, const char *);

// FUNCTION: GAME 0x161628
extern "C" int *func_00161628()
{
    if (!D_00460D38)
        func_0031EEC8(&D_00460D38, D_0041F1D0);
    return &D_00460D38;
}
