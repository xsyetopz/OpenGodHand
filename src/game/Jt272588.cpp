// Trigger check on the state word at 0x564; sole switch of 0x272588.
extern "C" void *func_002DDAB0(void *, float, int);
extern "C" void *Getplayer__Fv();
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" void func_001D0AD0(void *);
extern "C" void setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(void *, const void *, int, unsigned, float);

// FUNCTION: GAME 0x272588
extern "C" int func_00272588(char *self)
{
    if (*(int *)(self + 0x6EC) || *(int *)(self + 0x6F0))
        return 0;
    switch (*(int *)(self + 0x564)) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x216:
    case 0x227:
    case 0x228:
    case 0x229:
    case 0x22A:
    case 0x22B:
    case 0x23A:
    case 0x240:
    case 0x24A:
    case 0x24B:
    {
        char *e = (char *)func_002DDAB0(*(void **)(self + 0xF0), 10.0f, 0);
        if (!e)
            return 0;
        char *p = (char *)Getplayer__Fv();
        if (capVu0MagnitudeSqXZ__FPCfT0(*(const float **)(p + 0xF0), *(const float **)(e + 0xF0)) < 6.25f)
            return 0;
        func_001D0AD0(e);
        setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(self, *(void **)(e + 0xF0), 8, 0, 300.0f);
        self[0x2F5] = 0x13;
        self[0x2F4] = 0;
        self[0x2F6] = 0;
        self[0x2F7] = 0;
        return 1;
    }
    default:
        return 0;
    }
}
