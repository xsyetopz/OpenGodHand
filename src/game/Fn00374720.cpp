// Unit at 0x374720.
struct Tw {
    int on;
    int p4, p8;
    int n;
    char pad[0xC];
    float cur[2];
    float tgt[2];
    char pad2[0x34 - 0x2C];
    float hi;
    float lo;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x374720 - 58 words differ: original keeps this in a2 with counter in a0, reads cur[i] as -8(tgt ptr), no bc1fl; ours uses a0 for this and a cur-based pointer. Tried ternary, per-arm pointer assigns, tgt[i-2] read.
extern "C" void func_00374720(Tw *t, int idx, float x, float y)
{
    if (t->on) {
        if (idx == -1) {
            for (int i = 0; i < t->n; i++) {
                float v;
                float *p;
                if (y == 0.0f) {
                    if (x <= t->cur[i]) {
                        p = t->cur;
                        v = t->lo;
                    } else {
                        p = t->cur;
                        v = t->hi;
                    }
                } else {
                    v = y;
                    p = t->cur;
                }
                t->tgt[i] = v;
                *(float *)((int)p + (i << 2)) = x;
            }
        } else {
            float *p;
            float v;
            int o;
            if (y == 0.0f) {
                o = idx << 2;
                p = t->cur;
                if (x <= *(float *)((int)p + o))
                    v = t->lo;
                else
                    v = t->hi;
            } else {
                v = y;
                o = idx << 2;
                p = t->cur;
            }
            *(float *)((int)t + o + 0x24) = v;
            *(float *)((int)p + o) = x;
        }
    }
}
#endif
