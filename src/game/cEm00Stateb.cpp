#include "game/cEm00StateDecls.h"

extern "C" {

// FUNCTION: GAME 0x2256C8
void func_002256C8(char *self)
{
    B(0x186A) = 2;
    *(unsigned int *)(self + 0x16D4) |= 0x400;
    func_00262A10(self);
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned m = func_00276468(self) & 0xFFFF;
        func_002609A8(self, 0x28, 0xB, 0x42, 0, 0xF5);
        char *t = *(char **)(self + 0x304);
        int a1 = *(int *)(t + 0xCE4) + (int)t;
        int a2 = *(int *)(t + 0xCE8) + (int)t;
        *(int *)(self + 0x5F0) = 10;
        if ((unsigned)(*(int *)(self + 0x564) - 0x250) < 2) {
            a2 = *(int *)(t + 0xCEC) + (int)t;
            *(int *)(self + 0x5F0) = 8;
        }
        func_002A8578(self, a1, a2, 3, 0.0f, m, 0);
        *(int *)(self + 0x5FC) = 0;
        *(float *)(self + 0x600) = *(float *)(self + 0x104);
        B(0x2F6)++;
    }
    case 1:
        int c = *(int *)(self + 0x5F0);
        if (c) {
            float *pos = *(float **)(self + 0xF0);
            *(int *)(self + 0x5F0) = c - 1;
            cGameObj *pl = Getplayer();
            float d = Turn_dest(pos, *(float *)(self + 0x600), (const float *)pl->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
            *(float *)(self + 0x600) += d;
            *(float *)(self + 0x600) = Adjust_theta(*(float *)(self + 0x600));
            *(float *)(self + 0x104) += d;
            *(float *)(self + 0x104) = Adjust_theta(*(float *)(self + 0x104));
        }
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    func_00260B30(self);
    if (*(unsigned short *)(self + 0x3AC) & 1)
        func_00262750(self, 0);
    if (*(unsigned short *)(self + 0x3AC) & 3)
        *(int *)(self + 0x5FC) = 1;
    if (*(int *)(self + 0x5FC))
        *(unsigned int *)(self + 0x16D4) &= ~0x400;
}

// 0x22C1A8: 8 words differ (register allocation of the 0x304 blob pointer: original v1/v0/a1, compiled a2/v1/v0)
#ifdef NONMATCHING
void func_0022C1A8(char *self)
{
    B(0x186A) = 2;
    *(unsigned int *)(self + 0x16D0) |= 0x400;
    *(unsigned int *)(self + 0x16D4) |= 0x400;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned m = func_00276468(self) & 0xFFFF;
        unsigned rr = irand() & 1;
        char *t = *(char **)(self + 0x304);
        B(0x2F7) = rr;
        int a = *(int *)(t + 0x22E0) + (int)t;
        int b = *(int *)(t + 0x22E4) + (int)t;
        if (CoreSave.getGameLevel() == 5) {
            t = *(char **)(self + 0x304);
            b = *(int *)(t + 0x22E8) + (int)t;
        }
        func_002A8578(self, a, b, 3, 0.0f, m, 0);
        *(int *)(self + 0x5F0) = 1;
        *(float *)(self + 0x604) = 35.0f;
        B(0x2F6)++;
        *(int *)(self + 0x5FC) = 0;
    }
    case 1: {
        float f = *(float *)(self + 0x604);
        if (0.0f < f) {
            *(unsigned int *)(self + 0x16D0) |= 0x800000;
            *(float *)(self + 0x604) = f - *(float *)(self + 0x5A8);
        }
        cGameObj *pl = Getplayer();
        ((cGameObj *)self)->SetTgtTurn(*pl->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (*(int *)(self + 0x5F0)) {
            *(int *)(self + 0x5F0) = 0;
            void *r;
            if (*(int *)(self + 0x564) == 0x276)
                r = func_0026AA30(self, 0x373);
            else
                r = func_0026AA30(self, 0x36B);
            if (r) {
                func_0026BDD0(self, r);
                *(unsigned int *)(self + 0x16D4) |= 0x10000;
            }
        }
    } else
        *(int *)(self + 0x5F0) = 1;
    if (*(unsigned short *)(self + 0x3AC) & 3)
        *(int *)(self + 0x5FC) = 1;
    if (*(int *)(self + 0x5FC))
        *(unsigned int *)(self + 0x16D4) &= ~0x400;
}
#endif

// FUNCTION: GAME 0x239570
void func_00239570(char *self)
{
    char *pl = (char *)Getplayer();
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x3B38) + (int)t, *(int *)(t + 0x3B3C) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
        *(short *)(self + 0x56E) = 0xF;
    }
    case 1:
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
            char *q = pl + 0x550;
            char *p = *(char **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        *(float *)(self + 0x54C) = 3.0f;
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x239698
void func_00239698(char *self)
{
    char *pl = (char *)Getplayer();
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1484) + (int)t, *(int *)(t + 0x1488) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
        *(short *)(self + 0x56E) = 0xF;
    }
    case 1:
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
            char *q = pl + 0x550;
            char *p = *(char **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        *(float *)(self + 0x54C) = 3.0f;
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x23A010
void func_0023A010(char *self)
{
    char *pl = (char *)Getplayer();
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1054) + (int)t, *(int *)(t + 0x1058) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
        *(short *)(self + 0x56E) = 0xF;
    }
    case 1:
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
            char *q = pl + 0x550;
            char *p = *(char **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x236C60
void func_00236C60(char *self)
{
    char *pl = (char *)Getplayer();
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1D98) + (int)t, *(int *)(t + 0x1D9C) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
        *(short *)(self + 0x56E) = 0xF;
    }
    case 1:
        *(unsigned int *)(self + 0x250) |= 0x40000;
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
            char *q = pl + 0x550;
            char *p = *(char **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x236D98
void func_00236D98(char *self)
{
    char *pl = (char *)Getplayer();
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x2EF8) + (int)t, *(int *)(t + 0x2EFC) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
        *(short *)(self + 0x56E) = 0xF;
    }
    case 1:
        *(unsigned int *)(self + 0x250) |= 0x40000;
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
            char *q = pl + 0x550;
            char *p = *(char **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

} // extern "C"
