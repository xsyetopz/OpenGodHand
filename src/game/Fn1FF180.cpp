extern char Dvd[];
extern "C" int func_003078E0(int);
extern "C" int FileNameFromObjId__FPc6eObjId(char *, int);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(char *, char *, char *, int, int, int, int, int);

// FUNCTION: GAME 0x1FF180
extern "C" int func_001FF180(int *self, int id, int heap)
{
    char name[16];
    int v = func_003078E0(id);
    self[5] = heap;
    FileNameFromObjId__FPc6eObjId(name, id);
    int r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, name, (char *)(self + 4), self[5], 0, 0, 0, 0);
    self[7] = r;
    if (!r)
        return 0;
    {
        self[3] = v;
        self[0] = 1;
        self[2] |= 1;
        self[8] = id;
    }
    return self[4];
}
