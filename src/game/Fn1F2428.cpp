struct EmW { unsigned char id; };
extern "C" void func_001EF978(void *);
extern "C" int func_001EF8B8(void *);
extern "C" void setEm__11cEmSetParamUc(void *, unsigned char);
extern "C" void StartAction__7cEmWrap(void *);
extern char g_EmSet;

// FUNCTION: GAME 0x1F2428
extern "C" void func_001F2428(char *self)
{
    EmW w;
    int s = *(int *)(self + 0xB94);
    switch (s) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        break;
    case 1:
        if (func_001EF8B8(self) == 0) {
            w.id = s;
            setEm__11cEmSetParamUc(&g_EmSet, 1);
            StartAction__7cEmWrap(&w);
            *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
            *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        }
        break;
    case 2:
        if (func_001EF8B8(self) == 0) {
            w.id = s;
            setEm__11cEmSetParamUc(&g_EmSet, 2);
            StartAction__7cEmWrap(&w);
            *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
            *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        }
        break;
    case 3:
        if (func_001EF8B8(self) == 0) {
            w.id = s;
            setEm__11cEmSetParamUc(&g_EmSet, 3);
            StartAction__7cEmWrap(&w);
            *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
            *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        }
        break;
    }
}
