// COMPILER: ee-gcc3.2-030926
// FLAGS: -fno-optimize-sibling-calls
// SCE library wrappers in 0x3875A8-0x3A3FFF that keep a frame around the call (no sibling call).
void func_0038A8D8(int, int, int, char);
void func_0038AA60(int, int, int, char);
void func_00388A00(int, short);
void func_003885B0(int, char);
void func_0038CD18(int, char);
void func_0038E138(int, char);

// FUNCTION: GAME 0x38A1D8
void func_0038A1D8(int a, int b, int c, char d)
{
    func_0038A8D8(a, b, c, d);
}

// FUNCTION: GAME 0x38A1F8
void func_0038A1F8(int a, int b, int c, char d)
{
    func_0038AA60(a, b, c, d);
}

// FUNCTION: GAME 0x38A238
void func_0038A238(int a, int b, int c, char d)
{
    func_0038A8D8(a, b, c, d);
}

// FUNCTION: GAME 0x38A278
void func_0038A278(int a, int b, int c, char d)
{
    func_0038AA60(a, b, c, d);
}

// FUNCTION: GAME 0x38A528
void func_0038A528(int a, short b)
{
    func_00388A00(a, b);
}

// FUNCTION: GAME 0x38A588
void func_0038A588(int a, char b)
{
    func_003885B0(a, b);
}

// FUNCTION: GAME 0x38A5A8
void func_0038A5A8(int a, char b)
{
    func_003885B0(a, b);
}

// FUNCTION: GAME 0x38B460
void func_0038B460(int a, char b)
{
    func_0038CD18(a, b);
}

// FUNCTION: GAME 0x38BA68
void func_0038BA68(int a, char b)
{
    func_0038E138(a, b);
}
