// Free-standing units from slice F156: 0x1331B8, 0x1573C8, 0x188B50, 0x1F53A8.

extern "C" void SetMoveOffsetPosXSin__12CustomIDWorkiUs(char *, int, unsigned short);
extern "C" void SetColorAnimSin__12CustomIDWorkG3COLT1Us(char *, int, int, unsigned short);
extern "C" void ResetMoveOffsetPos__12CustomIDWork(char *);
extern "C" void ResetColorAnim__12CustomIDWork(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1331B8
// 60 differing words, 244 vs 276 bytes. Diff: byte-merge block and base/index register choice.
// Tried: separate offsets per loop (60, kept), stride hoist (60), stepped shift (61), inverted flag test (62), unsigned long accumulator with k*8 (68).
extern "C" void func_001331B8(char *self, unsigned long key, int flag)
{
    char *hdr = *(char **)self;
    if (hdr == 0) {
        return;
    }
    if (*(unsigned short *)(hdr + 0x20) == 0) {
        return;
    }
    unsigned int n = 0;
    int off6 = 0;
    int off7 = 0;
    for (;;) {
        char *base = *(char **)(self + 4);
        char *p = base + off6;
        unsigned long acc = 0;
        if (*(signed char *)(p + 0xC) != 0) {
            signed char *q = (signed char *)(p + 0xC);
            int k = 0;
            do {
                acc |= (unsigned long)(long)*q << (k * 8);
                k++;
                q++;
            } while (k < 8 && *q != 0);
        }
        if (key != acc) {
            n++;
            off7 += 0x14;
            off6 += 0x14;
            if (n >= *(unsigned short *)(*(char **)self + 0x20)) {
                return;
            }
            continue;
        }
        int idx = *(unsigned short *)(base + off7 + 0xA) - 1;
        if (idx != -1) {
            int a = *(unsigned short *)(base + off7 + 0x8) * 0x14;
            do {
                if (flag != 0) {
                    *(int *)(*(char **)(self + 0x14) + a + 0x10) &= ~2;
                } else {
                    *(int *)(*(char **)(self + 0x14) + a + 0x10) |= 2;
                }
                a += 0x14;
                idx--;
            } while (idx != -1);
        }
        return;
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1573C8
// 35 differing words, sizes equal (196). Diff: load order (a[0] first vs a[2] first), c.ole.s vs c.olt.s.
// Tried: draft with < (48w), nested-if with <= (35w, kept), >= operands (42w), decl reorder (35w), !(a<b) form (41w).
extern "C" int func_001573C8(float *p, float *a, float *b, float *c, float *d)
{
    float a2 = a[2];
    float a0 = a[0];
    float f6 = p[2] - a2;
    float f7 = b[2] - a2;
    float f4 = p[0] - a0;
    float f3 = b[0] - a0;
    float f8 = d[2] - a2;
    float f5 = d[0] - a0;
    if (f3 * f6 <= f7 * f4) {
        if (f8 * f4 <= f5 * f6) {
            float f1 = c[2] - a2;
            float f0 = c[0] - a0;
            f3 = f3 - f0;
            f4 = f4 - f0;
            f6 = f6 - f1;
            f7 = f7 - f1;
            f5 = f5 - f0;
            f8 = f8 - f1;
            if (f7 * f4 <= f3 * f6 && f5 * f6 <= f8 * f4) {
                return 1;
            }
        }
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x188B50
// 76 differing words (308 vs 312). Diff: home-area block at sp+0 unmatched, frame 0x80 vs 0x90.
// Tried: separate float arrays (76), buf[16] (78), struct-by-value float arg (87, abandoned), 8-arg prototype with junk int (76, kept).
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int, int, float, float, float, float);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001C28A0(char *, char *, int, int);
extern char g_DmgManage[];

extern "C" int func_00188B50(char *self)
{
    float buf[16];
    void *t;
    float one = 1.0f;

    func_001B6FB8(self);
    buf[4] = 4.4f;
    buf[5] = 1.6f;
    buf[6] = 0.3f;
    buf[7] = one;
    buf[8] = 0.0f;
    buf[9] = 0.0f;
    buf[10] = 0.0f;
    buf[11] = one;
    int junk;
    t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2, junk, 4.4f, 1.234f, 0.3f, one);
    *(void **)(self + 0x600) = t;
    if (t != 0) {
        buf[12] = 0.0f;
        buf[13] = 0.0f;
        buf[14] = 0.0f;
        buf[15] = one;
        func_001FD9D8(t, self + 0x80, buf + 8, buf + 12, buf + 4);
    }
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(short *)(self + 0x5F6) = 0;
    *(short *)(self + 0x54A) = 1;
    *(void **)(self + 0x608) = self + 0x620;
    *(unsigned char *)(self + 0x60C) = 6;
    *(int *)(self + 0x5EC) = 0xC9;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    func_001C28A0(self, self + 0x620, 6, 0xC9);
    return 1;
}
#endif

// FUNCTION: GAME 0x1F53A8
extern "C" void func_001F53A8(char *self, int flag)
{
    int c1;
    int c2;
    if (flag != 0) {
        SetMoveOffsetPosXSin__12CustomIDWorkiUs(self + 0x440, 3, 0x10);
        c1 = ((((((c1 & ~0xFF) | 0x80) & ~0xFF00) | 0x8000) & ~0xFF0000) | 0x800000) & 0xFFFFFF | 0x80000000;
        c2 = ((((((c2 & ~0xFF) | 0xC0) & ~0xFF00) | 0xC000) & ~0xFF0000) | 0xC00000) & 0xFFFFFF | 0x80000000;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x4BC, c1, c2, 4);
        return;
    }
    ResetMoveOffsetPos__12CustomIDWork(self + 0x440);
    ResetColorAnim__12CustomIDWork(self + 0x4BC);
}
