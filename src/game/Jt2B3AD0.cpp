// Phase reset keyed on the state byte at 0xA4; sole switch of 0x2B3AD0.
// DRAFT: GAME 0x2B3AD0 - original keeps four unmerged 'b; addiu 3' arms for cases 0-3; gcc merges identical arms (20 words differ, 88 vs 112 bytes); tried goto done, 1+2/6/2/4-1 arm exprs, fallthrough (all 20)
#ifdef NONMATCHING
extern "C" int func_002B3AD0(char *self)
{
    int v;
    switch (*(unsigned char *)(self + 0xA4)) {
    case 0:
        v = 3;
        break;
    case 1:
        v = 3;
        break;
    case 2:
        v = 3;
        break;
    case 3:
        v = 3;
        break;
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
#endif
