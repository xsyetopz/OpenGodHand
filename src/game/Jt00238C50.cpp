// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" void *Getplayer__Fv();
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_0027DCE8(void *);
extern "C" void func_002705D8(void *);
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern char CoreSave[];
extern char g_CollSolidManage[];

#define B(o) (*(unsigned char *)(self + (o)))

// FUNCTION: GAME 0x238C50
extern "C" void func_00238C50(char *self)
{
    char *pl = (char *)Getplayer__Fv();
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    switch (B(0x2F6)) {
    case 0: {
        char *o = *(char **)(self + 0x304);
        B(0x1864) = 0;
        func_002A8578(self, *(int *)(o + 0x33CC) + (int)o, *(int *)(o + 0x33D0) + (int)o, 0, 0, 0, 0.0f);
        if (*(void **)(self + 0x740))
            func_0027DCE8(*(void **)(self + 0x740));
        *(short *)(self + 0x56E) = 0xF;
        B(0x2F6)++;
    }
    case 1:
        *(float *)(self + 0x54C) = 3.0f;
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
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
        break;
    case 2: {
        char *o = *(char **)(self + 0x304);
        B(0x1864) = 0;
        func_002A8578(self, *(int *)(o + 0x33D4) + (int)o, *(int *)(o + 0x33D8) + (int)o, 0, 0, 0, 0.0f);
        *(short *)(self + 0x56E) = 0xF;
        *(float *)(self + 0x54C) = 5.0f;
        switch (getGameLevel__9cCoreSave(CoreSave)) {
        case 1:
        default:
            *(float *)(self + 0x16E4) = 180.0f;
            break;
        case 2:
            *(float *)(self + 0x16E4) = 150.0f;
            break;
        case 3:
            *(float *)(self + 0x16E4) = 120.0f;
            break;
        case 4:
            *(float *)(self + 0x16E4) = 120.0f;
            break;
        case 5:
            *(float *)(self + 0x16E4) = 90.0f;
            break;
        }
        B(0x2F6)++;
    }
    case 3:
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
            char *p = *(char **)(self + 0xF0);
            char *q = pl + 0x550;
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        if (moveMotion__FP8cObjBase(self)) {
            if (getGameLevel__9cCoreSave(CoreSave) < 3) {
                B(0x2F4) = 0;
                B(0x2F5) = 0x6C;
                B(0x2F6) = 0;
                B(0x2F7) = 0;
            } else {
                func_002705D8(self);
            }
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
}
