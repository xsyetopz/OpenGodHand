#include "game/cEm00StateDecls.h"

extern "C" {

int func_00262AA8(void *);
void func_001D0718(void *);
void func_0026EC60(void *);
void func_0026A638(void *, int);
void func_0026A938(void *, int, int);
void func_0026A838(void *, int);
void func_0026EE40(void *, int, int);
int func_0026F1D8(void *);
int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);

// FUNCTION: GAME 0x223470
void func_00223470(char *self)
{
    B(0x186A) = 2;
    *(unsigned int *)(self + 0x16D4) |= 0x400;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned m = func_00276468(self) & 0xFFFF;
        int a = *(int *)(*(int *)(self + 0x304) + 0x6E8) + *(int *)(self + 0x304);
        int b = *(int *)(*(int *)(self + 0x304) + 0x6EC) + *(int *)(self + 0x304);
        if (CoreSave.getGameLevel() == 5) {
            b = *(int *)(*(int *)(self + 0x304) + 0x6F0) + *(int *)(self + 0x304);
        }
        func_002A8578(self, a, b, 3, 0.0f, m, 0);
        *(int *)(self + 0x5F4) = 0;
        *(int *)(self + 0x5FC) = 0;
        *(int *)(self + 0x5F0) = 15;
        func_0026EE40(self, 0, 0);
        B(0x2F6)++;
    }
    case 1: {
        int c = *(int *)(self + 0x5F0);
        if (c) {
            *(int *)(self + 0x5F0) = c - 1;
            cGameObj *pl = Getplayer();
            ((cGameObj *)self)->SetTgtTurn(*pl->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
        }
        if (moveMotion((cObjBase *)self)) {
            func_0026EE40(self, 0, 0);
            if (func_00262AA8(self))
                return;
            func_002705D8(self);
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (!*(int *)(self + 0x5F4)) {
            if (*(unsigned short *)(self + 0x3AC) & 2) {
                SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x58, 0x29, self, 0, -1, -1);
                *(int *)(self + 0x5F4) = 1;
            }
        }
    }
    }
    func_002609A8(self, 0, 0xF, 0x4A, -1, 0);
    if (*(unsigned short *)(self + 0x3AC) & 1)
        func_00260B30(self);
    if (CoreSave.getGameLevel() >= 3 && !func_0026F1D8(self) && (*(unsigned short *)(self + 0x3AC) & 0x10) && func_00262AA8(self))
        return;
    if (*(unsigned short *)(self + 0x3AC) & 3)
        *(int *)(self + 0x5FC) = 1;
    if (*(int *)(self + 0x5FC))
        *(unsigned int *)(self + 0x16D4) &= ~0x400;
}

