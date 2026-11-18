// Medium units in 0x290000-0x29FFFF.
extern char g_RoomSave[];
extern "C" short *func_002BEF60(void *, unsigned);
extern "C" int irand__Fv(void);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void linkNoAlloc__7cRelSysPvPCcQ27cRelSys8eRelType(void *, void *, const char *, int);
extern char RelSys;
extern unsigned D_00747A30;
extern const char D_0044A920[], D_0044A940[], D_0044A958[];


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


extern "C" const char *func_00297B80(void);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(void *, const char *, void **, void *, int, unsigned, unsigned, unsigned);
extern void *MemDefalutHeapPtr;
extern char Dvd[];
extern const char D_0044A960[];

// FUNCTION: GAME 0x297540
extern "C" void func_00297540(char *self)
{
    char buf[0x20];
    sprintf(buf, D_0044A960, func_00297B80());
    *(void **)(self + 0x14) = 0;
    *(void **)(self + 0xC) = (void *)ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, buf, (void **)(self + 0x14), MemDefalutHeapPtr, 0, 0, 0, 0);
    if (*(void **)(self + 0x14))
        *(unsigned *)(self + 8) |= 0x100;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x295380
// diff: cvt.w.s targets f2/f1 where the original reuses f0 (6 words)
extern "C" void updateSetDataPos__11cEmSetParamUiRC4cVec(void *, unsigned idx, float *v)
{
    short *p = func_002BEF60(g_RoomSave, idx);
    if (p) {
        p[0] = (short)(v[0] * 20.0f);
        p[1] = (short)(v[1] * 20.0f);
        p[2] = (short)(v[2] * 20.0f);
    }
}

// DRAFT: GAME 0x297450
// diff: original loads the flag byte with dsrl 7 and uses v1 for the |= 0x80 (4 words)
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
#endif
