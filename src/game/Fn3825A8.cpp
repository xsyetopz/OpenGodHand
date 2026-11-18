extern "C" int func_0032DCD0(int, int);
extern "C" void func_0032A6D0(int, int, short);

#ifdef NONMATCHING
// DRAFT: GAME 0x3825A8
// 45 words differ: gcc strength-reduces the short index into pointer increments (5 regs vs original 6 saved, a1+0x18/0x22 invariant); tried int offsets, short*/char* bases, struct arrays
extern "C" void func_003825A8(int, char *self)
{
    char *p = self + 0x30;
    int i = 0;
    if (*(int *)(p + 8) > 0) {
        char *a = self + 0x18;
        char *b = self + 0x22;
        do {
            int n = i + 1;
            int k = n << 1;
            int h = func_0032DCD0(*(int *)(p + 0x20), i);
            i = n;
            func_0032A6D0(h, 0, *(short *)((int)a + k));
            func_0032A6D0(h, 1, *(short *)((int)b + k));
        } while (i < *(int *)(p + 8));
    }
}
#endif
