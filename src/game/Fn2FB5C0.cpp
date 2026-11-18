extern char D_0061B7C0[];
extern unsigned int D_0071B7C0[];
extern unsigned int D_0071B840[];
extern unsigned int D_0071B8C0[];
extern "C" void func_002FEB80(char *, int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x2FB5C0
// 51 words differ: i++ hoisted above the srlv and loop test cloned into each exit (orig puts i++ in bnel delay slots); tried unsigned/int i, for+continue, do-while, indexed D_ arrays.
extern "C" void func_002FB5C0(int a, int b)
{
    char *p = D_0061B7C0;
    int i = 0;
    do {
        unsigned w = (unsigned)i >> 5;
        unsigned bit = 0x80000000U >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) && !(D_0071B840[w] & bit) && !(D_0071B8C0[w] & bit)
            && *(int *)(p + 0x10C) == b && *(int *)(p + 0x108) == a)
            func_002FEB80(p, a, b);
        i++;
        p += 0x400;
    } while (i < 0x400);
}
#endif
