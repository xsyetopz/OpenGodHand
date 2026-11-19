extern "C" void func_001C6C30(char *, void *);

#ifdef NONMATCHING
static inline char *getMesh(char *o, int i)
{
    unsigned char n = *(unsigned char *)(o + 0x2B4);
    volatile int sp = n;
    return i < n ? *(char **)(*(char **)(o + 0x278) + (i << 2)) : 0;
}

// DRAFT: GAME 0x1C6B68
// 7 words differ (lbu/lw via t0 not a1, spill sw order, lw 0x40 sched); tried: volatile spill/reload, inline getMesh, m=obj placement, addu operand order (7, tie), nonvolatile s (9), int n (48), flipped ternary (7, tie), tern (42), s-first (7, tie), addu+s (7, tie), addu flip (7, tie).
extern "C" void initMove3_y__6cOmSubP4cObjiRC4cVecfff(char *self, char *obj, int idx, void *vec, float, float, float)
{
    if (obj) {
        char *m = obj;
        if (idx >= 0) m = getMesh(obj, idx);
        if (m) {
            *(char **)(self + 4) = obj;
            *(char **)(self + 8) = m;
            *(float **)(self + 0x40) = (float *)(idx >= 0 ? *(char **)(m + 0xD0) : *(char **)(m + 0xF0));
            float *s = *(float *volatile *)(self + 0x40);
            float *d = (float *)(self + 0x70);
            if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
            d = (float *)(self + 0x80);
            s = (float *)(m + 0x100);
            if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
        }
    }
    func_001C6C30(self, vec);
}
#endif
