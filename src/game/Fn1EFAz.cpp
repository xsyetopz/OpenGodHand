extern "C" void *Getplayer__Fv();
extern "C" void func_001FAD58(void *, unsigned);
extern "C" void func_001FADC0(void *, unsigned);
extern "C" void func_001FAE28(void *, unsigned);
extern "C" void func_002A9BF0(void *, float);
extern "C" void SetHeatGage__8cHeatSysf(void *, float);
extern "C" void clearGodItem__9cCoreSave(void *);
extern "C" void addGodItem__9cCoreSaveUc(void *, unsigned);
extern "C" void setGameLevel__9cCoreSavei(void *, int);
extern "C" void initData__10cCockPlBar(void *);
extern char CoreSave[];
extern char g_HeatSys[];
extern char *Cockpit;

// FUNCTION: GAME 0x1EFA50
// DIVNOP: 0 1 2
extern "C" void func_001EFA50(char *self)
{
    char *pl = (char *)Getplayer__Fv();
    if (pl) {
        if (*(short *)(self + 0xB74) != -1) {
            func_001FAD58(CoreSave, *(unsigned char *)(self + 0xB74));
            int v = *(short *)(self + 0xB74) * 20 + 100;
            *(short *)(pl + 0x548) = v;
            short a = *(short *)(self + 0xB76);
            if ((short)v <= a)
                *(short *)(pl + 0x54A) = v;
            else
                *(short *)(pl + 0x54A) = a;
        } else {
            int cv = (int)((float)*(short *)(pl + 0x548) * ((float)*(short *)(self + 0xB76) / 100.0f));
            if (*(short *)(pl + 0x548) <= cv)
                *(unsigned short *)(pl + 0x54A) = *(unsigned short *)(pl + 0x548);
            else
                *(short *)(pl + 0x54A) = cv;
        }
        if (*(short *)(self + 0xB78) != -1) {
            func_001FADC0(CoreSave, *(unsigned char *)(self + 0xB78));
            float h = (float)(*(short *)(self + 0xB78) * 30 + 120);
            func_002A9BF0(g_HeatSys, h);
            SetHeatGage__8cHeatSysf(g_HeatSys, h * (*(float *)(self + 0xB7C) / 100.0f));
        } else {
            SetHeatGage__8cHeatSysf(g_HeatSys, *(float *)g_HeatSys * (*(float *)(self + 0xB7C) / 100.0f));
        }
    }
    if (*(short *)(self + 0xB80) != -1)
        func_001FAE28(CoreSave, *(unsigned char *)(self + 0xB80));
    clearGodItem__9cCoreSave(CoreSave);
    for (int i = 0; i < *(unsigned char *)(self + 0xB82); i++)
        addGodItem__9cCoreSaveUc(CoreSave, 1);
    setGameLevel__9cCoreSavei(CoreSave, *(short *)(self + 0xB68));
    initData__10cCockPlBar(Cockpit + 0x460);
}
