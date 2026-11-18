// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void *Getplayer__Fv();
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
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

struct VT { char _p[0xA8]; short off; short _q; void (*fn)(char *, int, char *, int, int); };

// DRAFT: GAME 0x239240 - 6 words differ: the vtable pointer sits in v1 and the slot in v0 in the original; mine swaps them in the m_3AC & 1 virtual call
#ifdef NONMATCHING
// FUNCTION: GAME 0x239240
extern "C" void func_00239240(char *self)
{
    char *pl = (char *)Getplayer__Fv();
    switch (B(0x2F6)) {
    case 0: {
        char *o = *(char **)(self + 0x304);
        B(0x1864) = 0;
        func_002A8578(self, *(int *)(o + 0x3BD8) + (int)o, *(int *)(o + 0x3BDC) + (int)o, 0, 0.0f, 0, 0);
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
        H(0x56A) = 30;
        H(0x56E) = 15;
        B(0x2F6)++;
    }
    case 1:
        SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
        if (H(0x56E)) {
            UH(0x56E) = UH(0x56E) - 1;
            char *p = *(char **)(self + 0xF0);
            char *q = pl + 0x550;
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        *(float *)(self + 0x54C) = 3.0f;
        if (moveMotion__FP8cObjBase(self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0x6C;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (H(0x56A) > 0) {
            UH(0x56A) = UH(0x56A) - 1;
            func_002DB770();
            unsigned *sy = (unsigned *)Sys;
            if (sy[2] & 0xF0)
                UH(0x568) = UH(0x568) - 1;
            if (sy[2] & 0xF00000)
                UH(0x568) = UH(0x568) - 4;
        } else if (H(0x568) <= 0) {
            B(0x2F6) = 2;
            pl[0x2F6] = 2;
        }
        break;
    case 2: {
        char *o = *(char **)(self + 0x304);
        B(0x1864) = 0;
        func_002A8578(self, *(int *)(o + 0x3BE0) + (int)o, *(int *)(o + 0x3BE4) + (int)o, 3, 0.0f, 0, 0);
        *(int *)(self + 0x5F0) = 1;
        *(float *)(self + 0x54C) = 15.0f;
        H(0x568) = 40;
        B(0x2F6)++;
    }
    case 3:
        if (H(0x568)) {
            UH(0x568) = UH(0x568) - 1;
            SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
        }
        if (moveMotion__FP8cObjBase(self)) {
            func_002705D8(self);
            break;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        if (UH(0x3AC) & 1) {
            if (*(int *)(self + 0x5F0)) {
                VT *vt = *(VT **)(self + 0x214);
                vt->fn(self + vt->off, 10, pl, 1, 0);
                if (H(0x54A) <= 0)
                    H(0x54A) = 1;
            }
        }
        break;
    }
}
#endif
