extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void SetMotionStep__FP8cObjBasef(void *, float);
#define SM(name, off, n) \
extern "C" void name(char *self) \
{ \
    char *t = *(char **)(self + 0x304); \
    func_002A8578(self, *(int *)(t + off) + (int)t, 0, n, 0, 0, 0.0f); \
}
// FUNCTION: GAME 0x1B1FE0
SM(SetMotionTurn__5cOm71, 0x20, 5)
// FUNCTION: GAME 0x1B2018
SM(SetMotion010__5cOm71, 0x38, 10)
// FUNCTION: GAME 0x1B20A8
SM(SetMotion100__5cOm71, 0x48, 5)
// FUNCTION: GAME 0x1B20E0
SM(SetMotion102__5cOm71, 0x54, 5)
// FUNCTION: GAME 0x1B1F00
extern "C" void SetMotionWait__5cOm71(char *self)
{
    char *t = *(char **)(self + 0x304);
    func_002A8578(self, *(int *)(t + 0x10) + (int)t, 0, 5, 0, 0, 0.0f);
    SetMotionStep__FP8cObjBasef(self, 1.0f);
}
// FUNCTION: GAME 0x1B2050
extern "C" void SetMotionKokeru__5cOm71(char *self)
{
    char *t = *(char **)(self + 0x304);
    func_002A8578(self, *(int *)(t + 0x4C) + (int)t, *(int *)(t + 0x50) + (int)t, 5, 0, 0, 0.0f);
    *(unsigned *)(self + 0x600) |= 8;
}

extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" char *getMeshPtr__6cModeli(void *, int);
extern "C" void func_001B6F38(void *, int);
extern "C" void func_001B6FB8(void *);
extern "C" void func_0012EC58(void *, int);
extern "C" void func_001FE278(void *, int);
extern "C" void releaseObjCollision__7cOmDoor(void *);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" void SeStop__4cSnd6eSndId(void *, int);
extern "C" void setMeshDispFromLayer__7cOmBaseUib(void *, unsigned, int);
extern "C" void effDataRegist__6espSys12eEffDataTypePv(void *, int, void *);
extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" void setTextureExchange__6cModelPCUiPCvi(void *, void *, void *, int);
extern "C" void KeyStop__Fv();
extern "C" void addCasinoTicket__9cCoreSavei(void *, int);
extern "C" int getCasinoTicketNum__9cCoreSave(void *);
extern char g_CollScr[], Snd[], EspSys[], CoreSave[], g_DmgManage[];
extern char D_00428A18[], D_00428B58[], D_004292F0[];
extern char *Cockpit;
// FUNCTION: GAME 0x1BD3F0
extern "C" void releaseObjCollision__7cOmDoor(void *s)
{
    char *self = (char *)s;
    int c = *(int *)(self + 0x644);
    if (c) {
        func_0012EC58(g_CollScr, c);
        *(int *)(self + 0x644) = 0;
    }
}
// FUNCTION: GAME 0x1B7DE8
extern "C" void setTexChange__7cOmBaseUi(char *self, unsigned id)
{
    *(unsigned *)(self + 0x254) |= 0x10000000;
    int r = SearchData__FPUiPCcUi(*(void **)(self + 0x304), D_00428A18, 0);
    setTextureExchange__6cModelPCUiPCvi(self, *(void **)(self + 0x284), (void *)r, id);
}
// FUNCTION: GAME 0x1B8140
extern "C" void func_001B8140(char *self, int a)
{
    *(char **)(self + 0x214) = D_00428B58;
    KillEffect__FPC4cObji13eEspEraseMode(self, 0, 2);
    if (*(int *)(self + 0x608))
        SeStop__4cSnd6eSndId(Snd, *(int *)(self + 0x608));
    *(int *)(self + 0x608) = 0;
    func_001B6F38(self, a);
}
// FUNCTION: GAME 0x1BBF00
extern "C" void func_001BBF00(char *self, int a)
{
    *(char **)(self + 0x214) = D_004292F0;
    int v = *(int *)(self + 0x600);
    if (v) {
        func_001FE278(g_DmgManage, v);
        *(int *)(self + 0x600) = 0;
    }
    releaseObjCollision__7cOmDoor(self);
    func_001B6F38(self, a);
}
// FUNCTION: GAME 0x1BDF30
extern "C" int func_001BDF30(char *self)
{
    func_001B6FB8(self);
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 1);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 0);
    *(unsigned *)(self + 0x5B8) |= 8;
    char *t = *(char **)(self + 0x304);
    effDataRegist__6espSys12eEffDataTypePv(EspSys, 0x241, (void *)(*(int *)(t + 0x10) + (int)t));
    return 1;
}
// FUNCTION: GAME 0x1BEB28
extern "C" void func_001BEB28(char *self)
{
    KeyStop__Fv();
    addCasinoTicket__9cCoreSavei(CoreSave, -1);
    *(int *)(Cockpit + 0x1A10) = (short)getCasinoTicketNum__9cCoreSave(CoreSave);
    *(unsigned char *)(self + 0x2F4) = 1;
    *(unsigned char *)(self + 0x2F5) = 0;
    *(unsigned *)(self + 0x600) |= 1;
}
// FUNCTION: GAME 0x1BFF68
extern "C" void func_001BFF68(char *self)
{
    if (*(void **)(self + 0x600))
        SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x600), 0);
    *(unsigned *)(getMeshPtr__6cModeli(self, 0) + 0x380) |= 1;
    *(unsigned *)(getMeshPtr__6cModeli(self, 0) + 0x380) |= 0x2000;
    *(unsigned *)(self + 0x250) |= 0x10000;
}
