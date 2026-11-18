#ifndef CEM00STATEDECLS_H_
#define CEM00STATEDECLS_H_

// Small enemy state functions in 0x220000-0x23FFFF, over raw offsets.
#include "game/cGameObj.h"

#include "game/cCoreSave.h"

extern cCoreSave CoreSave;

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

unsigned irand();

extern "C" {

void func_001D0580(void *);

int func_00276468(void *);

void func_0026BDD0(void *, void *);

void func_00262A10(void *);

void func_00260B30(void *);

void func_002609A8(void *, int, int, int, int, int);

void func_002705D8(void *);

void *func_0026AA30(void *, int);

void func_0026B240(void *, void *, int, int);

void func_00262750(void *, int);

void *func_002DDAB0(void *, float, int);

void func_0026AB20(void *, void *, unsigned);

void func_002A8578(void *self, int a, int b, int c, float f, int d, int e);

} // extern "C"

#define B(o) (*(unsigned char *)((char *)self + (o)))

#endif
