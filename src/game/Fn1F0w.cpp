// God Hand: small functions in 0x1F0000-0x1F4000
extern "C" void func_001EF978(char *);
extern "C" int strcmp(const char *, const char *);
extern "C" void func_001F00E8(char *, char *, float);
extern char D_0042BE90[];
// FUNCTION: GAME 0x1F2698
extern "C" void func_001F2698(char *self)
{
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        break;
    case 1:
        *(int *)(self + 0xB94) = 2;
        break;
    }
}
// FUNCTION: GAME 0x1F0360
extern "C" void func_001F0360(char *self, char *e)
{
    if (e && *(short *)(e + 0x54A) > 0) {
        if (!strcmp(D_0042BE90, *(const char **)(e + 0x4AC)))
            func_001F00E8(self, e, *(float *)(e + 0x16CC) + 0.1f);
        else
            func_001F00E8(self, e, 0.5f);
    }
}
