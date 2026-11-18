#include "cvecop.h"
#ifdef NONMATCHING
extern "C" void func_002A8578(void *, float, void *, void *, int, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" int func_00291010(void *, float *, float, float, float, void *, int, int);
extern char g_EmManage[];

// DRAFT: GAME 0x2412A8 - 4 words off: orig does the 2nd `or` (0x20000) before swc1 0x54C; ours stores 3.0f first
extern "C" void func_002412A8(char *self)
{
    char *t;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        t = *(char **)(self + 0x304);
        func_002A8578(self, 0.0f, (char *)(*(int *)(t + 0x1A50) + (int)t), (char *)(*(int *)(t + 0x1A54) + (int)t), 3, 0, 0);
        *(short *)(self + 0x568) = 10;
        *(unsigned char *)(self + 0x2F6) += 1;
    case 1:
    {
        unsigned f = *(unsigned *)(self + 0x16D0);
        f |= 0x10000;
        __asm__("" : "+r"(f));
        *(float *)(self + 0x54C) = 3.0f;
        *(unsigned *)(self + 0x16D0) = f | 0x20000;
    }
        if (moveMotion__FP8cObjBase(self))
            *(unsigned char *)(self + 0x2F6) += 1;
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f / *(float *)(self + 0x118));
        return;
    case 2:
        t = *(char **)(self + 0x304);
        func_002A8578(self, 10.0f, (char *)(*(int *)(t + 0x18F0) + (int)t), (char *)(*(int *)(t + 0x18F4) + (int)t), 0, 0, 0);
        *(short *)(self + 0x568) = 10;
        *(unsigned char *)(self + 0x2F6) += 1;
    case 3:
    {
        unsigned f = *(unsigned *)(self + 0x16D0);
        f |= 0x10000;
        __asm__("" : "+r"(f));
        *(float *)(self + 0x54C) = 3.0f;
        *(unsigned *)(self + 0x16D0) = f | 0x20000;
    }
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (!(*(unsigned *)(self + 0x16D0) & 0x20000000)) {
            float v[4];
            cvecop_CopyR(v, *(float **)(self + 0xF0));
            if (func_00291010(g_EmManage, v, *(float *)(self + 0x104), 100.0f, 3.1415927f, self, 2, 0))
                return;
            if ((short)(--*(unsigned short *)(self + 0x568)) > 0)
                return;
        }
        {
            float *d = (float *)(self + 0x6D0);
            float *s = *(float **)(self + 0xF0);
            if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
            *(unsigned char *)(self + 0x2F5) = 0x75;
            *(float *)(self + 0x6E0) = *(float *)(self + 0x104);
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}
#endif
