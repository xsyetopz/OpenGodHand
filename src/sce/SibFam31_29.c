// COMPILER: ee-gcc2.9-991111
// Lazy-initialised singleton getters sharing the 0x3218F8 skeleton.

extern int D_00460DA0;
extern char D_004510B0[];
void func_0031EEC8(void *, char *);

// FUNCTION: GAME 0x31F4A0
int *func_0031F4A0(void)
{
    if (!D_00460DA0)
        func_0031EEC8(&D_00460DA0, D_004510B0);
    return &D_00460DA0;
}

void func_0031EEA8(void *, char *, void *);
extern char D_00451048[];
extern char D_00451060[];
extern char D_00451078[];
extern char D_00451090[];
extern char D_004510A0[];
extern char D_004511C8[];
extern char D_004511E0[];
extern char D_004511F8[];
extern char D_00451210[];
extern char D_00451228[];
extern char D_00451240[];
extern char D_00451258[];
extern int D_00460DA0;
extern int D_00460DA8;
extern int D_00786638;
extern int D_00786648;
extern int D_00786658;
extern int D_00786668;
extern int D_00786678;
extern int D_00786688;
extern int D_00786698;
extern int D_007866A8;
extern int D_007866B8;
extern int D_007866C8;
extern int D_007866D8;
extern int D_007866E8;
int *func_0031F2C0(void);
int *func_0031F4A0(void);
int *func_003218F8(void);

// FUNCTION: GAME 0x31F1A8
int *func_0031F1A8(void)
{
    if (!D_00786638) {
        func_0031F2C0();
        func_0031EEA8(&D_00786638, D_00451048, &D_00786648);
    }
    return &D_00786638;
}

// FUNCTION: GAME 0x31F238
int *func_0031F238(void)
{
    if (!D_00786658) {
        func_0031F2C0();
        func_0031EEA8(&D_00786658, D_00451060, &D_00786648);
    }
    return &D_00786658;
}

// FUNCTION: GAME 0x31F2C0
int *func_0031F2C0(void)
{
    if (!D_00786648) {
        func_0031F4A0();
        func_0031EEA8(&D_00786648, D_00451078, &D_00460DA0);
    }
    return &D_00786648;
}

// FUNCTION: GAME 0x31F378
int *func_0031F378(void)
{
    if (!D_00786668) {
        func_003218F8();
        func_0031EEA8(&D_00786668, D_00451090, &D_00460DA8);
    }
    return &D_00786668;
}

// FUNCTION: GAME 0x31F410
int *func_0031F410(void)
{
    if (!D_00786678) {
        func_003218F8();
        func_0031EEA8(&D_00786678, D_004510A0, &D_00460DA8);
    }
    return &D_00786678;
}

// FUNCTION: GAME 0x31FF50
int *func_0031FF50(void)
{
    if (!D_00786688) {
        func_0031F4A0();
        func_0031EEA8(&D_00786688, D_004511C8, &D_00460DA0);
    }
    return &D_00786688;
}

// FUNCTION: GAME 0x31FFC0
int *func_0031FFC0(void)
{
    if (!D_00786698) {
        func_0031F4A0();
        func_0031EEA8(&D_00786698, D_004511E0, &D_00460DA0);
    }
    return &D_00786698;
}

// FUNCTION: GAME 0x320030
int *func_00320030(void)
{
    if (!D_007866A8) {
        func_0031F4A0();
        func_0031EEA8(&D_007866A8, D_004511F8, &D_00460DA0);
    }
    return &D_007866A8;
}

// FUNCTION: GAME 0x3200A0
int *func_003200A0(void)
{
    if (!D_007866B8) {
        func_0031F4A0();
        func_0031EEA8(&D_007866B8, D_00451210, &D_00460DA0);
    }
    return &D_007866B8;
}

// FUNCTION: GAME 0x320110
int *func_00320110(void)
{
    if (!D_007866C8) {
        func_0031F4A0();
        func_0031EEA8(&D_007866C8, D_00451228, &D_00460DA0);
    }
    return &D_007866C8;
}

// FUNCTION: GAME 0x320180
int *func_00320180(void)
{
    if (!D_007866D8) {
        func_0031F4A0();
        func_0031EEA8(&D_007866D8, D_00451240, &D_00460DA0);
    }
    return &D_007866D8;
}

// FUNCTION: GAME 0x3201F0
int *func_003201F0(void)
{
    if (!D_007866E8) {
        func_0031F4A0();
        func_0031EEA8(&D_007866E8, D_00451258, &D_00460DA0);
    }
    return &D_007866E8;
}
