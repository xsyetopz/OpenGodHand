// COMPILER: ee-gcc2.96
// FLAGS: -O2
// SCE helpers in 0x328098-0x330000 compiled with 2.96.
extern int func_00329070();
extern int func_00329088();
extern int func_00328CD8();
extern int func_00333CE0();
extern void func_0033F130();
extern int func_003277E8();
extern int func_00327788();
extern int func_003277A0();
extern int func_00327950();
extern int func_0033E6A8();
extern int func_0033E6B0();
extern int func_0032A880();
extern char D_004520D8[], D_004524D0[], D_00452108[], D_00452138[], D_00452198[], D_00452228[];

// FUNCTION: GAME 0x328C80
int func_00328C80(int a, int b, int c)
{
    int r;
    func_00329070();
    r = func_00328CD8(a, b, c);
    func_00329088();
    return r;
}

// FUNCTION: GAME 0x32A4E0
int func_0032A4E0(char *o)
{
    if (!o) {
        func_0033F130(D_004520D8);
        return -1;
    }
    if (o[1] >= 2)
        return func_003277E8(*(int *)(o + 4));
    return 0;
}

// FUNCTION: GAME 0x32B0E8
int func_0032B0E8(char *o)
{
    if (!o) {
        func_0033F130(D_004524D0);
        return -1;
    }
    return *(short *)(o + 0x60);
}

// FUNCTION: GAME 0x32A568
int func_0032A568(char *o)
{
    if (!o) {
        func_0033F130(D_00452108);
        return -1;
    }
    if (o[1] >= 2)
        return func_00327788(*(int *)(o + 4));
    return 0;
}

// FUNCTION: GAME 0x32A5F0
int func_0032A5F0(char *o)
{
    if (!o) {
        func_0033F130(D_00452138);
        return -1;
    }
    if (o[1] >= 2)
        return func_003277A0(*(int *)(o + 4));
    return 0;
}

// FUNCTION: GAME 0x32A680
int func_0032A680(char *o)
{
    if (!o) {
        func_0033F130(D_00452198);
        return -1;
    }
    if (o[1] >= 2)
        return func_00327950(*(int *)(o + 4));
    return 0;
}

// FUNCTION: GAME 0x32A838
int func_0032A838(int a, int b)
{
    int r;
    func_0033E6A8();
    r = func_0032A880(a, b);
    func_0033E6B0();
    return r;
}

// FUNCTION: GAME 0x32A880
int func_0032A880(char *o, int i)
{
    if (!o) {
        func_0033F130(D_00452228);
        return 0;
    }
    return *(short *)(o + i * 2 + 0x42);
}
extern int func_0032B530();
extern int func_0032B888();
extern void func_0032BB98();
extern int func_00327710();
extern char D_00452500[], D_00452688[];

// FUNCTION: GAME 0x32B148
void func_0032B148(char *o)
{
    if (!o) {
        func_0033F130(D_00452500);
        return;
    }
    *(short *)(o + 0x60) = 0;
    *(int *)(o + 0x64) = 0;
    *(short *)(o + 0x68) = 0;
    *(short *)(o + 0x6A) = 0;
}

// FUNCTION: GAME 0x32B4E8
int func_0032B4E8(int a, int b)
{
    int r;
    func_0033E6A8();
    r = func_0032B530(a, b);
    func_0033E6B0();
    return r;
}

// FUNCTION: GAME 0x32B718
int func_0032B718(char *o)
{
    if (!o) {
        func_0033F130(D_00452688);
        return -1;
    }
    return func_00327710(*(int *)(o + 4));
}

// FUNCTION: GAME 0x32B830
int func_0032B830(int a, int b, int c)
{
    int r;
    func_0033E6A8();
    r = func_0032B888(a, b, c);
    func_0033E6B0();
    return r;
}

// FUNCTION: GAME 0x32BB48
void func_0032BB48(int a, int b, int c)
{
    func_0033E6A8();
    func_0032BB98(a, b, c);
    func_0033E6B0();
}

extern void adxt_StartMemIdx();
extern void func_0033FCA0();
extern void func_0033FCA8();
extern void func_0033FCB0();
extern void func_0032DA08();
extern void func_0032DA78();
extern int func_0032DD18();
extern void func_0032DE38(char *, float);
extern char D_00452B98[], D_00452BC0[];

// FUNCTION: GAME 0x32BDC0
void func_0032BDC0(int a, int b, int c)
{
    func_0033E6A8();
    adxt_StartMemIdx(a, b, c);
    func_0033E6B0();
}

// FUNCTION: GAME 0x32D9B8
void func_0032D9B8(int a, int b, int c)
{
    func_0033FCA0();
    func_0032DA08(a, b, c);
    func_0033FCA8();
}

// FUNCTION: GAME 0x32DA28
void func_0032DA28(int a, int b, int c)
{
    func_0033FCA0();
    func_0032DA78(a, b, c);
    func_0033FCA8();
}

// FUNCTION: GAME 0x32DCD0
int func_0032DCD0(int a, int b)
{
    int r;
    func_0033FCA0();
    r = func_0032DD18(a, b);
    func_0033FCA8();
    return r;
}

// FUNCTION: GAME 0x32DDF8
void func_0032DDF8(char *a, float f)
{
    func_0033FCA0();
    func_0032DE38(a, f);
    func_0033FCA8();
}

extern int func_0032EBD8();
extern int func_00330268();
extern void func_0032D868();
extern void func_0033FC70();
extern void func_0033FC88();
extern int func_0032DC90();
extern void func_0032DD70();
extern void func_0032DFC0();
extern char D_00452BF8[], D_00452C20[];

// FUNCTION: GAME 0x32D170
int func_0032D170()
{
    func_0032EBD8();
    func_00330268();
    return 0;
}

// FUNCTION: GAME 0x32DA08
void func_0032DA08(int a, int b, int c)
{
    func_0032D868(a, b, c, 0, 0xFFFFF);
}

// FUNCTION: GAME 0x32DE38
void func_0032DE38(char *o, float f)
{
    *(float *)(o + 0x1E4) = f;
    func_0033FC70();
    if (func_0032DC90(o) == 2)
        func_0032DD70(o);
    func_0033FC88();
}

// FUNCTION: GAME 0x32DEC8
void func_0032DEC8(char *o, int v)
{
    if (!o) {
        func_0033FCB0(D_00452BF8);
        return;
    }
    o[0x1B0] = v;
}

// FUNCTION: GAME 0x32DF38
void func_0032DF38(char *o, int v)
{
    if (!o) {
        func_0033FCB0(D_00452C20);
        return;
    }
    o[0x1B1] = v;
}

// FUNCTION: GAME 0x32DF70
void func_0032DF70(int a, int b, int c)
{
    func_0033FCA0();
    func_0032DFC0(a, b, c);
    func_0033FCA8();
}
