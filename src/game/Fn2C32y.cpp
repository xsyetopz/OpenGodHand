struct Room { unsigned short id; char pad[0x12]; };
extern Room SceRoomTable[];
struct SysT { char pad[0x5B0]; unsigned short room; };
extern SysT Sys;
extern unsigned D_00747A84;
extern char g_RoomSave[];
extern "C" void func_002D56A8(char *);
extern "C" void func_002BEBC8(char *, int);

// FUNCTION: GAME 0x2C32F0
extern "C" void func_002C32F0(char *self)
{
    unsigned i;
    int off;
    func_002D56A8(self + 0x1C);
    D_00747A84 &= 0xBFFFFFFF;
    i = 0;
    off = 0;
    for (; i < 16; i++) {
        if ((int)i >= 0) {
            char *p = (char *)((int)off + *(int *)(self + 0x1C));
            p[0x50] &= ~1;
        }
        off += 0x58;
    }
    *(Room **)(self + 0xD4) = SceRoomTable;
    if (SceRoomTable[0].id != 0xFFFF && SceRoomTable[0].id != Sys.room) {
        for (;;) {
            Room *r = *(Room **)(self + 0xD4);
            *(Room **)(self + 0xD4) = r + 1;
            if (r[1].id == 0xFFFF) break;
            if (r[1].id == Sys.room) break;
        }
    }
    func_002BEBC8(g_RoomSave, Sys.room);
}
