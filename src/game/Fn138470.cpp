#include "cvecop.h"
extern "C" int DISPLAY_W, DISPLAY_H;
extern "C" void sceVu0ApplyMatrix(float *, void *, const float *);

// FUNCTION: GAME 0x138470
// DIVNOP: 2 2
extern "C" float *getScreenPos__C7cCameraRC4cVec(float *ret, void *cam, const float *v)
{
    float t[4];
    cvecop_Zero(t);
    sceVu0ApplyMatrix(t, cam, v);
    float w = t[3];
    float x = t[0] / w;
    float y = t[1] / w;
    t[2] = w;
    t[0] = x + (float)(DISPLAY_W / 2 - 0x800);
    t[1] = y + (float)(DISPLAY_H / 2 - 0x800);
    cvecop_Copy(ret, t);
    return ret;
}
