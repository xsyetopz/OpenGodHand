#include "game/cVec.h"
struct V4 : cVec { float w; };
extern "C" float frand__Fff(float, float);
extern "C" char *func_001F0498(void *, int, V4 *, float);
extern "C" void func_001FD988(void *, int);

// FUNCTION: GAME 0x1F06A8
extern "C" void func_001F06A8(void *self)
{
    int i = 19;
    do {
        V4 v;
        float x = frand__Fff(-10.0f, 10.0f);
        float z = frand__Fff(-10.0f, 10.0f);
        v.x = x;
        v.z = z;
        v.y = 0.0f;
        v.w = 1.0f;
        func_001F0498(self, 0x380, &v, frand__Fff(-3.14f, 3.14f));
    } while (--i >= 0);
}

// FUNCTION: GAME 0x1FCD00
extern "C" void func_001FCD00(char *self)
{
    *(int *)self = 0;
    self[0x4A] = 0;
    V4 a;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    a.w = 1.0f;
    *(cVec *)(self + 0x10) = a;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    a.w = 1.0f;
    *(cVec *)(self + 0x20) = a;
    *(int *)(self + 0x30) = 0;
    *(int *)(self + 0x38) = 0;
    *(int *)(self + 0x3C) = 0;
    *(short *)(self + 0x44) = 0;
    *(short *)(self + 0x46) = 0;
    *(int *)(self + 0x40) = -1;
    func_001FD988(self, 4);
    *(int *)(self + 0x4C) = 0;
}
