// Medium units in 0x290000-0x29FFFF.
extern char g_RoomSave[];
extern "C" short *func_002BEF60(void *, unsigned);
extern "C" int irand__Fv(void);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void linkNoAlloc__7cRelSysPvPCcQ27cRelSys8eRelType(void *, void *, const char *, int);
extern char RelSys;
extern unsigned D_00747A30;
extern const char D_0044A920[], D_0044A940[], D_0044A958[];

// FUNCTION: GAME 0x295380
extern "C" void updateSetDataPos__11cEmSetParamUiRC4cVec(void *, unsigned idx, float *v)
{
    short *p = func_002BEF60(g_RoomSave, idx);
    if (p) {
        p[0] = (short)(v[0] * 20.0f);
        p[1] = (short)(v[1] * 20.0f);
        p[2] = (short)(v[2] * 20.0f);
    }
}

// FUNCTION: GAME 0x2949E8
extern "C" int func_002949E8(char *self, unsigned mod)
{
    unsigned char r = irand__Fv() % mod;
    if ((irand__Fv() & 3) == 0)
        self[0x53F] = 0;
    if (self[0x53F] >= r) {
        self[0x53F] = 0;
        return 1;
    }
    self[0x53F]++;
    return 0;
}

// FUNCTION: GAME 0x297450
struct Ft {
    char pad[8];
    unsigned char lo : 7;
    unsigned char done : 1;
};

extern "C" void func_00297450(char *self)
{
    char buf[0x40];
    if (!((unsigned long)*(unsigned char *)(self + 8) >> 7)) {
        if (D_00747A30 & 0x400)
            sprintf(buf, D_0044A920, D_0044A940);
        else
            sprintf(buf, D_0044A958, D_0044A940);
        if (*(void **)(self + 0x10)) {
            linkNoAlloc__7cRelSysPvPCcQ27cRelSys8eRelType(&RelSys, *(void **)(self + 0x10), buf, 2);
            *(unsigned *)(self + 8) |= 0x80;
        }
    }
}
