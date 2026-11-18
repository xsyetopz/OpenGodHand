#pragma once
#include "game/cEm00StateDecls.h"
#include "game/cVec.h"
struct Qv110 { float v[4] __attribute__((aligned(16))); };
extern "C" {
void func_00124540(void *, int);
void func_00124E68(void *, float);
void func_00124E58(void *);
void func_0012B618(void *);
int func_00123938(void *, int);
void func_001268F0(void *);
void func_00126770(void *);
void func_0012A8D8(void *);
void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
}
struct cFn110nSnd {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cFn110nSnd Snd;
extern char g_EmManage[];
extern "C" {
void SetSlotWait__9cEmManagei(void *, int);
void SetPlCatched__9cEmManage(void *);
void SetBigHitEffWait__9cEmManagei(void *, int);
void SetPlSorry__9cEmManage(void *);
void func_00124EC0(void *);
void func_00129578(void *);
void func_00129630(void *);
void useGodItem__9cCoreSave(void *);
void setGameLevel__9cCoreSavei(void *, int);
}
extern char g_HeatSys[];
extern "C" {
int SetEmAnger__9cEmManageG4cVecfff(void *, void *, float, float, float);
int getGameLevel__9cCoreSave(void *);
void AddHeatGage__8cHeatSysfUi(void *, float, unsigned);
void addGameLevelPoint__9cCoreSavei(void *, int);
}

extern "C" {
void GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(void *, int, float, float);
void func_001299F0(void *, void *, float *, int, float);
void func_0012AC28(void *);
void func_0012B928(void *);
void func_0012C348(void *, int);
}
extern "C" {
void sceVu0ApplyMatrix(float *, void *, float *);
}
extern "C" {
void SetSpeedRate__9cEmManagef(void *, float);
void func_0010A408(void *, int, int, int, int, int);
void func_0010A420(void *, int, int, int, int, int);
}
extern "C" void func_0012C348(void *, int);
extern "C" void func_0012AC28(void *);
extern "C" void func_0012B928(void *);
extern "C" {
void func_0010A438(void *);
void SetHeatMode__8cHeatSysUc(void *, int);
float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
}
