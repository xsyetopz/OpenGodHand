extern "C" unsigned int irand__Fv(void);

struct Slot {
    unsigned int a;
    int flags;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1D45A0
// 36 words differ: gcc reverses the loop counter (t0 counts down from 0x33, original counts up with slti); tried unsigned/long/short/uchar counter, i++ position, array indexing
extern "C" void func_001D45A0(char *self, Slot **out, unsigned int idx) {
    Slot *list[52];
    unsigned short n = idx;
    int i = 0;
    int cnt = 0;
    int a3 = (int)self + 0x1634;
    unsigned int *a1 = (unsigned int *)((int)self + 0x1638);
    Slot **p = list;
    do {
        i++;
        unsigned long f = *a1;
        unsigned long b = f & 1;
        if (b) {
            *p = (Slot *)a3;
            cnt++;
            p++;
        }
        a3 += 8;
        a1 += 2;
    } while (i < 52);
    if (cnt) {
        if (n == 0xFFFF)
            *out = list[irand__Fv() % (unsigned)cnt];
        else
            *out = (Slot *)(self + (n * 8 + 0x1634));
        (*out)->flags &= -2;
    }
}
#endif
