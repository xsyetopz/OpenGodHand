// Lazy type_info accessors (`__tf` functions) in 0x100000-0x13FFFF.
// Each builds its type_info once: base accessor, then func_0031EEA8(&ti, name, &base_ti).

extern "C" {

struct sTypeInfo {
    int m_unk0;
    int m_unk4;
    int m_unk8;
    int m_unkC;
};
void func_0031EEA8(sTypeInfo *, char *, void *);

#define TYPEINFO_FN(FN, TI, BASEFN, NAME, BASETI) \
    sTypeInfo *FN()                                \
    {                                              \
        if (!TI.m_unk0) {                          \
            BASEFN();                              \
            func_0031EEA8(&TI, NAME, &BASETI);     \
        }                                          \
        return &TI;                                \
    }

extern sTypeInfo D_007854E8;
extern sTypeInfo __ti8cObjBase;
extern sTypeInfo D_00785508;
extern sTypeInfo __ti7cPlBase;
extern sTypeInfo D_00785518;
extern sTypeInfo D_00785578;
extern sTypeInfo __ti7cCamera;
extern sTypeInfo D_00785588;
extern sTypeInfo D_00785598;
extern sTypeInfo D_007855A8;
extern sTypeInfo D_00460D28;
extern sTypeInfo D_007855B8;
extern sTypeInfo D_007855C8;
extern sTypeInfo D_007855D8;
extern char D_0041B710[];
extern char D_0041B7D0[];
extern char D_0041D2C0[];
extern char D_0041D920[];
extern char D_0041D950[];
extern char D_0041DBD8[];
extern char D_0041DC58[];
extern char D_0041DCB8[];
extern char D_0041DE80[];
extern char D_0041DEC8[];
sTypeInfo *__tf8cObjBase();
sTypeInfo *__tf7cPlBase();
sTypeInfo *__tf7cCamera();
sTypeInfo *func_0013C758();

// FUNCTION: GAME 0x101E48
TYPEINFO_FN(func_00101E48, D_007854E8, __tf8cObjBase, D_0041B710, __ti8cObjBase)

// FUNCTION: GAME 0x103880
TYPEINFO_FN(func_00103880, D_00785508, __tf7cPlBase, D_0041B7D0, __ti7cPlBase)

// FUNCTION: GAME 0x12CF08
TYPEINFO_FN(func_0012CF08, D_00785518, __tf7cPlBase, D_0041D2C0, __ti7cPlBase)

// FUNCTION: GAME 0x139820
TYPEINFO_FN(func_00139820, D_00785578, __tf7cCamera, D_0041D920, __ti7cCamera)

// FUNCTION: GAME 0x139B78
TYPEINFO_FN(func_00139B78, D_00785588, __tf7cCamera, D_0041D950, __ti7cCamera)

// FUNCTION: GAME 0x13BBD8
TYPEINFO_FN(func_0013BBD8, D_00785598, func_00139820, D_0041DBD8, D_00785578)

// FUNCTION: GAME 0x13C1C8
TYPEINFO_FN(func_0013C1C8, D_007855A8, func_0013C758, D_0041DC58, D_00460D28)

// FUNCTION: GAME 0x13C558
TYPEINFO_FN(func_0013C558, D_007855B8, func_0013C758, D_0041DCB8, D_00460D28)

// FUNCTION: GAME 0x13CFE0
TYPEINFO_FN(func_0013CFE0, D_007855C8, func_0013C758, D_0041DE80, D_00460D28)

// FUNCTION: GAME 0x13D180
TYPEINFO_FN(func_0013D180, D_007855D8, func_0013C758, D_0041DEC8, D_00460D28)

} // extern "C"
