// Small units in .text 0x180000-0x18FFFF (mode-table dispatchers).

class cFnZ;
typedef void (cFnZ::*cFnZPmf)();
class cFnZ {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
    unsigned char type2;
};
extern "C" {
int func_001B76B0(cFnZ *self);
void func_001B76D8(cFnZ *self);
void func_002A87E8(cFnZ *self, int a);
void func_001810A0(cFnZ *self);
}

extern cFnZPmf D_003BDAF8[];

// FUNCTION: GAME 0x180FD0
extern "C" void func_00180FD0(cFnZ *self)
{
    if (func_001B76B0(self)) {
        (self->*D_003BDAF8[self->type])();
        func_001810A0(self);
        func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

extern cFnZPmf D_003BDB38[];

// FUNCTION: GAME 0x1841E8
extern "C" void func_001841E8(cFnZ *self)
{
    if (func_001B76B0(self)) {
        (self->*D_003BDB38[self->type])();
        func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

extern "C" void setMeshDispFromLayer__7cOmBaseUib(void *, unsigned, int);
struct cCObjZ;
extern void *func_SetEffectZ(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
struct cSndZ {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cSndZ Snd;

#define FN18_MESH_SE(NAME, A, B, EFF)                                   \
    extern "C" void NAME(void *self, int mode)                          \
    {                                                                   \
        setMeshDispFromLayer__7cOmBaseUib(self, A, 0);                  \
        setMeshDispFromLayer__7cOmBaseUib(self, B, 0);                  \
        switch (mode) {                                                 \
        case 0:                                                         \
            setMeshDispFromLayer__7cOmBaseUib(self, A, 1);              \
            break;                                                      \
        case 1:                                                         \
            setMeshDispFromLayer__7cOmBaseUib(self, B, 1);              \
            break;                                                      \
        case 4:                                                         \
            EFF                                                         \
            break;                                                      \
        }                                                               \
    }

#define FN18_SE Snd.SeCall(2, 0x113, self, 0, 0, 0, 0);
#define FN18_FX(N) func_SetEffectZ(0x298, N, self, 0, -1, 0xFFFFFFFF);

// FUNCTION: GAME 0x185BD0
FN18_MESH_SE(func_00185BD0, 0x28, 0x29, FN18_SE FN18_FX(4))
// FUNCTION: GAME 0x1855A8
FN18_MESH_SE(func_001855A8, 0x1E, 0x1F, FN18_FX(3) FN18_SE)
// FUNCTION: GAME 0x185E68
FN18_MESH_SE(func_00185E68, 0x32, 0x33, FN18_FX(2) FN18_SE)
// FUNCTION: GAME 0x185F50
FN18_MESH_SE(func_00185F50, 0x2E, 0x2F, FN18_FX(6) FN18_SE)

// Round 28: damage-record destructor and hit-check dispatcher.
extern char g_DmgManage[];
extern char g_CollScr[];
extern char EspSys[];
extern char g_CollSolidManage[];
extern const char D_00424B68[];
extern cFnZPmf D_003BDB48[];
extern "C" {
void func_001FE278(void *mgr, void *p);
void ReleaseDamageGive__13cDamageManageP11cDamageGive(void *mgr, void *p);
void func_0012EC58(void *scr, void *p);
void effDataRelease__6espSys12eEffDataType(void *sys, int t);
void func_001B6F38(void *self, int flag);
void ChkHit__21cCollisionSolidManageP8cGameObj(void *mgr, void *obj);
}

// FUNCTION: GAME 0x193FD8
extern "C" void func_00193FD8(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00424B68;
    void *d = *(void **)(self + 0x604);
    if (d) {
        func_001FE278(g_DmgManage, d);
        *(void **)(self + 0x604) = 0;
    }
    void *g = *(void **)(self + 0x608);
    if (g) {
        ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, g);
        *(void **)(self + 0x608) = 0;
    }
    void *c = *(void **)(self + 0x614);
    if (c) {
        func_0012EC58(g_CollScr, c);
        *(void **)(self + 0x614) = 0;
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x177);
    func_001B6F38(self, flag);
}

// FUNCTION: GAME 0x194480
extern "C" void func_00194480(cFnZ *self)
{
    if (func_001B76B0(self)) {
        (self->*D_003BDB48[self->type])();
        ChkHit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
        func_001B76D8(self);
    }
}

// Dispatchers that copy a 3- or 4-entry method-pointer table to the stack before the call.
struct cFnZTab3 { cFnZPmf p[3]; };
struct cFnZTab4 { cFnZPmf p[4]; };
extern const char D_00424B30[];
extern const char D_004235D0[];
extern "C" void func_00194558(cFnZ *self);

// FUNCTION: GAME 0x1946E0
extern "C" void func_001946E0(cFnZ *self)
{
    cFnZTab3 t = *(const cFnZTab3 *)D_00424B30;
    (self->*t.p[self->type2])();
    func_00194558(self);
}

// FUNCTION: GAME 0x1895D8
extern "C" void func_001895D8(cFnZ *self)
{
    if (func_001B76B0(self)) {
        cFnZTab4 t = *(const cFnZTab4 *)D_004235D0;
        (self->*t.p[self->type])();
        func_001B76D8(self);
    }
}

extern const char D_004236E0[];
extern const char D_00424308[];
extern const char D_00423E10[];

// FUNCTION: GAME 0x18A870
extern "C" void func_0018A870(cFnZ *self)
{
    if (func_001B76B0(self)) {
        cFnZTab4 t = *(const cFnZTab4 *)D_004236E0;
        (self->*t.p[self->type])();
        func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

// FUNCTION: GAME 0x192458
extern "C" void func_00192458(cFnZ *self)
{
    if (func_001B76B0(self)) {
        short *tm = (short *)((char *)self + 0x602);
        if (*tm)
            (*tm)--;
        cFnZTab4 t = *(const cFnZTab4 *)D_00424308;
        (self->*t.p[self->type])();
        func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

// FUNCTION: GAME 0x187FE8
extern const char D_00423318[];
extern "C" void func_00187FE8(cFnZ *self)
{
    if (func_001B76B0(self)) {
        short *tm = (short *)((char *)self + 0x602);
        if (*tm)
            (*tm)--;
        cFnZTab4 t = *(const cFnZTab4 *)D_00423318;
        (self->*t.p[self->type])();
        func_002A87E8(self, 0);
        func_001B76D8(self);
    }
}

extern "C" void func_001C7E30(cFnZ *self);

// FUNCTION: GAME 0x18F488
extern "C" void func_0018F488(cFnZ *self)
{
    if (func_001B76B0(self)) {
        long f = (unsigned)*(int *)((char *)self + 0x5B0);
        long hit = (f >> 2) & 1;
        if (!hit) {
            cFnZTab4 t = *(const cFnZTab4 *)D_00423E10;
            (self->*t.p[self->type])();
            f = (unsigned)*(int *)((char *)self + 0x5B0);
            hit = (f >> 1) & 1;
            if (!hit) {
                func_002A87E8(self, 0);
            }
            func_001B76D8(self);
        } else {
            func_001C7E30(self);
        }
    }
}
