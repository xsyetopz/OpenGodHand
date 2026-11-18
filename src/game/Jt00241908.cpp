// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern "C" int func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int getGameLevel__9cCoreSave(void *);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" float Turn_dest_dir__Ffff(float, float, float);
extern "C" float Adjust_theta__Ff(float);
extern char CoreSave[];
extern char g_EmManage[];

#define B(o) (*(unsigned char *)(self + (o)))
#define F(o) (*(float *)(self + (o)))

// FUNCTION: GAME 0x241908
extern "C" void func_00241908(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x10A8) + (int)o, *(int *)(o + 0x10AC) + (int)o, 10, 0.0f, r, 0);
        switch (getGameLevel__9cCoreSave(CoreSave)) {
        case 1:
        default:
            F(0x600) = 750.0f;
            break;
        case 2:
            F(0x600) = 600.0f;
            break;
        case 3:
            F(0x600) = 450.0f;
            break;
        case 4:
            F(0x600) = 450.0f;
            break;
        case 5:
            F(0x600) = 450.0f;
            break;
        }
        B(0x2F6)++;
    }
    case 1: {
        B(0x617) = 1;
        float t = Turn_dest_dir__Ffff(F(0x104), 0.0f, F(0x5A8) * 0.098174773f);
        F(0x104) += t;
        F(0x104) = Adjust_theta__Ff(F(0x104));
        *(unsigned *)(self + 0x16D0) |= 0x10000;
        *(unsigned *)(self + 0x16D0) |= 0x20000;
        F(0x54C) = 3.0f;
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        int d = 1;
        if (!(*(unsigned *)(self + 0x16D0) & 0x20000000)) d = 0;
        {
            char *em = g_EmManage;
            char *e = *(char **)(em + 0x56C);
            if (e) { if (!(*(short *)(e + 0x54A) > 0)) d = 1; } else d = 1;
        }
        {
            char *em = g_EmManage;
            char *e = *(char **)(em + 0x568);
            if (e) { if (!(*(short *)(e + 0x54A) > 0)) d = 1; } else d = 1;
        }
        F(0x600) -= F(0x5A8);
        if (F(0x600) <= 0.0f) d = 1;
        if (d) B(0x2F6) = 2;
        break;
    }
    case 2:
        B(0x2F6)++;
        F(0x600) = 60.0f;
    case 3:
        *(unsigned *)(self + 0x16D0) |= 0x10000;
        *(unsigned *)(self + 0x16D0) |= 0x20000;
        F(0x54C) = 3.0f;
        B(0x617) = 1;
        moveMotion__FP8cObjBase(self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        F(0x600) -= F(0x5A8);
        if (F(0x600) <= 0.0f) {
            F(0x1748) = 300.0f;
            F(0x6D0) = 1.9540f;
            F(0x6D4) = 4.0f;
            F(0x6D8) = -14.8719f;
            F(0x6E0) = 0.0f;
            B(0x2F5) = 0x75;
            B(0x2F7) = 0;
            B(0x2F4) = 0;
            B(0x2F6) = 0;
        }
        break;
    }
}
