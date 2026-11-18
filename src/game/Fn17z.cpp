// Small units in .text 0x180000-0x18FFFF (mode-table dispatchers).

class cFnZ;
typedef void (cFnZ::*cFnZPmf)();
class cFnZ {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
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
