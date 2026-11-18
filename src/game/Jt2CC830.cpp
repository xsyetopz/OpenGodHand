// Sound-object setup from a short parameter block; sole switch of 0x2CC830.
extern char Snd[];
extern "C" int func_002D0598(void *, unsigned);
extern "C" int func_002D0578(void *, unsigned);

// FUNCTION: GAME 0x2CC830
extern "C" int func_002CC830(char *self, char *a1, int flag)
{
    unsigned u = *(unsigned *)(a1 + 8);
    *(int *)(self + 0x98) = flag;
    *(unsigned *)(self + 0x9C) = u;
    switch (*(unsigned *)(self + 0x94)) {
    case 3:
        *(unsigned *)(self + 0xAC) = ((unsigned short *)a1)[6];
        *(int *)(self + 0xA4) = func_002D0578(Snd, ((unsigned short *)a1)[7]);
        break;
    case 2:
        *(int *)(self + 0xA8) = func_002D0598(Snd, ((unsigned short *)a1)[6]);
        *(int *)(self + 0xA4) = func_002D0578(Snd, ((unsigned short *)a1)[7]);
        break;
    case 1:
    case 4:
    case 5:
        *(unsigned short *)(self + 0xA0) = ((unsigned short *)a1)[6];
        *(unsigned short *)(self + 0xA2) = ((unsigned short *)a1)[7];
        break;
    case 0:
        *(unsigned *)(self + 0x94) = 0;
        return 0;
    default:
        break;
    }
    return 1;
}
