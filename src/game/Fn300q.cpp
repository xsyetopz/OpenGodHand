enum eObjId { OBJ0 };
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_00306330(int, int);
extern "C" void *func_0030FAC8(eObjId);
extern "C" void *func_0030FB20(eObjId, void *);
extern char D_0071B940[], D_00741940[], D_00741960[], D_00741980[];
extern int D_00747A78, D_00752D00, g_iObjCnt;
extern float D_00741DC0;
void MoveEmitter(void);
void MoveEsp(void);
#define TM (*(volatile int *)0x10000800)

// FUNCTION: GAME 0x3003F0
void InitEmitterWork(void)
{
    memset(D_0071B940, 0, 0x26000);
    memset(D_00741940, 0, 0x20);
    memset(D_00741960, 0, 0x20);
    memset(D_00741980, 0, 0x20);
}

// FUNCTION: GAME 0x305BE0
extern "C" void sstClearSetFlag__6espSys(char *p)
{
    func_00306330(0x40, 2);
    *(int *)(p + 0x414) = 0;
}

// FUNCTION: GAME 0x308D40
extern "C" void ClearHiddenModelList__12HideModelMgr(int *p)
{
    int i;
    p += 0x1F;
    for (i = 0x1F; i >= 0; i--) *p-- = 0;
}

// FUNCTION: GAME 0x30F228
void MoveEffect(void)
{
    D_00752D00 = TM;
    g_iObjCnt = 0;
    if (!(D_00747A78 & 0x10000000)) {
        MoveEmitter();
        MoveEsp();
        D_00741DC0 = 1.0f;
    }
    D_00752D00 -= TM;
}

// FUNCTION: GAME 0x30FA98
void *CreateObj(eObjId a, eObjId b)
{
    return func_0030FB20(a, func_0030FAC8(a));
}
