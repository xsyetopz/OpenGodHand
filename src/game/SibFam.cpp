// Lazy type_info accessors sharing the TYPEINFO_FN skeleton (0x100328 family).

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

extern sTypeInfo D_00460D40;
extern sTypeInfo D_00785878;
extern sTypeInfo D_00786098;
extern sTypeInfo D_00786168;
extern sTypeInfo D_00786178;
extern sTypeInfo D_00786188;
extern sTypeInfo D_007861C8;
extern sTypeInfo D_007861D8;
extern sTypeInfo D_007861E8;
extern sTypeInfo D_007861F8;
extern sTypeInfo D_00786208;
extern sTypeInfo D_00786218;
extern sTypeInfo D_00786228;
extern sTypeInfo D_00786238;
extern sTypeInfo D_00786248;
extern sTypeInfo __ti8cGameObj;
extern char D_00428638[];
extern char D_00429F78[];
extern char D_0042AB48[];
extern char D_0042C300[];
extern char D_00447AB8[];
extern char D_00447B70[];
extern char D_00447C90[];
extern char D_00447E38[];
extern char D_00447F58[];
extern char D_00448010[];
extern char D_004480C8[];
extern char D_00448298[];
sTypeInfo *__tf8cGameObj();
sTypeInfo *func_001B8058();
sTypeInfo *func_001F7C88();
sTypeInfo *func_0028FDD0();

// FUNCTION: GAME 0x1B3680
TYPEINFO_FN(func_001B3680, D_00786098, func_001B8058, D_00428638, D_00785878)

// FUNCTION: GAME 0x1C90E8
TYPEINFO_FN(func_001C90E8, D_00786168, func_001B8058, D_00429F78, D_00785878)

// FUNCTION: GAME 0x1D0C28
TYPEINFO_FN(__tf9cOmWeapon, D_00786178, func_001B8058, D_0042AB48, D_00785878)

// FUNCTION: GAME 0x1F7B88
TYPEINFO_FN(func_001F7B88, D_00786188, func_001F7C88, D_0042C300, D_00460D40)

// FUNCTION: GAME 0x276790
TYPEINFO_FN(func_00276790, D_007861C8, func_0028FDD0, D_00447AB8, D_007861D8)

// FUNCTION: GAME 0x277238
TYPEINFO_FN(func_00277238, D_007861E8, __tf8cGameObj, D_00447B70, __ti8cGameObj)

// FUNCTION: GAME 0x278018
TYPEINFO_FN(func_00278018, D_007861F8, func_0028FDD0, D_00447C90, D_007861D8)

// FUNCTION: GAME 0x279C98
TYPEINFO_FN(func_00279C98, D_00786208, func_0028FDD0, D_00447E38, D_007861D8)

// FUNCTION: GAME 0x27A130
TYPEINFO_FN(func_0027A130, D_00786218, func_0028FDD0, D_00447F58, D_007861D8)

// FUNCTION: GAME 0x27AC00
TYPEINFO_FN(func_0027AC00, D_00786228, __tf8cGameObj, D_00448010, __ti8cGameObj)

// FUNCTION: GAME 0x27B6F8
TYPEINFO_FN(func_0027B6F8, D_00786238, __tf8cGameObj, D_004480C8, __ti8cGameObj)

// FUNCTION: GAME 0x27DD38
TYPEINFO_FN(func_0027DD38, D_00786248, func_0028FDD0, D_00448298, D_007861D8)

}
