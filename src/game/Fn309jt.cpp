// FUNCTION: GAME 0x309C30
extern "C" int func_00309C30(unsigned a, int b)
{
    int n;
    switch (a) {
    case 0: case 1: case 2: case 10: case 27: case 36: case 44:
    case 48: case 49: case 50: case 58:
        return (b + 63) / 64;
    case 19: case 20:
        b = (b + 63) / 64;
        return b + (b & 1);
    }
    return 0;
}
