extern char Sys[];
#define SYS ((char *)sys)
#define W(p, o) (*(int *)((p) + (o)))
extern char D_00747A2C[];
extern char *g_Sce;
extern char g_SceAt[], g_ActBtn[];
extern "C" char *Getplayer__Fv();
extern "C" void endMess__9cScenario(char *);
extern "C" void func_001F7360(char *);
extern "C" void func_002C1540(char *);

// DRAFT: GAME 0x2C3500 (4 words differ: addiu $s1 is scheduled after sd $ra instead of before)
#ifdef NONMATCHING
extern "C" void func_002C3500(char *self)
{
    char *sys = Sys;
    __asm__("" : "+r"(sys));
    if (*(unsigned short *)(sys + 0x5B0) != 0x20 && Getplayer__Fv() != 0) {
        long f = *(unsigned *)(self + 0x48);
        if (((f >> 1) & 1) == 0) {
            if (*(short *)(Getplayer__Fv() + 0x54A) > 0)
                goto tail;
            W(self, 0x48) |= 2;
            endMess__9cScenario(g_Sce);
            W(sys, 0x5E0) |= 0x100000;
        } else {
            if (*(short *)(Getplayer__Fv() + 0x54A) > 0) {
                W(self, 0x48) &= ~2;
                W(sys, 0x5E0) &= 0xFFEFFFFF;
            }
        }
    }
tail:
    if (W(D_00747A2C, 0) >= 0) {
        if (W(D_00747A2C, 0x58) & 0x8000000) return;
        {
            unsigned long g = *(int *)(D_00747A2C - 8);
            if (((g >> 3) & 1) == 1) return;
        }
        if (W(D_00747A2C, 0x4C) & 0x10000) return;
        if (W(D_00747A2C, 4) & 1) return;
        W(D_00747A2C, 0x84) = 0xFFFF;
        {
            long h = *(unsigned *)(self + 0x48);
            if (((h >> 1) & 1) == 0)
                func_002C1540(g_SceAt);
        }
        {
            void (*cb)() = *(void (**)())(self + 0x104);
            if (cb) cb();
        }
        func_001F7360(g_ActBtn);
    }
}
#endif
