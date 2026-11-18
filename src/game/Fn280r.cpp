extern char D_00448CA0[];
extern char D_00448E20[];
extern char D_0044A660[];
extern char g_DmgManage[];
extern char g_CollSolidManage[];
extern char g_EmManage[];

extern "C" void func_002A84A8(char *);
extern "C" void func_001C2370(int);
extern "C" void func_00285678(char *);
extern "C" void func_00289E10(char *);
extern "C" void func_0028EB88(char *, int);

// FUNCTION: GAME 0x284A90
extern "C" void func_00284A90(char *self, int a)
{
    *(char **)(self + 0x214) = D_00448CA0;
    func_002A84A8(self);
    int p = *(int *)(self + 0x15C4);
    if (p) {
        func_001C2370(p);
        *(int *)(self + 0x15C4) = 0;
    }
    func_00285678(self);
    func_0028EB88(self, a);
}

// FUNCTION: GAME 0x289788
extern "C" void func_00289788(char *self, int a)
{
    *(char **)(self + 0x214) = D_00448E20;
    func_002A84A8(self);
    int p = *(int *)(self + 0x15B0);
    if (p) {
        func_001C2370(p);
        *(int *)(self + 0x15B0) = 0;
    }
    func_00289E10(self);
    func_0028EB88(self, a);
}

extern "C" void func_001FE370(char *, char *);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(char *, char *);
extern "C" void func_0028EB88_dtor(char *, int) __asm__("_$_8cGameObj"); // asm names the destructor symbol containing '$'

// FUNCTION: GAME 0x28EB88
extern "C" void func_0028EB88(char *self, int a)
{
    *(char **)(self + 0x214) = D_0044A660;
    func_001FE370(g_DmgManage, self);
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
    func_0028EB88_dtor(self, a);
}

extern "C" char *func_002948C8(char *, unsigned);
extern "C" int func_001B8640(char *);

// FUNCTION: GAME 0x289418
extern "C" int func_00289418()
{
    for (unsigned i = 0; i < 2; i++) {
        char *r = func_002948C8(g_EmManage, i);
        if (r && func_001B8640(r)) return 1;
    }
    return 0;
}

extern char D_0044A528[];
extern char D_0044A518[];
extern char D_0044A520[];
extern char EspSys[];
extern char Snd[];
extern "C" void effDataRelease__6espSys12eEffDataType(void *sys, int t);
extern "C" void SeStop__4cSnd6eSndId(char *, int);
extern "C" void func_0028E418(char *);
extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" int setupModel__6cModelPC10SCR_HEADERUibT3(void *, int, int, int, int);

// FUNCTION: GAME 0x28E068
extern "C" void func_0028E068(char *self, int a)
{
    *(char **)(self + 0x214) = D_0044A528;
    func_002A84A8(self);
    effDataRelease__6espSys12eEffDataType(EspSys, 0xD7);
    int s = *(int *)(self + 0x1550);
    if (s) SeStop__4cSnd6eSndId(Snd, s);
    func_0028E418(self);
    func_0028EB88(self, a);
}

// FUNCTION: GAME 0x28EA38
extern "C" int func_0028EA38(char *self)
{
    int a = SearchData__FPUiPCcUi(*(void **)(self + 0x304), D_0044A518, 0);
    int b = SearchData__FPUiPCcUi(*(void **)(self + 0x304), D_0044A520, 0);
    if (b) return setupModel__6cModelPC10SCR_HEADERUibT3(self, a, b, 0, 0);
    return 0;
}

extern char g_EmdManager[];
extern char D_00585960[];
extern "C" void func_001FE6B8(char *, char *, int);

// FUNCTION: GAME 0x28FF80
extern "C" void func_0028FF80(int a, int b)
{
    if (b == 0xFFFF && a) {
        int n = 0x1F;
        do {
            n--;
        } while (n != -1);
        func_001FE6B8(g_EmdManager, D_00585960, 0x20);
    }
}
