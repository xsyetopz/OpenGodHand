extern int *objbaseArray;

#ifdef NONMATCHING
// DRAFT: GAME 0x2DB478
// 35 words differ: gcc folds the 0x300/0x500 range test (movn/sltiu) where original keeps slt+xori with 0x300 hoisted in t3 and an a3 copy of the object; tried unsigned short/int temp, inline helper, bool temp
extern "C" void displayOmLayer__FUib(unsigned a, int b)
{
    for (char **p = (char **)objbaseArray[1]; p != (char **)objbaseArray[2]; p++) {
        char *o = *p;
        int t = *(unsigned short *)(o + 0x2FE);
        unsigned char in = 0;
        if (t >= 0x300)
            in = t < 0x500;
        if (in && a == *(unsigned char *)(o + 0x2FD)) {
            if (b == 0)
                *(unsigned *)(o + 0x250) |= 2;
            else
                *(unsigned *)(o + 0x250) &= ~2u;
        }
    }
}
#endif
