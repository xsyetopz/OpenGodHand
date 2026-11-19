struct PlrS {
    char _p[0x54A];
    short m_54a;
};
PlrS *Getplayer();
float capVu0MagnitudeSqXZ(const float *, const float *);
float Turn_dest(const float *, float, const float *, float);
#define PS(s, o, T) (*(T *)((char *)(s) + (o)))

// DRAFT: GAME 0x292F70
// diff: 42 words, Turn_dest result copy order (orig mov.s f1,f0 before the zero load, c.lt on f0, mov.s f2,f1 in bc1f delay); same quirk as func_002DB7E0 in Fn2D0q.cpp; tried a=t;b=t, b=t;a=b;if(a<0)a=-a, a=t;b=a (all 42)
#ifdef NONMATCHING
extern "C" void func_00292F70(char *self, const float *arg)
{
    float m = capVu0MagnitudeSqXZ(PS(Getplayer(), 0xF0, const float *), arg);
    if (m < 3.24f || m > 25.0f)
        return;
    const float *p = PS(Getplayer(), 0xF0, const float *);
    float t = Turn_dest(p, PS(Getplayer(), 0x104, float), arg, 3.1415927f);
    float a = t;
    float b = t;
    if (t < 0.0f)
        a = -t;
    if (a < 0.7853982f)
        return;
    if (a > 2.3561945f) {
        PS(self, 0x550, int) = 2;
        return;
    }
    if (b > 0.0f)
        PS(self, 0x554, int) = 2;
    else
        PS(self, 0x558, int) = 2;
}
#endif
