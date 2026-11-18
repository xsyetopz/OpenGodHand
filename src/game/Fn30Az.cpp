extern "C" void sceVu0UnitMatrix(float *);
extern "C" void sceVu0MulMatrix(float *, float *, float *);

// FUNCTION: GAME 0x30AA40
// DIVNOP: 2 2
extern "C" void func_0030AA40(float *m, float a, float b, float c, float d, float e, float f, float g, float h, float s)
{
    float t = -f + g;
    float y = (-g * h + f * s) / (-h + s);
    float x = s * h * t / (-h + s);
    float tmp[16];
    sceVu0UnitMatrix(m);
    m[0] = a;
    m[5] = a;
    m[10] = 0.0f;
    m[15] = 0.0f;
    m[14] = 1.0f;
    m[11] = 1.0f;
    sceVu0UnitMatrix(tmp);
    tmp[0] = b;
    tmp[5] = c;
    tmp[10] = x;
    tmp[12] = d;
    tmp[13] = e;
    tmp[14] = y;
    sceVu0MulMatrix(m, tmp, m);
}
