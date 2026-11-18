// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void *Getplayer__Fv();
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_002705D8(void *);
extern "C" void func_002DB770();
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

// DRAFT: GAME 0x237078 - 6 words differ (~15 forms tried: struct VE, split fn/vt temps, cast forms, cond forms): the vtable pointer sits in v1 and the slot in v0 in the original; mine swaps them in the m_3AC & 1 virtual call
#ifdef NONMATCHING
extern "C" void func_00237078(char *self)
{
    char *pl = (char *)Getplayer__Fv();
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        char *o = *(char **)(self + 0x304);
        B(0x1864) = 0;
        func_002A8578(self, *(int *)(o + 0x240C) + (int)o, *(int *)(o + 0x2410) + (int)o, 0, 0, 0, 0.0f);
        H(0x56E) = 0x3C;
        switch (getGameLevel__9cCoreSave(CoreSave)) {
        case 1:
        default:
            H(0x568) = 15;
            break;
        case 2:
            H(0x568) = 20;
            break;
        case 3:
        case 4:
            H(0x568) = 25;
            break;
        case 5:
            H(0x568) = 30;
            break;
        }
        if (*(short *)(pl + 0x54A) < 2)
            H(0x568) = 0x3C;
        H(0x56A) = 0x14;
        B(0x2F6)++;
    }
    case 1:
        if (H(0x56E)) {
            UH(0x56E) = UH(0x56E) - 1;
            char *p = *(char **)(self + 0xF0);
            char *q = pl + 0x550;
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        if (moveMotion__FP8cObjBase(self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (H(0x56A) != 0) {
            UH(0x56A) = UH(0x56A) - 1;
        } else {
            func_002DB770();
            unsigned *sy = (unsigned *)Sys;
            if (sy[2] & 0xF0)
                UH(0x568) = UH(0x568) - 1;
            if (sy[2] & 0xF00000)
                UH(0x568) = UH(0x568) - 4;
        }
        if (UH(0x3AC) & 0x10) {
            if (H(0x568) <= 0) {
                pl[0x2F6] = 2;
                B(0x2F6) = 2;
            }
            H(0x56A) = 999;
        }
        break;
    case 2: {
        char *o = *(char **)(self + 0x304);
        B(0x1864) = 0;
        func_002A8578(self, *(int *)(o + 0x2420) + (int)o, *(int *)(o + 0x2424) + (int)o, 0, 0, 0, 0.0f);
        H(0x56E) = 15;
        B(0x2F6)++;
    }
    case 3:
        if (H(0x56E)) {
            UH(0x56E) = UH(0x56E) - 1;
            char *p = *(char **)(self + 0xF0);
            char *q = pl + 0x550;
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        if (moveMotion__FP8cObjBase(self))
            func_002705D8(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (UH(0x3AC) & 1) {
            char *vt;
            vt = *(char **)(self + 0x214);
            ((void (*)(char *, int, int, int, int)) * (void **)(vt + 0xAC))(self + *(short *)(vt + 0xA8), 0x14, 0, 0, 0);
            if (H(0x54A) <= 0)
                H(0x54A) = 1;
        }
        break;
    }
}
#endif
