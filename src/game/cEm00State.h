#pragma once
// Shared declarations for the raw-offset cEm00 state functions.

#include "game/cGameObj.h"

class cObjBase {
public:
    void addNullSpeed(float);
    void addNullSpeed_Rotation(float);
};
class cCollisionSolidManage {
public:
    void SetActive(cGameObj *obj, bool on);
};
extern cCollisionSolidManage g_CollSolidManage;
int moveMotion(cObjBase *);
cGameObj *Getplayer();

extern "C" {
void func_002606E8(void *, int);
void func_002705D8(void *);
void func_00270C78(void *);
int func_0026F120(void *);
int func_00276468(void *);
void func_002A8578(void *self, int a, int b, int c, float f, int d, int e);
}

#define B(o) (*(unsigned char *)((char *)self + (o)))
