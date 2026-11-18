extern char g_EmManage[];
extern "C" float GetSpeedRate__9cEmManage(char *);
extern "C" void func_001F2B80(char *, int, int, int, int, int);
// FUNCTION: GAME 0x1EFD70
// DIVNOP: 2 2 2
extern "C" void func_001EFD70(char *self, int a)
{
    float t;
    int h, m, s;
    *(float *)(self + 0xB98) -= GetSpeedRate__9cEmManage(g_EmManage);
    if (*(float *)(self + 0xB98) < 0.0f)
        *(float *)(self + 0xB98) = 0.0f;
    t = *(float *)(self + 0xB98);
    h = (int)(t / 1800.0f);
    t -= (float)(h * 1800);
    m = (int)(t / 30.0f);
    t -= (float)(m * 30);
    s = (int)(t / 30.0f * 100.0f);
    func_001F2B80(self + 0x60, a, h, m, s, 1);
}
