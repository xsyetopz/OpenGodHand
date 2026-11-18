extern "C" int D_00747A0C;

// FUNCTION: GAME 0x272688
extern "C" int func_00272688(char *self)
{
    if (D_00747A0C == 0) {
        int e = (*(int *)(self + 0x564) == 0x244);
        if (!e)
            return 0;
    }
    if (*(unsigned *)(self + 0x16D4) & 0x1000) {
        int e = (*(int *)(self + 0x564) == 0x244);
        if (!e)
            return 0;
    }
    switch (*(int *)(self + 0x564)) {
    case 0x200: case 0x201: case 0x202: case 0x203: case 0x204: case 0x205:
    case 0x206: case 0x207: case 0x20A: case 0x20C: case 0x20D: case 0x216:
    case 0x218: case 0x224: case 0x227: case 0x228: case 0x229: case 0x22A:
    case 0x22B: case 0x23A: case 0x240: case 0x241: case 0x242: case 0x243:
    case 0x244: case 0x245: case 0x246: case 0x247: case 0x24A: case 0x24B:
        break;
    default:
        return 0;
    }
    return 1;
}
