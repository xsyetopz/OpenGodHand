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
// DRAFT: GAME 0x374720
extern "C" void func_00374720(Tw *t, int idx, float x, float y)
{
    if (t->on) {
        if (idx == -1) {
            for (int i = 0; i < t->n; i++) {
                float v = y;
                float *p = t->cur;
                if (y == 0.0f) {
                    if (x <= t->cur[i])
                        v = t->lo;
                    else
                        v = t->hi;
                }
                t->tgt[i] = v;
                *(float *)((int)p + (i << 2)) = x;
            }
        } else {
            float *p = t->cur;
            float v = y;
            if (y == 0.0f) {
                if (x <= p[idx])
                    v = t->lo;
                else
                    v = t->hi;
            }
            t->tgt[idx] = v;
            p[idx] = x;
        }
    }
}
#endif
