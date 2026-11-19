extern "C" void func_001EF978(void *);
extern "C" int func_001EF8B8(void *);
extern "C" void setEm__11cEmSetParamUc(void *, unsigned char);
extern "C" void StartAction__7cEmWrap(void *);
extern char g_EmSet;

// FUNCTION: GAME 0x1F1B20
extern "C" void func_001F1B20(char *self)
{
    unsigned char em[16];
    int s = *(int *)(self + 0xB94);
    switch (s) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xBA0) = 0;
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        return;
    case 1:
        if (*(int *)(self + 0xBA0) < 0x2EE && func_001EF8B8(self))
            goto inc;
        em[0] = s;
        setEm__11cEmSetParamUc(&g_EmSet, 1);
        StartAction__7cEmWrap(em);
        *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
        *(int *)(self + 0xBA0) = 0;
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        return;
    case 2:
        if (*(int *)(self + 0xBA0) < 0x2EE && func_001EF8B8(self))
            goto inc;
        em[0] = s;
        setEm__11cEmSetParamUc(&g_EmSet, 2);
        StartAction__7cEmWrap(em);
        *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        return;
    }
    return;
inc:
    *(int *)(self + 0xBA0) = *(int *)(self + 0xBA0) + 1;
}
