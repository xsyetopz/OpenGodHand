// Unit at 0x30D258.
extern char D_00753DC0[];
extern "C" void func_00395430(void *, int, int, int, int, int, int, int);
extern "C" void func_00395758(void *, void *);
extern "C" void FlushCache(int);
extern "C" int sceGsSyncPath(int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x30D258
extern "C" void func_0030D258()
{
    char li[0x60];
    int i;
    for (i = 0x3FF; i >= 0; i--)
        D_00753DC0[i] = 0;
    long n = 0x400000L >> 8;
    int j = 0;
    if (n != 0) {
        int k = 0;
        do {
            j++;
            func_00395430(li, (short)k, 0x40000 >> 16, 0, 0, 0, 0x100000 >> 16, 0x100000 >> 16);
            k += 4;
            FlushCache(0);
            func_00395758(li, D_00753DC0);
            sceGsSyncPath(0, 0);
        } while (j < n);
    }
}
#endif
