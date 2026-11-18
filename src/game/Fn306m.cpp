// Game functions at 0x306000-0x318000, matched byte-identically.
extern "C" {
extern int D_003C3CF4;
extern int D_003C3CF8;
extern int D_003C3D00;
extern char D_003C3CFC;
extern char D_00754200[], SoundHeap[], SubScrHeap[], RoomHeap[], D_00754240[], D_00754C10[], D_00754C20[];
extern void *MemDefalutHeapPtr;
void func_002A9498(void *, int, int, int);
}

// FUNCTION: GAME 0x30ECF8
extern "C" void func_0030ECF8(int a)
{
    D_003C3CF4 = 0x7C0000;
    D_003C3CF8 = 0x1FFB000;
    D_003C3D00 = 0x7C0000;
    if (a != 1)
        func_002A9498(D_00754200, 0x8A0000, 0x6B0000, 0);
    func_002A9498(SoundHeap, 0xF50000, 0x1C0000, 0);
    func_002A9498(SubScrHeap, 0x1110000, 0xB0000, 0);
    func_002A9498(RoomHeap, 0x11C0000, 0xE3B000, 0);
    func_002A9498(D_00754240, 0, 0, 0);
    func_002A9498(D_00754C10, 0, 0, 0);
    func_002A9498(D_00754C20, 0, 0, 0);
    MemDefalutHeapPtr = RoomHeap;
    D_003C3CFC = 1;
}
