// FUNCTION: GAME 0x1BDC48
extern "C" void setOpenFix__8cOmDoor2(char *self)
{
    float v[4];
    if (*(unsigned char *)(self + 0x774) == 0) {
        void *p = ((void *(*)(char *))(*(void **)(*(char **)(self + 0x214) + 0x84)))(self + *(short *)(*(char **)(self + 0x214) + 0x80));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(v), "r"(p) : "memory");
        if (*(int *)(self + 0x778) == 0)
            v[1] = v[1] + *(float *)(self + 0x770);
        else
            v[1] = v[1] - *(float *)(self + 0x770);
        char *o = *(char **)(self + 0x214);
        ((void (*)(char *, float *))(*(void **)(o + 0x74)))(self + *(short *)(o + 0x70), v);
        *(unsigned char *)(self + 0x774) = 1;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F5) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
}

// FUNCTION: GAME 0x1BDCE8
extern "C" void setCloseFix__8cOmDoor2(char *self)
{
    float v[4];
    if (*(unsigned char *)(self + 0x774) == 1) {
        void *p = ((void *(*)(char *))(*(void **)(*(char **)(self + 0x214) + 0x84)))(self + *(short *)(*(char **)(self + 0x214) + 0x80));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(v), "r"(p) : "memory");
        if (*(int *)(self + 0x778) == 0)
            v[1] = v[1] - *(float *)(self + 0x770);
        else
            v[1] = v[1] + *(float *)(self + 0x770);
        char *o = *(char **)(self + 0x214);
        ((void (*)(char *, float *))(*(void **)(o + 0x74)))(self + *(short *)(o + 0x70), v);
        *(unsigned char *)(self + 0x774) = 0;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F5) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1F7D48
// 20 differing words: constants load late and the sign test uses $v0/$v1 instead of mfc1 $t0 + slt on the integer bits. Variants t1-t9 and a1, b1-b8 (float temp, hoisted constants, late -2, mov.s return copy) all stayed at 20 or rose to 22; 8-attempt limit reached.
extern "C" float Adjust_theta__Ff(float x)
{
    int n = (int)(x * 0.31830987f) + (*(int *)&x > 0);
    x = x - (float)(n & ~1) * 3.1415927f;
    return x;
}
#endif
