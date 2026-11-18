// Scaled product by selector; sole switch and jump table of 0x309CA0.
// FUNCTION: GAME 0x309CA0
extern "C" int func_00309CA0(unsigned sel, int a, int b)
{
    switch (sel) {
    case 0:
    case 1:
    case 27:
    case 36:
    case 44:
    case 48:
    case 49:
        return (a * b) / 64;
    case 2:
    case 10:
    case 50:
    case 58:
        return (a * b) / 128;
    case 19:
        return (a * b) / 256;
    case 20:
        return (a * b) / 512;
    default:
        return 0;
    }
}
