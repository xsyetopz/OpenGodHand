extern "C" int func_002B46F0(char *, int, int, int);

// FUNCTION: GAME 0x2B39B0
extern "C" int func_002B39B0(char *self)
{
    int k;
    switch (*(unsigned short *)(*(char **)(self + 0x8C) + 2)) {
    default:
    case 0:
    case 5: k = 0; break;
    case 1: k = 1; break;
    case 2: k = 6; break;
    case 3: k = 2; break;
    case 4: k = 3; break;
    case 6: k = *(int *)(self + 0x20); break;
    }
    func_002B46F0(self, k, *(short *)(*(char **)(self + 0x8C) + 4), *(int *)(self + 0x18));
    return 0;
}
