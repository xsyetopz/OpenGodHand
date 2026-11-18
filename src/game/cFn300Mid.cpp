// Medium unnamed functions in 0x300000-0x31BFFF.
extern "C" void func_002A9528(void *);
extern "C" void func_002C53A8(void *);
extern char D_00754200[], SoundHeap[], RoomHeap[], SubScrHeap[], D_00754240[];
extern char D_00754C10[], D_00754C20[], scrArray[], D_00754C50[];
extern int objArray, objbaseArray;
unsigned int *SearchData(unsigned int *, const char *, unsigned int);
extern char D_0044FEA0[];

struct SrchPair { unsigned *b; unsigned *a; };

// FUNCTION: GAME 0x30EE68
extern "C" void func_0030EE68(void *p, int f)
{
    if (f == 0xFFFF && p) {
        func_002A9528(D_00754200);
        func_002A9528(SoundHeap);
        func_002A9528(RoomHeap);
        func_002A9528(SubScrHeap);
        func_002A9528(D_00754240);
    }
}

// FUNCTION: GAME 0x305358
extern "C" void func_00305358(unsigned *self, unsigned *d)
{
    self[1] = (unsigned)SearchData(d, D_0044FEA0, 0);
    self[0] = (unsigned)SearchData(d, D_0044FEA0, 1);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3182D8
// 4 words differ: lui registers for the last two stores (D_00754C50 / objbaseArray) come out swapped
extern "C" void func_003182D8(void *p, int f)
{
    if (f == 0xFFFF && p) {
        func_002A9528(D_00754C10);
        func_002A9528(D_00754C20);
        objArray = 0;
        func_002C53A8(scrArray);
        objbaseArray = 0;
        *(int *)D_00754C50 = 0;
    }
}
#endif

