// God Hand: 0x2956F0, 0x2A2D60, 0x2ABA78, 0x2B0F20
extern "C" char *func_00295660(char *self);
extern "C" int irand__Fv(void);
extern "C" void func_002ABC18(char *, char *);
extern "C" void func_002ABC30(char *, char *);
extern "C" void func_002ABCE8(char *, char *);
extern "C" void func_002ABD30(char *, char *);
extern "C" void func_002ABD78(char *, char *);
extern "C" int func_002AF348(int);
extern "C" int func_002A4B88(void *, unsigned short);
extern "C" char *getMessageAddr__C8cMessageUs(char *, unsigned short);
extern char *g_Sce;
extern void *Font;
extern char *Message;

typedef float *(*Fn84)(char *, int);
typedef float *(*Fn8C)(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2956F0
// 78 words (352 vs 368 bytes): range check lacks target slti/andi form; typed-local stores gave 81.
extern "C" void func_002956F0(char *arg0, char *arg1)
{
    if (*(unsigned char *)(g_Sce + 0x14) == 1) return;
    if (arg1 == 0) return;
    int type = *(unsigned short *)(arg1 + 0x2FE);
    if (!(type >= 0x200 && type < 0x300)) return;
    if (*(short *)(arg1 + 0x54A) <= 0) return;
    if (type != 0x220 && type != 0x223) return;
    char *p = func_00295660(arg0);
    if (p == 0) return;
    *(unsigned char *)(p + 0x12) = *(unsigned short *)(arg1 + 0x2FE);
    *(unsigned char *)(p + 0x11) = *(int *)(arg1 + 0x564);
    *(int *)(p + 0x8) = *(int *)(arg1 + 0x1644);
    *(unsigned char *)(p + 0x10) = 0x1E;
    *(int *)(p + 0xC) = *(int *)(arg1 + 0x164C);
    char *obj = *(char **)(arg1 + 0x214);
    float *v = ((Fn84)*(void **)(obj + 0x84))(arg1 + *(short *)(obj + 0x80), 0x1E);
    *(short *)(p + 0x0) = (short)(v[0] * 20.0f);
    *(short *)(p + 0x2) = (short)(v[1] * 20.0f);
    *(short *)(p + 0x4) = (short)(v[2] * 20.0f);
    obj = *(char **)(arg1 + 0x214);
    float *w = ((Fn8C)*(void **)(obj + 0x8C))(arg1 + *(short *)(obj + 0x88));
    *(short *)(p + 0x6) = (short)(w[1] * 57.2958f);
    short m = *(short *)(arg1 + 0x54A);
    *(short *)(p + 0x16) = (m <= 0) ? 0 : m;
    *(unsigned char *)(p + 0x13) = 0xFF;
}
#endif

// FUNCTION: GAME 0x2A2D60
extern "C" void func_002A2D60(short *keys, int *vals, int lo, int hi)
{
    short pivot = keys[(lo + hi) / 2];
    int i = lo;
    int j = hi;
    for (;;) {
        while (keys[i] < pivot) i++;
        while (pivot < keys[j]) j--;
        if (i < j) {
            short tk = keys[i];
            keys[i] = keys[j];
            keys[j] = tk;
            int tv = vals[i];
            vals[i] = vals[j];
            vals[j] = tv;
            i++;
            j--;
            continue;
        }
        break;
    }
    if (lo < i - 1) func_002A2D60(keys, vals, lo, i - 1);
    if (j + 1 < hi) func_002A2D60(keys, vals, j + 1, hi);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2ABA78
// 77 words (372 vs 364 bytes): target divides by a register-held 9999 with zero check; local mod kept 77.
extern "C" void resetAnim__7cIDBase(char *self)
{
    *(short *)(self + 0x1A) = 0;
    *(unsigned char *)(self + 0x1D) = 0;
    *(unsigned char *)(self + 0x1E) = 0;
    if (*(char **)(self + 0x4) != 0) {
        int i = 0;
        if (*(int *)(self + 0xC) > 0) {
            int off = 0;
            do {
                char *e = *(char **)(self + 0x4) + off;
                if (e != 0) {
                    if (!(((unsigned long)*(unsigned int *)(e + 0x2C) >> 6) & 1)) {
                        *(short *)(e + 0xA0) = 0;
                        *(short *)(e + 0xA2) = 0;
                        *(short *)(e + 0xA6) = 0;
                        *(short *)(e + 0xA8) = 0;
                        *(short *)(e + 0xA4) = 0;
                    } else {
                        unsigned int mod = 9999U;
                        *(short *)(e + 0xA0) = (short)(irand__Fv() % mod);
                        *(short *)(e + 0xA2) = (short)(irand__Fv() % mod);
                        *(short *)(e + 0xA6) = (short)(irand__Fv() % mod);
                        *(short *)(e + 0xA8) = (short)(irand__Fv() % mod);
                        *(short *)(e + 0xA4) = (short)(irand__Fv() % mod);
                    }
                    func_002ABC18(self, e);
                    func_002ABC30(self, e);
                    func_002ABCE8(self, e);
                    func_002ABD30(self, e);
                    func_002ABD78(self, e);
                }
                i += 1;
                off += 0xAC;
            } while (i < *(int *)(self + 0xC));
        }
    }
}
#endif

// FUNCTION: GAME 0x2B0F20
extern "C" float func_002B0F20(char *arg0, int arg1, float *arg2)
{
    int s1 = arg1;
    int s0 = 1;
    unsigned temp_v0 = func_002AF348(s1);
    float f20 = 0.0f;
    unsigned v1 = 1;
    if ((unsigned)s0 < temp_v0) {
        do {
            v1 += 1;
            s0 *= 10;
        } while (v1 < temp_v0);
    }
    if (s0 != 0) {
        do {
            int lo = s1 / s0;
            char *mt = getMessageAddr__C8cMessageUs(Message, 4);
            float f3 = (float)func_002A4B88(Font, *(unsigned short *)(mt + lo * 2))
                       * (*arg2 * *(float *)(arg0 + 0x40) * *(float *)(arg0 + 0x48));
            if (f20 < f3) f20 = f3;
            int prod = lo * s0;
            s0 = s0 / 10;
            s1 -= prod;
        } while (s0 != 0);
    }
    if (*(unsigned int *)(arg0 + 0x0) & 1) {
        f20 = f20 + ((*(float *)(arg0 + 0x38) + 12.0f) * *(float *)(arg0 + 0x48));
    }
    return f20;
}
