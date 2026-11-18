extern "C" {
int func_002CDA38(void *, short, short, short);
int func_002CDFF0(void *, short, short, int, int);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2CDF18  41 words; s-reg allocation order (s2/s3/s5 vs a,b,c,d) differs; variants: early return, short-typed callee args
extern "C" int func_002CDF18(char *p, short a, short b, short c, short d, int e, int f) {
    if (func_002CDA38(p, a, b, c) == 1)
        return 0;
    *(short *)(p + 0x28) = c;
    *(short *)(p + 0x2A) = d;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x40) = 0;
    *(int *)(p + 0x44) = 0;
    *(int *)(p + 0x48) = 0;
    *(float *)(p + 0x4C) = 1.0f;
    return func_002CDFF0(p, a, b, e, f);
}
#endif
