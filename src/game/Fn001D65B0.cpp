// Jump-table units; this file holds no other .rodata.
typedef int COL;
extern "C" void SetOffsetPosX__12CustomIDWorki(char *, int);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(char *, int, int, unsigned short);
extern "C" void SetColorAnimNormal__12CustomIDWorkG3COLT1Us(char *, COL, COL, unsigned short);
extern "C" void func_001D51B8(char *, int, int);

// FUNCTION: GAME 0x1D65B0
extern "C" void func_001D65B0(char *self, unsigned short id, COL c1, COL c2)
{
    switch (id) {
    case 0:
    default:
        SetOffsetPosX__12CustomIDWorki(self + 0xB08, -0x1C2);
        func_001D51B8(self, 0x16, 0);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(self + 0xB08, 0);
        func_001D51B8(self, 0x16, 1);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xB08, -0x1C2, 0, 0x14);
        func_001D51B8(self, 0x16, 1);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xB08, 0, 0x1C2, 0x14);
        func_001D51B8(self, 0x16, 1);
        break;
    case 4:
        {
            COL m1 = c1 & (int)0xFF00FFFF;
            COL m2 = c2 & (int)0xFF00FFFF;
            m2 |= 0x800000;
            m1 |= 0x800000;
            m2 &= 0xFFFF00FF;
            m1 &= 0xFFFF00FF;
            m1 = ((m1 | 0x8000) & -0x100 | 0x80) & 0x00FFFFFF | (int)0x80000000;
            m2 = ((m2 | 0x8000) & -0x100 | 0x80) & 0x00FFFFFF;
            SetColorAnimNormal__12CustomIDWorkG3COLT1Us(self + 0xB08, m2, m1, 8);
        }
        SetOffsetPosX__12CustomIDWorki(self + 0xB08, 0);
        func_001D51B8(self, 0x16, 1);
        break;
    }
}

// FUNCTION: GAME 0x1D6700
extern "C" void func_001D6700(char *self, unsigned short id, COL c1, COL c2)
{
    switch (id) {
    case 0:
    default:
        SetOffsetPosX__12CustomIDWorki(self + 0xB84, -0x1C2);
        func_001D51B8(self, 0x17, 0);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(self + 0xB84, 0);
        func_001D51B8(self, 0x17, 1);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xB84, -0x1C2, 0, 0x14);
        func_001D51B8(self, 0x17, 1);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xB84, 0, 0x1C2, 0x14);
        func_001D51B8(self, 0x17, 1);
        break;
    case 4:
        {
            COL m1 = c1 & (int)0xFF00FFFF;
            COL m2 = c2 & (int)0xFF00FFFF;
            m2 |= 0x800000;
            m1 |= 0x800000;
            m2 &= 0xFFFF00FF;
            m1 &= 0xFFFF00FF;
            m1 = ((m1 | 0x8000) & -0x100 | 0x80) & 0x00FFFFFF | (int)0x80000000;
            m2 = ((m2 | 0x8000) & -0x100 | 0x80) & 0x00FFFFFF;
            SetColorAnimNormal__12CustomIDWorkG3COLT1Us(self + 0xB84, m2, m1, 8);
        }
        SetOffsetPosX__12CustomIDWorki(self + 0xB84, 0);
        func_001D51B8(self, 0x17, 1);
        break;
    }
}

// FUNCTION: GAME 0x1D6850
extern "C" void func_001D6850(char *self, unsigned short id, COL c1, COL c2)
{
    switch (id) {
    case 0:
    default:
        SetOffsetPosX__12CustomIDWorki(self + 0xC00, -0x1C2);
        func_001D51B8(self, 0x18, 0);
        break;
    case 1:
        SetOffsetPosX__12CustomIDWorki(self + 0xC00, 0);
        func_001D51B8(self, 0x18, 1);
        break;
    case 2:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xC00, -0x1C2, 0, 0x14);
        func_001D51B8(self, 0x18, 1);
        break;
    case 3:
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0xC00, 0, 0x1C2, 0x14);
        func_001D51B8(self, 0x18, 1);
        break;
    case 4:
        {
            COL m1 = c1 & (int)0xFF00FFFF;
            COL m2 = c2 & (int)0xFF00FFFF;
            m2 |= 0x800000;
            m1 |= 0x800000;
            m2 &= 0xFFFF00FF;
            m1 &= 0xFFFF00FF;
            m1 = ((m1 | 0x8000) & -0x100 | 0x80) & 0x00FFFFFF | (int)0x80000000;
            m2 = ((m2 | 0x8000) & -0x100 | 0x80) & 0x00FFFFFF;
            SetColorAnimNormal__12CustomIDWorkG3COLT1Us(self + 0xC00, m2, m1, 8);
        }
        SetOffsetPosX__12CustomIDWorki(self + 0xC00, 0);
        func_001D51B8(self, 0x18, 1);
        break;
    }
}
