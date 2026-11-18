extern char *g_Sce;
extern "C" void startSoftEvent__9cScenario14eSoftEventType(void *, int);
extern "C" int taskExec__9cScenarioPvT1i(void *, void *, void *, int);
extern "C" void func_001A6AF8(void *);
static inline void markTask(int id)
{
    if (id >= 0)
        *(unsigned char *)(*(char **)(g_Sce + 0x1C) + id * 0x58 + 0x50) |= 1;
}
#ifdef NONMATCHING
// DRAFT: GAME 0x1A6A78
// diff: 22 words, s0/s1 swapped (self vs g_Sce lui base), ours has extra move a0=v0 before bltz (original tests v0 directly, uses v0 in mult); tried int id local, early return, operand order, temp for 0x1C load
extern "C" void func_001A6A78(char *self)
{
    *(unsigned char *)(self + 0x604) = 5;
    startSoftEvent__9cScenario14eSoftEventType(g_Sce, 0);
    markTask(taskExec__9cScenarioPvT1i(g_Sce, (void *)func_001A6AF8, self, 1));
}
#endif
