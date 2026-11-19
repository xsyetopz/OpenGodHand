typedef int fn_u128 __attribute__((mode(TI)));
struct fn_blk20 { fn_u128 q[2]; };

extern "C" void func_002B45B0(void *);
extern char *pCamWork;
extern char D_005E75B0[];
extern int D_00747A84;

#ifdef NONMATCHING
// DRAFT: GAME 0x2B4428 - 24 differing words: copy loops use a1/a2/a0 where target uses v0/v1/a0 (lui/addiu coalescing); tried do-while, d-first, char*, end-first, top-level decls
extern "C" int func_002B4428(char *self, int a1, int a2)
{
    if (*(int *)(self + 0xB4) == a1 && *(int *)(self + 0x40) == a2)
        return 0;
    if (D_00747A84 & 0x20000000)
        return 0;
    if (a1 == 0) {
        func_002B45B0(self);
        fn_blk20 *d = (fn_blk20 *)pCamWork;
        fn_blk20 *s = (fn_blk20 *)D_005E75B0;
        fn_blk20 *end = s + 27;
        do {
            *d++ = *s++;
        } while (s != end);
    } else if (*(int *)(self + 0xB4) == 0) {
        fn_blk20 *s = (fn_blk20 *)pCamWork;
        fn_blk20 *d = (fn_blk20 *)D_005E75B0;
        fn_blk20 *end = s + 27;
        do {
            *d++ = *s++;
        } while (s != end);
    }
    *(int *)(self + 0xB4) = a1;
    *(int *)(self + 0x40) = a2;
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x296DD8 - matches under fncmp -q (276 bytes) with placeholder externs; stays under NONMATCHING because the placeholder symbols do not link; flag bit 2 of word at +8 gates 19 calls
extern "C" void func_placeholder_void(void *);
extern "C" int func_placeholder_ret(void *);
extern char D_placeholder_s0[];
extern char D_ph00[], D_ph01[], D_ph02[], D_ph03[], D_ph04[];
extern char D_ph05[], D_ph06[], D_ph07[], D_ph08[], D_ph09[];
extern char D_ph10[], D_ph11[], D_ph12[], D_ph13[], D_ph14[];

extern "C" int func_00296DD8(char *self)
{
    unsigned long bits = (unsigned long)(long)*(int *)(self + 8);
    if (((bits >> 2) & 1) == 0)
        return 0;
    char *s0 = D_placeholder_s0;
    func_placeholder_void(s0);
    func_placeholder_void(s0);
    func_placeholder_void(s0);
    func_placeholder_void(D_ph00);
    func_placeholder_void(D_ph01);
    func_placeholder_void(D_ph02);
    func_placeholder_void(D_ph03);
    func_placeholder_void(D_ph04);
    func_placeholder_void(D_ph05);
    func_placeholder_void(D_ph06);
    func_placeholder_void(D_ph07);
    func_placeholder_void(D_ph08);
    func_placeholder_void(D_ph09);
    func_placeholder_void(D_ph10);
    func_placeholder_void(D_ph11);
    func_placeholder_void(D_ph12);
    func_placeholder_void(D_ph13);
    func_placeholder_void(D_ph14);
    return func_placeholder_ret(s0);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x26A200 - 76 differing words: packed-field copy of D_004452D8 via loc = *src, byte loop over 7 entries; self kept in a2 vs a0, source base t1 vs t0; tried volatile bound, state load moved, struct initializer
struct fn_pk7 { int w __attribute__((packed)); signed char a; signed char b; signed char c; };
extern char D_004452D8[];

extern "C" void func_0026A200(char *self)
{
    struct fn_pk7 loc;
    struct fn_pk7 *src = (struct fn_pk7 *)D_004452D8;
    int i;
    loc = *src;
    if (*(int *)(self + 0x564) != 0x222)
        return;
    if (*(signed char *)(self + 0x1865) != 0)
        *(unsigned char *)(self + 0x1865) = (unsigned char)(*(unsigned char *)(self + 0x1865) - 1);
    for (i = 0; i < 7; i++) {
        int idx = ((unsigned char *)&loc)[i];
        int n = *(unsigned char *)(self + 0x2B4);
        *(volatile int *)&n = n;
        char *obj = 0;
        if (idx >= 0 && idx < n)
            obj = ((char **)*(char ***)(self + 0x278))[idx];
        if (obj == 0)
            continue;
        float f0 = *(float *)(self + 0x5A8);
        if (*(signed char *)(self + 0x1865) != 0) {
            float f1 = *(float *)(obj + 0x110) + f0;
            *(float *)(obj + 0x110) = f1;
            float c = *(float *)(self + 0x17D4);
            if (c < f1)
                *(float *)(obj + 0x110) = c;
        } else {
            float f1 = *(float *)(obj + 0x110) - f0 * 0.5f;
            *(float *)(obj + 0x110) = f1;
            if (f1 < 1.0f)
                *(float *)(obj + 0x110) = 1.0f;
        }
        float t = *(float *)(obj + 0x110);
        *(float *)(obj + 0x118) = t;
        *(float *)(obj + 0x114) = t;
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x27E6B8 - 37 differing lines: obj1 in t2 vs t1, bound in v0 vs v1, second store at 0x4($sp) vs 0($sp); tried slot pointer (79 lines), obj2 declared first (77 lines)
extern "C" void func_0027E6B8(char *self, char *other, int idx, float *vec, float *vec2)
{
    int n = *(unsigned char *)(other + 0x2B4);
    *(volatile int *)&n = n;
    char *obj1 = 0;
    if (idx >= 0 && idx < n)
        obj1 = ((char **)*(char ***)(other + 0x278))[idx];
    if (obj1 == 0)
        return;
    n = *(unsigned char *)(self + 0x2B4);
    *(volatile int *)&n = n;
    char *obj2 = 0;
    if (n != 0)
        obj2 = ((char **)*(char ***)(self + 0x278))[0];
    if (obj2 == 0)
        return;
    float *d0 = *(float **)(obj2 + 0xD0);
    *(int *)(obj2 + 0x148) = (int)obj1;
    *(int *)(obj2 + 0x100) = 0;
    *(int *)(obj2 + 0x104) = 0;
    *(int *)(obj2 + 0x108) = 0;
    if (d0 != (float *)vec) {
        d0[0] = vec[0];
        d0[1] = vec[1];
        d0[2] = vec[2];
    }
    float *p100 = (float *)(obj2 + 0x100);
    if (p100 != vec2) {
        p100[0] = vec2[0];
        p100[1] = vec2[1];
        p100[2] = vec2[2];
    }
    *(int *)(self + 0x1584) = idx;
    *(char **)(self + 0x1580) = other;
    float *p1590 = (float *)(self + 0x1590);
    if (p1590 != vec) {
        p1590[0] = vec[0];
        p1590[1] = vec[1];
        p1590[2] = vec[2];
    }
    float *p15A0 = (float *)(self + 0x15A0);
    if (p15A0 != vec2) {
        p15A0[0] = vec2[0];
        p15A0[1] = vec2[1];
        p15A0[2] = vec2[2];
    }
    *(char **)(self + 0x1608) = other;
    *(int *)(self + 0x15E8) = 0;
    float *p110 = (float *)(self + 0x110);
    float *o110 = (float *)(other + 0x110);
    if (p110 != o110) {
        p110[0] = o110[0];
        p110[1] = o110[1];
        p110[2] = o110[2];
    }
}
#endif
