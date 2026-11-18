#include "game/cEm00StateDecls.h"

extern "C" {

// FUNCTION: GAME 0x2376C0
void func_002376C0(char *self)
{
    *(short *)(self + 0x568) = 1;
}

// FUNCTION: GAME 0x2387B8
void func_002387B8(char *self)
{
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x36D0) + (int)t, *(int *)(t + 0x36D4) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
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

// FUNCTION: GAME 0x237E90
void func_00237E90(char *self)
{
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(unsigned int *)(self + 0x16D0) |= 0x20000;
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1550) + (int)t, *(int *)(t + 0x1554) + (int)t, 0, 0.0f, 0, 0);
        if (*(void **)(self + 0x6F0))
            func_001D0580(*(void **)(self + 0x6F0));
        B(0x2F6)++;
    }
    case 1:
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

// FUNCTION: GAME 0x227BB0
void func_00227BB0(char *self)
{
    B(0x186A) = 2;
    *(unsigned int *)(self + 0x16D4) |= 0x400;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        int m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1EAC) + (int)t, *(int *)(t + 0x1EB0) + (int)t, 0, 0.0f, m & 0xFFFF, 0);
        B(0x2F6)++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(float *)(self + 0x618) < 484.0f) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x25;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x237F98
void func_00237F98(char *self)
{
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x146C) + (int)t, *(int *)(t + 0x1470) + (int)t, 0, 0.0f, 0, 0);
        float *v = *(float **)(self + 0xF0);
        v[1] -= (*(float *)(self + 0x114) - 1.0f) * 1.6f;
        B(0x2F6)++;
    }
    case 1:
        *(unsigned int *)(self + 0x16D0) |= 0x10000;
        if (moveMotion((cObjBase *)self)) {
            *(unsigned int *)(self + 0x16D0) &= ~0x10000;
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x23F970
void func_0023F970(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        char *a = (char *)*(int *)(t + 0x488) + (int)t;
        char *b = (char *)*(int *)(t + 0x48C) + (int)t;
        int m = func_00276468(self);
        func_002A8578(self, (int)a, (int)b, 3, 0.0f, m & 0xFFFF, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(int *)(self + 0x6EC) == 0 && (*(unsigned short *)(self + 0x3AC) & 1)) {
        void *r = func_002DDAB0(*(void **)(self + 0xF0), 1.5f, 1);
        if (r)
            func_0026AB20(self, r, *(unsigned short *)((char *)r + 0x2FE));
    }
}

// FUNCTION: GAME 0x22A258
void func_0022A258(char *self)
{
    B(0x186A) = 2;
    switch (B(0x2F6)) {
    case 0: {
        int m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x3914) + (int)t, *(int *)(t + 0x3918) + (int)t, 3, 0.0f, m & 0xFFFF, 0);
        *(int *)(self + 0x5F0) = 1;
        *(int *)(self + 0x5F4) = 1;
        B(0x2F6)++;
    }
    case 1: {
        cGameObj *pl = Getplayer();
        ((cGameObj *)self)->SetTgtTurn(*pl->m_pPos, *(float *)(self + 0x5A8) * 0.09817477f);
        *(unsigned int *)(self + 0x16D0) |= 0x800000;
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(unsigned short *)(self + 0x3AC) & 1) {
            if (*(int *)(self + 0x5F0)) {
                *(int *)(self + 0x5F0) = 0;
                void *r = func_0026AA30(self, 0x37E);
                if (r)
                    func_0026B240(self, r, 0x37E, 0xE);
            }
        } else
            *(int *)(self + 0x5F0) = 1;
        if (*(unsigned short *)(self + 0x3AC) & 1) {
            if (*(int *)(self + 0x5F4)) {
                *(int *)(self + 0x5F4) = 0;
                void *r = func_0026AA30(self, 0x37E);
                if (r)
                    func_0026B240(self, r, 0x37E, 0x12);
            }
        } else
            *(int *)(self + 0x5F4) = 1;
    }
    }
}

// DRAFT: GAME 0x23A950
// 0x23A950: frame 0x40 vs 0x50 and branch layout differ; the original keeps constant 1 in s1 across the irand call (nested switch/if-chain forms tried)
#ifdef NONMATCHING
void func_0023A950(char *self)
{
    *(unsigned int *)(self + 0x16D0) |= 0x400;
    switch (B(0x2F6)) {
    case 0: {
        unsigned m = func_00276468(self) & 0xFFFF;
        unsigned sel = B(0x2F7);
        int a, b;
        char *t;
        switch (sel) {
        case 1:
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0xC20);
            b = *(int *)(t + 0xC24);
            break;
        case 2:
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0xC20);
            b = *(int *)(t + 0xC28);
            break;
        default:
            unsigned r = irand() % 3;
            if (r == 1) {
                t = *(char **)(self + 0x304);
                a = *(int *)(t + 0xC18);
                b = *(int *)(t + 0xC1C);
            } else if (r == 0) {
                t = *(char **)(self + 0x304);
                a = *(int *)(t + 0xC00);
                b = *(int *)(t + 0xC04);
            } else if (r == 2) {
                t = *(char **)(self + 0x304);
                a = *(int *)(t + 0xC20);
                b = *(int *)(t + 0xC24);
            } else {
                t = *(char **)(self + 0x304);
                a = *(int *)(t + 0xC00);
                b = *(int *)(t + 0xC04);
            }
            break;
        }
        func_002A8578(self, a + (int)t, b + (int)t, 3, 0.0f, m, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            func_002705D8(self);
        } else {
            ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
            ((cObjBase *)self)->addNullSpeed(1.0f);
        }
    }
    if (*(unsigned short *)(self + 0x3AC) & 1)
        func_00262750(self, 0);
}
#endif

// FUNCTION: GAME 0x236ED0
void func_00236ED0(char *self)
{
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(unsigned int *)(self + 0x16D0) |= 0x20000;
    *(float *)(self + 0x54C) = 3.0f;
    *(unsigned int *)(self + 0x250) |= 0x10000;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1BA0) + (int)t, *(int *)(t + 0x1BA4) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        break;
    case 2: {
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1BA8) + (int)t, *(int *)(t + 0x1BAC) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 3:
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
