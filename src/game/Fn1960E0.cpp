extern char g_DmgManage[];
extern char D_00424E18[];
extern "C" void func_001FE278(void *, void *);
extern "C" void ReleaseDamageGive__13cDamageManageP11cDamageGive(void *, void *);
extern "C" void func_001B6F38(void *, int);
// FUNCTION: GAME 0x1960E0
extern "C" void func_001960E0(char *self, int a)
{
    *(char **)(self + 0x214) = D_00424E18;
    void **p = (void **)(self + 0x600);
    int i = 0;
    do {
        if (*p) {
            func_001FE278(g_DmgManage, *p);
            *p = 0;
        }
        i--;
        p++;
    } while (i >= 0);
    if (*(void **)(self + 0x604)) {
        ReleaseDamageGive__13cDamageManageP11cDamageGive(g_DmgManage, *(void **)(self + 0x604));
        *(void **)(self + 0x604) = 0;
    }
    func_001B6F38(self, a);
}
