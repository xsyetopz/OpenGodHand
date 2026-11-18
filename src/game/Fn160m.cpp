// Units in .text 0x160000-0x17FFFF: effect starter, sound-call states, stop-and-aim handlers.
#include "game/cVec.h"
extern char Snd[];
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);

// FUNCTION: GAME 0x16FBF8
extern "C" void func_0016FBF8(char *self)
{
    if (*(int *)(self + 0x5EC))
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(*(int *)(self + 0x5F0), *(int *)(self + 0x5EC), self, 0, -1, 0xFFFFFFFF);
}

// FUNCTION: GAME 0x1731B8
extern "C" void func_001731B8(char *self)
{
    char *v = *(char **)(self + 0x214);
    float *o = ((float *(*)(char *))*(void **)(v + 0x8C))(self + *(short *)(v + 0x88));
    *(float *)(self + 0xDA4) = o[1];
    *(short *)(self + 0xDA0) = 6;
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x2D, self, 0, 0, 0, 0);
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 0, 10, self, 0, 0, 0, 0);
}

// FUNCTION: GAME 0x1793D0
extern "C" void func_001793D0(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0:
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 2, self, 0, 0, 0, 0);
        *(unsigned short *)(self + 0x654) = 15;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    case 1:
        *(unsigned short *)(self + 0x654) = *(unsigned short *)(self + 0x654) - 1;
        if ((short)*(unsigned short *)(self + 0x654) <= 0) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

#include "game/StopAim.h"

// FUNCTION: GAME 0x1754B0
FN190_STOP(func_001754B0)
// FUNCTION: GAME 0x179C60
FN190_STOP(func_00179C60)
// FUNCTION: GAME 0x17A9E0
FN190_STOP(func_0017A9E0)
// FUNCTION: GAME 0x17D2E0
FN190_STOP(func_0017D2E0)
