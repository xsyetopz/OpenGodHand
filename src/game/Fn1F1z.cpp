#include "game/cVec.h"
struct V4 : cVec { float w; };
extern "C" float frand__Fff(float, float);
extern "C" float Adjust_theta__Ff(float);
extern "C" float capVu0Sin__Ff(float);
extern "C" float capVu0Cos__Ff(float);
extern "C" char *func_001F0498(void *, int, V4 *, float);
struct Ids { int v[5]; };
extern Ids D_0042BEE0;

// FUNCTION: GAME 0x1F08B8
extern "C" void func_001F08B8(char *self)
{
    V4 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 5.0f;
    v.w = 1.0f;
    float z = v.x;
    *(char **)(self + 0xC64) = func_001F0498(self, 0x3ED, &v, z);
    v.x = z;
    v.y = z;
    v.z = z;
    v.w = 1.0f;
    *(char **)(self + 0xC68) = func_001F0498(self, 0x3ED, &v, z);
    v.x = z;
    v.y = z;
    v.z = -5.0f;
    v.w = 1.0f;
    *(char **)(self + 0xC6C) = func_001F0498(self, 0x3ED, &v, z);
}

// FUNCTION: GAME 0x1F0BF8
extern "C" void func_001F0BF8(char *self)
{
    V4 v;
    v.x = 2.9f;
    v.y = 0.0f;
    v.z = 5.4f;
    v.w = 1.0f;
    float z = v.y;
    *(char **)(self + 0xC64) = func_001F0498(self, 0x3EC, &v, z);
    v.x = 3.0f;
    v.y = z;
    v.z = -4.55f;
    v.w = 1.0f;
    *(char **)(self + 0xC68) = func_001F0498(self, 0x3EC, &v, z);
    v.x = -5.4f;
    v.y = z;
    v.z = -1.0f;
    v.w = 1.0f;
    *(char **)(self + 0xC6C) = func_001F0498(self, 0x3EC, &v, z);
}

// FUNCTION: GAME 0x1F1388
extern "C" void func_001F1388(void *self)
{
    Ids ids = D_0042BEE0;
    V4 v;
    V4 *pv = &v;
    int i = 9;
    do {
        int *p = &ids.v[(int)frand__Fff(0.0f, 5.0f)];
        float x = frand__Fff(-10.0f, 10.0f);
        float z = frand__Fff(-10.0f, 10.0f);
        v.x = x;
        v.z = z;
        v.y = 0.0f;
        pv->w = 1.0f;
        func_001F0498(self, *p, pv, frand__Fff(-3.14f, 3.14f));
    } while (--i >= 0);
}

// FUNCTION: GAME 0x1F16D8
extern "C" void func_001F16D8(void *self)
{
    V4 v;
    int i = 0;
    do {
        float a = Adjust_theta__Ff((float)i * 72.0f * 0.017453292f);
        i++;
        float x = capVu0Sin__Ff(a) * 8.0f;
        float z = capVu0Cos__Ff(a) * 8.0f;
        v.y = 0.0f;
        v.x = x;
        v.z = z;
        v.w = 1.0f;
        func_001F0498(self, 0x3ED, &v, 0.0f);
    } while (i < 5);
}

// FUNCTION: GAME 0x1F1D00
extern "C" void func_001F1D00(void *self)
{
    V4 v;
    int i = 0;
    do {
        float a = Adjust_theta__Ff((float)i * 72.0f * 0.017453292f);
        i++;
        float x = capVu0Sin__Ff(a) * 8.0f;
        float z = capVu0Cos__Ff(a) * 8.0f;
        v.y = 0.0f;
        v.x = x;
        v.z = z;
        v.w = 1.0f;
        func_001F0498(self, 0x3ED, &v, 0.0f);
    } while (i < 5);
}

// FUNCTION: GAME 0x1F1810
extern "C" void func_001F1810(char *self)
{
    V4 v;
    int i = 0;
    char **out = (char **)(self + 0xC64);
    do {
        float a = Adjust_theta__Ff((float)i * 60.0f * 0.017453292f);
        i++;
        float x = capVu0Sin__Ff(a) * 8.0f;
        float z = capVu0Cos__Ff(a) * 8.0f;
        v.y = 0.0f;
        v.x = x;
        v.z = z;
        v.w = 1.0f;
        *out++ = func_001F0498(self, 0x3EC, &v, 0.0f);
    } while (i < 6);
}
