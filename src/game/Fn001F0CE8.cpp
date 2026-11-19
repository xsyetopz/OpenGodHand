extern "C" void func_001EF978(void *);
extern "C" int func_001C2490(int);
extern "C" void setEm__11cEmSetParamUc(void *, unsigned char);
extern "C" void StartAction__7cEmWrap(void *);
extern char g_EmSet;

// FUNCTION: GAME 0x1F0CE8
extern "C" void func_001F0CE8(char *self)
{
    unsigned char em[16];
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        break;
    case 1:
        if (*(int *)(self + 0xC64) && func_001C2490(*(int *)(self + 0xC64))) {
            em[0] = 0;
            setEm__11cEmSetParamUc(&g_EmSet, 0);
            StartAction__7cEmWrap(em);
            *(int *)(self + 0xC64) = 0;
            *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
        }
        if (*(int *)(self + 0xC68) && func_001C2490(*(int *)(self + 0xC68))) {
            em[0] = 1;
            setEm__11cEmSetParamUc(&g_EmSet, 1);
            StartAction__7cEmWrap(em);
            *(int *)(self + 0xC68) = 0;
            *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
        }
        if (*(int *)(self + 0xC6C) && func_001C2490(*(int *)(self + 0xC6C))) {
            em[0] = 2;
            setEm__11cEmSetParamUc(&g_EmSet, 2);
            StartAction__7cEmWrap(em);
            *(int *)(self + 0xC6C) = 0;
            *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
        }
        break;
    }
}
