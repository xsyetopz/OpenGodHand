// COMPILER: ee-gcc2.96
// Sibling families: if (hook) hook(); and if (hook) hook(arg, a0);

extern void (*D_003D1418)();
extern void (*D_003D141C)();
extern void (*D_003D1424)();
extern void (*D_003F1FFC)();
extern void (*D_003F2000)();
extern void (*D_003F2008)();
extern void (*D_003F2010)();
extern void (*D_003F200C)();
extern void (*D_003F2024)();
extern void (*D_003F2028)();
extern void (*D_003F202C)();
extern void (*D_003F2034)();
extern void (*D_003F2038)();
extern void (*D_003F203C)();
extern void (*D_003F2040)();
extern void (*D_003F2044)();

// FUNCTION: GAME 0x329848
void func_00329848(void)
{
    if (D_003D1418)
        D_003D1418();
}

// FUNCTION: GAME 0x329870
void func_00329870(void)
{
    if (D_003D141C)
        D_003D141C();
}

// FUNCTION: GAME 0x329898
void func_00329898(void)
{
    if (D_003D1424)
        D_003D1424();
}

// FUNCTION: GAME 0x336CE0
void func_00336CE0(void)
{
    if (D_003D1424)
        D_003D1424();
}

// FUNCTION: GAME 0x36CCC8
void func_0036CCC8(void)
{
    if (D_003F1FFC)
        D_003F1FFC();
}

// FUNCTION: GAME 0x36CCF0
void func_0036CCF0(void)
{
    if (D_003F2000)
        D_003F2000();
}

// FUNCTION: GAME 0x36CD48
void func_0036CD48(void)
{
    if (D_003F2008)
        D_003F2008();
}

// FUNCTION: GAME 0x36CD70
void func_0036CD70(void)
{
    if (D_003F2010)
        D_003F2010();
}

// FUNCTION: GAME 0x36CD98
void func_0036CD98(void)
{
    if (D_003F200C)
        D_003F200C();
}

// FUNCTION: GAME 0x36CDC0
void func_0036CDC0(void)
{
    if (D_003F2024)
        D_003F2024();
}

// FUNCTION: GAME 0x36CDE8
void func_0036CDE8(void)
{
    if (D_003F2028)
        D_003F2028();
}

// FUNCTION: GAME 0x36CE10
void func_0036CE10(void)
{
    if (D_003F202C)
        D_003F202C();
}

// FUNCTION: GAME 0x36CE68
void func_0036CE68(void)
{
    if (D_003F2034)
        D_003F2034();
}

// FUNCTION: GAME 0x36CE90
void func_0036CE90(void)
{
    if (D_003F2038)
        D_003F2038();
}

// FUNCTION: GAME 0x36CEB8
void func_0036CEB8(void)
{
    if (D_003F203C)
        D_003F203C();
}

// FUNCTION: GAME 0x36CEE0
void func_0036CEE0(void)
{
    if (D_003F2040)
        D_003F2040();
}

// FUNCTION: GAME 0x36CF08
void func_0036CF08(void)
{
    if (D_003F2044)
        D_003F2044();
}

extern void (*D_003D90D4)();
extern int D_003D90D8;
extern void (*D_003D9F6C)();
extern int D_003D9F70;
extern void (*D_003DECFC)();
extern int D_003DED00;
extern void (*D_003EC454)();
extern int D_003EC458;

// FUNCTION: GAME 0x332808
void func_00332808(int a, int b)
{
    if (D_003D90D4)
        D_003D90D4(D_003D90D8, b, a);
}

// FUNCTION: GAME 0x334008
void func_00334008(int a, int b)
{
    if (D_003D9F6C)
        D_003D9F6C(D_003D9F70, b, a);
}

// FUNCTION: GAME 0x336330
void func_00336330(int a, int b)
{
    if (D_003DECFC)
        D_003DECFC(D_003DED00, b, a);
}

// FUNCTION: GAME 0x340450
void func_00340450(int a)
{
    if (D_003EC454)
        D_003EC454(D_003EC458, a);
}
