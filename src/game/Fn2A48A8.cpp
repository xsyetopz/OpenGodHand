extern int DISPLAY_H;
extern float D_003C1190;
extern char cFilter_tag[];
extern int D_00586B80;
extern float D_00586B84, D_00586B88;

// FUNCTION: GAME 0x2A48A8
// DIVNOP: 2
extern "C" void func_002A48A8(int a, int b)
{
    if (b == 0xFFFF && a) {
        int h = DISPLAY_H;
        float d = D_003C1190;
        char *t = cFilter_tag;
        D_00586B80 = 0x800 - h / 2;
        D_00586B84 = 2048.0f - d * 0.5f;
        D_00586B88 = (float)h / 480.0f;
        *(long *)(t + 0x140C8) = 0;
        *(long *)(t + 0x14098) = 0;
    }
}
