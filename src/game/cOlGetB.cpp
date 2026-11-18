// Singleton getter split from cOlGet.cpp.

extern "C" {
void func_0031EEA8(void *obj, const void *a, void *b);
void func_001BD528();
}
extern char D_007859B8[];
extern int D_00785BC8;
extern const char D_00423DF0[];

// FUNCTION: GAME 0x18F0C0
extern "C" void *func_0018F0C0()
{
    if (D_00785BC8 == 0) {
        func_001BD528();
        func_0031EEA8(&D_00785BC8, D_00423DF0, D_007859B8);
    }
    return &D_00785BC8;
}

