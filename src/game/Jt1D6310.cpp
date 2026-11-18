// Jump-table unit; this file holds no other .rodata.
typedef int COL;
extern "C" void SetOffsetPosX__12CustomIDWorki(char *, int);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(char *, int, int, unsigned short);
extern "C" void SetColorAnimNormal__12CustomIDWorkG3COLT1Us(char *, COL, COL, unsigned short);
extern "C" void func_001D51B8(char *, int, int);

// DRAFT: GAME 0x1D6310 (38 words differ: constant/register allocation of the COL mask sequence in case 4)
#ifdef NONMATCHING
extern "C" void func_001D6310(char *self, unsigned short id, COL c1, COL c2)
{
    switch (id) {
    case 0:
    default:
        SetOffsetPosX__12CustomIDWorki(self + 0xA10, -0x1C2);
        func_001D51B8(self, 0x14, 0);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(self + 0xA10, 0);
        func_001D51B8(self, 0x14, 1);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xA10, -0x1C2, 0, 0x14);
        func_001D51B8(self, 0x14, 1);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xA10, 0, 0x1C2, 0x14);
        func_001D51B8(self, 0x14, 1);
        break;
    case 4:
        c1 &= (int)0xFF00FFFF; c1 |= 0x800000;
        c1 &= 0xFFFF00FF; c1 |= 0x8000;
        c1 &= -0x100; c1 |= 0x80;
        c1 &= 0x00FFFFFF; c1 |= (int)0x80000000;
        c2 &= (int)0xFF00FFFF; c2 |= 0x800000;
        c2 &= 0xFFFF00FF; c2 |= 0x8000;
        c2 &= -0x100; c2 |= 0x80;
        c2 &= 0x00FFFFFF; c2 |= (int)0x80000000;
        SetColorAnimNormal__12CustomIDWorkG3COLT1Us(self + 0xA10, c2, c1, 8);
        SetOffsetPosX__12CustomIDWorki(self + 0xA10, 0);
        func_001D51B8(self, 0x14, 1);
        break;
    }
}
#endif
