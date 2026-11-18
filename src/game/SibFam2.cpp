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
extern sTypeInfo D_00460D58;
extern sTypeInfo D_00460D68;
extern sTypeInfo D_00460D70;
extern sTypeInfo D_007861D8;
extern sTypeInfo D_00786258;
extern sTypeInfo D_00786268;
extern sTypeInfo D_00786278;
extern sTypeInfo D_00786288;
extern sTypeInfo D_00786298;
extern sTypeInfo D_007862A8;
extern sTypeInfo D_007862B8;
extern sTypeInfo D_007862C8;
extern sTypeInfo D_007862D8;
extern sTypeInfo D_007862E8;
extern sTypeInfo D_007862F8;
extern sTypeInfo D_00786308;
extern sTypeInfo D_00786318;
extern sTypeInfo D_00786328;
extern sTypeInfo D_00786338;
extern sTypeInfo D_00786348;
extern sTypeInfo D_00786358;
extern sTypeInfo D_00786368;
extern sTypeInfo D_00786378;
extern sTypeInfo D_00786398;
extern sTypeInfo D_00786598;
extern sTypeInfo D_007865A8;
extern sTypeInfo D_00786608;
extern sTypeInfo D_00786618;
extern sTypeInfo D_00786628;
extern sTypeInfo __ti4cObj;
extern sTypeInfo __ti8cGameObj;
extern sTypeInfo __ti8cObjBase;
extern char D_00448498[];
extern char D_00448688[];
extern char D_00448878[];
extern char D_00448930[];
extern char D_004489E8[];
extern char D_00448D90[];
extern char D_00448F10[];
extern char D_0044A4F8[];
extern char D_0044A618[];
extern char D_0044A750[];
extern char D_0044AEC8[];
extern char D_0044B598[];
extern char D_0044B8B0[];
extern char D_0044BDC0[];
extern char D_0044BDD8[];
extern char D_0044BDF8[];
extern char D_0044BE18[];
extern char D_0044BE30[];
extern char D_0044BE48[];
extern char D_0044BE60[];
extern char D_0044BE80[];
extern char D_0044CF00[];
extern char D_0044FBA8[];
extern char D_0044FDB8[];
extern char D_00450C18[];
extern char D_00450CA8[];
extern char D_00450D58[];
sTypeInfo *__tf4cObj();
sTypeInfo *__tf8cGameObj();
sTypeInfo *__tf8cObjBase();
sTypeInfo *func_001F7C88();
sTypeInfo *func_0028FDD0();
sTypeInfo *func_002B6528();
sTypeInfo *func_002BAFA0();
sTypeInfo *func_003BAFF8();

// FUNCTION: GAME 0x27EE18
TYPEINFO_FN(func_0027EE18, D_00786258, func_0028FDD0, D_00448498, D_007861D8)

// FUNCTION: GAME 0x2815E8
TYPEINFO_FN(func_002815E8, D_00786268, func_0028FDD0, D_00448688, D_007861D8)

// FUNCTION: GAME 0x283498
TYPEINFO_FN(func_00283498, D_00786278, func_0028FDD0, D_00448878, D_007861D8)

// FUNCTION: GAME 0x283E58
TYPEINFO_FN(func_00283E58, D_00786288, __tf8cGameObj, D_00448930, __ti8cGameObj)

// FUNCTION: GAME 0x2849B8
TYPEINFO_FN(func_002849B8, D_00786298, __tf8cGameObj, D_004489E8, __ti8cGameObj)

// FUNCTION: GAME 0x2896D8
TYPEINFO_FN(func_002896D8, D_007862A8, func_0028FDD0, D_00448D90, D_007861D8)

// FUNCTION: GAME 0x28B0A0
TYPEINFO_FN(func_0028B0A0, D_007862B8, func_0028FDD0, D_00448F10, D_007861D8)

// FUNCTION: GAME 0x28DFC8
TYPEINFO_FN(func_0028DFC8, D_007862C8, func_0028FDD0, D_0044A4F8, D_007861D8)

// FUNCTION: GAME 0x28EAB0
TYPEINFO_FN(func_0028EAB0, D_007862D8, func_0028FDD0, D_0044A618, D_007861D8)

// FUNCTION: GAME 0x28FDD0
TYPEINFO_FN(func_0028FDD0, D_007861D8, __tf8cGameObj, D_0044A750, __ti8cGameObj)

// FUNCTION: GAME 0x2A9300
TYPEINFO_FN(__tf8cGameObj, __ti8cGameObj, __tf8cObjBase, D_0044AEC8, __ti8cObjBase)

// FUNCTION: GAME 0x2B8340
TYPEINFO_FN(func_002B8340, D_007862E8, __tf8cObjBase, D_0044B598, __ti8cObjBase)

// FUNCTION: GAME 0x2B8928
TYPEINFO_FN(func_002B8928, D_007862F8, __tf8cObjBase, D_0044B8B0, __ti8cObjBase)

// FUNCTION: GAME 0x2BA4E8
TYPEINFO_FN(func_002BA4E8, D_00786308, func_002BAFA0, D_0044BDC0, D_00460D68)

// FUNCTION: GAME 0x2BA590
TYPEINFO_FN(func_002BA590, D_00786318, func_002BAFA0, D_0044BDD8, D_00460D68)

// FUNCTION: GAME 0x2BA6F8
TYPEINFO_FN(func_002BA6F8, D_00786328, func_002BAFA0, D_0044BDF8, D_00460D68)

// FUNCTION: GAME 0x2BA828
TYPEINFO_FN(func_002BA828, D_00786338, func_002BAFA0, D_0044BE18, D_00460D68)

// FUNCTION: GAME 0x2BA8E0
TYPEINFO_FN(func_002BA8E0, D_00786348, func_002BAFA0, D_0044BE30, D_00460D68)

// FUNCTION: GAME 0x2BA948
TYPEINFO_FN(func_002BA948, D_00786358, func_002BAFA0, D_0044BE48, D_00460D68)

// FUNCTION: GAME 0x2BAA40
TYPEINFO_FN(func_002BAA40, D_00786368, func_002BAFA0, D_0044BE60, D_00460D68)

// FUNCTION: GAME 0x2BACF0
TYPEINFO_FN(func_002BACF0, D_00786378, func_001F7C88, D_0044BE80, D_00460D40)

// FUNCTION: GAME 0x2CD5C0
TYPEINFO_FN(func_002CD5C0, D_00786398, func_003BAFF8, D_0044CF00, D_00460D70)

// FUNCTION: GAME 0x3000F8
TYPEINFO_FN(func_003000F8, D_00786598, func_002B6528, D_0044FBA8, D_00460D58)

// FUNCTION: GAME 0x304E38
TYPEINFO_FN(func_00304E38, D_007865A8, func_002B6528, D_0044FDB8, D_00460D58)

// FUNCTION: GAME 0x3183C8
TYPEINFO_FN(func_003183C8, D_00786608, __tf8cObjBase, D_00450C18, __ti8cObjBase)

// FUNCTION: GAME 0x318788
TYPEINFO_FN(func_00318788, D_00786618, __tf8cObjBase, D_00450CA8, __ti8cObjBase)

// FUNCTION: GAME 0x319FC8
TYPEINFO_FN(func_00319FC8, D_00786628, __tf4cObj, D_00450D58, __ti4cObj)

}
