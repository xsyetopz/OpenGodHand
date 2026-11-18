struct EmW { unsigned char id; };
extern "C" void func_001EF978(void *);
extern "C" int GetVitalMax__7cEmWrap(EmW *);
extern "C" int GetVital__7cEmWrap(EmW *);
extern "C" void setSuspend__7cEmWrapb(EmW *, int);
extern "C" void *GetEm__9cEmManageUc(void *, unsigned char);
extern "C" void setEm65Separate__5cEm00(void *);
extern "C" void startSoftEvent__9cScenario14eSoftEventType(void *, int);
extern "C" void endSoftEvent__9cScenario(void *);
extern char *g_Sce;
extern char g_EmManage;

// FUNCTION: GAME 0x1F2540
extern "C" void func_001F2540(char *self)
{
    EmW w;
    w.id = 0;
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        break;
    case 1: {
        int mx = GetVitalMax__7cEmWrap(&w);
        int v = GetVital__7cEmWrap(&w);
        if (v > 0 && !(mx < v * 2)) {
            startSoftEvent__9cScenario14eSoftEventType(g_Sce, 0);
            setSuspend__7cEmWrapb(&w, 0);
            setEm65Separate__5cEm00(GetEm__9cEmManageUc(&g_EmManage, w.id));
            *(int *)(self + 0xBA0) = 0xBF;
            *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        }
        break;
    }
    case 2: {
        int c = *(int *)(self + 0xBA0);
        if (c == 0) {
            endSoftEvent__9cScenario(g_Sce);
            *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        } else {
            *(int *)(self + 0xBA0) = c - 1;
        }
        break;
    }
    }
}
