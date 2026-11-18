// Unit at 0x14C5A0.
extern int D_007476B0;
extern char D_00754C80[];
extern "C" char *getMeshPtr__6cModeli(void *, int);
extern "C" void func_0031A600(void *, int, int, char *);
extern "C" void func_0031A650(void *, int, int, char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x14C5A0 - 55 words differ (272 vs 276 bytes): original fills call delay slots (a0 %lo, a1/a2 consts) and has v0/v1 order swapped in the head; same issue as 0x14B810. Tried (i<<2) addu operand order.
extern "C" void func_0014C5A0(char *self, short h)
{
    int i = D_007476B0 & 1;
    unsigned fl = *(unsigned *)(getMeshPtr__6cModeli(self, 0) + 0x380);
    int s = *(int *)(self + 0x2C0);
    char *e = *(char **)((int)(self + 0x220) + (i << 2));
    char *p = e + 0x70;
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
    if (p == 0)
        func_0031A600(D_00754C80, s, *(short *)(self + 0x2AC), e);
    else
        func_0031A650(D_00754C80, s, *(short *)(self + 0x2AC), e);
}
#endif
