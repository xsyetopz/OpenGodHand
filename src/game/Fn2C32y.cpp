struct Room { unsigned short id; char pad[0x12]; };
extern Room SceRoomTable[];
extern char Sys[];
extern unsigned D_00747A84;
extern char g_RoomSave[];
extern "C" void func_002D56A8(char *);
extern "C" void func_002BEBC8(char *, int);

// DRAFT: GAME 0x2C32F0 (about 28 words differ: lui/constant register numbering, loop pointer reload and exit layout)
#ifdef NONMATCHING
extern "C" void func_002C32F0(char *self)
{
    int i, off;
    func_002D56A8(self + 0x1C);
    D_00747A84 &= 0xBFFFFFFF;
    off = 0;
    for (i = 0; (unsigned)i < 16; i++) {
        if (i >= 0) {
            char *p = *(char **)(self + 0x1C) + off;
            p[0x50] &= ~1;
        }
        off += 0x58;
    }
    *(Room **)(self + 0xD4) = SceRoomTable;
    if (SceRoomTable[0].id != 0xFFFF && SceRoomTable[0].id != *(unsigned short *)(Sys + 0x5B0)) {
        for (;;) {
            Room *r = *(Room **)(self + 0xD4);
            *(Room **)(self + 0xD4) = r + 1;
            if (r[1].id == 0xFFFF) break;
            if (r[1].id == *(unsigned short *)(Sys + 0x5B0)) break;
        }
    }
    func_002BEBC8(g_RoomSave, *(unsigned short *)(Sys + 0x5B0));
}
#endif
