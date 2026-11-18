// DRAFT: GAME 0x157498
// diff: 20 words; original does cvt.w.s/cvt.s.w in FPRs with no mfc1/mtc1 round trip and loads 0.5 later; compiled goes through v0. Variants: select vs two returns, hoisted 1.0f, d/f order (4 tries).
#ifdef NONMATCHING
float RoundFloat(float x, float step)
{
    float one = 1.0f;
    x = x * (one / step);
    float d = x - (float)(int)x;
    float f = (float)(int)x;
    if (d >= 0.5f)
        return (f + one) * step;
    return f * step;
}
#endif
