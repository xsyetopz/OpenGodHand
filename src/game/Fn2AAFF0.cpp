#ifdef NONMATCHING
extern "C" void func_002C70A8(void *, int, int, int, int, int, int, int, float, float, float, float, float, float, float, int, float, float, float, int, float);

// DRAFT: GAME 0x2AAFF0
// 42 words differ: original passes only f12-f16 in regs and the rest (w,h,0,1.0,w,h,0,1.0) as 8 stack words; tried float/int arg reorders, V4 struct by value (worse, passed by pointer).
extern "C" void func_002AAFF0(char *a, char *b, char *c)
{
    unsigned v;
    if (*(unsigned char *)(a + 0x46) == 6)
        v = *(unsigned char *)(c + 0x8D);
    else
        v = *(unsigned char *)(a + 0x46);
    *(unsigned *)(b + 0x28) = v;
    *(int *)(b + 0x2C) = *(short *)(c + 0x8E);
    float one = 1.0f;
    int s = *(signed char *)(c + 0x8C);
    float w = *(float *)(c + 0x68) * *(float *)(c + 0x58);
    float h = *(float *)(c + 0x6C) * *(float *)(c + 0x5C);
    func_002C70A8(b, s, *(int *)(c + 0x84), *(int *)(c + 0x64), *(unsigned char *)(c + 0x2D) & 1, *(unsigned char *)(c + 0x89),
                  *(unsigned char *)(c + 0x8B), *(unsigned char *)(c + 0x8A), *(float *)(c + 0x50), *(float *)(c + 0x54), w / (float)s, h,
                  *(float *)(c + 0x70), w, h, 0, one, w, h, 0, one);
}
#endif
