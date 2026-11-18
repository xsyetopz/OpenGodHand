// Small free functions of the cOm* object units in 0x1A0000-0x1AFFFF.
extern "C" void *func_001B6E90(void *self);
extern "C" int func_001B6FB8(void *self);
extern "C" int moveMotion__FP8cObjBase(void *self);
extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *self, void *dmg);
extern "C" void setPlCamera__11cCamManagerUc(void *mgr, unsigned char v);
extern "C" void endSoftEvent__9cScenario(void *sce);
extern char CamManager[];
extern void *g_Sce;
extern unsigned int D_00747A78;
extern const char D_004277B8[];
extern const char D_00427F48[];

// FUNCTION: GAME 0x1A8348
extern "C" void *func_001A8348(char *self)
{
    func_001B6E90(self);
    *(int *)(self + 0x600) = 0;
    *(const void **)(self + 0x214) = D_004277B8;
    return self;
}

// FUNCTION: GAME 0x1A96E8
extern "C" int func_001A96E8(char *self)
{
    func_001B6FB8(self);
    *(unsigned int *)(self + 0x250) |= 0x10000;
    return 1;
}

// FUNCTION: GAME 0x1ADB88
extern "C" void *func_001ADB88(char *self)
{
    func_001B6E90(self);
    *(int *)(self + 0x620) = 0;
    *(const void **)(self + 0x214) = D_00427F48;
    return self;
}

// FUNCTION: GAME 0x1AE700
extern "C" int func_001AE700(char *self)
{
    int r = 0;
    float f = *(float *)(self + 0x614);
    if (f > 200.0f)
        r = 1;
    if (f > 320.0f)
        r = 2;
    return r;
}

// FUNCTION: GAME 0x1ADBE8
extern "C" int func_001ADBE8(char *self)
{
    func_001B6FB8(self);
    *(unsigned int *)(self + 0x250) |= 0x10000;
    *(int *)(self + 0x600) = 0;
    *(int *)(self + 0x5B8) &= -0x41;
    return 1;
}

// FUNCTION: GAME 0x1AF630
extern "C" void func_001AF630(char *self)
{
    moveMotion__FP8cObjBase(self);
    if (*(short *)(self + 0x984) <= 0) {
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F5) = 2;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
    *(short *)(self + 0x984) -= 1;
}

// FUNCTION: GAME 0x1A4CF8
extern "C" void func_001A4CF8(char *self)
{
    if (*(unsigned char *)(self + 0x763)) {
        setPlCamera__11cCamManagerUc(CamManager, 0);
        endSoftEvent__9cScenario(g_Sce);
        D_00747A78 &= 0xFFFEFFFF;
    }
}

// FUNCTION: GAME 0x1A62B8
extern "C" void func_001A62B8(char *self)
{
    int r = checkDamage__7cOmBaseP11cDamageTake(self, *(void **)(self + 0x608));
    if (r == 1) {
        if (*(short *)(self + 0x54A) <= 0)
            *(unsigned char *)(self + 0x605) = r;
        *(unsigned char *)(self + 0x2F4) = r;
        *(unsigned char *)(self + 0x2F5) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
}
