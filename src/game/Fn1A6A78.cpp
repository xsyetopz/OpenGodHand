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
// diff: s0/s1 swapped (self vs g_Sce), original keeps g_Sce in s0 and 4 bytes longer, 22 words
extern "C" void func_001A6A78(char *self)
{
    *(unsigned char *)(self + 0x604) = 5;
    startSoftEvent__9cScenario14eSoftEventType(g_Sce, 0);
    markTask(taskExec__9cScenarioPvT1i(g_Sce, (void *)func_001A6AF8, self, 1));
}
#endif
