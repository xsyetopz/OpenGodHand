extern int D_00747A78;
extern int D_00755800;
extern int D_00755804;
extern char *D_00755840;

#ifdef NONMATCHING
// DRAFT: GAME 0x31BDC8 - 3 words differ: lw D_00755800/D_00755840 register swap (v0/v1) in the copy loop
extern "C" void func_0031BDC8(char *self)
{
    unsigned long f = D_00747A78;
    unsigned long b = (f >> 5) & 1;
    if (b) {
        char *dst = self + 0x100;
        int i;
        for (i = 0; i < 32; i++) {
            dst[i] = *((D_00755800 << 5) + D_00755840 + i);
        }
        int n = D_00755800 + 1;
        D_00755800 = n;
        if (n >= D_00755804) {
            D_00747A78 = D_00747A78 & ~0x20;
        }
    }
}
#endif

extern unsigned D_00747A2C[];
extern unsigned D_00747A88;
extern int D_00747A24;
extern char *SaveLoad;
extern "C" void openLoad__9cSaveLoad(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x160F38 - flag test ok (lw/dsrl/andi); shared return-1 tail, switch/beql layout and D_00747A24 base reg differ
extern "C" int func_00160F38(char *self)
{
    int *g = (int *)D_00747A2C;
    if (!(g[2] & 0x800) && g[3] >= 0) {
        unsigned long f = g[3];
        unsigned long b = (f >> 6) & 1;
        if (!b) {
            short s = *(short *)(self + 0x52);
            switch (s) {
            case 0:
                openLoad__9cSaveLoad(SaveLoad);
                *(unsigned short *)(self + 0x52) = *(unsigned short *)(self + 0x52) + 1;
            case 1:
                if (D_00747A88 & 0x40000000) {
                    return 0;
                }
            default:
                D_00747A24 &= -3;
                *(short *)(self + 0x52) = 0;
            }
        }
    }
    return 1;
}
#endif

extern int D_00747A84[];

#ifdef NONMATCHING
// DRAFT: GAME 0x2BF420 - 2 words differ: constants 4/1 load order (v1/v0) in the branch
extern "C" void func_002BF420(char *p)
{
    if (D_00747A84[1] >= 0) {
        unsigned long f = D_00747A84[-24];
        unsigned long b = (f >> 6) & 1;
        if (b) {
            p[0xC] = 1;
            p[0] = 4;
            p[3] = 0;
        } else {
            p[3] = 0;
            p[0] = 5;
        }
        p[2] = 0;
        p[1] = 0;
    }
}
#endif
