extern "C" void restartAnim__7cIDBase(void *);
extern char *Cockpit;

#ifdef NONMATCHING
// DRAFT: GAME 0x28EBF0
// 59 words off: constants 1/3 and a1 flag reg allocation (movn for the 0x2A0 test, store order); one variant only, unsolved-tail class.
extern "C" int func_0028EBF0(char *self, char *p, int n)
{
    float *src = (float *)(p + 0x10);
    float *dst = *(float **)(self + 0xF0);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    float *v = (float *)(self + 0x490);
    if (v != *(float **)(self + 0xF0)) {
        v[0] = (*(float **)(self + 0xF0))[0];
        v[1] = (*(float **)(self + 0xF0))[1];
        v[2] = (*(float **)(self + 0xF0))[2];
    }
    int f = 0;
    unsigned short a = *(unsigned short *)(self + 0x2FE);
    *(float *)(self + 0x104) = *(float *)(p + 0x20);
    *(int *)(self + 0x628) = n;
    *(char *)(self + 0x531) = 3;
    *(float *)(self + 0x644) = 1.0f;
    *(int *)(self + 0x610) = 0;
    *(char *)(self + 0x614) = 0;
    *(char *)(self + 0x615) = 0;
    *(char *)(self + 0x616) = 0;
    *(char *)(self + 0x623) = 0;
    *(short *)(self + 0x62C) = 0;
    *(char *)(self + 0x617) = 0;
    *(char *)(self + 0x622) = 0;
    *(float *)(self + 0x630) = 1.0f;
    if (a >= 0x2A0)
        f = a < 0x300;
    if (f & 0xFF)
        *(char **)(self + 0x660) = Cockpit + 0xE50;
    else
        *(char **)(self + 0x660) = Cockpit + 0xE00;
    restartAnim__7cIDBase(*(void **)(self + 0x660));
    *(float *)(self + 0x3A8) = 1.0f;
    *(int *)(self + 0x254) = *(int *)(self + 0x254) | 0x8000000;
    *(short *)(self + 0x570) = -1;
    *(int *)(self + 0x574) = 2;
    return 1;
}
#endif
