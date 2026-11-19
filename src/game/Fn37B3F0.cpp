extern char D_0045BD90, D_0045BDA0, D_0045BDA8, D_0045BDC0, D_0045BDC8, D_0045BDD0, D_0045BDD8, D_0045BDE0;
extern "C" {
void func_002E0DE8(int, int, int, char *);
int func_00387430(int);
}

// FUNCTION: GAME 0x37B3F0
extern "C" void func_0037B3F0(void)
{
    func_002E0DE8(3, 4, 8, &D_0045BD90);
    int v = func_00387430(0);
    if (v == 0) {
        func_002E0DE8(12, 4, 15, &D_0045BDA0);
        return;
    }
    if (v & 1)
        func_002E0DE8(12, 4, 13, &D_0045BDA8);
    if (v & 2)
        func_002E0DE8(12, 4, 8, &D_0045BDC0);
    if (v & 4)
        func_002E0DE8(15, 4, 8, &D_0045BDC8);
    if (v & 8)
        func_002E0DE8(18, 4, 12, &D_0045BDD0);
    if (v & 16)
        func_002E0DE8(21, 4, 13, &D_0045BDD8);
    if (v & 32)
        func_002E0DE8(24, 4, 10, &D_0045BDE0);
}
