// Fn001E8EB8: pick neighbouring table entries by angle.
#ifdef NONMATCHING
extern "C" float func_001E9078();
extern "C" int func_0031ED08(float);

// DRAFT: GAME 0x001E8EB8
// 18 words differ: n kept in a0 instead of a1, a2 base copy ordering; tried typed struct, temp load var, pointer-increment, shared base ptr (26-31 words)
extern "C" void func_001E8EB8(char *p) {
    int n = func_0031ED08(func_001E9078() / (360.0f / (float)*(unsigned short *)(p + 0xB4)));
    char *t = p + 0x54;
    char *b;
    if (n == *(unsigned short *)(p + 0xB4) - 1) {
        b = p + 0x54;
        *(int *)(p + 0xA8) = *(int *)t;
    } else {
        b = t;
        t += (n + 1) << 2;
        *(int *)(p + 0xA8) = *(int *)t;
    }
    *(int *)(p + 0xAC) = *(int *)(b + (n << 2));
    int k;
    if (n == 0) k = *(unsigned short *)(p + 0xB4) - 1;
    else k = n - 1;
    *(int *)(p + 0xB0) = *(int *)(b + (k << 2));
}
#endif
