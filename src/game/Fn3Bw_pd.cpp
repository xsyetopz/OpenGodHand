extern "C" int D_00460D70[];
extern "C" int D_0045A5F8[];
extern "C" void func_0031EEC8();

// FUNCTION: GAME 0x3BAFF8
extern "C" int *func_003BAFF8(void)
{
    if (!D_00460D70[0])
        func_0031EEC8(D_00460D70, D_0045A5F8);
    return D_00460D70;
}
