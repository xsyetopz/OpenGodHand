// Small free functions after cParts::setRotationOrder (0x150000-0x152FFF).

extern char D_00466470[];
extern "C" void func_00150418(void *);
extern "C" void func_001504B0(void *, void *);
extern "C" void func_001505A8(void *, void *);
extern "C" void func_001523F8(int a, unsigned int b);

// FUNCTION: GAME 0x150078
extern "C" void func_00150078()
{
    func_00150418(D_00466470);
}

// FUNCTION: GAME 0x150098
extern "C" void func_00150098(void *a)
{
    func_001504B0(D_00466470, a);
}

// FUNCTION: GAME 0x150100
extern "C" void func_00150100(void *a)
{
    func_001505A8(D_00466470, a);
}

// FUNCTION: GAME 0x152428
extern "C" void func_00152428()
{
    func_001523F8(1, 0xFFFF);
}
