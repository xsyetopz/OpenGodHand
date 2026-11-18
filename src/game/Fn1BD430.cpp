// Fn1BD430: find the first child whose id is in 0x100..0x1FE or 0x200..0x2FF, then clear the list.
extern "C" void *memset(void *, int, unsigned);

static inline int In(int v, int lo, int hi)
{
    if (v < lo) return 0;
    return v < hi;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1BD430
// 52 words: range flags (slti; daddu) fold to slti+movn and loop/null-check layout shifts; tried a=0;if(v>=lo)a=v<hi and early-return inline helper
extern "C" void func_001BD430(char *self)
{
    char *l = *(char **)(self + 0x644);
    if (l == 0) {
        *(short *)(self + 0x630) = 0;
        *(int *)(self + 0x634) = 0;
        return;
    }
    if (*(int *)(l + 0x34) != 0) {
        unsigned n = *(unsigned *)(l + 0x54);
        if (n != 0) {
            unsigned i = 0;
            char **pp = (char **)(l + 0x34);
            do {
                int v = *(unsigned short *)(*pp + 0x2FE);
                int b;
                if (In(v, 0x100, 0x1FF) == 1) goto found;
                b = In(v, 0x200, 0x300);
                i++;
                if (b == 1) {
found:
                    *(char **)(self + 0x634) = *pp;
                    *(unsigned short *)(self + 0x630) = *(unsigned short *)(self + 0x630) + 1;
                    break;
                }
                pp++;
            } while (i < n);
        }
    } else {
        *(int *)(self + 0x634) = 0;
        *(short *)(self + 0x630) = 0;
    }
    char *s = *(char **)(self + 0x644);
    memset(s + 0x34, 0, 0x20);
    *(int *)(s + 0x54) = 0;
}
#endif
