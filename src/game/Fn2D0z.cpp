// Small game functions at 0x2D0000-0x2E0000 (2.95.3 C++).
extern "C" int sprintf(char *, const char *, ...);
extern char D_00580D40[], D_0044D0B0[], D_0044D0C0[], D_0044D0D8[];
extern "C" int func_002CFF68(char *);
extern "C" int func_001FF9C0(char *, char *, int, int);
extern "C" int func_00322A68(int, int, int, int);
extern "C" char *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, int);
extern "C" int FileExist__4cDvdPCc(char *d, char *p);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(char *d, char *p, char *o, int h, int a, int b, int c, int e);
extern char Dvd[], SoundHeap[], D_0044D078[], D_0044D088[];
extern "C" void func_002CFF90(char *);
extern "C" void func_002D0350(char *, int);
// FUNCTION: GAME 0x002D0128
extern "C" int func_002D0128(char *self, int a, int b)
{
    char buf[0x40];
    int r;
    *(char **)(self + 8) = SoundHeap;
    a += 0x80;
    *(int *)(self + 0x18) = a;
    *(int *)(self + 0x20) = b;
    switch (a) {
    case 0x80:
        sprintf(buf, D_0044D078, b);
        break;
    case 0x81:
        sprintf(buf, D_0044D088, b);
        break;
    }
    if (!FileExist__4cDvdPCc(Dvd, buf))
        return 0;
    r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, buf, self + 0xC, *(int *)(self + 8), 0, 0, 0, 0);
    *(int *)(self + 0x1C) = r;
    if (!r || !*(int *)(self + 0xC)) {
        func_002CFF90(self);
        return 0;
    }
    func_002D0350(self, 1);
    return 1;
}

// FUNCTION: GAME 0x002D03E8
extern "C" int func_002D03E8(char *self)
{
    char buf[0x40];
    int r;
    if (func_002CFF68(self) == 1)
        return 0;
    *(char **)(self + 0x14) = _MemoryAlloc__FUiUiR5cHeap((((**(unsigned **)(self + 0xC)) + 0x8E) >> 1) << 2, 0x10, *(int *)(self + 8));
    switch (*(int *)(self + 0x18)) {
    case 0x80:
        sprintf(buf, D_0044D0B0, *(int *)(self + 0x20));
        break;
    case 0x81: {
        int v = *(int *)(self + 0x20);
        if (v != -1)
            sprintf(buf, D_0044D0C0, v);
        else
            sprintf(buf, D_0044D0D8, self + 0x24);
        break;
    }
    }
    r = func_001FF9C0(D_00580D40, buf, 0, 0);
    if (func_00322A68(*(int *)(self + 0x18), 0, r, *(int *)(self + 0x14)))
        return 0;
    func_002D0350(self, 4);
    return 1;
}
