#ifdef NONMATCHING
// DRAFT: GAME 0x2C3058
// 17 words: original keeps w (flag test) and v (copy) in v0/v1 with *p reloaded at entry; ours CSEs the loads. Tried volatile, signed/unsigned, while-form.
extern "C" void func_002C3058(void *self, unsigned int *p, unsigned int *target)
{
    if (*p != 0xFFFFFFFF) {
        unsigned int w = *p;
        unsigned int v = w;
        while (1) {
            if ((w & 0x80000000) && (v & 0x7FFFFFFF) == (unsigned int)target) {
                *p = *target;
                return;
            }
            p = (unsigned int *)(v & 0x7FFFFFFF);
            w = *p;
            v = w;
            if (w == 0xFFFFFFFF)
                break;
        }
    }
}
#endif
