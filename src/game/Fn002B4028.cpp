// Fn002B4028: per-frame cursor step with wrap-around, message speed update and state reset.
extern "C" void func_002B46F0(char *, int, short, void *);
extern "C" void func_002B4768(char *, char *, char *);
extern char Sys[];
extern char *Message;

extern "C" void func_002B4028(char *self)
{
    char *sys = Sys;
    short orig = *(short *)(self + 0x94);
    *(int *)(self + 0x14) |= 0x20;
    if (*(long *)(sys + 0x1A0) & (((0x8000L << 24) | 0x8000) << 9)) {
        *(unsigned short *)(self + 0x94) = *(unsigned short *)(self + 0x94) - 1;
    }
    if (*(long *)(sys + 0x1A0) & (((0x8000L << 24) | 0x8000) << 10)) {
        *(unsigned short *)(self + 0x94) = *(unsigned short *)(self + 0x94) + 1;
    }
    if (*(short *)(self + 0x94) != orig) {
        func_002B46F0(self, 0, 0x15F, 0);
    }
    short v = *(short *)(self + 0x94);
    int t0;
    if (v < 0) {
        t0 = *(unsigned short *)(self + 0x96) - 1;
    } else {
        if (*(short *)(self + 0x96) - 1 < v) {
            t0 = 0;
        } else {
            t0 = *(unsigned short *)(self + 0x94);
        }
    }
    *(unsigned short *)(self + 0x94) = t0;
    if (*(long *)(Sys + 0x1A0) & 0x10000000) {
        *(unsigned short *)(Message + 0xBEC) = t0;
        func_002B46F0(self, 0, 0x15E, 0);
        *(int *)(self + 0x14) = (*(int *)(self + 0x14) & ~1 & ~0x20) | 0x400;
        func_002B4768(self, self + 0x90, self + 0x8C);
        self[0xF] = 0;
        self[0xC] = 2;
        self[0xD] = 0;
        self[0xE] = 0;
    }
}
