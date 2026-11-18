enum eObjId { OBJ0 };
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_00306330(int, int);
extern "C" void *func_0030FAC8(eObjId);
extern "C" void *func_0030FB20(eObjId, void *);
enum eEffDataType { T0 };
enum eEffId { E0 };
enum eEspEraseMode { M0, M1, M2 };
struct cObj;
struct cHeap;
extern unsigned char D_003C3CFC;
extern "C" void func_00300D20(int, int);
extern "C" void func_002FB898(int, int);
extern "C" void func_003009F8(const cObj *, int);
extern "C" void func_002FB5C0(const cObj *, int);
extern "C" void func_00300AE8(int, int);
extern "C" void func_002FBB78(int, int, int, int);
extern "C" void func_0030ECF8(int);
extern "C" void *func_002A9538(cHeap *, unsigned, unsigned);
extern char *D_003C3BF8[];
extern char D_003C3C18[];
struct SysT { char p0[0x270]; long q270; char p1[0x168]; long q3E0; char p2[0x224]; unsigned w60C; };
extern SysT Sys;
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

// FUNCTION: GAME 0x3005D8
extern "C" void func_003005D8(char *p)
{
    unsigned i = (unsigned)(p - D_0071B940) / 0x260;
    ((unsigned *)D_00741960)[i >> 5] |= 0x80000000u >> (i & 0x1F);
}

// FUNCTION: GAME 0x306168
void KillEffect(eEffDataType a, eEffId b, eEspEraseMode m)
{
    switch (m) {
    case M0: func_00300D20(a, b); break;
    case M1: func_002FB898(a, b); break;
    case M2:
        func_002FB898(a, b);
        func_00300D20(a, b);
        break;
    }
}
// FUNCTION: GAME 0x306200
void KillEffect(const cObj *o, int id, eEspEraseMode m)
{
    if (!o && id == -1) return;
    switch (m) {
    case M0: func_003009F8(o, id); break;
    case M1: func_002FB5C0(o, id); break;
    case M2:
        func_002FB5C0(o, id);
        func_003009F8(o, id);
        break;
    }
}
// FUNCTION: GAME 0x306470
void VanishEffect(eEffDataType a, eEffId b, eEspEraseMode m, unsigned char c, bool d)
{
    switch (m) {
    case M0: func_00300AE8(a, d); break;
    case M1: func_002FBB78(a, b, c, d); break;
    case M2:
        func_002FBB78(a, b, c, d);
        func_00300AE8(a, d);
        break;
    }
}

// FUNCTION: GAME 0x30EE08
void *_MemoryAlloc(unsigned a, unsigned b, cHeap &h)
{
    if (!D_003C3CFC) func_0030ECF8(0);
    return func_002A9538(&h, a, b);
}

// FUNCTION: GAME 0x307918
char *FileNameFromObjId(char *d, eObjId id)
{
    char **t = &D_003C3BF8[id >> 8];
    d[0] = (*t)[0];
    d[1] = (*t)[1];
    d[2] = '/';
    d[3] = (*t)[0];
    d[4] = (*t)[1];
    d[5] = D_003C3C18[(id & 0xF0) >> 4];
    d[6] = D_003C3C18[id & 0xF];
    d[7] = '.';
    d[8] = 'd';
    d[9] = 'a';
    d[10] = 't';
    d[11] = 0;
    return d;
}

// FUNCTION: GAME 0x309D40
extern "C" int func_00309D40(int x)
{
    int i = 31;
    if (x >= 0) {
        while (--i > 0)
            if ((x >> i) & 1) break;
    }
    return i + ((1 << i) < x);
}

// FUNCTION: GAME 0x30E5C0
void Set_bg_mode(unsigned m, unsigned char a, unsigned char b, unsigned char c)
{
    switch (m) {
    case 0:
        Sys.q3E0 = (Sys.q3E0 & -0x8000L) | 0x10;
        Sys.q270 = (Sys.q270 & -0x8000L) | 0x10;
        break;
    case 1:
        Sys.q3E0 = (Sys.q3E0 & -0x8000L) | 0x16;
        Sys.q270 = (Sys.q270 & -0x8000L) | 0x16;
        Sys.w60C = a | (b << 8) | (c << 16);
        break;
    }
}
