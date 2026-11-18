#ifdef NONMATCHING
// DRAFT: GAME 0x002DA1F8 -- 1 word differs (neg.s f14,f14 vs f14,f13); tried ternary, lim=d;if(!) lim=-d, temp e, 0-d, t temp, inline Abs, lim>=m, split returns

extern "C" float Turn_dest_dir__Ffff(float a, float b, float lim)
{
    float d = b - a;
    if (d > 3.1415927f)
        d -= 6.2831855f;
    if (d < -3.1415927f)
        d += 6.2831855f;
    float s = d > 0.0f ? 1.0f : -1.0f;
    if (!(lim < (d > 0.0f ? d : -d)))
    {
        if (d > 0.0f)
            lim = d;
        else
            lim = -d;
    }
    return lim * s;
}
#endif
