extern unsigned D_00747A84;
extern void *SubScr;
extern char D_0044FA38;
extern "C" void func_002D9F68(void *, const char *, ...);
extern int D_00753D80;
extern int D_00753D84;
extern int D_003C3CD4;
extern char D_00752D80[];
extern char Sys[];
extern char Snd[];
extern "C" void func_002CA690(void *);
extern "C" int func_00397550(unsigned, int, int);
extern "C" void func_003973E8(unsigned, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x2CAF28 - 58 words; 312 vs 320 bytes. Variant kept: f assigned by if/else (1.0f in then-arm) instead of 1.0f-first, 68 to 58 words. Remaining: SubScr base register and clamp loop counter registers.
extern "C" void func_002CAF28(void *arg0)
{
    char *base = (char *)arg0;
    float *v0;
    float *v1;
    float *a0;
    int a1;

    if (D_00747A84 & 0x08000000) {
        *(float *)(base + 0x90) = 0.1f;
        *(float *)(base + 0x7C) = 0.45f;
        *(int *)(base + 0x78) = 0;
        *(float *)(base + 0x8C) = 0.1f;
        float f;
        if (*(int *)((char *)SubScr + 0xEE8) != 0) {
            f = 1.0f;
        } else {
            f = 0.45f;
        }
        *(float *)(base + 0x80) = f;
        *(float *)(base + 0x94) = 0.1f;
    } else {
        *(float *)(base + 0x80) = 1.0f;
        *(float *)(base + 0x94) = 0.1f;
        *(int *)(base + 0x78) = 0x3F800000;
        *(float *)(base + 0x8C) = 0.1f;
        *(float *)(base + 0x7C) = 1.0f;
        *(float *)(base + 0x90) = 0.1f;
    }
    v0 = (float *)(base + 0x60);
    v1 = (float *)(base + 0x88);
    a0 = (float *)(base + 0x74);
    a1 = 4;
    do {
        float f1 = *v0;
        float f0 = *a0;
        a1--;
        if (f1 != f0) {
            int cond;
            float t = *v1;
            if (f0 < f1) {
                float d = f1 - t;
                *v0 = d;
                cond = d < *a0;
            } else {
                float s = f1 + t;
                *v0 = s;
                cond = *a0 < s;
            }
            if (cond) {
                *v0 = *a0;
            }
        }
        v1++;
        a0++;
        v0++;
    } while (a1 >= 0);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3002B0 - 79 words; 364 vs 316 bytes. Switch hand-written (m2c has no jump table); index register and sd placement differ.
extern "C" void func_003002B0(char *self, unsigned long long *out)
{
    switch ((unsigned char)self[0x247]) {
    case 0:
        *out = 0x8000000044ULL;
        break;
    case 1:
        *out = 0x8000000048ULL;
        break;
    case 2:
        *out = 0x80000000A1ULL;
        break;
    case 3:
        *out = 0x8000000041ULL;
        break;
    case 4:
        *out = 0x8000000049ULL;
        break;
    case 5:
        *out = 0x8000000068ULL;
        break;
    case 6:
        *out = 0x8000000009ULL;
        break;
    case 7:
        *out = 0x8000000046ULL;
        break;
    case 8:
        *out = 0x80000000A4ULL;
        break;
    case 9:
        *out = 0x8000000042ULL;
        break;
    case 10:
        *out = 0x8000000006ULL;
        break;
    default:
        func_002D9F68(self, &D_0044FA38, (unsigned char)self[0x102]);
        break;
    }
    out[1] = 0x42;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2D8EB0 - 82 words; 244 vs 328 bytes. Compiled body is 84 bytes short: bnel delay-slot shapes at index read and record loop not reproduced; prologue order differs.
extern "C" void *func_002D8EB0(char *self)
{
    char *base = self + 0x10000;
    int idx;
    int *ent;
    char *recs;
    int count;
    int n;
    int m;
    int r;
    int j;
    unsigned char key;

    if (*(int *)(base + 0x6284) & 0x10) {
        idx = *(unsigned char *)(base + 0x6168);
    } else {
        idx = *(int *)(base + 0x6288);
    }
    ent = *(int **)(base + 0x6100 + idx * 4);
    if (ent == 0) {
        return 0;
    }
    recs = *(char **)(base + 0x6120);
    if (recs == 0) {
        return 0;
    }
    if (*ent == 0) {
        return 0;
    }
    count = *(int *)(base + 0x6124);
    if (count == 0) {
        *(int *)(base + 0x6128) = 0;
        return 0;
    }
    if (*(int *)(base + 0x6128) == count) {
        return (char *)ent + (*(int *)(base + 0x612C) << 4) + 4;
    }
    *(int *)(base + 0x6128) = count;
    n = *(int *)recs;
    if (n == 0) {
        return 0;
    }
    m = *ent;
    for (r = 0; r < n; r++) {
        key = *(unsigned char *)(recs + 0x12 + r * 0x50);
        if (key == count) {
            int *e = ent + 4;
            for (j = 0; j < m; j++) {
                if (key == *e) {
                    *(int *)(base + 0x612C) = j;
                    return (char *)ent + (j << 4) + 4;
                }
                e += 4;
            }
        }
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x30B148 - unscored first draft; branch on Sys+0x578 selects two bodies that share the D_003C3CD4 tail.
extern "C" int func_0030B148(void)
{
    D_00753D80++;
    if (*(int *)(Sys + 0x578) != 1) {
        if (D_00753D84 != 0 && func_00397550(0x1000A000, 1, 0) == 0) {
            if (!((unsigned)D_00753D80 < (unsigned char)Sys[0x569])) {
                func_003973E8(0x1000A000, (int)D_00752D80);
                D_00753D84 = 0;
            }
        }
        func_002CA690(Snd);
    } else {
        if (D_00753D84 != 0 && func_00397550(0x1000A000, 1, 0) == 0) {
            func_003973E8(0x1000A000, (int)D_00752D80);
            D_00753D84 = 0;
        }
        if (D_003C3CD4 != 0) {
            D_003C3CD4 = 0;
            *(int *)0x10000000 = 0;
        }
    }
    *(int *)(Sys + 0x214) = (*(unsigned long *)0x12001000 >> 13) & 1;
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    return 1;
}
#endif
