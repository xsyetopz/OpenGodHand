// Fn1A9938: object destructor wrapper releasing damage/collision handles and effects.
extern char g_DmgManage;
extern char g_CollScr;
extern const char D_00427CF0[];
extern "C" void func_001FE278(void *mgr, void *p);
extern "C" int ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
extern "C" void func_0012EC58(void *coll, void *p);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);
extern "C" void func_001B6F38(void *self, int flag);

#ifdef NONMATCHING
// DRAFT: GAME 0x1A9938
extern "C" void func_001A9938(char *self, int flag)
{
    *(const void **)(self + 0x214) = D_00427CF0;
    void *d = *(void **)(self + 0x604);
    if (d) {
        func_001FE278(&g_DmgManage, d);
        *(void **)(self + 0x604) = 0;
    }
    void *g = *(void **)(self + 0x608);
    if (g) {
        ReleaseDamageGive__13cDamageManageP11cDamageGive(&g_DmgManage, g);
        *(void **)(self + 0x608) = 0;
    }
    char *p = self + 0x60C;
    for (int i = 2; i >= 0; i--, p += 4) {
        void *c = *(void **)p;
        if (c)
            func_0012EC58(&g_CollScr, c);
    }
    KillEffect__FPC4cObji13eEspEraseMode(self, 3, 2);
    KillEffect__FPC4cObji13eEspEraseMode(self, 0xB, 2);
    KillEffect__FPC4cObji13eEspEraseMode(self, 0xA, 2);
    func_001B6F38(self, flag);
}
#endif
