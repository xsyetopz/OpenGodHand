extern unsigned short D_00747A50;
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
// FUNCTION: GAME 0x1B1F58
extern "C" void SetMotionRun__5cOm71(char *self)
{
    char *s = self;
    if (D_00747A50 == 0x305) {
        char *t = *(char **)(s + 0x304);
        func_002A8578(s, *(int *)(t + 0x14) + (int)t, 0, 5, 0, 0, 0.0f);
    } else {
        char *t = *(char **)(s + 0x304);
        func_002A8578(s, *(int *)(t + 0x14) + (int)t, *(int *)(t + 0x18) + (int)t, 5, 0, 0, 0.0f);
    }
}
