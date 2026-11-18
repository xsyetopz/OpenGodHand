// Selects heap pair by mode; sole switch of 0x2CFD50.
extern char SoundHeap[], RoomHeap[], D_00602F80[], D_006036A0[], D_00603310[];
extern unsigned short D_00747A50;

// FUNCTION: GAME 0x2CFD50
extern "C" void func_002CFD50(char *self)
{
    switch (*(unsigned *)(self + 0x2C)) {
    case 0:
        *(char **)(self + 8) = SoundHeap;
        *(char **)(self + 0xC) = D_00602F80;
        break;
    case 3:
        *(char **)(self + 8) = SoundHeap;
        *(char **)(self + 0xC) = D_00602F80;
        break;
    case 1: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
    case 16: case 17: case 18: case 19:
        if (D_00747A50 == 0x504 || D_00747A50 == 0x506 || D_00747A50 == 0x801 ||
            D_00747A50 == 0x4F || D_00747A50 == 0x4E)
            *(char **)(self + 8) = RoomHeap;
        else
            *(char **)(self + 8) = SoundHeap;
        *(char **)(self + 0xC) = D_006036A0;
        break;
    default:
        *(char **)(self + 8) = SoundHeap;
        *(char **)(self + 0xC) = D_00603310;
        break;
    }
}
