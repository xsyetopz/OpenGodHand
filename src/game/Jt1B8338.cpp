// Jump-table unit; this file holds no other .rodata.
extern char g_EmManage[];
extern "C" float GetSpeedRate__9cEmManage(char *);
extern "C" void SetMotionStep__FP8cObjBasef(char *, float);
extern "C" void func_002A8578(char *, char *, float, int, int, int, int);
extern "C" int moveMotion__FP8cObjBase(char *);

// FUNCTION: GAME 0x1B8338
extern "C" void func_001B8338(char *self)
{
    float f = GetSpeedRate__9cEmManage(g_EmManage);
    if (0.0f < *(float *)(self + 0x604))
        *(float *)(self + 0x604) = *(float *)(self + 0x604) - f;
    *(float *)(self + 0x5A8) = f;
    SetMotionStep__FP8cObjBasef(self, f);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(self, (char *)(*(int *)(p + 0xC) + (int)p), 0.0f, 0, 0, 0, 0);
        moveMotion__FP8cObjBase(self);
        *(unsigned short *)(self + 0x434) |= 8;
        *(unsigned char *)(self + 0x2F6) += 1;
        break;
    }
    case 2:
        *(unsigned char *)(self + 0x2F6) += 1;
    case 3:
        *(unsigned short *)(self + 0x434) |= 8;
        if (moveMotion__FP8cObjBase(self))
            *(unsigned char *)(self + 0x601) = 1;
        break;
    case 1:
    case 5:
        break;
    case 4:
        *(unsigned char *)(self + 0x2F6) += 1;
        break;
    }
}
