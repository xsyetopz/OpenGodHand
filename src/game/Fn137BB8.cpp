extern "C" {
unsigned char HitCheck__C5cAreaRC4cVec(void *, void *);
unsigned char HitCheck__C5cAreaRC4cVecf(void *, void *, float);
}

struct AreaSet137 {
    char *areas;
    char _4[8];
    unsigned count;
    char _10[0x20];
    char *cur;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x137BB8
extern "C" int func_00137BB8(AreaSet137 *s, void *pos)
{
    if (s->areas == 0)
        return 0;
    unsigned char best = 0xFF;
    unsigned i = 0;
    char *found = 0;
    if (s->count != 0) {
        int off = 0;
        do {
            char *a = s->areas + off;
            unsigned char hit;
            if (a == s->cur)
                hit = HitCheck__C5cAreaRC4cVecf(a, pos, *(float *)(a + 0x30));
            else
                hit = HitCheck__C5cAreaRC4cVec(a, pos);
            if (hit) {
                if ((unsigned char)a[0x3E] < best) {
                    found = a;
                    best = a[0x3E];
                }
            }
            i++;
            off += 0x6C;
        } while (i < s->count);
    }
    if (found != 0) {
        s->cur = found;
        return 1;
    }
    s->cur = 0;
    return 0;
}
#endif
