#ifdef NONMATCHING
// DRAFT: GAME 0x158198
// 53 words: lbu 0x155 flag test emits xori (u8 idiom), 0.0f folds to sw $zero not mtc1 f4, reg alloc n/i differ; tried zero/one float locals, volatile sp0, continue form, unsigned fl
extern "C" void func_00158198(char *self)
{
    char *n = *(char **)(self + 0x144);
    if (n) {
        char *a = *(char **)(self + 0x280);
        int i = 0;
        char *t = a + *(int *)(a + 0x10);
        float zero = 0.0f, one = 1.0f;
        char *volatile sp0 = t + *(int *)t;
        do {
            unsigned fl = *(int *)(n + 0x154);
            if (fl & 1) {
                n = *(char **)(n + 0x144);
                i++;
                continue;
            }
            {
                float *src = (float *)(sp0 + *(int *)(sp0 + 4) + (i << 4));
                if (!(fl & 0x200)) {
                    float *d = (float *)(n + 0xE0);
                    d[0] = src[0];
                    d[1] = src[1];
                    d[2] = src[2];
                    float *o = *(float **)(n + 0xD0);
                    if (o != d) {
                        o[0] = d[0];
                        o[1] = d[1];
                        o[2] = d[2];
                    }
                }
                unsigned char f2 = *(unsigned char *)(n + 0x155);
                if (!(f2 & 1)) {
                    *(float *)(n + 0x108) = zero;
                    *(float *)(n + 0x104) = zero;
                    *(float *)(n + 0x100) = zero;
                }
                if (!(*(unsigned *)(n + 0x154) & 0x400)) {
                    *(float *)(n + 0x118) = one;
                    *(float *)(n + 0x114) = one;
                    *(float *)(n + 0x110) = one;
                }
            }
            n = *(char **)(n + 0x144);
            i++;
        } while (n);
    }
}
#endif
