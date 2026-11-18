extern char g_EmManage[];
extern char D_00428AF0[];
extern "C" int func_001B6FB8(void *self);
extern "C" void func_00294898(void *, void *);
extern "C" char *getMeshPtr__6cModelPCc(void *, const char *);
// FUNCTION: GAME 0x1B81A8
extern "C" int func_001B81A8(char *self)
{
    func_001B6FB8(self);
    *(unsigned char *)(self + 0x600) = 0;
    *(unsigned *)(self + 0x250) |= 0x10000;
    *(unsigned char *)(self + 0x601) = 0;
    func_00294898(g_EmManage, self);
    char *m = getMeshPtr__6cModelPCc(self, D_00428AF0);
    if (m)
        *(unsigned *)(m + 0x380) |= 1;
    *(int *)(self + 0x608) = 0;
    return 1;
}
