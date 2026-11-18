extern "C" int func_001F8AD8(void *, void *, void *, void *);
extern unsigned char D_00747A80[];
extern unsigned int D_00747A2C;
extern unsigned char scrArray[];

#ifdef NONMATCHING
// DRAFT: GAME 0x319848
// 31 words differ: self copy lands in t0 not a2 (cascades), one extra insn; tried d pointer, early-return vs nested, local self copy
extern "C" int func_00319848(char *self)
{
    unsigned char *d = D_00747A80;
    if (!(*(unsigned int *)d & 0x8000000)) {
        unsigned long b = d[-0x53];
        if (b >> 7)
            return 0;
        if (scrArray[4]) {
            if (*(int *)(scrArray + 8) <= 0 && (*(unsigned int *)(*(char **)(self + 0x320) + 0x34) & 0x200))
                return 1;
        } else {
            if (*(int *)(scrArray + 8) <= 0 && (*(unsigned char *)(*(char **)(self + 0x320) + 0x35) & 1))
                return 1;
        }
        if (*(unsigned char *)(self + 0x32D)) {
            if (scrArray[5] == 0)
                return 1;
        } else {
            if (scrArray[5] == 1)
                return 1;
        }
        unsigned int f = *(unsigned int *)(self + 0x250);
        if (f & 2)
            return 1;
        if (f & 0x10000)
            return 0;
        if (func_001F8AD8(self + 0x260, self + 0x80, self, d)) {
            unsigned t = D_00747A2C & 0x4000000;
            return t != 0;
        }
    }
    return 1;
}
#endif
