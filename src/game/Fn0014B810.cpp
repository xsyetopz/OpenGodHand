// Unit at 0x14B810.
extern int D_007476B0;
extern char D_00754C80[];
extern "C" void func_0031A600(void *, int, int, char *);
extern "C" void func_0031A650(void *, int, int, char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x14B810
extern "C" void func_0014B810(char *self, char *o, short h)
{
    int i = D_007476B0 & 1;
    int s = *(int *)(self + 0x2C0);
    unsigned fl = *(unsigned *)(o + 0x380);
    char *e = o + i * 0xB0;
    char *p = e + 0xA0;
    if (s == 10) {
        if (fl & 0x4080) {
            if (p == 0)
                func_0031A600(D_00754C80, 2, h, e);
            else
                func_0031A650(D_00754C80, 2, h, e);
            return;
        }
        if (p == 0)
            func_0031A600(D_00754C80, 1, 13, e);
        else
            func_0031A650(D_00754C80, 1, 13, e);
        return;
    }
    short a = *(short *)(self + 0x2AC);
    if (p == 0)
        func_0031A600(D_00754C80, s, a, e);
    else
        func_0031A650(D_00754C80, s, a, e);
}
#endif
