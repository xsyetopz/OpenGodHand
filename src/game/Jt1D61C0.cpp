// Jump-table unit; this file holds no other .rodata.
extern "C" void SetOffsetPosY__12CustomIDWorki(char *, int);
extern "C" void SetMoveOffsetPosY__12CustomIDWorkiiUs(char *, int, int, unsigned short);
extern "C" void func_001D51B8(char *, int, int);

// FUNCTION: GAME 0x1D61C0
extern "C" void func_001D61C0(char *self, unsigned short id)
{
    switch (id) {
    case 0:
    default:
        SetOffsetPosY__12CustomIDWorki(self + 0x820, 0x46);
        func_001D51B8(self, 0x10, 0);
        func_001D51B8(self, 0x11, 0);
        func_001D51B8(self, 0x12, 0);
        break;
    case 1:
        SetOffsetPosY__12CustomIDWorki(self + 0x820, 0);
        break;
    case 2:
        SetMoveOffsetPosY__12CustomIDWorkiiUs(self + 0x820, 0x46, 0, 0xA);
        func_001D51B8(self, 0x10, 0);
        func_001D51B8(self, 0x11, 1);
        func_001D51B8(self, 0x12, 1);
        break;
    case 3:
        SetMoveOffsetPosY__12CustomIDWorkiiUs(self + 0x820, 0, 0x46, 0xA);
        break;
    case 4:
        SetMoveOffsetPosY__12CustomIDWorkiiUs(self + 0x820, 0x46, 0, 0xA);
        func_001D51B8(self, 0x10, 0);
        func_001D51B8(self, 0x11, 0);
        func_001D51B8(self, 0x12, 1);
        break;
    }
}
