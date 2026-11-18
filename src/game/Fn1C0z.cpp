extern char g_EmManage[];
extern "C" float GetSpeedRate__9cEmManage(char *);
extern "C" void SetMotionStep__FP8cObjBasef(char *, float);
extern "C" void func_002A8578(char *, char *, float, int, int, int, int);
extern "C" int moveMotion__FP8cObjBase(char *);
extern "C" void SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, char *, int, int, unsigned);
// FUNCTION: GAME 0x1CB8C0
// FUNCTION: GAME 0x1CEC68
extern "C" void func_001CEC68(char *self)
{
    float r = GetSpeedRate__9cEmManage(g_EmManage);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        float k = 0.013f;
        *(float *)(self + 0x630) = k;
        *(float *)(self + 0x660) = 15.0f;
        *(float *)(self + 0x674) = -k;
        *(unsigned char *)(self + 0x2F6) += 1;
    }
    case 1: {
        char *p = *(char **)(self + 0xF0);
        *(float *)(p + 4) += *(float *)(self + 0x674) * r;
        float a = *(float *)(self + 0x630) * r;
        float b = *(float *)(self + 0x660) - r;
        float c = *(float *)(self + 0x674) - a;
        *(float *)(self + 0x660) = b;
        *(float *)(self + 0x674) = c;
        if (b <= 0.0f) {
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F4) = 1;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
    }
}

extern "C" void func_001CB8C0(char *self)
{
    float f = GetSpeedRate__9cEmManage(g_EmManage);
    *(float *)(self + 0x5A8) = f;
    SetMotionStep__FP8cObjBasef(self, f);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(self, (char *)(*(int *)(p + 0xC) + (int)p), 0.0f, 0, 0, 0, 0);
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x7B, 0xB8, self, 0, -1, 0xFFFFFFFFu);
        register int k __asm__("$3") = *(unsigned char *)(self + 0x2F6);
        *(unsigned char *)(self + 0x2F6) = k + 1;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F5) = 1;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        break;
    }
}
