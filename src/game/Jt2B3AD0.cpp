// Phase reset keyed on the state byte at 0xA4; sole switch of 0x2B3AD0.
// FUNCTION: GAME 0x2B3AD0
extern "C" int func_002B3AD0(char *self)
{
    int v;
    switch (*(unsigned char *)(self + 0xA4)) {
    case 4:
        v = 4;
        break;
    case 5:
        v = 5;
        break;
    default:
        v = 3;
        break;
    }
    self[0xF]= 0;
    self[0xC] = v;
    self[0xD] = 0;
    self[0xE] = 0;
    return 2;
}
