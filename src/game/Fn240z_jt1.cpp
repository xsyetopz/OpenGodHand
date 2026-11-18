// FUNCTION: GAME 0x2740D8
extern "C" int func_002740D8(char *self)
{
    if (*(int *)(self + 0x6EC) != 0 || *(int *)(self + 0x6F0) != 0 || *(int *)(self + 0x700) != 0 || *(int *)(self + 0x704) != 0)
        return 0;
    switch (*(int *)(self + 0x564)) {
    case 0x209: case 0x213: case 0x217: case 0x21F: case 0x221: case 0x223:
    case 0x224: case 0x242: case 0x243: case 0x244: case 0x252: case 0x256:
    case 0x264: case 0x265: case 0x26A: case 0x275: case 0x276: case 0x27E:
        return 0;
    }
    return 1;
}
