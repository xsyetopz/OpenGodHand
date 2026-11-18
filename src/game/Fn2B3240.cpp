// Fn2B3240: per-frame step advance scaled by message speed.
extern char *Message;
extern char Sys[];
extern long D_003C3D48;
extern "C" void func_002B45D0(char *);
extern "C" void func_002B45D8(char *);
extern "C" void func_002B3338(char *);

// FUNCTION: GAME 0x2B3240
extern "C" void func_002B3240(char *self)
{
    switch (*(unsigned char *)(self + 0xD)) {
    case 0:
        func_002B45D0(self);
        (*(unsigned char *)(self + 0xD))++;
    case 1:
        func_002B45D8(self);
        break;
    }
    char *sys = Sys;
    int v = (short)(int)((float)*(short *)(Message + 0xBDA) * *(float *)(self + 0x6C));
    if (*(long *)(sys + 0x1A0) & 0x10000000)
        *(int *)(self + 0x14) |= 1;
    if (*(int *)(self + 0x34) == 0) {
        if ((*(int *)(self + 0x14) & 1) || (*(long *)(sys + 0x178) & D_003C3D48))
            v *= 10;
    }
    *(int *)(self + 0x68) += v;
    func_002B3338(self);
}
