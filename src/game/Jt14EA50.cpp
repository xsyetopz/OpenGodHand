// Scenario dispatch on the state byte at 0x2F5; sole switch of 0x14EA50.
extern "C" void func_0014EAD8(void *);
extern "C" void func_0014EB90(void *);
extern "C" void func_0014EC88(void *);
extern "C" void func_0014ED60(void *);
extern "C" void func_0014EE60(void *);

// FUNCTION: GAME 0x14EA50
extern "C" void R0_scenario__8cObjBase(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 1:
        func_0014EAD8(self);
        break;
    case 2:
        func_0014EB90(self);
        break;
    case 3:
        func_0014EC88(self);
        break;
    case 4:
        func_0014ED60(self);
        break;
    case 5:
        func_0014EE60(self);
        break;
    case 0:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        break;
    }
}
