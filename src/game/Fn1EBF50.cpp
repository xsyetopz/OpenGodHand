extern "C" void calcParts__6cModel(char *);

static inline int bit(unsigned long n) { return 1 << n; }

#ifdef NONMATCHING
// DRAFT: GAME 0x001EBF50
// 56 words: orig shifts with dsllv (untruncated 64-bit count) then dsll32/dsra32; ours truncates count + sllv; tried 1L<<a, (long) count casts (70)
extern "C" void func_001EBF50(char *self, int arg1, int arg2) {
    unsigned i = arg1 & 0xFFFF;
    if (i < 5) {
        unsigned long a = i + 1;
        int b = i * 2 + 1;
        unsigned long c = i + 6;
        if (arg2 != 0) {
            if (a < 0x20) {
                *(int *)(self + 0x54) |= bit(a);
            }
            if (c < 0x20) {
                *(int *)(self + 0x54) |= bit(c);
            }
        } else {
            char *t = self + 0x1C4;
            char **p = (char **)(t + (i << 3));
            if (*p != 0) {
                char **q = (char **)(t + (b << 2));
                if (*q != 0) {
                    *(int *)(*p + 0x104) = 0;
                    *(int *)(*q + 0x104) = 0;
                    calcParts__6cModel(*p);
                    calcParts__6cModel(*q);
                    if (a < 0x20) {
                        *(int *)(self + 0x54) &= ~bit(a);
                    }
                    if (c < 0x20) {
                        *(int *)(self + 0x54) &= ~bit(c);
                    }
                }
            }
        }
    }
}
#endif
