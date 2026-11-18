extern "C" void SetMotionRun__5cOm71(void *);
extern "C" void SetMotionStep__FP8cObjBasef(void *, float);

struct F082M {
    int w[9];
};

static inline bool F082dec(int &x)
{
    if (x != 0) {
        x--;
        return false;
    }
    return true;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1EBB78
// 17 words differ: z/c register choice and bnel with n-- in delay slot; tried do-while, for+continue, inline dec helper, unsigned char z, c-- form.
extern "C" void func_001EBB78(char *self)
{
    char *p = self + 0x5C;
    int n = 4;
    do {
        long f = *(unsigned *)(p + 0x30);
        long b = (f >> 1) & 1;
        if (!b) {
            int c = *(int *)(p + 0xC);
            int z;
            if (c != 0) {
                z = 0;
                *(int *)(p + 0xC) = c - 1;
            } else {
                z = 1;
            }
            if ((unsigned char)z) {
                F082M m = *(F082M *)(p + 8);
                *(int *)(p + 0x30) |= 2;
                SetMotionRun__5cOm71(*(void **)p);
                float v = *(float *)&m.w[2];
                SetMotionStep__FP8cObjBasef(*(void **)p, v);
            }
        }
        n--;
        p += 0x40;
    } while (n >= 0);
}
#endif
