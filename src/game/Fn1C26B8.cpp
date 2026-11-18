extern "C" void *Getplayer__Fv();
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" float Turn_dest__FPCffT0f(const float *, float, const float *, float);

#ifdef NONMATCHING
// DRAFT: GAME 0x1C26B8
// diff: 3 words, fabs branch is bc1t+neg first vs orig bc1f with mov.s in delay slot; tried ternary, else, !(t>=0), 0>t, a=-a (all 23+ or this)
extern "C" int func_001C26B8(char *self)
{
    char *pl = (char *)Getplayer__Fv();
    float d = capVu0MagnitudeSqXZ__FPCfT0(*(const float **)(pl + 0xF0), *(const float **)(self + 0xF0));
    int r = 1;
    if (!(d < 0.5f)) {
        r = 0;
        if (!(d > 2.0f)) {
            float t = Turn_dest__FPCffT0f(*(const float **)(pl + 0xF0), *(float *)(pl + 0x104), *(const float **)(self + 0xF0), 3.1415927f);
            float a = -t;
            if (!(t < 0.0f))
                a = t;
            r = 1;
            if (!(a < 0.5235988f))
                r = 0;
        }
    }
    return r;
}
#endif
