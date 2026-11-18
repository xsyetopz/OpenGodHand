// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void *Getplayer__Fv();
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_002705D8(void *);
extern "C" void func_002DB770();
extern "C" void func_00129718(void *, void *, int);
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern char CoreSave[];
extern char g_CollSolidManage[];
extern char Sys[];

#define B(o) (*(unsigned char *)(self + (o)))
#define H(o) (*(short *)(self + (o)))
#define UH(o) (*(unsigned short *)(self + (o)))

// FUNCTION: GAME 0x236190
extern "C" void func_00236190(char *self)
{
    char *pl = (char *)Getplayer__Fv();
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    switch (B(0x2F6)) {
    case 0: {
        char *o = *(char **)(self + 0x304);
        B(0x1864) = 0;
        func_002A8578(self, *(int *)(o + 0x518) + (int)o, *(int *)(o + 0x51C) + (int)o, 0, 0, 0, 0.0f);
        switch (getGameLevel__9cCoreSave(CoreSave)) {
        case 1:
        default:
            H(0x568) = 5;
            break;
        case 2:
            H(0x568) = 10;
            break;
        case 3:
        case 4:
            H(0x568) = 15;
            break;
        case 5:
            H(0x568) = 20;
            break;
        }
        H(0x56A) = 4;
        H(0x56E) = 15;
        H(0x56C) = 1;
        B(0x2F6)++;
    }
    case 1:
        if (H(0x56E)) {
            UH(0x56E) = UH(0x56E) - 1;
            char *p = *(char **)(self + 0xF0);
            char *q = pl + 0x550;
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        {
            unsigned *sy = (unsigned *)Sys;
            if (sy[2] & 0xF0)
                UH(0x568) = UH(0x568) - 1;
            if (sy[2] & 0xF00000)
                UH(0x568) = UH(0x568) - 4;
        }
        *(float *)(self + 0x54C) = 3.0f;
        if (moveMotion__FP8cObjBase(self)) {
            func_002705D8(self);
            return;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (UH(0x3AC) & 0x10) {
            if (H(0x568) <= 0) {
                B(0x2F6) = 0;
                B(0x2F4) = 1;
                B(0x2F5) = 0x1D;
                B(0x2F7)++;
                SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
                func_00129718(pl, self, 0x1D);
            }
            func_002DB770();
            H(0x56C) = 0;
        } else if (H(0x56C)) {
            func_002DB770();
        }
        break;
    }
}
