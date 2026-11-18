extern int D_003F28B0[];
extern int D_003F28A0[];
extern char D_0045C328[];
extern "C" void func_002E0DE8(int, int, int, ...);

// FUNCTION: GAME 0x380048
extern "C" void func_00380048(char *o, char *in, unsigned char k, char *p)
{
    if (k == 8)
        p = o + *(unsigned char *)(o + 5) * 0x48 + 0x49;
    else if (k == 9)
        p = o + 0x319;
    else
        p = (k == 10) ? o + 0x371 : o + 0x471;
    if (*(unsigned *)(in + 0x34) & 0x40) {
        o[2] = 1;
        *p = 0;
        return;
    }
    if (*(unsigned char *)p == 2)
        func_002E0DE8(3, 0x14, 0xA, D_003F28B0[k - 8]);
    else
        func_002E0DE8(3, 0x14, 0xA, D_003F28A0[*(unsigned char *)p - 1]);
    func_002E0DE8(3, 0x15, 0xA, D_0045C328);
}
