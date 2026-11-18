extern unsigned short D_00770850[];
extern "C" {
void func_00376400(unsigned short *);
void func_00376438(unsigned short *);
void func_00376720(unsigned short *);
void func_003767B0(unsigned short *);
void func_00376820(unsigned short *);
void func_00376B80(unsigned short *, unsigned short *);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x376370 - 8 words: delay-slot fill and andi register differ (v1 vs v0), inner skip uses beqz not beql; tried m2c shape, swapped arms, reload of *p
extern "C" void func_00376370()
{
    unsigned short *p = D_00770850;
    unsigned short *e = p + 0x1500;
    do {
        unsigned short v = *p;
        if (v) {
            if (v & 0x1000) func_00376400(p);
            else func_00376438(p);
            if (*p) {
                func_00376720(p);
                func_003767B0(p);
                func_00376820(p);
            }
        }
        p += 0x70;
    } while ((int)p < (int)e);
}

// DRAFT: GAME 0x376720 - 19 words: loop counter decrement hoisted to loop head and lhu/ori scheduling differ; tried do-while with n-=1, for(i=7;i>=0;i--,s++) with struct, preloaded v
extern "C" void func_00376720(unsigned short *t)
{
    unsigned short *s = t + 0x20;
    int n = 7;
    do {
        unsigned short v = *s;
        if (v && !(v & 2)) {
            if (*(short *)(s + 9) == 0) {
                *s = v | 2;
                func_00376B80(t, s);
            } else {
                s[9] = s[9] - 1;
            }
        }
        s += 10;
    } while (--n >= 0);
}
#endif
