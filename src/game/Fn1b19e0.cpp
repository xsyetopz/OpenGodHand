// DRAFT: GAME 0x1B19E0 -- 8 words differ (f4/f5 swap of y and 1.0f); tried decl order, store order, hoisted 1.0f
#ifdef NONMATCHING
extern "C" void func_001B19E0(void *, float *m, float *v)
{
    float x = v[0];
    float z = v[2];
    float a = x * -2.0f;
    float one = 1.0f;
    float y = v[1];
    m[12] = 0;
    float xy = a * y;
    float xz = a * z;
    m[8] = xz;
    m[4] = xy;
    m[0] = one - 2.0f * x * x;
    m[1] = xy;
    float yz = y * -2.0f * z;
    float y2 = v[1];
    m[2] = xz;
    m[9] = yz;
    m[6] = yz;
    m[13] = 0;
    m[5] = one - 2.0f * y2 * y2;
    float z2 = v[2];
    m[15] = 0;
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    m[10] = one - 2.0f * z2 * z2;
}
#endif