// FUNCTION: GAME 0x230F20
void func_00230F20(char *self)
{
    B(0x186A) = 2;
    *(unsigned int *)(self + 0x16D4) |= 0x400;
    func_00262A10(self);
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned m = func_00276468(self) & 0xFFFF;
        int a, b;
        int ty = *(int *)(self + 0x564);
        if (ty != 0x213 && ty != 0x217) {
            char *t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x1B8) + (int)t;
            b = *(int *)(t + 0x1BC) + (int)t;
        } else {
            char *t = *(char **)(self + 0x304);
            void *w = *(void **)(self + 0x708);
            a = *(int *)(t + 0x2F6C) + (int)t;
            b = *(int *)(t + 0x2F70) + (int)t;
            if (w)
                func_001D0718(w);
        }
        func_002A8578(self, a, b, 5, 0.0f, m, 0);
        *(int *)(self + 0x5F0) = 0x16;
        *(int *)(self + 0x5F8) = 0xF;
        B(0x2F6)++;
        *(int *)(self + 0x5F4) = 0;
        *(int *)(self + 0x5FC) = 0;
    }
    case 1: {
        int d = *(int *)(self + 0x5F8);
        if (d)
            *(int *)(self + 0x5F8) = d - 1;
        int c = *(int *)(self + 0x5F0);
        if (c) {
            cGameObj *tg = *(cGameObj **)(self + 0x17A0);
            *(int *)(self + 0x5F0) = c - 1;
            if (tg) {
                ((cGameObj *)self)->SetTgtTurn(*tg->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
            } else if (*(int *)(self + 0x5F8) <= 0) {
                cGameObj *pl = Getplayer();
                ((cGameObj *)self)->SetTgtTurn(*pl->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
            }
        }
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
    if ((*(unsigned short *)(self + 0x3AC) & 2) && !*(int *)(self + 0x5F4)) {
        *(int *)(self + 0x5F4) = 1;
        func_0026EC60(self);
        *(int *)(self + 0x17A0) = 0;
    }
    if (*(unsigned short *)(self + 0x3AC) & 0x20)
        g_CollSolidManage.SetActive((cGameObj *)self, false);
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        func_002609A8(self, 0x1E, 2, 0x3E, -1, 0);
        func_00260B30(self);
    }
    if (*(unsigned short *)(self + 0x3AC) & 3)
        *(int *)(self + 0x5FC) = 1;
    if (*(int *)(self + 0x5FC))
        *(unsigned int *)(self + 0x16D4) &= ~0x400;
}

// FUNCTION: GAME 0x22ACE0
void func_0022ACE0(char *self)
{
    B(0x186A) = 2;
    *(unsigned int *)(self + 0x16D4) |= 0x400;
    switch (B(0x2F6)) {
    case 0: {
        unsigned m = func_00276468(self) & 0xFFFF;
        unsigned rr = irand() & 1;
        float f = *(float *)(self + 0x618);
        if (64.0f < f)
            rr = 0;
        if (f < 16.0f)
            rr = 1;
        int a, b;
        if (rr) {
            a = *(int *)(*(int *)(self + 0x304) + 0xDD0) + *(int *)(self + 0x304);
            b = *(int *)(*(int *)(self + 0x304) + 0xDD4) + *(int *)(self + 0x304);
            if (CoreSave.getGameLevel() == 5) {
                b = *(int *)(*(int *)(self + 0x304) + 0xDD4) + *(int *)(self + 0x304);
            }
            B(0x2F7) = 1;
        } else {
            a = *(int *)(*(int *)(self + 0x304) + 0xDC4) + *(int *)(self + 0x304);
            b = *(int *)(*(int *)(self + 0x304) + 0xDC8) + *(int *)(self + 0x304);
            if (CoreSave.getGameLevel() == 5) {
                b = *(int *)(*(int *)(self + 0x304) + 0xDCC) + *(int *)(self + 0x304);
            }
            B(0x2F7) = 0;
        }
        func_002A8578(self, a, b, 3, 0.0f, m, 0);
        *(int *)(self + 0x5F0) = 100;
        *(int *)(self + 0x5FC) = 0;
        B(0x2F6)++;
    }
    case 1: {
        *(int *)(self + 0x16DC) = 100;
        *(int *)(self + 0x16E0) = 150;
        int c = *(int *)(self + 0x5F0);
        if (c) {
            *(int *)(self + 0x5F0) = c - 1;
            cGameObj *pl = Getplayer();
            ((cGameObj *)self)->SetTgtTurn(*pl->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
        }
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(unsigned short *)(self + 0x3AC) & 1) {
            if (B(0x17C3))
                func_0026A638(self, 1);
            else
                func_0026A638(self, 0);
        }
        if (*(unsigned short *)(self + 0x3AC) & 2) {
            if (B(0x2F7)) {
                func_0026A938(self, 0, 0);
                func_0026A938(self, 1, 0);
            } else {
                func_0026A838(self, 0);
                func_0026A838(self, 1);
            }
        }
    }
    }
    if (*(unsigned short *)(self + 0x3AC) & 3)
        *(int *)(self + 0x5FC) = 1;
    if (*(int *)(self + 0x5FC))
        *(unsigned int *)(self + 0x16D4) &= ~0x400;
}

} // extern "C"
