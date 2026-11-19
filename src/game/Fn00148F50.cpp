extern "C" void func_001F8A88(void *, float, float, float, float, float, float);
extern "C" int func_00150D78(void *, int);
extern "C" void func_003090F8(unsigned char, int, int, int);
extern "C" void func_00309D88(int, int, int, int, int);
extern "C" void func_0030A200(int);
extern "C" int func_0030A298(int);
extern "C" char D_00747BA0[];
extern "C" int func_0031A650(void *, int, int, int);
extern char D_00754C80[];

#ifdef NONMATCHING
// DRAFT: GAME 0x00148F50
// 2 words: addu operand order at 0x148FAC and 0x148FC0 (compiled puts the loaded offset in rt, original in rs); 9 variants tried: operand-order t6-t8, separate offset temp t9, += forms (12 words)
extern "C" void func_00148F50(void *unused, char **pp, void *out)
{
    float minx = 1e9f, maxx = -1e9f, miny = 1e9f, maxy = -1e9f, minz = 1e9f, maxz = -1e9f;
    char *base = *pp;
    char *volatile spill;
    int n = *(unsigned short *)(base + 0xA);
    int i = 0;
    if (n != 0) {
        char *tab = base + 0x20;
        do {
            char *m = base + *(int *)(tab + (i << 2));
            spill = m;
            float *v = (float *)(m + *(int *)m);
            unsigned int cnt = *(unsigned short *)(m + 0x14);
            if (cnt != 0) {
                do {
                    float t = (float)*(short *)((char *)v + 0);
                    if (t < minx) minx = t;
                    if (maxx < t) maxx = t;
                    t = (float)*(short *)((char *)v + 2);
                    if (t < miny) miny = t;
                    if (maxy < t) maxy = t;
                    t = (float)*(short *)((char *)v + 4);
                    if (t < minz) minz = t;
                    if (maxz < t) maxz = t;
                    v = (float *)((char *)v + 8);
                } while (--cnt != 0);
            }
            i++;
        } while (i < n);
    }
    func_001F8A88(out, minx / 100.0f, maxx / 100.0f, miny / 100.0f, maxy / 100.0f, minz / 100.0f, maxz / 100.0f);
}
#endif

// FUNCTION: GAME 0x00150C10
extern "C" int func_00150C10(char *s, int idx, int mode)
{
    int ret = -1;
    if (idx != 0) {
        if (mode == 0) {
            unsigned char b = *(unsigned char *)(s + 4);
            int r = func_0030A298(*(int *)(s + 0xC));
            func_003090F8(b, idx, *(int *)(s + 8), r);
            ret = *(int *)(s + 4);
            *(int *)s = *(int *)s + 1;
            char *e = D_00747BA0 + ret * 0xB0;
            *(int *)(s + 4) = ret + *(unsigned short *)(e + 0x10);
            *(int *)(s + 0xC) = *(int *)(s + 0xC) + *(unsigned char *)(e + 2);
            *(int *)(s + 8) = *(int *)(s + 8) + *(unsigned short *)(e + 0x12);
        }
        if (mode == 1) {
            int r = func_00150D78(s, idx);
            if (r == -1) {
                func_00309D88(*(int *)(s + 4), idx, *(int *)(s + 8), *(int *)(s + 0xC), 1);
                func_0030A200(*(int *)(s + 4));
                ret = *(int *)(s + 4);
                *(int *)s = *(int *)s + 1;
                char *e = D_00747BA0 + ret * 0xB0;
                char *e14 = *(char **)(e + 0x14);
                *(int *)(s + 4) = ret + *(unsigned short *)(e + 0x10);
                *(int *)(s + 0xC) = *(int *)(s + 0xC) + *(unsigned short *)(e14 + 0x12);
                *(int *)(s + 8) = *(int *)(s + 8) + *(unsigned short *)(e + 0x12);
            } else {
                ret = r;
            }
        }
    }
    return ret;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x002FF748
// 82 words (320 vs 344 bytes): switch and bit-test shape right, six instructions short; obj/p1/p2 register mapping (t2/t1/t3 in original) and one clamp (6 insns) missing; variants: a1=4 placement, clamp in both arms (84 words), re-read of obj+0x101, fourth parameter
extern "C" int func_002FF748(char *obj, int p1, int p2)
{
    int t1 = p1;
    int a1 = 2;
    if ((*(unsigned *)(obj + 0x11C) & 0x01000000) == 0) {
        a1 = 4;
        switch ((signed char)((unsigned char)obj[0x101] + 2)) {
        case 0: t1 = 0xC; break;
        case 1: t1 = 0xB; break;
        case 2: t1 = 0xA; break;
        case 3: t1 = 9; break;
        case 4: t1 = 8; break;
        case 5: a1 = 6; t1 = 7; break;
        case 6: a1 = 6; t1 = 3; break;
        }
    } else {
        if (t1 > 0x3FC) t1 = 0x3FC;
        if (t1 < 0) t1 = 0;
    }
    unsigned w = *(unsigned *)(obj + 0x11C);
    if (w & 0x2000) {
        a1 = 3;
        if (w & 0x4000) t1 = 1;
        else t1 = 2;
    } else if (w & 0x4000) {
        a1 = 3;
        t1 = 5;
    }
    int c = (signed char)(unsigned char)obj[0x101];
    if (c == 3) {
        a1 = 6;
        t1 = 7;
    } else if (c == 4) {
        a1 = 6;
        t1 = 3;
    }
    return func_0031A650(D_00754C80, a1, t1, p2);
}
#endif
