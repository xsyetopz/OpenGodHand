extern "C" {
void endSoftEvent__9cScenario(void *);
void exit__9cTaskWork(void *);
int func_002C3F10(void *, int);
void setMess__9cScenarioUi(void *, unsigned short);
void startSoftEvent__9cScenario14eSoftEventType(void *, int);
void waitCam__9cScenario(void *);
void waitMess__9cScenario(void *);
}
extern char *g_Sce;

// FUNCTION: GAME 0x2C41C8
extern "C" void func_002C41C8(void)
{
    int cam = 0;
    if (*(int *)(g_Sce + 0xDC) != 0) {
        cam = 1;
        func_002C3F10(g_Sce, *(int *)(g_Sce + 0xDC));
    }
    int mess = 0;
    if (*(unsigned short *)(g_Sce + 0xD8) != 0xFFFF) {
        mess = 1;
        setMess__9cScenarioUi(g_Sce, *(unsigned short *)(g_Sce + 0xD8));
    }
    int ev = 1;
    if (cam == 0 && mess == 1) {
        ev = 2;
    } else if (cam == 1) {
        if (mess == 0)
            ev = 3;
    }
    startSoftEvent__9cScenario14eSoftEventType(g_Sce, ev);
    if (mess == 1) {
        if ((*(unsigned char *)(g_Sce + 0xE5) ^ 1) & 1)
            waitMess__9cScenario(g_Sce);
    } else if (cam != 0) {
        if ((*(unsigned char *)(g_Sce + 0xE5) ^ 1) & 1)
            waitCam__9cScenario(g_Sce);
    }
    endSoftEvent__9cScenario(g_Sce);
    if (*(unsigned char *)(g_Sce + 0xE4) == 1)
        exit__9cTaskWork(*(void **)(g_Sce + 0x20));
}
