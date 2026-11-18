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

extern sTypeInfo __ti8cGameObj;
extern char D_0041B638[];
sTypeInfo *__tf8cGameObj();
extern sTypeInfo D_007855E8;
extern char D_0041DF10[];
extern sTypeInfo D_007855F8;
extern char D_0041DF98[];
extern sTypeInfo D_00785608;
extern char D_0041DFE8[];
extern sTypeInfo D_00785618;
extern char D_0041E070[];
extern sTypeInfo D_00785628;
extern char D_0041E0D8[];
extern sTypeInfo D_00785638;
extern char D_0041E128[];
extern sTypeInfo D_00785648;
extern char D_0041E170[];
extern sTypeInfo D_00785658;
extern char D_0041E580[];
extern sTypeInfo D_00785668;
extern char D_0041E658[];
extern sTypeInfo D_00785678;
extern char D_0041E6A0[];
extern sTypeInfo D_00785688;
extern char D_0041E700[];
extern sTypeInfo D_00785698;
extern char D_0041E830[];
extern sTypeInfo D_007856A8;
extern char D_0041E8F8[];
extern sTypeInfo D_007856B8;
extern char D_0041E948[];
extern sTypeInfo D_007856C8;
extern char D_0041E9F0[];
extern sTypeInfo D_00785788;
extern sTypeInfo D_00785798;
extern char D_00420140[];
sTypeInfo *func_001C3BE8();
extern sTypeInfo D_007857A8;
extern char D_00420228[];
extern sTypeInfo D_007857B8;
extern char D_00420310[];
extern sTypeInfo D_007857C8;
extern char D_004203F8[];
extern sTypeInfo D_00785868;
extern sTypeInfo D_00785878;
extern char D_00420D50[];
sTypeInfo *func_001B8058();

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

// FUNCTION: GAME 0x100328
TYPEINFO_FN(__tf7cPlBase, __ti7cPlBase, __tf8cGameObj, D_0041B638, __ti8cGameObj)

// FUNCTION: GAME 0x13D368
TYPEINFO_FN(func_0013D368, D_007855E8, func_0013C758, D_0041DF10, D_00460D28)

// FUNCTION: GAME 0x13DF20
TYPEINFO_FN(func_0013DF20, D_007855F8, func_0013C758, D_0041DF98, D_00460D28)

// FUNCTION: GAME 0x13E330
TYPEINFO_FN(func_0013E330, D_00785608, func_0013C758, D_0041DFE8, D_00460D28)

// FUNCTION: GAME 0x13E780
TYPEINFO_FN(func_0013E780, D_00785618, func_0013C758, D_0041E070, D_00460D28)

// FUNCTION: GAME 0x13EC80
TYPEINFO_FN(func_0013EC80, D_00785628, func_0013C758, D_0041E0D8, D_00460D28)

// FUNCTION: GAME 0x13F0C0
TYPEINFO_FN(func_0013F0C0, D_00785638, func_0013C758, D_0041E128, D_00460D28)

// FUNCTION: GAME 0x13F2A0
TYPEINFO_FN(func_0013F2A0, D_00785648, func_0013C758, D_0041E170, D_00460D28)

// FUNCTION: GAME 0x140B88
TYPEINFO_FN(func_00140B88, D_00785658, func_0013C758, D_0041E580, D_00460D28)

// FUNCTION: GAME 0x143500
TYPEINFO_FN(func_00143500, D_00785668, func_0013C758, D_0041E658, D_00460D28)

// FUNCTION: GAME 0x143B20
TYPEINFO_FN(func_00143B20, D_00785678, func_0013C758, D_0041E6A0, D_00460D28)

// FUNCTION: GAME 0x144B00
TYPEINFO_FN(func_00144B00, D_00785688, func_0013C758, D_0041E700, D_00460D28)

// FUNCTION: GAME 0x146778
TYPEINFO_FN(func_00146778, D_00785698, func_0013C758, D_0041E830, D_00460D28)

// FUNCTION: GAME 0x146EA0
TYPEINFO_FN(func_00146EA0, D_007856A8, func_0013C758, D_0041E8F8, D_00460D28)

// FUNCTION: GAME 0x146FC8
TYPEINFO_FN(func_00146FC8, D_007856B8, func_0013C758, D_0041E948, D_00460D28)

// FUNCTION: GAME 0x1474D0
TYPEINFO_FN(func_001474D0, D_007856C8, func_0013C758, D_0041E9F0, D_00460D28)

// FUNCTION: GAME 0x16F648
TYPEINFO_FN(func_0016F648, D_00785788, func_001C3BE8, D_00420140, D_00785798)

// FUNCTION: GAME 0x16F938
TYPEINFO_FN(func_0016F938, D_007857A8, func_001C3BE8, D_00420228, D_00785798)

// FUNCTION: GAME 0x16FC30
TYPEINFO_FN(func_0016FC30, D_007857B8, func_001C3BE8, D_00420310, D_00785798)

// FUNCTION: GAME 0x16FF18
TYPEINFO_FN(func_0016FF18, D_007857C8, func_001C3BE8, D_004203F8, D_00785798)

// FUNCTION: GAME 0x171AB8
TYPEINFO_FN(func_00171AB8, D_00785868, func_001B8058, D_00420D50, D_00785878)

} // extern "C"
