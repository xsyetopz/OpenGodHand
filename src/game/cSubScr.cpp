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

struct sIDSysInner {
    char _pad0[0x48];
    int m_unk48;
    int m_unk4C;
};

struct sIDSys {
    sIDSysInner *m_inner;
};

extern sIDSys *IDSys;
extern "C" void func_00161590(void *self);

// FUNCTION: GAME 0x161780
extern "C" void func_00161780(cIDBase *self)
{
    func_001615F0((sSubScrWork *)self);
    self->release();
    sIDSysInner *in = IDSys->m_inner;
    in->m_unk4C = 0;
    in->m_unk48 = 0;
    func_00161590(self);
}

extern "C" void func_0031EEA8(void *, const char *, void *);

struct sIDSysInner161CC0 {
    char _pad0[0x30];
    int m_unk30;
    int m_unk34;
};

struct sIDSys161CC0 {
    sIDSysInner161CC0 *m_inner;
};

// FUNCTION: GAME 0x161CC0
extern "C" void func_00161CC0(cIDBase *self)
{
    func_001615F0((sSubScrWork *)self);
    self->release();
    sIDSysInner161CC0 *in = ((sIDSys161CC0 *)IDSys)->m_inner;
    in->m_unk34 = 0;
    in->m_unk30 = 0;
    func_00161590(self);
}

struct sIDSysInner1632A0 {
    char _pad0[0x20];
    int m_unk20;
    int m_unk24;
};

struct sIDSys1632A0 {
    sIDSysInner1632A0 *m_inner;
};

// FUNCTION: GAME 0x1632A0
extern "C" void func_001632A0(cIDBase *self)
{
    func_001615F0((sSubScrWork *)self);
    self->release();
    sIDSysInner1632A0 *in = ((sIDSys1632A0 *)IDSys)->m_inner;
    in->m_unk24 = 0;
    in->m_unk20 = 0;
    func_00161590(self);
}

struct sIDSysInner1655D8 {
    char _pad0[0x20];
    int m_unk20;
    int m_unk24;
};

struct sIDSys1655D8 {
    sIDSysInner1655D8 *m_inner;
};

// FUNCTION: GAME 0x1655D8
extern "C" void func_001655D8(cIDBase *self)
{
    func_001615F0((sSubScrWork *)self);
    ((cIDBase *)((char *)self + 0x230))->release();
    ((cIDBase *)((char *)self + 0x100))->release();
    self->release();
    ((cIDBase *)((char *)self + 0x180))->release();
    sIDSysInner1655D8 *in = ((sIDSys1655D8 *)IDSys)->m_inner;
    in->m_unk24 = 0;
    in->m_unk20 = 0;
    func_00161590(self);
}

struct sIDSysInner166730 {
    char _pad0[0x40];
    int m_unk40;
    int m_unk44;
};

struct sIDSys166730 {
    sIDSysInner166730 *m_inner;
};

// FUNCTION: GAME 0x166730
extern "C" void func_00166730(cIDBase *self)
{
    func_001615F0((sSubScrWork *)self);
    ((cIDBase *)((char *)self + 0xE0))->release();
    self->release();
    sIDSysInner166730 *in = ((sIDSys166730 *)IDSys)->m_inner;
    in->m_unk44 = 0;
    in->m_unk40 = 0;
    func_00161590(self);
}

struct sIDSysInner1674C8 {
    char _pad0[0x40];
    int m_unk40;
    int m_unk44;
};

struct sIDSys1674C8 {
    sIDSysInner1674C8 *m_inner;
};

// FUNCTION: GAME 0x1674C8
extern "C" void func_001674C8(cIDBase *self)
{
    func_001615F0((sSubScrWork *)self);
    ((cIDBase *)((char *)self + 0xC0))->release();
    self->release();
    sIDSysInner1674C8 *in = ((sIDSys1674C8 *)IDSys)->m_inner;
    in->m_unk44 = 0;
    in->m_unk40 = 0;
    func_00161590(self);
}

extern int D_007856F8;
extern const char D_0041F240[];

// FUNCTION: GAME 0x161B60
extern "C" int *func_00161B60()
{
    if (!D_007856F8) {
        func_00161628();
        func_0031EEA8(&D_007856F8, D_0041F240, &D_00460D38);
    }
    return &D_007856F8;
}

extern int D_00785708;
extern const char D_0041F3C8[];

// FUNCTION: GAME 0x162750
extern "C" int *func_00162750()
{
    if (!D_00785708) {
        func_00161628();
        func_0031EEA8(&D_00785708, D_0041F3C8, &D_00460D38);
    }
    return &D_00785708;
}

extern int D_00785718;
extern const char D_0041F620[];

// FUNCTION: GAME 0x164E88
extern "C" int *func_00164E88()
{
    if (!D_00785718) {
        func_00161628();
        func_0031EEA8(&D_00785718, D_0041F620, &D_00460D38);
    }
    return &D_00785718;
}

extern int D_00785728;
extern const char D_0041F708[];

// FUNCTION: GAME 0x1665C8
extern "C" int *func_001665C8()
{
    if (!D_00785728) {
        func_00161628();
        func_0031EEA8(&D_00785728, D_0041F708, &D_00460D38);
    }
    return &D_00785728;
}

extern int D_00785738;
extern const char D_0041FB60[];

// FUNCTION: GAME 0x167360
extern "C" int *func_00167360()
{
    if (!D_00785738) {
        func_00161628();
        func_0031EEA8(&D_00785738, D_0041FB60, &D_00460D38);
    }
    return &D_00785738;
}

extern int D_00785748;
extern const char D_0041FC28[];

// FUNCTION: GAME 0x167F20
extern "C" int *func_00167F20()
{
    if (!D_00785748) {
        func_00161628();
        func_0031EEA8(&D_00785748, D_0041FC28, &D_00460D38);
    }
    return &D_00785748;
}

extern int D_00785758;
extern const char D_0041FCA0[];

// FUNCTION: GAME 0x1684D8
extern "C" int *func_001684D8()
{
    if (!D_00785758) {
        func_00161628();
        func_0031EEA8(&D_00785758, D_0041FCA0, &D_00460D38);
    }
    return &D_00785758;
}

extern int D_00785768;
extern const char D_0041FE38[];

// FUNCTION: GAME 0x16C1E8
extern "C" int *func_0016C1E8()
{
    if (!D_00785768) {
        func_00161628();
        func_0031EEA8(&D_00785768, D_0041FE38, &D_00460D38);
    }
    return &D_00785768;
}

extern int D_00785778;
extern const char D_0041FF70[];

// FUNCTION: GAME 0x16F350
extern "C" int *func_0016F350()
{
    if (!D_00785778) {
        func_00161628();
        func_0031EEA8(&D_00785778, D_0041FF70, &D_00460D38);
    }
    return &D_00785778;
}
